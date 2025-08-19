#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
int n,a,b,c,d,k,ans,mio[N+5]={},p[N+5],tot=0;
bool flag[N+5]={};
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
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	mio[1]=1;
	for(int i=2;i<=N;i++){
		if(!flag[i])p[++tot]=i,mio[i]=-1;
		for(int j=1;j<=tot&&i*p[j]<=N;j++){
			flag[i*p[j]]=1;
			if(i%p[j]==0)break;
			mio[i*p[j]]=mio[i]*mio[p[j]];
		}
//		cout<<mio[i]<<" ";
	}
	n=read();
	while(n--){
		a=read(),b=read(),c=read(),d=read(),k=read(),ans=0;
		for(int i=a;i<=b;i++){
			for(int j=c;j<=d;j++)ans+=(k==__gcd(i,j));
		}
		print(ans),putchar('\n');
	}
	return 0;
}
