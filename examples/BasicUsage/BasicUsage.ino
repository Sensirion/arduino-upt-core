#include "Arduino.h"
#include "Sensirion_UPT_Core.h"

DataPoint dummyDataPoint = {SignalType::RELATIVE_HUMIDITY_PERCENTAGE, 0, 0,
                            sensorName(SensorID::SHT4X)};

DataPoint randomDataPoint();

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(1000);

    Serial.println("\n--------------------------------------\n");    

    Serial.printf("Sensor: %s\nquantity: %s\nunit: %s\n",
                  dummyDataPoint.sourceDevice,
                  quantityOf(dummyDataPoint.signalType),
                  unitOf(dummyDataPoint.signalType));
    
    Serial.println("\n--------------------------------------\n");    
}

void loop() {
    delay(1000); // 1 second
    dummyDataPoint = randomDataPoint();
    Serial.printf("%s measured %s: %.2f\t@%i\n", dummyDataPoint.sourceDevice,
                  quantityOf(dummyDataPoint.signalType), dummyDataPoint.value,
                  dummyDataPoint.timeStamp);
}

DataPoint randomDataPoint() {
    return DataPoint(static_cast<SignalType>(random(1, 13)),
                     0.01 * static_cast<float>(random(1000)), millis(),
                     sensorName(static_cast<SensorID>(random(1, 11))));
}
