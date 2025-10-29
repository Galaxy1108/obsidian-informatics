#include<bits/stdc++.h>
using namespace std;
const int N=110,M=1e9+7;
int n,a[N],m;
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	while(m--)
	{
		int op;
		cin>>op;
		int x,l,r;
		if(op==1) cin>>x,a[x]^=1;
		else
		{
			cin>>l>>r;
			int ans=0,s=0;
			for(int i=l;i<=r;i++)
			{
				s=0;
				for(int j=i;j<=r;j++)
				{
					if(a[j]==1) s++;
					int len=j-i+1,num1,num2;
					if(len%2==0) num1=num2=len/2;
					else num1=(len+1)/2,num2=(len-1)/2;
					if(s%2==0) ans++;
					else
					{
						if(s<=3+(num1-3)*2) ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
5
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
