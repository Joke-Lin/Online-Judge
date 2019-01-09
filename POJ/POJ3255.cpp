//迪杰斯特拉
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
#include<cstring>
#define LOCAL
using namespace std;
const int maxn = 1e5+10;

struct edge{ 
    int to,cost;
    edge(int a,int b):to(a),cost(b){}
};
typedef pair<int,int> P;//最短距离和顶点的编号
vector<edge> G[maxn];
priority_queue< P,vector<P>,greater<P> > que;
int dist[maxn];//最短路
int dist2[maxn];//次短路

int N,R;

int main()
{
#ifdef LOCAL
    freopen("../VScode/in.txt","r",stdin);
    freopen("../VScode/out.txt","w",stdout);
#endif 
    scanf("%d%d",&N,&R);
    for(int i = 0;i < R;i++)
    {
        int x,y,cost; scanf("%d%d%d",&x,&y,&cost);
        G[x-1].push_back(edge(y-1,cost));//所有的坐标都减一
        G[y-1].push_back(edge(x-1,cost));//注意是双向边
    }
    memset(dist,0x3f,sizeof(dist));
    memset(dist2,0x3f,sizeof(dist2));
    dist[0] = 0;//初始化起点
    que.push(P(0,0));//起始点
    while(!que.empty())
    {
        P p = que.top();  que.pop();
        int v = p.second, d = p.first;//到的下一个点 和 权值
        if(dist2[v] < d) continue;//次短边比此边还小的话，直接跳过
        for (int i = 0;i < G[v].size();i++)//遍历边
        {
            edge &e = G[v][i];
            int d2 = d+e.cost;//d2始终是比最短路稍微长的一点
            if(dist[e.to] > d2)
            {
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }
            if(dist2[e.to] > d2 && dist[e.to] < d2)//如果是次短的话
            {
                dist2[e.to] = d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    printf("%d\n",dist2[N-1]);
    return 0;
}