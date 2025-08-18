#include <bits/stdc++.h>
using namespace std;
const int maxn=107;
int n,a[maxn],s1[maxn],s2[maxn],s3[maxn],ans;
inline int read() {
	int s=0,w=1; char ch=getchar();
	while (ch<'0' || ch>'9') w=(ch=='-')?-1:1, ch=getchar();
	while (ch>='0' && ch<='9') s=(s<<1)+(s<<3)+(ch^48), ch=getchar();
	return s*w;
}
int main() {
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) {
		char ch; cin>>ch;
		if (ch=='A') a[i]=1;
		else if (ch=='B') a[i]=2;
		else a[i]=3;
	}
	for (int i=1;i<=n;++i) {
		s1[i]=s1[i-1]+(a[i]==1);
		s2[i]=s2[i-1]+(a[i]==2);
		s3[i]=s3[i-1]+(a[i]==3);
//		cout<<i<<' '<<s1[i]<<' '<<s2[i]<<' '<<s3[i]<<endl;
	}
	int pre=0,i=10, nowa=0, nowb=0, nowc=0;
	bool flag=1;
	while (i) {
		int t1=s1[i]-s1[pre], t2=s2[i]-s2[pre], t3=s3[i]-s3[pre];
		nowa+=t1; nowb+=t2; nowc+=t3;
	//	cout<<i<<' '<<nowa<<' '<<nowb<<' '<<nowc<<endl;
		if (nowa>=nowb && nowa>=nowc) pre=i, i+=nowa, ++ans, nowa=0;
		else if (nowb>=nowa &&nowb>=nowc) pre=i, i+=nowb, ++ans, nowb=0;
		else if (nowc>=nowa && nowc>=nowb) pre=i, i+=nowc, ++ans, nowc=0;
		if (i>n &&flag) {
			i=n, flag=0;
		}
		if (i>n && !flag) {
			if (nowa) ++ans;
			if (nowb) ++ans;
			if (nowc) ++ans;
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
11
A
B
C
A
B
C
A
B
C
A
B
*/
