#include "DeviceType.h"
#include "Measurement.h"
#include "BLEProtocol.h"

#include <unity.h>

using namespace sensirion::upt::core;

void test_ble_device() {
    DeviceType device_t = BLE_DIY_GADGET();
    std::string device_label{device_t};
    DeviceType device_t_bis = DeviceTypeRegistry::GetDeviceType(device_label).value_or(DeviceType("undefined_ble_type"));

    TEST_ASSERT_TRUE(device_t == device_t_bis);
}

void test_device_alias() {
    DeviceType ble_device_t = BLE_DIY_GADGET();
    std::string ble_device_alias("S");
    DeviceType device_t_from_alias = DeviceTypeRegistry::GetDeviceType(ble_device_alias).value_or(DeviceType("undefined_ble_type"));

    TEST_ASSERT_TRUE(ble_device_t == device_t_from_alias);
}

void test_get_wired_platform() {
    DeviceType wired_device_type = SHT4X();
    DevicePlatform platform = DeviceTypeRegistry::GetDevicePlatform(wired_device_type);

    TEST_ASSERT_TRUE(platform == DevicePlatform::WIRED);
}

void test_get_ble_platform() {
    DeviceType ble_device_type = BLE_DIY_GADGET();
    DevicePlatform platform = DeviceTypeRegistry::GetDevicePlatform(ble_device_type);

    TEST_ASSERT_TRUE(platform == DevicePlatform::BLE);
}

void test_device_label() {
    DeviceType wired_device_type = SHT4X();
    std::string label = deviceLabel(wired_device_type);

    TEST_ASSERT_TRUE(label == "Sht4x");
}

void test_get_sample_configuration() {
    auto sampleConfiguration = GetSampleConfiguration(DataType::T_RH_V3);
    TEST_ASSERT_TRUE(sampleConfiguration.sampleSlots[SignalType::TEMPERATURE_DEGREES_CELSIUS].encodingFunction);
    TEST_ASSERT_TRUE(sampleConfiguration.sampleSlots[SignalType::RELATIVE_HUMIDITY_PERCENTAGE].encodingFunction);
}

void setup() {
    UNITY_BEGIN();

    RUN_TEST(test_ble_device);
    RUN_TEST(test_device_alias);
    RUN_TEST(test_get_wired_platform);
    RUN_TEST(test_get_ble_platform);
    RUN_TEST(test_device_label);
    RUN_TEST(test_get_sample_configuration);

    UNITY_END();
}

[[maybe_unused]]
void loop() {
    // not used
}