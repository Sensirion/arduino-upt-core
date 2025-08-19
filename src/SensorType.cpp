
#include "SensorType.h"
namespace upt_core{

const char *sensorLabel(DeviceType sensorType) {
    return sensorType.data();
}

} // end namespace

