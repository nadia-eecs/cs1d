// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
        
//     }
// };

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> psum(nums.size() + 1,0);
        vector<int> mod_p(psum.size(),0);
        vector<int> mod_counter(k,0);
        int result = 0;

        psum = prefix_sum_generator(nums);
        mod_p = mod_generator(psum, k);
        for(int i = 0; i < mod_p.size(); ++i){
            mod_counter[mod_p[i]]++;
        }
        // remove extra count for the origin that we added in psum
        mod_counter[0]--;

        result = mod_counter[0]; // zeroth remainder is special initializing to the count
        for(int i=0; i<k; i++) {
            result += (mod_counter[i]*(mod_counter[i]-1)) / 2;
        }
    
        return result;
    }

private:
    vector<int> prefix_sum_generator(vector<int>& nums){
        vector<int> prefix_sum(nums.size() + 1);
        prefix_sum.at(0) = 0;
        for(int i = 1; i < nums.size() + 1; ++i){
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        return prefix_sum;

    }

    vector<int> mod_generator(vector<int>& prefix_sum, int k){
        
        vector<int> mod_prefix(prefix_sum.size(),0);

        for(int i = 0; i < prefix_sum.size(); ++i)
        {
            mod_prefix.at(i) = prefix_sum[i]%k;
            if (mod_prefix[i] < 0) mod_prefix[i]+=k;
        }
        return mod_prefix;
    }

};

/*
int myArr[5];
myArr = 42;
*/


/*
To do: 
1. create prefix sum array array    
   - create helper function that returns a prefix sum array given the input vector nums
2. Find the modulo of each individual item in prefix sum 
   - Check if the modulo is always positive
   - Accurate modulo: (a/b)*b + a%b == a
3. Make a new array of mods found as you go through prefix sum with size k to store counts
4. Check if mod have been found, add/increment counts
    - Array for results with size k
    - Add to result
5. Return number of subarrays

*/

// cursors here 