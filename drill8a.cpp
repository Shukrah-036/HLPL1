//__________________________________DRILL8 PART1________________________
/*
   1.  Allocate an array of ten ints on the free store using new.
   2.  Print the values of the ten ints to cout.
   3.  Deallocate the array (using delete[ ]).
   4.   Write  a  function  print_array10(ostream&  os,  int*  a)
      that  prints  out  the  values of a (assumed to have ten elements) to os.
   5.  Allocate an array of ten ints on the free store;
      initialize it with the values 100, 101, 102, etc.; and print out its values.
   6.  Allocate an array of 11 ints on the free store;
      initialize it with the values 100, 101, 102, etc.; and print out its values.
   7.  Write a function print_array(ostream& os, int* a, int n)
      that prints out the values of a (assumed to have n elements) to os.
   8.  Allocate an array of 20 ints on the free store;
      initialize it with the values 100, 101, 102, etc.; and print out its values.
   9.  Did you remember to delete the arrays? (If not, do it.)
   10.   Do  5,  6,  and  8  using  a  vector  instead  of  an  array
      and  a  print_vector()instead of print_array().
 */

#include "std_lib_facilities.h"

using namespace std;

void print_array10(ostream& os, int* a)
{
        for(int i = 0; i < 10; i++)
        {
                os << a[i] << "\t";
        }
        cout << "\n\n";
}

void print_array(ostream& os, int* a, int n)
{
        for(int i = 0; i < n; i++)
        {
                os << a[i] << "\t";
        }
        cout << "\n\n";
}

void print_vector(ostream& os, vector<int>& v)
{
        for(int x : v)
        {
                os << x << "\t";
        }
        cout << "\n\n";
}

int main()
{

        int *p = new int[10] {0,1,2,3,4,5,6,7,8,9};

        for(int i = 0; i < 10; i++)
        {
                cout << p[i] << "\t";
        }
        cout << "\n\n";

        delete[] p;

        int *q = new int[10] {100,101,102,103,104,105,106,107,108,109};

        print_array10(cout,q);

        delete[] q;

        int *r = new int[11] {100,101,102,103,104,105,106,107,108,109,110};

        for(int i = 0; i < 11; i++)
        {
                cout << r[i] << "\t";
        }
        cout << "\n\n";

        delete[] r;

        int *s = new int[20] {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};

        print_array(cout,s,20);

        delete[] s;

        cout << "vectors\n\n";

        vector<int> t; t.reserve(10);
        t={100,101,102,103,104,105,106,107,108,109};

        print_vector(cout,t);

        vector<int> u; u.reserve(11);
        u={100,101,102,103,104,105,106,107,108,109,110};

        print_vector(cout,u);

        vector<int> v; v.reserve(20);
        v={100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};

        print_vector(cout,v);

        return 0;

}
