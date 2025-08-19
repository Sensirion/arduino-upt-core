#ifndef _MEASUREMENT_H_
#define _MEASUREMENT_H_

#include "BLEGadgetType.h"
#include "SensorType.h"
#include "SignalType.h"
#include <Arduino.h>
#include <string>
#include <DeviceType.h>

namespace upt_core{

struct DataPoint {
    unsigned long t_offset = 0;
    float value = 0;
};


struct MetaData {
    /// We require a device type that is not added to the registry but that can just be used to
    /// have a default constructor for Measurements
    static constexpr DeviceType DEVICE_UNDEFINED{"undefined"};

    /**
     * @note deviceID is intended as a unique identifier for sensors within the
     * UPT ecosystem. 64 bits are made available to accomodate full MAC
     * addresses of BLE devices, or the typical 48 bits of sensor serial numbers
     * (available via WIRED communications only). In case the serial number is
     * longer than 64 bits (ie. SEN5X series of sensors have a serial no. of 16
     * characters, or 128 bits) the last 8 characters (or 64 bits) are kept by
     * convention.
     * In case no serial number is available (eg. for SCD30 or SFA3X series of
     * sensors) a random value is chosen by the author of the Measurement.
     */
    uint64_t deviceID = 0;
    DeviceType deviceType;

    explicit MetaData(const DeviceType& deviceType) : deviceType{deviceType} {};
};

struct Measurement {
    
    explicit Measurement(const DeviceType& deviceType): metaData{deviceType}{}
    Measurement(const MetaData& metadata, const SignalType signalType, const DataPoint& dataPoint):
        metaData{metadata}, signalType{signalType}, dataPoint{dataPoint}{}
    Measurement():
        dataPoint{0,0},signalType{SignalType::UNDEFINED},metaData{MetaData::DEVICE_UNDEFINED}{}

    DataPoint dataPoint{0,0};
    SignalType signalType{SignalType::UNDEFINED};
    MetaData metaData{MetaData::DEVICE_UNDEFINED};
};

/**
 * @brief obtain a label for the device platform, eg. "WIRED"
 */
const char *devicePlatformLabel(DeviceType deviceType);

/**
 * @brief obtain a label for the device type, eg. "SCD4X"
 */
const char *deviceLabel(DeviceType deviceType);

/**
 * @brief print Measurement.metaData to console via Arduino Serial
 */
void printMeasurementMetaData(const Measurement &measurement);

/**
 * @brief print Measurement without Measurement.metaData to console via Arduino
 * Serial
 */
void printMeasurementWithoutMetaData(const Measurement &measurement);

/**
 * @brief print Measurement to console via Arduino Serial
 */
void printMeasurement(const Measurement &measurement);

// Utilities for printing methods
std::string arrayifyDeviceID(uint64_t deviceID);
void printMACAddess(const std::string &macAddress);

} // end namespace

#endif /* _MEASUREMENT_H_ */
