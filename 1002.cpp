#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    map<int, double> ex_map;
    int max_ex = 0;
    for (int i = 0; i < 2; i++)
    {
        //cout << "log001" << endl;
        int k;
        cin >> k;
        while (k != 0)
        {
            k--;
            //cout << "k: " << k << endl;
            //cout << "log002" << endl;
            int ex;
            double co;
            cin >> ex >> co;
            //cout << ex << ' ' << co << endl;
            if (ex > max_ex)
                max_ex = ex;
            ex_map[ex] += co;
            //cout << "log003" << endl;
        }
    }
    //cout << "log004" << endl;
    int num = 0;
    for (int i = 0; i <= max_ex; i++)
    {
        if (ex_map[i] != 0)
            num++;
    }
    cout << num;
    cout.precision(2);
    cout << showpoint;
    for (int i = max_ex; i >= 0; i--)
    {
        if (ex_map[i] != 0)
        {
            cout << ' ' << i << ' ' << ex_map[i];
        }
    }
    cout << endl;
    return 0;
}