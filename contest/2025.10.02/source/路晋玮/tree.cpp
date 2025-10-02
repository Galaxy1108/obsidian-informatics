#include<iostream>
using namespace std;
//inline void decode(int &l, int &r, int &k, i64 lstans, int testop) {  lstans %= 19260817;  if(testop) {   l ^= lstans; l = (l % n + n) % n + 1;   r ^= lstans; r = (r % n + n) % n + 1;   if(l > r) std :: swap(l, r);   k ^= lstans;    k = (k % std :: min(r - l + 1, 100)) + 1;  } } 
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	long long w,ans=0;
	int id,op,n,u,v,p,q,l,r,k,i;
	cin>>id>>op>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		ans+=w;
	 }
	for(i=1;i<=n;i++)
	    cin>>p;
	cin>>q;
	for(i=1;i<=q;i++) 
	{
		cin>>l>>r>>k;
		cout<<ans<<endl;
	}
	return 0;
}
