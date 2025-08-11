#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	if(k==1)
	{
		for(int i=1;i<s.size();i++)
		{
			int j=i;
			while(s[j-1]=='B' and s[j]=='A')
			{
				swap(s[j-1],s[j]);
				ans++;
				j--;
				if(j==0)
				{
					break;
				}
			}
		}
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
