#include<bits/stdc++.h>
using namespace std;
int f[205][15][15][15],a[105],n;
//f {i,j,k,l} = Ê×¸öpos=i A-j,B-k,C-l 
char ch;
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>ch;
		a[i]=ch-'A'+1;
	}
	memset(f,0x3f,sizeof(f));
	int acnt=0,bcnt=0,ccnt=0;
	for(int i = 1; i <= 10; i++)
	{
		if(a[i]==1) acnt++;
		if(a[i]==2) bcnt++;
		if(a[i]==3) ccnt++;
	}
	f[11][acnt][bcnt][ccnt]=0;
	if(n<=10)
	{
		int ans=0;
		if(acnt!=0) ans++;
		if(bcnt!=0) ans++;
		if(ccnt!=0) ans++;
		cout<<ans<<endl;
		return 0;
	}
	for(int i = 11; i <= n+50; i++)
	{
		for(int j = 0; j <= 10; j++)
		{
			for(int k = 0; k <= 10; k++)
			{
				for(int l = 0; l <= 10; l++)
				{
					//a
					//if(f[i][j][k][l]<100000) cout<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k][l]<<endl;
					if(j+k+l>10) continue;
					acnt=0,bcnt=0,ccnt=0;
					for(int nn = i; nn <= i+j-1; nn++)
					{
						if(a[nn]==1) acnt++;
						if(a[nn]==2) bcnt++;
						if(a[nn]==3) ccnt++;
					}
					f[i+j][acnt][bcnt+k][ccnt+l]=min(f[i+j][acnt][bcnt+k][ccnt+l],f[i][j][k][l]+1);
					//b
					acnt=0,bcnt=0,ccnt=0;
					for(int nn = i; nn <= i+k-1; nn++)
					{
						if(a[nn]==1) acnt++;
						if(a[nn]==2) bcnt++;
						if(a[nn]==3) ccnt++;
					}
					f[i+k][acnt+j][bcnt][ccnt+l]=min(f[i+k][acnt+j][bcnt][ccnt+l],f[i][j][k][l]+1);
					acnt=0,bcnt=0,ccnt=0;
					for(int nn = i; nn <= i+l-1; nn++)
					{
						if(a[nn]==1) acnt++;
						if(a[nn]==2) bcnt++;
						if(a[nn]==3) ccnt++;
					}
					f[i+l][acnt+j][bcnt+k][ccnt]=min(f[i+l][acnt+j][bcnt+k][ccnt],f[i][j][k][l]+1);
					acnt=0,bcnt=0,ccnt=0;
					for(int nn = i; nn <= i+j+k-1; nn++)
					{
						if(a[nn]==1) acnt++;
						if(a[nn]==2) bcnt++;
						if(a[nn]==3) ccnt++;
					}
					f[i+j+k][acnt][bcnt][ccnt+l]=min(f[i+j+k][acnt][bcnt][ccnt+l],f[i][j][k][l]+2);
					acnt=0,bcnt=0,ccnt=0;
					for(int nn = i; nn <= i+j+l-1; nn++)
					{
						if(a[nn]==1) acnt++;
						if(a[nn]==2) bcnt++;
						if(a[nn]==3) ccnt++;
					}
					f[i+j+l][acnt][bcnt+k][ccnt]=min(f[i+j+l][acnt][bcnt+k][ccnt],f[i][j][k][l]+2);
					acnt=0,bcnt=0,ccnt=0;
					for(int nn = i; nn <= i+k+l-1; nn++)
					{
						if(a[nn]==1) acnt++;
						if(a[nn]==2) bcnt++;
						if(a[nn]==3) ccnt++;
					}
					f[i+k+l][acnt+j][bcnt][ccnt]=min(f[i+k+l][acnt+j][bcnt][ccnt],f[i][j][k][l]+2);
					acnt=0,bcnt=0,ccnt=0;
					for(int nn = i; nn <= i+j+k+l-1; nn++)
					{
						if(a[nn]==1) acnt++;
						if(a[nn]==2) bcnt++;
						if(a[nn]==3) ccnt++;
					}
					f[i+j+k+l][acnt][bcnt][ccnt]=min(f[i+j+k+l][acnt][bcnt][ccnt],f[i][j][k][l]+3);
				}
			}
		}
	}
	int anss=10000000;
	for(int i = n+1; i <= 200; i++)
	{
		anss=min(anss,f[i][0][0][0]);
	}
	cout<<anss<<endl;
}
