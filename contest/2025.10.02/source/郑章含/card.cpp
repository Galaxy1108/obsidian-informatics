#include<bits/stdc++.h>
using namespace std;
int n,m,q,num1,num2,a[100000];
void plusx(char c){
	if(c=='0'||c=='2'||c=='4'||c=='6'||c=='8') num2++;
	if(c=='1'||c=='3'||c=='5'||c=='7'||c=='9') num1++;
	return ;
}
void getin(){
	char c1,c2;
	while(1){
		c2=c1;
		scanf("%c",c1);
		if(c1=='\n'){
			plusx(c2);
			return ;
		}
		if(c1==' ') plusx(c2);
	}
}
int solve(){
	int cnt1,cnt2,st,f=0,al=0,bl=0,cl=0;
	int la[110],lb[110],lc[110]; //a:22,b:12,c:11
	for(int i=1;i<=n;i++){
		if(a[i]==0) continue;
		if(a[i]==2){
			if(a[i-1]!=0){
				if(f==2) a[++al]=(i-st+1);
				else b[++bl]=(i-st+1)
			}
			cnt2++;
			st=i;
			f=2;
		}
		else{
			if(a[i-1]!=0){
				if(f==2) a[++al]=(i-st+1);
				else b[++bl]=(i-st+1)
			}
			cnt2++;
			st=i;
			f=1;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	getin();
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y%2==0) a[x]=2;
		else a[x]=1;
	} 
	for(int i=1;i<=q;i++){
		int opt,x;
		scanf("%d%d",&opt,&x);
		if(opt==1) a[x]=0;
		else{
			int y;
			scanf("%d",&y);
			if(y%2==0) a[x]=2;
			else a[x]=1;
		}
		printf("%d\n",solve());
	}
	return 0;
} 

/*
1 2 3 4 5 6 7 8 9 10
0 1   0 0 0 1   0 1
0 1   0 0 0 1 1 0 1
0 1   0 0 0   1 0 1
0 1   0 0     1 0 1
0 1   0 0   0 1 0 1
0 1   0 0 1 0 1 0 1
0 1   0 0 1 0   0 1
0 1   0 0 1 0 1 0 1
0 1   0 0 1 0 1   1
0 1     0 1 0 1   1
0 1       1 0 1   1


11 1
9 0

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
          1          1  0     1     1  0     1  0 
          1          1  0     1     1  0  0  1  0 
          1             0     1     1  0  0  1  0 
          1   1         0     1     1  0  0  1  0 
          1   1         0     1     1  0  0     0 
          1   1         0           1  0  0     0 
*/
