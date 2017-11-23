#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    double bets[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            double bet;
            cin >> bet;
            bets[i][j] = bet;
        }
    }
    double product = 1;
    char namely[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++)
    {
        double max = 0;
        int max_index = 0;
        for (int j = 0; j < 3; j++)
        {
            if (bets[i][j] > max)
            {
                max = bets[i][j];
                max_index = j;
            }
        }
        product *= max;
        cout << namely[max_index] << ' ';
    }
    product = (product * 0.65 - 1) * 2;
    printf("%.2lf", product);
}