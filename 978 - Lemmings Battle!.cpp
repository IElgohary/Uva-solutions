/*input
3
5 1 1
10
10
2 2 3
20
10
10
10
15
3 5 5
50
40
30
40
50
50
30
30
20
60
*/

#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stack>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>

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

inline int toint(string s){ll v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

class Compare
{
public:
	bool operator() (ii t1 , ii t2){
		return t1>t2;
	}
	
};

void printQ(priority_queue<int> pq)
{
	while(!pq.empty())
	{
		int tmp = pq.top(); pq.pop();
		cout << tmp << endl;
	}
}

priority_queue <int> blue;
priority_queue <int> green;
int n , sg ,  sb, b;

int main()
{
	cin >>n ;
	while(n--)
	{
		while(!blue.empty()) blue.pop();
		while(!green.empty()) green.pop();
		cin >> b >> sg >> sb;
		FOR(i , sg) 
		{
			int tmp;
			cin >> tmp;
			green.push(tmp);
		}
		FOR(i , sb) 
		{
			int tmp;
			cin >> tmp;
			blue.push(tmp);
		}

		int tmpg, tmpb;
		while(1)
		{
			int r = min(green.sz(), blue.sz());
			r = min (r , b);
			queue<int> qblue , qgreen;
			FOR(i , r)
			{
				tmpg = green.top(); green.pop();
				tmpb = blue.top(); blue.pop();
				int survive = tmpg - tmpb;
				if( survive < 0) qblue.push(-survive);
				else if ( survive > 0) qgreen.push(survive);
			}

			while(!qblue.empty())
			{
				int tmp = qblue.front();
				blue.push(tmp);
				qblue.pop();
			}
			while(!qgreen.empty())
			{
				int tmp = qgreen.front();
				green.push(tmp);
				qgreen.pop();
			}

			if ( green.empty() ||  blue.empty()) break;

		}
		if (!green.empty()) 
		{
			cout << "green wins"<< endl;
			printQ(green);
		}
		else if(!blue.empty())
		{
		 cout << "blue wins"<< endl;
		 printQ(blue);
		}
		else	cout << "green and blue died" << endl;

		if(n)cout <<endl;
	}
}