
//_______________________________DRILL 7_____________________________________________
/*
   1.  Start a program to work with points, discussed in §10.4.
    Begin by defining the data type Point that has two coordinate members x and y.
   2.  Using the code and discussion in §10.4,prompt the user to input seven (x,y)  pairs.
    As  the  data  is  entered,  store  it  in  a  vector  of  Points  called  original_points.
   3.  Print the data in original_points to see what it looks like.
   4.  Open  an  ofstream and output each point to a file named mydata.txt.
    On Windows, we suggest the .txt suffix to make it easier to look at the data with an ordinary text editor (such as WordPad).
   5.  Close  the  ofstream and then open an ifstream for mydata.txt.
    Read the data from mydata.txt and store it in a new vector called processed_points.
   6.  Print the data elements from both vectors.
   7.  Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.
 */

#include "std_lib_facilities.h"

using namespace std;

struct Point
{

        double x;
        double y;
        Point ()
        {

        }
        Point (double n1, double n2)                                 //q1
        {
                x = n1;
                y = n2;
        }

        void print (Point P)
        {
                cout << "(" << P.x << " , " << P.y << ")" << endl;
        }
};

vector <Point> original_points;
vector <Point> processed_points;


void fill_original_points ()
{

        double x, y;
        char comma;

        for (int i = 0; i < 7; i++)
        {
                cout << "Enter pairs in format x,y" << endl;
                if (cin >> x >> comma >> y)
                {
                        if (comma != ',')
                        {
                                cout << "Make sure to separate x and y with a comma!!!" << endl;
                        }
                        else
                        {
                                Point p (x, y);
                                original_points.push_back (p);          //q2
                        }
                }
                cout << "\n\n";
                for (Point i:original_points)
                {
                        i.print (i);                                    //q3
                }
        }

        ofstream new_file;                                               //q4

        new_file.open ("mydata.txt");
        if (!new_file)
        {
                cout << "\n\nFile doesn't exist" << endl;
        }
        else
        {
                cout << "\n\nNew file opened" << endl;


                for (Point i:original_points)
                {
                        new_file << "(" << i.x << " , " << i.y << ")" << endl;
                }
        }

        new_file.close ();


        ifstream new_file1;                                           //q5
        new_file1.open("mydata.txt");
        if (!new_file1)
        {
                cout<<"\n\nCannot open file"<<endl;
        }
        else
        {
                double x1, y1;
                string s, s1, s2;
                while (getline(new_file1, s))
                {
                        int comma1 = s.find(',');
                        int first = s.find('(');
                        int last = s.find(')');

                        s1 = s.substr(first+1, comma1-1);
                        s2 = s.substr(comma1+1, last-1);
                        x1 = stod(s1);
                        y1 = stod(s2);
                        Point p (x1,y1);

                        processed_points.push_back(p);
                }

        }

        cout << "\noriginal points : " << endl;
        for (Point i:original_points)
        {
                i.print (i);
        }                                                        //q6
        cout <<"\nprocessed points : " << endl;
        for (Point i:processed_points)
        {
                i.print (i);
        }

}

bool comparison(vector<Point> r, vector<Point> s)
{
        bool a = false;
        for(int i = 0; i < 7; i++)
        {
                if(r[i].x == s[i].x && r[i].y == s[i].y)           //q7
                {
                        a = true;
                }
        }
        return a;
}


int main ()
{

        fill_original_points ();

        if(comparison(original_points, processed_points) == true)
        {
                cout << "\nBoth vectors are the same. Comparison successful" << endl;
        }
        else
        {
                cout << "\nSomething's wrong!" << endl;
        }



        return 0;
}
