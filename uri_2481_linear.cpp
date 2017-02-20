/// David Mateus Batista <david.batista3010@gmail.com>
/// Computer Science - Federal University of Itajuba - Brazil

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define PI (double)acos(-1.0)
#define RAD(x) (double)(x*PI)/180.0
#define PCT(x,y) (double)x*100.0/y
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define D(x) x&(-x)
#define ALL(x) x.begin(),x.end()
#define SET(a,b) memset(a, b, sizeof(a))
#define DEBUG(x,y) cout << x << y << endl
#define gcd(x,y) __gcd(x, y)
#define lcm(x,y) (x/gcd(x,y))*y
#define bitcnt(x) __builtin_popcountll(x)
#define lbit(x) 63-__builtin_clzll(x)
#define zerosbitll(x) __builtin_ctzll(x)
#define zerosbit(x) __builtin_ctz(x)

enum {North, East, South, West};
//{0, 1, 2, 3}
//{Up, Right, Down, Left}

int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};

class Hull
{
	const static int CN=1e+5+35;
public:
	long long a[CN], b[CN];
	double x[CN];
	int head, tail;
	Hull():head(1), tail(0){};

	long long query(long long xx)
	{
		if(head>tail)
			return 0;
		while(head<tail && x[head+1]<=xx)
			head++;
		x[head]=xx;
		return a[head]*xx+b[head];
	}

	void insertLine(long long aa, long long bb)
	{
		double xx=-1e18;
		while(head<=tail)
		{
			if(aa==a[tail])
				return;
			xx=1.0*(b[tail]-bb)/(aa-a[tail]);
			if(head==tail || xx>=x[tail])
				break;
			tail--;
		}
		a[++tail]=aa;
		b[tail]=bb;
		x[tail]=xx;
	}
};

inline void fastRead(ll &n)
{
	n=0;
	register ll c=getchar_unlocked();
	register ll s=0;
	while(c<'0' || c>'9')
	{
		if(c=='-')
			s=1;
		c=getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		n=(n<<3)+(n<<1)+c-'0';
		c=getchar_unlocked();
	}
}

const int MN=1e+5+35;
int n;
Hull cht;
ll dp[MN], x[MN], c[MN];

void init()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cout << "[FREOPEN]" << endl;
	return;
}

int main()
{
	//init();
	int tt;
	scanf("%d", &tt);
	while(tt--)
	{
		cht.head=1;
		cht.tail=0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			fastRead(x[i]), fastRead(c[i]);

		dp[0]=0;
		cht.insertLine(x[1], dp[1]);
		for(int i=2; i<n; i++)
		{
			dp[i]=cht.query(x[i])-(x[i]*x[i])-c[i];
			cht.insertLine(x[i], dp[i]);
		}
		ll ans=cht.query(x[n])-c[n];
		printf("%s %lld\n", (ans>0)?"Ganha":"Perde", abs(ans));
	}
	return 0;
}