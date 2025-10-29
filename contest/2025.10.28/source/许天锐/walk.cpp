#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
const int N=200501;
int n,a[N],f[N],ans,suf1[N],suf2[N],pre1[N],pre2[N];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		a[i]=read();
		pre2[i]=pre2[i-1],pre1[i]=pre1[i-1];
		if(a[i]%2==0)pre2[i]++;
		else pre1[i]++;
	}
	ans=pre2[n];
	for(int i=n;i>=1;i--){
		suf2[i]=suf2[i+1],suf1[i]=suf1[i+1];
		if(a[i]%2==0)suf2[i]++;
		else suf1[i]++;
	}
	for(int i=1;i<=n;i++){
		f[i]=min(pre2[i-1],pre1[i-1])+suf2[i];
		f[i]=min(f[i],f[i-1]);
	}
	ans=min(ans,f[n]);
	for(int i=n;i>=1;i--){
		ans=min(ans,f[i]-(suf2[i]-suf1[i]));
	}
	cout<<ans<<endl;
	return 0;
}
