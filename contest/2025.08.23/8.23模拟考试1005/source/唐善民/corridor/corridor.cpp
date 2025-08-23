//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;
int n,m;
namespace judge0{
	constexpr const int N=1000,M=1000,Q=2000;
	bool a[N+1][M+1];
	//op=0:向下,op=1:向右 
	void query(int i,int j,int q,bool op){
		while(q){
			if(i>=n+1||j>=m+1){
				break;
			}
			if(a[i][j]){
				op=!op;
				q--;
				if(!q){
					break;
				}
			}
			switch(op){
				case 0:
					i++;
					break;
				case 1:
					j++;
					break;
			}
		}
		cout<<i<<' '<<j<<'\n';
	}
	int main(){
		int k;
		cin>>n>>m>>k;
		while(k--){
			int i,j;
			cin>>i>>j;
			a[i][j]=true;
		}
		int q;
		cin>>q;
		while(q--){
			int op,i,j,q;
			cin>>op>>i>>j;
			switch(op){
				case 1:
					a[i][j]=true;
					break;
				case 2:
					cin>>q;
					if(!i){
						query(1,j,q,0);
					}else{
						query(i,1,q,1);
					}
					break;
			}
		}
		return 0;
	}
}
namespace judge2{
	constexpr const int N=50000,M=50000,Q=150000;
	set<int>row[N+1],col[M+1];
	set<pair<int,int> >vis;
	//op=0:向下,op=1:向右 
	void query(int i,int j,int q,bool op){
		while(q){ 
			if(vis.count({i,j})){
				op=!op;
				q--;
				if(!q){
					break;
				}
			}
			set<int>::iterator p;
			switch(op){
				case 0:
//					i++;
					p=col[j].upper_bound(i);
					if(p==col[j].end()){
						cout<<n+1<<' '<<j<<'\n';
						return;
					}
					i=*p;
					break;
				case 1:
//					j++;
					p=row[i].upper_bound(j);
					if(p==row[i].end()){
						cout<<i<<' '<<m+1<<'\n';
						return;
					}
					j=*p;
					break;
			}
		}
		cout<<i<<' '<<j<<'\n';
	}
	int main(){
		int k;
		cin>>n>>m>>k;
		while(k--){
			int i,j;
			cin>>i>>j;
			row[i].insert(j);
			col[j].insert(i);
			vis.insert({i,j});
		}
		int q;
		cin>>q;
		while(q--){
			int op,i,j,q;
			cin>>op>>i>>j;
			switch(op){
				case 1:
					row[i].insert(j);
					col[j].insert(i);
					vis.insert({i,j});
					break;
				case 2:
					cin>>q;
					if(!i){
						query(1,j,q,0);
					}else{
						query(i,1,q,1);
					}
					break;
			}
		}
		return 0;
	}
}
int main(){
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int type;
	cin>>type;
	switch(type){
		case 0:
			judge0::main();
			break;
		default:
			judge2::main();	
			break;
	}
	
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 4 4 1
2 2
5
2 2 0 3
1 3 2
2 2 0 2
2 2 0 3
2 2 0 4
*/
