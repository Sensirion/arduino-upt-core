#include "Measurement.h"
#include "DeviceType.h"

namespace sensirion::upt::core{

const char *devicePlatformLabel(DeviceType deviceType) {
    auto platform = DeviceTypeRegistry::GetDevicePlatform(deviceType);
    switch (platform) {
    case DevicePlatform::WIRED:
        return "WIRED";
    case DevicePlatform::BLE:
        return "BLE";
    default:
        return "UNDEFINED";
    }
}

const char *deviceLabel(DeviceType deviceType) {
    return deviceType.data();
}

void printMeasurementMetaData(const Measurement &measurement) {
    // Get device and platform descriptive labels
    auto platform = DeviceTypeRegistry::GetDevicePlatform(measurement.metaData.deviceType);
    const char *platformLbl = devicePlatformLabel(measurement.metaData.deviceType);
    const char *deviceLbl = deviceLabel(measurement.metaData.deviceType);

    Serial.printf("  Metadata:\n");
    Serial.printf("    Platform:\t\t%s\n", platformLbl);
    Serial.printf("    deviceID:\t\t");
    switch (platform) {
    case DevicePlatform::BLE:
        printMACAddess(arrayifyDeviceID(measurement.metaData.deviceID));
        break;
    case DevicePlatform::WIRED:
    default:
        Serial.printf("%llu", measurement.metaData.deviceID);
    }

    Serial.println();
    Serial.printf("    Device Type:\t%s\n", deviceLbl);

    return;
}

void printMeasurementWithoutMetaData(const Measurement &measurement) {
    Serial.printf("  Data Point:\n");
    Serial.printf("    Measured at:\t%lus\n",
                  measurement.dataPoint.t_offset / 1000);
    Serial.printf("    Value:\t\t");
    switch (measurement.signalType) {
    case SignalType::TEMPERATURE_DEGREES_CELSIUS:
    case SignalType::TEMPERATURE_DEGREES_FARENHEIT:
    case SignalType::RELATIVE_HUMIDITY_PERCENTAGE:
    case SignalType::VELOCITY_METERS_PER_SECOND:
        Serial.printf("%.1f\n", measurement.dataPoint.value);
        break;
    case SignalType::CO2_PARTS_PER_MILLION:
    case SignalType::HCHO_PARTS_PER_BILLION:
    case SignalType::PM1P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM2P5_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM4P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::PM10P0_MICRO_GRAMM_PER_CUBIC_METER:
    case SignalType::RAW_VOC_INDEX:
    case SignalType::RAW_NOX_INDEX:
    case SignalType::VOC_INDEX:
    case SignalType::NOX_INDEX:
    case SignalType::GAS_CONCENTRATION_VOLUME_PERCENTAGE:
    case SignalType::H2_CONCENTRATION_VOLUME_PERCENTAGE:
    case SignalType::PRESSURE_MBAR:
        Serial.printf("%i\n", static_cast<int>(measurement.dataPoint.value));
        break;
    default:
        Serial.printf("%i\n", static_cast<int>(measurement.dataPoint.value));
        break;
    }

    Serial.printf("  SignalType:\n");
    Serial.printf("    Physical Quantity:\t%s\n",
                  quantityOf(measurement.signalType));
    Serial.printf("    Units:\t\t%s\n", unitOf(measurement.signalType));
}

void printMeasurement(const Measurement &measurement) {
    printMeasurementWithoutMetaData(measurement);
    printMeasurementMetaData(measurement);
}

std::string arrayifyDeviceID(uint64_t deviceID) {
    std::string address;
    address.reserve(6);
    for (int i = 0; i < 6; i++) {
        address.insert(address.begin(), static_cast<char>(deviceID));
        deviceID = deviceID >> 8;
    }
    return address;
}

void printMACAddess(const std::string &macAddress) {
    assert(macAddress.capacity() >= 6);
    for (int i = 0; i < 5; i++) {
        Serial.printf("%X:", macAddress[i]);
    }
    Serial.printf("%X", macAddress[5]);
}

} // end namespace
