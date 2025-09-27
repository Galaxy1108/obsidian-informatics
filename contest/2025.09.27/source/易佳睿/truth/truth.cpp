#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e4+5;

int N,K,M;
int a[MAXN];
int T[MAXN][35];

int lowbit(int x){
	return x&(-x);
}

void add(int i,int p,int v){
	while(p<=N){
		T[p][v]+=i;
		p+=lowbit(p);
	}
	return ;
}

int query(int p,int v){
	int sum=0;
	while(p){
		sum+=T[p][v];
		p-=lowbit(p);
	}
	return sum;
}

bool check(int l,int r){
	for(int i=1;i<=K;i++){
		if(query(r,i)-query(l-1,i)<1) return 0;
	}
	return 1;
}

int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	
	cin>>N>>K>>M;
	for(int i=1;i<=N;i++){
		int x;
		cin>>x;
		add(1,i,x);
	}
	for(int i=1;i<=M;i++){
		int op,p,v;
		cin>>op;
		if(op==1){
			cin>>p>>v;
			int x=a[p];
			add(-1,p,x);
			add(1,p,v);
			a[p]=v;
		}
		else{
			int l=1,r=1,ans=N+1;
			while(l<=N&&r<=N){
				if(l==r) r++;
				if(check(l,r)){
					ans=r-l+1;
					l++;
				}
				else{
					r++;
				}
			}
			if(ans==N+1) cout<<-1<<endl;
			else cout<<ans<<endl;
		}
	}
}
