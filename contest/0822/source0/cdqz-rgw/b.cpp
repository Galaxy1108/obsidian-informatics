#include<bits/stdc++.h>
#define Add(x,y) (x+y>=mod)?(x+y-mod):(x+y)
#define lowbit(x) x&(-x)
#define pi pair<ll,ll>
#define pii pair<ll,pair<ll,ll>>
#define iip pair<pair<ll,ll>,ll>
#define ppii pair<pair<ll,ll>,pair<ll,ll>>
#define fi first
#define se second
#define full(l,r,x) for(auto it=l;it!=r;it++) (*it)=x
#define Full(a) memset(a,0,sizeof(a))
#define open(s1,s2) freopen(s1,"r",stdin),freopen(s2,"w",stdout);
#define For(i,l,r) for(register int i=l;i<=r;i++)
#define _For(i,l,r) for(register int i=r;i>=l;i--)
using namespace std;
typedef double db;
typedef unsigned long long ull;
typedef long long ll;
bool Begin;
const ll N=2020,INF=1e18;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
          f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar(x%10+'0');
}
ll n,w,Min=INF,id;
ll a[N][N],d[N];
bool f[N];
void dijkstra(ll s){
	f[s]=1;
	For(i,1,n){
		d[i]=a[s][i];
		For(j,1,n){
			if(i==j)
			  continue;
			d[i]=min(d[i],a[i][j]*2);
		}
	}
	For(i,1,n-1){
		Min=INF,id=0;
		For(j,1,n){
			if(f[j])
			  continue;
			if(d[j]<Min){
				Min=d[j];
				id=j;
			}
		}
		f[id]=1;
		For(j,1,n){
			if(f[j])
			  continue;
			d[j]=min(d[j],d[id]+a[id][j]);
		}
	}
}
bool End;
int main(){
	open("b.in","b.out");
	n=read();
	For(i,1,n){
	    For(j,i+1,n){
	    	a[i][j]=a[j][i]=read();
	    	if(a[i][j]<Min){
	    		Min=a[i][j];
	    		id=i;
			}
		}
	}
	For(i,1,n)
	  For(j,1,n)
		if(a[i][j])
		  a[i][j]-=Min;
	w=Min;
	dijkstra(id);
	For(i,1,n){
		write(d[i]+(n-1)*w);
		putchar('\n');
	}
	cerr<<'\n'<<abs(&Begin-&End)/1048576<<"MB";
	return 0;
}
