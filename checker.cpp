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
  tempCheck = isValueWithinRange(temperature , 0, 45);
  socCheck = isValueWithinRange(soc , 20, 80);
  if(tempCheck || socCheck || chargeRate > 0.8)
  {
    return false;
  }
 else
 {
   return true;
 }
 

int main() 
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
