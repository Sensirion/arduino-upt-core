#ifndef _MEASUREMENT_H_
#define _MEASUREMENT_H_

#include "BLEGadgetType.h"
#include "SensorType.h"
#include "SignalType.h"
#include <Arduino.h>

struct DataPoint {
    unsigned long t_offset = 0;
    float value = 0;
};

enum class DevicePlatform {
    UNDEFINED,
    BLE,
    WIRED,
};

union DeviceType {
    SensorType sensorType;
    BLEGadgetType bleGadgetType;
};

struct MetaData {
    DevicePlatform platform = DevicePlatform::UNDEFINED;
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

    MetaData() : deviceType{SensorType::UNDEFINED} {};
};

struct Measurement {
    DataPoint dataPoint;
    SignalType signalType = SignalType::UNDEFINED;
    MetaData metaData;
};

/**
 * @brief obtain a label for the device platform, eg. "WIRED"
 */
const char *devicePlatformLabel(DevicePlatform devicePlatform,
                                DeviceType deviceType);

/**
 * @brief obtain a label for the device type, eg. "SCD4X"
 */
const char *deviceLabel(DevicePlatform platform, DeviceType deviceType);

#endif /* _MEASUREMENT_H_ */
