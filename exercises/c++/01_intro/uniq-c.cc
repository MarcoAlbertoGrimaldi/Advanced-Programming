#include <iostream>
#include <string>

int main() {

  int n{0};
  
  std::string line;
  std::string temp{};
  
  while(std::getline(std::cin, line)) {

    if (line!=temp) {
      if (n>0) {std::cout << n << " " << temp << "\n";}
      n=0;
    }
    
    n++;

    temp = line;

  }
  
}

    
