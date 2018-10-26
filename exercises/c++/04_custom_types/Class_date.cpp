#include <iostream>
#include <array>
#include <ctime> 

enum class month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

month& operator++ (month& m) {
    m = static_cast<month>( int(m)+1 );
    return m;
}


// std::istream& operator>>(std::istream& is, month& m) {
    
// };

bool is_leap(const int y);

class Date {

    public:

    unsigned int _day;
    month _month;
    unsigned int _year;

     Date(const unsigned int date, const month m, const unsigned int y)
     : _day{date},
      _month{m},
      _year{y}{}

     Date();
     ~Date() {};

     const unsigned int get_day() {
     return _day;
     }

     const month get_month() {
     return _month;
     }

     const unsigned int get_year() {
     return _year;
     }

     void set_day(Date& date, const unsigned int d) {
         date._day = d;
     }

     void set_month(Date& date, month m) {
         date._month= m;
     }

     void set_year(Date& date, const unsigned int y) {
         date._year= y;
     }

     void add_day();

     void add_days(const unsigned int);
     
};

std::ostream& operator<<(std::ostream& os, const Date& d) {
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    os << d._day << "-" << months[int(d._month)-1] << "-" << d._year << std::endl;
    return os;
};

bool operator== (const Date& lhs,const Date& rhs) {

    if (lhs._day==rhs._day && lhs._month==rhs._month && lhs._year==rhs._year) {
        return true;}
    else return false;
};

bool operator!= (const Date& lhs, const Date& rhs) {
    if (lhs==rhs) {return false;}
    else return true;
};


int main()
{
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << "Today date: ";
    std::cout <<  now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << "\n";

    unsigned int d = (now->tm_mday), m = (now->tm_mon +1), y = (now->tm_year + 1900);
    Date date {d, month(m), y};

    unsigned int l_d, l_mt, l_y, r_d, r_mt, r_y;
    month l_m, r_m;
   
    unsigned int n{}, action{};

    std::cout << "Press: 0 to add days, 1 for compare dates, 2 for quit.\n";
    std::cin >> action;

    switch(action) {
        case 0:
        std::cout << "Insert how many days you want to add: " << std::endl;
        std::cin >> n;
        date.add_days(n);
        std::cout << "New changed date is: " << date << std::endl;
        break;

        case 1: {   
        std::cout << "Insert the first date as dd mm yyyy: " << std::endl;
        std::cin >> l_d >> l_mt >> l_y;
        l_m = month(l_mt);
        const Date l_date{l_d, l_m, l_y};

        std::cout << "Insert the second date as dd mm yyyy: " << std::endl;
        std::cin >> r_d >> r_mt >> r_y;
        r_m = month(r_mt);
        const Date r_date{r_d, r_m, r_y};

        if (l_date==r_date) {std::cout << "The two given dates are the same.\n";}
        else {std::cout << "The two given dates are different.\n";}
        break;
        }
        case 2:
        break;
    }

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