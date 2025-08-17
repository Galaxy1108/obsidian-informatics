#include<cstdio>
#include<algorithm>
#define gc getchar()
#define lson now<<1
#define rson now<<1|1
using namespace std;
const int mm=1e6+100,mod=1e9+9;
int n,m,q,now=0,ans[mm];
struct oper{int l,r,x;} op[mm];
struct ques{int x,l,r,op,id;} t[mm<<1];
bool cmp(ques a,ques b) {return a.x<b.x;}
void file() {
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
}
int read() {
    int ans=0,f=1;char ch=gc;
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=gc;}
    while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc;
    return ans*f;
}
void write(int x) {
    if(x>9) write(x/10);
    putchar(x%10+48);
}
struct data { 
    int len,sum,add,sumh,tag,addh;  
}s[mm<<2];             
void pushup(int now) { 
    s[now].sum=(s[lson].sum+s[rson].sum)%mod;    
    s[now].sumh=(s[lson].sumh+s[rson].sumh)%mod;   
}      
void mark_adh(int now,int v,int t) {  
    s[now].addh=((s[now].addh+v)%mod+mod)%mod;   
    if(t) s[now].sumh=((s[now].sumh+1LL*v*s[now].len%mod)%mod+mod)%mod;    
}
void mark_add(int now,int v) {       
    if(s[now].tag) mark_adh(now,-1LL*v*s[now].tag%mod,0);    
    s[now].add=((s[now].add+v)%mod+mod)%mod;    
    s[now].sum=((s[now].sum+1LL*s[now].len*v%mod)%mod+mod)%mod;                    
} 
void mark_tag(int now,int v) { 
    s[now].tag=((s[now].tag+v)%mod+mod)%mod;      
    s[now].sumh=((s[now].sumh+1LL*s[now].sum*v%mod)%mod+mod)%mod;   
}
void pushdown(int now) {  
    if(s[now].add) {  
        mark_add(lson,s[now].add); 
        mark_add(rson,s[now].add);   
        s[now].add=0; 
    }  
    if(s[now].addh) {  
        mark_adh(lson,s[now].addh,1);  
        mark_adh(rson,s[now].addh,1); 
        s[now].addh=0; 
    }  
    if(s[now].tag) {   
        mark_tag(lson,s[now].tag); 
        mark_tag(rson,s[now].tag); 
        s[now].tag=0;  
    }
}
void build(int l,int r,int now) { 
    s[now].len=r-l+1;     
    if(l==r) return;
    int mid=l+r>>1; 
    build(l,mid,lson), build(mid+1,r,rson);
    pushup(now); 
}
void update(int l,int r,int now,int L,int R,int v) { 
    if(L<=l&&r<=R) return mark_add(now,v),void(); 
    pushdown(now); 
    int mid=l+r>>1;  
    if(L<=mid)  update(l,mid,lson,L,R,v); 
    if(R>mid)   update(mid+1,r,rson,L,R,v);   
    pushup(now); 
}
int query(int l,int r,int now,int L,int R) {   
    if(L<=l&&r<=R) return s[now].sumh; 
    pushdown(now); 
    int mid=l+r>>1,re=0;
    if(L<=mid)  re+=query(l,mid,lson,L,R); 
    if(R>mid)   re+=query(mid+1,r,rson,L,R);  
    return (re%mod+mod)%mod;  
}    
int main() {
    file();
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++) {
        int l=read(),r=read(),x=read();
        op[i]={l,r,x};
    }
    for(int i=1;i<=q;i++) {
        int u=read(),d=read(),l=read(),r=read();
        t[i*2-1]={u-1,l,r,-1,i},t[i*2]={d,l,r,1,i};
    }
    sort(t+1,t+q*2+1,cmp);
    build(1,n,1);
    for(int i=1;i<=q*2;i++) {
        while(now<t[i].x) now++,update(1,n,1,op[now].l,op[now].r,op[now].x),mark_tag(1,1);
        ans[t[i].id]=((ans[t[i].id]+t[i].op*query(1,n,1,t[i].l,t[i].r))%mod+mod)%mod;
    }
    for(int i=1;i<=q;i++) write(ans[i]),puts("");
    return 0;
}