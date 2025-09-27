#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
inline int read(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	return x*f;
}
int asb(long long x){
	if(x<0) x*=-1;
	return x;
}
long long a[maxn],b[maxn],n,m,ans,o;
int main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	n=read(),m=read();
	if(m>n){
		for(int i=0;i<n;i++) b[i]=read();
		for(int i=0;i<m;i++) a[i]=read();
		swap(n,m);
	}
	else{
		for(int i=0;i<n;i++) a[i]=read();
		for(int i=0;i<m;i++) b[i]=read();
	}
	sort(a,a+n);sort(b,b+m);
	for(int i=0;i<m;i++) ans=max(ans,abs(a[i]-b[i]));
	for(int i=1,an;i<=n-m;i++){
		an=0;
		for(int j=0;j<m;j++){
			if(an>ans) {o++;break;}
			an=max(an,asb(a[i+j]-b[j]));
		}
		if(o) break;
		ans=an;
	}
	cout<<ans;
}
