#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
const int inf=2147483647;
int n,m,a[maxn],ans;
struct node {
	int l,r;
	bool isok;
}b[maxn];
inline int read() {
	int s=0,w=1; char ch=getchar();
	while (ch<'0' || ch>'9') w=(ch=='-')?-1:1, ch=getchar();
	while (ch>='0' && ch<='9') s=(s<<1)+(s<<3)+(ch^48), ch=getchar();
	return s*w;
}
int main() {
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	n=read(); m=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=1;i<=m;++i) {
		b[i].l=read(); 
		b[i].r=read();
		b[i].isok=1;
	}
	int cnt=m;
	while (cnt>0) {
//		cout<<cnt<<endl;
		int t1,t2,t3,t4,d1,d2,g1,g2;
		double minx=inf;
		for (int i=1;i<=n;++i) 
			for (int j=1;j<=m;++j) 
				if (a[i]>=b[j].l && a[i]<=b[j].r && b[j].isok) {
					b[j].isok=0;
					--cnt;
				}
		if (cnt<=0) break;
		for (int i=1;i<=n;++i) {
			for (int j=1;j<=m;++j) {
				if (!b[j].isok) continue;
				d1=abs(a[i]-b[j].l),d2=abs(a[i]-b[j].r),g1=0,g2=0;
				for (int k=1;k<=m;++k) {
					if (!b[k].isok) continue;
					if (b[j].l>=b[k].l && b[j].l<=b[k].r) {
						++g1;
					}
					if (b[j].r>=b[k].l && b[j].r<=b[k].r) 
						++g2;
				}
//				cout<<a[i]<<' '<<b[j].l<<' '<<a[i]<<' '<<b[j].r<<endl;
//				cout<<d1<<' '<<g1<<' '<<d2<<' '<<g2<<endl;
//				if (a[i]==2 && b[j].l==3) cout<<d1<<' '<<g1<<endl;
				double tmp1=(double)d1/(double)g1,tmp2=(double)d2/(double)g2;
//				cout<<tmp1<<' '<<tmp2<<endl;
				if (g1 && tmp1<minx) {
					minx=tmp1; t1=i; t2=b[j].l; t3=j; t4=d1;
				}
				if (g2 && tmp2<minx) {
					minx=tmp2; t1=i; t2=b[j].r; t3=j; t4=d2;
				}
			}
		}
//		for (int j=1;j<=m;++j) {
//			if (b[j].isok) cout<<b[j].l<<' '<<b[j].r<<endl;
//		}
//		cout<<a[t1]<<' '<<t2<<endl; cout<<minx<<endl;
		a[t1]=t2; ans+=t4;
//		cout<<cnt<<endl;
	}
	printf("%d",ans);
	return 0;
}
/*
4 11 
2 6 14 18 
0 3 
4 5 
11 15 
3 5 
10 13 
16 16 
1 4 
8 12 
17 19 
7 13 
14 19
*/
