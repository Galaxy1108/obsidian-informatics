#include <bits/stdc++.h>

const int32_t MAXN = 5010;
int32_t a[MAXN][MAXN];
int32_t p[MAXN][MAXN];
int32_t w[MAXN];
int32_t v[MAXN];
 
inline void gen (const int32_t n, const int32_t seed){
    if (!seed) {
    	
    	for (int i = 1; i <= n; ++ i) 
	        for(int j = 1; j <= n + 1; ++ j) 
	            std::cin >> a[i][j];
	            
    } else {
    	
	    std::mt19937 rng (seed);
	    
	    for (int i = 1; i <= n; ++ i) 
	        for(int j = 1; j <= n + 1; ++ j) 
	            a[i][j] = j, std::swap (a[i][j], a[i][rng () % j + 1]);
	            
    }
    
    for (int i = 1; i <= n; ++ i)
    	for (int j = 1; j <= n + 1; ++ j)
    		p[i][a[i][j]] = j;
}

int32_t n, seed;

inline int32_t pre (const int32_t x) {
	if (x == 1) return n;
	return x - 1;
}

inline void Solve (const int32_t x) {
	
	memset (v, 0, sizeof v);
	
	for (int i = pre (x); i != x; i = pre (i)) {
		while (v[p[i][w[i]]]) ++ w[i];
		v[p[i][w[i]]] = 1;
	}
	
	while (v[p[x][w[x]]]) ++ w[x];
		
	v[p[x][w[x]]] = 1, w[x] = 1;
	
	for (int i = 1; i <= n + 1; ++ i) 
		if (!v[i]) std::cout << i << ' ';
}

int main () {
	
	freopen ("c.in", "r", stdin);
	freopen ("c.out", "w", stdout);
	
	std::ios::sync_with_stdio (0);
	std::cin.tie (0), std::cout.tie (0);
	
	std::cin >> n >> seed;
	
	gen (n, seed);
	
	for (int i = 1; i <= n; ++ i) w[i] = 1;
	
	for (int i = 1; i <= n; ++ i) Solve (i);
	
	return 0;
}
