#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    cout << "Program started\n";

    ifstream file("input.txt");

    if (!file.is_open())
    {
        cout << "Error: Cannot open file!" << endl;
        return 1;
    }

    string line;

    cout << "File content:\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

    return 0;
}
