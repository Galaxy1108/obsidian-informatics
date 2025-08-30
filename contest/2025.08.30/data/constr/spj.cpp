#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define maxn 1200005
using namespace std;
int tot, m, ch[maxn][15], n, T	= 113400, vis[15];
ifstream fin, fout;
ofstream fscore, freport;
int viss[maxn];
void dfs(int x, int y, int dep) {
	if(dep == n && x != y) {
		if(x != y) {
    		fscore<<0<<endl;
   	 		fin.close();
    		fout.close();
    		fscore.close();
    		freport.close();
    		exit(0);
		}
		return;
	}
	ru(i, 1, n) if(ch[x][i] && ch[y][i]) dfs(ch[x][i], ch[y][i], dep + 1);
	ru(i, 2, n) if(ch[x][i - 1] && ch[y][i]) dfs(ch[x][i - 1], ch[y][i], dep + 1);
	ru(i, 2, n) if(ch[x][i] && ch[y][i - 1]) dfs(ch[x][i], ch[y][i - 1], dep + 1);
}
double judge() {
	n=10; fout>>m;
	if(m > T || m < 1) return 0;
	ru(i, 1, m) {
		int now = 0;
		ru(j, 1, n) vis[j] = 0;
		ru(j, 1, n) {
			int k; fout>>k;
			if(k < 1 || k > n || vis[k]) return 0;
			vis[k] = 1;
			if(!ch[now][k]) ch[now][k] = ++tot;
			now = ch[now][k];
		}
		if(viss[now]) {
			fscore<<0<<endl;
			
		    fin.close();
		    fout.close();
		    fscore.close();
		    freport.close();
			exit(0);
		}
		viss[now] = 1;
	}
	dfs(0, 0, 0);
	if(m <= 113214) return 3 * log(m)+5;
	else if(m < T) return (double)(m - 113000) / 5;
	else return 100;
}
int main(int argc, char *argv[]) {
	
//	registerLemonChecker(argc, argv);
	fin.open(argv[1]);
    fout.open(argv[2]);
    fscore.open(argv[5]);
    freport.open(argv[6]);
//    fscore<<judge() / 10.0 <<endl;
	fscore<<judge()<<endl;
    fin.close();
    fout.close();
    fscore.close();
    freport.close();
	return 0;
}
