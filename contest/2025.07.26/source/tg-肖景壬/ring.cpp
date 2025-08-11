#include<bits/stdc++.h> 
using namespace std;
#define int long long
int m[50005],n,f[50005],tmp[50005],cnt,ans,xx,nmin,tmp2[50005],finans=10000000000000000;
vector<int> v[50005];
int calc(int st,int en,int id)
{
	if(id==n)
	{
		cnt=0;
		for(int l = st; l <= m[n]; l++)
		{
			cnt++;
			tmp[cnt]=v[n][l];
		}
		for(int l = 1; l <= en; l++)
		{
			cnt++;
			tmp[cnt]=v[1][l];
		}
		tmp[cnt+1]=0;
		tmp[cnt+2]=2000000;
		cnt+=2;
		sort(tmp+1,tmp+cnt+1);
		ans=0;
		for(int l = 1; l < cnt; l++)
		{
			ans+=(tmp[l+1]-tmp[l])*(tmp[l+1]-tmp[l]);
		}
		return ans;
	}
	else
	{
		cnt=0;
		for(int l = st; l <= m[id]; l++)
		{
			cnt++;
			tmp[cnt]=v[id][l];
		}
		for(int l = 1; l <= en; l++)
		{
			cnt++;
			tmp[cnt]=v[id+1][l];
		}
		tmp[cnt+1]=0;
		tmp[cnt+2]=2000000;
		cnt+=2;
		sort(tmp+1,tmp+cnt+1);
		ans=0;
		for(int l = 1; l < cnt; l++)
		{
			ans+=(tmp[l+1]-tmp[l])*(tmp[l+1]-tmp[l]);
			//cout<<tmp[l]<<" ";
		}
		return ans;
	}
}
signed main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>m[i];
		v[i].push_back(0);
		for(int j = 1; j <= m[i]; j++)
		{
			cin>>xx;
			v[i].push_back(xx); 
		}
	} 
	//cout<<calc(2,2,1);
	for(int xxx = 1; xxx <= m[n]; xxx++)
	{
		for(int j = 0; j < m[1]; j++)
		{
			f[j]=calc(xxx,j,n);
		}
		for(int i = 2; i < n; i++)
		{
			for(int j = 0; j < m[i]; j++)
			{
				nmin=10000000000000000;
				for(int k = 0; k < m[i-1]; k++)
				{
					nmin=min(nmin,f[k]+calc(k+1,j,i-1));
				}
				tmp2[j]=nmin;
			}
			for(int j = 0; j < m[i]; j++)
			{
				f[j]=tmp2[j];
			}
		}
		nmin=10000000000000000;
		for(int k = 0; k < m[n-1]; k++)
		{
			nmin=min(nmin,f[k]+calc(k+1,xxx-1,n-1));
		}
		finans=min(finans,nmin);
	}
	cout<<finans<<endl;
}
