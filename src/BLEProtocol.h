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
 *  --  DataType: identifies the structure & contents of ManufacturerData field
 *      in BLE Advertisement
 *  --  Sample: set of measurements, typically retrived simultaneously from a
 *      sensor. Made up of several SampleSlots.
 *  --  Data: array of bytes containing the Company ID, Sample Adv. Type, Sample
 *      Type, and Sample. See diagram in Sect 2 "BLE Advertisement" in document
 *      linked above
 */
namespace sensirion::upt::core{
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
    PM10_PM25_PM40_PM100,
    CO2_DataType,
    AV_T,
    /* Add new DataType here. Don't forget to add corresponding
    SampleConfig in BLEProtocol.cpp */
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
/* Declare new encoding function here, define in
 * BLEProtocol.cpp */

// Decoding functions
float decodeSimple(uint16_t rawValue);
float decodeTemperatureV1(uint16_t rawValue);
float decodeHumidityV1(uint16_t rawValue);
float decodeHumidityV2(uint16_t rawValue);
float decodePM2p5V1(uint16_t rawValue);
float decodePMV2(uint16_t rawValue);
float decodeHCHOV1(uint16_t rawValue);
float decodeVelocityV1(uint16_t rawValue);
/* Declare new decoding function here, define in
 * BLEProtocol.cpp */

// Data manipulators
void emplaceRawValue(std::string &data, uint8_t offset, uint16_t rawValue);
uint16_t getRawValue(const std::string &data, uint8_t offset);

struct SampleSlot {
    SignalType signalType;
    size_t offset;
    uint16_t (*encodingFunction)(float value);
    float (*decodingFunction)(uint16_t rawValue);
};

// Sample configuration data
struct SampleConfig {
    DataType dataType;
    uint16_t downloadType;
    uint8_t sampleType; // Maps 1-to-1 to DataType
    size_t sampleSizeBytes;
    size_t sampleCountPerPacket;
    uint8_t sensirionAdvertisementSampleType;
    std::map<SignalType, SampleSlot> sampleSlots;
};

DataType getDataTypeFromSampleType(uint8_t sampleType);

extern std::map<DataType, SampleConfig> sampleConfigSelector;

} // end namespace

#endif /* BLE_PROTOCOL_H */
