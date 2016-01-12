/*input
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
abc]def[gsd]back[front]back3
*/


#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <deque>
#include <string.h>
#include <stack>

using namespace std;


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )


typedef long long ll;
typedef std::pair<int,int> ii;

int main()
{
	string s;
	deque<char> t;
	stack<char> front;

	while ( cin >> s)
	{
		for ( int i = 0 ; i < s.size(); i++)
		{
			if(s[i] == '[')
			{	i++;
				for(;s[i] != '[' && s[i] != ']' && i < s.size(); i++)
					front.push(s[i]);

				while(!front.empty())
				{
					t.push_front(front.top());
					front.pop();
				}
				if(s[i] == '[')
					i--;
			}
			else if(s[i] == ']')
				continue;
			else
			{
				t.push_back(s[i]);
			}

		}
	
		while(!t.empty())
		{	
			cout << t.front();
			t.pop_front();
		}
		cout << endl;
	}
}