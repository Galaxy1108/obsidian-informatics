#include<iostream>
#include<cstring>
#include<random>
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
int val[405] = {} ;
bool ok[405] = {} ;
mt19937 myrand(114514) ;
int n = 0 ;
inline int gcd(int a , int b)
{
	return b ? gcd(b , a % b) : a ;
}
inline int lcm(int a , int b)
{
	return a / gcd(a , b) * b ;
}
inline void update()
{
	for(int i = 1 ; i <= n ; ++i)
		ok[i] = false ;
	for(int i = 1 ; i <= n ; ++i)
	{
		int Gcd = val[i] ;
		for(int j = i + 1 ; j <= n ; ++j)
		{
			Gcd = gcd(Gcd , val[j]) ;
			if(Gcd <= n)
				ok[Gcd] = true ;
		}
	}
}
inline bool check()
{
	for(int i = 1 ; i <= n ; ++i)
		if(!ok[i])
			return false ;
	return true ;
}
inline void solve()
{
//	for(int i = 1 ; i <= n ; ++i)
//		val[i] = 0 , ok[i] = false ;
//	for(int i = 1 ; i <= n ; ++i)
//	{
//		if(!val[i])
//			val[i] = myrand() % (myrand() & 1 ? n : 11000) + 1 ;
//		int pos = i ;
//		while(pos <= n)
//		{
//			++pos ;
//			if(!val[pos])
//				val[pos] = myrand() % (myrand() & 1 ? n : 11000) + 1 ;
//		}
//		update() ;
//	}
//	while(myrand() & 1)
//	{
		int pos = myrand() % n + 1 ;
		val[pos] = myrand() % (myrand() & 1 ? n : 11000) + 1 ;
//	}
	update() ;
}
int main()
{
	File("divisors") ;
	qcin>>n ; 
	if(n == 8)
	{
		qcout<<"4880 8275 3261 2082 2928 8 5964 7\n" ;
		for(int i = 1 ; i < n ; ++i)
			qcout<<i<<' '<<i + 1<<'\n' ;
		return 0 ;
	}
	if(n == 9)
	{
		qcout<<"3 7 9030 5004 9585 2030 9328 8 260\n" ;
		for(int i = 1 ; i < n ; ++i)
			qcout<<i<<' '<<i + 1<<'\n' ;
		return 0 ;
	}
	if(n == 10)
	{
		qcout<<"7125 8965 4 8 5960 7070 1603 10032 4374 9\n" ;
		for(int i = 1 ; i < n ; ++i)
			qcout<<i<<' '<<i + 1<<'\n' ;
		return 0 ;
	}
	for(int i = 1 ; i <= n ; ++i)
		val[i] = i + 1 ;
	update() ;
	while(!check())
		solve() ;
	for(int i = 1 ; i <= n ; ++i)
		qcout<<val[i]<<' ' ;
	qcout<<'\n' ;
	for(int i = 1 ; i < n ; ++i)
		qcout<<i<<' '<<i + 1<<'\n' ;
	return 0 ;
}
