#include <iostream>
#include <cmath>
#include <map>
#include <sstream>
#include <cstdlib>

using namespace std;

unsigned long long number(unsigned long long k , unsigned long long n)
{
    stringstream stream;
    string s;
    stream<<k;
    s = stream.str().substr(0,n);
    return strtoull(&s[0] ,NULL, 10);
}

int main()
{
    int TC;
    cin>> TC;

    while (TC--)
    {
        map <unsigned long long , bool> m;
        unsigned long long n, Max;
        unsigned long long k;
        cin>>n >>k;
        Max = k;

        while ( !m[k])
        {
            m[k] = true;
            k *= k;

            k = number(k , n);

            Max= (Max < k) ? k: Max;
        }

        cout<< Max <<endl;

    }
    return 0;
}
