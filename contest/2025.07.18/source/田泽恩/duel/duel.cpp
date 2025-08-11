#include <bits/stdc++.h>
using namespace std;
int n,q,p[229028],opt[229028],x[229028],k[229028],st[229028][20];
bool sub1,sub2,sub4;
queue<int> que;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	sub1=sub2=sub4=true;
	cin>>n>>q;
	if(n*q>150000000) sub1=false;
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	for(int i=1;i<=q;++i){
		cin>>opt[i]>>x[i]>>k[i];
		if(opt[i]&1) sub4=false;
	}
	if(sub4){
		for(int i=0;i<=19;++i){
			for(int j=n+1-(1<<i);j>0;--j){
				if(!i) st[j][i]=p[j];
				else{
					int k=j+(1<<(i-1));
					st[j][i]=abs(st[j][i-1]-st[k][i-1]);
				}
			}
		}
		for(int i=1;i<=q;++i){
			cout<<st[x[i]][k[i]]<<endl;
		}
	}
	else{
		for(int i=1;i<=q;++i){
			if(opt[i]&1){
				p[x[i]]=k[i];
			}
			else{
				int beg=x[i],nd=x[i]+(1<<k[i])-1;
				for(int j=beg;j<=nd;++j) que.push(p[j]);
				while(!que.empty()){
					int u=que.front();
					que.pop();
					if(que.empty()){
						cout<<u<<endl;
						break;
					}
					int v=que.front();
					que.pop();
					que.push(abs(u-v));
				}
			}
		}
	}
	return 0;
}
