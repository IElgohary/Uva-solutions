/*input
0 Fuel consumption 10
50 Gas station
50 Fuel consumption 20
100 Goal
0 Fuel consumption 20
50 Gas station
50 Fuel consumption 10
100 Goal
*/

#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <cstring>
#include <stack>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
#include <bitset>

using namespace std;

#define r(input) freopen("input.txt","r",stdin)
#define w(output) freopen("output.txt","w",stdout)

#define FOR(i, a) for ( int i = 0 ; i < a ; i++ )
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

#define VISITED 1
#define UNVISITED 0
#define INF 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> triple;

inline int toint(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
template<class T> inline char toChar(T x) { ostringstream sout; sout << x; return sout.str()[0];}


class Compare
{
public:
	bool operator() (ii t1 , ii t2){
		return t1>t2;
	}
	
};



int main()
{
	string line;
	while (getline(cin, line))
	{
		if(line == "0 Fuel consumption 0")break;
		
		double curr = 0.0, tank = 0.0;
		int dist = 0, consumption = 0, leak = 0;;
		do
		{
			istringstream sin(line);
			int n , c;
			string s,trash;
			sin >> n >> s;
			if(s == "Fuel" || s == "Gas") sin>>trash;
			sin >> c;

			curr += leak * (n-dist);
			curr += (consumption/100.0) * (n - dist);
			tank = max(curr, tank);

			//cout << dist << " "<< tank<<" " <<n<< endl;
			if ( s == "Goal") break;
			if ( s == "Fuel") consumption = c;
			else if ( s == "Leak") leak++;
			else if (s[0] == 'M') leak = 0;
			else if (s == "Gas") curr = 0.0;
			dist = n;

		}while(getline(cin, line));

		cout << fixed << setprecision(3) << tank<< endl;
		

	}
}