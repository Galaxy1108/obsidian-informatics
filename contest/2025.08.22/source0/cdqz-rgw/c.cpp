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
#define For(i,l,r) for(int i=l;i<=r;i++)
#define _For(i,l,r) for(int i=r;i>=l;i--)
using namespace std;
typedef double db;
typedef unsigned long long ull;
typedef long long ll;
bool Begin;
const ll N=5050,INF=1e18;
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
ll n,Min,x,y,id,seed;
ll a[N][N],h[N][N],pre[N],ans[N];
bool f[N];
void gen(){
    std::mt19937 rnd(seed);
    For(i,1,n){
        For(j,1,n+1){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rnd()%j+1]);           	
		}
	}
	For(i,1,n)
	  For(j,1,n+1)
	    a[i-1][j-1]=a[i][j];
}
bool End;
int main(){
	open("c.in","c.out");
	n=read(),seed=read();
	if(seed)
	  gen();
	else{
		For(i,0,n-1)
		  For(j,0,n)
		    a[i][j]=read();
	}
	For(i,0,n-1)
	  For(j,0,n)
		h[i][--a[i][j]]=j;
	For(i,0,n-1){
		For(j,0,n)
		  f[j]=0;
//		For(j,0,n-1){
//			cerr<<pre[j]<<' ';
//		}
//		cerr<<'\n';
		x=i;
		while(1){
			x--;
			if(x<0)
			  x+=n;
			y=pre[x];
			if(!f[h[x][0]])
			  y=0;
			while(1){
				if(!f[h[x][y]]){
					if(x!=i)
					  pre[x]=y;
					id=h[x][y];
					break;
				}
				y++;
				if(y==n+1)
				  y=0;
			}
//			cerr<<y<<' ';
			f[id]=1;
			if(x==i)
			  break;
		}
//		cerr<<'\n';
		For(j,0,n){
			if(!f[j]){
				ans[i]=j+1;
				break;
			}
		}
	}
	For(i,0,n-1){
		write(ans[i]);
		putchar(' ');
	}
	cerr<<'\n'<<abs(&Begin-&End)/1048576<<"MB";
	return 0;
}
