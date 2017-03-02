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

const int MN=100+35;
int n, m;
int data[MN][MN];
int dist[MN][MN];

inline bool valid(int i, int j)
{
	return (i>=0 && i<n && j>=0 && j<m);
}

int solve(int si, int sj)
{
	SET(dist, INF);
	dist[si][sj]=0;

	queue<pii>bfs;
	bfs.push({si, sj});

	int ret=0;
	while(!bfs.empty())
	{
		int i=bfs.front().F;
		int j=bfs.front().S;
		int d=dist[i][j];
		ret=max(ret, d);
		bfs.pop();
		for(int k=0; k<8; k++)
		{
			int ii=i+mi[k];
			int jj=j+mj[k];
			if(valid(ii, jj) && data[ii][jj] && d+1<dist[ii][jj])
			{
				dist[ii][jj]=d+1;
				bfs.push({ii, jj});
			}
		}
	}
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
	int tt;
	scanf("%d", &tt);
	while(tt--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &data[i][j]);
		int si, sj;
		scanf("%d %d", &si, &sj);
		printf("%d\n", solve(si-1, sj-1));
	}
	return 0;
}