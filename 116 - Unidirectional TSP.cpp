#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>

using namespace std;

// How to output the path ?

int grid [15][105]; 
int dp[15][105];
int m , n;

int f(int i , int j)
{

    if (i < 0)
        i += m;

    if ( i >= m)
        i = 0;

    if (j >= n )
        return 0;

    if ( dp[i][j] != -1)
        return dp[i][j];

    int E , NE , SE;

    E = f(i , j+1) + grid[i][j];
    NE = f(i+1 , j +1) + grid[i][j];
    SE = f(i - 1 , j +1) + grid[i][j];

    return dp[i][j] = min(min(E , NE) , SE);


}


int main()
{   string s;
    while ( getline(cin, s) && s.length() > 0)
    {
        istringstream iss(s);
        iss >> m >> n;

        memset(dp, -1 , sizeof dp);

        for ( int i = 0 ; i < m ; i++)
            for ( int j = 0 ; j < n ; j++)
                cin >> grid[i][j];

        int fin = 10e6;
        for (int i = 0 ;i <  m; i++)
        {
            fin = min(f(i , 0) , fin );
        }

        cout << fin << endl;
        cin.ignore(10000 , '\n');
    }

    return 0;
}

