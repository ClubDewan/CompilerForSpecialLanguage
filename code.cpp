#include <iostream>
#include <fstream>
using namespace std;
int i = 0;
string dfa = "0";
string print;
void state0(char c)
{
    print = "\0";
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_')
    {
        print = print + c;
        dfa = "id1";
    }
    else if ((c == '/'))
    {
        print = print + c;
        dfa = "cm1";
    }
    else if ((c >= '0' && c <= '9'))
    {
        print = print + c;
        dfa = "cn1";
    }
    else if ((c == '.'))
    {
        print = print + c;
        dfa = "cn2";
    }
    else if ((c == '"'))
    {
        print = print + c;
        dfa = "st1";
    }
    else if ((c == '\''))
    {
        print = print + c;
        dfa = "st3";
    }
    else if ((c == '?'))
    {
        print = print + c;
        dfa = "op1";
    }
    else if ((c == '~') || (c == '^'))
    {
        print = print + c;
        dfa = "oOperation3";
    }
    else if ((c == '-'))
    {
        print = print + c;
        dfa = "op3";
    }
    else if ((c == '+'))
    {
        print = print + c;
        dfa = "op5";
    }
    else if ((c == '%') || (c == '*') || (c == '/') || (c == '=') || (c == '!'))
    {
        print = print + c;
        dfa = "op7";
    }
    else if ((c == '<'))
    {
        print = print + c;
        dfa = "op9";
    }
    else if ((c == '>'))
    {
        print = print + c;
        dfa = "op11";
    }
    else if ((c == '|'))
    {
        print = print + c;
        dfa = "op13";
    }
    else if ((c == '&'))
    {
        print = print + c;
        dfa = "op15";
    }
    else if (c == '\n' || c == ' ' || c == '\r' || c == '\t')
    {
        print = print + c;
        print = "\0";
        dfa = "0";
    }
    else
    {
        print = print + c;
        cout << "SP Ch--> ";
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateid1(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_')
    {
        print = print + c;
        dfa = "id1";
    }
    else
    {
        if (print == "cout" || print == "cin" || print == "if" || print == "else" || print == "int" || print == "float")
        {
            cout << "KeyWord--> ";
            i--;
            cout << print << endl;
            print = "\0";
            dfa = "0";
        }
        else
        {
            cout << "Identifier--> ";
            i--;
            cout << print << endl;
            print = "\0";
            dfa = "0";
        }
    }
}
void statecm1(char c)
{
    if (c == '/')
    {
        print = "\0";
        dfa = "cm2";
    }
    else if (c == '*')
    {
        print = "\0";
        dfa = "cm3";
    }
    else
    {
        i--;
        print = "\0";
        dfa = "0";
    }
}
void statecm2(char c)
{
    if (c == '\n')
    {
        i--;
        print = "\0";
        dfa = "0";
    }
    else
    {
        print = "\0";
        dfa = "cm2";
    }
}
void statecm3(char c)
{
    if (c == '*')
    {
        print = "\0";
        dfa = "cm4";
    }
    else
    {
        print = "\0";
        dfa = "cm3";
    }
}
void statecm4(char c)
{
    if (c == '/')
    {
        i--;
        print = "\0";
        dfa = "0";
    }
    else
    {
        print = "\0";
        dfa = "cm3";
    }
}
void statecn1(char c)
{
    if ((c >= '0') && (c <= '9'))
    {
        print = print + c;
        dfa = "cn1";
    }
    else if (c == '.')
    {
        print = print + c;
        dfa = "cn2";
    }
    else
    {
        cout << "Constant--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void statecn2(char c)
{
    if ((c >= '0') && (c <= '9'))
    {
        print = print + c;
        dfa = "cn2";
    }
    else
    {
        cout << "Constant--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void statest1(char c)
{
    if (c == '"')
    {
        print = print + c;
        dfa = "st2";
    }
    else if (c == 0x0d)
    {
        print = print + c;
        dfa = "st1";
    }
    else
    {
        print = print + c;
        dfa = "st1";
    }
}
void statest2(char c)
{
    cout << "String--> ";

    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void statest3(char c)
{
    print = print + c;
    dfa = "st4";
}
void statest4(char c)
{
    if (c == '\'')
    {
        print = print + c;
        dfa = "st5";
    }
}
void statest5(char c)
{
    cout << "String--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop1(char c)
{
    if (c == ':')
    {
        print = print + c;
        dfa = "op2";
    }
}
void stateop2(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateoOperation3(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop3(char c)
{
    if (c == '-')
    {
        print = print + c;
        dfa = "op4";
    }
    else if (c == '=')
    {
        print = print + c;
        dfa = "op8";
    }
    else
    {
        cout << "Operator--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateop4(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop5(char c)
{
    if (c == '+')
    {
        print = print + c;
        dfa = "op6";
    }
    else if (c == '=')
    {
        print = print + c;
        dfa = "op8";
    }
    else
    {
        cout << "Operator--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateop6(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop7(char c)
{
    if (c == '=')
    {
        print = print + c;
        dfa = "op8";
    }
    else
    {
        cout << "Operator--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateop8(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop9(char c)
{
    if (c == '=')
    {
        print = print + c;
        dfa = "op8";
    }
    else if (c == '<')
    {
        print = print + c;
        dfa = "op10";
    }
    else
    {
        cout << "Operator--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateop10(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop11(char c)
{
    if (c == '=')
    {
        print = print + c;
        dfa = "op8";
    }
    else if (c == '>')
    {
        print = print + c;
        dfa = "op12";
    }
    else
    {
        cout << "Operator--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateop12(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop13(char c)
{
    if (c == '|')
    {
        print = print + c;
        dfa = "op14";
    }
    else
    {
        cout << "Operator--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateop14(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void stateop15(char c)
{
    if (c == '&')
    {
        print = print + c;
        dfa = "op16";
    }
    else
    {
        cout << "Operator--> ";
        i--;
        cout << print << endl;
        print = "\0";
        dfa = "0";
    }
}
void stateop16(char c)
{
    cout << "Operator--> ";
    i--;
    cout << print << endl;
    print = "\0";
    dfa = "0";
}
void statesc1(char c)
{
    dfa = "0";
}

void isAccepted(string str)
{
    dfa = "0";
    int length = str.length();
    for (i = 0; i < length; i++)
    {

        if (dfa == "0")
        {
            state0(str[i]);
        }
        else if (dfa == "id1")
        {
            stateid1(str[i]);
        }
        else if (dfa == "cm1")
        {
            statecm1(str[i]);
        }
        else if (dfa == "cm2")
        {
            statecm2(str[i]);
        }
        else if (dfa == "cm3")
        {
            statecm3(str[i]);
        }
        else if (dfa == "cm4")
        {
            statecm4(str[i]);
        }
        else if (dfa == "cn1")
        {
            statecn1(str[i]);
        }
        else if (dfa == "cn2")
        {
            statecn2(str[i]);
        }
        else if (dfa == "st1")
        {
            statest1(str[i]);
        }
        else if (dfa == "st2")
        {
            statest2(str[i]);
        }
        else if (dfa == "st3")
        {
            statest3(str[i]);
        }
        else if (dfa == "st4")
        {
            statest4(str[i]);
        }
        else if (dfa == "st5")
        {
            statest5(str[i]);
        }
        else if (dfa == "op1")
        {
            stateop1(str[i]);
        }
        else if (dfa == "op2")
        {
            stateop2(str[i]);
        }
        else if (dfa == "oOperation3")
        {
            stateoOperation3(str[i]);
        }
        else if (dfa == "op3")
        {
            stateop3(str[i]);
        }
        else if (dfa == "op4")
        {
            stateop4(str[i]);
        }
        else if (dfa == "op5")
        {
            stateop5(str[i]);
        }
        else if (dfa == "op6")
        {
            stateop6(str[i]);
        }
        else if (dfa == "op7")
        {
            stateop7(str[i]);
        }
        else if (dfa == "op8")
        {
            stateop8(str[i]);
        }
        else if (dfa == "op9")
        {
            stateop9(str[i]);
        }
        else if (dfa == "op10")
        {
            stateop10(str[i]);
        }
        else if (dfa == "op11")
        {
            stateop11(str[i]);
        }
        else if (dfa == "op12")
        {
            stateop12(str[i]);
        }
        else if (dfa == "op13")
        {
            stateop13(str[i]);
        }
        else if (dfa == "op14")
        {
            stateop14(str[i]);
        }
        else if (dfa == "op15")
        {
            stateop15(str[i]);
        }
        else if (dfa == "op16")
        {
            stateop16(str[i]);
        }
        else if (dfa == "sc1")
        {
            statesc1(str[i]);
        }
    }
}

int main()
{
    fstream file;
    file.open("code.txt", ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
            isAccepted(line);
        }
    }

    return 0;
}