class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char, int> mymap = { { 'I' , 1 },
                                               { 'V' , 5 },
                                               { 'X' , 10 },
                                               { 'L' , 50 },
                                               { 'C' , 100 },
                                               { 'D' , 500 },
                                               { 'M' , 1000} };
            //            unordered_map<char, int> mymap;
            //            mymap['I'] = 1; mymap['V'] = 5; mymap['X'] = 10; mymap['L'] = 50;
            //            mymap['C'] = 100; mymap['D'] = 500; mymap['M'] = 1000;
            int sum = 0;
            for(int i=s.length()-1; i>=0; --i) {
                if(i!=0 && (mymap[s[i]]>mymap[s[i-1]]) ) {
                    sum += mymap[s[i]] - mymap[s[i-1]];
                    i--;
                } else {
                    sum += mymap[s[i]];
                }
            }
            return sum;
        }
};
