#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001],b[100001];
int lu[1000001];
string x[1000001];
int len=0;
int tot=0;
void DFS(int s)
{
	if(s>n)
	{
		string str="";
		for(int i=1;i<=len;i++)
		{
			/*if(lu[i]<=26)
			{
				str+=(lu[i]-1+'a');
			}
			else
			{
				str+=(lu[i]-27+'A');
			}*/
			str+=(lu[i]+'A');
		}
		x[++tot]=str;
		return;
	}
	DFS(s+1);
	
	
	lu[++len]=a[s];
	DFS(s+1);
	len--;
}
bool cmp(string a,string b)
{
	int l1=a.size();
	int l2=b.size();
	for(int i=0;i=min(l1,l2)-1;i++)
	{
		if(a[i]<b[i])
		{
			return a<b;
		}
	}
	return l1<l2;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	string s="";
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		s+=(b[i]+'A');
	}
	DFS(1);
	int num[100001]; 
	srand(time(0));
	cout<<rand()%30+1;
}
/*
4 
1 2 4 1 
1 
2
*/
