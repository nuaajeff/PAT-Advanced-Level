#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Account
{
    string username;
    string password;
    bool is_modified;
    Account() { }
    Account(const string &username, const string &password, bool is_modified) :
        username(username), password(password), is_modified(is_modified) { }
};

int main()
{
    int n;
    cin >> n;
    vector<Account> accounts;
    for (int i = 0; i < n; i++) {
        Account acc;
        cin >> acc.username >> acc.password;
        acc.is_modified = false;
        accounts.push_back(acc);
    }
    vector<int> mdf_idx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < accounts[i].password.size(); j++) {
            if (accounts[i].password[j] == '1') {
                accounts[i].password[j] = '@';
                accounts[i].is_modified = true;
            } else if (accounts[i].password[j] == '0') {
                accounts[i].password[j] = '%';
                accounts[i].is_modified = true;
            } else if (accounts[i].password[j] == 'l') {
                accounts[i].password[j] = 'L';
                accounts[i].is_modified = true;
            } else if (accounts[i].password[j] == 'O') {
                accounts[i].password[j] = 'o';
                accounts[i].is_modified = true;
            }
        }
        if (accounts[i].is_modified) {
            mdf_idx.push_back(i);
        }
    }
    if (mdf_idx.size() == 0) {
        if (n == 1) {
            cout << "There is 1 account and no account is modified" << endl;
        } else {
            cout << "There are " << n << " accounts and no account is modified" << endl;
        }
        return 0;
    }
    cout << mdf_idx.size() << endl;
    for (auto i : mdf_idx) {
        cout << accounts[i].username << " " << accounts[i].password << endl;
    }
    return 0;
}