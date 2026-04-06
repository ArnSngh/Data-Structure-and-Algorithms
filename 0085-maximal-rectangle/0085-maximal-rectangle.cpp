class Solution {
public:
    
    int largestRectangle(vector<int>& heights){
        int n = heights.size();
        
        vector<int> nsl(n), nsr(n);
        stack<int> st;
        
        // NSL
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.empty()) nsl[i] = -1;
            else nsl[i] = st.top();
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // NSR
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.empty()) nsr[i] = n;
            else nsr[i] = st.top();
            
            st.push(i);
        }
        
        int maxArea = 0;
        
        for(int i=0;i<n;i++){
            int width = nsr[i] - nsl[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea,area);
        }
        
        return maxArea;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> heights(n,0);
        int ans = 0;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    heights[j]+=1;
                else
                    heights[j]=0;
            }
            
            ans = max(ans,largestRectangle(heights));
        }
        
        return ans;
    }
};