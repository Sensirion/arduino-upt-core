# UPT Core

A library containing all the relevant types and definitions shared between components of the Unified Prototyping Toolkit (UPT) for ease of maintainability.
There shouldn't be a reason to use it directly, but it is being used to create libraries compatible with the rest of the UPT.

## Getting started

To test this library, you can run the `BasicUsage` example in the `examples` folder. For this you can use the Arduino IDE or PlatformIO. If you are on a Unix System, it is highly recommend to use the PlatformIO CLI as it way more straight forward to set up.

### Arduino

1. Download [Arduino IDE](http://www.arduino.cc/en/main/software) and setup the environment for ESP32 platform
	* Follow [this guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)
	* Detailed Instructions for advanced users: [Arduino-ESP32](https://github.com/espressif/arduino-esp32)
2. Start the Arduino IDE and open the Library Manager by selecting `Sketch` -> `Include Library` -> `Manage Libraries...`. Search for the `Sensirion_Unified_Prototyping_Toolkit_Core` library in the `Filter your search...` field and install it by clicking the `install` button.
3. Connect your ESP32 DevKit to your computer.
4. In the Arduino IDE, make sure you have the `ESP32 Dev Module` and the correct Port selected.
5. Select `File` -> `Examples` -> `Sensirion Gadget BLE Lib` -> **`Basic_Usage`**.
6. Connect your board and click the upload button.

### PlatformIO

1. To install the PlatformIO Core, follow the steps detailed [here](https://docs.platformio.org/en/latest/core/installation/methods/installer-script.html).
2. Install the library using the terminal:
```bash
pio lib install Sensirion_UPT_Core
```
3. After you've conected your board, Compile, Upload and view Serial output using the terminal:
```bash
pio run -t upload && pio device monitor
```
As of November '23, platformio cannot compile ```.ino``` files if they're in a subdirectory of the project directory. Thus, the example ```.ino``` file is copied to a ```.cpp``` file during the build process.

The example script will now display mock sensor measurements in the console.

## Philosophy behind this library

### Introduction:

Goal of this library is to provide a uniform design language across all UPT modules when handling sensor data, for convenient flow of information and preserving metadata.

Fundamentally, a data point in the UPT ecosystem comes from one of two sources:
* Wired: signal readings retrieved via eg. i2c communication
* Bluetooth Low Energy (BLE): signal readings transimtted via BLE
       advertisement from a Sensirion demo device

Unfortunately, further classification of a data point's origin is tricky:
* The sensor authoring a measurement is not transmitted via BLE, it is thus
       for example not possible to distinguish between Temperature readings from
       SCD4X or SHT4X if received via BLE
* Not all wired sensors support exact sensor classification. For example,
       while we know that a sensor responding to i2c commands on address ```0x62```
       belongs in the SCD4X family of sensors, we have no way of knowing if it
       is a SCD40 or SCD41.

These two reasons motivate why we distinguish two sensor types, ```BLEGadgetType```
and ```SensorType```, and the granularity of their definitions. To counter this
granularity, fields for storing the authoring sensor's serial number or MAC
address (depending on whether the data was received via i2c or BLE) are
provided, to ensure a unique identifier is made available.

### Measurement creation Pipeline:

To enable both total characterization and efficient storage of large quantities
of measurements, it was decided to encapsulate the actual values in different
layers. Let us go over each of the objects that make up a ```Measurement```:

#### DataPoint:

At first, some measurement is either made via i2c, or received via interception
of a BLE advertisement. This allows us to populate the ```DataPoint``` struct:
```cpp
DataPoint(
    t_offset = *Milliseconds since startup*
    value = *Signal value*
);
```

We measure a relative time since startup because of its easy availability
anywhere in the code, through the built-in Arduino method ```millis()```. Conversion
to Epoch (or another time format) usually requires an internet connection,
making it less versatile. The underlying data type of the ```value``` field depends on the sensor and the signal being measured. For ease of interoperability, all values (independently of their original type) are stored as ```float``` in the ```DataPoint```.

#### SignalType:

Any kind of signal that can be measured by a Sensirion sensor is available as
a ```SignalType```. Both a description of the physical quantity being measured and the
SI units of the measurement can be queried through the provided methods ```unitOf()```
and ```quantityOf()```. The ```SignalType```s of measurements by Sensirion's SCD4X series of CO<sub>2</sub> sensors are for example

```cpp
SignalType::CO2_PARTS_PER_MILLION
SignalType::TEMPERATURE_DEGREES_CELSIUS
SignalType::RELATIVE_HUMIDITY_PERCENT
```

#### MetaData:

The metadata encodes information regarding a measurement's origin:
```cpp
MetaData(
    devicePlatform = *WIRED or BLE*;
    deviceID = *MAC address or sensor serial No.*;
    DeviceType = *BLEGadgetType or SensorType*;
);
```

The first field, devicePlatform, enables us to interpret information contained
in the other two fields. A method to obtain a descriptive string of the device
type is available with ```deviceLabel()```. The ```DeviceType``` is one of the
available ```BLEGadgetTypes``` or ```SensorTypes``` available in the Sensirion ecosystem.

To pick up on the SCD4X example above, assuming its signals are retrieved using UPT Sensor Autodetection, the ```MetaData``` would look as such:
```cpp
MetaData(
    devicePlatform = DevicePlatform::WIRED;
    deviceID = 151181767251340; // Some 48-bit int
    DeviceType = SensorType::SCD4X;
);
```

### Bluetooth Protocol
Sensirion BLE Gadgets send their measurements encoded in their device advertisements,
one way to enable data transmission without needing to establish a connection to the device.
Utility functions used to retrieve the measurements from advertisements are also contained in
this library, but we won't go over their use in this example. Pleaser refer to [this guide](https://github.com/Sensirion/arduino-ble-gadget/blob/master/documents/00-Sensirion_BLE_communication_protocol.pdf)
for further information on how Sensirion BLE Gadgets broadcast their data.
