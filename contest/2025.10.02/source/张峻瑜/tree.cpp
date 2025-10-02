#include <bits/stdc++.h>
using namespace std;
//#define ll long long
int id,op,n,u,v,w,Q,l,r,k;
inline void decode(int &l, int &r, int &k, i64 lstans, int testop)
 {  
 	lstans %= 19260817;  
 	if(testop) 
 	{   
	 l ^= lstans;
  		l = (l % n + n) % n + 1;
     r ^= lstans; r = (r % n + n) % n + 1; 
	   if(l > r) std :: swap(l, r); 
	     k ^= lstans; 
		    k = (k % std :: min(r - l + 1, 100)) + 1;  
		}
 } 
 int cun[200005],fz[200005];
 int p[200005];
 priority_queue <int> du;
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	cin >> id;
	cin >> op >> n;
	for (int i = 1;i < n;i++)
	{
		cin >> u >> v >> w;
		if (u == 1)
		{
			cun[v]=w;
		}
		else
		{
			cun[u]=w;
		}
	}
	int hao;
	for (int i = 1;i <= n;i++)
	{
		cin >> p[i];
		if (p[i] == 1)
		{
			hao=i;
		}
	}
	cun[1]=0;
	cin >> Q;
	for (int i = 1;i <= Q;i++)
	{
		cin >> l >> r >> k;
		if (op == 1)
		{
			decode(l,r,k);
		}
		if (l > hao or hao > r)
		{
			cout << 0 << endl;
		}
		else
		{
			
			for (int i = l;i <= r;i++)
			{
				du.push(cun[p[i]]);
			}
			k--;
			int sum=0;
			while (k)
			{
				k--;
				sum+=du.top();
				du.pop();
			}
			cout << sum << endl;
		}
	}
	return 0;
 }
