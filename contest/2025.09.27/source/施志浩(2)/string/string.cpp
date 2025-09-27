#include<iostream>
#include<cstring>
using namespace std;
string s;
char n[401];
int a=0,b=0,c=0,l,i,j,cnt=0;
bool flag=1;
int main()
{
	ios::sync_with_stdio(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>s;
	l=s.length();
	for(i=0;i<l;i++)
	{
		if(s[i]=='0')
			a++;
		if(s[i]=='1')
			b++;
		if(s[i]=='2')
			c++;
		if(s[i]==s[i-1])
		{
			flag=0;
		}
	}
//	cout<<a<<" "<<b<<" "<<c<<" "<<l%2<<'\n';
	if(flag==1)
	{
		cout<<0;
	}
	else if(((a+b<c||a+c<b||c+b<a)&& l%2==0)||((a+b+1<c||a+c+1<b||c+b+1<a)&& l%2==1))
	{
		cout<<-1;
	}
	else
	{
		for(i=0;i<l;i++)
		{
			if(s[i]==s[i-1])
			{
				for(j=i+1;j<l;j++)
				{
					if(s[j]!=s[i])
					{
						char cu=s[j];
						s[j]=s[i];
						s[i]=cu;
						cnt+=j-i;
						break;
					}
				}
			}
		}
		cout<<cnt;	
	}
	return 0;
}

/*
0101020002

00001122

*/
