#include<iostream>
using namespace std;
int ch[405],sub[405];
int cnt0;
bool flag=1;
int pos,neg,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=1;i<=n;i++)
	{
		ch[i]=s[i-1]-'0';
		if(ch[i]==0) cnt0++;
		sum+=ch[i];
	}
	for(int i=1;i<=n;i++)
	{
		sub[i]=ch[i]-ch[i-1];
	}
	if(cnt0>(n-1)/2+1)
	{
		cout<<-1;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(ch[i]==ch[i-1]) flag=0;
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(sub[i]>=0)
		{
			pos+=sub[i];
		}
		else
		{
			neg+=sub[i];
		}
	}
	cout<<max(pos,abs(neg));
	return 0;
}
