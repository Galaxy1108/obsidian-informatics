#include <bits/stdc++.h>
#define int long long
#define P 9999973
using namespace std;
int n,m;
int cnt;
int book[105];//��j����x�� 
void Mobius(int p,int st,int vis)
{
	if(p==n+1)
	{
		cnt++;
		cnt%=P;
		return;
	}
	if(!vis)Mobius(p+1,1,0);//��ѡ����һ�е����� 
	for(int i=st;i<=m;i++)
	{
		if(book[i]==2 || i==vis)continue;		
		book[i]++;
		if(!vis)
		{
			Mobius(p,i+1,i);
		}
		Mobius(p+1,1,0);//����һ�� 
		book[i]--;
	}
}
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	if(n>m)swap(n,m);
	Mobius(1,1,0); 
	cout<<cnt;
	return 0;
} 
