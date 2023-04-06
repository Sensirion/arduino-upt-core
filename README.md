# UPT Core

A library containing all the relevant types and definitions shared between components of the Unified Prototyping Toolkit (UPT) for ease of maintainability.
There shouldn't be a reason to use it directly, but could be used to create custom libraries compatible with the rest of the UPT.

## Getting started

To test this library, you can run the `Basic_Usage` example in the `examples` folder. For this you can use the Arduino IDE or PlatformIO. If you are on a Unix System, it is highly recommend to use the PlatformIO CLI as it way more straight forward to set up.

### Arduino

1. Download [Arduino IDE](http://www.arduino.cc/en/main/software) and setup the environment for ESP32 platform
	* Follow [this guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html)
	* Detailed Instructions for advanced users: [Arduino-ESP32](https://github.com/espressif/arduino-esp32)
2. Start the Arduino IDE and open the Library Manager by selecting `Sketch` -> `Include Library` -> `Manage Libraries...`. Search for the `Sensirion_Unified_Prototyping_Toolkit_Core` library in the `Filter your search...` field and install it by clicking the `install` button.
3. Connect your ESP32 DevKit to your computer.
4. In the Arduino IDE, make sure you have the `ESP32 Dev Module` and the correct Port selected.
5. Select `File` -> `Examples` -> `Sensirion Gadget BLE Lib` -> **`Basic_Usage`**.
6. Click the upload button.

### PlatformIO

1. To install the PlatformIO Core, follow the steps detailed [here](https://docs.platformio.org/en/latest/core/installation/methods/installer-script.html).
2. Install the library using the terminal:
```bash
pio lib install Sensirion_Unified_Prototyping_Toolkit_Core
```
3. Compile, Upload and view Serial output using the terminal:

Note that theses commands must be called from the `BasicUsage` directory, where the `platformio.ini` file resides.
```bash
pio run -t upload
```
```bash
pio device monitor -b 115200
```
