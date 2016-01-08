/*input

*/

#include <iostream>
#include <math.h>
#include <algorithm>
#include <utility>
using namespace std;



int n , l , w;
pair<int , int> arr[10000];

int main()
{
	ios::sync_with_stdio(false);
	while(cin >> n >> l >> w)
	{
		for ( int i = 0 ; i < n ; i++)
		{
			int pos , r;
			cin >> pos >> r;
			int dx = sqrt(r*r - (w/2)*(w/2));
			arr[i].first = pos - dx;
			arr[i].second = pos + dx;
		}

		sort(arr, arr+n);

		
	}

}