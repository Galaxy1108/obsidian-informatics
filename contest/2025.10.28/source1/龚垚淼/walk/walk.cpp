#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int a[200005],n;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		int x=read();
		a[i]=(x&1)?1:-1;
	}
	int sum=0,ans=0;
	for(int i=1;i<=n;++i){
		sum=max(0,sum+a[i]);
		ans=max(sum,ans);
	}
	int tot=0;
	for(int i=1;i<=n;++i){
		if(a[i]==1) tot++;
	}
	cout<<tot-ans;
	return 0;
}
