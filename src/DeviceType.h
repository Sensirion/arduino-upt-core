////////////////////////////////////////////////////////////////////////////////
//  S E N S I R I O N   AG,  Laubisruetistr. 50, CH-8712 Staefa, Switzerland
////////////////////////////////////////////////////////////////////////////////
/// @file DeviceType.h
/// This file defines the type `DeviceType`. DeviceType is an extensible identifier for
/// device prototypes created with arduino-upt-core framework
/// Device types are kept in the DeviceTypeRegistry and can be looked up from there as well.

#ifndef _DEVICE_TYPE_H_
#define _DEVICE_TYPE_H_
#include <string_view>
#include <string>
#include <map>
#include <vector>
#include <optional>

namespace sensirion::upt::core{

/// Describe how a device communicates
enum class DevicePlatform: uint8_t {
    UNDEFINED,
    BLE,
    WIRED,
};

/// Device type used to identify a device
using DeviceType = std::string_view;

/// Return type for device type query. In case the query is not successful std::null_option is used
using OptionalDeviceType = std::optional<DeviceType>;

/// Input type for device type alias. In case std::null_option is passed as argument, no alias is added
using DeviceTypeAlias = std::optional<std::string>;


/// A registry to define and store device types that are used in the framework
class DeviceTypeRegistry{


public:
        
        /// Information about the device type
        struct DeviceTypeData{
            std::string label;
            DevicePlatform platform;
            DeviceTypeAlias alias;
        };

        /// Type of the container that holds the device type data
        using RegistryType = std::vector<const DeviceTypeData*>;
        using Iterator = RegistryType::iterator;

        /// Shorthand to be used when no alias is needed
        static constexpr std::nullopt_t NO_ALIAS = std::nullopt;

        /// Create a new device type with the supplied label
        ///
        /// @param label The label that is printed for the device type
        /// @param platform A flag indicating whether the device is wired or using BLE
        /// @param alias An optional alias for the device type; used for an alternative way to lookup the device (used by HUMI-Gadget)
        ///
        /// @return The new created device type or an existing device type if a type with the supplied label already exists
        static DeviceType CreateDeviceType(const std::string& label, const DevicePlatform platform, 
                                                     const DeviceTypeAlias alias);

        /// Shorthand to create a wired device type without alias
        /// @param label Name of the device
        /// @return The associated device type object
        static DeviceType CreateWiredDeviceType(const std::string& label);

        /// Shorthand to create a ble device type without alias
        /// @param label Name of the device
        /// @return The associated device type object
        static DeviceType CreateBleDeviceType(const std::string& label);

        /// Try to fetch a device type
        ///
        /// @param label_or_alias The device type can be fetched either by name of by alias
        /// @return an option including the device type or std::nullopt
        static OptionalDeviceType GetDeviceType(const std::string& label_or_alias);

        /// Figure out if a device type is a wired or a ble device
        ///
        /// @param deviceType A device type that was created using the method CreateDeviceType
        ///
        /// @return The DevicePlatform that is associated with the device type
        static DevicePlatform GetDevicePlatform(const DeviceType deviceType);

    private:

        /// Access the device type registry
        /// ensure creation of the container on first used
        /// @return reference to the create device type registry
        static RegistryType& deviceTypeRegistry();

};

/// Get a pointer to the c-string that represents the device type
/// @param deviceType 
/// @return The device type as c-string
const char *getDeviceLabel(DeviceType deviceType);

// functions to create the predefined device types

// device types representing sensors
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

// Device types representing BLE Gadgets
    
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

} // namespace sensirion::upt::core

#endif //_DEVICE_TYPE_H_
