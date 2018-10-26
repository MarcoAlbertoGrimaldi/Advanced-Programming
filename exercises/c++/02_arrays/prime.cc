#include <iostream>
#inclide <cmath>

bool isprime(unsigned int n);

int main() {

  std::cout << "Type upper limit for prime check: \n";

  unsigned int l{0};
  std::cin >> l;

  bool is_prime_list[l];
  unsigned int counter{0};
  
  for(unsigned int i{1}; i<=l; i++) {
    
   is_prime_list[i-1] = isprime(i);

    if(is_prime_list[i-1]) {
      counter++;
    }
    
  }

  unsigned int prime_list[counter];

  unsigned int c{0};

  for(unsigned int i{1}; i<=l; i++) {

    if(is_prime_list[i-1]) {
      prime_list[c]=i;

      std::cout << prime_list[c] << std::endl;
      c++;
    }
  }
}


bool isprime(unsigned int n) {

  unsigned int i{2};

  while((n%i != 0) && i <= (std::sqrt(n)) {

    i++;

  }

  return (i==n);

}
