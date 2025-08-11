#include<iostream>
#include<cstring>
#include<vector>
#include<ctime>
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
int c[1050] = {} ;
int F[1050][1050] = {} ;
int use[1050] = {} ;
int n = 0 ;
vector<int> edge[3100] ;
int tot = 0 ;
int fa[3100] = {} , dep[3100] = {} ;
void dfs_pre(int now , int father)
{
	fa[now] = father , dep[now] = dep[father] + 1 ;
	int siz = edge[now].size() , to = 0 ;
	for(int i = 0 ; i < siz ; ++i)
	{
		to = edge[now][i] ;
		dfs_pre(to , now) ;
	}
	return ;
}
int lca(int u,  int v)
{
	while(u != v)
		u = fa[u] , v = fa[v] ;
	return u ;
}
void get_cnt(int now , int& a , int& b)
{
	if(now <= n)
	{
		if(use[now])
			++b ;
		else
			++a ;
		return ;
	}
	int siz = edge[now].size() ;
	for(int i = 0 ; i < siz ; ++i)
		get_cnt(edge[now][i] , a , b) ;
}
int ans = 0 ;
inline int calc()
{
	int sum = 0 ;
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = i + 1 ; j <= n ; ++j)
		{
			int a = 0 , b = 0 ;
			get_cnt(lca(i , j) , a , b) ;
			if(a < b)
			{
				if(use[i])
				{
					if(!use[j])
						sum += F[i][j] ;
				}
				else
				{
					if(use[j])
						sum += F[i][j] ;
					else
						sum += 2 * F[i][j] ;
				}
			}
			else
			{
				if(use[i])
				{
					if(use[j])
						sum += 2 * F[i][j] ;
					else
						sum += F[i][j] ;
				}
				else
				{
					if(use[j])
						sum += F[i][j] ;
				}
			}
		}
	}
	return sum ;
}
void dfs(int now , int used)
{
	if(now == n + 1)
	{
		ans = min(ans , used + calc()) ;
		return ;
	}
	dfs(now + 1 , used) ;
	use[now] ^= 1 ;
	dfs(now + 1 , used + c[now]) ;
	use[now] ^= 1 ;
	if(clock() > 1.9 * CLOCKS_PER_SEC)
	{
		qcout<<ans<<'\n' ;
		exit(0) ;
	}
}
bool flag = true ;
int main()
{
	File("cost") ;
	qcin>>n ;
	n = 1 << n ;
	tot = n ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>use[i] ;
	for(int i = 1 ; i <= n ; ++i)
	{
		qcin>>c[i] ;
		if(c[i])
			flag = false ;
	}
	for(int i = 1 ; i <= n ; ++i)
		for(int j = i + 1 ; j <= n ; ++j)
			qcin>>F[i][j] , F[j][i] = F[i][j] ;
	if(flag)
	{
		qcout<<'0'<<'\n' ;
		return 0 ;
	}
	for(int i = 1 ; tot != 2 * n - 1 ; i += 2)
	{
		++tot ;
		edge[tot].push_back(i) ;
		edge[tot].push_back(i + 1) ;
	}
	dfs_pre(tot , 0) ;
	ans = calc() ;
	dfs(1 , 0) ;
	qcout<<ans<<'\n' ;
	return 0 ;
}
