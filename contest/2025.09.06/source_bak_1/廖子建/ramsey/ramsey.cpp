#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,edge[20][20];
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
bool check(int x,int y,int z){
//	if(ver[x][y][z])return f[x][y][z];
//	ver[x][y][z]=1;
	for(int i=1;i<=n;i++){
		if(i==x||i==y)continue;
		if(edge[x][i]==edge[y][i]&&edge[x][i]==z)return 0;
	}
	return 1;
}
main(){
	n=5,k=3;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=2;k++){
				if(check(i,j,k)){
					cout<<i<<" "<<j<<" "<<k<<"\n";
					edge[i][j]=k;
					edge[j][i]=k;
					break;
				}
			}
		}
	}
	return 0;
}
