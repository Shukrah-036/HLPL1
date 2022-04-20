//______________________________DRILL9 PART2_________________________
/*
   Standard libraryvector drill:
   1.  Define a global vector<int> gv;
   initialize it with ten ints, 1, 2, 4, 8, 16, etc.
   2.  Define a function f() taking a vector<int> argument.
   3.  In  f() :
        a.Define a local vector<int>lv with the same number of elements as the argument vector.
        b.Copy the values from gv into lv.
        c.Print out the elements of lv.
        d.Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
        e.Print out the elements of lv2.
   4.  In  main() :
        a.Call f() with gv as its argument.
        b.Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
        c.Call f() with vv as its argument.
 */

#include "std_lib_facilities.h"

using namespace std;

vector<int> gv = {1,2,4,8,16,32,64,128,256,512};        //q1

void f(vector<int> v)                                  //q2
{
        vector<int> lv;                                //q3a
        for(int i = 0; i < v.size(); i++)
        {
                lv.push_back(gv[i]);                   //q3b
        }

        for(int i = 0; i < v.size(); i++)
        {
                cout << lv[i] << "\t";                 //q3c
        }
        cout << "\n\n";

        vector<int> lv2(v.begin(), v.end());           //q3d
        for(int x : v)
        {
                cout << x << "\t";                    //q3e
        }
        cout << "\n\n";
}

int main()
{
        f(gv);                                       //q4a
        vector<int> vv = {1,2,6,24,120,720,5040,40320,362880,3628800};    //q4b
        f(vv);                                       //q4c

        return 0;
}
