#include <bits/stdc++.h>
using namespace std;
int n,q,tr[1145][1145],P[1145][1145],tot;
int lowbit(int x){
	return x&(-x);
}
bool flag;
void edit(int x,int lay){
	while(x<=n){
		tr[x][lay]++;
		x+=lowbit(x);
	}
}
int sum(int x,int lay){
	int res=0;
	while(x){
		res+=tr[x][lay];
		x-=lowbit(x);
	}
	return res;
}
queue<int> qa,qb;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>P[i][0];
		edit(P[i][0],0);
		if(i==n/2+1){
			if(sum(P[i][0],0)==n/2+1) flag=true;
		}
	}
	for(tot=1;!flag&&tot<=n;++tot){
		for(int i=1;i<=n/2;++i) qa.push(P[i][tot-1]);
		for(int i=n/2+1;i<=n;++i) qb.push(P[i][tot-1]);
		int j=0;
		while(!qa.empty()&&!qb.empty()){
			if(qa.front()<qb.front()){
				P[++j][tot]=qa.front();
				qa.pop();
				edit(P[j][tot],tot);
			}
			else{
				P[++j][tot]=qb.front();
				qb.pop();
				edit(P[j][tot],tot);
			}
			if(j==n/2+1){
				if(sum(P[j][tot],tot)==n/2+1) flag=true;
			}
		}
		while(!qa.empty()){
			P[++j][tot]=qa.front();
			qa.pop();
			edit(P[j][tot],tot);
			if(j==n/2+1){
				if(sum(P[j][tot],tot)==n/2+1) flag=true;
			}
		}
		while(!qb.empty()){
			P[++j][tot]=qb.front();
			qb.pop();
			edit(P[j][tot],tot);
			if(j==n/2+1){
				if(sum(P[j][tot],tot)==n/2+1) flag=true;
			}
		}
	}
	tot--;
	while(q--){
		int t,i;
		cin>>t>>i;
		cout<<P[i][min(tot,t)]<<endl;
	}
	return 0;
}
