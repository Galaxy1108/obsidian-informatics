#include<bits/stdc++.h>
#define int __int128
#define N 1000
using namespace std;
double const T0=2e3,Tk=1e-5,D=0.99;
int const T=10;
int n,t,bans,ans,a[N*N+5],tmp[N+5],b[N+5],uans;
mt19937 rnd;
inline int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
int Rand(int l,int r){
	return rand()%(r-l+1)+l;
}
int getEnergey(){
	int sum=0;
	for(int i=1;i<=n;i++)b[i]=tmp[i];
	bool flag=1;
	for(int j=1;j<n;j++){
		if(b[j+1]>b[j]){
			flag=0;
			break;
		}
	}
	if(flag)return 0;
	for(int i=1;i<=n*n;i++){
		sum=max(sum,b[a[i]]+b[a[i]+1]);
		swap(b[a[i]],b[a[i]+1]);
		b[a[i]+1]++,b[a[i]]--;
		flag=1;
		for(int j=1;j<n;j++){
			if(b[j+1]>b[j]){
				flag=0;
				break;
			}
		}
		if(flag)break;
	}
	flag=1;
	for(int j=1;j<n;j++){
		if(b[j+1]>b[j]){
			flag=0;
			break;
		}
	}
	if(!flag)return LONG_LONG_MAX;
	return sum;
}
void solve(){
	for(int i=1;i<=n*n;i++)a[i]=Rand(1,n-1);
	ans=getEnergey();
	bans=min(bans,ans);
	for(double t=T0;t>Tk;t*=D){
		int rx=Rand(1,n*n),ry=Rand(1,n-1),ty=a[rx];
		a[rx]=ry;
		uans=getEnergey();
		if(uans<ans||exp((ans-uans)/t)>rand()*1.0/RAND_MAX)ans=uans;
		else a[rx]=ty;
		bans=min(bans,ans);
//		cout<<"ans="<<(long long)ans<<"\n";
	}
	return;
}
main(){
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	rnd.seed(time(0));
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++)tmp[i]=read();
		bans=LONG_LONG_MAX;
		for(int i=1;i<=T;i++)solve();
		if(bans<LONG_LONG_MAX)print(bans),putchar('\n');
		else print(-1),putchar('\n');
	}
	return 0;
}
