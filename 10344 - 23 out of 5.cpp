#include <iostream>
#include <algorithm>

using namespace std;
int nums[5];
bool b;

bool p(int sum, int n )
{
    if (n == 5 )
        return sum == 23;
    return p(sum + nums[n], n +1  ) || p(sum - nums[n], n +1 )
                || p(sum * nums[n], n +1 );
}

int main()
{
    while(true)
    {
        for (int i = 0 ; i < 5 ; i++)
                cin >> nums[i];

        if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0 && nums[3] == 0 && nums[4] == 0 )
            break;

        sort(nums, nums+5);
        b = false;
        do
        {
            if(p(nums[0] ,1))
            {
                b = true;
                break;
            }

        }while(next_permutation(nums, nums+5));

        if (b)
            cout <<"Possible" << endl;
        else
            cout << "Impossible"<< endl;
    }
    return 0;
}
