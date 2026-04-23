class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int k=2;
        int i=0;
        if(n<3){
            return 0;
        }
        int dif=nums[1]-nums[0];
        int cnt=0;
        while(k<n){
            if(nums[k]-nums[k-1]==dif){
                cnt=cnt+(k-i-1);
                k++;
            }
            else{
                dif=nums[k]-nums[k-1];
                i=k-1;
                k++;
            }
        }
        return cnt;
    }
};