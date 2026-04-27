////////////////////////////////////////////////////////////////////////////////
//  S E N S I R I O N   AG,  Laubisruetistr. 50, CH-8712 Staefa, Switzerland
////////////////////////////////////////////////////////////////////////////////
/// @file DeviceType.h
/// This file defines the type `DeviceType`. DeviceType is an extensible
/// identifier for device prototypes created with arduino-upt-core framework
/// Device types are kept in the DeviceTypeRegistry and can be looked up from
/// there as well.

#ifndef DEVICE_TYPE_H
#define DEVICE_TYPE_H
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace sensirion::upt::core {

/// Describe how a device communicates
enum class DevicePlatform : uint8_t {
    UNDEFINED,
    BLE,
    WIRED,
};

/// Device type used to identify a device
using DeviceType = std::string_view;

/// Return type for device type query. In case the query is not successful,
/// std::null_option is used
using OptionalDeviceType = std::optional<DeviceType>;

/// Input type for device type alias. In case std::null_option is passed as
/// an argument, no alias is added
using DeviceTypeAlias = std::optional<std::string>;

/// A registry to define and store device types that are used in the framework
class DeviceTypeRegistry {

  public:
    /// Information about the device type
    struct DeviceTypeData {
        std::string label;
        DevicePlatform platform;
        DeviceTypeAlias alias;
    };

    /// Type of the container that holds the device type data
    using RegistryType = std::vector<const DeviceTypeData *>;
    using Iterator = RegistryType::iterator;

    /// Shorthand to be used when no alias is needed
    static constexpr std::nullopt_t NO_ALIAS = std::nullopt;

    /// Create a new device type with the supplied label
    ///
    /// @param label The label that is printed for the device type
    /// @param platform A flag indicating whether the device is wired or using
    /// BLE
    /// @param alias An optional alias for the device type; used for an
    /// alternative way to look up the device (used by HUMI-Gadget)
    ///
    /// @return The newly created device type or an existing device type if a
    /// type with the supplied label already exists
    static DeviceType CreateDeviceType(const std::string &label,
                                       DevicePlatform platform,
                                       DeviceTypeAlias alias);

    /// Shorthand to create a wired device type without alias
    /// @param label Name of the device
    /// @return The associated device type object
    static DeviceType CreateWiredDeviceType(const std::string &label);

    /// Shorthand to create a ble device type without alias
    /// @param label Name of the device
    /// @return The associated device type object
    static DeviceType CreateBleDeviceType(const std::string &label);

    /// Try to fetch a device type
    ///
    /// @param label_or_alias The device type can be fetched either by name of
    /// by alias
    /// @return an option including the device type or std::null_option
    static OptionalDeviceType GetDeviceType(const std::string &label_or_alias);

    /// Figure out if a device type is a wired or a ble device
    ///
    /// @param deviceType A device type that was created using the method
    /// CreateDeviceType
    ///
    /// @return The DevicePlatform that is associated with the device type
    static DevicePlatform GetDevicePlatform(DeviceType deviceType);

  private:
    /// Access the device type registry
    /// ensure creation of the container on first used
    /// @return reference to the create device type registry
    static RegistryType &deviceTypeRegistry();
};

/// Get a pointer to the c-string that represents the device type
/// @param deviceType
/// @return The device type as c-string
const char *getDeviceLabel(DeviceType deviceType);

// functions to create the predefined device types

// device types representing sensors
inline DeviceType SCD4X() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SCD4x");
}
inline DeviceType SFA3X() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SFA3x");
}
inline DeviceType SFA40() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SFA4x");
}
inline DeviceType SVM4X() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SVM4x");
}
inline DeviceType SVM41() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SVM41");
}
inline DeviceType SHT4X() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SHT4x");
}
inline DeviceType SAV45() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SAV45");
}
inline DeviceType SEN5X() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN5x");
}
inline DeviceType SEN50() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN50");
}
inline DeviceType SEN54() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN54");
}
inline DeviceType SEN55() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN55");
}
inline DeviceType SCD30() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SCD30");
}
inline DeviceType STC3X() {
    return DeviceTypeRegistry::CreateWiredDeviceType("STC3x");
}
inline DeviceType STC31() {
    return DeviceTypeRegistry::CreateWiredDeviceType("STC31");
}
inline DeviceType SGP4X() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SGP4x");
}
inline DeviceType SGP41() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SGP41");
}
inline DeviceType SEN62() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN62");
}
inline DeviceType SEN63C() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN63C");
}
inline DeviceType SEN65() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN65");
}
inline DeviceType SEN66() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN66");
}
inline DeviceType SEN68() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN68");
}
inline DeviceType SEN69C() {
    return DeviceTypeRegistry::CreateWiredDeviceType("SEN69C");
}
inline DeviceType STCC4() {
    return DeviceTypeRegistry::CreateWiredDeviceType("STCC4");
}

// Device types representing BLE Gadgets

inline DeviceType AQ_MINION() {
    return DeviceTypeRegistry::CreateBleDeviceType("AQ Minion");
}

inline DeviceType MYCO2() {
    return DeviceTypeRegistry::CreateBleDeviceType("MyCO2");
}

inline DeviceType SHT40_GADGET() {
    return DeviceTypeRegistry::CreateBleDeviceType("SHT40 Gadget");
}

inline DeviceType SHT43_GADGET() {
    return DeviceTypeRegistry::CreateBleDeviceType("SHT43 DB");
} // SHT43 DB

inline DeviceType BLE_DIY_GADGET() {
    return DeviceTypeRegistry::CreateDeviceType("DIY Gadget",
                                                DevicePlatform::BLE, "S");
}

inline DeviceType HUMI_GADGET() {
    return DeviceTypeRegistry::CreateBleDeviceType("Smart Humigadget");
} // Smart humigadget

} // namespace sensirion::upt::core

#endif // DEVICE_TYPE_H
