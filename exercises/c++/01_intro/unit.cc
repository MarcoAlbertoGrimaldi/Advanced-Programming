#include <iostream>
#include <string>

double get_double() {

  double i;

  while(!(std::cin >> i)) {

    std::cin.clear();
    std::cin.ignore();
    
  }

  return i;
  
}

int main() {
  
  std::cout << "Type a measure in inches: \n";
  double i{get_double()};
  double coeff{0.0252};
  std::cout << "is equal to: " << i*coeff << "meters.\n";
}
