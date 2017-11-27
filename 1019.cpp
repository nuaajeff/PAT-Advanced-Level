/**
 * 注意该题如果用字符串形式作转换，单个位数可能会超过256，导致结果错误
 * 故应该使用int格式
 **/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> change(long long num, long long base)
{
    /**
    string a = "";
    if (num == 0)
        return "0";
    while (num != 0)
    {
        char b = num % base + '0';
        a = b + a;
        num /= base;
    }
    return a;
    **/
    if (num == 0) return vector<int>{0};
    vector<int> v;
    while(num)
    {
        v.push_back(num % base);
        num /= base;
    }
    return v;
}

int main()
{
    long long num, base;
    cin >> num >> base;
    vector<int> num_b = change(num, base);
    vector<int> r_num_b = num_b;
    reverse(r_num_b.begin(), r_num_b.end());
    num_b == r_num_b ? cout << "Yes" << endl : cout << "No" << endl;
    for (int i = 0; i < r_num_b.size(); i++)
    {
        cout << r_num_b[i];
        if (i != r_num_b.size() - 1)
            cout << " ";
    }
}