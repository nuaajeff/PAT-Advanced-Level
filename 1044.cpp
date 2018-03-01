// 难题
// 使用二分法，应当复习。除了思路之外，有很多细节问题

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> chain;
vector<int> sum_i;

int binary(int left, int right, int num) {
    //cout << "num: " << num << endl;
    while(left < right) {
        int mid = (left+right) / 2;
        //cout << mid << endl;
        if (sum_i[mid] > num) {
            right = mid;
        } 
        else {
            left = mid + 1;
        } 
        //else if (sum_i[mid] == num) {
        //    return mid;
        //}
    }
    return left;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        chain.push_back(d);
    }
    sum_i.push_back(0);
    for (int i = 0; i < n; i++) {
        sum_i.push_back(sum_i[i] + chain[i]);
    }
    int nearm = 100000001;
    for (int i = 1; i <= n; i++) {
        //cout << "the " << i << "th time." << endl;
        int j = binary(i, n+1, sum_i[i-1]+m);
        //cout << "j: " << j << endl;
        if (sum_i[j-1] - sum_i[i-1] == m) {
            nearm = m;
            break;
        }
        else if (j <= n && sum_i[j] - sum_i[i-1] < nearm) {
            nearm = sum_i[j] - sum_i[i-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        //cout << "the " << i << "th time." << endl;
        int j = binary(i, n+1, sum_i[i-1]+nearm);
        //cout << "j: " << j << endl;
        if (sum_i[j-1] - sum_i[i-1] == nearm) {
            printf("%d-%d\n", i, j-1);
        }
    }
    //cout << "near_m: " << nearm << endl;
    return 0;
}