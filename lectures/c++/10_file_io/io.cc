#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

int main()
{
    int a=0;
    double d=9.9;
    {
        std::ofstream of{"a_file",}; //only write
        std::fstream f{"a_file",};   //write&read
    
        of << "Hello";
        f << "Hi";
        std::string word;
        f >> word;
            
    }
    std::string base_name "file_";
    for (auto i=1; i<10; ++i){
        std::stringstream ss;
        

    }


    return 0;
}