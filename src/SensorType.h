#ifndef SENSOR_TYPE_H
#define SENSOR_TYPE_H
#include "DeviceType.h"

namespace sensirion::upt::core{

// functions to create the predefined sensor types
inline const DeviceType SCD4X(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Scd4x");
}
inline const DeviceType SFA3X(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sfa3x");
}
inline const DeviceType SFA40(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sfa4x");
}
inline const DeviceType SVM4X(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Svm4x");
}
inline const DeviceType SVM41(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Svm41");
}
inline const DeviceType SHT4X(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sht4x");
}
inline const DeviceType SAV45(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sav45");
}
inline const DeviceType SEN5X(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sen5x");
}
inline const DeviceType SEN50(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sen50");
}
inline const DeviceType SEN54(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sen54");
}
inline const DeviceType SEN55(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sen55");
}
inline const DeviceType SCD30(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Scd30");
}
inline const DeviceType STC3X(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Stc3x");
}
inline const DeviceType STC31(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Stc31");
}
inline const DeviceType SGP4X(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sgp4x");
}
inline const DeviceType SGP41(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sgp41");
};
inline const DeviceType SEN66(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Sen66");
}
inline const DeviceType STCC4(){
    return DeviceTypeRegistry::CreateWiredDeviceType("Stcc4");
}

} // end namespace
#endif /* SENSOR_TYPE_H */
