#include <bits/stdc++.h>
using namespace std;
int f[100005];
int main()
{
	string s;
	cin>>s;
	s=' '+s;
	int n=s.size();
	string bf=s;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='(') continue;
		for(int j=i+1;j<n;j++)
		{
			if(s[j]=='(')
			{
				break;
			}
			if(s[j]==')')
			{
				s[i]=' ';
				s[j]=' ';
				break;
			}
		}
	}
	string v=s;
	for(int i=1;i<(int)v.size();i++)
	{
		if(v[i]=='*')
		{
			if(f[i-1]<0)
			{
				v[i]='(';
				bf[i]='(';
			}
		}
		if(v[i]=='(')
		{
			f[i]=f[i-1]+1;
		}
		if(v[i]==')')
		{
			f[i]=f[i-1]-1;
		}
		if(v[i]==' ')
		{
			f[i]=f[i-1];
		}
//		cout<<f[i]<<" ";
	}
	for(int i=0;i<(int)bf.size();i++)
	{
		if(bf[i]!=' ')
		{
			cout<<bf;
		}
	}
}
/*
((***)()((**
((  ))()(())
1 2 2 2 2 1 2 1 2 3 3 3


*/
