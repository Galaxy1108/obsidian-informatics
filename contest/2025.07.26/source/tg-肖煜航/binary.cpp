#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char ans[770][1550];
pair<int,int> id[15][1025];
pair<int,int> dfs(int dep,int num){
	if(dep==m){
		if(num==1){
			ans[769][1]='o';
			return id[dep][num]={769,1};
		}
		else if(num&1){
			ans[769][((num)/2)*6+1]='o';
			return id[dep][num]={769,((num)/2)*6+1};			
		}
		else{
			ans[769][((num)/2)*6-1]='o';
			return id[dep][num]={769,((num)/2)*6-1};
		}
	}
	pair<int,int> op1=dfs(dep+1,(num-1)*2+1),op2=dfs(dep+1,num*2);
	while(op1!=op2){
		op1.first--;
		op1.second++;
		op2.first--;
		op2.second--;
		ans[op1.first][op1.second]='/';
		ans[op2.first][op2.second]='\\';
	}
	ans[op1.first][op1.second]='o';
	return id[dep][num]=op1;
}
pair<int,int> delet(int dep,int num){
	if(dep==m){
		if(num==1){
			ans[769][1]=32;
			return id[dep][num]={769,1};
		}
		else if(num&1){
			ans[769][((num)/2)*6+1]=32;
			return id[dep][num]={769,((num)/2)*6+1};			
		}
		else{
			ans[769][((num)/2)*6-1]=32;
			return id[dep][num]={769,((num)/2)*6-1};
		}
	}
	pair<int,int> op1=delet(dep+1,(num-1)*2+1),op2=delet(dep+1,num*2);
	while(op1!=op2){
		op1.first--;
		op1.second++;
		op2.first--;
		op2.second--;
		ans[op1.first][op1.second]=32;
		ans[op2.first][op2.second]=32;
	}
	ans[op1.first][op1.second]=32;
	return id[dep][num]=op1;
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=0;i<770;i++) for(int j=0;j<1550;j++) ans[i][j]=32;
	pair<int,int> rt=dfs(1,1); 
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		pair<int,int> op=id[x][y];
		pair<int,int> nw=op;
		pair<int,int> fa,ls,rs;
		if(x>1) fa=id[x-1][y/2];
		if(x<m) ls=id[x+1][2*y-1],rs=id[x+1][2*y];
		delet(x,y);
		nw=op;
		if(x>1){
			while(nw.first!=fa.first){
				ans[nw.first][nw.second]=32;
				nw.first--;
				if(y&1) nw.second++;
				else nw.second--;
			}
		}
	}
	for(int i=rt.first;i<=769;i++){
		int mx=0;
		for(int j=1;j<1550;j++){
			if(ans[i][j]!=32){
				mx=j;
			}
		}
		for(int j=1;j<=mx;j++) putchar(ans[i][j]);
		printf("\n");
	}
	return 0;
} 
