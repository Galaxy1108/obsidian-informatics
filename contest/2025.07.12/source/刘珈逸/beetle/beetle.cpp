#include<bits/stdc++.h>
using namespace std;
const int N=2.5e6+5,mod=1e9+7;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
namespace Fread {
	const int SIZE=1<<23;char buf[SIZE],*S,*T;
	inline char getchar() {if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return '\n';}return *S++;}
}
namespace Fwrite {
	const int SIZE=1<<23;
	char buf[SIZE],*S=buf,*T=buf+SIZE;
	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
	inline void putchar(char c){*S++=c;if(S==T)flush();}
	struct POPOSSIBLE{~POPOSSIBLE(){flush();}}ztr;
}
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
namespace Fastio{
	struct Reader{
	    template<typename T>
    	Reader& operator >> (T& x) {
        	char c=getchar();T f=1;
        	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;
        	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}x*=f;
	        return *this;
    	}
	    Reader(){}
	}cin;
	struct Writer{
	    template<typename T>
	    Writer& operator << (T x) {
	        if(x==0){putchar('0');return *this;}
	        if(x<0){putchar('-');x=-x;}
	        static int sta[45];int top=0;
	        while(x){sta[++top]=x%10;x/=10;}
	        while(top){putchar(sta[top]+'0');--top;}
	        return *this;
    	}
    	Writer& operator << (char c) {putchar(c);return *this;}
    	Writer(){}
	}cout;
}
#define endl '\n'
#define cin Fastio :: cin
#define cout Fastio :: cout
int n,k;
int s[N],lst[N],stk[N],tp;
ll dp[N];
int q[N],h=1,t=0;
priority_queue<ll,vector<ll>,greater<ll> >q1,q2;
void clear(){
	while(q2.size()&&q1.top()==q2.top())q1.pop(),q2.pop();
}
int q3[N],hh=1,tt=0;
int main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		while(tp&&s[stk[tp]]<=s[i])tp--;
		lst[i]=stk[tp];
		stk[++tp]=i;
	}q1.push(inf);
	for(int i=1;i<=n;i++){
		if(hh<=tt&&q3[hh]<=i-k)hh++;
		while(hh<=tt&&s[q3[tt]]<=s[i])tt--;
		q3[++tt]=i;
		while(h<=t&&s[i]>=s[q[t]])q2.push(s[q[t]]+dp[lst[q[t]]]),t--;
		q[++t]=i;q1.push(s[i]+dp[lst[i]]);
		while(h<=t&&lst[q[h]]<i-k)q2.push(s[q[h]]+dp[lst[q[h]]]),h++;
		clear();
		dp[i]=min(q1.top(),s[q3[hh]]+dp[max(0,i-k)]);
	}
	ll pw=1,ans=0;
	for(int i=n;i>=1;i--){
		ans=(ans+dp[i]%mod*pw)%mod;
		pw=pw*23%mod;
	}cout<<ans<<endl;
	return 0;
}
