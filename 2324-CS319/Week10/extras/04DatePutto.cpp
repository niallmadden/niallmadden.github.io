// CS319 Operator Overloading: Extras
// Date: a class representing a calandar date
// Example of overloading the <<  operator

#include <iostream>
#include <string>

int StandardDaysMonth[] =
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

class Date
{
  friend std::ostream &operator<<(std::ostream &, const Date &);
   
public:
  Date (int d=1, int m=1, int y=1901);
  void SetDate(int dd, int mm, int yy);
  int GetDay(void) {return day;};
  int GetMonth(void) {return month;};
  int GetYear(void) {return year;};
  bool IsLeapYear(void);
   
  Date &operator++(void); // prefix version
  Date operator++(int Dummy); // postfix version
   
private:
  int day, month, year;
  int *DaysMonth;
  void Increment(void);
};

///// Constructor 
Date::Date(int d, int m, int y)
{
  DaysMonth = new int [13];
  for (int i=0; i<=12; i++)
    DaysMonth[i] = StandardDaysMonth[i];
  SetDate(d,m,y);
} 

bool Date::IsLeapYear(void)
{
  if ( (year%400 == 0) ||
       ( (year%4 == 0) && (year%100 != 0)))
    return true;
  else
    return false;
}

void Date::SetDate(int d, int m, int y)
{
  year=y;
  if (IsLeapYear())
    DaysMonth[2]=29;
   
  month = ( (m>=1) && (m<=12) ) ? m : 1;
   
  day = ( (d>=1) && (d<=DaysMonth[month]) ) ? d : 1;
}

// Will call this in both prefix and postfix versions.
void Date::Increment(void)
{
  if (day != DaysMonth[month])
    day++;
  else if ( month != 12 )
  {
    month++; day=1;
  }
  else
    SetDate(1,1,year+1); // Need to set the leap year
}

Date &Date::operator++(void) // Prefix version
{
  Increment();
  return(*this);
}

Date Date::operator++(int Dummy) // Postfix version
{
  Date temp=*this;
  Increment();
  return(temp);
}

std::ostream &operator<<(std::ostream &output, const Date &d)
{
  std::string MonthName[13]={"", "Jan", "Feb", "Mar", "Apr",
			"May", "Jun", "Jul", "Aug", "Sep",
			"Oct", "Nov", "Dec"};
  output << d.day << "/" << MonthName[d.month] << "/" << d.year;
   
  return(output);
}

int main(void)
{
  Date today(13,03,2024);
  Date tomorrow;

  std::cout << "Today is " << today.GetDay() << "/" << 
    today.GetMonth() << "/" << today.GetYear() << std::endl;

  std::cout << "Today is " << today << std::endl;
  tomorrow=(++today);
  std::cout << "Tomorrow is " << tomorrow << std::endl;
  
  std::cout << std::endl;

  return(0);
}
