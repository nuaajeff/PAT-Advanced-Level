#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 100000000;

struct Station 
{
    double price;
    double distance;
};

bool cmp(const Station &a, const Station &b)
{
    return a.distance < b.distance;
}

int main()
{
    double cmax, d, davg;
    int n;
    cin >> cmax >> d >> davg >> n;
    vector<Station> stations;
    for (int i = 0; i < n; i++) {
        Station s;
        cin >> s.price >> s.distance;
        stations.push_back(s);
    }
    Station des;
    des.price = 0;
    des.distance = d;
    stations.push_back(des);
    sort(stations.begin(), stations.end(), cmp);
    if (stations[0].distance != 0) {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }
    int now = 0;
    double farest = cmax * davg;
    double total_price = 0;
    double current_gas = 0;
    while (now < n) {
        int min_station = -1;
        double min_price = INF;
        for (int i = now+1; i <= n; i++) {
            if (stations[i].distance - stations[now].distance <= farest) {
                if (stations[i].price < min_price) {
                    min_price = stations[i].price;
                    min_station = i;
                    if (min_price < stations[now].price) break;
                }
            }
        }
        if (min_station == -1) break;
        double need = (stations[min_station].distance - stations[now].distance) / davg;
        if (min_price < stations[now].price) {
            if (current_gas < need) {
                total_price += (need - current_gas) * stations[now].price;
                current_gas = 0;
            } else {
                current_gas -= need;
            }
        } else {
            total_price += (cmax - current_gas) * stations[now].price;
            current_gas = cmax - need;
        }
        now = min_station;
    }
    if (now == n) {
        printf("%.2f\n", total_price);
    } else {
        printf("The maximum travel distance = %.2f\n", stations[now].distance + farest);
    }
    return 0;
}