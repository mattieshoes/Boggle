#include <iostream>
#include "Boggle.h"

using namespace boggle;

int main() {
 
  Boggleboard b;
  b.print();
  Bogglesolution s = b.solve();
  s.print();
//  b.printdict();
  
  return 0;
}
