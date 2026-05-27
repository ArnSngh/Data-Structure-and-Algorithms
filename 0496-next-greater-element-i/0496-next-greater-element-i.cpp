class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {

            stack<int> st;
            bool found = false;

            // traverse nums2 from right to left
            for (int j = nums2.size() - 1; j >= 0; j--) {

                while (!st.empty() && st.top() <= nums2[j]) {
                    st.pop();
                }

                // when nums1[i] found in nums2
                if (nums2[j] == nums1[i]) {
                    found = true;

                    if (st.empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(st.top());
                    }

                    break;
                }

                st.push(nums2[j]);
            }
        }

        return ans;
    }
};