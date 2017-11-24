/**
 * 注意：是在17：00及之后才开始的业务不再处理输出sorry
 * 注意边界条件：有可能出现办业务人数少于window_num * line_cap的情况！
 **/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Window{
    Window() : poptime(0), endtime(0) {}
    int poptime, endtime;
    queue<int> que;
};

int main()
{
    int window_num, line_cap, cus_num, query_num;
    cin >> window_num >> line_cap >> cus_num >> query_num;
    vector<Window> window(window_num);
    vector<int> process_time;
    vector<int> result(cus_num, 0);
    for (int i = 0; i < cus_num; i++)
    {
        int time_;
        cin >> time_;
        process_time.push_back(time_);
    }
    int index = 0;
    // 该循环要注意边界情况，即index < cus_num
    while(index < window_num * line_cap && index < cus_num)
    {
        for (int j = 0; j < window_num; j++)
        {
            window[j].que.push(index);
            window[j].endtime += process_time[index];
            result[index] = window[j].endtime;
            if (index < window_num)
                window[j].poptime = process_time[index];
            index++;
            if (index == window_num * line_cap || index == cus_num)
                break;
        }
    }
    while (index < cus_num)
    {
        int min_poptime = window[0].poptime; 
        int min_window = 0;
        for (int i = 0; i < window.size(); i++)
        {
            if (window[i].poptime < min_poptime)
            {
                min_poptime = window[i].poptime;
                min_window = i;
            }
        }
        window[min_window].que.pop();
        window[min_window].poptime += process_time[window[min_window].que.front()];
        window[min_window].que.push(index);
        window[min_window].endtime += process_time[index];
        result[index] = window[min_window].endtime;
        index++;
    }
    for (int i = 0; i < result.size()+1; i++)
    {
        //cout << "result " << i << " : " << result[i] << endl;
    }
    for (int i = 0; i < query_num; i++)
    {
        int query;
        cin >> query;
        int minute = result[query-1];
        int diff = process_time[query-1];
        if (minute-diff >= 540)
            cout << "Sorry" << endl;
        else
            printf("%02d:%02d\n",(minute + 480) / 60, (minute + 480) % 60);
    }
    return 0;
}