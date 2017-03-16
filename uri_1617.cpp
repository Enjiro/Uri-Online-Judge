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
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define SET(a,b) memset(a, b, sizeof(a))

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

typedef int FTYPE; //type of flow
typedef int CTYPE; //type of cost
typedef pair<FTYPE,CTYPE>pfc;
const CTYPE CINF=INF;
const FTYPE FINF=INF;

void operator+=(pfc &p1, pfc &p2)
{
	p1.F+=p2.F;
	p1.S+=p2.S;
}

class graph
{
	const static int MN=1e+4;
public:
	int n;
	FTYPE flow[MN];
	CTYPE dist[MN], pot[MN];
	int prev[MN], eidx[MN];

	struct Edge
	{
		int to;
		FTYPE cap;
		CTYPE cost;
		Edge(){};
		Edge(int _to, FTYPE _cap, CTYPE _cost)
		{
			to=_to;
			cap=_cap;
			cost=_cost;
		}//
	};
	struct node
	{
		int u;
		CTYPE d;
		node(){};
		node(int _u, CTYPE _d)
		{
			u=_u;
			d=_d;
		}
		bool operator <(const node &foo) const
		{
			return d>foo.d;
		}
	};
	graph(){};
	vector<int>adj[MN];
	vector<Edge>edge;
	inline void set(int _n)
	{
		n=_n;
	}
	inline void reset()
	{
		for(int i=0; i<MN; i++)
			adj[i].clear();
		edge.clear();
	}
	inline void add_edge(int u, int v, FTYPE c, FTYPE cst)
	{
		adj[u].push_back(edge.size());
		edge.push_back(Edge(v, c, cst));
		adj[v].push_back(edge.size());
		edge.push_back(Edge(u, 0, -cst));
	}

	pfc dijkstra(int s, int t)
	{
		for(register int i=0; i<n; i++)
			dist[i]=CINF;
		dist[s]=0;
		flow[s]=FINF;
		priority_queue<node>heap;
		heap.push(node(s, 0));
		while(!heap.empty())
		{
			int u=heap.top().u;
			CTYPE d=heap.top().d;
			heap.pop();
			if(d>dist[u])
				continue;
			for(int i=0; i<adj[u].size(); i++)
			{
				int idx=adj[u][i];
				int v=edge[idx].to;
				CTYPE w=edge[idx].cost;
				if(!edge[idx].cap || dist[v]<=d+w+pot[u]-pot[v])
					continue;
				if(d+w<dist[v])
				{
					dist[v]=d+w;
					prev[v]=u;
					eidx[v]=idx;
					flow[v]=min(flow[u], edge[idx].cap);
					heap.push(node(v, d+w));
				}
			}
		}
		if(dist[t]==CINF)
			return mp(FINF, CINF);
		pfc ret=mp(flow[t], 0);
		for(int u=t; u!=s; u=prev[u])
		{
			int idx=eidx[u];
			edge[idx].cap-=flow[t];
			edge[idx^1].cap+=flow[t];
			ret.second+=flow[t]*edge[idx].cost;
		}
		return ret;
	}

	inline pfc mcmf(int s, int t)
	{
		pfc ret=mp(0, 0);
		pfc got;
		while((got=dijkstra(s, t)).first!=FINF)
			ret+=got;
		return ret;
	}
};

graph g;

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
	int n;
	while(scanf("%d", &n) && n)
	{
		g.reset();
		int source=0, sink=n, cnt=n+1;
		g.add_edge(source, 1, 2, 0);
		g.add_edge(n, sink, 2, 0);

		int m;
		scanf("%d", &m);
		for(int i=0; i<m; i++)
		{
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			int xx=cnt++;
			int yy=cnt++;

			g.add_edge(x, xx, 1, 0);
			g.add_edge(xx, yy, 1, w);
			g.add_edge(yy, y, 1, 0);
			g.add_edge(y, xx, 1, 0);
			g.add_edge(yy, x, 1, 0);
		}

		g.set(cnt);
		pfc ans=g.mcmf(source, sink);
		if(ans.F==2)
			printf("%d\n", ans.S);
		else
			printf("Pernoite.\n");
	}
	return 0;
}