
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int w[10]; // weight of items 
int p[10]; // prices
int n; // number of items
int INF = 1000000;
int dp[5][11] = {0};// bag has max weight of 10 and items = 5

int main ()
{
    int bag;
    cin >> bag;

	for (int i = 0; i < n; ++i) // weight = 0
        dp[i][0] = 0;

    for (int i = 0; i < w[0]; ++i) // first item until I can take it
        dp[0][i] = 0;

    for (int i = 0; i < bag; ++i) // taking first item
        dp[0][i] = p[0];

    for ( int i = 1 ; i < n ; i++)
    {
    	for ( int j = 0 ; j <= bag ; j++)
    	{
    		int leave = dp[i-1][j];
    		int take = p[i] + dp[i-1][j];
    		dp[i][j] = max(take , leave);
    	}
    }
    
   cout << dp[4/*n - 1 */][10 /*W*/];
   
    return 0;
}
