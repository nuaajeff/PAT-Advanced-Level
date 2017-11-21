/**
 * 用到的STL函数有
 * 1.string.substr()
 * 2.string.stoi()
 **/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Member
{
    string id;
    string sign_in;
    string sign_out;
};

bool is_earlier(string a, string b)
{
    int hha = stoi(a.substr(0, 2));
    int hhb = stoi(b.substr(0, 2));
    int mma = stoi(a.substr(3, 2));
    int mmb = stoi(b.substr(3, 2));
    int ssa = stoi(a.substr(6, 2));
    int ssb = stoi(b.substr(6, 2));
    if (hha < hhb)
    {
        return true;
    }
    else if (hha > hhb)
    {
        return false;
    }
    else
    {
        if (mma < mmb)
        {
            return true;
        }
        else if (mma > mmb)
        {
            return false;
        }
        else
        {
            if (ssa < ssb)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

string find_sign_in(const vector<Member>& members)
{
    Member earliest = members[0];
    for (int i = 0; i < members.size(); i++)
    {
        if (is_earlier(members[i].sign_in, earliest.sign_in))
        {
            earliest = members[i];
        }
    }
    return earliest.id;
}

string find_sign_out(const vector<Member>& members)
{
    Member latest = members[0];
    for (int i = 0; i < members.size(); i++)
    {
        if (is_earlier(latest.sign_out, members[i].sign_out))
        {
            latest = members[i];
        }
    }
    return latest.id;
}

int main()
{
    int k;
    cin >> k;
    vector<Member> members;
    while(k--)
    {
        string id, sign_in, sign_out;
        cin >> id >> sign_in >> sign_out;
        Member member;
        member.id = id;
        member.sign_in = sign_in;
        member.sign_out = sign_out;
        members.push_back(member);
    }
    string sign_in_id = find_sign_in(members);
    string sign_out_id = find_sign_out(members);
    cout << sign_in_id << ' ' << sign_out_id;

    return 0;
}