#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
int n,a[N],b[N];
mt19937 rd(20250913);
typedef pair<int,int>pii;
struct Node{
    int rnd,siz,ls,rs,mx,val;
    pii mn;
}t[N];
int tot,rt;
#define l(x) t[x].ls
#define r(x) t[x].rs
inline void chk(int&x,int y){
    if(x<y)x=y;
}
inline void pushup(int x){
    t[x].siz=t[l(x)].siz+1+t[r(x)].siz;
    t[x].mx=t[l(x)].mx;
    chk(t[x].mx,t[x].val+2*t[l(x)].siz+2);
    chk(t[x].mx,t[r(x)].mx+2*(t[l(x)].siz+1));
    t[x].mn=t[l(x)].mn;
    t[x].mn=min(t[x].mn,{t[x].val,t[l(x)].siz+1});
    t[x].mn=min(t[x].mn,{t[r(x)].mn.fi,t[r(x)].mn.se+t[l(x)].siz+1});
}
inline int New(int v){
    tot++;
    t[tot].rnd=rd();
    t[tot].ls=t[tot].rs=0;
    t[tot].val=v;
    pushup(tot);
    return tot;
}
int merge(int x,int y){
    if(!x||!y)return x|y;
    if(t[x].rnd<t[y].rnd){
        r(x)=merge(r(x),y);
        pushup(x);
        return x;
    }l(y)=merge(x,l(y));
    pushup(y);
    return y;
}
void split(int x,int k,int&k1,int&k2){
    if(!x){
        k1=k2=0;
        return;
    }
    if(t[l(x)].siz+1<=k){
        k1=x;
        split(r(k1),k-t[l(x)].siz-1,r(k1),k2);
        pushup(k1);
    }else{
        k2=x;
        split(l(k2),k,k1,l(k2));
        pushup(k2);
    }
}
inline void read(int&x){
    x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
}
int solve(){
    read(n);
    for(int i=1;i<=n;i++)read(a[i]),a[i]-=i,b[i]=a[i];
    sort(b+1,b+1+n);
    for(int i=1;i<n;i++)if(b[i]==b[i+1]){
        puts("-1");
        return 0;
    }
    int res=0;tot=rt=0;
    for(int i=1;i<=n;i++)rt=merge(rt,New(a[i]));
    for(int i=1;i<=n;i++){
        int k1,k2,k3;
        int pos=t[rt].mn.se-1;
        split(rt,pos,k1,k3);
        split(k3,1,k2,k3);
        if(k3)res=max(res,t[k3].mx+2*t[k1].siz+t[k2].val+1);
        rt=merge(k1,k3);
    }
    printf("%lld\n",res);
    return 0;
}
signed main(){
    freopen("jyrg.in","r",stdin);
    freopen("jyrg.out","w",stdout);
    t[0].mn={2e18,0};
    int t;read(t);
    while(t--)solve();
    return 0;
}
/*
每个数到每个位置的值是确定的
即求每一对逆序对被交换的位置
每次把最小的向后交换即可？
用平衡树维护
(a[i]+2i)max
*/
