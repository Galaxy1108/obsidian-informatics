#include<bits/stdc++.h>
using namespace std;
//bool ck[1000009];
struct zhta{
	bool gd;
	bool jo;
};
zhta ck[1000099];
int n,m,q;
int totj=0;
int gd;
inline int deel(zhta ckk[],int totjj)
{
	int toto=n-gd-totjj;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(i==n)
		{
			if(ckk[i].gd)
			{
				if(ckk[i].jo==ckk[i-1].jo)
				{
					break;
				}
				else
				{
					ans++;
					break;
				}
			}
			else
			{
				if(ckk[i-1].jo)
				{
					if(toto>0)
					{
						toto--;
						ckk[i].gd=1;
						ckk[i].jo=0;
					}
					else
					{
						totjj--;
						ckk[i].gd=1;
						ckk[i].jo=1;
					}
				}
				else
				{
					if(totjj>0)
					{
						totjj--;
						ckk[i].gd=1;
						ckk[i].jo=1;
					}
					else
					{
						toto--;
						ckk[i].gd=1;
						ckk[i].jo=0;
					}
				}
				break;
			}
		}
		if(ckk[i].gd)
		{
			if(ckk[i-1].jo==ckk[i].jo)
			{
				continue;
			}
			else
			{
				ans++;
			}
		}
		else
		{
			if(ckk[i+1].gd)
			{
				if(ckk[i+1].jo==ckk[i-1].jo)
				{
					if(ckk[i-1].jo)
					{
						if(toto>0)
						{
							toto--;
							ckk[i].gd=1;
							ckk[i].jo=0;
						}
						else
						{
							totjj--;
							ckk[i].gd=1;
							ckk[i].jo=1;
						}
					}
					else
					{
						if(totjj>0)
						{
							totjj--;
							ckk[i].gd=1;
							ckk[i].jo=1;
						}
						else
						{
							toto--;
							ckk[i].gd=1;
							ckk[i].jo=0;
						}
					}
				}
				else
				{
					if(toto>totjj)
					{
						ckk[i].gd=1;
						ckk[i].jo=0;
						toto--;
						ans++;
					}
					else
					{
						ckk[i].gd=1;
						ckk[i].jo=1;
						totjj--;
						ans++;
					}
				}
			}
			else
			{
				if(ckk[i-1].jo)
				{
					if(toto>0)
					{
						toto--;
						ckk[i].gd=1;
						ckk[i].jo=0;
					}
					else
					{
						totjj--;
						ckk[i].gd=1;
						ckk[i].jo=1;
					}
				}
				else
				{
					if(totjj>0)
					{
						totjj--;
						ckk[i].gd=1;
						ckk[i].jo=1;
					}
					else
					{
						toto--;
						ckk[i].gd=1;
						ckk[i].jo=0;
					}
				}
			}
		}
	}
	return ans;
}
inline int jc(zhta ckk[])
{
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(ckk[i].jo!=ckk[i-1].jo)
		{
			ans++;
		}
	}
	return ans;
}
/*inline int bfs(string a,zhta ckk[])
{
	unordered_map <string,int > ma;
	int tot=0;
	deque<string> de;
	de.push_back(a);
	ma[a]=1;
	while(!de.empty())
	{
		string cl=de.front();
		de.pop_front();
		for(int i=1;i<=n;i++)
		{
			
		}
	}
}*/
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	gd=m;
	for(int i=1;i<=n;i++)
	{
		int aa;
		cin>>aa;
		if(aa%2)
		{
			totj++;
		}
//		ck[i]=aa%2;
	}
	for(int i=1;i<=m;i++)
	{
		int aa,bb;
		cin>>aa>>bb;
		ck[aa].gd=1;
		ck[aa].jo=bb%2;
		totj-=ck[aa].jo;
	}
	for(int i=1;i<=q;i++)
	{
		short aa;
		cin>>aa;
		if(aa==1)
		{
			int k;
			cin>>k;
			ck[k].gd=0;
			gd--;
		}
		else
		{
			int kk,kkk;
			cin>>kk>>kkk;
			ck[kk].gd=1;
			ck[kk].jo=kkk%2;
			gd++;
		}
//		cout<<deel(ck,totj)<<endl;
//		string a;
//		int toto=n-gd-totj;
//		int totoo=toto;
//		int totjj=totj;
/*		while(totoo>0)
		{
			a.push_back('0');
			totoo--;
		}
		while(totjj>0)
		{
			a.push_back('1');
			totjj--;
		}*/
		cout<<deel(ck,totj)<<endl;
	}
	return 0;
}

