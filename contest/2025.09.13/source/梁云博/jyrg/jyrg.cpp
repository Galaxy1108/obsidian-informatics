#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n;
int a[N],b[N];
bool down(vector<int>v)
{
	for(int i=0;i<v.size()-1;i++)if(v[i+1]>v[i])return 0;
	return 1;
}

struct T{
	int cnt;
	vector<int>v;
};

int book[205][250][205];

bool check(int mid)
{
	memset(book,0,sizeof(book));
	queue<T>q;
	vector<int>st(3);
	st[0]=a[1],st[1]=a[1],st[2]=a[2];
	q.push({0,st});
	book[a[1]][a[2]][a[3]]=0;
	while(!q.empty())
	{
		auto cur=q.front();
		q.pop();
		if(cur.cnt>15)return 0;
		if(down(cur.v))
		{
			return 1;
		}
		vector<int>xx=cur.v;
		swap(xx[1],xx[2]);
		xx[1]--,xx[2]++;
		if(!book[xx[0]][xx[1]][xx[2]])
		{
			book[xx[0]][xx[1]][xx[2]]=1;
			q.push({cur.cnt+1,xx});
		}
		vector<int>yy=cur.v;
		swap(yy[1],yy[0]);
		yy[0]--,yy[1]++;
		if(!book[yy[0]][yy[1]][yy[2]])
		{
			book[yy[0]][yy[1]][yy[2]]=1;
			q.push({cur.cnt+1,yy});
		}
	}
}
int main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=0,r=10,res=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))
			{
				r=mid-1;
				res=mid;
			}
			else l=mid+1;
		}
		cout<<res<<"\n";
	}
	return 0;
 } 
