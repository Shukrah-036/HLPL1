//_____________________________DRILL 6 (9.4.3)_____________________________
/*
   This drill simply involves getting the sequence of versions of Date to work.
   For each version define a Date called today initialized to June 25, 1978.
   Then, define a Date called tomorrow and give it a value by copying today into it
   and increasing its  day  by  one  using  add_day().
   Finally,  output  today  and tomorrow using  a  <<  defined as in §9.8.
   Your check for a valid date may be very simple.
   Feel free to ignore leap years.
   However, don’t accept a month that is not in the [1,12] range or day of the month that is not in the [1,31] range.
   Test each version with at least one invalid date (e.g., 2004, 13, –5).
   3.  The version from §9.4.3
 */
#include "std_lib_facilities.h"

using namespace std;

class Date
{
int y, m, d;

public:
Date(int y, int m, int d);

void add_day(int x);
int month() {
        return m;
}
int day() {
        return d;
}
int year() {
        return y;
}
};

Date::Date(int yy, int mm, int dd)
{
        y = yy;
        m = mm;
        d = dd;

        if(m < 1 || m > 12 )
                error("Invalid month");
        if(d < 1 || d > 31)
                error("Invalid day");
}

void Date::add_day(int x)
{
        d+=x;
        if(d>31)
        {
                d=1;
                ++m;
        }
        if(m>12)
        {
                m=1;
                ++y;
        }
}

ostream& operator<<(ostream& os, Date& d)
{
        return os << d.year() << "-" << d.month() << "-" << d.day() << endl;
}

void f()
{
        try
        {
                Date today(1978, 6, 25);
                //Date invalid_date(2004, 13, -5);

                Date tomorrow = today;

                tomorrow.add_day(1);


                cout << "Today's date: " << today << endl;
                cout << "Tomorrow's date: " << tomorrow << endl;
        }
        catch(exception& e)
        {
                cerr << e.what() << endl;
        }
}

int main()
{
        f();

        return 0;
}
