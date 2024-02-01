# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.3.0]
This is a breaking version, most APIs were reworked during this revision.
### Modified
- Renamed SensorID -> SensorType
- Introduced additional SensorTypes (for all detectable sensor versions)
- Introduced BLEGadgetType (for all detectable Sensirion BLE Gadgets)
- Replaced DataPoint by a more refined and comprehensive object, Measurement
- Replaced library examples

## [0.2.0]
### Modified
- Placed platformio.ini file in project root directory
- Switched away from using std::string

## [0.1.5]
### Added
- Printing cases for Gas Concentration SignalType

## [0.1.4]
### Added
- Gas Concentration SignalType

## [0.1.3]
### Added
- Data structure for data points
- Sensor ID enum

## [0.1.2]
### Added
- Velocity SignalType
- AV_T DataType
- CI lint check

## [0.1.1]
### Added
- Add monitor speed to platformio.ini
- README instructions for getting started

## [0.1.0]
### Added
- Sensirion BLE Protocol
- SignalType with matching String methods
