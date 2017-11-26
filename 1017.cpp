#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Customer{
    int begintime;
    int lasttime;
};

bool cmp(Customer a, Customer b)
{
    return a.begintime < b.begintime;
}

int main()
{
    int custom_num, window_num;
    cin >> custom_num >> window_num;
    vector<int> windows(window_num, 0);
    vector<Customer> customers;
    for (int i = 0; i < custom_num; i++)
    {
        int hour, minute, second, last;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &last);

        int time = second + minute * 60 + hour * 60 * 60;
        Customer cus;
        cus.begintime = time;
        cus.lasttime = last * 60;
        customers.push_back(cus);
    }

    sort(customers.begin(), customers.end(), cmp);

    int waittime = 0;
    int late_num = 0;
    int EARLY_TIME = 8 * 60 * 60;
    int LATE_TIME = 1 + 17 * 60 * 60;
    for (int i = 0; i < windows.size(); i++)
    {
        windows[i] = EARLY_TIME;
    }

    for (int i = 0; i < customers.size(); i++)
    {
        //cout << customers[i].begintime << ' ' << customers[i].lasttime << endl;
    }
    for (int i = 0; i < custom_num; i++)
    {
        if (customers[i].begintime >= LATE_TIME)
        {
            late_num++;
            continue;
        }
        if (customers[i].begintime < EARLY_TIME)
        {
            waittime += EARLY_TIME - customers[i].begintime;
            customers[i].begintime = EARLY_TIME;
        }
        int min_window_index = 0;
        int min_window = windows[0];
        for (int j = 0; j < window_num; j++)
        {
            if (windows[j] < min_window)
            {
                min_window_index = j;
                min_window = windows[j];
            }
        }
        //cout << "min_window: " << min_window << endl;
        if (customers[i].begintime < windows[min_window_index])
        {
            waittime += windows[min_window_index] - customers[i].begintime;
            //cout << "min_window: " << windows[min_window_index] << endl;
            windows[min_window_index] += customers[i].lasttime;
            //cout << "test1" << endl;
            //cout << "min_window: " << windows[min_window_index] << endl;
            //cout << "customers: " << customers[i].begintime << endl;
            //cout << "waittime: " << waittime << endl;
        }
        else
        {
            windows[min_window_index] = customers[i].begintime + customers[i].lasttime;
            //cout << "min_window: " << min_window << endl;
            //cout << "test2" << endl;
        }
    }
    if (custom_num == late_num)
        printf("0.0");
    else{
        double wait = waittime / 60.0 / (custom_num-late_num);
        //cout << waittime << " " << custom_num << endl;
        printf("%.1f", wait);
    }
    return 0;
}