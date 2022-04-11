/*Write  three  functions  swap_v(int,int), swap_r(int&,int&),  and  swap_cr(const int&, const int&).
   Each should have the body{ int temp; temp = a, a=b; b=temp; }where a and b are the names of the arguments.
   Try calling each swap like this
   int x = 7;int y =9;swap_?(x,y);swap_?(7,9);
   const int cx = 7;const int cy = 9;swap_?(cx,cy);swap_?(7.7,9.9);
   double dx = 7.7;double dy = 9.9;swap_?(dx,dy);swap_?(7.7,9.9);
   Which functions and calls compiled, and why?
   After each swap that compiled, print the value of the arguments after the call to see if they were actually swapped.*/
#include "std_lib_facilities.h"

using namespace std;

void swap_v(int a, int b)
{
        int temp;
        temp = a;
        a = b;
        b = temp;
}

void swap_r(int& a, int& b)
{
        int temp;
        temp = a;
        a = b;
        b = temp;
}


/*void swap_cr(const int& a, const int& b)
   {
        int temp;  //This function does not compile as we are trying to assign values to read-only references.
        temp = a;  //trying to swap this returns an error in every circumstance
        a = b;     //because the 'const' cannot be changed
        b = temp;
   } */

int main()
{
        int x = 7;
        int y = 9;

        /* swap_v(x, y);    This compiles but does not swap any values, because swap_v
                            only manages copies. It would swap auccesfully if pointers were used.*/

        /* swap_v(7, 9);    This compiles but nothing changes, the swap doesn't happen
                            because '7' and '9' are local to swap_v and get destroyed when the function
                            ends, and theres no reference to it in the main function (passed by value)*/

        swap_r(x, y);       /* This compiles and swaps the values as expected (passed by reference) */

        /* swap_r(7,9);     This does not compile as binding an "lvalue- something that points to a specific
                            memory location(int&)" to a temporary value that doesnt point to anything (int)
                            is not permitted */


        cout << "After the swap, x is " << x << " and y is " << y << endl; // output message.

        const int cx = 7;
        const int cy = 9;

        /* swap_v(cx, cy);    This compiles are we are passing copied values of variables, but doesnt swap.
                              It doesnt swap because it is just temporary copies, there are no references
                              to the original values after the function swap_v has ended */

        /* swap_v(7.7, 9.9);  This compiles but doesnt not swap. Its arguments get truncated. The swap doesn't
                              happen because '7.7' and '9.9' are local to swap_v and get destroyed when the
                              function ends, and theres no reference to it in the main function (passed by value)*/


        /* swap_r(cx, cy);    This doesnt compile as binding a reference type of "int&" to a const int
                              variable is not possible*/

        /* swap_r(7.7, 9.9);  This doesnt compile. Its arguments get truncated. Binding an "lvalue(int&)"
                              to a temporary value that doesnt point to anything (int) is not permitted*/


        cout << "After the swap, cx is " << cx << " and cy is " << cy << endl; //output message.

        double dx = 7.7;
        double dy = 9.9;

        /* swap_v(dx, dy);    This compiles but doesnt swap. It doesnt swap because it is just temporary copies,
                              there are no references to the original values after the function swap_v has ended */

        /* swap_v(7.7,9.9);   This compiles but doesn't swap, because '7.7' and '9.9' are local to swap_v and get
                              destroyed when the function ends, and theres no reference to it in the main function
                              (passed by value) */

        /* swap_r(dx, dy);    This doesnt compile. The function receives an rvalue(int) which cant be bound to int&
                              so no references can be made */

        /* swap_r(7.7,9.9);   This doesnt compile. Binding an "lvalue(int&)" to a temporary value that doesnt point
                              to anything (int) is not permitted*/


        cout << "After the swap, dx is " << dx << " and dy is " << dy << endl; // output message.

        return 0;
}
