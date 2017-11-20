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
10 2 
1
2
3
4
5
6
7
8
9 
10 
5 1 
5 2 
5 1 
2
3
4
5
6 
6 2 
0 0
*/

using namespace std;

#define r(input) freopen(input,"r",stdin)
#define w(output) freopen(output,"w",stdout)

#define FOR(a) for ( int i = 0 ; i < a ; i++ )
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

int m,n,q,d,set_num;
int numbers[200];
ll memo [200][20][11];

int compute(int i, int m, int sum) {
    if (m == 0) {
        return (sum%d == 0);
    }
    int modulo = ((sum%d)+d) % d;
    if (i == n ) return 0;
    if (memo[i][modulo][m] != -1) return memo[i][modulo][m];

    int take = compute(i+1,m-1, sum + numbers[i]);
    int leave = compute(i+1, m, sum);
   
    return memo[i][modulo][m] = take + leave;
}

int main() {
    set_num = 1;
    // std::ifstream infile("input.txt");
    // ofstream outfile;
    // outfile.open ("output.txt");
    
    
    while (1) {
        // infile>> n >>q;
        cin>> n >>q;
        if (n == 0 && q == 0) break;
        
        for ( int i = 0 ; i < n ; i++) {
            // infile >> numbers[i];
            cin >> numbers[i];
        }

       
        
        // outfile<< "SET " +toString(set_num) +":\n";
        cout<< "SET " +toString(set_num) +":\n";
        set_num++;
        for (int t = 0 ; t < q; t++) {
            
            // infile >> d>> m;
            for(int k = 0 ; k < 200; k++) {
                for ( int i = 0 ; i < 20; i++) {
                    for ( int j = 0 ; j < 11; j++) {
                        memo[k][i][j] = -1;
                    }
                }
            }
           
            cin >> d>> m;
            int result = compute(0, m, 0);
            // outfile<< "QUERY " + toString(t+1)+ ": "+ toString(result)+ "\n";
            cout<< "QUERY " + toString(t+1)+ ": "+ toString(result)+ "\n";
        }
    }    
    // outfile.close();
    return 0;
}