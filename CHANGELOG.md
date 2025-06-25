# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Unreleased

## [0.6.0] - 2025-06-25

### Added
- Added STCC4 to sensor types
- Added SFA40 to sensor types

## [0.5.1] - 2024-12-11

### Fixed

- Fix download definition T_RH_VOC_NOX_PM25 to only have 1 sample per download pack.
  With 2 there was a buffer overflow leading to a crash when starting a data download 
  for a gadget built with arduino-ble-gadget using T_RH_VOC_NOX_PM25 (e.g. SEN55 Example)
  The fixed definition is supported by MyAmbience Version 3.5.0 onwards.

## [0.5.0] - 2024-09-09

### Added
- Added Farenheit unit

## [0.4.0] - 2024-07-25

### Added
- Added SEN66 to sensor types

## [0.3.2] - 2024-06-19

### Fixed
- Add missing string import to BLEProtocol.h and Measurement.h

## [0.3.1] - 2024-05-21

### Fixed
- Sample size for type RH_CO2_ALT resp Sample type 2 changed from 6 to 8 Bytes as specified in 
  https://github.com/Sensirion/arduino-ble-gadget/blob/master/documents/00-Sensirion_BLE_communication_protocol.pdf

## [0.3.0] - Breaking Changes

### Added

-   Additional SensorTypes for all detectable sensor versions
-   BLEGadgetType enum for Sensirion BLE Gadgets
-   Raw VOC and NOX signal types
-   Utility to print 'Measurement' to Serial

### Modified

-   Renamed SensorID to SensorType
-   Replaced DataPoint with a more comprehensive Measurement object
-   Updated library examples
-   Updated library APIs
-   Renamed Library in Arduino and PlatformIO registry

## [0.2.0]

### Modified

-   Placed platformio.ini file in project root directory
-   Switched away from using std::string

## [0.1.5]

### Added

-   Printing cases for Gas Concentration SignalType

## [0.1.4]

### Added

-   Gas Concentration SignalType

## [0.1.3]

### Added

-   Data structure for data points
-   Sensor ID enum

## [0.1.2]

### Added

-   Velocity SignalType
-   AV_T DataType
-   CI lint check

## [0.1.1]

### Added

-   Add monitor speed to platformio.ini
-   README instructions for getting started

## [0.1.0]

### Added

-   Sensirion BLE Protocol
-   SignalType with matching String methods


[Unreleased]: https://github.com/sensirion/arduino-upt-core/compare/v0.3.1...HEAD
[0.3.1]: https://github.com/sensirion/arduino-upt-core/compare/v0.3.0...v0.3.1
[0.3.0]: https://github.com/sensirion/arduino-upt-core/compare/v0.2.0...v0.3.0
[0.2.0]: https://github.com/sensirion/arduino-upt-core/compare/v0.1.5...v0.2.0
[0.1.5]: https://github.com/sensirion/arduino-upt-core/compare/v0.1.4...v0.1.5
[0.1.4]: https://github.com/sensirion/arduino-upt-core/compare/v0.1.3...v0.1.4
[0.1.3]: https://github.com/sensirion/arduino-upt-core/compare/v0.1.2...v0.1.3
[0.1.2]: https://github.com/sensirion/arduino-upt-core/compare/v0.1.1...v0.1.2
[0.1.1]: https://github.com/sensirion/arduino-upt-core/compare/v0.1.0...v0.1.1
[0.1.0]: https://github.com/sensirion/arduino-upt-core/releases/tag/v0.1.0
