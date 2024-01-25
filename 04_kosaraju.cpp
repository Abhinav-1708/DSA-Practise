#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1; // mark as visited
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    void dfs_(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1; // mark as visited
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs_(it, vis, adjT);
            }
        }
    }

public:
    // Function to find number of SCC in the graph
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        // Transpose the graph
        vector<int> adjT[V];
        for (int v = 0; v < V; v++)
        {
            vis[v] = 0;
            for (auto it : adj[v])
            {
                adjT[it].push_back(v);
            }
        }
        int count = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                count++;
                dfs_(node, vis, adjT);
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;

    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<int> adj[V];

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges in the format: <from> <to>\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v; // Assuming vertices are 0-indexed
        adj[u].push_back(v);
    }

    int sccCount = sol.kosaraju(V, adj);
    cout << "The number of strongly connected components is: " << sccCount << endl;

    return 0;
}
