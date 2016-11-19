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

const int MN=1e+3+35;
const ll MOD=1e+9+7;

int n;
ll dp[MN][MN];
ll ans[MN];
pii data[MN];
map< pair<double,double>, int>cnt;
set< pair<double,double> >center;

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
	for(int i=0; i<MN; i++)
	{
		dp[i][0]=dp[i][i]=1;
		for(int j=1; j<i; j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
		}
	}

	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &data[i].F, &data[i].S);
		center.insert({data[i].F, data[i].S});
	}

	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			cnt[mp((data[i].F+data[j].F)/2.0, (data[i].S+data[j].S)/2.0)]++;

	for(auto it:cnt)
	{
		int p=it.S;
		double x=it.F.F;
		double y=it.F.S;
		for(int i=1; i<=p; i++)
		{
			if(center.count({x, y}))
				ans[2*i+1]=(ans[2*i+1]+dp[p][i])%MOD;
			ans[2*i]=(ans[2*i]+dp[p][i])%MOD;
		}
	}

	printf("%d", n);
	for(int i=2; i<=n; i++)
	{
		i>1?printf(" "):NULL;
		printf("%lld", ans[i]);
	}
	printf("\n");
	return 0;
}