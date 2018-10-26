#include <iostream>
#include <cmath>

int main() {

  unsigned int l{0};
  std::cout << "Insert max n: \n";
  std::cin >> l;

  bool list[l] = {0};

  for(unsigned int i{2}; i<=(std::sqrt(l)); i++) {

    if(list[i-1]) {continue;}
    
    unsigned int n{2};
    
    while((i*n)<=l) {

      list[i*n]=1;
      n++;
      
    }

  }

  std::cout << "All prime numbers minor or equal to " << l << " are: \n";

  for(unsigned int i{2}; i<=l; i++) {
    
    if(!list[i]) {
      std::cout << i << std::endl;
    }

  }

}

    
    

  
