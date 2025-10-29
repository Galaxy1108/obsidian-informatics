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
	template<typename T,typename T1> il void rd(T a[],T1 s,T1 t){for(T i=s;i<=t;i++) rd(a[i]);}
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
#define int long long
int n;
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    if(n%2)cout<<n;
    else cout<<0;
    return 0;
}