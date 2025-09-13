#include<bits/stdc++.h>
#define int long long
#define N 2000000
using namespace std;
int n,lk,rk,a[N+5],to[N+5],q,ux,uy,tot=0,sum[N+5],f[N+5],s[N+5],vis[N+5];
char c;
inline int read(){
//	int f=1,g=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9'){
//		if(ch=='-')f=-1;
//		ch=getchar();
//	}
//	while('0'<=ch&&ch<='9'){
//		g=g*10+ch-'0';
//		ch=getchar();
//	}
//	return f*g;
	int x;
	cin>>x;
	return x;
}
//inline void print(int x){
//	if(x<0){
//		putchar('-');
//		x*=-1;
//	}
//	if(x>9)print(x/10);
//	putchar(x%10+'0');
//}
inline int find(int x){
	int l=x,r=tot,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(sum[mid]-sum[x-1]<lk)l=mid+1;
		else r=mid;
	}
	if(sum[l]-sum[x-1]<lk)return tot+1;
	return l;
}
int findRoot(int x){
	if(f[x]==x)return x;
	return f[x]=findRoot(f[x]); 
}
inline void merge(int rx,int ry){
	if(rx==ry)return;
	if(s[rx]>s[ry])f[ry]=rx,s[rx]+=s[ry];
	else f[rx]=ry,s[ry]+=s[rx];
	return;
}
main(){
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=read(),lk=read(),rk=read(),a[0]=1;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[i]=(c=='a');
		if(a[i-1]||a[i])to[i]=++tot,sum[tot]=sum[tot-1]+a[i];
		else to[i]=to[i-1];
	}
	for(int i=1;i<=tot;i++)f[i]=i,s[i]=1;
	if(lk==rk){
		for(int i=1;i<=tot;i++){
			for(int j=find(i);j<=tot&&sum[j]-sum[i-1]<=rk;j++){
	//			cout<<i<<" "<<j<<" debug\n";
				merge(findRoot(i),findRoot(j));
			}
		}
	}
	else{
		for(int i=lk;i<=sum[tot];i++){
			if(vis[i])continue;
			int j=i;
			while(j<=sum[tot]){
//				cout<<"j="<<j<<"\n";
				vis[j]=1,merge(findRoot(i),findRoot(j));
				j-=lk-1;
//				cout<<"j="<<j<<"\n";
				vis[j]=1,merge(findRoot(i),findRoot(j));
				j+=lk;
			}
		}
//		return 0;
//		system("pause");
		q=read();
		for(int i=1;i<=q;i++){
			ux=read(),uy=read();
	//		cout<<"rx="<<findRoot(ux)<<" ry="<<findRoot(uy)<<"\n";
			bool flag=0;
//			cout<<"sx="<<sum[to[ux]]<<" sy="<<sum[to[uy]]<<" sn="<<sum[tot]<<"\n";
//			return 0;
			flag|=(findRoot(sum[to[ux]])==findRoot(sum[to[uy]]));
//			cout<<"flag="<<flag<<"\n";
			if(!a[ux]&&sum[to[ux]]+1<=sum[tot])flag|=(findRoot(sum[to[ux]]+1)==findRoot(sum[to[uy]]));
			if(!a[uy]&&sum[to[uy]]+1<=sum[tot])flag|=(findRoot(sum[to[ux]])==findRoot(sum[to[uy]]+1));
			if(!a[ux]&&sum[to[ux]]+1<=sum[tot]&&!a[uy]&&sum[to[uy]]+1<=sum[tot])flag|=(findRoot(sum[to[ux]]+1)==findRoot(sum[to[uy]]+1));
//			cout<<"i="<<i<<" "<<"flag="<<flag<<"\n";
//			if(i==267){
//				cout<<findRoot(501675)<<" "<<sum[to[ux]]<<" debug\n";
//		cout<<findRoot(547095)<<" "<<sum[to[uy]]<<" debug\n"; 
//		cout<<(findRoot(sum[to[ux]])==find(sum[to[uy]]))<<" debug\n";
//			}
//			if(i==267)return 0;
			if(flag)cout<<"Yes\n";
			else cout<<"No\n";
		}
		return 0;
	}
	q=read();
	for(int i=1;i<=q;i++){
		ux=to[read()],uy=to[read()];
//		cout<<"rx="<<findRoot(ux)<<" ry="<<findRoot(uy)<<"\n";
//		cout<<"sx="<<sum[ux]<<" sy="<<sum[uy]<<" sn="<<sum[tot]<<"\n";
//		return 0;
		if(findRoot(ux)==findRoot(uy))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
