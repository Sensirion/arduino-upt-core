#include "Arduino.h"
#include "Sensirion_UPT_Core.h"
#include "DeviceType.h"
#include "BLEGadgetType.h"
#include "SensorType.h"

using namespace upt_core;

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
    delay(4000);
    Serial.println("Lookup and compare device types and platforms");
    Serial.println("=============================================\n");
    
    std::string bleDevLabel{BLEGadgetType::BLE_DIY_GADGET};
    std::string wiredDevLabel{SensorType::SAV45};
    std::string bleDevAlias("S");
    auto wiredDevType = DeviceTypeRegistry::GetDeviceType(wiredDevLabel)
        .value_or(DeviceType("undefined"));
    auto wired = DeviceTypeRegistry::GetDevicePlatform(wiredDevType);
    Serial.println(wiredDevLabel.c_str());
    Serial.println(deviceLabel(wired, wiredDevType));
    Serial.println(devicePlatformLabel(wired, wiredDevType));

    auto bleDevType = DeviceTypeRegistry::GetDeviceType(bleDevLabel)
        .value_or(DeviceType("undefined_ble_type"));
    auto bleDevType2 = DeviceTypeRegistry::GetDeviceType(bleDevAlias)
        .value_or(DeviceType("undefined_ble_type"));

    Serial.printf("type retrieved with alias matches original: %i\n", bleDevType==bleDevType2);
    auto ble = DeviceTypeRegistry::GetDevicePlatform(bleDevType2);

    Serial.println(deviceLabel(ble, bleDevType2));
    Serial.println(devicePlatformLabel(ble, bleDevType));
    
}

