#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[1001][1001];
vector<int> adj[1001];
vector<pair<int, int>> edge;
vector<pair<int, int>> Adj[10001];
bool visited[1001];

void sangMTKe()
{
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void sangDSKe()
{
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
void tuMTSangCanh()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] && i < j)
                edge.push_back({i, j});
        }
    }
    for (auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }
}
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u)
{
    cout << u << " ";
    // danh dau u da duoc tham
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            DFS(v);
    }
}
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        cout << k << " ";
        for (int x : adj[k])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void nhap()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        Adj[x].push_back({y, w});
        Adj[y].push_back({x, w});
    }
}
const int INF = 1e9;
void dijkstra(int s)
{
    vector<long long> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while (!Q.empty())
    {
        // chọn ra đỉnh có khoảng cách từ s nhỏ nhất
        pair<int, int> top = Q.top();
        Q.pop();
        int kc = top.first;
        int u = top.second;
        if (kc > d[u])
            continue;
        // cập nhâp khoảng cách từ s cho đến mọi đỉnh kề của u
        for (auto it : Adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
}
int main()
{
    input();
    BFS(1);
}
