#include<bits/stdc++.h>
#define int long long
#define N 200000
#define inf (10ll*N*INT_MAX)
using namespace std;
int n,m,a[N+5],tree[N*4+5],tag[N*4+5],suf[N+5],pre[N+5],ans=inf,uans,f[N+5];
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
main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),m+=a[i];
//	build(1,n,1);
	for(int i=n;i>0;i--){
		int k=(a[i]==0?2:(a[i]%2==1?1:0));
//		modify(i,n,1,n,k-a[i],1);
		suf[i]=min(0ll,suf[i+1])+k-a[i];
	}
//	build(1,n,1);
	for(int i=1;i<=n;i++){
		int k=(a[i]==0?2:(a[i]%2==1?1:0));
//		modify(1,i,1,n,k-a[i],1);
		pre[i]=min(0ll,pre[i-1])+k-a[i];
	}
	for(int i=1;i<=n;i++)suf[i]=min(0ll,suf[i]),pre[i]=min(0ll,pre[i]);//,cout<<"i="<<i<<" suf[i]="<<suf[i]<<" pre[i]="<<pre[i]<<"\n";
//	build(1,n,1);
	for(int i=n;i>0;i--){
		int k=(a[i]%2==0);
//		modify(i,n,1,n,k-a[i],1);
//		cout<<"i="<<i<<" d="<<k-a[i]<<"\n";
//		modify(i,i,1,n,suf[i+1],1);
		f[i]=min(f[i+1]+k-a[i],k-a[i]+suf[i+1]);
		uans=pre[i-1]+min(suf[i],f[i]);
		
		ans=min(ans,uans);
	}
	print(ans+m);
	return 0;
}
