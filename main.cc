#include <iostream>
#include "Boggle.h"

using namespace boggle;

int main() {
 
  Boggleboard b;
  b.usedice(0);

  for (int i=0; i<1; i++) {
    b.roll();
    Bogglesolution s = b.solve();
  }
  return 0;
}
