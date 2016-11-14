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

class node
{
public:
	int i, j, t;
	node(){};
	node(int _i, int _j, int _t)
	{
		i=_i, j=_j, t=_t;
	}
};

const int MN=55;
int n, m;
int data[MN][MN];
int dist[MN][MN][10];

int valid(int i, int j)
{
	return i>=0 && i<n && j>=0 && j<m;
}

int solve()
{
	RESET(dist, INF);
	dist[0][0][0]=0;
	queue<node>queue;
	queue.push(node(0, 0, 0));
	while(!queue.empty())
	{
		int i=queue.front().i;
		int j=queue.front().j;
		int t=queue.front().t;
		int d=dist[i][j][t];
		int h=(data[i][j]+t)%10;
		queue.pop();
		if(d+1<dist[i][j][(t+1)%10])
		{
			dist[i][j][(t+1)%10]=d+1;
			queue.push(node(i, j, (t+1)%10));
		}
		for(int k=0; k<4; k++)
		{
			int ii=i+mi[k];
			int jj=j+mj[k];
			if(!valid(ii, jj))
				continue;
			if(h+1<(data[ii][jj]+t)%10)
				continue;
			if(d+1<dist[ii][jj][(t+1)%10])
			{
				dist[ii][jj][(t+1)%10]=d+1;
				queue.push(node(ii, jj, (t+1)%10));	
			}
		}
	}
	int ret=INF;
	for(int i=0; i<10; i++)
		ret=min(ret, dist[n-1][m-1][i]);
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
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &data[i][j]);
	printf("%d\n", solve());
	return 0;
}