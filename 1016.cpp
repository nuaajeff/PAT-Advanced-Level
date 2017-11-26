#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> rate(24);
struct Record
{
    Record (string name, int month, int day, int hour, int minute) : name(name), month(month), day(day), hour(hour), minute(minute) {}
    string name;
    int month;
    int day;
    int hour;
    int minute;
    bool online;
};

bool cmp(Record a, Record b)
{
    if (a.name != b.name)
        return a.name < b.name;
    else if (a.day != b.day)
        return a.day < b.day;
    else if (a.hour != b.hour)
        return a.hour < b.hour;
    else
        return a.minute < b.minute;
}

void get_ans(Record a, Record b, int &total_time, double &money)
{
    total_time = 0;
    total_time += b.minute - a.minute;
    total_time += (b.hour - a.hour) * 60;
    total_time += (b.day - a.day) * 24 * 60;
    money = 0;
    int day = a.day;
    int hour = a.hour;
    int minute = a.minute;
    while (day < b.day || hour < b.hour || minute < b.minute)
    {
        money += rate[hour];
        minute++;
        if (minute >= 60)
        {
            minute = 0;
            hour++;
        }
        if (hour >= 24)
        {
            hour = 0;
            day++;
        }
    }
    money /= 100;
}

int main()
{
    for (int i = 0; i < rate.size(); i++)
    {
        int r;
        cin >> r;
        rate[i] = r;
        //cout << i << ": " << r << endl;
    }
    int n;
    cin >> n;
    vector<Record> records;
    while(n--)
    {
        string name, line;
        int month, day, hour, minute;
        cin >> name;
        scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
        cin >> line;
        Record record(name, month, day, hour, minute);
        line == "on-line" ? record.online = true : record.online = false;
        records.push_back(record);
        //cout << n << ": " << month << ' ' << day << ' ' << hour << ' ' << minute << ' ' << record.online << endl;
    }
    //cout << "test" << endl;
    sort(records.begin(), records.end(), cmp);
    
    int cur = 0;
    int next;
    while (cur < records.size())
    {
        int need_print = 0;
        string name = records[cur].name;
        next = cur;
        while (next < records.size() && name == records[next].name)
        {
            if (need_print == 0 && records[next].online == true)
                need_print = 1;
            else if (need_print == 1 && records[next].online == false)
                need_print = 2;
            next++;
        }
        /**
        for (int i = cur; i < records.size(); i++)
        {
            if (i == records.size()-1)
            {
                next = records.size();
            }
            if (name != records[i].name)
            {
                next = i; 
                break;
            }
            if (records[i].online == true)
                need_print = 1;
            else if (need_print == 1 && records[i].online == false)
                need_print = 2;
        }
        **/
        //cout << "need_print: " << need_print << endl;
        if (need_print < 2)
        {
            cur = next;
            continue;
        }
        printf("%s %02d\n", name.c_str(), records[cur].month);
        double total_money = 0;
        for (int i = cur+1; i < next; i++)
        {
            if (records[i].online == false && records[i-1].online == true)
            {
                printf("%02d:%02d:%02d ", records[i-1].day, records[i-1].hour, records[i-1].minute);
                printf("%02d:%02d:%02d ", records[i].day, records[i].hour, records[i].minute);
                int total_time = 0;
                double money = 0;
                get_ans(records[i-1], records[i], total_time, money);
                printf("%d $%.2f\n", total_time, money);
                total_money += money;
            }
        }
        printf("Total amount: $%.2f\n", total_money);
        cur = next;
    }
    return 0;
}