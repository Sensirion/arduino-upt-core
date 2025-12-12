#ifndef BLE_PROTOCOL_H
#define BLE_PROTOCOL_H

#include "Arduino.h"
#include "SignalType.h"
#include <map>
#include <string>

/**
 * Refer to
 * https://github.com/Sensirion/arduino-ble-gadget/blob/master/documents/00-Sensirion_BLE_communication_protocol.pdf
 * for the general BLE sample transmission strategy.
 *
 * Common definitions:
 *  --  DataType: identifies the structure and contents of ManufacturerData
 *                field in BLE Advertisement
 *  --  Sample: set of measurements, typically retrieved simultaneously from a
 *              sensor. Made up of several SampleSlots.
 *  --  Data: array of bytes containing the Company ID, Sample Adv. Type, Sample
 *            Type, and Sample. See the diagram in Sect 2 "BLE Advertisement"
 *            in the document linked above
 */
namespace sensirion::upt::core {
enum DataType {
    UNDEFINED,
    T_RH_V3,
    T_RH_V4,
    T_RH_VOC,
    T_RH_CO2,
    T_RH_CO2_ALT,
    T_RH_CO2_PM25,
    T_RH_VOC_PM25,
    T_RH_VOC_NOX,
    T_RH_VOC_NOX_PM25,
    T_RH_HCHO,
    T_RH_CO2_VOC_PM25_HCHO,
    T_RH_CO2_VOC_NOX_PM25,
    T_RH_CO2_PM25_V2,
    T_RH_VOC_PM25_V2,
    T_RH_CO2_VOC_PM25_HCHO_V2,
    T_RH_H2_P,
    PM10_PM25_PM40_PM100,
    CO2_DataType,
    AV_T,
    /* Add new DataType here. Remember to add corresponding
     * SampleConfig in BLEProtocol.cpp */
};

// Encoding functions
uint16_t encodeSimple(float value);
uint16_t encodeTemperatureV1(float value);
uint16_t encodeHumidityV1(float value);
uint16_t encodeHumidityV2(float value);
uint16_t encodePM2p5V1(float value);
uint16_t encodePMV2(float value);
uint16_t encodeHCHOV1(float value);
uint16_t encodeVelocityV1(float value);
uint16_t encodeH2ConcentrationV1(float value);
/* Declare new encoding functions here, define in BLEProtocol.cpp */

// Decoding functions
float decodeSimple(uint16_t rawValue);
float decodeTemperatureV1(uint16_t rawValue);
float decodeHumidityV1(uint16_t rawValue);
float decodeHumidityV2(uint16_t rawValue);
float decodePM2p5V1(uint16_t rawValue);
float decodePMV2(uint16_t rawValue);
float decodeHCHOV1(uint16_t rawValue);
float decodeVelocityV1(uint16_t rawValue);
float decodeH2ConcentrationV1(uint16_t rawValue);
/* Declare new decoding functions here, define in BLEProtocol.cpp */

/// Helper template to prevent access to uninitialized function pointers
/// @tparam retT return type of the wrapped function pointer
/// @tparam argT argument type of the wrapped function pointer
template <typename retT, typename argT> struct FunctionWrapper {
    using wrappedT = retT (*)(argT arg);

    FunctionWrapper() : function{nullptr} {}
    // Intentionally non-explicit to allow convenient initialization from
    // function pointers
    FunctionWrapper(const wrappedT ptr) // NOLINT(google-explicit-constructor)
        : function{ptr} {}
    retT operator()(argT arg) const {
        if (function != nullptr) {
            return function(arg);
        }
        return static_cast<retT>(0);
    }

    explicit operator bool() const { return function != nullptr; }

  private:
    wrappedT function;
};

using EncodingFunction = FunctionWrapper<uint16_t, float>;
using DecodingFunction = FunctionWrapper<float, uint16_t>;

// Data manipulators
void emplaceRawValue(std::string &data, uint8_t offset, uint16_t rawValue);
uint16_t getRawValue(const std::string &data, uint8_t offset);

struct SampleSlot {
    SignalType signalType{SignalType::UNDEFINED};
    size_t offset{0};
    EncodingFunction encodingFunction;
    DecodingFunction decodingFunction;
};

// Sample configuration data
struct SampleConfig {
    DataType dataType{DataType::UNDEFINED};
    uint16_t downloadType{0};
    uint8_t sampleType{0}; // Maps 1-to-1 to DataType
    size_t sampleSizeBytes{0};
    size_t sampleCountPerPacket{0};
    uint8_t sensirionAdvertisementSampleType{0};
    std::map<SignalType, SampleSlot> sampleSlots{};
};

DataType getDataTypeFromSampleType(uint8_t sampleType);

using SampleConfigMapping = std::map<DataType, SampleConfig>;

/// Initializes the data structures that define the layout of
/// BLE samples from different gadgets
///
/// If you need this data structure, call this function in the
/// setup of your arduino application.
void InitSampleConfigurationMapping();

/// Get a reference to the mapping table that defines the mapping from
/// DataType to SampleConfig
const SampleConfigMapping &GetSampleConfigurationMapping();

/// Read a specific SampleConfiguration for a specified data type
/// @param dataType
/// @return The mapped SampleConfig entry
SampleConfig GetSampleConfiguration(DataType dataType);

} // namespace sensirion::upt::core

#endif /* BLE_PROTOCOL_H */
