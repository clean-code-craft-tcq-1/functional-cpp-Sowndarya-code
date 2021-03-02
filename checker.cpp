#include <assert.h>
#include <iostream>
using namespace std;

bool isValueOutOfRange (float value, float min, float max)
{
  bool valueOutOfRange = (value < min) || (value > max);
  return valueOutOfRange;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  float tempr_min = 0.0F, tempr_max = 45.0F;
  float soc_min = 20.0F, soc_max = 80.0F;
  float charge_rate_max = 0.8F;
  bool tempCheck = isValueOutOfRange(temperature , tempr_min, tempr_max);
  bool socCheck = isValueOutOfRange(soc , soc_min, soc_max);
  bool batteryIsNotOkay = tempCheck || socCheck || chargeRate > charge_rate_max;
  return !batteryIsNotOkay;
}

int main() 
{
  assert(batteryIsOk(25.0F, 70.0F, 0.7F) == true);
  assert(batteryIsOk(50.0F, 85.0F, 0.0F) == false);
}
