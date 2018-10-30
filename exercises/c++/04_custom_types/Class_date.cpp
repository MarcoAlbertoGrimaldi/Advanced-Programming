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

class Date {

    unsigned int _day;
    month _month;
    unsigned int _year;

    friend std::ostream& operator<<(std::ostream& os, const Date& d) {
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    os << d._day << "-" << months[int(d._month)-1] << "-" << d._year << std::endl;
    return os;
    };

    friend bool operator== (const Date& lhs,const Date& rhs) {

    if (lhs._day==rhs._day && lhs._month==rhs._month && lhs._year==rhs._year) {
        return true;}
    else return false;
    };

    friend bool operator!= (const Date& lhs, const Date& rhs) {
    if (lhs==rhs) {return false;}
    else return true;
    };
  
    public:

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

     void set_day(const unsigned int d) {
         _day = d;
     }

     void set_month(month m) {
         _month= m;
     }

     void set_year(const unsigned int y) {
         _year= y;
     }

     void add_day();

     void add_days(const unsigned int);

     bool is_leap(const int y) {
         return(y%4==0 && y%400!=0);
     }
     
};


int main()
{
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << "Today date: ";
    std::cout <<  now->tm_mday << '-' << months[(now->tm_mon)] << '-' << (now->tm_year + 1900) << "\n";

    unsigned int d = (now->tm_mday), m = (now->tm_mon +1), y = (now->tm_year + 1900);
    Date date {d, month(m), y};

    unsigned int l_d, l_mt, l_y, r_d, r_mt, r_y;
   
    unsigned int n{}, action{0};

    while(action!=3) {
        std::cout << "Type: 0 to add days, 1 for compare dates, 2 for set the date, 3 for quit.\n";
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
        const Date l_date{l_d, month(l_mt), l_y};

        std::cout << "Insert the second date as dd mm yyyy: " << std::endl;
        std::cin >> r_d >> r_mt >> r_y;
        const Date r_date{r_d, month(r_mt), r_y};

        if (l_date==r_date) {std::cout << "The two given dates are the same.\n";}
        else {std::cout << "The two given dates are different.\n";}
        break;
        }
        case 2: {
            std::cout << "Insert the new date as dd mm yyyy: \n";
            std::cin >> l_d >> l_mt >> l_y;
            date.set_day(l_d);
            date.set_month(month(l_mt));
            date.set_year(l_y);
            std::cout << "New set date is: " << date << std::endl;
        }
        case 3:
        break;
      }
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
      if (is_leap(_year)) {
        if (_day!=29) {_day++;}
        else {++_month; _day = 1;}
      }
      else {
        if (_day!=28) {_day++;}
        else {++_month; _day = 1;}
      }
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