#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
#define ls(p) t[p].ls
#define rs(p) t[p].rs

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,lastans,a[N],b[N];
bool testop;

struct node{
    signed ls,rs,v;
    int sum;
}t[N*75];
int tot;
signed rt[N];

void insert(int y,signed &x,int l,int r,int k){
    x=++tot;t[x]=t[y];
    t[x].v++;t[x].sum+=k;
    if(l==r)return;
    int mid=l+r>>1;
    if(k<=mid)insert(ls(y),ls(x),l,mid,k);
    else insert(rs(y),rs(x),mid+1,r,k);
}

int qry(int x,int y,int l,int r,int k){
    if(l==r)return k*l;
    int mid=l+r>>1;
    if(k<=t[rs(y)].v-t[rs(x)].v)return qry(rs(x),rs(y),mid+1,r,k);
    else return t[rs(y)].sum-t[rs(x)].sum+qry(ls(x),ls(y),l,mid,k-t[rs(y)].v+t[rs(x)].v);
}

inline void decode(int &l, int &r, int &k, int lstans, int testop) {  lstans %= 19260817;  if(testop) {   l ^= lstans; l = (l % n + n) % n + 1;   r ^= lstans; r = (r % n + n) % n + 1;   if(l > r) std :: swap(l, r);   k ^= lstans;    k = (k % std :: min(r - l + 1, 100ll)) + 1;  } } 

signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    // int siz=sizeof(t);
    // cout<<" siz:"<<siz/1024/1024<<" MB"<<endl;
    read();testop=read();n=read();
    int vn=0;
    for(int i=1;i<=n;++i){
        int u=read(),v=read(),w=read();
        if(u>v)swap(u,v);
        a[v]=w;
        vn=max(vn,w);
    }
    for(int i=1;i<=n;++i){
        int p=read();
        b[i]=a[p];
        insert(rt[i-1],rt[i],1,vn,a[p]);
    }
    int Q=read();
    for(int i=1;i<=Q;++i){
        int l=read(),r=read(),k=read();
        decode(l,r,k,lastans,testop);
        int ans=qry(rt[r],rt[l-1],1,vn,k);
        print(ans);putchar('\n');
        lastans=ans;
    }
    return 0;
}