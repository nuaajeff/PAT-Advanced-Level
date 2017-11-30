#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    Student(const int id, const string &name, const int grade) : id(id), name(name), grade(grade) {}
    int id;
    string name;
    int grade;
};

bool cmp1(const Student &a, const Student &b)
{
    return a.id < b.id;
}

bool cmp2(const Student &a, const Student &b)
{
    if (a.name != b.name) {
        return a.name < b.name;
    } else {
        return a.id < b.id;
    }
}

bool cmp3(const Student &a, const Student &b)
{
    if (a.grade != b.grade) {
        return a.grade < b.grade;
    } else {
        return a.id < b.id;
    }
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<Student> stu;
    for (int i = 0; i < n; i++) {
        string name; 
        name.resize(10);
        int id, grade;
        scanf("%d %s %d", &id, &name[0], &grade);
        //cin >> id >> name >> grade;
        Student student(id, name, grade);
        stu.push_back(student);
    }
    if (c == 1) {
        sort(stu.begin(), stu.end(), cmp1);
    } else if (c == 2) {
        sort(stu.begin(), stu.end(), cmp2);
    } else if (c == 3) {
        sort(stu.begin(), stu.end(), cmp3);
    }

    for (int i = 0; i < n; i++) {
        //cout << stu[i].id << " " << stu[i].name << " " << stu[i].grade << endl;
        printf("%06d %s %d\n", stu[i].id, stu[i].name.c_str(), stu[i].grade);
    }

    return 0;
}