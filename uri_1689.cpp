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
#define RESET(a,b) memset(a, b, sizeof(a))
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

const int MN=1e+6+35;
int n, k;
vector<int>data, val;
int dp[MN];

inline int findnext(register int &i)
{
	return (lower_bound(data.begin()+i, data.begin()+n, data[i]+k)-data.begin());
}

inline void fastInt(int &x)
{
	x=0;
	register int c=getchar_unlocked();
	register int s=0;
	while(c<'0' || c>'9')
	{
		if(c=='-')
			s=1;
		c=getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar_unlocked();
	}
}

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
	data.resize(MN);
	val.resize(MN);
	
	int tt;
	fastInt(tt);
	while(tt--)
	{
		fastInt(n);
		fastInt(k);
		for(register int i=0; i<n; i++)
			fastInt(data[i]);
		for(register int i=0; i<n; i++)
			fastInt(val[i]);

		dp[n]=0;
		for(register int i=n-1; i>=0; i--)
		{
			dp[i]=dp[i+1];
			dp[i]=max(dp[i], val[i]+dp[findnext(i)]);
		}
		printf("%d\n", dp[0]);
	}
	return 0;
}