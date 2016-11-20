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
int n, m; 
vector<int>graph[MN];
int dp[MN][MN];
bool memo[MN][MN];

int solve(int l, int r)
{
	if(l==r)
		return l==0;
	if(memo[l][r])
		return dp[l][r];
	int &ret=dp[l][r]=0;
	if(l>r)
	{
		for(int i=0; i<graph[l].size(); i++)
		{
			ret=max(ret, solve(graph[l][i], r));
		}
	}
	else
	{
		for(int i=0; i<graph[r].size(); i++)
		{
			ret=max(ret, solve(l, graph[r][i]));
		}
	}
	memo[l][r]=true;
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
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			graph[i].clear();
			for(int j=0; j<n; j++)
			{
				memo[i][j]=false;
			}
		}

		for(int i=0; i<m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--, y--;
			graph[y].pb(x);
		}

		int ans=0;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				ans+=solve(i, j);
		printf("%d\n", ans);
	}
	return 0;
}