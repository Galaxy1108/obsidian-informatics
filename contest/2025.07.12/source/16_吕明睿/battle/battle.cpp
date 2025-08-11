#include<bits/stdc++.h>
using namespace std;
long long abi[150001][4],n,ans[4];
bool g;
priority_queue<pair<int,int>>b[4]; 
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>abi[i][1]>>abi[i][2]>>abi[i][3];
		b[1].push({abi[i][1],i});
		b[2].push({abi[i][2],i});
		b[3].push({abi[i][3],i});
	}
	ans[1]=b[1].top().second;
	ans[2]=b[2].top().second;
	ans[3]=b[3].top().second;
	b[1].pop();
	b[2].pop();
	b[3].pop();
	while(!(b[1].empty()||b[2].empty()||b[3].empty())){
		
		if(abi[ans[1]][1]<=abi[ans[2]][1]){
			ans[2]=b[2].top().second;
			b[2].pop();
		}
		if(b[1].empty()||b[2].empty()||b[3].empty())break;
		
		if(abi[ans[1]][1]<=abi[ans[3]][1]){
			ans[3]=b[3].top().second;
			b[3].pop();
		}
		if(b[1].empty()||b[2].empty()||b[3].empty())break;
		
		if(abi[ans[2]][2]<=abi[ans[1]][2]){
			ans[1]=b[1].top().second;
			b[1].pop();
		}
		if(b[1].empty()||b[2].empty()||b[3].empty())break;
		
		if(abi[ans[2]][2]<=abi[ans[3]][2]){
			ans[3]=b[3].top().second;
			b[3].pop();
		}
		if(b[1].empty()||b[2].empty()||b[3].empty())break;
		
		if(abi[ans[3]][3]<=abi[ans[1]][3]){
			ans[1]=b[1].top().second;
			b[1].pop();
		}
		if(b[1].empty()||b[2].empty()||b[3].empty())break;
		
		if(abi[ans[3]][3]<=abi[ans[2]][3]){
			ans[2]=b[2].top().second;
			b[2].pop();
		}
		if(b[1].empty()||b[2].empty()||b[3].empty())break;
		
		if(abi[ans[1]][1]>abi[ans[2]][1]&&abi[ans[1]][1]>abi[ans[3]][1]
		&&abi[ans[2]][2]>abi[ans[1]][2]&&abi[ans[2]][2]>abi[ans[3]][2]
		&&abi[ans[3]][3]>abi[ans[1]][3]&&abi[ans[3]][3]>abi[ans[2]][3]){
			g=1;
			break;
		}
	}
	if(g)cout<<abi[ans[1]][1]+abi[ans[2]][2]+abi[ans[3]][3];
	else cout<<-1;
	return 0;
}
