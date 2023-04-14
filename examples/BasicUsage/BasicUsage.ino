#include "Arduino.h"
#include "Sensirion_UPT_Core.h"

DataPoint dummyDataPoint = {SignalType::RELATIVE_HUMIDITY_PERCENTAGE, 0, 0,
                            sensorName(SensorID::SHT4X)};

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(1000);
    Serial.print("Sensor: ");
    // Serial doesn't know std::string objects, so they have to converted
    // to C style strings using c_str()
    Serial.println(dummyDataPoint.sourceDevice.c_str());
    Serial.print("quantity: ");
    Serial.println(quantityOf(dummyDataPoint.signalType).c_str());
    Serial.print("unit: ");
    Serial.println(unitOf(dummyDataPoint.signalType).c_str());
    Serial.println();
}

void loop() {
    Serial.print(quantityOf(dummyDataPoint.signalType).c_str());
    Serial.print(": ");
    Serial.print(dummyDataPoint.value);
    Serial.print(unitOf(dummyDataPoint.signalType).c_str());
    Serial.print(", @");
    Serial.println(dummyDataPoint.timeStamp);
    dummyDataPoint.value += 1;
    dummyDataPoint.value =
        static_cast<float>(static_cast<int>(dummyDataPoint.value) % 100);
    dummyDataPoint.timeStamp = millis();
    delay(1000); // 1 second
}
