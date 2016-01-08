#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

// decimal approximation problem

int L [15][105];
int N , M;
int dp [15][105];


int f (int i , int j, int hours )
{
    if (hours > M )
        return -10e6;

    if ( j > M - 1 && i <= N - 1)
        return -10e6;
    if ( i > N - 1 && j > M - 1 )
        return 0;

    if ( dp[i][hours] != -1)
        return dp[i][hours];

    int leave = f(i , j+1 ,hours);
    int take = -10e6;

    if ( L[i][j] >= 5)
        take = f(i+1 , 0, hours + j + 1) + L[i][j];


    return dp[i][hours] = max(leave , take);


}

int main ()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        memset(L , 0 , sizeof L);

        for ( int i = 0 ; i < N ; i++)
            for ( int j = 0 ; j < M ; j++)
                cin >> L[i][j];

        memset(dp , -1 , sizeof dp);

        double out = f (0, 0 , 0);

        double avg = out / N ;

        if (avg >= 5)
            cout << "Maximal possible average mark - " <<fixed << setprecision(2) << avg <<"."<< endl;
        else
            cout << "Peter, you shouldn't have played billiard that much." << endl;

    }

    return 0;

}
