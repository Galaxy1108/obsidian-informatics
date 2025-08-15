#include <bits/stdc++.h>
#define Mod 998244353
using namespace std;
int Qread()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x;
}
int chk(int a){return a>=Mod?a-Mod:a;}
int add(int &a,int b){a+=b;if(a>=Mod) a-=Mod;}
int del(int &a,int b){a-=b;if(a<0) a+=Mod;}
int n,m,ans;
int a[1000010],b[1000010];
int num[100010],sum;
int rem[1000010];
int ls;
void init(){for(int i=1;i<=100000;i++) if(i+(i&-i)<=100000) add(num[i+(i&-i)],num[i]);}
void add_num(int x,int k){for(;x<=100000;x+=(x&-x)) add(num[x],k);}
int get_sum(int x){int ret=0;for(;x;x-=(x&-x)) add(ret,num[x]);return ret;}
int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    n=Qread();
    for(int i=1;i<=n;i++)
        a[i]=Qread();
    m=Qread();
    for(int i=1;i<=m;i++)
        b[i]=Qread();

    for(int i=n;i;i--)
    {
        ls=sum+1;
        rem[i]=chk(num[a[i]]-ls+Mod);
        del(sum,num[a[i]]);
        add(sum,num[a[i]]=ls);
    }

    init();

    int nw=0,cur=1;
    for(int i=1;i<=m;i++)
    {
        add(ans,get_sum(b[i]-1)+1);
        do add_num(a[cur],rem[cur]),cur++;
        while(a[cur-1]!=b[i]);
    }
    printf("%d\n",ans);
    return 0;
}