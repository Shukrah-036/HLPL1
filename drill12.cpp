//_______________________________________DRILL12__________________________________
/*
   1.Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
   2.Define  a  vector<int> with those ten elements.
   3.Define  a  list<int> with those ten elements.
   4.Define a second array, vector, and list,
      each initialized as a copy of the first array, vector, and list, respectively.
   5.Increase the value of each element in the array by 2;
      increase the value of each element in the vector by 3;
      increase the value of each element in the list by 5.
   6.Write a simple copy() operation,template<typename Iter1, typename Iter2>
   7.Use   your   copy() to copy the array into the vector and to copy the list into the array.
   8.Use  the  standard  library  find()  to  see  if  the  vector  contains  the  value  3  and print out its position if it does;
      use find() to see if the list contains the value 27 and print out its position if it does.
 */

#include "std_lib_facilities.h"

using namespace std;

namespace S {
template<typename Iter1, typename Iter2>

Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)               //q6
{
        while(f1!=e1)
        {
                *f2 = *f1;
                ++f2;
                ++f1;
        }
        return f2;
}
}

int main()
{
        int a[10] = {0,1,2,3,4,5,6,7,8,9};         //q1

        vector<int> v = {0,1,2,3,4,5,6,7,8,9};      //q2

        list<int> l ({0,1,2,3,4,5,6,7,8,9});        //q3

        int a2[10];
        for(int i = 0; i < 10; i++)
        {
                a2[i] = a[i];                        //q4
        }

        vector<int> v2;
        for(int i = 0; i < 10; i++)
        {
                v2.push_back(v[i]);                  //q4
        }

        list<int> l2(l.begin(),l.end());             //q4

        cout << "a2 + 2 : " << endl;

        for(int i = 0; i < 10; i++)
        {
                a2[i] = a2[i] + 2;                    //q5
                cout << a2[i] << "\t";
        }
        cout << "\n\n";

        cout << "v2 + 3 : " << endl;

        for(int i = 0; i < 10; i++)
        {
                v2[i] = v2[i] + 3;                     //q5
                cout << v2[i] << "\t";
        }
        cout << "\n\n";

        cout << "l2 + 5 : " << endl;

        for(int x : l2)
        {
                x = x + 5;                               //q5
                cout << x << "\t";
        }
        cout << "\n\n";

        cout <<"Using copy operation : "<< "\n\n";

        S::copy(a2,a2+10,v2.begin());                       //q7

        cout << "copied(a2 into v2) : " << endl;

        for(vector<int>::iterator it = v2.begin() ; it != v2.end() ; ++it)
        {
                cout << *it << "\t";
        }
        cout << "\n\n";

        S::copy(l2.begin(),l2.end(),a2);                     //q7

        cout << "copied (l2 into a2) : " << endl;

        for(int i = 0; i < 10; i++)
        {
                cout << a2[i] << "\t";
        }
        cout << "\n\n";

        vector<int>::iterator it = find(v2.begin(), v2.end(), 3);

        if(it!=v2.end())
        {
                cout << "3 found in vector v2 at position : ";       //q8
                cout << it - v2.begin() << endl;
        }
        else
                cout << "3 not found" << endl;

        list<int>::iterator ot = find(l2.begin(), l2.end(), 27);

        if(ot!=l2.end())
        {
                cout << "27 found in list l2 at position : ";         //q8
                cout << distance(l2.begin(), ot) << endl;
        }
        else
                cout << "27 not found" << endl;

        return 0;
}
