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

const int MN=1035;
int n;
int data[MN][MN];
int dp[MN][MN][2];
bool memo[MN][MN][2];
int v[]={2, 5};

int f(int x, int d)
{
	int ret=0;
	while(x && x%d==0)
	{
		ret++;
		x/=d;
	}
	return ret;
}

int solve(int i, int j, int k)
{
	if(i==n-1 && j==n-1)
		return f(data[i][j], v[k]);
	if(memo[i][j][k])
		return dp[i][j][k];

	int &ret=dp[i][j][k]=INF;
	if(i+1<n && data[i+1][j]!=0)
		ret=min(ret, f(data[i][j], v[k])+solve(i+1, j, k));
	if(j+1<n && data[i][j+1]!=0)
		ret=min(ret, f(data[i][j], v[k])+solve(i, j+1, k));
	memo[i][j][k]=true;
	return ret;
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
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &data[i][j]);
	printf("%d\n", min(solve(0, 0, 0), solve(0, 0, 1)));
	return 0;
}