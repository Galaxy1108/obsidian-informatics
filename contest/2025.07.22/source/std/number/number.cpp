#include <bits/stdc++.h>
using namespace std;
int n,m,L,R,x[300010];
long long f,ans;
multiset<int> S;
void solve()
{
	cin>>n>>m;
	f=0;
	multiset<int>().swap(S);
	for(int i=m;i;i--)
		cin>>x[i];
	L=R=0;
	for(int i=1;i<=m;i++)
	{
		f+=x[i];
		if((i+1)&1) R++;
		S.insert(x[i]);
		if(i>n&&((i-n)&1))
		{
			f-=2*(*S.begin());
			S.erase(S.begin());
			L++;
		}
		while(L+S.size()>R) S.erase(--S.end());
	}
	for(int g:S) if(g<0) f-=2*g;
	cout<<f<<"\n";
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}