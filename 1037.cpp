#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nc, np;
    cin >> nc;
    vector<int> coupons;
    for (int i = 0; i < nc; i++) {
        int c;
        cin >> c;
        coupons.push_back(c);
    }
    cin >> np;
    vector<int> products;
    for (int i = 0; i < np; i++) {
        int p;
        cin >> p;
        products.push_back(p);
    }

    sort(coupons.rbegin(), coupons.rend());
    sort(products.rbegin(), products.rend());

    int c_mid = 0, p_mid = 0;
    for (int i = 0; i < coupons.size(); i++) {
        if (coupons[i] <= 0) break;
        c_mid++;
    }
    for (int i = 0; i < products.size(); i++) {
        if (products[i] <= 0) break;
        p_mid++;
    }
    //cout << c_mid << " " << p_mid << endl;
    int total = 0;
    for (int i = 0; ; i++) {
        if (i == p_mid || i == c_mid) break;
        total += products[i] * coupons[i];
    }
    for (int i = products.size()-1, j = coupons.size()-1; ; i--, j--) {
        if (i < p_mid || j < c_mid) break;
        total += products[i] * coupons[j];
    }
    cout << total << endl;
    return 0;
}