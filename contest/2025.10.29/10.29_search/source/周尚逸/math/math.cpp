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
int a,b;
struct op{
    int fenmu;
}ans[100005];
int len=1e9;
void DFS(int zi,int mu,int sum)
{
    if(len<=sum)return;
    if(zi==0)
    {
        len=sum;
        return;
    }
    for(int i=ans[sum]+1;;i++)
    {
        if((zi*i)>=mu)
        {
            int furina=zi*i-mu;
            int fufu2=__gcd(furina,mu*i);
            ans[sum+1]=i;
            DFS(furina/fufu2,mu*i/fufu2,sum+1);
        }
    }
}
int main()
{
    a=rd();
    b=rd();
    void DFS(a,b);
    return 0;
}