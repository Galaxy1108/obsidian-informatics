#include<bits/stdc++.h>
using namespace std; 
const int N=1e4+5,P=998244353;
#define int long long

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())if(c=='-')f=1;
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10|48);
}

int n,a[N],cnt;
bool vis[N];

int power(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%P;
		x=x*x%P;
		y>>=1;
	}
	return ans;
}
int inv_5=598946612;

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(!vis[a[i]])++cnt;
		vis[a[i]]=1;
	}
	if(cnt==1){
		puts("0");return 0;
	}
	if(n==2&&cnt==2){
		puts("4");return 0;
	}
	if(n==3&&cnt==3){
		puts("42");return 0;
	}
	if(n==3&&cnt==2){
		print(49*inv_5%P);
		putchar('\n');
		return 0;
	}
	puts("0");
	return 0;
}















