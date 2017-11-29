#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    string id;
    int grade;
    int location;
    Student (string id, int grade, int location) : id(id), 
        grade(grade), location(location) { }
};

bool cmp (const Student &a, const Student &b)
{
    if (a.grade != b.grade)
        return a.grade > b.grade;
    else return a.id < b.id;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<Student>> locations;
    vector<vector<int>> grades;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<Student> location;
        locations.push_back(location);
        vector<int> grade_;
        grades.push_back(grade_);
        for (int j = 0; j < k; j++) {
            string id;
            int grade;
            cin >> id >> grade;
            Student s(id, grade, i);
            locations[i].push_back(s);
            grades[i].push_back(grade);
        }
    }

    int total = 0;
    for (auto x : locations) {
        total += x.size();
    }
    cout << total << endl;

    vector<Student> all_stu;
    vector<int> all_grade;
    for (int i = 0; i < locations.size(); i++) {
        for (int j = 0; j < locations[i].size(); j++) {
            all_stu.push_back(locations[i][j]);
            all_grade.push_back(grades[i][j]);
        }
    }

    sort(all_grade.rbegin(), all_grade.rend());
    sort(all_stu.begin(), all_stu.end(), cmp);
    for (int i = 0; i < grades.size(); i++) {
        sort(grades[i].rbegin(), grades[i].rend());
    }

    for (int i = 0; i < all_grade.size(); i++) {
        cout << all_stu[i].id << ' ';
        int rank = 0;
        while (all_grade[rank] != all_stu[i].grade) rank++;
        cout << rank+1 << ' ';
        cout << all_stu[i].location + 1 << ' ';
        int lrank = 0;
        while (grades[all_stu[i].location][lrank] != all_stu[i].grade) lrank++;
        cout << lrank+1 << endl;
    }
    return 0;
}
