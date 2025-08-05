
#include "SensorType.h"

const DeviceType SensorType::SCD4X=DeviceTypeRegistry::CreateBleDeviceType("Scd4x");
const DeviceType SensorType::SFA3X=DeviceTypeRegistry::CreateWiredDeviceType("Sfa3x");
const DeviceType SensorType::SFA40=DeviceTypeRegistry::CreateWiredDeviceType("Sfa4x");
const DeviceType SensorType::SVM4X=DeviceTypeRegistry::CreateWiredDeviceType("Svm4x");
const DeviceType SensorType::SVM41=DeviceTypeRegistry::CreateWiredDeviceType("Svm41");
const DeviceType SensorType::SHT4X=DeviceTypeRegistry::CreateWiredDeviceType("Sht4x");
const DeviceType SensorType::SAV45=DeviceTypeRegistry::CreateWiredDeviceType("Sav45");
const DeviceType SensorType::SEN5X=DeviceTypeRegistry::CreateWiredDeviceType("Sen5x");
const DeviceType SensorType::SEN50=DeviceTypeRegistry::CreateWiredDeviceType("Sen50");
const DeviceType SensorType::SEN54=DeviceTypeRegistry::CreateWiredDeviceType("Sen54");
const DeviceType SensorType::SEN55=DeviceTypeRegistry::CreateWiredDeviceType("Sen55");
const DeviceType SensorType::SCD30=DeviceTypeRegistry::CreateWiredDeviceType("Scd30");
const DeviceType SensorType::STC3X=DeviceTypeRegistry::CreateWiredDeviceType("Stc3x");
const DeviceType SensorType::STC31=DeviceTypeRegistry::CreateWiredDeviceType("Stc31");
const DeviceType SensorType::SGP4X=DeviceTypeRegistry::CreateWiredDeviceType("Sgp4x");
const DeviceType SensorType::SGP41=DeviceTypeRegistry::CreateWiredDeviceType("Sgp41");
const DeviceType SensorType::SEN66=DeviceTypeRegistry::CreateWiredDeviceType("Sen66");
const DeviceType SensorType::STCC4=DeviceTypeRegistry::CreateWiredDeviceType("Stcc4");

const char *sensorLabel(DeviceType sensorType) {
    return sensorType.data();
}
