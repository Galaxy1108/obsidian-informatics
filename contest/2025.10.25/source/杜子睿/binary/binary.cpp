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
int n,m;
int a[100005];
signed main(){
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    rd(n);
    rd(a,1ll*1,n);
    rd(m);
    for(int i=1;i<=m;i++){
        int opt,x,y;
        rd(opt,x);
        if(opt==1) a[x]^=1;
        else{
            rd(y);
            int ans=0;
            for(int j=x;j<=y;j++){
                int c=0,d=0;
                if(a[j]==1)c=1;else d=1;
                if(d==1)ans++;
                for(int k=j+1;k<=y;k++){
                    if(a[k]==1)c++;
                    else d++;
                    if(c%2==0)ans++;
                    else if(d>=c-1&&c>=3)ans++;
                }
            }
            wr(ans);
        }
    }
    Flush();
    return 0;
}