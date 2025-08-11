#include<bits/stdc++.h>
using namespace std;
bool f[1000005][4],ans[1000005];
int n,a[1000005],comefrom[1000005][4];
int main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		a[i]*=2;
	}
	a[n+1]=a[1];
	/*f[1][0]=1;
	f[1][1]=1;
	f[1][2]=1;
	f[1][3]=1;*/
	for(int nnn = 0; nnn <= 3; nnn++)
	{
		memset(f,0,sizeof(f));
		f[0][nnn]=1;
		
		//cout<<f[0][0]<<" "<<f[0][1]<<" "<<f[0][2]<<" "<<f[0][3]<<endl;
		for(int i = 1;i <= n; i++)
		{
			if((f[i-1][1]&(a[i]>=a[i+1])))
			{
				f[i][0]=1;
				comefrom[i][0]=1;
			}
			if((f[i-1][3]&(a[i]/2>=a[i+1])))
			{
				f[i][0]=1;
				comefrom[i][0]=3;
			}
			if((f[i-1][1]&(a[i]>=a[i+1]/2)))
			{
				f[i][1]=1;
				comefrom[i][1]=1; 
			} 
			if((f[i-1][3]&(a[i]>=a[i+1])))
			{
				f[i][1]=1;
				comefrom[i][1]=3;
			}
			if((f[i-1][0]&(a[i]<=a[i+1])))
			{
				f[i][2]=1;
				comefrom[i][2]=0;
			}
			if((f[i-1][2]&(a[i]/2<=a[i+1])))
			{
				f[i][2]=1;
				comefrom[i][2]=2;
			}
			if((f[i-1][0]&(a[i]<=a[i+1]/2)))
			{
				f[i][3]=1;
				comefrom[i][3]=0;
			}
			if((f[i-1][2]&(a[i]<=a[i+1])))
			{
				f[i][3]=1;
				comefrom[i][3]=2;
			}
			/*f[i][0]=(f[i-1][1]&(a[i]>=a[i+1]))|(f[i-1][3]&(a[i]/2>=a[i+1]));
			f[i][1]=(f[i-1][1]&(a[i]>=a[i+1]/2))|(f[i-1][3]&(a[i]>=a[i+1]));
			f[i][2]=(f[i-1][0]&(a[i]<=a[i+1]))|(f[i-1][2]&(a[i]/2<=a[i+1]));
			f[i][3]=(f[i-1][0]&(a[i]<=a[i+1]/2))|(f[i-1][2]&(a[i]<=a[i+1]));
			cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<" "<<f[i][3]<<endl;*/
		}
		//cout<<f[n][0]<<" "<<f[n][1]<<" "<<f[n][2]<<" "<<f[n][3]<<endl<<endl;
		if(f[n][nnn]==1)
		{
			int noww=nnn;
			for(int i = n; i >= 1; i--)
			{
				if(noww>=2) ans[i]=1;
				noww=comefrom[i][noww];
			}
			for(int i = 1; i <= n; i++)
			{
				cout<<(i+ans[i]-1)%n+1<<" ";
				//cout<<i+ans[i]<<" ";
			}
			cout<<endl;
			return 0;
		}
		f[0][nnn]=0;
	}
	cout<<"NIE"<<endl;
	return 0;
 } 
