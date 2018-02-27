#include <iostream>
#include <vector>

using namespace std;

int num_to_cards(int num) {
    if (num >= 1 && num <= 13) {
        cout << "S" << num;
    }
    else if (num >= 14 && num <= 26) {
        cout << "H" << num - 13;
    }
    else if (num >= 27 && num <= 39) {
        cout << "C" << num - 26;
    }
    else if (num >= 40 && num <= 52) {
        cout << "D" << num - 39;
    }
    else if (num == 53) {
        cout << "J1";
    }
    else {
        cout << "J2";
    }
}

int main() {
    vector<int> cards;
    for (int i = 1; i <= 54; i++) {
        cards.push_back(i);
    }
    int k;
    cin >> k;
    vector<int> order;
    for (int i = 1; i <= 54; i++) {
        int ord;
        cin >> ord;
        order.push_back(ord);
    }

    vector<int> shuffle_cards(54, 0);

    while (k--) {
        for (int i = 0; i < order.size(); i++) {
            int j = order[i];
            shuffle_cards[j-1] = cards[i];
        }
        cards.assign(shuffle_cards.begin(), shuffle_cards.end());
    }
    for (int i = 0; i < cards.size()-1; i++) {
        num_to_cards(cards[i]);
        cout << " ";
    }
    num_to_cards(cards[cards.size()-1]);
}