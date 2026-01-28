class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a;
        int flag = 0;
        for(int i = 0; i<nums.size(); i++){
            a = target - nums[i];
            for(int j =i+1; j<nums.size();j++){
                if(nums[j]==a){
                    flag =1;
                    return {i,j};
                }
            }
            
        }
        if(flag==0){
            return {0,0};
        }
        else{return {};}
       
        
    }
};