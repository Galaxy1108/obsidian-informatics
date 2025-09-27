#include<bits/stdc++.h>
using namespace std;
/*
struct QJ{
int num;
int be;
int en;
};
int qd[50000];
deque <QJ> de;
*/
int a[100009];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	int n,kk,m;
	cin>>n>>kk>>m;
	bool boo[50];
	int toto=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int kl;
		cin>>kl;
		if(kl==1)
		{
			int aa,bb;
			cin>>aa>>bb;
			a[aa]=bb;
		}
		else
		{
			int ans=0x3f3f3f3f;
			int flag=0;
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=j;k++)
				{
					bool bo[50];
					memset(bo,0,sizeof(bo));
					int tot=0;
					for(int koko=k;koko<=j;koko++)
					{
						if(bo[a[koko]]==0)
						{
							bo[a[koko]]=1;
							tot++;
						}
					}
//				cout<<j<<" "<<k<< " "<<tot<<endl<<"--------------------"<<endl;
					if(tot==kk)
					{
						ans=min(ans,j-k+1);
						flag=1;
//						cout<<tot<<" "<<k<<"jinru"<<endl;
					}
				}
			}
			if(flag==0)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<ans<<endl;
			}
		}
//		cout<<"------------------------------------------"<<endl;
	}
	/*
	int ks=0;
	for(int i=1;i<=n;i++)
{
	cin>>a[i];
	if(i==1)
	{
	de.push_back({a[i],i,i});
	ks++;
	}
	else
{
	if(a[i]==a[i-1])
{
	de[ks].en++;
	}
	else
{
	de.push_back({a[i],i,i});
	ks++;
	}
	}
	}
	for(int i=0;i<de.size();i++)
{
	qd[i]=de[i].be;
	}
	for(int i=1;i<=m;i++)
{
	int kl;
	cin>>kl;
	if(kl==1)
{
	int ko;
	cin>>ko;
	
	}
	}
	*/
	return 0;
}
/*
---INFORMATIONS---
TIME:2025-09-27 10:50:31
*/
