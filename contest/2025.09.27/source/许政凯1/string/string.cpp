#include<bits/stdc++.h>
using namespace std;

string s;
bool flag=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==s[i-1])
		{
			flag=1;
			break;
		}
	}
	if(flag==0) cout<<0;
	else cout<<-1;
	return 0; 
}
