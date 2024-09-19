class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        if(expression.length() == 0) return res;
        if(expression.length() == 1){
         res.push_back(stoi(expression));
         return res;
        }
        
        if(expression.length() == 2 && isdigit(expression[0])) {
            res.push_back(stoi(expression));
            return res;
        } 
        
        for(int i = 0; i < expression.length(); i++) {
            char curr = expression[i];
            if(isdigit(curr)) continue;
            vector<int> leftPart = diffWaysToCompute(expression.substr(0, i));
            vector<int> rightPart = diffWaysToCompute(expression.substr(i+1));
            
            for(int left: leftPart) {
                for(int right: rightPart) {
                    int computeRes = 0;
                    switch(curr) {
                        case '+':
                            computeRes = left + right;
                            break;
                        case '-':
                            computeRes = left - right;
                            break;
                        case '*':
                            computeRes = left * right;
                            break;
                    }
                    res.push_back(computeRes);
                }
            }
        
        }
        return res;
    }
};