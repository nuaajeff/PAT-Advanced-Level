/**
 * 注意考虑边界值和特殊值
 * 本题中如果没有考虑只输入0的情况
 * 会造成有一个测试点无法通过
 * 同时要注意样例的大小，此题N为10^100
 * 用int存入肯定会超出限制
 **/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int add_bit(long long number)
{
    int bit = 0;
    int sum = 0;
    while (number != 0)
    {
        bit = number % 10;
        sum += bit;
        number /= 10;
    }
    return sum;
}

vector<int> get_bit(long long summary)
{
    vector<int> bits;
    if (summary == 0)
    {
        bits.push_back(0);
    }
    while (summary != 0)
    {
        bits.push_back(summary % 10);
        summary /= 10;
    }
    reverse(bits.begin(), bits.end());
    return bits;
}

int add_string_bit(string number)
{
    int summary = 0;
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] != '\0' && number[i] != '\n')
            summary += number[i]-'0';
    }
    return summary;
}

int main()
{
    vector<string> alphabet;
    alphabet.push_back("zero");
    alphabet.push_back("one");
    alphabet.push_back("two");
    alphabet.push_back("three");
    alphabet.push_back("four");
    alphabet.push_back("five");
    alphabet.push_back("six");
    alphabet.push_back("seven");
    alphabet.push_back("eight");
    alphabet.push_back("nine");
    string number;
    cin >> number;
    long long summary = add_string_bit(number);
    vector<int> bits = get_bit(summary);
    if (bits.size() == 0)
    {
        cout << alphabet[0];
    }
    else{
        for (int i = 0; i < bits.size(); i++)
        {
            i != bits.size()-1 ? cout << alphabet[bits[i]] <<  ' ' : cout << alphabet[bits[i]];
        }
    }
    return 0;
}