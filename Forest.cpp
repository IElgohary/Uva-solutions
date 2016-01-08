#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

int ppl[100];
int opn;
int rnk[100];
bool op[100][100];

int findset(int a)
{
    if ( ppl[a] == a)
        return a;
    return ppl[a] = findset(ppl[a]);

}

void unionF(int a , int b)
{
    int x = findset(a);
    int y = findset(b);

    if ( y != x )
    {
        opn--;
        if ( rnk[x] > rnk[y])
        {
            ppl[y] = x;

        }
        else if ( rnk[y] > rnk[x])
        {
            ppl[x] = y;

        }
        else
        {
            ppl[y] = x;
            rnk[x] ++;
        }
    }

}

bool same ( int i , int j, int t)
{
    for ( int k = 0 ; k < t ; k++)
    {
        if ( op[i][k] != op[j][k])
            return false;
    }
    return true;

}

int main()
{
    int tc;
    cin >> tc;

    while ( tc--)
    {

        int p , t;
        cin >> p >> t;

        for ( int i = 0 ; i < p ; i++)
            ppl[i]=i;
        opn = p;
        memset(op , false, sizeof(op));

        string l;
        cin.ignore(10000,'\n');
        while (getline(cin, l) && l.length() > 0) {

            int i, j;
            istringstream strm(l);
            strm >> i >> j;
            op[i-1][j-1] = true;
        }

        for ( int i = 0 ; i < p ; i++)
        {
            for ( int j = i+1 ; j < p ; j++)
            {
                if ( same (i , j, t))
                {
                    unionF(i , j);
                }

            }
        }

        if ( tc > 0)
            cout << opn << "\n"<< endl;
        else
            cout<< opn << "\n";
    }


    return 0;
}
