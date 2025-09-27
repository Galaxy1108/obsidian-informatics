#include<iostream>
#include<cstring>
using namespace std;
int a[50005],v[35];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	int n,m,op,k,p,x,minl,cnt,i,j,h,t;
	cin>>n>>k>>m;
	for(i=1;i<=n;i++)
	    cin>>a[i];
	for(i=1;i<=m;i++)
	{
		cin>>op;
		if(op==1)
		{
			cin>>p>>x;
			a[p]=x;
		}
		else
		{
			cnt=0;
			memset(v,0,sizeof(v));
			t=1;
			minl=54188;
			for(h=1;h<=n;)
			{
				if(t>n&&cnt<k)
				    break;
				while(cnt<k&&t<=n)
				{
					v[a[t]]++;
					if(v[a[t]]==1)
					   cnt++;
					t++;
				}
				while(cnt==k&&h<t)
				{
					minl=min(minl,t-h);
					v[a[h]]--;
					if(v[a[h]]==0)
					    cnt--;
					h++;
				}
			}
			if(minl==54188)
			    cout<<-1<<endl;
			else
			    cout<<minl<<endl;
		}
	}
	return 0;
}
