#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;


int mx = 0;

void connect(int n, int x )
{
    if ( x > mx)
        mx = x;

    if ( n == 1)
        return;

   if ( n % 2 != 0)
   {
       //g.arr[n-1].push_back((3*n)-1);
       connect((3*n)+1 , x+1);
   }else
   {
       //g.arr[n-1].push_back(n/2);
       connect(n/2 , x+1);
   }

}

int main()
{
    string l ;
    while(getline(cin , l) && l.length()> 0)
    {
        int a , b ;
        istringstream os(l);
        os >> a >>b;

        int tmp = 0;
        int m , n;
        if (b < a)
        {
            m = b ;
            n = a ;
        }
        else
        {
            m = a;
            n = b;
        }
        mx = 0;
        for ( int i = m ; i <= n ; i++)
           connect(i , 1);

        cout <<a << " " << b << " "<< mx<< endl;
    }
}
