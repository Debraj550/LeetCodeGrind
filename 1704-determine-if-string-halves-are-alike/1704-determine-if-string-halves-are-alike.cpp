class Solution {
public:
    bool isVowel(char x) {
       if (x == 'a' || x == 'e' || x == 'i' ||
        x == 'o' || x == 'u' || x == 'A' ||
        x == 'E' || x == 'I' || x == 'O' || x == 'U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        string a = s.substr(0, n/2), b = s.substr(n/2);
        int countA = 0,  countB = 0;
        
        for(auto x: a){
            if(isVowel(x)) countA++;
        }
        for(auto x: b) {
            if(isVowel(x)) countB++;
        }
        return countA==countB;
    }
};