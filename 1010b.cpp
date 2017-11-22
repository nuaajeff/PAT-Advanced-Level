/**
 * 该题要注意
 * 1.radix范围未知，实际上上界并非35，而是max(tag指定的数，下界)
 * 2.下界为最大位+1
 * 3.之所以max中含下界，是为了避免样例：11 b 1 10错误
 * 4.在二分查找时，不可直接计算出某个 radix 下数的值，因为可能会 longlong 溢出。于是需要用特定的 compare 函数，在累加的过程中判定是否大于另一个数。算是一种剪枝。
 * reference: https://www.cnblogs.com/549294286/p/3571604.html
 * 记一个奇怪的错误：long long型的mid传入到compare函数中，compare接受long long型的话，用例会出错，但是把接受类型改为int，用例通过。
 **/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int get_bit_dec(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else 
        return ch - 'a' + 10;
}

long long get_dec(string num, long long radix)
{
    long long dec = 0;
    for (auto x:num)
        dec = dec * radix + get_bit_dec(x);
    return dec;
}

int max_bit(string num)
{
    int m_b = 0;
    for (auto x:num)
        m_b = max(get_bit_dec(x), m_b);
    return m_b;
}

long long compare(string b, long long a, long long radix)
{
    long long m = 1;
    long long sum = 0;
    for (int i = b.size()-1; i >= 0; i--)
    {
        sum += get_bit_dec(b[i]) * m;
        m *= radix;
        if (sum > a)
            return 1;
    }
    return (sum == a) ? 0 : -1;
}

long long get_rad(string b, long long a)
{
    long long low = max_bit(b) + 1;
    long long high = max(a, low) + 1;
    long long res = -1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long k = compare(b, a, mid);
        if (k == 0) 
        {
            res = mid;
            high = mid - 1;
        }
        else if (k < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return res;
}

int main()
{
    string n1, n2;
    int tag;
    long long radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2)
        swap(n1, n2);
    long long dec_n1 = get_dec(n1, radix);
    long long rad_n2 = get_rad(n2, dec_n1);
    if (rad_n2 == -1)
        cout << "Impossible";
    else
        cout << rad_n2;
}