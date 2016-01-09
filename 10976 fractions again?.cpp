/*input
3
1
4
15
92
653
589
793
2384
626
4338
3279
502
88
*/

#include <stdio.h>
#include <vector>

using namespace std;

int k;
vector<pair<int,int> > pairs;

int main()
{
	while(scanf("%d" , &k) != EOF)
	{	
		pairs.clear();
		int n = 2*k;
		for( int y = k+1  ; y <= n; y++)
		{
			if((y*k) % (y-k) == 0)
				pairs.push_back(make_pair( (y*k) / (y-k), y));
			
		}

		int ln = pairs.size();
		printf("%d\n", ln);
		for ( int i = 0 ; i < ln;i++)
		{
			printf("1/%d = 1/%d + 1/%d\n", k , pairs[i].first , pairs[i].second);
		}
	}
}

