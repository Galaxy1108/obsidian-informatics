#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=2e6+10;
int n,sn[N],k;
bool iff=0;
void solve()
{
	if(iff==0)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>sn[i];
		iff=1;
	}
	else
	{
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int a,b;
			cin>>a>>b;
			sn[a]=b;
		}
	}
	int flag=0,ans;
	set<pair<int,int>> st;
	for(int i=1;i<=n;i++) st.insert({sn[i],i});
	while(true)
	{
		if(st.size()==2)
		{
			st.erase(st.begin());
			if(flag)
			{
				if((flag-st.size())%2)
				{
					ans=flag+1;
				}
				else ans=flag;
			}
			else ans=1;
			break;
		}
		int minn=st.begin()->first;
		st.erase(st.begin());
		auto it=st.end();
		it--;
		int maxx=it->first,id=it->second;
		st.erase(it);
		st.insert({maxx-minn,id});
		if(st.begin()->second!=id) 
		{
            if(flag) 
			{
                if((flag-st.size())%2) 
				{
                    ans=flag+1;
                } 
				else 
				{
                    ans=flag;
                }
                break;
			}
        } 
		else 
		{
            if(flag==0) flag=st.size();
        }
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
