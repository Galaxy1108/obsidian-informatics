#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=5e7+5;
int sa[N];
char s[N];
int n,m,L,R;
int fa[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
bool fl[N<<2];
void pushup(int p){
    fl[p]=fl[p<<1]+fl[p<<1|1];
}
void build(int p,int l,int r){
    if(l==r){
        fl[p]=1;
        return;
    }int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void query(int p,int l,int r,int l1,int r1,vector<int>&res){
    if(!fl[p])return;
    if(l==r){
        res.push_back(l);
        fl[p]=0;
        return;
    }int mid=l+r>>1;
    if(l1<=mid)query(p<<1,l,mid,l1,r1,res);
    if(r1>mid)query(p<<1|1,mid+1,r,l1,r1,res);
    pushup(p);
}
void comb(int l,int r){
    if(l==r)return;
    vector<int>res;
    query(1,1,n,l,r-1,res);
    for(int i:res)merge(i,i+1);
}
void read(int&x){
    x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
}
int main(){
    freopen("virtual.in","r",stdin);
    freopen("virtual.out","w",stdout);
    read(n),read(L),read(R);
    build(1,1,n);
    for(int i=1;i<=n;i++)fa[i]=i;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)sa[i]=sa[i-1]+(s[i]=='a');
    for(int i=1;i<=n;i++){
        int l0=lower_bound(sa+1,sa+1+n,sa[i-1]+L)-sa;
        int r0=upper_bound(sa+1,sa+1+n,sa[i-1]+R)-sa-1;
        if(l0<=r0){
            comb(l0,r0);
            merge(i,l0);
        }
    }read(m);
    while(m--){
        int x,y;read(x),read(y);
        if(find(x)==find(y))puts("Yes");
        else puts("No");
    }
    return 0;
}
/*
找到一个区间中的所有颜色不同的点即可
*/