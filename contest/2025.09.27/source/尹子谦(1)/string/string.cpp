#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	int l=s.size();
	s=" "+s;
	for(int i=1;i<=l;i++) cnt[s[i]-'0']++;
	if(cnt[0]>(l-1)/2+1||cnt[1]>(l-1)/2+1||cnt[2]>(l-1)/2+1)
	{
		cout<<-1<<endl;
		return 0;
	}
	int ans=0;
	for(int i=1;i<l;i++)
	{
		if(s[i]==s[i-1])
		{
			int j=i+1;
			while(s[j]==s[i]&&j<=l) j++;
			if(j>l) break; 
			for(int p=j;p>i;p--) swap(s[p],s[p-1]),ans++;
			
		}
	}
	for(int i=l;i>=1;i--)
	{
		if(s[i]==s[i+1])
		{
			int j=i-1;
			while(s[j]==s[i]&&j>=1) j--;
			if(j<1) break;
			for(int p=j;p<i;p++) swap(s[p],s[p+1]),ans++;
		}
	}
	for(int i=1;i<=l;i++) if(s[i]==s[i-1]){cout<<-1;return 0;}
	cout<<ans;
	return 0;
} 
