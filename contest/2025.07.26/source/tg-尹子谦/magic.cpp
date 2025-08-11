#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int n,q,a[N][N],maxt=-1;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>q;
	if(n<=2000)
	{
		
		for(int i=1;i<=n;i++) cin>>a[0][i];
		//±©Á¦ 
		for(int i=1;i<=n/2;i++)
		{
			int cnt=1,cnt1=1,cnt2=n/2+1;
			while(cnt1<=n/2&&cnt2<=n) 
			{
				if(a[i-1][cnt1]<a[i-1][cnt2]) a[i][cnt++]=a[i-1][cnt1++];
				else a[i][cnt++]=a[i-1][cnt2++];
			}
			while(cnt1<=n/2) a[i][cnt++]=a[i-1][cnt1++];
			while(cnt2<=n) a[i][cnt++]=a[i-1][cnt2++];
			bool b=0;
			for(int j=1;j<=n;j++) if(a[i][j]!=a[i-1][j]){b=1;break}
			if(!b){ maxt=i,break;} 
			//for(int j=1;j<=n;j++) cout<<a[i][j]<<' ';
			//cout<<endl;
		}
		while(q--)
		{
			int t,i;
			cin>>t>>i;
			t=min(t,maxt);
			cout<<a[t][i]<<endl;
		}
		return 0;
	}
	return 0;
}

