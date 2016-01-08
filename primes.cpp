#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll>  vll;
typedef vector<int> vi;
#define F(a,n) for ( ll i = a ; i < n ; i++)
#define FE(a,n) for ( ll i = a ; i <= n ; i++)
#define Pb(n) push_back(n)
#define SZ size();

bool isPrime(ll n)
{
    if ( n == 1 || n == 0)
        return false;
    ll root = sqrt(n);
    FE(2,root)
    {
        if ( n%i == 0)
            return false;
    }

    return true;
}



int main()
{

    cin >> TC;

    while(TC--)
    {
        cin >> m >> n;

        ll a = 0;
        while ( prime[a] < m)
            a++;

        F(a , a+(n-m))
        {
            if (prime[i] > n)
                break;
            cout << prime[i] << endl;
        }

        if ( TC > 0)
            cout << endl;

    }

    return 0;
}
