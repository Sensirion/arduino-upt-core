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

        // using NO_ALIAS = std::nullopt;

        using RegistryType = std::vector<const DeviceTypeData*>;
        using Iterator = RegistryType::iterator;

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

        static DeviceType CreateWiredDeviceType(const std::string& label);

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


#endif //_DEVICE_TYPE_H_
