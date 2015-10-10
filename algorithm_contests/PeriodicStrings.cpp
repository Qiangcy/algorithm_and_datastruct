#include <iostream>
#include <string>
using namespace std;

int is_substr(string str, int start)
{
    for(int i=0; i<start; ++i) {
        for(int n=1; start*n+i<str.length(); ++n) {
            if(str[i] != str[start*n+i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int count = 0;
        for(int i=1; str[i]; ++i) {
            if(str[0] == str[i]) {
                if(str.length()%i != 0)
                    continue;
                count = is_substr(str, i);
                if(count != 0) {
                    count = i;
                    break;
                }
            }
        }
        if(count == 0)
            count = str.length();
        if(!t)
            cout<<count<<endl;
        else
            cout<<count<<endl<<endl;
    }
    return 0;
}

/* other people's solution
#include <stdio.h>
#include <string.h>
#define maxn 80
char s[maxn];
int ans, l;

bool check()
{
for (int i = ans; i < l; i++)
if (s[i] != s[i % ans]) return false;
return true;
}

int main()
{
int t;
scanf("%d", &t);
while (t--)
{
scanf( "%s", s);
l = strlen(s);
for (ans = 1; ans <= l; ans++)
{
if (l % ans != 0) continue;
if (check()) break;
}
if (t==0) printf("%d\n",ans);
else printf("%d\n\n",ans);
}
return 0;
}
*/
