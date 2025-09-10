#include<bits/stdc++.h>
using namespace std;
int n,ra[2002],rb[2002];
int ans;
void dfs(vector <int> s,int c,int next,int lan)
{
	if(lan<ans)
	{
		if(next>n&&s.size()==0) ans=lan;
		else
		{
			if(s.size()==0)
			{
				s.push_back(next);
				lan+=abs(ra[next]-c)+1;
				c=ra[next];next++;
				dfs(s,c,next,lan);
			}
			else if(s.size()==4)
			{
				for(int i=0;i<4;i++)
				{
					int li=s[i];
					s.erase(s.begin()+i);
					dfs(s,rb[li],next,lan+abs(rb[li]-c)+1);
					s.insert(s.begin()+i,li);
				}
			}
			else
			{
				for(int i=0;i<s.size();i++)
				{
					int li=s[i];
					s.erase(s.begin()+i);
					dfs(s,rb[li],next,lan+abs(rb[li]-c)+1);
					s.insert(s.begin()+i,li);
				}
				if(next<=n)
				{
					s.push_back(next);
					lan+=abs(ra[next]-c)+1;
					c=ra[next];next++;
					dfs(s,c,next,lan);
				}
			}
		}
	}
}

int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ra[i]>>rb[i];
	}
	ans=10000000;
	vector <int> st;
	st.clear();
	dfs(st,1,1,0);
	cout<<ans;
	return 0;
}
