#include <iostream>
#include <bitset>

using namespace std;

int x[10000];
int y[10000];
bitset<100001> xS;
bitset<100001> yS;

int d_val(int a[], int l, int b)
{
    int o = 0;
    for ( int i = 0 ; i < l ; i++)
    {
        if (b == 1 )// setting x
        {
            if(xS[a[i]] == 1)
            {
                o++;
                xS[a[i]] = 0;

            }
        }
        else
        {
            if ( yS[a[i]] == 1)
            {
                o++;
                yS[a[i]] = 0;
            }
        }
    }
    return o;
}


int res(int arr[] , int l, int b)
{
    int o = 0;
    for ( int i = 0 ; i < l ; i++)
    {
        if ( b == 1)// x is less
        {
            if (yS[arr[i]] == 1)
               {
                   o++;
                   yS[arr[i]] = 0;
               }
        }
        else
        {
            if ( xS[arr[i]] == 1)
                {
                    o++;
                    xS[arr[i]] = 0;
                }
        }
    }
    return o;
}

int main()
{
    while (true )
    {
        xS.set();
        yS.set();
        int a , b;
        cin >> a >>b;

        if( a == b && a == 0)
            return 0;


        for ( int i = 0 ; i < a ; i++)
            cin >> x[i];
        for ( int i = 0 ; i < b ; i++)
            cin >> y[i];

        int dX = d_val(x , a, 1);
        int dY = d_val(y , b, 2);

        int r;
        if ( dX < dY )
            r = res(x , a, 1);
        else
            r = res( y , b, 2);

        cout << r << endl;


    }

    return 0;
}
