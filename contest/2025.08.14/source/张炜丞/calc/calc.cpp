#include<bits/stdc++.h>
using namespace std; 
const int N=1e4+5;
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

int n,p,ans[N];

void work(int x){
	int y=1;
	ans[x]=-1;
	for(int i=1;i<=p;++i){
		y=y*x%p;
		if(y*y%p==1){
			ans[x]=i;return;
		}
	}
} 

signed main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	n=read();p=read();ans[0]=1;ans[1]=-1;
	for(int i=2;i<=p;++i)work(i);
	for(int i=1;i<=n;++i){
		int v=read();
		if(p==2)puts("-1");
		else if(p==3){
			if(v%p<=1)puts("-1");
			else puts("2");
		}
		else {
			print(ans[v%p]);putchar('\n');
		}
	}
	return 0;
}


















