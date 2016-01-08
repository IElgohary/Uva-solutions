#include <iostream>

using namespace std;

int ppl[10000];
int rnk[10000] = {0};
int mny[10000];

int findset(int a )
{
    if ( ppl[a] == a)
        return a;
    return ppl[a] = findset(ppl[a]);

}

void unionF(int a , int b)
{
    int x = findset(a);
    int y = findset(b);
    if ( x != y)
    {
       if ( rnk[x] > rnk[y])
        {
            ppl[y] = x;
            mny[x] += mny[y];
            mny[y] = 0;
        }
        else if ( rnk[y] > rnk[x])
        {
            ppl[x] = y;
            mny[y] += mny [x];
            mny[x] = 0;
        }
        else
        {
            ppl[y] = x;
            rnk[x] ++;
            mny [x] += mny [y];
            mny[y] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for ( int i = 0 ; i < n ; i++)
            ppl[i] = i;

        for ( int i = 0 ; i < n ; i++)
            cin >> mny[i];

        while ( m--)
        {
            int a , b;
            cin >> a >> b;
            unionF(a , b);

        }

        bool done = true;
        for ( int i = 0 ; i < n ; i++)
        {
            if( mny[i] != 0)
            {
                done = false;
                break;
            }
        }

        if(done)
            cout << "POSSIBLE"<<endl;
        else
            cout << "IMPOSSIBLE"<<endl;


    }
    return 0;
}
