#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string num;
    cin >> num;
    vector<int> numv;
    for (auto x : num) {
        numv.push_back(x-'0');
    }
    vector<int> numd(numv.size()+1);
    int carry = 0;
    for (int i = numv.size()-1; i >= 0; i--) {
        int n = numv[i] * 2;
        int bit = n % 10;
        numd[i+1] = bit + carry;
        carry = n / 10;
    }
    if (carry == 1) {
        numd[0] = carry;
    } else {
        vector<int> temp(numd.begin()+1, numd.end());
        numd = temp;
    }
    vector<int> count1(10, 0);
    vector<int> count2(10, 0);
    for (auto x : numv) {
        count1[x]++;
    }
    for (auto x : numd) {
        count2[x]++;
    }
    count1 == count2 ? cout << "Yes" << endl : cout << "No" << endl;
    for (auto x : numd) {
        cout << x;
    }
    return 0;
}