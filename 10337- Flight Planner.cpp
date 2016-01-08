#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;

int dp[15][1005]; // i = altitude j = distance dp[i][j] = cost so far
int X;
int w;
int wind[15][1005];// i = altitudes , j = X/100
const int oo = 10e8;

int value (int a , int d)
{
    if (d == w  &&  a == 9)
        return 0;

    if ( a > 9 || a < 0 || d >= w )
        return oo;

    if (dp [a][d] != -1)
        return dp[a][d];

    int high, low , hold;

    high = 60 - wind[a][d] + value (a - 1 , d + 1);
    low = 20 - wind[a][d] + value (a + 1 , d + 1);
    hold = 30 - wind[a][d] + value(a  , d + 1);

    return dp[a][d] = min(high , min(low , hold));


}


int main ()
{
    int TC;
    cin >> TC;

    while (TC--)
    {
        cin >> X;
        w = X / 100;

        memset(dp , -1 , sizeof dp);

        for ( int i = 0 ; i < 10 ; i++)
            for ( int j = 0 ; j < w ; j++)
                cin >> wind[i][j];

        cout << value(9,0)<< endl;
        cout << endl;
    }
    return 0;
}
