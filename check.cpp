#include <bits/stdc++.h>
using namespace std;
void chek()
{
    string myText;
    ifstream MyReadFile("text.txt");
    while (getline(MyReadFile, myText))
    {
        cout << myText;
    }
    MyReadFile.close();
}
void chek2()
{
    string myText;
    ofstream MyWriteFile("text.txt");
    MyWriteFile << "int main() {int x ; x = 10 ; cout << \"hello world\"; return 0;}";
    MyWriteFile.close();
}
void chek3()
{
}

int main()
{
    // chek();
    // chek2();
    chek3();

    return 0;
}
