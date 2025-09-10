#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[14][40][27][14][14],aa[10]={0,0,1,0,2,0,1,0,3,0},bb[10]={0,0,0,1,0,0,1,0,0,2},cc[10]={0,0,0,0,0,1,0,0,0,0},dd[10]={0,0,0,0,0,0,0,1,0,0};
int n,k,nd[20],tmp,ans[40][27][14][14],tota,totb,totc,totd,ans2[500005],anscnt,finfinans;
bool cmp(long long xx,long long yy)
{
	return xx>yy;
}
struct ppp
{
	int val,xa,xb;
};
operator <(const ppp &xx,const ppp &yy)
{
	return xx.val<yy.val;
}
priority_queue<ppp> pq;
signed main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	tmp=n;
	for(int i = 1; i <= 15; i++)
	{
		nd[i]=n%10;
		n/=10;
	}
	n=tmp;
	f[0][0][0][0][0]=1;
	for(int i = 0; i < 13; i++)
	{
		for(int acc = 0; acc <= 36; acc++)
		{
			for(int bcc = 0; bcc <= 24; bcc++)
			{
				for(int ccc = 0; ccc <= 12; ccc++)
				{
					for(int dcc = 0; dcc <= 12; dcc++)
					{
						for(int nc = 1; nc <= 9; nc++)
						{
							f[i+1][acc+aa[nc]][bcc+bb[nc]][ccc+cc[nc]][dcc+dd[nc]]+=f[i][acc][bcc][ccc][dcc];
						}
					}
				}
			}
		}
	}
	//f[0][0][0][0][0]=0;
	int flg=0;
	for(int i = 13; i >= 1; i--)
	{
		if(nd[i]!=0) flg=1;
		for(int j = 0; j < nd[i]; j++)
		{
			for(int acc = 0; acc <= 36; acc++)
			{
				for(int bcc = 0; bcc <= 24; bcc++)
				{
					for(int ccc = 0; ccc <= 12; ccc++)
					{
						for(int dcc = 0; dcc <= 12; dcc++)
						{
							ans[acc+tota+aa[j]][bcc+totb+bb[j]][ccc+totc+cc[j]][dcc+totd+dd[j]]+=f[i-1][acc][bcc][ccc][dcc];
						}
					}
				}
			}
		}
		if(flg&&nd[i]==0)
		{
			flg=2;
			break;
		}
		tota+=aa[nd[i]];
		totb+=bb[nd[i]];
		totc+=cc[nd[i]];
		totd+=dd[nd[i]];
	}
	if(flg!=2) ans[tota][totb][totc][totd]++;
	ans[0][0][0][0]--;
	for(int acc = 0; acc <= 39; acc++)
	{
		for(int bcc = 0; bcc <= 26; bcc++)
		{
			for(int ccc = 0; ccc <= 13; ccc++)
			{
				for(int dcc = 0; dcc <= 13; dcc++)
				{
					if(ans[acc][bcc][ccc][dcc])
					{
						anscnt++;
						ans2[anscnt]=ans[acc][bcc][ccc][dcc];
						//cout<<pow(2,acc)*pow(3,bcc)*pow(5,ccc)*pow(7,dcc)<<" "<<ans[acc][bcc][ccc][dcc]<<endl;
					}
				}
			}
		}
	}
	//cout<<anscnt<<endl;
	sort(ans2+1,ans2+anscnt+1,cmp);
	pq.push({ans2[1]*ans2[1],1,1});
	while(k--)
	{
		ppp fff=pq.top(),ggg;
		//cout<<fff.val<<" "<<fff.xa<<" "<<fff.xb<<endl; 
		pq.pop();
		finfinans+=fff.val;
		finfinans%=1000000007;
		pq.push({ans2[fff.xa]*ans2[fff.xb+1],fff.xa,fff.xb+1});
		if(fff.xb==1)
		{
			ggg.val=ans2[fff.xa+1]*ans2[fff.xb];
			ggg.xa=fff.xa+1;
			ggg.xb=fff.xb;
			pq.push(ggg);
			//cout<<ans2[fff.xa+1]*ans2[fff.xb]<<endl;
		}
	}
	cout<<finfinans<<endl;
}
