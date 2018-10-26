#include <iostream>

template <typename T>
T* read(const unsigned int l);

template <typename T>
void print_inv(unsigned int l, T* t_array);

int main () {

 unsigned int l{0};
  
 std::cout << "Please insert array lenght:\n";
 std::cin >> l;

 double* d_arr = read<double>(l);

 print_inv(l, d_arr);

 delete[] d_arr;
 
}



 template <typename T>
 T* read(const unsigned int l) {

   T* array{new T[l]};

   for (std::size_t i{0}; i < l; ++i) {
   
   std::cout << "Please insert array element n° " << i <<":\n";
   std::cin >> array[i];

   }

   return array;

   }



 template <typename T>
 void print_inv(unsigned int l, T* t_array) {

   for (unsigned int i{1}; i <= l; ++i)
	  std::cout << t_array[l-i] << std::endl;
   
   // while (l--)
   //   std::cout << t_array[l] << std::endl;
   
 }



 
