#include <vector>
using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int xorR = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      xorR = xorR ^ nums[i];
    }
    return xorR;
  }
};