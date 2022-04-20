//______________________________DRILL 10___________________________________

/* 1.  Define  template<typename T> struct S { T val; };.
2.Add a constructor, so that you can initialize with a T.
3.Define  variables  of  types  S<int>,  S<char>,  S<double>, S<string>,  and  S<vector<int>>;
      initialize them with values of your choice.
4.Read those values and print them.
5.Add a function template get() that returns a reference to val.
6.Put the definition of get() outside the class.
7.Make val private.
8.Do 4 again using get().
9.Add  a  set() function template so that you can change val.
10.Replace set()  with  an  S<T>::operator=(const  T&).
      Hint:  Much  simpler  than §19.2.5.
11.Provide const and non-const versions of get().
12.Define a function template<typename T> read_val(T& v) that reads from cin into v.
13.Use  read_val()  to  read  into  each  of  the  variables  from  3  except  the  S<vector<int>> variable.
*/

#include "std_lib_facilities.h"

using namespace std;

template <typename T>

struct S
{
        private:                //q7
        T val;

        public:
        S()
        {
        }
        S(T n)
        {
            val = n;              //q2
        }

        T get() const;           //q11
        /*{
            return val;
        }*/

        T get();
        /*{
            return val;        //q5
        }*/
        void operator=(const T&); // q10
        //void set(T n1);
        /*{
            val = n1;     //q9
        }*/

};

template <typename T>
T S<T>::get()
{
    return val;                  //q6
}

template <typename T>
T S<T>::get() const
{
    return val;                  //q11
}

/*template <typename T>
void S<T>::set(T n1)      //replaced by q10
{
    val = n1;
}*/

template <typename T>
void S<T>::operator=(const T& n1)    //q10
{
    val = n1;
}

template<typename T>
void read_val(T& v)
{
    cout << "Enter a/an (int,char,double,string):" << endl;
    cin >> v;                     //q12
    cout << "\n";
}
int main()
{

    S<int> s_1(5);
    S<char> s_2('h');
    S<double> s_3(5.87);                   //q3
    S<string> s_4("hello");
    S<vector<int>> s_5({0,1,2,3,4});

    //q4 -: read and print the values
    /*cout << "S<int> = " << s_1.val << endl;
      cout << "S<char> = " << s_2.val << endl;
      cout << "S<double> = " << s_3.val << endl;
      cout << "S<string> = " << s_4.val << endl;
      cout << "S<vector<int>> = ";
      for(int i : s_5.val)
      {
        cout << i << "\t";
      }
      cout << "\n\n"; */

    cout << "S<int> = " << s_1.get() << endl;
    cout << "S<char> = " << s_2.get() << endl;
    cout << "S<double> = " << s_3.get() << endl;     //q8
    cout << "S<string> = " << s_4.get() << endl;
    cout << "S<vector<int>> = ";
    for(int i : s_5.get())
    {
        cout << i << "\t";
    }
    cout << "\n\n";

    int i;
    read_val(i);
    S<int> s_1a(i);               //q13

    char c;
    read_val(c);                 //q13
    S<char> s_2a(c);

    double d;
    read_val(d);                 //q13
    S<double> s_3a(d);

    string s;
    read_val(s);                 //q13
    S<string> s_4a(s);

    cout << "S<int> after read_val is : " << s_1a.get() << endl;
    cout << "S<char> after read_val  is : " << s_2a.get() << endl;
    cout << "S<double> after read_val is : " << s_3a.get() << endl;     //q13
    cout << "S<string> after read_val is : " << s_4a.get() << endl;
    cout << "\n\n";
return 0;
}
