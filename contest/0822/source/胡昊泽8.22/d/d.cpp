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
		#define sb(ch) (ch == ' ' || ch == '\n' || ch == '\r')
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(sb(tmp))
				tmp = getchar() ;
			c = tmp ;
		}
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
long long y[100005] = {} ;
int n = 0 , q = 0 ;
inline void calc(long long x1 , long long y1 , long long x2 , long long y2 , long long& a , long long& b)
{
	a = (y1 - y2) / (x1 - x2) ;
	b = (x2 * y1 + x1 * y2) / (x1 - x2) ;
}
inline void get_ans(int l , int r , long long& a , long long& b , long long& c)
{
	if(l == r)
	{
		a = 0 , b = y[l] , c = 1 ;
		return ;
	}
	calc(0 , y[l] , 1 , y[l + 1] , a , b) ;
	bool flag = true ;
	for(int i = 0 ; i <= r - l ; ++i)
	{
		if(a * i + b != y[l + i])
		{
			flag = false ;
			break ;
		}
	}
	if(flag)
	{
		c = 1 ;
		return ;
	}
	for(c = 2 ; c <= 10 ; ++c)
		for(a = 0 ; a <= 10 ; ++a)
			for(b = 0 ; b <= 10 ; ++b)
			{
				flag = true ;
				for(int i = 0 ; i <= r - l ; ++i)
					if((a * i + b) / c != y[l + i])
					{
						flag = false ;
						break ;
					}
				if(flag)
					return ;
			}
}
inline void solve()
{
	qcin>>n ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>y[i] ;
	qcin>>q ;
	int l = 0 , r = 0 ;
	while(q--)
	{
		qcin>>l>>r ;
		long long a = 0 , b = 0 , c = 0 ;
		get_ans(l , r , a , b , c) ;
		qcout<<a<<' '<<b<<' '<<c<<'\n' ;
	}
	return ;
}
int main()
{
	File("d") ;
	int T = 0 ;
	qcin>>T ;
	while(T--)
		solve() ;
	return 0 ;
}
