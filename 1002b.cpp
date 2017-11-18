#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    float poly[1001];
    int max_ex = 0;
    int k;
    int ex;
    float co;
    memset(poly, 0, sizeof(poly));

    for (int i = 0; i < 2; i++)
    {
        cin >> k;
        while(k != 0)
        {
            k--;
            cin >> ex >> co;
            poly[ex] += co;
        }
    }
    int num = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (poly[i] != 0)
            num++;
    }
    cout << num;
    //cout.precision(2);
    //cout << showpoint;
    for (int i = 1000; i >= 0; i--)
    {
        if (poly[i] != 0)
        {
            cout<< fixed <<setprecision(1);  
            cout << ' ' << i << ' ' << poly[i];
        }
    }
    return 0;
}