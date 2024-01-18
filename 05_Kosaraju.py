from collections import defaultdict, deque

class Graph:
    def _init_(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs(self, vertex, visited, stack):
        visited[vertex] = True
        for neighbor in self.graph[vertex]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited, stack)
        stack.append(vertex)

    def transpose(self):
        transposed_graph = Graph(self.vertices)
        for vertex in self.graph:
            for neighbor in self.graph[vertex]:
                transposed_graph.add_edge(neighbor, vertex)
        return transposed_graph

    def dfs_scc(self, vertex, visited, scc):
        visited[vertex] = True
        scc.append(vertex)
        for neighbor in self.graph[vertex]:
            if not visited[neighbor]:
                self.dfs_scc(neighbor, visited, scc)

    def kosaraju(self):
        visited = [False] * self.vertices
        stack = deque()

        for vertex in range(self.vertices):
            if not visited[vertex]:
                self.dfs(vertex, visited, stack)

        transposed_graph = self.transpose()

        visited = [False] * self.vertices
        strongly_connected_components = []

        while stack:
            vertex = stack.pop()
            if not visited[vertex]:
                scc = []
                transposed_graph.dfs_scc(vertex, visited, scc)
                strongly_connected_components.append(scc)

        return strongly_connected_components
vertices = int(input("Enter the number of vertices: "))
edges = int(input("Enter the number of edges: "))
edge_list = [input().split() for _ in range(edges)]
graph = Graph(vertices)
for edge in edge_list:
    graph.add_edge(ord(edge[0]) - ord('A'), ord(edge[1]) - ord('A'))
scc_result = graph.kosaraju()
print(len(scc_result))
