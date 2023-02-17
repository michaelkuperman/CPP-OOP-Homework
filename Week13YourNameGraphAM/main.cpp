#include <bits/stdc++.h>
using namespace std;

class myGraph
{
public:
    int mat[100][100];
    int maxVertex;       // max vertex graph can store
    int cnt = 0;         // current max vertex number graph containng
    map<string, int> m1; // map tp store mapping node string name to node number
    map<int, string> m2; // map tp store mapping node number to node string name
public:
    myGraph(int size)
    {
        maxVertex = size;                  // initailising the maxVertex graph can contain
        for(int i = 0; i < maxVertex; i++) // initialising the matrix with -1 , -1 indicate no edge between vertex
        {
            for(int j = 0; j < maxVertex; j++) {
                mat[i][j] = -1;
            }
        }
    }
    void AddVertex(string u)
    {
        if(cnt >= maxVertex) // graph is full
        {
            cout << "Max Limit exceed\n";
            return;
        }
        m2[cnt] = u; // store new node name string to map with new node number
        m1[u] = cnt;
        cnt++;
    }
    void AddEdge(string ust, string vst)
    { // inserting edge in graph
        int u = m1[ust];
        int v = m1[vst];
        mat[u][v] = 0; // 0 means edge between nodes with weight 0
        mat[v][u] = 0;
    }
    void setWeight(string ust, string vst, int weight)
    {
        int u = m1[ust];
        int v = m1[vst];
        mat[u][v] = weight; // set edge with new weight
        mat[v][u] = weight;
    }
    int countVertex()
    {
        return m1.size(); // vertex grapg is containing
    }
    int countEdge()
    {
        int edgeCnt = 0; // number of edge present in graph
        for(int i = 0; i < cnt; i++) {
            for(int j = 0; j < cnt; j++) {
                if(mat[i][j] >= 0)
                    edgeCnt++;
            }
        }
        return edgeCnt / 2; // above for loop will count each edge twice so edgeCnt/2 is answer
    }
    void dfs(int start, vector<bool>& vis)
    {

        cout << m2[start] << " "; // print the current node
        vis[start] = true;        // make current node visited
        for(int i = 0; i < cnt; i++) {
            if(mat[start][i] >= 0 && !vis[i]) { // if node is adjacent but not visited
                dfs(i, vis);
            }
        }
    }
    void DepthFirstSearch(string u)
    {
        vector<bool> vis(cnt, false);
        dfs(m1[u], vis);
    }
    void BreathFirstSearch(string ust)
    {
        int start = m1[ust];
        vector<bool> vis(cnt, false); // visited vector to identify which node is visited or not
        vector<int> q;
        q.push_back(start);
        vis[start] = true; // set source as visited
        while(!q.empty()) {
            int u = q[0];
            cout << m2[u] << " "; // print the current node
            q.erase(q.begin());
            for(int i = 0; i < cnt; i++) { // visit all neighbour
                if(!vis[i] && mat[u][i] >= 0) {
                    q.push_back(i); // push the adjacent node to the queue
                    vis[i] = true;
                }
            }
        }
    }
    void DeleteVertex(string ust)
    {
        int u = m1[ust];
        for(int i = 0; i < cnt; i++) // set all edge emerging from vertex -1
        {
            mat[u][i] = -1;
            mat[i][u] = -1;
        }
        m1.erase(ust); // removing vertex from map
        m2.erase(u);
    }
    int minDis(int dist[], bool vis[])
    {
        int min = INT_MAX; // initialise it with INT_MAX
        int minIndex;
        for(int i = 0; i < cnt; i++) {
            if(vis[i] == false && dist[i] <= min) {
                min = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void DijkstraShortPath(string sourceNode, string destinationNode)
    {
        int src = m1[sourceNode];
        bool vis[cnt]; // sptSet[i] will be true if vertex i is in shortest path from src to i is finalized
        int dis[cnt];  // dist[i] will contain the shortest distance from src to i
        int par[cnt];
        for(int i = 0; i < cnt; i++) { // Initialize all distances array to infinte and stpSet array to false

            dis[i] = INT_MAX;
            vis[i] = false;
            par[i] = -1;
        }
        dis[src] = 0; // distance of source vertex from itself is zero
        for(int k = 0; k < cnt - 1; k++) {

            int u = minDis(dis, vis);      // pick the vertex which has minimum distance which not visited yet
            vis[u] = true;                 // set picked vertex to visited
            for(int v = 0; v < cnt; v++) { // Update distance of all adjacent vertices of the picked vertex.

                // update dist[v] only if it is not in sptSet and there is edge from u to v and total weight of path
                // from src to v through u is smaller than current value of dist[v]
                if(mat[u][v] >= 0 && !vis[v] && dis[u] != INT_MAX && mat[u][v] + dis[u] < dis[v]) {
                    dis[v] = mat[u][v] + dis[u];
                    par[v] = u;
                }
            }
        }
        cout << endl;
        cout << sourceNode << " to " << destinationNode << " total weightis : " << dis[m1[destinationNode]] << endl;
        cout << destinationNode << " ";
        printPath(par, m1[destinationNode]);
        cout << endl;
    }
    void printPath(int par[], int j)
    {
        if(par[j] == -1)
            return;
        printPath(par, par[j]);
        cout << m2[j] << " ";
    }
};
int main()
{
    cout << "Michael Kuperman: 11/14/2021 " << endl;
    myGraph G1(12);
    G1.AddVertex("SE");
    G1.AddVertex("SFO");
    G1.AddVertex("SLC");
    G1.AddVertex("LAX");
    G1.AddVertex("DEN");
    G1.AddVertex("PHO");
    G1.AddVertex("DAL");
    G1.AddVertex("CHG");
    G1.AddVertex("ALT");
    G1.AddVertex("WDC");
    G1.AddVertex("NYC");
    G1.AddVertex("MIA");

    G1.AddEdge("SE", "SFO");
    G1.AddEdge("SE", "LAX");
    G1.AddEdge("SE", "DEN");
    G1.AddEdge("SE", "CHG");

    G1.AddEdge("SFO", "SLC");
    G1.AddEdge("SFO", "LAX");

    G1.AddEdge("LAX", "PHO");

    G1.AddEdge("SLC", "ALT");

    G1.AddEdge("PHO", "DEN");
    G1.AddEdge("PHO", "CHG");

    G1.AddEdge("DEN", "DAL");

    G1.AddEdge("DAL", "CHG");
    G1.AddEdge("DAL", "MIA");

    G1.AddEdge("CHG", "NYC");
    G1.AddEdge("CHG", "WDC");

    G1.AddEdge("WDC", "WDC");
    G1.AddEdge("WDC", "ALT");
    G1.AddEdge("WDC", "MIA");

    G1.AddEdge("NYC", "MIA");

    cout << "Number of vertex " << G1.countVertex() << endl;
    cout << "Number of edge " << G1.countEdge() << endl;

    G1.setWeight("SE", "SFO", 500);
    G1.setWeight("SE", "LAX", 550);
    G1.setWeight("SE", "DEN", 800);
    G1.setWeight("SE", "CHG", 1500);

    G1.setWeight("SFO", "SLC", 600);
    G1.setWeight("SFO", "LAX", 390);

    G1.setWeight("LAX", "PHO", 300);

    G1.setWeight("SLC", "ALT", 900);

    G1.setWeight("PHO", "DEN", 400);
    G1.setWeight("PHO", "CHG", 800);

    G1.setWeight("DEN", "DAL", 400);

    G1.setWeight("DAL", "CHG", 600);
    G1.setWeight("DAL", "MIA", 700);

    G1.setWeight("CHG", "NYC", 400);
    G1.setWeight("CHG", "WDC", 400);

    G1.setWeight("WDC", "WDC", 100);
    G1.setWeight("WDC", "ALT", 500);
    G1.setWeight("WDC", "MIA", 300);

    G1.setWeight("NYC", "MIA", 370);

    G1.DepthFirstSearch("SFO");
    cout << endl;
    G1.BreathFirstSearch("DAL");
    G1.DijkstraShortPath("SFO", "MIA");
    G1.DeleteVertex("ALT");
    G1.DijkstraShortPath("SFO", "MIA");

    return 0;
}