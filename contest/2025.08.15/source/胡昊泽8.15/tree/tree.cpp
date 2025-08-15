#include<iostream>
#include<cstring>
#include<vector>
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
inline void myswap(int& a , int& b)
{
	a ^= b ^= a ^= b ;
}
struct tr
{
	vector<int> edge[500005] ;
	int fa[500005] = {} , dep[500005] = {} , top[500005] = {} , sz[500005] = {} , son[500005] = {} ;
	int tot = 0 , id[500005] = {} , fid[500005] = {} ;
	int val[500005] = {} , sum[500005] = {} ;
	void dfs1(int now , int father)
	{
		fa[now] = father , dep[now] = dep[father] + 1 , sz[now] = 1 ;
		int siz = edge[now].size() , to = 0 ;
		for(int i = 0 ; i < siz ; ++i)
		{
			to = edge[now][i] ;
			if(to == father)
				continue ;
			sum[to] = sum[now] + val[now] ;
			dfs1(to , now) ;
			sz[now] += sz[to] ;
			if(sz[to] > sz[son[now]])
				son[now] = to ;
		}
	}
	void dfs2(int now , int t)
	{
		top[now] = t ;
		id[now] = ++tot ;
		fid[tot] = now ;
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
} T1 , T2 ;
int n = 0 ;
int main()
{
	File("tree") ;
	qcin>>n ;
	for(int i = 2 ; i <= n ; ++i)
	{
		qcin>>T1.fa[i] ;
		T1.edge[T1.fa[i]].push_back(i) ;
	}
	for(int i = 2 ; i <= n ; ++i)
		qcin>>T1.val[i]  ;
	for(int i = 2 ; i <= n ; ++i)
	{
		qcin>>T2.fa[i] ;
		T2.edge[T2.fa[i]].push_back(i) ;
	}
	for(int i = 1 ; i <= n ; ++i)
		qcin>>T2.val[i] ;
	T1.dfs1(1 , 0) ;
	T1.dfs2(1 , 1) ;
	T2.dfs1(1 , 0) ;
	T2.dfs2(1 , 1) ;
	for(int i = 1 ; i <= n ; ++i)
	{
		long long ans = 0 ;
		for(int j = T2.id[i] ; j < T2.id[i] + T2.sz[i] ; ++j)
		{
			long long res = T1.sum[T1.fid[j]] - T1.sum[i] ;
			int lca = T2.lca(i , T2.fid[j]) ;
			int cnt = T2.dep[i] + T2.dep[T2.fid[j]] - 2 * T2.dep[lca] + 1 ;
			int u = i , v = T2.fid[j] ;
			int tot1 = 0 , tot2 = 0 ;
			while(v != lca)
				res += T2.val[v] * (tot1++) , v = T2.fa[v] ;
			while(u != lca)
				res += T2.val[u] * (tot2++) , u = T2.fa[u] ;
			res -= T2.val[lca] * (--tot2) ;
			ans = max(ans , res) ;
		}
		qcout<<ans<<'\n' ;
	}
	return 0 ;
}
