#ifndef _BLE_GADGET_TYPE_H_
#define _BLE_GADGET_TYPE_H_

#include "DeviceType.h"

namespace sensirion::upt::core{

// functions to create the predefined sensor types
    
inline const DeviceType AQ_MINION(){
    return DeviceTypeRegistry::CreateBleDeviceType("AQ Minion");
};

inline const DeviceType MYCO2(){
    return DeviceTypeRegistry::CreateBleDeviceType("MyCO2");
}

inline const DeviceType SHT40_GADGET(){
    return DeviceTypeRegistry::CreateBleDeviceType("SHT40 Gadget");
}

inline const DeviceType SHT43_GADGET(){
    return DeviceTypeRegistry::CreateBleDeviceType("SHT43 DB");
} // SHT43 DB

inline const DeviceType BLE_DIY_GADGET(){
    return DeviceTypeRegistry::CreateDeviceType("DIY Gadget", DevicePlatform::BLE, "S");
}

inline const DeviceType HUMI_GADGET(){
    return DeviceTypeRegistry::CreateBleDeviceType("Smart Humigadget");
} // Smart humigadget

} // end namespace
#endif /* _BLE_GADGET_TYPE_H_ */
