class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left < right) {
            right = right & (right - 1);
        }
        return left & right;
    }
};