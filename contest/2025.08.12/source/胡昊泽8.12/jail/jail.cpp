#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std ;
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
namespace IO
{
	#define isdigit(ch) (ch >= '0' && ch <= '9')
	#define SIZE (1 << 16)
	namespace Read
	{
		char buf[SIZE] , *_now = buf , *_end = buf ;
		inline char getchar()
		{
			if(_now == _end)
			{
				_now = _end = buf ;
				_end += fread(buf , 1 , SIZE , stdin) ;
				if(_now == _end)
					return EOF ;
			}
			return *(_now++) ;
		}
		template<typename T>
		inline void read(T& w)
		{
			w = 0 ;
			short f = 1 ;
			char ch = getchar() ;
			while(!isdigit(ch))
			{
				if(ch == '-')
					f = -1 ;
				ch = getchar() ;
			}
			while(isdigit(ch))
				w = (w << 1) + (w << 3) + (ch ^ 48) , ch = getchar() ;
			w *= f ;
		}
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(tmp == ' ' || tmp == '\n')
				tmp = getchar() ;
			c = tmp ;
		}
		#define sb(ch) (ch == ' ' || ch == '\n')
		inline void read(char* s)
		{
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			int len = 0 ;
			while(!sb(ch) && ch != EOF)
				s[len++] = ch , ch = getchar() ;
			s[len] = '\0' ;
		}
		inline void read(string& s)
		{
			s.clear() ;
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			while(!sb(ch) && ch != EOF)
				s.push_back(ch) , ch = getchar() ;
		}
		class qistream
		{
			public:
			template<typename T>
			inline qistream& operator>>(T& a)
			{
				read(a) ;
				return *this ;
			}
			inline qistream& operator>>(char* s)
			{
				read(s) ;
				return *this ;
			}
		} qcin ;
	}
	namespace Write
	{
		#define SIZE (1 << 16)
		char buf[SIZE] , *p = buf ;
		inline void flush()
		{
			fwrite(buf , 1 , p - buf , stdout) ;
			p = buf ;
		}
		inline void putchar(char ch)
		{
			if(p == buf + SIZE)
				flush() ;
			*p = ch ;
			++p ;
		}
		class Flush{public:~Flush(){flush() ;};}_;
		template<typename T>
		inline void write(T x)
		{
			char st[50] ;
			int len = 0 ;
			if(x < 0)
				putchar('-') , x = -x ;
			do
			{
				st[++len] = x % 10 + '0' ;
				x /= 10 ;
			} while(x) ;
			while(len)
				putchar(st[len--]) ;
		}
		inline void write(char c)
		{
			putchar(c) ;
		}
		inline void write(const char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(string& s)
		{
			int siz = s.size() ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		class qostream
		{
			public:
			template<typename T>
			inline qostream& operator<<(T x)
			{
				write(x) ;
				return *this ;
			}
			inline qostream& operator<<(const char* s)
			{
				write(s) ;
				return *this ;
			}
		} qcout ;
	}
	using Read::qcin ;
	using Write::qcout ;
}
using namespace IO ;
constexpr int N = 120005 ;
vector<int> edge[N] ;
int fa[N] = {} , dep[N] = {} , son[N] = {} , sz[N] = {} , top[N] = {} , id[N] = {} , tot = 0 ;
void dfs1(int now , int father)
{
	fa[now] = father , dep[now] = dep[father] + 1 , sz[now] = 1 ;
	int siz = edge[now].size() , to = 0 ;
	for(int i = 0 ; i < siz ; ++i)
	{
		to = edge[now][i] ;
		if(to == father)
			continue ;
		dfs1(to , now) ;
		sz[now] += sz[to] ;
		if(sz[to] > sz[son[now]])
			son[now] = to ;
	}
	return ;
}
void dfs2(int now , int t)
{
	top[now] = t ;
	id[now] = ++tot ;
	if(!son[now])
		return ;
	dfs2(son[now] , t) ;
	int siz = edge[now].size() , to = 0 ;
	for(int i = 0 ; i < siz ; ++i)
	{
		to = edge[now][i] ;
		if(to == fa[now] || to == son[now])
			continue ;
		dfs2(to , to) ;
	}
	return ;
}
inline void myswap(int& a , int& b)
{
	a ^= b ^= a ^= b ;
}
inline int lca(int u , int v)
{
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
			myswap(u , v) ;
		u = fa[top[u]] ;
	}
	return dep[u] < dep[v] ? u : v ;
}
int n = 0 , m = 0 ;
//int s[N] = {} , t[N] = {} ;
inline int get_dis(int u , int v)
{
	return dep[u] + dep[v] - 2 * dep[lca(u , v)] ;
}
struct cri
{
	int s , t ;
} all[N] ;
set<int> tree[N << 2] ;
#define ls (now << 1)
#define rs (now << 1 | 1)
inline void merge_this(set<int>& a , const set<int>& b)
{
	for(auto i : b)
		a.insert(i) ;
}
#define mid (curl + curr >> 1)
void build(int now , int curl = 1 , int curr = n)
{
	tree[now].clear() ;
	if(curl == curr)
		return ;
	build(ls , curl , mid) ;
	build(rs , mid + 1 , curr) ;
}
void update(int now , int pos , int k , int curl = 1 , int curr = n)
{
	tree[now].insert(k) ;
	if(curl == curr)
		return ;
	if(pos <= mid)
		update(ls , pos , k , curl , mid) ;
	else
		update(rs , pos , k , mid + 1 , curr) ;
	return ; 
}
void erase(int now , int pos , int k , int curl = 1 , int curr = n)
{
	tree[now].erase(k) ;
	if(curl == curr)
		return ;
	if(pos <= mid)
		erase(ls , pos , k , curl , mid) ;
	else
		erase(rs , pos , k , mid + 1 , curr) ;
	return ;
}
set<int> query(int now , int l , int r , int curl = 1 , int curr = n)
{
	if(l <= curl && r >= curr)
		return tree[now] ;
	set<int> ans ;
	if(l <= mid)
		merge_this(ans , query(ls , l , r , curl , mid)) ;
	if(r > mid)
		merge_this(ans , query(rs , l , r , mid + 1 , curr)) ;
	return ans ;
}
inline set<int> tree_query(int u , int v)
{
	set<int> ans ;
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
			myswap(u , v) ;
		merge_this(ans , query(1 , id[top[u]] , id[u])) ;
		u = fa[top[u]] ;
	}
	if(dep[u] > dep[v])
		myswap(u , v) ;
	merge_this(ans , query(1 , id[u] , id[v])) ;
	return ans ;
}
bool ok[N] = {} , vis[N] = {} ;
vector<int> to[N] ;
inline void clear()
{
	build(1) ;
	for(int i = 1 ; i <= n ; ++i)
		edge[i].clear() , to[i].clear() , son[i] = 0 , sz[i] = 0 , fa[i] = 0 , top[i] = 0 , dep[i] = 0 , ok[i] = false ;
	tot = 0 ; 
}
//bool get_ok(int now)
//{
//	set<int> ans = tree_query(all[now].s , all[now].t) ;
//	vis[now] = true ;
//	while(ans.size() > 1)
//	{
//		for(auto x : ans)
//		{
//			if(x == now)
//				continue ;
//			if(vis[x])
//				return vis[now] = false ;
//			if(ok[x])
//				return vis[now] = false ;
//			if(!get_ok(x))
//				return vis[now] = false ;
//		}
//		ans = tree_query(all[now].s , all[now].t) ;
//	}
//	vis[now] = false ;
//	erase(1 , id[all[now].s] , now) ;
//	update(1 , id[all[now].t] , now) ;
//	ok[now] = true ;
//	return true ;
//}
bool get_ok(int now)
{
	vis[now] = true ;
	ok[now] = true ;
	int siz = to[now].size() ;
	for(int i = 0 ; i < siz ; ++i)
	{
		if(vis[to[now][i]])
			return vis[now] = false ;
		if(!get_ok(to[now][i]))
			return vis[now] = false ;
	}
	vis[now] = false ;
	return true ;
}
inline void solve()
{
	qcin>>n ;
	clear() ;
	for(int i = 1 , u , v ; i < n ; ++i)
		qcin>>u>>v , edge[u].push_back(v) , edge[v].push_back(u) ;
	dfs1(1 , 0) ;
	dfs2(1 , 1) ;
	qcin>>m ;
	set<int> ans ;
	for(int i = 1 ; i <= m ; ++i)
	{
		qcin>>all[i].s>>all[i].t ;
		update(1 , id[all[i].s] , i) ;
		update(1 , id[all[i].t] , m + i) ;
	}
	for(int i = 1 ; i <= m ; ++i)
	{
//		if(ok[i])
//			continue ;
//		if(!get_ok(i))
//		{
//			qcout<<"No\n" ;
//			return ;
//		}
		ans = tree_query(all[i].s , all[i].t) ;
		for(auto x : ans)
		{
			if(x == i || x == m + i)
				continue ;
			if(x <= m)
				to[i].push_back(x) ;
			else
				to[x - m].push_back(i) ;
		}
	}
	for(int i = 1 ; i <= m ; ++i)
	{
		if(ok[i])
			continue ;
		if(!get_ok(i))
		{
			qcout<<"No\n" ;
			return ;
		}
	}
	qcout<<"Yes\n" ;
	return ;
}
int main()
{
	File("jail") ;
	int T = 0 ;
	qcin>>T ;
	while(T--)
//	for(int i = 1 ; i <= T ; ++i)
		solve() ;
	return 0 ;
}
