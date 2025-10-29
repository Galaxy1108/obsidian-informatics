#include<bits/stdc++.h>
using namespace std;
namespace fastio{
	#define il inline
	const int isz=1<<25;
	char iin[isz],*is=iin+isz,*it=iin+isz;
	#define gc() (is==it)?(it=(is=iin)+fread(iin,1,isz,stdin),(is==it)?EOF:*is++):*is++
	template<typename T> il void rd(T &x){
		x=0;
		char c=gc();
		bool fla=false;
		while(!isdigit(c)) fla|=(c=='-'),c=gc();
		while(isdigit(c)) x=(x<<1)+(x<<3)+(c&15),c=gc();
		x=(fla)?-x:x;
	}
	template<typename T1,typename...T2> il void rd(T1 &x,T2&...y){rd(x);rd(y...);}
	template<typename T,typename T1> il void rd(T a[],T1 s,T t){for(T i=s;i<=t;i++) rd(a[i]);}
	char iout[isz],*ita=iout;
	#define Flush() fwrite(iout,1,ita-iout,stdout);ita=iout
	template<typename T> il void wr(T x,char la='\n'){
		char c[35];
		int len=0;
		if(x<0) *ita++='-',x=-x;
		do{c[++len]=(x%10+'0');x/=10;}while(x);
		while(len)*ita++=c[len--];
		*ita++=la;
	} 
	il void en(char x='\n'){*ita++=x;}
}
using namespace fastio;
bool flag[1000005],book[25];
int n,q,cnt,rt,init[25][10005];
struct node{
    int sz,l,r,val,pri;
}tr[1000005];
int merge(int u,int v){
    if(!u||!v)return u+v;
    if(tr[u].pri>tr[v].pri){tr[u].r=merge(tr[u].r,v);tr[u].sz=tr[tr[u].l].sz+tr[tr[u].r].sz+1;return u;};
    tr[v].l=merge(u,tr[v].l);tr[v].sz=tr[tr[v].l].sz+tr[tr[v].r].sz+1;return v;
}
void split(int p,int x,int &l,int &r){
    if(!p){l=r=0;return;}
    if(tr[p].val<=x){l=p;split(tr[p].r,x,tr[p].r,r);}
    else{r=p;split(tr[p].l,x,l,tr[p].l);}
    tr[p].sz=tr[tr[p].l].sz+tr[tr[p].r].sz+1;
}
void split_rank(int p,int x,int &l,int &r){
    if(!p){l=r=0;return;}
    if(tr[tr[p].l].sz+1<=x){l=p;split_rank(tr[p].r,x-tr[tr[p].l].sz-1,tr[p].r,r);}
    else{r=p;split_rank(tr[p].l,x,l,tr[p].l);}
    tr[p].sz=tr[tr[p].l].sz+tr[tr[p].r].sz+1;
}
void build(){
    for(int i=1;i<=n;i++){
        tr[i].sz=1;
        tr[i].val=i;
        tr[i].pri=rand();
        rt=merge(rt,i);
    }
}
int in(int x,int y,int op=0){
    if(op==0){
        if(x<=y) return x/2+1;
        int z=in(x-(x+y-1)/y,y,1);
        return z+(z-1)/(y-1)+1;
    }
    else{
        if(x<=y)return(x+1)/2;
        int z=in(x-(x+y-1)/y,y),w=(x-(x+y-1)/y);
        int res=w-z+1;
        res+=(res-1)/(y-1)+1;
        return x-res+1;
    }
}
int query(int x,int y,int op=0){
    if(op==0){
        if(x<=10000)return init[y][x];
        if(x<=y) return x/2+1;
        int z=query(x-(x+y-1)/y,y,1);
        return z+(z-1)/(y-1)+1;
    }
    else{
        if(x<=y)return(x+1)/2;
        int z=query(x-(x+y-1)/y,y),w=(x-(x+y-1)/y);
        int res=w-z+1;
        res+=(res-1)/(y-1)+1;
        return x-res+1;
    }
}
int main(){
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    srand(time(NULL));
    rd(n,q);
    build();
    cnt=n;
    for(int i=2;i<=20;i++)for(int j=1;j<=10000;j++)init[i][j]=in(j,i);
    for(int i=0;i<q;i++){
        int opt,m;
        rd(opt,m);
        if(opt==1){
            if(book[m])continue;
            else{
                book[m]=true;
                for(int i=1;i<=n;i+=m)if(!flag[i]){flag[i]=true;cnt--;int l,r,p;split(rt,i-1,l,r);split(r,i,p,r);rt=merge(l,r);}
            }
        }
        else if(opt==2){
            if(!cnt) continue;
            for(int i=1;i<=cnt;i+=m-1){int l,r,p;split_rank(rt,i-1,l,r);split_rank(r,1,p,r);flag[tr[p].val]=true;cnt--;rt=merge(l,r);}
        }
        else{
            if(!cnt)wr(-1);
            else{int rk=query(cnt,m);int p,l,r;split_rank(rt,rk-1,l,r);split_rank(r,1,p,r);wr(tr[p].val);rt=merge(merge(l,p),r);}
        }
    }
    Flush();
    return 0;
}