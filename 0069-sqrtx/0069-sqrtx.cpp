class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        int low = 1;
        int high = x;
        int sqrt = INT_MIN;
        while( low <= high){
            int mid = low + ( high - low ) / 2;
            if( mid <= x / mid ){
                sqrt = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return sqrt;  
    }
};