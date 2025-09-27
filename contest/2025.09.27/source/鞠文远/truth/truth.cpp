#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int n,k,m,t[50],ary[N];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)cin>>ary[i];
	while(m--)
	{
		int op,x,y;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			ary[x]=y;
		}
		if(op==2)
		{
			memset(t,0,sizeof(t));
			int l=-1,r=0,res=0x3f3f3f3f;
			while(true)
			{
				r++;
				t[ary[r]]++;
				if(r>n)break;
				while(true)
				{
					if(l+1>r)break;
					l++;
					t[ary[l]]--;
					bool pd=true;
					for(int i=1;i<=k;i++)
						if(t[i]<=0)
						{
							pd=false;
							break;
						}
					if(!pd)
					{
						t[ary[l]]++; 
						l--;
						break;
					}
				}
				if(l!=-1)res=min(res,r-l);
			}
			if(res>1e9)res=-1;
			cout<<res<<endl;
		}
	}
	
	
	return 0;
} 
