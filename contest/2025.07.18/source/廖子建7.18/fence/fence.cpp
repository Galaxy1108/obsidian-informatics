#include<bits/stdc++.h>
#define int long long
#define N 100000
#define Mod 1000000007
using namespace std;
int n,h[N+5],w[N+5],ans=0,st[N+5][21],minn,ul,ur,sum[N+5]={},top=0;
pair<int,int>q[N+5];
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
}
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
inline int getmin(int x,int y){
	return min(st[x][(long long)log2(y-x+1)],st[y-(1ll<<((long long)log2(y-x+1)))+1][(long long)log2(y-x+1)]);
}
inline int lowerb(int v,int x){
	int l=1,r=x,mid;
	while(l<r){
		mid=(l+r)>>1ll;
		if(getmin(mid,x)<v)l=mid+1;
		else r=mid;
	}
	return l;
}
main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<=n;i++)w[i]=read(),sum[i]=(sum[i-1]+w[i])%Mod;
	for(int i=n;i>0;i--){
		st[i][0]=h[i];
		for(int j=1;i+(1ll<<j)-1<=n;j++)st[i][j]=min(st[i][j-1],st[i+(1ll<<(j-1))][j-1]);
	}
	for(int i=n;i>0;i--){
		ans=(ans+h[i]*(h[i]+1)%Mod*w[i]%Mod*(w[i]+1)%Mod*fpow(4,Mod-2)%Mod)%Mod;
		while(top&&q[top].first>=h[i])top--;
		q[++top]={h[i],i};
		for(int j=top;j>0;j--){
			minn=q[j].first;
			ul=q[j].second,ur=(j==1?n:q[j-1].second-1);
			ans=(ans+minn*(minn+1)%Mod*fpow(2,Mod-2)%Mod*w[i]%Mod*((sum[ur]-sum[(j==top?ul:ul-1)]+Mod)%Mod)%Mod)%Mod;
		}
	}
	print(ans);
	return 0;
}
