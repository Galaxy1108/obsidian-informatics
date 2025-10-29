#include <bits/stdc++.h>
using namespace std;
double n,m,a;
int b[2001],f=0;
int c[2001],ans=0;
void dfs(double x,int s){
	if(x<=0.0000001){
		f=1;
		cout<<s-1<<endl;
		for(int i=1;i<s;i++) cout<<c[i]<<" ";
		cout<<endl; 
	}
	for(int i=2;;i++){
		if(b[i]==1||double(1.0/double(i))>x) continue;
		x-=double(1.0/double(i));
		b[i]=1;
		c[s]=i;
		dfs(x+1,s+1); 
		b[i]=0;
	}
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin>>n>>m;
	a=m/n;
	dfs(a,1);
	return 0;
}
