#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string name;
    string gender;
    string cls;
    int grade;
};

int main()
{
    vector<Student> boys;
    vector<Student> girls;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student stu;
        cin >> stu.name >> stu.gender >> stu.cls >> stu.grade;
        if (stu.gender == "M") {
            boys.push_back(stu);
        } else {
            girls.push_back(stu);
        }
    }
    int highest_idx = -1;
    int highest = -1;
    int lowest_idx = -1;
    int lowest = 101;
    for (int i = 0; i < girls.size(); i++) {
        if (girls[i].grade > highest) {
            highest = girls[i].grade;
            highest_idx = i;
        }
    }
    for (int i = 0; i < boys.size(); i++) {
        if (boys[i].grade < lowest) {
            lowest = boys[i].grade;
            lowest_idx = i;
        }
    }
    if (highest_idx != -1) {
        cout << girls[highest_idx].name << " " << girls[highest_idx].cls << endl;
    } else {
        cout << "Absent" << endl;
    }
    if (lowest_idx != -1) {
        cout << boys[lowest_idx].name << " " << boys[lowest_idx].cls << endl;
    } else {
        cout << "Absent" << endl;
    }
    if (highest_idx != -1 && lowest_idx != -1) {
        cout << highest - lowest << endl;
    } else {
        cout << "NA" << endl;
    }
    return 0;
}