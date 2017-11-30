#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<long int> vec1;
    vector<long int> vec2;
    int cnt1, cnt2;
    long int num1, num2;
    scanf("%d", &cnt1);
    for (int i = 0; i < cnt1; i++) {
        scanf("%ld", &num1);
        vec1.push_back(num1);
    }
    scanf("%d", &cnt2);
    for (int i = 0; i < cnt2; i++) {
        scanf("%ld", &num2);
        vec2.push_back(num2);
    }

    int mid = (cnt1 + cnt2) / 2 - 1;
    if ((cnt1 + cnt2) % 2 == 1) mid = (cnt1+cnt2) / 2;
    int mnum = 0;
    int cnt = -1;
    for (int i = -1, j = -1; ;) {
        //if (i >= cnt1 && j >= cnt2) break;
        if (cnt == mid) break;
        if (j+1 == cnt2 || i+1 != cnt1 && vec1[i+1] < vec2[j+1]) {
            i++;
            cnt++;
            mnum = vec1[i];
        } else if (i+1 == cnt1 || j+1 != cnt2 && vec2[j+1] < vec1[i+1]) {
            j++;
            cnt++;
            mnum = vec2[j];
        }
    }
    printf("%d", mnum);
    return 0;
}
