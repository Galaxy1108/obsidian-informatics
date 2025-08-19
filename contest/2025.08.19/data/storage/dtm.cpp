#include<bits/stdc++.h>
using namespace std;
int m,T,n,K,Q,P=998244853;
int a[1000001],son[101][2];
char ns[1001];
int rd(){return rand()*32768+rand();}
signed main(){
	srand(time(0));
	for(int ii=11;ii<=20;ii++){
		sprintf(ns,"storage%d.in",ii-1);
		freopen(ns,"w",stdout);
		if(ii<=12)n=500;
		else if(ii<=14)n=10000;
//		else if(ii<=15)n=100;
//		else if(ii<=17)n=500;
		else n=1000000;
		cout<<n<<' '<<endl;
		int lt=0;
		for(int i=1;i<=n;i++){
			cout<<lt<<' '<<rand()%1000+1<<' '<<rd()%100000000+1<<endl;
			lt+=rand()%1000+1;
//			double nc=rand()/40000.0,nd=1.0/nc;
//			nd=nd*(rand()/35000.0);
//			cout<<rd()%30+1<<' '<<nc<<' '<<nd<<endl;
		}
//		m=rd()%(n*(n-1)/2)+1;
//		m=min(m,500);
//		cout<<n<<' '<<m<<endl;
//		for(int i=1;i<=n;i++,cout<<endl)for(int j=n-i+1;j>=1;j--)cout<<rd()%50+1<<' ';
//		int lt=0;
//		for(int i=1;i<=n;i++){
//			int nt=rd()%21+1;
//			if(nt==15&&rand()%50)nt=1;
//			cout<<nt<<' '<<rd()%20+1<<' '<<(lt=lt+rd()%3)<<endl;
//		}
//		n=max(ii,3);
//		memset(son,0,sizeof(son));
//		for(int i=2;i<=n;i++){
//			int nfa=rd()%(i-1)+1;
//			while(son[nfa][1])nfa=rd()%(i-1)+1;
//			if(!son[nfa][0])son[nfa][0]=i;
//			else son[nfa][1]=i;
//		}
//		cal(1,1),cout<<endl,cal(1,2),cout<<endl;
//		for(int i=1;i<=n;i++){
//			int nl=rand()%6+2;
//			for(int j=1;j<=nl;j++)printf("%c",rand()%3+'a');
//			printf("\n");
//		}
//		printf("%c",rand()%3+'a');
//		cout<<n<<' '<<rand()%(n-1)+1<<endl;
//		printf("%d",rd()%9+1);
//		for(int i=2;i<=n;i++)printf("%d",rd()%10);
//		cout<<endl;
//		int na,nb;
//		printf("%d\n%d %d\n",na=rand()%20+200,nb=na-21,(300-nb)*10);
//		for(int i=1;i<=n;i++)printf("%d %d\n",nb=na-rand()%20,(300-nb)*10);
//		printf("-1 -1\n%d\n",rand()%50+1);
//		for(int i=1;i<=n;i++){
//			int np=rand()%100-50;
//			while(np==0)np=rand()%100-50;
//			if(rd()%2){
//				if(np>0&&i>1)printf("+");
//				printf("%d",np);
//			}else{
//				if(np>0&&i>1)printf("+");
//				if(np!=1&&np!=-1)printf("%dx",np);
//				else printf("x");
//			}
//		}
//		printf("=");
//		for(int i=1;i<=n;i++){
//			int np=rand()%100-50;
//			while(np==0)np=rand()%100-50;
//			if(rd()%2){
//				if(np>0&&i>1)printf("+");
//				printf("%d",np);
//			}else{
//				if(np>0&&i>1)printf("+");
//				if(np!=1&&np!=-1)printf("%dx",np);
//				else printf("x");
//			}
//		}
//		if(ii<=6)n-=ii;
//		else n-=rand()%100;
//		if(rand()%2)P=998244353;
//		cout<<n<<' '<<P<<endl;
//		cout<<T<<endl;
//		for(int i=1;i<=T;i++){
//			cout<<n<<' '<<m<<endl;
//			for(int j=1;j<=n;j++,cout<<'\n'){
//				for(int k=1;k<=m;k++){
//					cout<<rand()+1<<' ';
//				}
//			}
//		}
//		cout<<n<<' '<<Q<<' '<<P<<endl;
//		for(int i=1;i<=n/2;i++)a[i-1]=0;for(int i=1;i<=n/2;i++)a[i-1]=1;
//		for(int i=1;i<=5*n;i++)swap(a[rd()%n],a[rd()%n]);
//		for(int i=1;i<=n;i++){
//			if(a[i-1]==0)cout<<'(';else cout<<')';
//		}
//		cout<<endl;
//		for(int i=1;i<=Q;i++){
//			int np=rd()%n+1,nq=rd()%n+1;while(np==nq)nq=rd()%n+1;
//			cout<<np<<' '<<nq<<endl;
//		}
//		for(int i=1;i<=n;i++)cout<<rd()%1500000000-750000000<<' ';cout<<endl;
//		cout<<T<<endl;
//		for(int i=1;i<T;i++){
//			cout<<10<<endl;
//			for(int j=1;j<=10;j++)cout<<rd()%P+1<<' ';
//			cout<<endl;
//		}
//		cout<<n-(T-1)*10<<endl;
//		for(int j=1;j<=n-(T-1)*10;j++)cout<<rd()%P+1<<' ';
//		cout<<endl;
	}
	return 0;
} 
