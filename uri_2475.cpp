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

const int MN=1e+4+35;
const int MN2=535;
int p, a;
ll data[MN];

inline ll getValue(int l, int r)
{
	return (r-l+1)*(data[r]-data[l-1]);
}

ll dp[MN2][MN];
inline void solve(int k, int l, int r, int L, int R)
{
	if(l>r)
		return;
	int m=(l+r)/2;
	int s=L;
	dp[k][m]=LINF;
	for(int i=max(m, L); i<=R; i++)
	{
		if(dp[k][m]>dp[k-1][i+1]+getValue(m+1, i+1))
		{
			dp[k][m]=dp[k-1][i+1]+getValue(m+1, i+1);
			s=i;
		}
	}
	solve(k, l, m-1, L, s);
	solve(k, m+1, r, s, R);
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
	scanf("%d %d", &p, &a);
	for(int i=1; i<=p; i++)
	{
		ll x;
		scanf("%lld", &x);
		data[i]=data[i-1]+x;
	}

	for(int i=0; i<=p; i++)
		dp[0][i]=LINF;
	for(int i=0; i<=a; i++)
		dp[i][p]=0;
	for(int i=1; i<=a; i++)
		solve(i, 0, p-1, 0, p-1);
	printf("%lld\n", dp[a][0]);
	return 0;
}