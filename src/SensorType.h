#ifndef SENSOR_TYPE_H
#define SENSOR_TYPE_H
#include "DeviceType.h"

namespace upt_core{

/* X stands for any sensor version in a family, ie. SHT4X can be assigned to any
 * sensor in Sensirion's SHT4 series of sensors. */
struct SensorType {
    static const DeviceType SCD4X(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Scd4x");
    }
    static const DeviceType SFA3X(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sfa3x");
    }
    static const DeviceType SFA40(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sfa4x");
    }
    static const DeviceType SVM4X(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Svm4x");
    }
    static const DeviceType SVM41(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Svm41");
    }
    static const DeviceType SHT4X(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sht4x");
    }
    static const DeviceType SAV45(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sav45");
    }
    static const DeviceType SEN5X(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sen5x");
    }
    static const DeviceType SEN50(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sen50");
    }
    static const DeviceType SEN54(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sen54");
    }
    static const DeviceType SEN55(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sen55");
    }
    static const DeviceType SCD30(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Scd30");
    }
    static const DeviceType STC3X(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Stc3x");
    }
    static const DeviceType STC31(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Stc31");
    }
    static const DeviceType SGP4X(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sgp4x");
    }
    static const DeviceType SGP41(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sgp41");
    };
    static const DeviceType SEN66(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Sen66");
    }
    static const DeviceType STCC4(){
        return DeviceTypeRegistry::CreateWiredDeviceType("Stcc4");
    }
};
} // end namespace
#endif /* SENSOR_TYPE_H */
