#include<bits/stdc++.h>
using namespace std;
int ans[200005][15],anscnt,now[15],n,lss=0;
int main()
{
	srand(time(0));
	//freopen("constr.in","r",stdin);
	freopen("constr2.out","w",stdout);
	cin>>n;
	anscnt=0;
	lss=0;
	for(int i = 1; i <= n; i++) now[i]=i;
	for(int c = 1; c <= 3628800; c++)
	{
		if(c%10000==0) cerr<<c<<' '<<anscnt<<'\n';
		bool flg=1,nowflg;
		for(int i = lss; i <= anscnt; i++)
		{
			while(now[1]>ans[lss][1]+1) lss++;
			nowflg=1;
			for(int j = 1; j <= n; j++)
			{
				if(abs(now[j]-ans[i][j])>1)
				{
					nowflg=0;
					break;
				}
			}
			if(nowflg)
			{
				flg=0;
				break;
			}
		}
		if(flg&&rand()%200==0) flg=0;
		if(flg)
		{
			anscnt++;
			for(int i = 1; i <= n; i++)
			{
				ans[anscnt][i]=now[i];
			}
		}
		next_permutation(now+1,now+n+1);
	}
	cerr<<anscnt<<endl;
	for(int i = 1; i <= anscnt; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<'\n';
	}
 } 
