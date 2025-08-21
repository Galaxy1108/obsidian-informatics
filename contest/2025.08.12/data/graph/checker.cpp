#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int T;
int n,m,u,v;
map<pair<int,int>,int> G;
pair<int,int> tmp;
int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
//	registerLemonChecker(argc, argv);
	
	T=inf.readInt();
	while(T--)
	{
		map<pair<int,int>,int>().swap(G);

		n=inf.readInt();m=inf.readInt();
		for(int i=1;i<=m;i++)
		{
			u=inf.readInt(),v=inf.readInt();
			if(u>v) swap(u,v);
			G[make_pair(u,v)]++;
		}

		u=ouf.readInt();
		if(u==-1) quitf(_wa,"Wrong Answer!");
		v=ouf.readInt();
		if(u==v) quitf(_wa,"Wrong Answer!!");

		int k=(m+n-2)/(n-1);
		for(int i=1,cnt,las,nw;i<=k;i++)
		{
			cnt=ouf.readInt(),las=ouf.readInt();
			if(las!=u) quitf(_wa,"Wrong Answer!!!");
			for(int i=2;i<=cnt;i++)
			{
				nw=ouf.readInt();
				if(las<nw) tmp=make_pair(las,nw);
				else tmp=make_pair(nw,las);
				if(G[tmp]==0) quitf(_wa,"Wrong Answer!!!!");
				G[tmp]--;
				las=nw;
			}
			if(las!=v) quitf(_wa,"Wrong Answer!!!!!");
		}
	}
	quitf(_ok,"Accepted!!!");
	return 0;
}
