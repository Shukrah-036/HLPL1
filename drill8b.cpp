//___________________________DRILL8 PART2_____________________________________
/*
   The second part focuses on pointers and their relation to arrays. Using print_array()from the last drill:
   1.  Allocate an int, initialize it to 7, and assign its address to a variable p1.
   2.  Print out the value of p1 and of the int it points to.
   3.  Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.;
    and assign its address to a variable p2.
   4.  Print out the value of p2 and of the array it points to.
   5.  Declare an int* called p3 and initialize it with p2.
   6.  Assign p1 to p2.
   7.  Assign p3 to p2.
   8.  Print out the values of p1 and p2 and of what they point to.
   9.  Deallocate all the memory you allocated from the free store.
   10.  Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.;
      and assign its address to a variable p1.
   11.  Allocate an array of ten ints, and assign its address to a variable p2.
   12.  Copy the values from the array pointed to by p1 into the array pointed to by p2.
   13.  Repeat 10–12 using a vector rather than an array.
 */

#include "std_lib_facilities.h"

using namespace std;

iint main()
{
        int *p1 = new int(7);                 //q1

        cout << "The value of p1 is : " << p1 << " and the value of the int it points to is : " << *p1 << endl;  //q2

        int *p2 = new int[7] {1,2,4,8,16,32,64};      //q3

        cout << "The value of p2 is : " << p2 << " and the values in the array it points to are : "<<endl;

        for(int i = 0; i < 7; i++)
        {
                cout << p2[i] << "\t";          //q4
        }
        cout << "\n\n";

        int* p3 = p2;                          //q5

        p2 = p1;                               //q6

        p2 = p3;                               //q7

        cout << "The value of p1 is : " << p1 << " and it points to : " << *p1 << endl;
        //q8
        cout << "The value of p2 is : " << p2 << " and it points to : " << *p2 << endl;

        delete p1;
        //q9
        delete[] p2;

        p1 = new int[10] {1,2,4,8,16,32,64,128,256,512};       //q10

        p2 = new int[10];                                      //q11

        for(int i = 0; i <10; i++)
        {
                p2[i] = p1[i];                                     //q12
        }

        vector<int> v1; v1.reserve(10);
        v1= {1,2,4,8,16,32,64,128,256,512};

        vector<int> v2;  v2.reserve(10);


        for(int i = 0; i < 10; i++)
        {
                v2.push_back(v1[i]);
        }
        return 0;
}
