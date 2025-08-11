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
using namespace std;
constexpr const int N=10,M=N,Len=768;
int n,m,del[N+1][2];
//单个前/后面的缩进 
int tab[N+1+1];
char ans[Len<<1|1][Len<<4|1];
int L=2147483647,R=-2147483648,Up=1,Down=-2147483648;
void solve(int p){
	if(p>=m){
		tab[p]=0;
		return;
	}
	solve(p+1);
	if(p+1==m){
		tab[p]=2;
	}else{
		tab[p]=tab[p+1]<<1|1;
	}
//	cerr<<"tab["<<p<<"]="<<tab[p]<<endl;
}
bool check(int depth,int kth){
	for(int k=1;k<=n;k++){
		if(del[k][0]==depth&&del[k][1]==kth){
			return true;
		}
	}
	return false;
}
//(i,j)=ch,剩余last条边绘制 
void print(int i,int j,char ch,int last,int depth,bool deleted,int kth){
	if(depth>m){
		return;
	} 
//	cerr<<"print("<<i<<","<<j<<","<<ch<<","<<last<<","<<depth<<","<<deleted<<","<<kth<<")\n";
	Down=max(Down,i);
	L=min(L,j);R=max(R,j);
	if(deleted){
		return;
	}
	if(last){
		ans[i][j]=ch;
		if(ch=='/'){
			print(i+1,j-1,'/',last-1,depth,deleted,kth);
		}else{
			print(i+1,j+1,'\\',last-1,depth,deleted,kth);
		}
	}else{
		ch='o';
		
		ans[i][j]=ch;
		if(!check(depth+1,(kth-1)<<1|1)){
			print(i+1,j-1,'/',tab[depth]-tab[depth+1]-1,depth+1,deleted,(kth-1)<<1|1);
		}
		if(!check(depth+1,kth<<1)){
			print(i+1,j+1,'\\',tab[depth]-tab[depth+1]-1,depth+1,deleted,kth<<1);
		}
	}
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	memset(ans,' ',sizeof(ans));
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		del[i][0]=x,del[i][1]=y;
	}
	solve(1);
	print(1,Len<<2,'o',0,1,false,1);
	for(int i=Up;i<=Down;i++){
		for(int j=L;j<=R;j++){
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
