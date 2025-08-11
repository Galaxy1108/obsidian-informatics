#include<iostream>
#include<vector>
#include<cstring> 
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
using namespace std ;
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
char ans[1600][1600] = {} ;
int n = 0 , m = 0 ;
vector< pair<char , int> > pos[1600] ;
int ceng[15] = {} , tot_ceng = 0 ;
int tot = 1 ;
void del(int i , int j)
{
	ans[i][j] = ' ' ;
	if(i == 1)
		return ;
	del(i - 1 , j + 1) ;
	del(i - 1 , j - 1) ;
}
int main()
{
	memset(ans , ' ' , sizeof ans) ;
	File("binary") ;
	ios::sync_with_stdio(false) ;
	qcin>>m>>n ;
	int las = -1 ;
	pos[1].push_back(make_pair(' ' , 0)) ;
	for(int i = 1 ; i <= (1 << m - 1) ; ++i)
		ans[1][i & 1 ? las + 2 : las + 4] = 'o' , las = i & 1 ? las + 2 : las + 4 , pos[1].push_back(make_pair('o' , las)) ;
	while(pos[tot].size() > 2)
	{
		pos[tot + 1].push_back(make_pair(' ' , 0)) ;
		for(int i = 1 ; i < pos[tot].size() ; i += 2)
		{
			if(pos[tot][i].second + 1 == pos[tot][i + 1].second - 1)
				ans[tot + 1][pos[tot][i].second + 1] = 'o' , pos[tot + 1].push_back(make_pair('o' , pos[tot][i].second + 1)) ;
			else
			{
				ans[tot + 1][pos[tot][i].second + 1] = '/' ;
				ans[tot + 1][pos[tot][i + 1].second - 1] = '\\' ;
				pos[tot + 1].push_back(make_pair('/' , pos[tot][i].second + 1)) ;
				pos[tot + 1].push_back(make_pair('\\' , pos[tot][i + 1].second - 1)) ;
			}
		}
		++tot ;
	}
//	for(int i = tot ; i >= 1 ; --i , cout<<'\n')
//		for(int j = 1 ; j <= las ; ++j)
//			qcout<<ans[i][j] ;
	for(int i = tot ; i >= 1 ; --i)
		if(pos[i][1].first == 'o')
			ceng[++tot_ceng] = i ;
	for(int i = 1 , a , b ; i <= n ; ++i)
	{
		qcin>>a>>b ;
		del(ceng[a] , pos[ceng[a]][b].second) ;
		int x = ceng[a] , y = pos[ceng[a]][b].second ;
		if(ans[x + 1][y + 1] == '/')
			while(ans[x + 1][y + 1] == '/')
				ans[x + 1][y + 1] = ' ' , ++x , ++y ;
		else
			while(ans[x + 1][y - 1] == '\\')
				ans[x + 1][y - 1] = ' ' , ++x , --y ;
	}
	for(int i = tot ; i >= 1 ; --i , qcout<<'\n')
		for(int j = 1 ; j <= las ; ++j)
			qcout<<ans[i][j] ;
	return 0 ;
}
