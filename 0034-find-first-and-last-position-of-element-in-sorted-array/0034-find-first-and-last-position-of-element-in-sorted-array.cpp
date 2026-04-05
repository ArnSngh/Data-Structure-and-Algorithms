class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fres = -1;
        int low = 0 , high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                fres = mid;
                high = mid-1;
            }
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        int lres = -1;
        low = 0 , high= nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                lres = mid;
                low = mid+1;
            }
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return {fres,lres};
    }
};