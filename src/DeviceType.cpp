#include "DeviceType.h"
#include <algorithm>


/// Helper function to search the registry
/// @param key key to search for
/// @param iterator iterator to current element
/// @return true if the element matches the key
bool FindEntry(const std::string& key, 
    const DeviceTypeRegistry::DeviceTypeData& entry){
    if(entry.label == key.data()){
        return true;
    }
    if(entry.alias.has_value()){
        if (entry.alias.value()==key.data()){
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
DeviceType DeviceTypeRegistry::CreateDeviceType(const std::string& label, const DevicePlatform platform, const OptionalDeviceTypeAlias alias){
    for ( const auto it: deviceTypeRegistry){
        if (it.label==label){
            return DeviceType(it.label);
        }
    }
    auto device_type_data = DeviceTypeData{label, platform, alias};
    deviceTypeRegistry.push_back(device_type_data);
    return DeviceType(device_type_data.label);
}

/// Try to fetch a device type
///
/// @param label_or_alias The device type can be fetched either by name of by alias
/// @return an option including the device type or std::nullopt
OptionalDeviceType DeviceTypeRegistry::GetDeviceType(const std::string& label_or_alias){
    const auto it = std::find_if(deviceTypeRegistry.begin(), deviceTypeRegistry.end(),
                                 [=](auto entry){return FindEntry(label_or_alias, entry );});
    if (it != deviceTypeRegistry.end()){
        return DeviceType((*it).label);
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
    const auto it = std::find_if(deviceTypeRegistry.begin(), deviceTypeRegistry.end(),
                                 [&key](auto entry){return FindEntry(key, entry );});
    if (it != deviceTypeRegistry.end()){
        return (*it).platform;
    }
    return DevicePlatform::UNDEFINED;
}

/// vector to hold the data of the device_type
DeviceTypeRegistry::RegistryType DeviceTypeRegistry::deviceTypeRegistry;
const OptionalDeviceTypeAlias DeviceTypeRegistry::NO_ALIAS{std::nullopt};