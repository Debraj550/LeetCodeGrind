/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int n = a.length();
        //find pivot
        int l = 0, r = n - 1;
        while(l <= r) {
            int m = (l + r)/2;
            int val = a.get(m);
            if(val < a.get(m+1)) 
                l = m + 1;
            else 
                r = m-1;
        }
        int piv = l;

        //find element in left 
        l = 0, r = piv;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a.get(m) == target) return m;
            if(a.get(m) > target) r = m - 1;
            else l = m + 1;
        }
        
        //find element in right
         l = piv+1, r = n - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a.get(m) == target) return m;
            if(a.get(m) > target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};