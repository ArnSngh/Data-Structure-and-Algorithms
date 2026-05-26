class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int greater;
        vector<int>ans;
        bool found;
        for(int i =0; i<nums.size(); i++){
            greater = -1;
            found = false;
            for(int j = i; j<nums.size();j++){
                if(nums[j]>nums[i]){
                    greater = nums[j];
                    found = true;
                    break;
                }
            }
            if(found == false){
                for(int k = 0; k<i; k++){
                    if(nums[k]>nums[i]){
                        greater = nums[k];
                        break;
                    }
                }
            }
            ans.push_back(greater);


        }
        return ans;
        
    }
};