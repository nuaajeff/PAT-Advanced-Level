/**
 * 声明变量时不要忘记其类型
 * 把float型声明成int型会导致输入出错
 **/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

float poly1[1001];
float poly2[1001];
float poly3[2001];

int main()
{
    memset(poly1, 0, sizeof(poly1));
    memset(poly2, 0, sizeof(poly2));
    memset(poly3, 0, sizeof(poly3));
    int k1;
    cin >> k1;
    //cout << "k1: " << k1 << endl;
    while(k1--)
    {
        //cout << "k1: " << k1 << endl;
        int n;
        float a;
        cin >> n >> a;
        //cout << "n: " << n << " a: " << a << endl;
        poly1[n] = a;
    }
    int k2;
    cin >> k2;
    //cout << "k2: " << k2 << endl;
    while(k2--)
    {
        int n;
        float a;
        cin >> n >> a;
        //cout << "n: " << n << " a: " << a << endl;
        poly2[n] = a;
    }
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (poly1[i] != 0 && poly2[j] != 0)
            {
                poly3[i+j] += poly1[i] * poly2[j];
            }
        }
    }
    int num = 0;
    for (int i = 0; i < 2001; i++)
    {
        if (poly3[i] != 0)
        {
            num++;
        }
    }
    
    cout << num;
    for (int i = 2000; i >= 0; i--)
    {
        if (poly3[i] != 0)
            printf(" %d %.1f", i, poly3[i]);
    }
    
    
    return 0;
}