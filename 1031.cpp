#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    /**
    if (n <= 3) {
        cout << str;
        return 0;
    }
    **/
    int n1 = (n + 2) / 3;
    int n2 = n + 2 - n1 * 2;
    string blank_space = "";
    for (int i = 0; i < n2-2; i++) {
        blank_space += " ";
    }
    for (int i = 0; i < n1-1; i++) {
        cout << str[i] << blank_space << str[str.size()-1-i] << endl;
    }
    for (int i = n1-1; i < n1+n2-1; i++) {
        cout << str[i];
    }
    return 0;
}