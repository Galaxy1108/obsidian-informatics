#include<bits/stdc++.h>
using namespace std;
long double p[1005][1005];
double ans;
int n,m;
int main()
{
	cin>>n>>m;
	p[n][m]=1;
	for(int i = n; i >= 0; i--)
	{
		for(int j = m; j >= 0; j--)
		{
			if(i==0&&j==0) break;
			ans+=p[i][j]*(1.0*i/(i+j));
			//cout<<i<<" "<<j<<" "<<ans<<" "<<p[i][j]<<endl; 
			if(j>2&&i>0)
			{
				if(j-2>=0&&i>0) p[i-1][j-2]+=p[i][j]*(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1))*(1.0*i/(i+j-2));
				if(j-3>=0) p[i][j-3]+=p[i][j]*(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1))*(1.0*(j-2)/(i+j-2));
				//if(i==4&&j==3) cout<<"kjhgdkihsdf "<<(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1))<<endl;
			}
			else if(j==2&&i>0)
			{
				p[i-1][j-2]+=p[i][j]*(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1));
				//cout<<"pp"<<i<<" "<<j<<" "<<p[i][j]*(1.0*j/(i+j))*(1.0*(j-1)/(i+j-1))<<endl;
			}
		}
	}
	printf("%.9lf",ans);
}
