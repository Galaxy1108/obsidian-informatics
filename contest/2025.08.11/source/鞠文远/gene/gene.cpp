#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,l,r,anslt=0x3f3f3f3f,ary[N],cnt[N],sec[N],fir[N],lst[N],slt[N];
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>ary[i];
		cnt[ary[i]]++;
		if(sec[ary[i]]==-1)sec[ary[i]]=i;
		if(!sec[ary[i]])sec[ary[i]]=-1;
		if(!fir[ary[i]])fir[ary[i]]=i;
		lst[ary[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		if(slt[ary[i]]==-1)slt[ary[i]]=i;
		if(!slt[ary[i]])slt[ary[i]]=-1;
	}
	for(int i=l-1;i>=1;i--)
	{
		if(fir[ary[i]]!=i)continue;
		int pd=sec[ary[i]]-1;
		if(sec[ary[i]]==-1)pd=n+1;
		if(pd<=r)continue;
		for(int j=r+1;j<=pd;j++)
		{
			if(lst[ary[j]]!=j)continue;
			if(slt[ary[j]]>=i)continue;
			anslt=(j-i+1);
			break;
		}
		break;
	}
	if(anslt==0x3f3f3f3f)anslt=-1;
	cout<<anslt;
	
	return 0;
} 
