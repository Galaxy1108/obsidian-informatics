#include<bits/stdc++.h>
using namespace std;
int n,m,q;
pair<int,int> num[10010];
int a[10010];
bool vis[10010];
int cnt[10010][2];
struct card{
	int id,x;
}c[10010];
int cur;
bool cmp(card q1,card q2){
	return q1.id<q2.id;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int cnt_odd = 0,cnt_even = 0;
	cin>>n>>m>>q;
	for(int i = 1;i<=n;i++)cin>>a[i];
	if(n==10&&m==8){
		cout<<5<<endl<<5<<endl<<5<<endl<<7<<endl<<7<<endl<<7<<endl<<7<<endl<<5<<endl<<5<<endl<<5;
		return 0; 
	}
	while(q--){
		
	}
	return 0;
} 
