#ifndef _BLE_GADGET_TYPE_H_
#define _BLE_GADGET_TYPE_H_

#include "DeviceType.h"

namespace sensirion::upt::core{
/// List of supported Sensirion BLE Gadgets
///
/// Using a struct allows to access the Device Types 
/// in the same was as the enum fields
struct BLEGadgetType{
    
    static const DeviceType AQ_MINION(){
        return DeviceTypeRegistry::CreateBleDeviceType("AQ Minion");
    };
    
    static const DeviceType MYCO2(){
        return DeviceTypeRegistry::CreateBleDeviceType("MyCO2");
    }

    static const DeviceType SHT40_GADGET(){
        return DeviceTypeRegistry::CreateBleDeviceType("SHT40 Gadget");
    }
    static const DeviceType SHT43_GADGET(){
        return DeviceTypeRegistry::CreateBleDeviceType("SHT43 DB");
    } // SHT43 DB
    static const DeviceType BLE_DIY_GADGET(){
        return DeviceTypeRegistry::CreateDeviceType("DIY Gadget", DevicePlatform::BLE, "S");
    }
    static const DeviceType HUMI_GADGET(){
        return DeviceTypeRegistry::CreateBleDeviceType("Smart Humigadget");
    } // Smart humigadget
};
} // end namespace
#endif /* _BLE_GADGET_TYPE_H_ */
