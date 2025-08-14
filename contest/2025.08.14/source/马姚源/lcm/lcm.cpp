#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define endl '\n'
#define ll unsigned __int128 
#define LL long long
ll e[N],f[N],g[N];

ll qpow(ll a,ll b,ll p){
	if(a==1)return 1;
	ll power=a,res=1;
	if(b<=0)return 1;
	while(b>0){
		if(b&1){
			res%=p;
			res=res+power%p;	
			res%=p;
		}
		power%=p;
		power=power*power%p;
		power%=p;
		b>>=1;
	}
	return res%p;
}
ll GCD(ll a,ll b){
	if(b==0)return a;
	return GCD(b,a%b);
}
ll ny(ll x,ll p){
	return qpow(x,max(p-2,(ll)0),p);
}
ll lcm(ll a,ll b,ll p){
	if(a<b)swap(a,b);
	ll gcd=GCD(a,b);
	return (a/gcd*b);
	return (((a%p*(ny(gcd,p)%p))%p*b%p)%p)%p;
}

void write(ll x){
	if(x<10&&x>0){
		putchar(x+'0');
		return;	
	}
	if(x<0){
		putchar('-');
		x=-x;
	}
	write(x/10);putchar(x%10+'0');
}
void solv(){
	LL n,x;
	cin >> n >> x;
//	memset(f,0,sizeof(f));
//	memset(e,0,sizeof(e));
//	memset()
	ll p=x;
	f[1]=1;
	e[1]=1;
//	f[2]=2;
//	e[2]=3;
	for(LL i=2;i<=n;i++){
		e[i]=f[i-1]*2%p+e[i-1]%p;
		e[i]%=p;
		f[i]=e[i-1]%p+f[i-1]%p;
		f[i]%=p;
	}
//	for(int i=2;i<=n;i++){
//		e[i]=f[i-1]*2+e[i-1];
//		f[i]=e[i-1]+f[i-1];
//	}
	g[1]=1;
	for(int i=2;i<=n;i++){
		g[i]=lcm(g[i-1]%p,f[i]%p,p);
//		g[i]=lcm(g[i-1],f[i],p);
//		cout << g[i] << " ";
	}
//	write(g[18]);
//	cout << "\n\n\n\n\n\n\n\n\n\n\n\n"; 
//	cout << endl;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=(g[i]+p)%p*(ll)i%p;
//		ans+=((g[i]+p)%p*((ll)i+p)%p)%p;
		ans=(ans+p)%p;
	}
	cout << (LL)ans << endl;
//	if(ans<0)ans+=(1<<64)-1;
	write(ans);
	cout << endl;

}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout); 
	int T;
	cin >> T;
	
//	for(int i=1;i<=1e2;i++)cout << e[i] << " ";
//	cout << endl;
//	for(int i=1;i<=1e2;i++)cout << f[i] << " ";
//	cout << endl;
	while(T--)solv(); 
	return 0;
} 
