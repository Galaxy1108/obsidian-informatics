#include<bits/stdc++.h>
using namespace std;
int a[100005],now[100005],ans,n;
struct pp
{
	int b[15];
};
pp tmp;
int sh(pp x)
{
	int ret=0;
	for(int i = 1; i <= n; i++)
	{
		ret*=131;
		ret+=x.b[i];
		ret%=998243;
	}
	return ret;
}
map<int,int> m;
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= 2*n; i++)
	{
		cin>>a[i];
		now[i]=i;
	}
	bool flg=0;
	do
	{
		flg=1;
		for(int i = 1; i <= 2*n; i++)
		{
			if(a[i]!=-1&&now[i]!=a[i])
			{
				flg=0;
				break;
			}
		}
		if(flg)
		{
			//cout<<"ds";
			for(int i = 1; i <= n; i++)
			{
				tmp.b[i]=min(now[2*i],now[2*i-1]);
				//cout<<tmp.b[i]<<" ";
			}
			//cout<<sh(tmp)<<endl;
			m[sh(tmp)]=1;
		}
	}while(next_permutation(now+1,now+2*n+1));
	cout<<m.size();
}
