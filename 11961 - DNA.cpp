/*input
1
3 1
AAA
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

int t , n , k;
set<string> st;
string a;

void genseq(string s , int num, int ind)
{
	if (num > k ) return;
	if (ind == n )
	{
		st.insert(s);
		return;
	}
	genseq(s+'A', (a[ind] == 'A')? num: num+1, ind+1);
	genseq(s+'C', (a[ind] == 'C')? num: num+1, ind+1);
	genseq(s+'G', (a[ind] == 'G')? num: num+1, ind+1);
	genseq(s+'T', (a[ind] == 'T')? num: num+1, ind+1);
}

int main()
{
	cin >> t;
	while ( t--)
	{
		st.clear();
		cin >> n >> k >> a;
		genseq("" , 0, 0);
		cout << st.size()<< endl;
		FOREACH(st){
			cout<<*it<<endl;
		}
	}
}