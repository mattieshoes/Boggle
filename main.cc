#include <iostream>
#include "Bogglesolution.h"
#include "Boggleboard.h"

using namespace boggle;

int main() {
 
  Boggleboard b;
  b.usedice(0);

  b.print();
  Bogglesolution s = b.solve();
  s.print();
  
  return 0;
}
