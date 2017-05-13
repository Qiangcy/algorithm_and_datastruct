class Solution {
public:
    string generate_number(long long int num) {
        vector<int> res;
        while(num) {
            /* cout<<"push "<<num%10<<" "; */
            res.push_back(num%10);
            num /= 10;
        }
        /* cout<<endl; */
        int cnt = 1;
        string sum;
        for(auto it=res.rbegin(); it != res.rend(); ++it) {
            /* cout<<"now it is "<<*it<<" "; */
            if(it+1!=res.rend() && *it == *(it+1)) {
                cnt++;
            }else {
                sum += to_string(cnt)+to_string(*it);
                cout<<"sum is "<<sum<<endl;
                cnt = 1;
            }
        }
        return sum;
    }
    string countAndSay(int n) {
        string res = "1";
        for(int i=1; i<n; ++i) {
            res = generate_number(stoll(res));
        }
        return res;
    }
};
