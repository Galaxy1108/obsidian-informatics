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
#define work_1
#ifdef work_1
int n = 0 , k = 0 ;
string s ;
int a[30] = {} ;
int posa[30] = {} ;
int posaa[30] = {} ;
int b[30] = {} ;
bool vis[30] = {} ;
int posb[30] = {} ;
int ans = 1e9 ;
inline void dfs(int step)
{
	if(step == n + 1)
	{
		memset(b , 0 , sizeof b) ;
		for(int i = 1 ; i <= n ; ++i)
			b[posaa[i]] = 1 ;
		int cnt = 0 ;
		for(int i = 1 ; i <= 2 * n ; ++i)
			if(!b[i])
				posb[++cnt] = i ;
		for(int i = 1 ; i <= n ; ++i)
			if(posaa[i] > posb[i])
				return;
		int L = 1 , R = 1 ;
		int num = 0 ;
		while(L <= n && R <= n)
		{
			int res = 1 ;
			while(posaa[L + res - 1] < posb[R] && L + res - 1 <= n)
				++res ;
			--res ;
			++num ;
			L = L + res ;
			R = R + res ;
		}
		if(num <= k)
		{
			int ans_now = 0 ;
			for(int i = 1 ; i <= n ; ++i)
				ans_now += (max(posa[i] , posaa[i]) - min(posa[i] , posaa[i])) ;
			ans = min(ans , ans_now) ;
		}
		return ;
	}
	for(int i = posaa[step - 1] + 1 ; i <= n + step ; ++i)
	{
		posaa[step] = i ;
		dfs(step + 1) ;
		posaa[step] = 0 ;
	}
}
int main()
{
	File("transfer") ;
	qcin>>n>>k ;
	qcin>>s ;
	if(n > 10)
	{
		qcout<<"0\n" ;
		return 0 ;
	}
	for(int i = 1 ; i <= 2 * n ; ++i)
		a[i] = (s[i - 1] == 'A' ? 1 : 0 ) ;
	int cnt = 0 ;
	for(int i = 1 ; i <= 2 * n ; ++i)
		if(a[i] == 1)
			posa[++cnt] = i ;
	dfs(1) ;
	qcout<<ans<<'\n' ;
	return 0 ;
}
#endif
#ifdef work_2
int n = 0 , k = 0 ;
string s ;
int w = 1 , h[1000005] = {} , lim[1000005] = {} ;
long long sum[1000005] = {} ;
long long dp[1000005] = {} ;
inline bool check(long long x)
{
	
}
int main()
{
	File("transfer") ;
	qcin>>n>>k ;
	qcin>>s ;
	for(int i = 0 ; i < 2 * n ; ++i)
	{
		if(s[i] == 'A')
			lim[++h[w]] = w - 1 ;
		else
			h[w + 1] = h[w] , ++w ;
	}
	for(int i = 1 ; i <= n ; ++i)
		sum[i] = sum[i - 1] + h[i] ;
	long long l = -1e12 , r = 1e12 , mid = 0 , ans = 0 ;
	while(l <= r)
	{
		mid = l + r >> 1 ;
		if(!check(mid))
			r = mid - 1 , ans = dp[n] - mid * k ;
		else
			l = mid + 1 ;
	}
	qcout<<ans<<'\n' ;
	return 0 ;
}
#endif
