#include <iostream>
#include <map>

using namespace std;

int ppl[200000];
int frn[200000] ;
int rnk[200000] = {0};

int findset(int a )
{
    if ( ppl[a] == a)
        return a;
    return ppl[a] = findset(ppl[a]);

}

int unionF(int a , int b)
{
    int n;
    int x = findset(a);
    int y = findset(b);

    if ( x != y)
    {
       if ( rnk[x] > rnk[y])
        {
            ppl[y] = x;
            frn[x]+= frn[y];
            n = frn[x];

        }
        else if ( rnk[y] > rnk[x])
        {
            ppl[x] = y;
            frn[y]+= frn[x];
            n = frn[y];
        }
        else
        {
            ppl[y] = x;
            rnk[x] ++;
            frn[x]+= frn[y];
            n = frn[x];

        }
    }
    return frn[findset(x)];
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        map<string, int> mp;
        int f;
        cin >> f;
        int x = 0;

        for ( int i = 0 ; i <= 2*f ; i++)
            ppl[i] = i;

        for ( int i = 0 ; i <= 2*f ; i++)
            frn[i] = 1;

        while ( f--)
        {
            string s1;
            string s2;

            cin >> s1 >> s2;

            if ( mp.count(s1) == 0)
                {
                    mp[s1] =  x;
                    x++;
                }
            if ( mp.count(s2) == 0)
                {
                    mp[s2] = x;
                    x++;
                }


            cout<<unionF(mp[s1] , mp[s2])<< endl;

        }

    }
    return 0;
}
