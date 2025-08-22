#include<bits/stdc++.h>
using namespace std;
int t,n,q,l,r,x[100005],k,tx[100005];
void sol()
{
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>x[i];
	cin>>q;
	for(int tt = 1; tt <= q; tt++)
	{
		cin>>l>>r;
		k=r-l+1;
		for(int i = l; i <= r; i++)
		{
			tx[i-l]=x[i];
		}
		if(n<=20)
		{
			bool flg=0;
			for(int c = 1; c <= 10; c++)
			{
				for(int a = 0; a <= 10; a++)
				{
					for(int b = 0; b <= 10; b++)
					{
						for(int chk = 0; chk < k; chk++)
						{
							if((a*chk+b)/c!=tx[chk])
							{
								break;
							}
							if(chk==k-1)
							{
								flg=1;
								cout<<a<<" "<<b<<" "<<c<<endl;
							}
						}
						if(flg) break;
					}
					if(flg) break; 
				}
				if(flg) break;
			}
		}
		else
		{
			if(k==1) cout<<"0 "<<tx[0]<<" 1"<<endl;
			else cout<<tx[1]-tx[0]<<" "<<tx[0]<<" 1"<<endl;
		}
	}
	return;
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout); 
	cin>>t;
	while(t--) sol();
}
