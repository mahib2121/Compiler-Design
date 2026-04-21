#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

unordered_set<string> keywords = {
    "int", "float", "double", "char", "return",
    "if", "else", "while", "for", "void", "include",
    "using", "namespace", "std", "main"};

bool isNumber(const string &s)
{
    for (char c : s)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isIdentifier(const string &s)
{
    if (!isalpha(s[0]) && s[0] != '_')
        return false;
    for (char c : s)
    {
        if (!isalnum(c) && c != '_')
            return false;
    }
    return true;
}

int main()
{
    ifstream file("input.txt");

    if (!file.is_open())
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    char ch;

    cout << "Tokens with Classification:\n\n";

    while (file.get(ch))
    {
        if (isspace(ch))
            continue;

        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' ||
            ch == ';' || ch == ',')
        {
            cout << ch << " : Delimiter\n";
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
        {
            cout << ch << " : Operator\n";
        }

        else if (ch == '<')
        {
            if (file.peek() == '<')
            {
                file.get(ch);
                cout << "<< : Operator\n";
            }
        }

        else if (ch == '"')
        {
            string str = "";
            while (file.get(ch) && ch != '"')
            {
                str += ch;
            }
            cout << "\"" << str << "\" : String Literal\n";
        }
        else
        {
            string token = "";
            token += ch;

            while (file.peek() != EOF &&
                   !isspace(file.peek()) &&
                   !ispunct(file.peek()))
            {
                token += file.get();
            }

            if (keywords.count(token))
            {
                cout << token << " : Keyword\n";
            }
            else if (isNumber(token))
            {
                cout << token << " : Number\n";
            }
            else if (isIdentifier(token))
            {
                cout << token << " : Identifier\n";
            }
            else
            {
                cout << token << " : Unknown\n";
            }
        }
    }

    file.close();
    return 0;
}
