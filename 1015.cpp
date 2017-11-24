/**
 * 本题考点：
 * 1.十进制与各进制互相转换
 * 2.素数检查
 **/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int num)
{
    if (num <= 1) return false;
    int sqr = sqrt(num);
    for (int i = 2; i <= sqr; i++)
        if (num % i == 0) return false;
    return true;
}

int main()
{
    while(1)
    {
        int n, d;
        cin >> n;
        if (n < 0)
            break;
        cin >> d;
        if (!is_prime(n))
        {
            cout << "No" << endl;
            continue;
        }
        vector<int> num_rad_v;
        int num = n;
        while(num != 0)
        {
            num_rad_v.push_back(num % d);
            num /= d;
        }
        int num_rad = 0;
        for (int i = 0; i < num_rad_v.size(); i++)
        {
            num_rad = num_rad * d + num_rad_v[i];
        }
        if (!is_prime(num_rad))
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}