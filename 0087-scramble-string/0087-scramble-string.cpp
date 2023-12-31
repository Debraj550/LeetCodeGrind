class Solution {
        bool DP_helper(unordered_map<string, bool> &isScramblePair, string s1, string s2)
        {
            int i, len = s1.size();
            bool res = false;
            if(len == 0) return true;
            else if(len == 1) return s1 == s2;
            else
            {
                if(isScramblePair.count(s1+s2)) return isScramblePair[s1+s2]; 
                if(s1==s2) res=true;
                else{
                    for(i=1; i<len && !res; ++i)
                    {

                        res = res || 
                            (DP_helper(isScramblePair, s1.substr(0,i), s2.substr(0,i)) && 
                             DP_helper(isScramblePair, s1.substr(i,len-i), s2.substr(i,len-i)));

                       res = res || 
                           (DP_helper(isScramblePair, s1.substr(0,i), s2.substr(len-i,i)) && 
                            DP_helper(isScramblePair, s1.substr(i,len-i), s2.substr(0,len-i)));
                    }
                }
                return isScramblePair[s1+s2]= res; //save the intermediate results
                
            }
        }
    public:
        bool isScramble(string s1, string s2) {
           unordered_map<string, bool> isScramblePair;
           return DP_helper(isScramblePair, s1, s2);
        }
    };