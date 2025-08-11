#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1010;
int n,K;
int F(int num){
	int res=1;
	while(num){
		res*=num%10;
		num/=10;
	}
	return res;
}
int f[N];
struct node{
	int ad,w;
}l[1000010];
int bk[1000010];
bool cmp2(node x,node y){
	return x.w>y.w;
}
void init1(){
	for(int i=1;i<=n;i++) f[i]=F(i);
	
}
void init2(){
	for(int i=1;i<=n;i++){
		l[i].ad=i;
		if(f[i]>n) continue;
		l[f[i]].w++;
	} 
	for(int i=1;i<=n;i++) bk[i]=l[i].w;
	sort(l+1,l+n+1,cmp2);
}
int nmp[N][N];
int dat[N*N],tot;
bool cmp(int x,int y){
	return x>y;
}
void solve1(){
	for(int i=1;i<=n;i++){
		if(f[i]>n) continue;
		for(int j=1;j<=n;j++){
			if(f[j]>n) continue;
			nmp[f[i]][f[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(nmp[i][j]==0) continue;
			dat[++tot]=nmp[i][j];
		}
	}
	sort(dat+1,dat+tot+1,cmp);
	ll ans=0;
	for(int i=1;i<=min(tot,K);i++){
		ans+=dat[i]; ans%=mod;
	}
	cout<<ans;		
}
int main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	cin>>n>>K;
	init1();
	if(n<=1000){
		solve1();
	}
	else if(n<=1000000){
		init2();
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				dat[++tot]=l[i].w+l[j].w;
			}
		}
		sort(dat+1,dat+tot+1,cmp);
		ll ans=0;
		for(int i=1;i<=min(tot,K);i++){
			ans+=dat[i]; ans%=mod;
		}
		cout<<ans;
	} 

	return 0;
}

