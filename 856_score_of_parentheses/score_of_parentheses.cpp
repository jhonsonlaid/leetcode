class Solution{
public:
    int scoreOfParentheses(string S){
        stack<int> res;
        int n = S.size();
        // -1 for '(' 
        for(int i = 0; i < n; i++){
            if(S[i] == '('){
                res.push(-1);
            }
            else if(S[i] == ')'){
                int new_score = 0;
                if (res.top() == -1){
                    res.pop();
                    new_score = 1;
                }
                else{
                    while(!res.empty() && res.top() > 0){
                        new_score += res.top();
                        res.pop();
                    }
                    res.pop(); // pop '('
                    new_score *= 2;
                    
                }
                res.push(new_score);
            }
        }
        int score = 0;
        while(!res.empty()){
            score += res.top();
            res.pop();
        }
        return score;
    }
};
