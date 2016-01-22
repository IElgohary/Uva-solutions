/*input
vwxyz
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

using namespace std;


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()

typedef long long ll;
typedef std::pair<int,int> ii;


map<string,int> mp;
int ind = 0;
void gen(string s, int lim, int cnt)
{
	if(cnt > lim) return;
	if(cnt == lim) 
	{	
		mp[s] = ++ind;
		return;
	}

	int i;
	if(s.size()== 0) 
		i = 0;
	else
		i = (int) s[s.sz()-1] - 'a' + 1;

	for ( ;i < 26; ++i)
	{
		gen(s+(char)('a'+i), lim, cnt+1);
	}

}

int main()
{
	// map<string,int> mp;
	// mp.clear();
	// int ind =1;
	// string s = "a";
	// for ( int i = 1;i <= 26;i++)
	// {
	// 	mp[s] = ind;
	// 	ind++;
	// 	s[0] ++;
	// }

	// s = "ab";
	// for (int i = 1; i <= 25;i++)
	// {
	// 	s[1] = s[0] + 1;
	// 	for (int j = i+1; j <= 26; j++)
	// 	{
	// 		mp[s] = ind;
	// 		//if ( s == "bc")
	// 		//	cout << s << " "<< ind<<" "<<mp[s] <<endl;
	// 		ind++;
	// 		s[1]++;
	// 	}
	// 	s[0]++;
	// 	//if ( i == 1) cout << s << endl;
	// }

	// s = "abc";
	// for ( int i = 1 ; i<= 24 ; i++)
	// {
	// 	s[1] = s[0] + 1;
		
	// 	for ( int j = i+1 ; j <= 25 ; j++)
	// 	{
	// 		s[2] = s[1]+ 1;
	// 		for ( int k = j+1 ; k <= 26 ; k++)
	// 		{
				
	// 			mp[s] = ind;
	// 			ind++;
	// 			s[2] ++;

	// 		}
	// 		s[1] ++;
	// 	}
	// 	s[0] ++;
	// }
	// //cout << ind << endl;
	// s = "abcd";
	// for ( int i = 0 ; i < 24; i++)
	// {
	// 	s[1] = s[0] + 1;
		
	// 	for (int j = i + 1 ; j < 25; j++)
	// 	{
	// 		s[2]= s[1] +1;
	// 		for ( int k = j+1 ; k < 26 ; k++)
	// 		{
	// 			s[3]= s[2] +1;		
	// 			for ( int l = k + 1 ; l <27 ; l++)
	// 			{
	// 				mp[s] = ind;
	// 				ind++;
	// 				s[3] ++;
	// 			}
	// 			s[2] ++;
	// 		}

	// 		s[1] ++;
	// 	}
	// 	s[0] ++;
	// }

	// s = "abcde";
	// for ( int e = 0 ; e < 23 ; e++)
	// {
	// 	s[1]= s[0] + 1;	
		
	// 	for ( int i = e + 1 ; i < 24; i++)
	// 	{
	// 		s[2] = s[1] + 1;
	// 		for (int j = i + 1; j < 25; j++)
	// 		{
	// 			s[3] = s[2] + 1;
	// 			for ( int k = j + 1 ; k < 26 ; k++)
	// 			{
	// 				s[4]= s[3] + 1;
	// 				for ( int l = k + 1 ; l < 27 ; l++)
	// 				{
	// 					mp[s] = ind;
	// 					ind++;
	// 					s[4] ++;
	// 				}
	// 				s[3] ++;
	// 			}

	// 			s[2] ++;
	// 		}
	// 		s[1] ++;
	// 	}
	// 	s[0] ++;
	// }

	for ( int i = 1; i < 6 ; i++)
	{
		gen("",i, 0);
	}

	string in;
	while ( cin >> in)
	{
		if ( mp.count(in))
		{
			//cout << "ab: "<< mp["ab"] << endl;
			cout << mp[in] << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}

	
}
