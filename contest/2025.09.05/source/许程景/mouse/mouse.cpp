#include <cstdio>
double dpA[1001][1001],dpB[1001][1001];
int main(){
    freopen("mouse.in","r",stdin);
    freopen("mouse.out","w",stdout);
    int wh,bk;
    double tmp;
    scanf("%d%d",&wh,&bk);
    for(int i=1;i<=wh;i++) dpA[i][0]=dpB[i][0]=1;
    for(int i=0;i<=bk;i++) dpA[0][i]=0,dpB[0][i]=1;
    for(int i=1;i<=wh;i++){
	for(int j=1;j<=bk;j++){
	    dpA[i][j]=1-(double)j/(i+j)*dpB[i][j-1];
	    tmp=(double)i/(j+i-1)*dpA[i-1][j-1];
	    if(j-1) tmp+=(double)(j-1)/(j+i-1)*dpA[i][j-2];
	    dpB[i][j]=1-tmp*j/(i+j);
	}
    }
    #ifdef debug
    for(int i=0;i<=wh;i++){
	for(int j=0;j<=bk;j++){
	    printf("%lf ",dpA[i][j]);
	}printf("\n");
    }
    printf("\n");
    for(int i=0;i<=wh;i++){
	for(int j=0;j<=bk;j++){
	    printf("%lf ",dpB[i][j]);
	}printf("\n");
    }
    #endif
    printf("%.9lf\n",dpA[wh][bk]);
    return 0;
}
	    
