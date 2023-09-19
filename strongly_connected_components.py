from collections import defaultdict
# graph should be given as a dictionary of outneighbors for each node
# for ex, if 1 is said to have an outneighborhood of 2,3,5, then the
# dictionary entry should look like 1: [2,3,5]
def strongly_connected_components(graph,n):
    L = []
    visited = [False] * (n+1)
    in_neighbors = defaultdict(list)
    for i,j in graph.items():
        for k in j:
            in_neighbors[k].append(i)

    def visit(u):
        if not visited[u]:
            visited[u] = True
            for k in graph[u]:
                visit(k)
            L.append(u)

    components = defaultdict(lambda: -1)
    def assign(u,root):
        if components[u] == -1:
            components[u] = root
            for k in in_neighbors[u]:
                assign(k,root)

    for i in graph.keys():
        visit(i)

    L = L[::-1]

    for i in L:
        assign(i,i)

    print('\n'.join(f'{i}: {j}' for i,j in components.items()))