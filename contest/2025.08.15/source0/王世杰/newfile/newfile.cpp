#include<bits/stdc++.h>
#define G getchar()
#define Ls (nw<<1)
#define Rs (nw<<1|1)
using namespace std;
const int mm=1e6+100,mo=1e9+9;
int n,m,q,nw=0,ans[mm];
struct oper{int l,r,x;} op[mm];
struct ques{int x,l,r,op,id;} t[mm<<1];
bool cmp(ques a,ques b) {return a.x<b.x;}
inline int read() 
{
    int ans=0,f=1; char ch=G;
    while(!isdigit(ch)) {if(ch=='-') f=-1; ch=G;}
    while(isdigit(ch)) ans=ans*10+ch-'0',ch=G;
    return ans*f;
}
struct note {int len,sum,add,sumh,tag,addh;} s[mm<<2];          
void pushup(int nw)
{ 
    s[nw].sum=(s[Ls].sum+s[Rs].sum)%mo;
    s[nw].sumh=(s[Ls].sumh+s[Rs].sumh)%mo;
}
void mark_adh(int nw,int v,int t)
{
    s[nw].addh=((s[nw].addh+v)%mo+mo)%mo;   
    if(t) s[nw].sumh=((s[nw].sumh+1LL*v*s[nw].len%mo)%mo+mo)%mo;    
}
void mark_add(int nw,int v) 
{
    if(s[nw].tag) mark_adh(nw,-1LL*v*s[nw].tag%mo,0);    
    s[nw].add=((s[nw].add+v)%mo+mo)%mo;    
    s[nw].sum=((s[nw].sum+1LL*s[nw].len*v%mo)%mo+mo)%mo;                    
} 
void mark_tag(int nw,int v) 
{ 
    s[nw].tag=((s[nw].tag+v)%mo+mo)%mo;      
    s[nw].sumh=((s[nw].sumh+1LL*s[nw].sum*v%mo)%mo+mo)%mo;   
}
void pushdown(int nw)
{  
    if(s[nw].add)
    {
        mark_add(Ls,s[nw].add); 
        mark_add(Rs,s[nw].add);   
        s[nw].add=0; 
    }  
    if(s[nw].addh)
    {
        mark_adh(Ls,s[nw].addh,1);  
        mark_adh(Rs,s[nw].addh,1); 
        s[nw].addh=0; 
    }  
    if(s[nw].tag)
    {
        mark_tag(Ls,s[nw].tag); 
        mark_tag(Rs,s[nw].tag); 
        s[nw].tag=0;  
    }
}
void build(int l,int r,int nw)
{ 
    s[nw].len=r-l+1;     
    if(l==r) return;
    int mid=l+r>>1; 
    build(l,mid,Ls), build(mid+1,r,Rs);
    pushup(nw); 
}
void update(int l,int r,int nw,int L,int R,int v) 
{ 
    if(L<=l&&r<=R) return mark_add(nw,v),void(); 
    pushdown(nw); 
    int mid=l+r>>1;  
    if(L<=mid) update(l,mid,Ls,L,R,v); 
    if(R>mid) update(mid+1,r,Rs,L,R,v);   
    pushup(nw); 
}
int query(int l,int r,int nw,int L,int R)
{   
    if(L<=l&&r<=R) return s[nw].sumh; 
    pushdown(nw); 
    int mid=l+r>>1,ret=0;
    if(L<=mid) ret+=query(l,mid,Ls,L,R); 
    if(R>mid) ret+=query(mid+1,r,Rs,L,R);  
    return (ret%mo+mo)%mo;  
}    
int main()
{
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i=1;i<=m;i++) 
    {
        int l=read(),r=read(),x=read();
        op[i]={l,r,x};
    }
    for(int i=1;i<=q;i++) 
    {
        int u=read(),d=read(),l=read(),r=read();
        t[i*2-1]={u-1,l,r,-1,i},t[i*2]={d,l,r,1,i};
    }
    sort(t+1,t+q*2+1,cmp); build(1,n,1);
    for(int i=1;i<=q*2;i++)
    {
        while(nw<t[i].x) nw++,update(1,n,1,op[nw].l,op[nw].r,op[nw].x),mark_tag(1,1);
        ans[t[i].id]=((ans[t[i].id]+t[i].op*query(1,n,1,t[i].l,t[i].r))%mo+mo)%mo;
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}