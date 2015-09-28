#include <iostream>
#include <string>
using namespace std;

int is_substr(string str, int start, int count)
{
//    if(!str[start+count])
//        return 0;
    int i = 0, tmp = start;
    static int record = count;
    cout<<endl<<"start is  "<<start<<endl;
    while(str[i++] == str[tmp++]) {
        cout<<" i is  \t "<<i<<"tmp is  \t"<<tmp<<"    \t"<<str[tmp]<<" "<<endl;
        if(tmp-start == start) {// || tmp-start+1 == count
            if((count=is_substr(str, tmp, count)))
                return count;
            else
                return 0;
        }
    }
    if(str[i-1] != str[tmp-1] && str[i-1] && str[tmp-1] ) {
        cout<<endl<<"str[i-1] is  "<<str[i-1]<<" str[tmp-1] is "<<str[tmp-1]<<endl;
        return 0;
    }
    if(str[tmp]=='\0') {
        cout<<"inside2"<<endl;
        cout<<"record is "<<record<<endl;
        return record;
    }


    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int count, record;
        for(int i=1; str[i]; ++i) {
            //            cout<<"str[i] is "<<str[i]<<endl;
            if(str[0] == str[i]) {
//                if(count == 0)
//                    count = i;
                //cout<<endl<<"str[i] is , equal to str[0]"<<str[i]<<endl;
                count = is_substr(str, i, i);
                if(count != 0)
                    cout<<"!=0 : count is "<<count<<endl;
                //cout<<"count in equal  is "<<count<<endl;
                i += count;
            }
//            else
//            {
//                 if(count!=0 && !is_substr(str, i, count))
//                     count = 0;
//            }
        }
        cout<<endl<<endl<<"count is "<<count<<endl;
    }
    return 0;
}
