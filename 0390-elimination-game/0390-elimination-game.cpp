class Solution {
public:
    bool changeBothPtr(int& left, int& right, int& step) {
        return !((right - left) % step);
    }

    int lastRemaining(int n) {
        int left = 1, right = n, step = 2, pos = 0;

        while (left < right) {
            if (changeBothPtr(left, right, step)) {
                left+= (step / 2);
                right-= (step / 2);
            }
            else {
                if (pos) right-= (step / 2);
                else left+= (step / 2);
            }
            pos = 1 - pos;
            step*= 2;
        }
        return left;
    }
};