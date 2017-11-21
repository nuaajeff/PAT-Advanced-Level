#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> request;
    while (k--)
    {
        int flor;
        cin >> flor;
        request.push_back(flor);
    }
    int current = 0;
    int time = 0;
    for (int i = 0; i < request.size(); i++)
    {
        int diff = request[i] - current;
        if (diff > 0)
        {
            time += diff * 6;
            time += 5;
        }
        else if (diff < 0)
        {
            time += -1 * diff * 4;
            time += 5;
        }
        else if (diff == 0)
        {
            time += 5;
        }
        //cout << time << endl;
        current = request[i];
    }
    cout << time;
    return 0;
}