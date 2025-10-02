#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;

int N,M,Q;
int p,b;
int ans;
int a[MAXN];
int odd,even;
bool od[MAXN];
bool able[MAXN];

void DFS(int p){
	if(p>N){
		int cnt=0;
		for(int i=2;i<=N;i++){
			if(od[i]!=od[i-1]) cnt++;
		}
		ans=min(cnt,ans);
		return ;
	}
	if(able[p]){
		DFS(p+1);
		return ;
	}
	if(odd){
		odd--;
		od[p]=1;
		DFS(p+1);
		odd++;
		od[p]=0;
	}
	if(even){
		even--;
		od[p]=0;
		DFS(p+1);
		even++;
		od[p]=1;
	}
	return ;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>N>>M>>Q;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		if(a[i]%2) odd++;
		else even++;
	}
	for(int i=1;i<=M;i++){
		cin>>p>>b;
		able[p]=1;
		if(b%2){
			odd--;
			od[p]=1;
		} 
		else{
			even--;
			od[p]=0;
		} 
	}
	for(int i=1;i<=Q;i++){
		int op,p,x;
		cin>>op>>p;
		if(op==1){
			able[p]=0;
			if(od[p]) odd++;
			else even++;
			ans=1e9;
			DFS(1);
			cout<<ans<<endl;
		}
		if(op==2){
			cin>>x;
			if(x%2) od[p]=1;
			else od[p]=0;
			able[p]=1;
			if(od[p]) odd--;
			else even--;
			ans=1e9;
			DFS(1);
			cout<<ans<<endl;
		}
	}
} 
