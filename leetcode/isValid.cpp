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


class Solution {
public:
    bool isValid(string s) {
        string left =  "({[";
        string right = ")}]";
        stack<char> operators;
        for(int i=0; i<s.length(); ++i) {
            if(left.find(s[i]) != string::npos)
                operators.push(s[i]);
            else {
                if(operators.empty() || operators.top() != left[right.find(s[i])])
                    return false;
                else
                    operators.pop();
            }
        }
        return operators.empty();
    }
};
