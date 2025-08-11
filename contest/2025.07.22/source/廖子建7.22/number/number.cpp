#include<bits/stdc++.h>
#define int long long
#define N 300000
using namespace std;
int t,n,m,val[N+5],a[N+5],f[N+5],ans;
int read(){
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
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
void dfs(int x){
	if(x>m){
		int sum=0;
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1;i<=m;i++)a[f[i]]=val[i]-a[f[i]];
		for(int i=1;i<=n;i++)sum+=a[i];
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)f[x]=i,dfs(x+1);
	return;
}
main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=read(),ans=LONG_LONG_MIN;
		for(int i=1;i<=m;i++)val[i]=read();
		val[0]=0;
		if(n==2){
			int opt=0;
			ans=0;
			for(int i=m;i>0;i--){
				if(opt==0)ans+=val[i],opt=2;
				else if(opt==1)ans-=val[i],opt=2;
				else{
					if(val[i]>val[i-1])ans+=val[i],opt=1;
					else ans-=val[i],opt=0;
				}
			}
			print(ans),putchar('\n');
			continue;
		}
		dfs(1),print(ans),putchar('\n');
	}
	return 0;
}
