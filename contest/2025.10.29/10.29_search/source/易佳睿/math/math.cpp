#include<bits/stdc++.h>
#define ld long double
using namespace std;
int a,b; ld frac;
vector<int> v;

inline bool check(ld res){
	if(res==frac) return 1;
	return 0;
}

inline void DFS(int mx,int i,int top,ld res){
	if(check(res)){
		cout<<v.size()<<'\n';
		for(int n:v) cout<<n<<' ';
		exit(0); 
	}
	if(i>mx){
		if(check(res)){
			cout<<v.size()<<'\n';
			for(int n:v) cout<<n<<' ';
			exit(0); 
		}
		return ;
	} 
	for(int j=top;;j++){
		if(j>2e9) return ;
		if(res+1.0l*(mx-i+1)/j<frac) return ;
		if(res+1.0l/j>frac) continue;
		res+=1.0l/j;
		v.push_back(j);
		DFS(mx,i+1,j+1,res);
		res-=1.0l/j;
		v.pop_back();
	}
}

int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
/*	mt19937 rng(time(0));
	a=rng()%1000+1;
	while(b<=a){
		b=rng()%1000+1;
	}*/
	cin>>a>>b;
	frac=1.0l*a/b;
	int x=1;
	while(1){
		DFS(x,1,2,0.0l);
		x++;
	}
}
