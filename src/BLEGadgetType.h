#ifndef _BLE_GADGET_TYPE_H_
#define _BLE_GADGET_TYPE_H_

#include "DeviceType.h"

namespace upt_core{
/// List of supported Sensirion BLE Gadgets
///
/// Using a struct allows to access the Device Types 
/// in the same was as the enum fields
struct BLEGadgetType{
    static const DeviceType AQ_MINION;
    static const DeviceType MYCO2;
    static const DeviceType SHT40_GADGET;
    static const DeviceType SHT43_GADGET; // SHT43 DB
    static const DeviceType BLE_DIY_GADGET;
    static const DeviceType HUMI_GADGET; // Smart humigadget
};
} // end namespace
#endif /* _BLE_GADGET_TYPE_H_ */
