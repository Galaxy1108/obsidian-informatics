#include <bits/stdc++.h>
using namespace std;
#define int long long
struct fenshu
{
	int fz,fm;
};
int gcd(int x,int y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y,x%y);
}
fenshu s;
fenshu ans[100005];
fenshu cun;
void add(fenshu a)
{
	int fz1=cun.fz,fz2=a.fz;
	int fm1=cun.fm,fm2=a.fm;
	int fm=fm1*fm2;
	int fz=fz2*fm1+fz1*fm2;
	int mo=gcd(fz,fm);
	fz/=mo;
	fm/=mo;
	cun.fz=fz;
	cun.fm=fm;
	return;
}
int pan(fenshu a,fenshu b)
{
	//int fz1=cun.fz,fz2=a.fz;
	int fm1=a.fm,fm2=b.fm;
	//int fm=fm1*fm2;
	int fz1=a.fz*fm2;
	int fz2=b.fz*fm1;
	if (fz1 == fz2)
	{
		return 0;
	}
	else if (fz1 > fz2)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
signed main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin >> s.fz  >> s.fm;
	//s.fz=a,s.fm=b;
	cun.fm=1;
	cun.fz=0;
	int lst=1,now=0;
	while (1)
	{
		now++;
		int l=lst+1,r=999999999,mid,as;
		while (l <= r)
		{
			//cout << now << endl;
			mid=(l+r)/2;
			fenshu huisu=cun;
			add({1,mid});
			ans[now]={1,mid};
			int fg=pan(cun,s);
			if (fg == 0)
			{
				cout << now << endl;
				for (int i = 1;i <= now;i++)
				{
					cout << ans[i].fm << " ";
				}
				
				return 0;
			}
			else if (fg == 1)
			{
				cun=huisu;
				ans[now]={0,0};
				l=mid+1;
			}
			else
			{
				cun=huisu;
				ans[now]={0,0};
				as=mid;
				r=mid-1;
			}	
		}
		add({1,as});
		ans[now]={1,as};
		lst=as+1;
	}
	return 0;
 } 
