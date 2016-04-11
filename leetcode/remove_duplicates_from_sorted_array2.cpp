#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
    vector<int> nums;
    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(3);
//    nums.push_back(3);
//    nums.push_back(4);
    if(!nums.size() )
        return 0;
    int count = 1, index = 0;
    auto begin_it = begin(nums);
    for(auto& it : nums) {
        if(count <= 2) {
//            cout<<" he is "<<*(&it+index)<<endl;
//            cout<<" &it is "<<&it<<" index is  "<<index<<" + index is "<<(&it+index)<<endl;
            *(begin_it+index) = it;
            index++;
        }
        if(it == *(&it+1)) {
            ++count;
        } else {
            count = 1;
        }
    }
    for(auto it : nums)
        cout<<it<<endl;
    return index+1;
}
