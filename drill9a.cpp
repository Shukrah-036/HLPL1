//_____________________________DRILL9 PART 1___________________________________
/*
Array drill:
1.  Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
2.  Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.
3.  In  f() :
        a.Define a local int array la of ten ints.
        b.Copy the values from ga into la.
        c.Print out the elements of la.
        d.Define a pointer p to int and
        initialize it with an array allocated on the free store with the same number of elements as the argument array.
        e.Copy the values from the argument array into the free-store array.
        f.Print out the elements of the free-store array.
        g.Deallocate the free-store array.
        4.  In  main() :
                a.Call f() with ga as its argument.
                b.Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
                c.Call f() with aa as its argument. */

#include "std_lib_facilities.h"

using namespace std;

int ga[10]={1,2,4,8,16,32,64,128,256,512};         //q1

void f(int a[], int n)                             //q2
{
        int la[10];                                //q3a
        for(int i = 0; i < 10; i++)
        {
                la[i]=ga[i];                       //q3b
        }

        for(int i = 0; i < 10; i++)
        {
                cout << la[i] << "\t";             //q3c

        }
        cout << endl;

        int *p = new int[n];                      //q3d
        for(int i = 0; i < 10; i++)
        {
                p[i]=a[i];                        //q3e
        }

        for(int i = 0; i < 10; i++)
        {
                cout << p[i] << "\t";            //q3f

        }
        cout << endl;

        delete[] p;                              //q3g
}

int main()
{
        f(ga,10);                               //q4a

        int aa[10]= {1,2,6,24,120,720,5040,40320,362880,3628800};   //q4b

        f(aa,10);                              //q4c

return 0;
}
