#include <iostream>
#include <array>

using namespace std;

template < std::size_t N>
void transpose (array<double, N>& mat_t, unsigned int n_row, unsigned int n_col) ;

int main() {

  constexpr unsigned int n_row{12};
  constexpr unsigned int n_col{16};
  
  array<double,(n_row*n_col)> mat{};

  for(unsigned int r{0}; r<n_row; ++r) {
    
    for(unsigned int c{0}; c<n_col; ++c) {

	mat[n_col*r+c] = n_col*r+c;
	cout << mat[n_col*r+c] << " ";

     }

    cout << "\n";
     
   }

  transpose(mat, n_row, n_col);      

}

 template < std::size_t N>
 void transpose(array<double, N>& mat_t, unsigned int n_row, unsigned int n_col) {

  for(unsigned int r{0}; r<n_row; ++r) {  
    for(unsigned int c{0}; c<n_col; ++c) {

      swap(mat_t[n_col*r+c], mat_t[n_col*r+c]);

    }
  }

  
      

  for(unsigned int c{0}; c<n_col; ++c) {

    for(unsigned int r{0}; r<n_row; ++r) {
    
	cout << mat_t[n_col*r+c] << " ";

     }

    cout << "\n";
    
  }
  
 }
  
  

        

    
     

