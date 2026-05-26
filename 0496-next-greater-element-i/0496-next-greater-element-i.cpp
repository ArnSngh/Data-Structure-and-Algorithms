
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        bool found = false;
        int greater;

        for(int i = 0; i < nums1.size(); i++) {

            greater = -1;
            found = false;

            for(int j = 0; j < nums2.size(); j++) {

                if(nums1[i] == nums2[j]) {
                    found = true;
                }

                if(found == true && nums2[j] > nums1[i]) {
                    greater = nums2[j];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};