/*
    From Programming Pringiples using C++
    Calculator from chapter 7
    Alessandro Felici

    Basic calculator for expressions
        WITH VARIABLES

    Grammar for input:
    
    Statement:
        Expression
        Print
        Quit
    
    Print:
        const print (';')

    Quit:
        const quit ('q')

    Expression
        Term
        Expression + Term
        Expression - Term
    
    Term
        Primary
        Term * Primary
        Term / Primary
        Term % Primary

    Primary
        Number
        ( Expression )
        - Primary
        + Primary
    
    Number
        floating-point-literal

    Input comes from cin through the Token_stream call ts
*/

#include "../std_lib_facilities.h"

const char number = '8';
const char print = ';';
const char quit = 'q';
const string prompt = "> ";
const string result = "= ";

class Token{
public:
    char kind;
    double value;
};

class Token_stream{
public:
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    Token buffer;
    bool full {false};
};

void Token_stream::putback(Token t){
    if(full) throw runtime_error("putback() when buffer is full");
    buffer = t;
    full = true;
}

Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch(ch){
        case print:
        case quit:
        case '%':
        case '(': case ')':
        case '+': case '-':
        case '*': case '/':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{number, val};
        }
        default:
            throw runtime_error("Bad Token");
    }
}

void Token_stream::ignore(char c){ // c represents the kind of Token
    //first look in buffer
    if(full && c==buffer.kind){
        full = false;
        return;
    }
    full = false;
    // now search input

    char ch = 0;
    while (cin>>ch)
        if (ch == c) return;
    
}

Token_stream ts;

double expression();

double primary(){
    Token t = ts.get();
    switch(t.kind){
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') throw runtime_error("Expected ')'");
        return d;
    }
    case number:
        return t.value;
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        throw runtime_error("Expected primary");
    }
}

double term(){
    double left = primary();

    Token t = ts.get();

    while(true){
        switch(t.kind){
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if(d == 0) throw runtime_error("divide by 0");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0) throw runtime_error("% divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression(){
    double left = term();
    Token t = ts.get();

    while(true){
        switch(t.kind){
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

void clean_up_mess(){
    ts.ignore(print);
}


void calculate(){
try{
    cout << "type " << quit <<" to quit and " << print << " to print expression\n";

    while(cin){
        cout << prompt;
        Token t = ts.get();

        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;

        ts.putback(t);
        cout << result << expression() << "\n";
    }
}
catch(exception&e){
    cerr << "calculation error: " << e.what() << "\n";
    clean_up_mess();
}
}

int main() {
try
{   
    cout << "Welcome to the calculator de cristo!\n";

    calculate();

    keep_window_open("ADDIOS");
    return 0;
}
catch(exception&e)
{
    cerr << "error: " << e.what() << "\n";
    keep_window_open("SIUM");
    return 1;
}
catch(...)
{
    cerr << "error unknown\n";
    keep_window_open("sturniolo");
    return 2;
}
}
