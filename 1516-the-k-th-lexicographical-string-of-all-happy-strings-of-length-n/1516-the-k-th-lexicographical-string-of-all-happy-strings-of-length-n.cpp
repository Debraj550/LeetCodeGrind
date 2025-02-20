class Solution {
public:
    void backtrack(string &pattern, int n, string &happy, vector<string> &listOfHappyStrings) {
        if(happy.size() >= n) {
            listOfHappyStrings.push_back(happy);
            return;
        }
        for(int i = 0; i < pattern.size(); i++) {
            if(happy.size() == 0 || happy[happy.size()-1] != pattern[i]) {
                happy.push_back(pattern[i]);
                backtrack(pattern, n, happy, listOfHappyStrings);
                happy.pop_back();
            }
           else continue;
        }
    }
    string getHappyString(int n, int k) {
        string pattern = "abc";
        vector<string> listOfHappyStrings;
        string temp = "";
        backtrack(pattern, n, temp, listOfHappyStrings);
        if (k > listOfHappyStrings.size()) return "";
        return listOfHappyStrings[k - 1]; 

    }
};