class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,h=height.size()-1;
        int area=1;
        int maxarea=-1;
        while(l<h)
        {
            area=(h-l)*(min(height[l],height[h]));
            maxarea=max(maxarea, area);
            if(height[l]<height[h])
            {
                l++;
            }
            else{
                h--;
            }
        }
        return maxarea;
    }
};