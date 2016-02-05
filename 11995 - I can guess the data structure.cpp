/*input
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
typedef pair<int,ii> iii;

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

queue<int> qu;
stack<int> st;
priority_queue<int> pqu;
bool q , s, pq;
int n;

int main()
{
	while(cin >> n)
	{
		while(!qu.empty()) qu.pop();
		while(!st.empty()) st.pop();
		while(!pqu.empty()) pqu.pop();
		q = s = pq = true;

		FOR(i, n)
		{
			int in;
			int x;
			cin >> in >> x;
			if ( in == 1)
			{
				st.push(x);
				qu.push(x);
				pqu.push(x);
			}
			else
			{
				if(!st.empty() && st.top() != x) {s = false;}
				else if(st.empty()) s = false;

				if(!qu.empty() && qu.front() != x) {q = false;}
				else if ( qu.empty()) q = false;

				if(!pqu.empty() && pqu.top() != x) {pq = false;}
				else if ( pqu.empty()) pq = false;

				if(!st.empty())  st.pop();
				if(!qu.empty())  qu.pop();
				if(!pqu.empty())  pqu.pop();

			}
		}

		int cnt = 0;
		if(s) cnt++;
		if(q) cnt++;
		if(pq) cnt++;

		if( cnt > 1) cout << "not sure"<<endl;
		else if( cnt == 0) cout << "impossible" << endl;
		else if(s) cout <<"stack"<< endl;
		else if(q) cout << "queue"<< endl;
		else if (pq) cout << "priority queue" << endl;
	}	
	
}