#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int rowL [100000100] ; // coordinates of L
int colL [100000100] ; // at time i

int main()
{
    int tc;
    cin >> tc;

    while ( tc--)
    {
        int Vir, Vic;
        cin >> Vir>> Vic; // V initial location

        int Lir , Lic;
        cin >> Lir >> Lic; // L initial location

        int LS;
        cin >> LS;

        bool safe = true;

        int t = 0;
        int mx = 0;
        while( LS--)// record L position
        {

            int r, c;
            cin >> r >> c;
            mx += max(abs(c - Lic) , abs(r - Lir)); // max time

            for ( int j = t ; j< mx; j++)// position at time j
            {
                rowL[j] = Lir;
                colL[j] = Lic;

                // Move to destination
                if (Lir < r)
                    Lir++;
                else if( Lir > r)
                    Lir--;

                if (Lic < c)
                    Lic++;
                else if( Lic > c)
                    Lic--;

            }
            t = mx;
        }

        int VS;
        cin >> VS;

        t = 0;
        mx = 0;
        while ( VS--) // compare V positions with L positions
        {
            int r, c;
            cin >> r >> c;
            mx += max(abs(c - Vic) , abs(r - Vir)); // max time

            for ( int j = t ; j< mx; j++)// position at time j
            {
              if (Vir == rowL[j] && Vic == colL[j] )
              {
                  safe = false;
                  break;
              }
                // Move to destination
                if (Vir < r)
                    Vir++;
                else if( Vir > r)
                    Vir--;

                if (Vic < c)
                    Vic++;
                else if( Vic > c)
                    Vic--;
            }
            t = mx;
        }

        if ( safe )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        if ( tc )
            cout << endl;
    }
    return 0;
}
