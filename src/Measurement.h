#ifndef _MEASUREMENT_H_
#define _MEASUREMENT_H_

#include "BLEGadgetType.h"
#include "SensorType.h"
#include "SignalType.h"
#include <Arduino.h>

struct DataPoint {
    unsigned long t_offset = 0;
    float value;
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
    uint64_t
        deviceID; // Device MAC or Serial No. (Not available for SCD30 or SFA3X)
    DeviceType devicetype; // SensorType U BLEGadgetType
};

struct Measurement {
    DataPoint datapoint;
    SignalType signaltype = SignalType::UNDEFINED;
    MetaData metadata;
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
