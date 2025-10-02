#include<iostream>
using namespace std;
int id,op,n;
inline void decode(int &l, int &r, int &k, int lstans, int testop) 
{  
	lstans %= 19260817;  
	if(testop) 
	{   
		l ^= lstans; 
		l = (l % n + n) % n + 1;   
		r ^= lstans; r = (r % n + n) % n + 1;   
		if(l > r) swap(l, r);   
		k ^= lstans;    
		k = (k % std :: min(r - l + 1, 100)) + 1;  
	} 
} 
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>id;
	if(id>10)
		cout<<"Fuck_CCF";
	else
	{
		while(1)
		{
			cout<<"ÎÒ²»»á£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡"; 
		}
	}
	return 0;
}
