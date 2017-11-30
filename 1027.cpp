#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

string dec_to_13(int num)
{
    string n = "";
    char remainder;
    do {
        remainder = num % 13;
        if (remainder < 10) {
            remainder += '0';
        } else {
            remainder = remainder - 10 + 'A';
        }
        num /= 13;
        n = remainder + n;
    } while (num != 0);
    if (n.size() == 1) {
        n = '0' + n;
    }
    return n;
}

int main()
{
    int i, j, k;
    cin >> i >> j >> k;
    string i_ = dec_to_13(i);
    string j_ = dec_to_13(j);
    string k_ = dec_to_13(k);
    cout << "#" << i_ << j_ << k_ << endl;
    return 0;
}