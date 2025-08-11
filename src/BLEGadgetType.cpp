#include "BLEGadgetType.h"
#include <Arduino.h>
#include "DeviceType.h"
namespace upt_core{
const DeviceType BLEGadgetType::AQ_MINION = DeviceTypeRegistry::CreateBleDeviceType("AQ Minion");
const DeviceType BLEGadgetType::BLE_DIY_GADGET = DeviceTypeRegistry::CreateDeviceType("DIY Gadget", DevicePlatform::BLE, "S");
const DeviceType BLEGadgetType::MYCO2 = DeviceTypeRegistry::CreateBleDeviceType("MyCO2");
const DeviceType BLEGadgetType::SHT40_GADGET = DeviceTypeRegistry::CreateBleDeviceType("SHT40 Gadget");
const DeviceType BLEGadgetType::SHT43_GADGET = DeviceTypeRegistry::CreateBleDeviceType("SHT43 DB");
const DeviceType BLEGadgetType::HUMI_GADGET = DeviceTypeRegistry::CreateBleDeviceType("Smart Humigadget");
} // end namespace
