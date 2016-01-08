/*input
4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567
*/
#include <bits/stdc++.h>

using namespace std;
int T, sum , num ;
int arr[25];
int memo[1000][20];

bool rec(int index, int s)
{
    if (s == sum)
        return true;
    if (s > sum || index == num)
        return false;
    if(memo[s][index] != -1)
        return memo[s][index];
    bool take = rec(index+1, s+arr[index]);
    bool leave = rec(index+1, s);
    return  take || leave;
}
int main()
{  
    cin >> T;
    while(T--)
    {

        cin >> sum>> num;
        for(int i = 0 ; i < 1000 ;i++ )
            for(int j = 0 ; j < 20; j++)
                memo[i][j] = -1;

        for(int i = 0 ; i < num ; i++)
            cin >> arr[i];

        if(rec(0, 0))
            cout << "YES" <<endl;
        else
            cout << "NO"<< endl;
    }
}

