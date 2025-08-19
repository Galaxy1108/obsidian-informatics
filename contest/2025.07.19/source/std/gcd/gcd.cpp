#include <bits/stdc++.h>
using namespace std;
vector<int> prim;
bool vis[1000010];
int mu[1000010],Smu[1000010];
long long calc(int n,int m,int k)
{
	long long ret=0;
	n/=k,m/=k;
	int lim=min(n,m);
	for(int l1=1,l2=1,r1,r2;l1<=lim&&l2<=lim;)
	{
		r1=n/(n/l1),r2=m/(m/l2);
		ret+=1ll*(n/l1)*(m/l2)*(Smu[min(r1,r2)]-Smu[max(l1,l2)-1]);
		if(r1==r2) l1=r1+1,l2=r2+1;
		else if(r1<r2) l1=r1+1;
		else l2=r2+1;
	}
	return ret;
}
int a,b,c,d,k;
void solve()
{
	cin>>a>>b>>c>>d>>k;
	cout<<calc(b,d,k)+calc(a-1,c-1,k)-calc(b,c-1,k)-calc(a-1,d,k)<<"\n";
}
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	mu[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i]) prim.push_back(i),mu[i]=-1;
		for(int j:prim)
		{
			if(i*j>1000000) break;
			vis[i*j]=true,mu[i*j]=mu[i]*mu[j];
			if(i%j==0){mu[i*j]=0;break;}
		}
	}
	for(int i=1;i<=1000000;i++)
		Smu[i]=Smu[i-1]+mu[i];

	int T;cin>>T;
	while(T--) solve();
	return 0;
}