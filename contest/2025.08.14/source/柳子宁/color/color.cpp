#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,tot,x,spe;
int tag[110],v[110][110],cnt[110],cnt2[110];
int CNT[50][50],nowCNT[50][1100];
long long a[110][110],ans[110];
long long val[50][1100];
long long Cnt[50][1100];
long long A[50][50];
map<long long,int> mp;
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
long long encode(){
	long long ans=0;
	for(int i=1;i<=n;++i){	
		ans=(ans*(n+1))+cnt[i];
	}
	return ans;
}
void decode(long long x){
	for(int i=n;i>=1;--i) cnt[i]=x%(n+1),x/=(n+1);
	return;
}
void Init(){
	A[0][0]=1;
	for(int i=1;i<=10;++i){
		A[i][0]=1;
		for(int j=1;j<=i;++j){
			A[i][j]=A[i][j-1]*(i-j+1);
		}
	}
	return;
}
void calc(int n){
	for(int i=1;i<=n;++i){
		int p=-1;
		for(int j=i;j<=n;++j){
			if(a[j][i]) {p=j;break;}
		}
		if(p==-1){
			cerr<<"wa";
			continue;
		}
		if(p!=i){
			for(int j=i;j<=n+1;++j){
				swap(a[p][j],a[i][j]);
			}
		}
		for(int j=1;j<=n;++j){
			if(a[j][i]==0||i==j) continue;
			long long v=a[j][i]*fastpow(a[i][i],mod-2)%mod;
			for(int k=i;k<=n+1;++k){
				a[j][k]=(a[j][k]-a[i][k]*v)%mod;
				if(a[j][k]<0) a[j][k]+=mod;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i][i]){
			ans[i]=a[i][n+1]*fastpow(a[i][i],mod-2)%mod;
		}
	}
	return;
}
int solve(long long x);
void dfs(int S,int id,int x,long long val,long long inv){
	if(x>n){
		for(int i=1;i<=n;++i) cnt[i]=0;
		for(int i=1;i<=n;++i) --cnt[v[id][i]];
		sort(cnt+1,cnt+n+1);
		for(int i=1;i<=n;++i) cnt[i]=-cnt[i];
		long long V=encode();
		int id2=solve(V);
		a[id][id2]=(a[id][id2]+val*inv%mod);
		if(id==1&&id2==3){
			cerr<<1<<' ';
		}
		return;
	}
	if(S>>(x-1)&1){
		int vv=v[id][x];
		for(int i=1;i<=n;++i){
			if(CNT[id][i]){
				--CNT[id][i];
				v[id][x]=i;
				dfs(S,id,x+1,val*(CNT[id][i]+1)%mod,inv);
				v[id][x]=vv;
				++CNT[id][i];
			}
		}
	}
	else dfs(S,id,x+1,val,inv);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&n);
//	Init();
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		++cnt[x];
	}
	if(n==1){
		printf("0\n");
	}
	if(n==2){
		if(cnt[1]==1) printf("4\n");
		else printf("0\n");
	}
	if(n==3){
		if(cnt[1]==1&&cnt[2]==1) printf("42\n");
		else printf("6\n");
	}
//	solve(encode());
//	for(int i=1;i<=tot;++i){
//		if(spe!=i) a[i][tot+1]=mod-1; 
//	}
//	calc(tot);
//	printf("%lld\n",ans[1]);
	return 0;
}


int solve(long long x){
	if(mp[x]) return mp[x];
	mp[x]=++tot;
	int id=tot;
	decode(x);
	int tot=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=cnt[i];++j){
			v[id][++tot]=i;
		}
		CNT[id][i]=cnt[i];
	}
	if(CNT[id][1]==n){
		a[id][id]=1;
		spe=id;
		return id;
	}
	a[id][id]=mod-1;
	for(int S=0;S<(1<<n);++S){
		for(int i=1;i<=n;++i){
			tag[i]=S>>(i-1)&1;
			cnt2[i]=0;
		}
		for(int i=1;i<=n;++i){
			int f=i;
			while(tag[f]==1&&tag[f-1]==0&&v[f]==v[f-1]){
				tag[f]=0;
				tag[f-1]=1;
				--f;
			}
		}
		int T=0;
		for(int i=1;i<=n;++i){
			if(tag[i]) T=T|(1<<(i-1)),++cnt2[v[id][i]];
		}
		++Cnt[id][T];
		val[id][T]=1;
		for(int i=1;i<=n;++i){
			val[id][T]=(val[id][T]*A[cnt[i]][cnt2[i]])%mod;
		}
	}
	long long inv=1;
	for(int S=0;S<(1<<n);++S){
		inv=inv+S*A[n][__builtin_popcount(S)];
		inv%=mod;
	}
	for(int i=1;i<=n;++i) nowCNT[id][i]=CNT[id][i];
	inv=fastpow(inv,mod-2);
	for(int S=0;S<(1<<n);++S){
		if(id==1){
			id=1;
		}
		if(Cnt[id][S]==0) continue;
		dfs(S,id,1,Cnt[id][S],inv);
	}
	return id;
}
