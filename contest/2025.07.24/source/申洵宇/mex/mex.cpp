#include <bits/stdc++.h>
using namespace std;
/*
f[i][S]:考虑完前i个数，压位S每个数有没有 
*/
#define N 5005
#define MOD 998244353ll
int n,m,ch[N],lg2[(1<<21)+5];
long long f[25][(1<<21)];
inline int lowbit(int x){
	return x&(-x);
}
inline long long mpow(long long b,long long p){
	long long res=1;
	while(p){
		if(p&1)res=res*b%MOD;
		p>>=1;
		b=b*b%MOD;
	}
	return res;
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&ch[i]);
		cnt+=(ch[i]==0);
	}
	if(n>20||m>20){
		printf("%lld",mpow(m,cnt));
		return 0;
	}
	lg2[1]=0;
	for(int s=2;s<=(1<<(m+1));s++){
		lg2[s]=lg2[s>>1]+1;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int s=0;s<(1<<(m+1));s++){
			if(ch[i]==1){
				if(lg2[lowbit(s+1)]<=m){
					f[i][s|lowbit(s+1)]+=f[i-1][s];
					while(f[i][s|lowbit(s+1)]>=MOD){
						f[i][s|lowbit(s+1)]-=MOD;
						break;
					}
				}
			}
			else{
				for(int c=0;c<=m;c++){
					if(c==lg2[lowbit(s+1)])continue;
					f[i][s|(1<<c)]+=f[i-1][s];
					while(f[i][s|(1<<c)]>=MOD){
						f[i][s|(1<<c)]-=MOD;
						break;
					}
				}
			}
		}
	}
	long long ans=0;
	for(int s=0;s<(1<<(m+1));s++){
		ans+=f[n][s]; 
		while(ans>=MOD){
			ans-=MOD;
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}

