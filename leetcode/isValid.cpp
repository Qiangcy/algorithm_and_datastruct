class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return false;
        stack<char> operators;
        if(s[0]!='(' && s[0]!='{' && s[0]!='[')
            return false;
        else
            operators.push(s[0]);

        char tmp = ' ';
        for(int i=1; i<s.length(); ++i) {
            if(operators.empty())
                tmp = ' ';
            else
                tmp = operators.top();
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                operators.push(s[i]);
            else if(s[i]==')' && tmp!='(')
                return false;
            else if(s[i]=='}' && tmp!='{')
                return false;
            else if(s[i]==']' && tmp!='[')
                return false;
            else
                operators.pop();
        }
        return operators.empty();
    }
};
