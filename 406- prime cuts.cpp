#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

bitset<10000005> b;
long long SSize;
vector<int> prime;
int N , C;

void sieve(long long upper)
{
    SSize = upper;
    b.set();
    b[0]=b[1]= 0;
    for (long long i = 2 ; i <= SSize ;i++ )
    {
        if(b[i])
        {
            for ( long long j = i * i ; j <= SSize ; j+= i)
                b[j] = 0;
            prime.push_back((int)i);
        }
    }

}

int main ()
{
    prime.clear();
    while ( cin>>N>>C)
    {
        prime.clear();
        prime.push_back(1);
        sieve(N);
        int bgn;
        int nC;

        if ( prime.size() % 2 == 0)
        {
            bgn = (prime.size()/2) - C;
            nC = C*2;
        }
        else
        {
            bgn = (prime.size()/2) - C +1;
            nC = (C*2) - 1;
        }

        if ( nC > prime.size())
        {
            nC = prime.size();
            bgn = 0;
        }

        cout << N << " "<< C<<":";
        for ( int i = bgn ; i < nC + bgn ; i++)
        {
            cout << " " << prime[i];
        }
        cout << endl;
        cout << endl;

    }

   return 0;
}
