#include <iostream>
#include <map>
using namespace std;

int crt[5000];
int rel[5000];
int rnk[5000] = {0};

int findset ( int a)
{
    if (crt[a] == a )
        return a;
    return crt[a] = findset(crt[a]);
}

void unionF(int a , int b)
{
    int x = findset(a);
    int y = findset(b);
    if ( x != y)
    {
        if ( rnk[x] > rnk[y])
        {
            crt[y] = x;
            rel[x] += rel[y];
        }
        else if (rnk[x] < rnk [y])
        {
            crt[x] = y;
            rel[y] += rel[x];
        }
        else
        {
            crt[y] = x;
            rnk[x]++;
            rel[x] += rel[y];
        }

    }


}


int main()
{
    while (true)
    {
        int c , r;
        cin >>c >> r;
        if ( c == r && r == 0)
            break;

        map < string , int> mp;

        for ( int i = 0 ; i < c ; i++)
            crt[i] = i;

        for ( int i = 0 ; i < c ; i++)
            rel[i] = 1;

        for ( int i = 0 ; i < c ; i++)
        {
            string s;
            cin >> s;
            mp[s] = i;
        }

        for ( int i = 0 ; i < r ; i++)
        {
            string s1 , s2;
            cin >> s1 >> s2;
            unionF(mp[s1] , mp[s2]);
        }

        int mx = rel[0];
        int cnt= 0;
        for ( int i = 1 ; i < c ; i++)
        {
            if ( mx < rel[i])
            {

                mx = rel[i];
                cnt = i;
            }

        }

        cout << rel[cnt]<< endl;


    }



return 0;
}
