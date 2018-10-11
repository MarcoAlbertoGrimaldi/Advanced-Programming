#include <iostream>
#include <string>

int get_int() {

  int i;

  while(!(std::cin >> i)) {

    std::cin.clear();
    std::cin.ignore();
    
  }

  return i;
  
}

double get_double() {

  double i;

  while(!(std::cin >> i)) {

    std::cin.clear();
    std::cin.ignore();
    
  }

  return i;
  
}

int main() {

  std::cout << "Type an integer\n";

  std::cout << get_int() << "\n";

  std::cout << "Type a double\n";

   std::cout << get_double() << "\n";


}

