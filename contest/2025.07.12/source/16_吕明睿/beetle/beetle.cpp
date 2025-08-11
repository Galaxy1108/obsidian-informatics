#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>>q;
long long n,k,s[2500001],f[2500001],ppow[2500001];
long long ans;
void read(long long &x) {
	bool neg = false;
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-') neg = true;
		ch = getchar();
	}
	if (neg) {
		while (ch >= '0' && ch <= '9') {
			x = x * 10 + ('0' - ch);
			ch = getchar();
		}
	} else {
		while (ch >= '0' && ch <= '9') {
			x = x * 10 + (ch - '0');
			ch = getchar();
		}
	}
}
long long fpow(long long x, long long y, long long p) {
	if(ppow[y])return ppow[y];
	if(y==0)return ppow[y]=1;
	long long tmp=fpow(x,y/2,p);
	tmp*=tmp;
	tmp%=p;
	if(y%2)tmp*=x;
	tmp%=p;
	return ppow[y]=tmp;
}
int main() {
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	read(n);
	read(k);
	for(int i=1; i<=n; i++) {
		read(s[i]);
		while(!q.empty()&&q.back().first<=s[i])q.pop_back();
		while(!q.empty()&&q.front().second<=i-k)q.pop_front();
		q.push_back({s[i],i});
		f[i]=q.front().first;
		if(i-k>0)f[i]+=f[i-k];
		f[i]%=1000000007;
	}
	for(int i=1; i<=n; i++)ans+=f[i]*fpow(23,n-i,1000000007),ans%=1000000007;
	cout<<ans;
	return 0;
}
