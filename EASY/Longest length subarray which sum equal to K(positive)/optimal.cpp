#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int longestSubarrayWithSumK(vector<int> &nums, int K)
  {
    int start = 0, currentSum = 0, maxLength = 0;

    for (int end = 0; end < nums.size(); end++)
    {
      // Add the current number to the sum
      currentSum += nums[end];

      // Shrink the window from the left if the sum exceeds K
      while (currentSum > K)
      {
        currentSum -= nums[start];
        start++;
      }

      // If the sum equals K, update the maximum length
      if (currentSum == K)
      {
        maxLength = max(maxLength, end - start + 1);
      }
    }

    return maxLength; // Return the length of the longest subarray
  }
};
