#include<bits/stdc++.h>
#define int long long
#define N 1000
using namespace std;
mt19937 rnd(time(0));
int Rand(int l,int r){
	return rnd()%(r-l+1)+l;
}
main(){
	freopen("corridor.in","w",stdout);
	int n=N,a[N+5][N+5],ux,uy,opt;
//	cerr<<"ufiueuifhuie\n";
	cout<<1<<" "<<n<<" "<<n<<" "<<n<<"\n";
	for(int i=1;i<=n;i++){
		ux=Rand(1,n),uy=Rand(1,n);
//		cerr<<i<<" "<<a[ux][uy]<<"\n";
		while(a[ux][uy]){
//			cerr<<"emd\n";
			ux=Rand(1,n),uy=Rand(1,n);
//			cerr<<"run\n";
		}
		cout<<ux<<" "<<uy<<"\n";
	}
	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		opt=Rand(1,2);
		cout<<opt<<" ";
		if(opt==1){
			ux=Rand(1,n),uy=Rand(1,n);
		while(a[ux][uy])ux=Rand(1,n),uy=Rand(1,n);
		cout<<ux<<" "<<uy<<"\n";
		}
		else{
			ux=Rand(0,n);
			if(ux==0)uy=Rand(1,n);
			else uy=0;
			cout<<ux<<" "<<uy<<" "<<Rand(1,n)<<"\n";
		}
	}
	return 0;
}
