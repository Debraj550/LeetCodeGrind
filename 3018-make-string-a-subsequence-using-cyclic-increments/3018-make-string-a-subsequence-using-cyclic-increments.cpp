class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;

        while(i < str1.size() && j < str2.size()) {
            int str1ch = str1[i];
            int str2ch = str2[j];
            if(str1ch == str2ch || str1ch + 1 == str2ch || str1ch - 25 == str2ch) {
                j++;
            }
            i++;
        }

        if(j == str2.size()) return true;
        return false;
    }
};