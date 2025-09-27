#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int cnt=0,c1=0,c2=0;
	bool fl=0;
	for(int i=0;i<s.size();i++)
	{
		if(i!=s.size()-1&&s[i]==s[i+1])
		{
			fl=1;
		}
		if(s[i]=='0') cnt++;
		if(s[i]=='1') c1++;
		if(s[i]=='2') c2++;
	}
	if(fl==0)
	{
		cout<<0;
		return 0;
	}
	int mx=max(max(cnt,c1),c2);
	if(mx<=(s.size()+1)/2)
	{
		int ans=0,tot=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!='0')
			{
				tot++;
				ans+=abs(i-tot*2 +1);
			}
		}
		cout<<ans;
	}
	else
	{
		cout<<-1;
	}
	
	
//	020001202 2
//	020100202 4
//	020102020 7
	
	return 0;
}
