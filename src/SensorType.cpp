
#include "SensorType.h"
namespace sensirion::upt::core{

const char *sensorLabel(DeviceType sensorType) {
    return sensorType.data();
}

} // end namespace

