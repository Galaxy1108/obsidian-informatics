#include<bits/stdc++.h>
using namespace std;
int book[15];
int q[15];
void dfs(int x){
	if(x==11){
		for(int i=1;i<=10;i++)
			cout<<q[i]<<" ";
		cout<<endl;
		return;
	} 
	if(x%2)
		for(int i=1;i<=9;i+=2){
			if(book[i])
				continue;
			q[x]=i;
			book[i]=1;
			dfs(x+1);
			book[i]=0;
		}
	else
		for(int i=2;i<=10;i+=2){
			if(book[i])
				continue;
			q[x]=i;
			book[i]=1;
			dfs(x+1);
			book[i]=0;
		}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	cout<<14400<<endl;
	dfs(1);
	return 0;
}

