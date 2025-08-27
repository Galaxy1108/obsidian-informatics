#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int an,p,ary[N],av[N];
long long anslt;
vector<pair<int,int>>vec[N];
inline void ins(int x,int val){for(int i=0;i<vec[x].size();++i)av[vec[x][i].first]+=vec[x][i].second*val;}
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	cin>>an>>p;
	for(int ni=1;ni<=an;++ni)
	{
		int lin=ni;
		for(int i=2;i*i<=ni;++i)
		{
			int cnt=0;	
			while(lin%i==0)
			{
				lin/=i;
				cnt++;
			}
			vec[ni].push_back(make_pair(i,cnt));
		}
		if(lin>1)vec[ni].push_back(make_pair(lin,1));
	} 
	for(int n=1;n<=an;++n)
	{
		ins(n,n);
		for(int i=1;i<=n;++i)ins(i,-1);
		long long ans=1;
		for(int i=1;i<=n;++i)
		{
			long long res=1,avi=1;
			long long lav=av[i];
			while(lav)
			{
				lav--;
				avi*=i;
				avi%=p;
				res+=avi;
				res%=p;
			}
			ans=ans*res%p;
		}
		anslt=(anslt+ans)%p;
	}
	cout<<anslt;
	
	return 0;
} 
