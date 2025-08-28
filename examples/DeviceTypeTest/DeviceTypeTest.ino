#include "Arduino.h"
#include "Sensirion_UPT_Core.h"
#include "DeviceType.h"
#include "BLEGadgetType.h"
#include "SensorType.h"

using namespace sensirion::upt::core;

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(1000);

    Serial.println("======================================");
    Serial.println("--------------------------------------");
    Serial.println("DeviceType Test:");
    Serial.println("--------------------------------------");
    Serial.println("\n======================================\n");
}

void loop() {
    delay(2000);
    Serial.println("Lookup and compare device types and platforms");
    Serial.println("=============================================\n");
    
    std::string bleDevLabel{BLE_DIY_GADGET()};
    std::string wiredDevLabel{SAV45()};
    std::string bleDevAlias("S");
    auto wiredDevType = DeviceTypeRegistry::GetDeviceType(wiredDevLabel)
        .value_or(DeviceType("undefined"));
    [[maybe_unused]]auto wired = DeviceTypeRegistry::GetDevicePlatform(wiredDevType);
    Serial.println(wiredDevLabel.c_str());
    Serial.println(deviceLabel(wiredDevType));
    Serial.println(devicePlatformLabel(wiredDevType));

    auto bleDevType = DeviceTypeRegistry::GetDeviceType(bleDevLabel)
        .value_or(DeviceType("undefined_ble_type"));
    auto bleDevType2 = DeviceTypeRegistry::GetDeviceType(bleDevAlias)
        .value_or(DeviceType("undefined_ble_type"));

    Serial.printf("type retrieved with alias matches original: %i\n", bleDevType==bleDevType2);
    [[maybe_unused]]auto ble = DeviceTypeRegistry::GetDevicePlatform(bleDevType2);

    Serial.println(deviceLabel(bleDevType2));
    Serial.println(devicePlatformLabel(bleDevType));
    
}

