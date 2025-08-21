#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n,anslt,av,ary[N];
int main()
{
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ary[i];
	while(true)
	{
		int nsd=0,rl=0,rr=0,res=-1;
		double pdj=0;
		for(int l=1;l<=n;l++)
			for(int r=l+1;r<=n;r++)
			{
				if(ary[r]<ary[l])nsd++;
				int gc=0;
				for(int i=l+1;i<=r-1;i++)
					if(ary[i]>ary[r]&&ary[i]<ary[l])gc++;
					else gc--;
				if(ary[l]>ary[r])gc++;
				if(1.0*gc/(r-l+1)>pdj)res=gc,rl=l,rr=r,pdj=1.0*gc/(r-l+1);
			}
		if(!nsd)break;
		anslt+=(rr-rl)*2;
		swap(ary[rl],ary[rr]);
	}
	cout<<anslt;
	
	return 0;
} 
