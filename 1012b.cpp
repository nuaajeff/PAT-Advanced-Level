#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student{
    string id;
    int c;
    int m;
    int e;
    double a;
};

int main()
{
    int stu_num, check_num;
    cin >> stu_num >> check_num;
    vector<Student> stu_lst;
    vector<int> grd_c;
    vector<int> grd_m;
    vector<int> grd_e;
    vector<double> grd_a;
    while (stu_num--)
    {
        string id;
        int c, m, e;
        cin >> id >> c >> m >> e;
        double a = (c+m+e) / 3.0;
        Student stu;
        stu.id = id;
        stu.c = c;
        stu.m = m;
        stu.e = e;
        stu.a = a;
        stu_lst.push_back(stu);
        grd_c.push_back(c);
        grd_m.push_back(m);
        grd_e.push_back(e);
        grd_a.push_back(a);
    }

    sort(grd_c.rbegin(), grd_c.rend());
    sort(grd_m.rbegin(), grd_m.rend());
    sort(grd_e.rbegin(), grd_e.rend());
    sort(grd_a.rbegin(), grd_a.rend());
    char rank[4] = {'A', 'C', 'M', 'E'};
    int stu_rank[4];

    while (check_num--)
    {
        string id;
        cin >> id;
        int i;
        for (i = 0; i < stu_lst.size(); i++)
            if (stu_lst[i].id == id)
                break;
        if (i == stu_lst.size())
        {
            cout << "N/A" << endl;
            continue;
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < grd_a.size(); k++)
            {
                if (grd_a[k] == stu_lst[i].a)
                {
                    stu_rank[0] = k;
                    break;
                }
            }
            for (int k = 0; k < grd_c.size(); k++)
            {
                if (grd_c[k] == stu_lst[i].c)
                {
                    stu_rank[1] = k;
                    break;
                }
            }
            for (int k = 0; k < grd_m.size(); k++)
            {
                if (grd_m[k] == stu_lst[i].m)
                {
                    stu_rank[2] = k;
                    break;
                }
            }
            for (int k = 0; k < grd_e.size(); k++)
            {
                if (grd_e[k] == stu_lst[i].e)
                {
                    stu_rank[3] = k;
                    break;
                }
            }
        }
        if (i != stu_lst.size())
        {
            int high_rank = 100000;
            int high_index = -1;
            for (int j = 0; j < 4; j++)
            {
                if (stu_rank[j] < high_rank)
                {
                    //cout << "stu_rank: " << j << " " << stu_rank[j] << endl;
                    high_rank = stu_rank[j];
                    high_index = j;
                }
            }
            cout << high_rank+1 << ' ' << rank[high_index] << endl;
        }
    }
    return 0;
}