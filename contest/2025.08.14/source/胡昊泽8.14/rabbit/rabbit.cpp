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
#define mod (998244353)
struct edg
{
	int to , op ;
} ;
vector<edg> edge[105] , fedge[105] ;
int st = 0 , ed = 0 ;
int deg[105] = {} ;
long long f[105] = {} ;
inline long long qpow(long long a , int k)
{
	long long ret = 1 ;
	while(k)
	{
		if(k & 1)
			(ret *= a) %= mod ;
		(a *= a) %= mod ;
		k >>= 1 ;
	}
	return ret ;
}
//long long dfs(int now)
//{
//	if(now == st)
//		return 0 ;
//	if(f[now])
//		return f[now] ;
//	int siz = fedge[now].size() , to = 0 ;
//	for(int i = 0 ; i < siz ; ++i)
//	{
//		to = fedge[now][i].to ;
//		if(fedge[now][i].op)
//			(f[now] += (dfs(to) + 1) * qpow(deg[to] , mod - 2) % mod) %= mod ;
//	}
//	return f[now] ;
//}
int n = 0 , m = 0 ;
int main()
{
	File("rabbit") ;
	qcin>>n>>m>>st>>ed ;
	bool flag0 = true , flagmin = true ;
	for(int i = 1 , u , v , op ; i <= m ; ++i)
	{
		qcin>>u>>v>>op ;
		if(op)
			flag0 = false ;
		if(u >= v)
			flagmin = false ;
		fedge[v].push_back((edg){u , op}) ;
		edge[u].push_back((edg){v , op}) ;
		++deg[u] ;
	}
	if(flag0)
	{
		qcout<<"0 0\n" ;
		return 0 ;
	}
	if(flagmin)
	{
//		qcout<<dfs(ed)<<'\n' ;
		for(int i = st ; i <= ed ; ++i)
		{
			int siz = edge[i].size() , to = 0 ;
			for(int j = 0 ; j < siz ; ++j)
			{
				to = edge[i][j].to ;
				if(edge[i][j].op)
					(f[to] += (f[i] + 1) % mod * qpow(deg[i] , mod - 2) % mod) %= mod ;
			}
		}
		qcout<<f[ed]<<'\n' ;
		return 0 ;
	}
	qcout<<"0 0\n" ;
	return 0 ;
}
