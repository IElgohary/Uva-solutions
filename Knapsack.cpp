#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int w[10]; // weight of items
int p[10]; // prices
int n; // number of items
int INF = 1000000;
int dp[5][11];// 10 is weight of bag and items = 5

int val(int i , int remW)
{
    if ( remW < 0 )
        return -INF;

    if ( remW == 0)
        return 0;

    if ( i == n)
        return 0;

    if ( dp[i][remW] != -1)
        return dp[i][remW];

    int leave = val(i+1 , remW);
    int take = val(i+1 , remW - w[i]) + p[i];
    dp[i][remW] = max(leave , take); //max price after taking item i and having weight left remW
    return dp[i][remW];

}

int main ()
{
    int bag;


    for (int i =0 ; i < 5; ++i) // 5 items
        for (int j =0 ; j < 10; ++j) // 10 weight of bag
                dp[i][j] = -1;

    cin >> bag;
    cout << val(0, bag);

    return 0;
}
