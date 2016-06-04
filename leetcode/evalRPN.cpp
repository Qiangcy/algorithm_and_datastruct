class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> nums;
            for(int i=0; i<tokens.size(); ++i) {
                if(!is_operator(tokens[i])) {
                    nums.push(stoi(tokens[i]));
                }else {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    switch(tokens[i][0]) {
                        case '+': a += b; break;
                        case '-': a -= b; break;
                        case '*': a *= b; break;
                        case '/': a /= b; break;
                    }
                    nums.push(a);
                }
            }
            return nums.top();
        }
    private:
        bool is_operator(const string &op) {
            return (op.size()==1) && string("+-*/").find(op)!=string::npos;
        }
};
