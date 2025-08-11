#include<bits/stdc++.h>
using namespace std; 

struct Road{
	int a,b;
	int jc;
};

Road tr[100005];

int main(){
	
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	
	int n,m,q;
	scanf("%d",&n,&m,&q);
	for(int i = 1;i <= n-1;++i){
		scanf("%d",&tr[i].a,&tr[i].b);
	}
	int tmp1,tmp2;
	for(int i = 1;i <= m;++i){
		scanf("%d%d",&tmp1,&tmp2);
		tr[tmp1].jc = tmp2;
	}
	int s,t,aun,agn;
	for(int mq = 1;mq <= q;++mq){
		scanf("%d%d%d%d",&s,&t,&aun,&agn);
		int w = 0;
		priority_queue<int> pq;
		while(!pq.empty()) pq.pop();
		for(int i = s;i <= t-1;++i){
			w += tr[i].jc;
			pq.push(wi);		
		}
		if(agn >= w){
			printf("%d\n",aun);
			continue;
		}
		while(aun != 0){
			aun--;
			w -= pq.top();
			pq.pop();
			if(agn >= w){
				printf("%d\n",aun);
				break;
			} 
		}
		printf("-1");
	}
	
	return 0;
} 
