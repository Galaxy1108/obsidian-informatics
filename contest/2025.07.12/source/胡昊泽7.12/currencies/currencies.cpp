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
struct edg
{
	int to , v1 , v2 ;
} ;
vector<edg> edge[100005] ;
int fa[100005] = {} , dep[100005] = {} , top[100005] = {} , son[100005] = {} , sz[100005] = {} ;
int v1[100005] = {} , v2[100005] = {} ;
void dfs1(int now , int father)
{
	fa[now] = father , dep[now] = dep[father] + 1 , sz[now] = 1 ;
	int siz = edge[now].size() , to = 0 ;
	for(int i = 0 ; i < siz ; ++i)
	{
		to = edge[now][i].to ;
		if(to == father)
			continue ;
		v1[to] = edge[now][i].v1 ;
		v2[to] = edge[now][i].v2 ;
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
	if(!son[now])
		return ;
	dfs2(son[now] , t) ;
	int siz = edge[now].size() , to = 0 ;
	for(int i = 0 ; i < siz ; ++i)
	{
		to = edge[now][i].to ;
		if(to == fa[now] || to == son[now])
			continue ;
		dfs2(to , to) ;
	}
	return ;
}
inline int lca(int u , int v)
{
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
			swap(u , v) ;
		u = fa[top[u]] ;
	}
	return dep[u] < dep[v] ? u : v ; 
}
struct tmp_edg
{
	int a , b , v1 , v2 ;
} tmp[100005] ;
int n = 0 , m = 0 , q = 0 ;
inline void solve()
{
	int s = 0 , t = 0 , x = 0 , y = 0 ;
	qcin>>s>>t>>x>>y ;
	int Lca = lca(s , t) ;
	qcout<<"-1\n" ;
}
int main()
{
	File("currencies") ;
	qcin>>n>>m>>q ;
	for(int i = 1 ; i < n ; ++i)
		qcin>>tmp[i].a>>tmp[i].b ;
	for(int i = 1 , p , c ; i <= m ; ++i)
		qcin>>p>>c , ++tmp[p].v1 , tmp[p].v2 += c ;
	for(int i = 1 ; i <= m ; ++i)
	{
		edge[tmp[i].a].push_back((edg){tmp[i].b , tmp[i].v1 , tmp[i].v2}) ;
		edge[tmp[i].b].push_back((edg){tmp[i].a , tmp[i].v1 , tmp[i].v2}) ;
	}
	dfs1(1 , 0) ;
	dfs2(1 , 1) ;
	while(q--)
		solve() ;
	return 0 ;
}
