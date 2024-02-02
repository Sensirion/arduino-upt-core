# UPT Core

A library containing all the relevant types and definitions shared between components of the Unified Prototyping Toolkit (UPT) for ease of maintainability.
There shouldn't be a reason to use it directly, but it is being used to create libraries compatible with the rest of the UPT.

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
Please refer to the ```BasicUsage.ino``` script for a featured example on how to use the ```Measurement``` struct.

### Bluetooth Protocol
Sensirion BLE Gadgets send their measurements encoded in their device advertisements,
one way to enable data transmission without needing to establish a connection to the device.
This encoding depends on the data being transmitted (to ensure the receiver knows how to interpret the data),
and can be queried in a dictionary (implemented as a ```std::map```) provided by this library.

#### SampleType and DataType
These two identifiers (```SampleType``` is a ```uint8_t``` and ```DataType``` an ```enum```) serve as the main ways to
identify (1) the shape of the transmission message, and (2) the nature of the contents therein. The device sending the advertisement (such as an Arduino board running [Sensirion's BLE DIY Gadget software](https://github.com/Sensirion/arduino-ble-gadget)) typically knows what signals it wants to send (and therefore selects an appropriate ```DataType```), while the receiving device reads the ```SignalType``` field in the ```ManufacturerData``` part of the BLE Advertisement message and maps it to the corresponding ```DataType```.

For example, a [Sensirion MyCO<sub>2</sub> Gadget](https://sensirion.com/products/catalog/SCD4x-CO2-Gadget/) sends an advertisement identified by ```DataType::T_RH_CO2_ALT``` and  ```SignalType = 8```, and containing the temperature, relative humidity and CO<sub>2</sub> concentration measured by the device.

Please refer to the [Sensirion BLE Communication Protocol](https://github.com/Sensirion/arduino-ble-gadget/blob/master/documents/00-Sensirion_BLE_communication_protocol.pdf) for a list of available ```SignalType```s and for the structure of a Sensirion BLE Advertisement.

#### SampleConfig
Once the ```DataType``` of the message is determined, it can be used to query configuration information of the message, such as it size and signals it contains, using the provided ```sampleConfigSelector``` dictionary provided:
```cpp
SampleConfig sampleConfig = sampleConfigSelector[myDataType];
```
```SampleConfig``` contains the following fields, among others:
* ```SampleConfig.sampleSizeBytes```: useful for determining the size of the Advertisement message
* ```SampleConfig.sampleSlots```: a dictionary mapping the slots to ```SignalType```.

To pick up on the MyCO<sub>2</sub> Gadget, the corresponding ```sampleSizeBytes``` reads ```6``` (the 3 signal values transmitted get 2 bytes each), while the ```sampleSlots``` informs us of the order of the signals, the aforementioned Temperature, Relative Humidity, and CO<sub>2</sub> concentration.

#### En/De-coding functions
The signals are transmitted as ```uint16_t```. To ensure no information is lost, encoding and decoding functions are provided. Since these are not uniform (being both signal and ```DataType``` dependant), ```sampleSlots``` also provides
pointers to the appropriate conversion functions.

Please refer to the ```BLE_example.ino``` script for a featured example on how to encode/decode sensor data in a BLE Advertisement message.

## Library example scripts
Two example scripts are provided:
* ```BasicUsage```: An example showing how to use the ```Measurement``` struct to handle sensor data in general;
* ```BLE_example```: An example showing how to encode/decode senor data for transmission via BLE Advertisement. Note that the example does not actually use Bluetooth, so it can be run on a board that does not have an antenna.

On PlatformIO, the examples can be run by by executing the following command from the library's root directory (containing this README):
* For example ```BasicUsage```: ```$ pio run -t upload``` or ```$ pio run -e basicUsage -t upload``` (environment BasicUsage is default)
* For example ```BLE_example```: ```pio run -e ble_example -t upload```

In both cases, the output can be monitored by using the PlatformIO device monitor:
```bash
pio device monitor
```

Arduino IDE users can navigate to `File` -> `Examples` -> `Sensirion Gadget BLE Lib` -> **`BasicUsage`** or **`BLE_example`**, and click the upload button. The example outputs can be examined using the serial monitor (make sure to use ```115200 baud```).

## How to install
### Requirements
This library requires standard library compatibility. Some boards such as Arduino AVR Uno do not ship with this functionnality. This library was developed and tested on Espressif ESP32 boards.

### Arduino

1. Download [Arduino IDE](http://www.arduino.cc/en/main/software) and setup the environment for ESP32 platform
	* Follow [this guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)
	* Detailed Instructions for advanced users: [Arduino-ESP32](https://github.com/espressif/arduino-esp32)
2. Start the Arduino IDE and open the Library Manager by selecting `Sketch` -> `Include Library` -> `Manage Libraries...`. Search for the `Sensirion_Unified_Prototyping_Toolkit_Core` library in the `Filter your search...` field and install it by clicking the `install` button.
3. Connect your ESP32 DevKit to your computer.
4. In the Arduino IDE, make sure you have the `ESP32 Dev Module` and the correct Port selected.
5. Select `File` -> `Examples` -> `Sensirion Gadget BLE Lib` -> **`BasicUsage`**.
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