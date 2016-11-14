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

const int MN=35, MN2=105;
int n, k;
vector<int>graph[MN];
pair<int,int>data[MN];
vector<int>val[2];
set<int>aux[2];
bool memo[MN][MN2][MN2];

void dfs(int x, int wa, int wb)
{
	if(memo[x][wa][wb])
		return;
	memo[x][wa][wb]=true;

	if(data[x].S==0 && wa+wb+data[x].F<=k)
		dfs(x, wa+data[x].F, wb);
	if(data[x].S==1 && wa+wb+data[x].F<=k)
		dfs(x, wa, wb+data[x].F);
	for(int i=0; i<graph[x].size(); i++)
	{
		int y=graph[x][i];
		dfs(y, wa, wb);
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
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
	{
		int x, w, m;
		char c;
		scanf("%d %d %c %d", &x, &w, &c, &m);
		data[x]=mp(w, (c-'A'));
		for(int i=0; i<m; i++)
		{
			int y;
			scanf("%d", &y);
			graph[x].pb(y);
		}
	}
	dfs(0, 0, 0);
	int ans=INF;
	for(int i=0; i<n; i++)
		for(int j=0; j<=k; j++)
			for(int l=0; l+j<=k; l++)
				if(j+l>0 && memo[i][j][l])
					ans=min(ans, abs(j-l));
	printf("%d\n", ans);
	return 0;
}