/**
 * reference1: http://blog.csdn.net/sgbfblog/article/details/8032464
 * reference2: http://blog.csdn.net/hcbbt/article/details/10454947
 * 后期可练习动态规划解法，本题用累积求和解
 **/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> num;
    while (k--)
    {
        int n;
        cin >> n;
        num.push_back(n);
    }
    int maxsum, maxhere, maxsum_s, maxsum_e, maxhere_s, maxhere_e;
    maxsum = maxhere = num[0];
    maxsum_s = maxsum_e = maxhere_s = maxhere_e = num[0];

    for (int i = 1; i < num.size(); i++)
    {
        if (maxhere < 0)
        {
            maxhere = num[i];
            maxhere_s = num[i];
            maxhere_e = num[i];
        }
        else
        {
            maxhere += num[i];
            maxhere_e = num[i];
        }
        if (maxhere > maxsum)
        {
            maxsum = maxhere;
            maxsum_s = maxhere_s;
            maxsum_e = maxhere_e;
        }
    }
    if (maxsum < 0)
        cout << "0" << ' ' << num[0] << ' ' << num[num.size()-1];
    else
        cout << maxsum << ' ' << maxsum_s << ' ' << maxsum_e;
    // 注意两个要求：1.输出的是最短的序列 2.如果全为负输出从头到尾所有值
}