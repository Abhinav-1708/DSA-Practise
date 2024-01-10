#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Private helper function for DFS traversal
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &result)
    {
        vis[node] = 1;    // Mark the current node as visited
        result.push_back(node); // Add the current node to the traversal result

        for (auto neighbor : adj[node])
        {
            if (!vis[neighbor]) // If this neighbor is not visited
            {
                dfs(neighbor, adj, vis, result); // Recursively perform DFS on the neighbor
            }
        }
    }

public:
    // Function to return a DFS traversal of a graph
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0}; // Initialize the visited array
        int start = 0;     // Starting node for DFS traversal

        vector<int> dfsResult; // To store the DFS traversal

        // Perform DFS traversal starting from the specified node
        dfs(start, adj, vis, dfsResult);

        return dfsResult; // Return the DFS traversal result
    }
};

int main()
{
    // Example usage of the DFS function

    // Create an instance of the Solution class
    Solution solution;

    // Number of vertices
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Adjacency list representation of the graph
    vector<int> adj[V];

    // User input for adjacency list
    for (int i = 0; i < V; ++i)
    {
        int edges;
        cout << "Enter the number of edges for vertex " << i << ": ";
        cin >> edges;

        cout << "Enter the adjacent vertices for vertex " << i << ": ";
        for (int j = 0; j < edges; ++j)
        {
            int adjacentVertex;
            cin >> adjacentVertex;
            adj[i].push_back(adjacentVertex);
        }
    }

    // Get DFS traversal of the graph
    vector<int> dfsTraversal = solution.dfsOfGraph(V, adj);

    // Display the DFS traversal
    cout << "DFS Traversal: ";
    for (int node : dfsTraversal)
    {
        cout << node << " ";
    }

    return 0;
}
