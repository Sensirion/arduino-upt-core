#include "Arduino.h"
#include "Sensirion_UPT_Core.h"

SignalType testSignalType = SignalType::RELATIVE_HUMIDITY_PERCENTAGE;
int dummyValue = 0;

void setup() {
    Serial.begin(115200);
    Serial.println();
    Serial.print("quantity: ");
    Serial.println(quantityOf(testSignalType).c_str());
    Serial.print("unit: ");
    Serial.println(unitOf(testSignalType).c_str());
}

void loop() {
    Serial.print(quantityOf(testSignalType).c_str());
    Serial.print(" ");
    Serial.print(dummyValue);
    Serial.print(" ");
    Serial.println(unitOf(testSignalType).c_str());

    dummyValue += 1;
    dummyValue = dummyValue % 100;
    delay(1000); // 1 second
}
