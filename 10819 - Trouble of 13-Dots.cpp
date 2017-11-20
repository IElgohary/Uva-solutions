#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <stack>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
#include <bitset>
#include <ctype.h>
#include <fstream>

/**

*/

using namespace std;

#define r(input) freopen(input,"r",stdin)
#define w(output) freopen(output,"w",stdout)
#define inputFile(input) std::ifstream infile(input)
#define outputFile(output) std::ofstream outfile; outfile.open(output);

#define FOR(i,a) for (i = 0 ; i < a ; i++ )
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

#define BitCount(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a, d) memset(a,d,sizeof(a))
#define remove(v,e) v.erase(std::find(v.begin(),v.end(),e))
#define is_in(container, element) (container.find(element) != container.end())
#define SWAP(a,b) a= a^b, b=a^b, a=a^b

#define sz size
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

#define INF 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> triple;

inline int toint(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
inline string toUpper(string s){int i = 0 ; while(s[i]){s[i] = toupper(s[i]); i++;} return s;}
inline string toLower(string s){int i = 0 ; while(s[i]){s[i] = tolower(s[i]); i++;} return s;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
template<class T> inline char toChar(T x) { ostringstream sout; sout << x; return sout.str()[0];}

int m,n; // m: total money, n: number of items
int favour[4000]; // items[i] = favour of item i
int price[4000]; // items[i] = price of item i
int memo [101][20000];

int dots(int idx , int pr) {
    if(pr > m && m < 1800) return -1000000;
    if(pr > m +200) return -1000000;
    if (idx == n) {
        if(pr > m && pr <= 2000)
            return -1000000;
        return 0;
    }
    if (memo[idx][pr] != -1) return memo[idx][pr];
    int priceSoFar = pr + price[idx];
    int take = favour[idx] + dots(idx+1,priceSoFar);
    int leave = dots(idx+1,pr);
    
    return memo[idx][pr] = max(take, leave);
}

int main() {
    inputFile("input.txt");
    outputFile("output.txt");

    while (cin >> m >> n){
       int p , f; // price and favour
       for ( int i = 0 ; i < n; i++) {
           cin >> p >> f;
           price[i] = p;
           favour[i] = f;
       }
       memset(memo, -1, sizeof memo);
       
       int result = dots(0,0);
       cout << result<<endl;
    }
    return 0;
}