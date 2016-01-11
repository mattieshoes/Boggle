#include <iostream>
#include "Bogglesolution.h"
#include "Boggleboard.h"

using namespace boggle;

int main() {
 
  Boggleboard b;
  b.usedice(0);

  b.print();
  b.solution.print();
  
  return 0;
}
