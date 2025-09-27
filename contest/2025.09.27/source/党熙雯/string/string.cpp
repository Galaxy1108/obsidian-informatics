#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
bool isri(string s)
{
	int l=s.size();
	for(int i=0;i<l-1;i++) if(s[i]==s[i+1]) return 0;
	return 1;
}
//int ans=0,k=0;
//void solve(string s)
//{
//	if(isri(s))
//	{
//		ans=min(ans,k);
//		return;
//	}
//	if(k>=ans) return ;
//	int se=k;
//	int l=s.size();
//	for(int i=1;i<l;i++)
//	{
//		if(s[i]==s[i-1])
//		{
//			p=i-1;
//			break;
//		}
//	}
//	string s1=s;
//	while(s[p]==s[p-1]||s[p]==s[p+1])
//	{
//		swap(s[p],s[p-1]);
//		k++;
//	}
//	solve(s);
//	while(s1[p]==s1[p-1]||s1[p]==s1[p+1])
//	{
//		swap(s[p],s[p+1]);
//	}
//	
//}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int c0=0,c1=0,c2=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='0') c0++;
		if(s[i]=='1') c1++;
		if(s[i]=='2') c2++;
	}
	if(c1>(l+1)/2||c2>(l+1)/2||c0>(l+1)/2)
	{
		cout<<-1;
		return 1;
	}
	int flag=0;
	for(int i=0;i<l-1;i++)
	if(s[i]==s[i+1]) flag=1;
	if(flag==0) 
	{
		cout<<0;
		return 1;
	}
	return 0;
}


