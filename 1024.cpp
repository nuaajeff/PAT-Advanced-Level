#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BigInt
{
    vector<int> num;
    BigInt (const string &str) {
        for (int i = str.size()-1; i >= 0; i--) {
            num.push_back(str[i] - '0');
        }
    }
    BigInt (const vector<int> &vctr) {
        num = vctr;
    }
};

bool palindromic(BigInt &num)
{
    vector<int> num2 = num.num;
    reverse(num2.begin(), num2.end());
    return num2 == num.num ? true : false;
}

BigInt reverse_int(BigInt &num)
{
    vector<int> num2 = num.num;
    reverse(num2.begin(), num2.end());
    BigInt num2_(num2);
    return num2_;
}

BigInt add_num(BigInt &num1, BigInt &num2)
{
    vector<int> n1 = num1.num;
    vector<int> n2 = num2.num;
    vector<int> n3;
    for (int i = 0, carry = 0; ; i++) {
        if (carry == 0 && i >= n1.size() && i >= n2.size()) break;
        int cur_bit = carry;
        if (i < n1.size()) cur_bit += n1[i];
        if (i < n2.size()) cur_bit += n2[i];
        carry = cur_bit / 10;
        n3.push_back(cur_bit % 10);
    }
    BigInt num3(n3);
    return num3;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;
    BigInt num1(n);
    int i = 0;
    do {
        if (palindromic(num1)) break;
        BigInt num2 = reverse_int(num1);
        num1 = add_num(num1, num2);
        i++;
    } while (i < k);
    for (int i = num1.num.size()-1; i >= 0; i--)
        cout << num1.num[i];
    cout << endl;
    cout << i << endl;
}