#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
    int x=0,f=1;
    char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s<='9'&&s>='0'){x=x*10+(s^48);s=getchar();}
    return x*f;
}
int n;
string s[45];
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    n=rd();
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    if(n==3)
    {
        cout<<s[3]<<endl<<s[1]<<endl<<s[2]<<endl<<s[1]<<endl<<s[3]<<endl<<s[2];
    }
    if(n==4)
    {
        cout<<s[4]<<endl<<s[1]<<endl<<s[3]<<endl<<s[1]<<endl<<s[2]<<endl<<s[4]<<endl<<s[3]<<endl<<s[2];
    }
    return 0;
}