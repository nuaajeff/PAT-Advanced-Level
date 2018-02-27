#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;
    map<int, int> nummap;
    vector<int> hash;
    int num;
    while(k--) {
        cin >> num;
        hash.push_back(num);
        nummap[num]++;
    }
    for (int i = 0; i < hash.size(); i++) {
        if (nummap[hash[i]] == 1) {
            cout << hash[i];
            break;
        }
        if (i == hash.size() - 1) {
            cout << "None";
        }
    }    
    return 0;
}