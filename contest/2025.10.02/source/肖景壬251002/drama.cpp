#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],l[2000005],r[2000005],f[2200005][23],mxx[2000005],nl,nr,nf;
__int128 ans,tmp;
stack<int> st,emp;
void print(__int128 x)
{
	if(x<10)
	{
		cout<<(char)(x+'0');
		return;
	}
	print(x/10);
	cout<<(char)(x%10+'0');
	return;
}
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	a[0]=a[n+1]=-1;
	for(int i = 0; i <= n+1; i++)
	{
		while(!st.empty()&&a[st.top()]>a[i])
		{
			r[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	st=emp;
	for(int i = n+1; i >= 0; i--)
	{
		while(!st.empty()&&a[st.top()]>a[i])
		{
			l[st.top()]=i;
			st.pop();
		}
		st.push(i);
	}
	for(int i = 1; i <= n; i++)
	{
		f[0][i]=a[i];
	}
	for(int i = 1; i <= 21; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			f[i][j]=max(f[i-1][j],f[i-1][j+1<<(i-1)]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		nl=max(1,l[i]+1);
		nr=min(n,r[i]-1);
		nf=log2(nr-nl+1);
		//cout<<nr-nl+1<<" "<<nf<<" "<<nl<<" "<<nr-(1<<nf)+1<<endl;
		mxx[i]=max(f[nf][nl],f[nf][nr-(1<<nf)+1]);
		tmp=a[i]*mxx[i]*(nr-nl+1);
		if(ans<tmp) ans=a[i]*mxx[i]*(nr-nl+1);
		//cout<<a[i]*mxx[i]*(nr-nl+1)<<endl;
	}
	print(ans);
 } 
