#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	if(!(n&1))
	{
		cout<<"-1\n";
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++)cnt+=s[i]=='0';
	if(cnt!=(n+1)/2)
	{
		cout<<"-1\n";
		return 0;
	}
	cnt=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			ans+=abs(i-cnt*2);
			cnt++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
