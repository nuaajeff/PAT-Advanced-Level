#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int result = m + n;
    string res = to_string(result);
    string stand_res;
    int len = res.size();
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        if(j == 3 && res[len-i-1] != '-')
        {
            stand_res = "," + stand_res;
            j = 0;
        }
        stand_res = res[len-i-1] + stand_res;
        j++;
    }
    cout << stand_res << endl;
    return 0;
}