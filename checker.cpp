#include <assert.h>
#include <iostream>
using namespace std;

namespace
{
  const float tempr_min = 0.0F, tempr_max = 45.0F;
  const float soc_min = 20.0F, soc_max = 80.0F;
  const float charge_rate_max = 0.8F;
}
bool isValueOutOfRange (float value, float min, float max)
{
  bool valueOutOfRange = (value < min) || (value > max);
  return valueOutOfRange;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  bool tempCheck = isValueOutOfRange(temperature , tempr_min, tempr_max);
  bool socCheck = isValueOutOfRange(soc , soc_min, soc_max);
  bool batteryIsNotOkay = tempCheck || socCheck || chargeRate > charge_rate_max;
  return !batteryIsNotOkay;
}

int main() 
{
  assert(batteryIsOk(25.0F, 70.0F, 0.7F) == true);  // all okay
  assert(batteryIsOk(50.0F, 85.0F, 0.0F) == false); // temp and soc high
  assert(batteryIsOk(50.0F, 65.0F, 0.0F) == false); // temp high
  assert(batteryIsOk(-50.0F, 80.0F, 0.0F) == false); // temp low
  assert(batteryIsOk(40.0F, 15.0F, 0.0F) == false); // soc low
  assert(batteryIsOk(40.0F, 85.0F, 0.0F) == false); // soc high
  assert(batteryIsOk(40.0F, 65.0F, 0.81F) == false); // charge rate high
}
