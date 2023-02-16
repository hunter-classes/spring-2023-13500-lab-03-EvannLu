#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  //Task A
  std::cout << "\n";
  std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons \n \n";

  //Task B
  std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons \n";
  std::cout << "maximum storage in East basin: " << get_max_east() << " billion gallons \n \n";

  //Task C
  std::cout << "Compare East and West basin: \n";
  std::cout << "09/13/2018: " << compare_basins("09/13/2018") << "\n";
  std::cout << "09/14/2018: " << compare_basins("09/14/2018") << "\n";
  std::cout << "09/15/2018: " << compare_basins("09/15/2018") << "\n";
  std::cout << "09/16/2018: " << compare_basins("09/16/2018") << "\n";
  std::cout << "09/17/2018: " << compare_basins("09/17/2018") << "\n \n";

  //Task D
  std::cout << "Reverse-order: \n";
  reverse_order("05/29/2018", "06/02/2018");
  
  return 0;
}