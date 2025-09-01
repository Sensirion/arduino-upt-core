#include "DeviceType.h"
#include <algorithm>
#include "Arduino.h"

namespace sensirion::upt::core{

/// Helper function to search the registry
/// @param key key to search for
/// @param iterator iterator to current element
/// @return true if the element matches the key
bool FindEntry(const std::string& key, 
    const DeviceTypeRegistry::DeviceTypeData* entry){
  
    if(entry->label == key){
        return true;
    }
    if(entry->alias.has_value()){
        if (entry->alias.value()==key){
            return true;
        }
    }
    return false;
}


/// Create a new device type with the supplied label
///
/// @param label The label that is printed for the device type
/// @param platform A flag indicating whether the device is wired or using BLE
/// @param alias An optional alias for the device type; used for an alternative way to lookup the device (used by HUMI-Gadget)
///
/// @return The new created device type or an existing device type if a type with the supplied label already exists
DeviceType DeviceTypeRegistry::CreateDeviceType(const std::string& label, const DevicePlatform platform, const DeviceTypeAlias alias){
    RegistryType& registry = deviceTypeRegistry();
    const DeviceTypeRegistry::Iterator it = std::find_if(registry.begin(), 
                                                         registry.end(),
                                 [=](auto entry){return FindEntry(label, entry );});                            
    if (it != registry.cend()){
        return DeviceType((*it)->label);
    }
    DeviceTypeData *pDeviceData = new DeviceTypeData{label, platform, alias};
    assert(pDeviceData);
    registry.push_back(pDeviceData);
    return DeviceType(registry.back()->label); 
}

DeviceType DeviceTypeRegistry::CreateWiredDeviceType(const std::string& label){
    return CreateDeviceType(label, DevicePlatform::WIRED, DeviceTypeRegistry::NO_ALIAS);
}

DeviceType DeviceTypeRegistry::CreateBleDeviceType(const std::string& label){
    return CreateDeviceType(label, DevicePlatform::BLE, DeviceTypeRegistry::NO_ALIAS);
}

/// Try to fetch a device type
///
/// @param label_or_alias The device type can be fetched either by name of by alias
/// @return an option including the device type or std::nullopt
OptionalDeviceType DeviceTypeRegistry::GetDeviceType(const std::string& label_or_alias){
    RegistryType& registry = deviceTypeRegistry();
    const DeviceTypeRegistry::Iterator it = std::find_if(registry.begin(), registry.end(),
                                 [=](const auto &entry){return FindEntry(label_or_alias, entry );});
    if (it != registry.cend()){
        return DeviceType((*it)->label);
    }
    return std::nullopt;
}

/// Figure out if a device type is a wired or a ble device
///
/// @param deviceType A device type that was created using the method CreateDeviceType
///
/// @return The DevicePlatform that is associated with the device type
DevicePlatform DeviceTypeRegistry::GetDevicePlatform(const DeviceType deviceType){
    std::string key{deviceType.data()};
    RegistryType& registry = deviceTypeRegistry();
    const DeviceTypeRegistry::Iterator it = std::find_if(registry.begin(), registry.end(),
                                 [&key](const auto &entry){return FindEntry(key, entry );});
    if (it != registry.end()){
        return (*it)->platform;
    }
    return DevicePlatform::UNDEFINED;
}


DeviceTypeRegistry::RegistryType& 
DeviceTypeRegistry::deviceTypeRegistry(){
    // create a new registry on the heap; this will never be reclaimed!
    static RegistryType* registry = new RegistryType();
    return *registry;
}


const char *getDeviceLabel(DeviceType deviceType) {
    return deviceType.data();
}

} // end namespace

