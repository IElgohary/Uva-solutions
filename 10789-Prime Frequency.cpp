#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

bitset<10000005> b;
long long SSize;
vector<int> prime;
map<char ,int> m;
map <int , char> rm;
int T ;
int rep[62] = {0};
vector<char> nums;


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
bool isPrime(long long n)
{
    if (n <= SSize)
        return b[n];
    for ( int i = 0 ; i < prime.size() ; i++)
    {
        if ( n % prime[i] == 0)
            return false;
    }
    return true;


}

int main ()
{
    sieve(2001);
    int x = 0;
    for (int i = 0;i < 10 ; i++, x++)
        {
            m[(char)('0'+i)] = x;
            rm[x] = (char)('0'+i);
        }
    for (int i = 0;i < 26 ;i++, x++ )
    {
       m[(char)( 'A'+ i)] = x;
       rm[x] = (char)( 'A'+ i);

    }
    for (int i = 0;i < 26 ;i++ , x++)
    {
        m[(char)( 'a'+ i)] = x;
        rm[x] = (char)( 'a'+ i);
    }

    cin >> T;
    for (int k = 1;k <= T ;k++ )
    {
        nums.clear();
        for (int i = 0;i < 62 ;i++ )
        {
            rep[i] = 0;
        }
        string s;
        cin >> s;

        for (int i = 0 ; i < s.length() ; i++)
            rep[m[s[i]]]++;

        for (int i = 0 ;i < 62 ;i++ )
            if (isPrime(rep[i]))
                nums.push_back(rm[i]);

        cout << "Case "<< k<< ": ";
        for (int i = 0 ;i < nums.size() ;i++ )
        {
            cout<<nums[i];
        }
        if(nums.size() == 0)
            cout << "empty";

        cout << endl;

    }

   return 0;
}
