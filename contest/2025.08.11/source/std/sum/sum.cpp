#include <bits/stdc++.h>
using namespace std;
void get_min(long long &a,long long b){if(a>b) a=b;}
long long S,K,N;
int d;
long long f[110],v[110];
void solve()
{
	cin>>S>>K;
	N=(S-1)>>1;
	if(K>N) return cout<<"-1\n",void();

	memset(f,0x3f,sizeof(f));
	d=1;
	while(S%d==0) d++;
	f[0]=0;

	while(1)
	{
		for(int i=0;i<d;i++)
		{
			v[i]=1;
			for(int j=1;j<d;j++) if(i*j<=S&&f[(S-i*j)%d]<=S)
				v[i]=max(v[i],(S-f[(S-i*j)%d])/j+1);
			while(v[i]%d!=i) v[i]++;
		}

		int id=-1;
		for(int i=1;i<d;i++) if(v[i]<f[i])
		{
			if(id==-1||v[i]<v[id])
				id=i;
		}

		if(id==-1) break;

		f[id]=v[id];

		for(int i=0;i<d;i++)
		for(int j=1;j<d;j++) if(S/v[id]>=j)
			get_min(f[(i+j*id)%d],f[i]+j*v[id]);
	}
	
	long long L=1,R=S-1,mid,ans,cnt;
	while(L<=R)
	{
		mid=(L+R>>1);cnt=0;
		for(int i=0;i<d;i++) if(mid>=f[i])
			cnt+=(mid-f[i])/d+1;
		if(cnt>K) ans=mid,R=mid-1;
		else L=mid+1;
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int T;cin>>T;
	while(T--) solve();
	return 0;
}