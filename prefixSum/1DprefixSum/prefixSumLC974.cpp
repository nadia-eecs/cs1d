
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size() + 1, 0);
        vector<int> remCount(k,0);
        int prefixSumMod = 0;
        for(int i = 0; i < nums.size(); ++i){
            //count += ((i % k) + k) % k;
            prefixSum[i+1] = prefixSum[i] + nums[i];
            prefixSumMod = (prefixSum[i+1] % k + k) % k;
            ++remCount[prefixSumMod];
        }

        int numSubArrays = 0;
        numSubArrays += remCount[0];

        for (int rem = 0; rem < remCount.size(); ++rem) {
            if (remCount[rem] > 1) {
                numSubArrays += (remCount[rem]*(remCount[rem]-1))/2;

            }
        }
        return numSubArrays;
        
    }
        
};
