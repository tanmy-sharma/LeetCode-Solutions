class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size(), max_ans = INT_MIN, j = 0, numZeros = 0;
        for(int i = 0 ; i < len ; i++){
            if(nums[i] == 0){
                numZeros++;
            }
            if(numZeros > k){
                if(nums[j] == 0){
                    numZeros--;
                }
                j++;
            }
            max_ans = max(max_ans, i - j + 1);
        }
        return max_ans;
    }
};
