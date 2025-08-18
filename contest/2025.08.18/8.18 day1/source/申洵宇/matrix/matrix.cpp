#include <bits/stdc++.h>
using namespace std;
/*
上一行：
0:左右都没有
1:左是一个
2:右是一个
3:左右是一个
4:左右是两个

未整理： 
0-0:0
0-1:1
0-2:1
0-3:1
0-4:2
1-0:0
1-1:0/1 
1-2:1
1-3:1
1-4:1/2
2-0:0
2-1:1
2-2:0/1 
2-3:1
2-4:1/2 
3-0:0
3-1:1
3-2:1
3-3:0/1 
3-4:2
4-0:0
4-1:0/1 
4-2:0/1 
4-3:1
4-4:0/1/2 
总结：
x-0:必然0
x-1:可以1 
x-2:可以1 
x-3:可以1 
x-4:可以2
1/2/4-4:可以1 
x-x(x!=0):可以0 
4-1/2:可以0  
*/
#define N 105
#define K 15
int n,m,k,a[N][2],f[N][K][5];
inline void addto(int i,int oj,int nj,int lo,int no,int add){
	f[i][nj][no]=max(f[i][nj][no],f[i-1][oj][lo]+add);
} 
inline void add(int i,int j,int lo,int no){
	int newadd=0;
	if(no==1||no==3||no==4)newadd+=a[i][0];
	if(no==2||no==3||no==4)newadd+=a[i][1];
	if(no==0){
		addto(i,j,j,lo,no,newadd);
		return ;
	}
	else if(no==1||no==2||no==3){
		if(j+1<=k)addto(i,j,j+1,lo,no,newadd);
	}
	else if(no==4){
		if(j+2<=k)addto(i,j,j+2,lo,no,newadd);
	}
	if(no==4&&(lo==1||lo==2||lo==4)){
		if(j+1<=k)addto(i,j,j+1,lo,no,newadd);
	}
	if(lo==no&&no!=0){
		addto(i,j,j,lo,no,newadd);
	}
	if(lo==4&&(no==1||no==2)){
		addto(i,j,j,lo,no,newadd);
	}
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j]; 
		}
	}
	memset(f,0xc0,sizeof(f));
	f[0][0][0]=0;
	int mxo=(m==1)?1:4;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int lo=0;lo<=mxo;lo++){
				for(int no=0;no<=mxo;no++){
					add(i,j,lo,no);
				}
			}
		}
	}
	int ans=0xc0c0c0c0;
	for(int no=0;no<=mxo;no++){
		ans=max(ans,f[n][k][no]);
	}
	cout<<ans;
	return 0;
}

