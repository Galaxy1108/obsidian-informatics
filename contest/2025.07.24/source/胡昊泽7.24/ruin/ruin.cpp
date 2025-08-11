#include<iostream>
#include<cstring>
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
constexpr int mod = 1e9 + 7 ;
int n = 0 ;
int a[605] = {} ;
bool vis[1210] = {} ;
int h[1210] = {} , tmp[1210] = {} ;
int cnt[605] = {} ;
int ans = 0 ;
inline bool check()
{
	for(int i = 1 ; i <= 2 * n ; ++i)
		tmp[i] = h[i] ;
	for(int times = 1 ; times <= n ; ++times)
	{
		for(int i = 1 ; i <= 2 * n ; ++i)
		{
			if(!tmp[i])
				continue ;
			bool flag = false ;
			for(int j = i + 1 ; j <= 2 * n ; ++j)
			{
				if(tmp[j] == tmp[i])
				{
					flag = true ;
					break ;
				}
			}
			if(flag)
				--tmp[i] ;
		}
	}
	for(int i = 1 ; i <= 2 * n ; ++i)
		if(tmp[i] && !vis[i] || !tmp[i] && vis[i])
			return false ;
	return true ;
}
void dfs(int now)
{
	if(now == 2 * n + 1)
	{
		if(check())
			(++ans) %= mod ;
		return ;
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		if(cnt[i] == 2)
			continue ;
		h[now] = i ;
		++cnt[i] ;
		dfs(now + 1) ;
		h[now] = 0 ;
		--cnt[i] ;
	}
}
int main()
{
	File("ruin") ;
	qcin>>n ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>a[i] , vis[a[i]] = true ;
	if(a[n] != 2 * n)
	{
		qcout<<'0'<<'\n' ;
		return 0 ;
	}
	dfs(1) ;
	qcout<<ans<<'\n' ;
	return 0 ;
}
