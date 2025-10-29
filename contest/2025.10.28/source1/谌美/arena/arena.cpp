#include <bits/stdc++.h>
using namespace std;
const int maxn=507;
const int mod=998244353;
int n,x,a[maxn],b[maxn],cnt,maxx=0;
inline int read() {
	int s=0,w=1; char ch=getchar();
	while (ch<'0' || ch>'9') w=(ch=='-')?-1:1, ch=getchar();
	while (ch>='0' && ch<='9') s=(s<<1)+(s<<3)+(ch^48), ch=getchar();
	return s*w;
}
inline void sub2() {
	for (int i=1;i<=x;++i) {
		a[1]=i;
		for (int j=1;j<=x;++j) {
			a[2]=j;
//			for (int k=1;k<=n;++k) cout<<a[k]<<' ';
//			cout<<endl;
			for (int k=1;k<=n;++k) b[k]=a[k];
			sort(b+1,b+n+1);
			int k=1;
			while (k<n) {
				if (b[n]<=0) break;
				if (b[k]>0) {
					int tmp=b[k]/(n-k);
					if (b[k]%(n-k)) ++tmp;
					for (int l=k;l<=n;++l) 
						b[l]-=(n-k)*tmp; 
				}
				++k;
			}
			if (b[n]>0) continue;
			cnt=(cnt+1)%mod;
		}
//		a[1]=0;
	}
}
inline void sub3() {
	for (int i=1;i<=x;++i) {
		a[1]=i;
		for (int j=1;j<=x;++j) {
			a[2]=j;
			for (int m=1;m<=x;++m) {
				a[3]=m;
				for (int k=1;k<=n;++k) b[k]=a[k];
				sort(b+1,b+n+1);
				int k=1;
				while (k<n) {
					if (b[n]<=0) break;
					if (b[k]>0) {
						int tmp=b[k]/(n-k);
						if (b[k]%(n-k)) ++tmp;
						for (int l=k;l<=n;++l) 
							b[l]-=(n-k)*tmp; 
					}
					++k;
				}
				if (b[n]>0) continue;
				cnt=(cnt+1)%mod;
			}
		}
	}	
}
inline void sub4() {
	for (int i=1;i<=x;++i) {
		a[1]=i;
		for (int j=1;j<=x;++j) {
			a[2]=j;
			for (int m=1;m<=x;++m) {
				a[3]=m;
				for (int o=1;o<=x;++o) {
					a[4]=o;
					for (int k=1;k<=n;++k) b[k]=a[k];
					sort(b+1,b+n+1);
					int k=1;
					while (k<n) {
						if (b[n]<=0) break;
						if (b[k]>0) {
							int tmp=b[k]/(n-k);
							if (b[k]%(n-k)) ++tmp;
							for (int l=k;l<=n;++l) 
								b[l]-=(n-k)*tmp; 
						}
						++k;
					}
					if (b[n]>0) continue;
					cnt=(cnt+1)%mod;
				}
			}
		}
	}
}
inline void sub5() {
	for (int i=1;i<=x;++i) {
		a[1]=i;
		for (int j=1;j<=x;++j) {
			a[2]=j;
			for (int m=1;m<=x;++m) {
				a[3]=m;
				for (int o=1;o<=x;++o) {
					a[4]=o;
					for (int p=1;p<=x;++p) {
						a[5]=p;
						for (int k=1;k<=n;++k) b[k]=a[k];
						sort(b+1,b+n+1);
						int k=1;
						while (k<n) {
							if (b[n]<=0) break;
							if (b[k]>0) {
								int tmp=b[k]/(n-k);
								if (b[k]%(n-k)) ++tmp;
								for (int l=k;l<=n;++l) 
									b[l]-=(n-k)*tmp; 
							}
							++k;
						}
						if (b[n]>0) continue;
						cnt=(cnt+1)%mod;
					}		
				}
			}
		}
	}
}
int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(); x=read();
	if (n==2) sub2();
	if (n==3) sub3();
	if (n==4) sub4();
	if (n==5) sub5();
	printf("%d",cnt);
	return 0;
}
