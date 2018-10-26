#include <iostream>
#include <array>
#include <vector> 

enum class month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

month& operator++ (month& m) {
    m = static_cast<month>( int(m)+1 );
    return m;
}

class Date {

    unsigned int _day;
    month _month;
    unsigned int _year;

    public:

     Date(const unsigned int d, const month m, const unsigned int y)
     : _day{d},
      _month{m},
      _year{y}{}

     ~Date() {};

     const unsigned int day() {
     return _day;
     }

     const month get_month() {
     return _month;
     }

     const unsigned int year() {
     return _year;
     }

     void add_day();

     void add_days(const unsigned int);
     
};


int main()
{
    Date d {4, month::mar, 2018};

    unsigned int n{};

    std::cin >> n;

    d.add_days(n);

    std::cout << d.day() << " " << int(d.get_month()) << " " << d.year() << std::endl;

    return 0;
}

void Date::add_days(const unsigned int n) {

    for(unsigned int i=0; i<n; i++) {
        Date::add_day();
    }
}

void Date::add_day() {

    switch(int(_month)) {
    case 1: case 3: case 5: case 7: case 8: case 10: 
      if (_day!=31) {_day++;}
      else {++_month; _day = 1;}
      break;
    case 4: case 6: case 9: case 11:
      if (_day!=30) {_day++;}
      else {++_month; _day = 1;}
      break;
    case 2:
      if (_day!=28) {_day++;}
      else {++_month; _day = 1;}
      break;
    case 12:
      if (_day!=31) {_day++;}
      else {
        _month = month::jan;
        _year++;
        _day = 1;
      }

}
}