class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize the overall maximum sum found so far
        int max_so_far = nums[0];
        
        // Initialize the maximum sum of a subarray ending at the current position
        int max_ending_here = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Determine if the current element starts a new, better subarray
            // or extends the existing one.
            max_ending_here = max(nums[i], max_ending_here + nums[i]);

            // Update the overall maximum sum.
            max_so_far = max(max_so_far, max_ending_here);
        }

        return max_so_far;
    }
};