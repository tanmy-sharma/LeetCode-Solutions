class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0, numZeros = 0, max_len = INT_MIN, len = nums.size();
        while(end < len){
            if(nums[end] == 0) ++numZeros;
            end++;
            if(numZeros > 1){
                if(nums[start] == 0) --numZeros;
                ++start;
            }
            max_len = max(max_len, end - start);
        }
        return max_len - 1;
    }
};
