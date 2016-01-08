/*input
3 3
1 1 1
1 2 1
2 3 2
3 1 3
3 3
1 1 1
1 2 1
2 3 2
3 1 4
3 3
1 1 1
1 2 2
2 3 2 
3 1 2 
0 0
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int B , N;
	int arr[25];
	while ( true)
	{
		cin >> B >> N;
		if ( B == N && N ==0)
			break;
		for( int i = 0 ; i < B ; i++)
			cin >> arr[i];

		for ( int i = 0 ; i < N ; i++)
		{
			int D , C , V;
			cin >> D >> C >> V;
			arr[D-1] -= V;
			arr[C-1] += V;
		}

		bool S = true;
		for (int i = 0 ; i < B ; i++ )
		{	
			if ( arr[i] < 0) 
			{
				S = false; 
				break;
			}
		}
		if ( S)	cout << "S"<< endl;
		else cout << "N"<< endl;

	}
}