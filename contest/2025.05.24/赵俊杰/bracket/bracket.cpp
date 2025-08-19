#include<bits/stdc++.h>
using namespace std;
const int N=100005;
string s;
queue<int>id;
char c[N];
int f[N];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.size(),t=0,lst=0;
	for(int i=0;i<n;i++)
	{
		c[i]=s[i];
		if(s[i]=='*')
		{
			id.push(i);
			f[i]=t;
			continue;
		}
		if(s[i]==')')t--;
		else t++;
		if(t<0)
		{
			if(id.empty())
			{
				cout<<"No solution!\n";
				return 0;
			}
			c[id.front()]='(';
			id.pop();
			lst=i+1;
			t++;
		}
		f[i]=t;
	}
	int mn=f[n-1];
	for(int i=n-1;i>=lst;i--)
	{
		//cout<<i<<' '<<mn<<'\n';
		if(mn==0)break;
		if(c[i]=='*')
		{
			c[i]=')';
			if(i!=0)mn=min(mn-1,f[i-1]);
			t--;
		}
		else if(i!=0)mn=min(mn,f[i-1]);
	}
	if(t!=0)
	{
		cout<<"No solution\n";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]!='*')cout<<c[i];
	}
	cout<<'\n';
	return 0;
}
