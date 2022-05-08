//_____________________________DRILL 3_________________________________________
/*
   This drill involves a series of modifications of a buggy program
   to turn it from something useless into something reasonably useful.
   1.Take the calculator from the file calculator02buggy.cpp.
   Get it to compile. You need to find and fix a few bugs.
   Those bugs are not in the text in the book.
   Find the three logic errors deviously inserted in calculator02buggy.cpp
   remove them so that the calculator produces correct results.
   2.Change the character used as the exit command from q to x.
   3.Change the character used as the print command from ; to =.
   4.Add a greeting line in main():
   "Welcome to our simple calculator. Please enter expressions using floating-point numbers."
   5.Improve that greeting by mentioning which operators are available and how to print and exit
 */

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {     //first error (lass)
public:
char kind;            // what kind of token
double value;         // for numbers: a value
Token(char ch)        // make a Token from a char
        : kind(ch), value(0) {
}
Token(char ch, double val)         // make a Token from a char and a double
        : kind(ch), value(val) {
}
};

//------------------------------------------------------------------------------

class Token_stream {
public:
Token_stream();       // make a Token_stream that reads from cin
Token get();          // get a Token (get() is defined elsewhere)
void putback(Token t);        // put a Token back
private:
bool full;            // is there a Token in the buffer?
Token buffer;         // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
        : full(false), buffer(0) // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
        if (full) error("putback() into a full buffer");
        buffer = t;   // copy t to buffer
        full = true;  // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()   //second error
                            //(defining of member function "get()" outside the class)
                            // datatype class :: function -> Token Token_stream::get()
{
        if (full) {   // do we already have a Token ready?
                // remove token from buffer
                full = false;
                return buffer;
        }

        char ch;
        cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

        switch (ch)
        {
        case '=': // for "print" from ; to =
        case 'x': // for "quit" from q to x
        case '(': case ')': case '+': case '-': case '*': case '/': case '%': //add %
                return Token(ch); // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': //add 8
        {
                cin.putback(ch); // put digit back into the input stream
                double val;
                cin >> val;      // read a floating-point number
                return Token('8', val); // let '8' represent "a number"
        }
        default:
                error("Bad token");
        }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
        Token t = ts.get();
        switch (t.kind) {
        case '(': // handle '(' expression ')'
        {
                double d = expression();
                t = ts.get();
                if (t.kind != ')') error("')' expected"); // quotation " added
                return d;
        }
        case '8':        // we use '8' to represent a number
                return t.value; // return the number's value
        default:
                error("primary expected");
        }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
        double left = primary();
        Token t = ts.get();    // get the next token from token stream

        while (true) {
                switch (t.kind) {
                case '*':
                { // {} added
                        left *= primary();
                        t = ts.get();
                        break; //break added
                }
                case '/':
                {
                        double d = primary();
                        if (d == 0) error("divide by zero");
                        left /= d;
                        t = ts.get();
                        break;
                }

                case '%':
                {
                        double d = primary();
                        if (d == 0) error("Division by 0!");
                        left %= d;
                        t = ts.get();
                        break;
                }
                default:
                        ts.putback(t); // put t back into the token stream
                        return left;
                }
        }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
        double left = term(); //added  )  // read and evaluate a Term
        Token t = ts.get();    // get the next token from token stream

        while (true) {
                switch (t.kind) {
                case '+':
                        left += term(); // evaluate Term and add
                        t = ts.get();
                        break;
                case '-':
                        left -= term(); //change + to -  // evaluate Term and subtract
                        t = ts.get();
                        break;
                default:
                        ts.putback(t); // put t back into the token stream
                        return left; // finally: no more + or -: return the answer
                }
        }
}

//------------------------------------------------------------------------------

int main()
{
        cout << "Welcome to our simple calculator. Please enter expressions using floating-point numbers." << endl;
        cout << "enter + (sum) or - (minus) or * (multiplication) or / (division) or % (modulo)" << endl;
        cout << "add an 'x' at the end to signify the end of your input, use '=' to print the result" << endl;

        double val = 0.0; //define val
        try
        {
                while (cin) {
                        Token t = ts.get();

                        if (t.kind == 'x') break; // 'q' for quit changed to 'x'
                        if (t.kind == '=') // ';' for "print changed to '='"
                                cout << "=" << val << '\n';
                        else
                                ts.putback(t);
                        val = expression();
                }
                keep_window_open();
        }
        catch (exception& e) {
                cerr << "error: " << e.what() << '\n';
                keep_window_open();
                return 1;
        }
        catch (...) {
                cerr << "Oops: unknown exception!\n";
                keep_window_open();
                return 2;
        }
}
//------------------------------------------------------------------------------
