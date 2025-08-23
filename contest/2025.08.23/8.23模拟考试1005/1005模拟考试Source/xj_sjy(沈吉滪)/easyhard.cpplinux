#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}

int mod;
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define N 3005
#define inf 0x3f3f3f3f

/*
为了数折线不数重，有两种解决方法：
1. 钦定必须碰一下0的被记入。
2. 点边容斥，求每个初始位置的方案 - 相邻2个可行的方案数

可以把n,m减一，首位都是颜色随便，变成先放2个再拿2个 
*/

int n,m;
modint f[N][N][2],res;
signed main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	n=read()-1,m=read()-1,mod=read();
	f[0][0][1]=1;
	For(i,1,n)f[0][i][0]=1;
	For(i,0,m-1)
		For(j,0,n){
			For(o,0,1){
				f[i+1][j][o]+=2*f[i][j][o];
				if(j>=1) f[i+1][j-1][o|(j==1)]+=f[i][j][o];
				if(j<n) f[i+1][j+1][o]+=f[i][j][o];
			}
		}
	For(i,0,n) res+=f[m][i][1];
	res*=4;
	cout<<res.x; 
	return 0;
}