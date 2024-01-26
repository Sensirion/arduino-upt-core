#include "Measurement.h"

const char *devicePlatformLabel(DevicePlatform platform,
                                DeviceType deviceType) {
    switch (platform) {
    case DevicePlatform::WIRED:
        return "WIRED";
    case DevicePlatform::BLE:
        return "BLE";
    default:
        return "UNDEFINED";
    }
}

const char *deviceLabel(DevicePlatform platform, DeviceType deviceType) {
    switch (platform) {
    case DevicePlatform::WIRED:
        return sensorLabel(deviceType.sensorType);
    case DevicePlatform::BLE:
        return bleGadgetLabel(deviceType.bleGadgetType);
    default:
        return "UNDEFINED";
    }
}
