class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        double max_sum = accumulate(nums.begin(), nums.begin() + k, 0), curr_sum = max_sum;
        for(int i = k; i < len; i++){
            curr_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum/k;
    }
};
