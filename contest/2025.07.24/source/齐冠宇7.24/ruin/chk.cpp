#include<bits/stdc++.h>
#include "testlib.h" 
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
#define pr(...) void(0)//fprintf(stderr,__VA_ARGS__)

const int maxn=2e3,N=maxn+10;
int n,k;
std::bitset<N> A[N],B[N],C[N],D[N];

void mul(std::bitset<N> x[],std::bitset<N> y[]){
	for(int i=0;i<=n;++i)D[i].reset();
	for(int i=0;i<=n;++i)
		for(int k=0;k<=n;++k)
			if(x[i][k])D[i]|=y[k];
	for(int i=0;i<=n;++i)x[i]=D[i];
}

int table[16][4]={
{},
{},
{79870},
{38085},
{23960},
{19610},
{16065},
{14515},
{12540},
{11980},
{10995},
{10705},
{10345},
{10120},
{10015},
{9940},
};

int in_read(int L,int R){
	int x;
	x = inf.readInt(L, R);
	return x;
}

int out_read(int L,int R){
	int x;
	x = ouf.readInt(L, R);
	return x;
};

int ans_read(int L,int R){
	int x;
	x = ans.readInt(L, R);
	return x;
};

int main( int argc , char * argv[] ){
	 registerTestlibCmd( argc , argv );
	//registerLemonChecker(argc, argv);
	std::ifstream in(argv[1]);
	std::ifstream out(argv[2]);
	std::ifstream ans(argv[3]);
	
	n=in_read(1900,maxn);
	k=in_read(2,15);
	
	int cost=out_read(1,n*n);
	F(i,0,cost){
		int a=out_read(0,n),b=out_read(a+2,n);
		A[a][b]=1;
	}
	
	for(int i=1;i<=n;++i)A[i-1][i]=1;
	for(int i=0;i<=n;++i)C[i]=A[i];
	mul(C,C);
	/*for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j)fprintf(stderr,"%d ",(int)A[i][j]);
		fprintf(stderr,"\n");
	}*/
	for(int i=0;i<=n;++i)
	for(int j=i+2;j<=n;++j)if(A[i][j]) if(!C[i][j]) quitf( _wa , "Not correct" );
	
	for(int i=0;i<=n;++i)A[i][i]=1;
	for(int i=0;i<=n;++i)B[i][i]=1;
	for(int i=1;;i<<=1){
		if(k&i)mul(B,A);
		if(k<i*2)break;
		mul(A,A);
	}
	Fe(i,0,n)Fe(j,i,n) if(!B[i][j]) quitf( _wa , "Not correct" );
	//fprintf(stderr,"%g / %g\n",cost*1./n,table[k][0]*1e-4);
	double score=1-sqrt(cost*10000LL*1./(1LL*table[k][0]*n)-1);
	score=std::max(0.,std::min(1.,score));
	if(cost*10000LL<=table[k][0]*n*1LL)score=1;
	if(cost*10000LL>=table[k][0]*n*2LL)score=0;
	if( score == 1 ) quitf( _ok , "Correct" );
	else if( score == 0 ) quitf( _wa , "Not correct" );
	else quitp( score * 100 , "Partially correct" ); 
	//fprintf(stderr,"score: %g\n",score);
	return 0;
}
