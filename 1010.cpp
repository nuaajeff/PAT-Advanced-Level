#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int get_max(string word)
{
    char max = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] > max)
        {
            max = word[i];
        }
    }
    int radix = 0;
    if (max >= '0' && max <='9')
    {
        radix = max - '0';
    }
    else if (max >= 'a' && max <= 'z')
    {
        radix = max - 'a' + 10;
    }
    return radix; 
}

long long get_dec(string num, int radix)
{
    //long long dec_num = -1;
    if (get_max(num) >= radix)
        return -1;
    long long dec_num = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            dec_num += (num[i] - '0') * pow(radix, num.size()-i-1);
        }
        else if (num[i] >= 'a' && num[i] <= 'z')
        {
            dec_num += (num[i] - 'a' + 10) * pow(radix, num.size()-i-1);
        }
    }
    return dec_num;
}

long long get_radix(string num1, int radix, string num2)
{
    long long dec_num1, dec_num2;
    dec_num1 = get_dec(num1, radix);
    int i;
    for (i = 1; i <= dec_num1; i++)
    {
        dec_num2 = get_dec(num2, i);
        if (dec_num2 == -1)
            continue;
        //cout << i << ' ' << dec_num2 << endl;
        if (dec_num1 == dec_num2)
            break;
    }
    return i;
}

int main()
{
    string num1;
    string num2;
    int tag, radix;
    cin >> num1 >> num2 >> tag >> radix;
    int result = 0;
    if (tag == 1)
    {
        result = get_radix(num1, radix, num2);
    }
    else
    {
        result = get_radix(num2, radix, num1);
    }
    
    if (result < 1)
    {
        cout << "Impossible";
    }
    else
    {
        cout << result;
    }
    return 0;
}