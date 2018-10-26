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

  const unsigned int n{4};

  std::string unit[] = {"meters","liters","inches","pints"};
  double coeff[] = {39.37, 2.113, 0.02524, 0.4732};
  
  std::cout << "Type the number equivalent to the conversion you desire: \n";
  for (int i{0}; i<n; i++) {
    std::cout << i << "- from " << unit[i] << " to " << unit[(i+n/2)%n] <<"\n";
  }

  int t{0};
  std::cin >> t;

  std::cout << "Type the value: \n";    
  double v{get_double()};
 
  std::cout << v << " " << unit[t] << " is equal to: " << v*coeff[t] << " " << unit[(t+n/2)%n] << ".\n";
}
