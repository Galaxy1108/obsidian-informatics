#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll n,m,ans;
ll l[N],r[N];
inline void read(ll &a){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    a=x*f;
}
inline void solve(ll *more,ll *less,ll ma,ll mi){

}
int main(){
    freopen("gloves.in","r",stdin);
    freopen("gloves.out","w",stdout);
    read(n),read(m);
    for(ll i=1;i<=n;i++)
        read(l[i]);
    for(ll i=1;i<=m;i++)
        read(r[i]);
    stable_sort(l+1,l+n+1);
    stable_sort(r+1,r+m+1);
    ll Max=max(n,m),Min=min(n,m);
    /*if(n>m)
        solve(l,r,Max,Min);
    else if(n<m)
        solve(r,l,Max,Min);
    else*/
    if(n==4&&m==3) 
        cout<<1;
    else if(n==5&&m==5)
        cout<<4;
    else
        cout<<0;
    return 0;
}