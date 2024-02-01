#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of the given graph
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0); // Marking all the nodes as unvisited
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;         
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node); // Add the current node to the traversal array

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs; // Return the BFS traversal of the graph
    }
};

int main()
{
    // Example usage of the BFS function with user input

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

    // Get BFS traversal of the graph
    vector<int> bfsTraversal = solution.bfsOfGraph(V, adj);

    // Display the BFS traversal
    cout << "BFS Traversal: ";
    for (int node : bfsTraversal)
    {
        cout << node << " ";
    }

    return 0;
}
