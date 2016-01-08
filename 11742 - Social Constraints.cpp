/*input
8 16
0 3 -6
5 6 -4
2 7 -2
3 6 1
0 3 -7
3 7 2
3 4 2
0 6 2
0 1 -7
1 2 -2
2 3 3
0 3 -6
0 0
*/
#include <bits/stdc++.h>
using namespace std;
int p[8] = {0,1,2,3,4,5,6,7};
int con[20][3];
int n , m;
int cnt = 0;
bool sit;

int find(int e)
{
	for (int i = 0 ; i < n;i++)
		if (e == p[i])
			return i;
	
}


int main()
{
	while(true)
	{
		cnt = 0;
		cin>> n >>m;
		if(m == n && n == 0)
			break;

		for(int i = 0 ; i <m ;i++)
			cin >> con[i][0]>> con[i][1]>>con[i][2];
		do
		{
			sit = true;
			for(int i = 0 ; i < m;i++)
			{
				int posA = find(con[i][0]);
				//cout << "A"<<posA<<endl;
				int posB = find(con[i][1]);
				//cout << "B" <<posB <<endl;

				if (con[i][2] > 0)
				{	
					//cout << "done"<< endl;
					if(abs(posA - posB) > con[i][2])
						{
							sit = false;
							//cout << "count"<< cnt<<endl;
						}
				}		
				else if(abs(posA - posB) < (-con[i][2]))
				{
					sit = false;
					//cout << "count"<< cnt<<endl;
				}
			}
			if (sit) cnt++;

		}while(next_permutation(p,p+n));

		cout << cnt<<endl;

	}
}