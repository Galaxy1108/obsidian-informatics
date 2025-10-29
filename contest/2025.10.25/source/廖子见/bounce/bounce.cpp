#include<bits/stdc++.h>
#define N 1000000
#define M 20
using namespace std;
int n,q,opt,m,len,a[N+5],tcnt=0,f[N+5][M+5];
bool flag[M+5],vis[N+5];
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
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	for(int i=2;i<=M;i++)f[1][i]=1;
	for(int i=2;i<=N;i++){
		for(int j=2;j<=M;j++){
			int k=(i-1)/j+1;
			f[i][j]=i-k-f[i-k][j]+1+(i-k-f[i-k][j])/(j-1)+1;
		}
	}
//	cout<<"debug:"<<f[4][3]<<"\n";
	len=n=read(),q=read();
	vis[n+1]=1;
	for(int i=1;i<=n;i++)a[i]=i,vis[i]=1;
	while(q--){
		opt=read(),m=read();
		if(opt==1){
			if(flag[m])continue;
			flag[m]=1;
			int i=1;
			while(i<=n){
				vis[i]=0;
				i+=m;
			}
			len=0;
			for(int j=1;j<=n;j++){
				if(vis[j])a[++len]=j;
			}
		}
		else if(opt==2){
			if(tcnt>=20)continue;
			tcnt++;
			int i=1;
			while(!vis[i])i++;
			while(i<=n){
				vis[i]=0;
				int ucnt=0;
				while(ucnt<m&&i<=n)ucnt+=vis[++i];
			}
			len=0;
			for(int j=1;j<=n;j++){
				if(vis[j])a[++len]=j;
			}
		}
		else{
			if(len==0)print(-1);
			else print(a[f[len][m]]);
			putchar('\n');
		}
//		cout<<"i="<<q<<" vis:";
//		for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
//		cout<<"\n";
	}
	return 0;
}
