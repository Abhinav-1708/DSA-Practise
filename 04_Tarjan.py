from collections import defaultdict

class TarjanSCC:
    def __init__(self, graph):
        self.graph = graph
        self.time = 0
        self.stack = []
        self.lowlink = {}
        self.ids = {}
        self.sccs = []

    def _dfs(self, node):
        self.lowlink[node] = self.ids[node] = self.time
        self.time += 1
        self.stack.append(node)

        for neighbor in self.graph[node]:
            if neighbor not in self.ids:
                self._dfs(neighbor)
                self.lowlink[node] = min(self.lowlink[node], self.lowlink[neighbor])
            elif neighbor in self.stack:
                self.lowlink[node] = min(self.lowlink[node], self.ids[neighbor])

        if self.lowlink[node] == self.ids[node]:
            scc = []
            while True:
                current = self.stack.pop()
                scc.append(current)
                if current == node:
                    break
            self.sccs.append(scc)

    def find_sccs(self):
        for node in self.graph:
            if node not in self.ids:
                self._dfs(node)

        return self.sccs


num_vertices = int(input("Enter the number of vertices: "))
num_edges = int(input("Enter the number of edges: "))

graph = defaultdict(list)


print("Enter the edges (format: <start> <end>):")
for _ in range(num_edges):
    edge = input()
    start, end = edge.split()
    graph[start].append(end)


tarjan = TarjanSCC(graph)
sccs = tarjan.find_sccs()

print("Number of Strongly Connected Components:",len(sccs))
