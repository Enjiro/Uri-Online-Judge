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

const int MN=200;
class maxflow_dinic
{
	static const int N=MN;
public:
	vector< pair<int,int> >edge;
	vector<int>adj[N];
	int ptr[N];
	int dist[N];

	maxflow_dinic(){};
	void clear()
	{
		for(int i=0; i<N; i++)
			adj[i].clear();
		edge.clear();
	}
	void add_edge(int u, int v, int c)
	{
		adj[u].push_back(edge.size());
		edge.push_back(mp(v, c));
		adj[v].push_back(edge.size());
		edge.push_back(mp(u, 0)); //(u, c) if is non-directed
	}
	bool dinic_bfs(int s, int t)
	{
		memset(dist, -1, sizeof(dist));
		dist[s]=0;

		queue<int>queue;
		queue.push(s);
		while(!queue.empty() && dist[t]==-1)
		{
			int u=queue.front();
			queue.pop();
			for(int i=0; i<adj[u].size(); i++)
			{
				int idx=adj[u][i];
				int v=edge[idx].F;

				if(dist[v]==-1 && edge[idx].S>0)
				{
					dist[v]=dist[u]+1;
					queue.push(v);
				}
			}
		}
		return dist[t]!=-1;
	}
	int dinic_dfs(int u, int t, int flow)
	{
		if(u==t)
			return flow;
		for(int &i=ptr[u]; i<adj[u].size(); i++)
		{
			int idx=adj[u][i];
			int v=edge[idx].F;
			if(dist[v]==dist[u]+1 && edge[idx].S>0)
			{
				int cf=dinic_dfs(v, t, min(flow, edge[idx].S));
				if(cf>0)
				{
					edge[idx].S-=cf;
					edge[idx^1].S+=cf;
					return cf;
				}
			}
		}
		return 0;
	}
	int maxflow(int s, int t)
	{
		int ret=0;
		while(dinic_bfs(s, t))
		{
			memset(ptr, 0, sizeof(ptr));
			int cf=dinic_dfs(s, t, INF);
			if(cf==0)
				break;
			ret+=cf;
		}
		return ret;
	}
};

int n;
maxflow_dinic data;
int sum[MN];
vector<int>val[MN];

int solve(int p)
{
	data.clear();
	for(int i=1; i<=n; i++)
	{
		if(val[p][0]==i || val[p][1]==i)
			data.add_edge(n+i, 2*n+1, max(0, sum[p]-2));
		else
			data.add_edge(n+i, 2*n+1, max(0, sum[p]-1));

		if(i==p || val[i][0]==p || val[i][1]==p)
			continue;
		data.add_edge(0, i, 1);

		for(int j=0; j<2; j++)
			data.add_edge(i, n+val[i][j], 1);
	}
	int mf=data.maxflow(0, 2*n+1);
	return (mf==(n-sum[p]-1))?0:1;
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
	for(int i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		val[i].pb(x);
		val[i].pb(y);
		sum[x]++;
		sum[y]++;
	}
	
	int ans=0;
	for(int i=1; i<=n; i++)
		ans+=solve(i);
	printf("%d\n", ans);
	return 0;
}