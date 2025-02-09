#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int longestSubarrayWithSumK(vector<int> &nums, int K)
  {
    unordered_map<int, int> prefixSumMap; // To store (prefixSum, index)
    int prefixSum = 0, maxLength = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      // Add current number to the running prefix sum
      prefixSum += nums[i];

      // Check if the entire array from 0 to i adds up to K
      if (prefixSum == K)
      {
        maxLength = i + 1; // Update maxLength
      }

      // Check if (prefixSum - K) exists in the map
      if (prefixSumMap.find(prefixSum - K) != prefixSumMap.end())
      {
        // Calculate the length of the subarray
        maxLength = max(maxLength, i - prefixSumMap[prefixSum - K]);
      }

      // Store the current prefix sum in the map if it doesn't exist
      if (prefixSumMap.find(prefixSum) == prefixSumMap.end())
      {
        prefixSumMap[prefixSum] = i;
      }
    }

    return maxLength;
  }
};
