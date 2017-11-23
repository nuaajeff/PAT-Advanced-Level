/**
 * 本题对并列成绩的处理有误
 * 应该把成绩单独存到vector里然后排序
 * 再拿科目成绩查询排名
 * 而非查询学生姓名
 **/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student
{
    string id;
    double grd;
};

bool cmp(Student a, Student b)
{
    return a.grd > b.grd;
}

int main()
{
    vector<Student> c_grd;
    vector<Student> m_grd;
    vector<Student> e_grd;
    vector<Student> a_grd;

    int stu_num, check_num;
    cin >> stu_num >> check_num;
    for (int i = 0; i < stu_num; i++)
    {
        string id;
        int c, m, e;
        cin >> id >> c >> m >> e;
        double a = (c+m+e) / 3;
        Student stu_c;
        Student stu_m;
        Student stu_e;
        Student stu_a;

        stu_c.id = id;
        stu_c.grd = c;
        stu_m.id = id;
        stu_m.grd = m;
        stu_e.id = id;
        stu_e.grd = e;
        stu_a.id = id;
        stu_a.grd = a;
        c_grd.push_back(stu_c);
        m_grd.push_back(stu_m);
        e_grd.push_back(stu_e);
        a_grd.push_back(stu_a);
    }

    sort(c_grd.begin(), c_grd.end(), cmp);
    sort(m_grd.begin(), m_grd.end(), cmp);
    sort(e_grd.begin(), e_grd.end(), cmp);
    sort(a_grd.begin(), a_grd.end(), cmp);

    char cls[4] = {'A', 'C', 'M', 'E'};
    while (check_num--)
    {
        string id;
        cin >> id;
        int rank[4];
        memset(rank, 0, sizeof(rank));

        for (int i = 0; i < a_grd.size(); i++)
        {
            if(a_grd[i].id == id)
            {
                rank[0] = i+1;
                break;
            }
        }
        for (int i = 0; i < c_grd.size(); i++)
        {
            if(c_grd[i].id == id)
            {
                rank[1] = i+1;
                break;
            }
        }
        for (int i = 0; i < m_grd.size(); i++)
        {
            if(m_grd[i].id == id)
            {
                rank[2] = i+1;
                break;
            }
        }
        for (int i = 0; i < e_grd.size(); i++)
        {
            if(e_grd[i].id == id)
            {
                rank[3] = i+1;
                break;
            }
        }
        
        if (rank[0] == 0)
        {
            cout << "N/A" << endl;
            continue;
        }

        int high = 10000;
        int high_index = 5;
        for (int i = 0; i < 4; i++)
        {
            if (rank[i] < high)
            {
                high = rank[i];
                high_index = i;
            }
        }
        cout << high << ' ' << cls[high_index] << endl;
        
    }

}