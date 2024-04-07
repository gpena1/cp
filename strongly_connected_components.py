# this code assumes that all edges are distinct
# that is, if you have an edge (u,v) and another edge (a,b), they are
# considered duplicates if u == a and v == b.
out_neighbors = {
    'a': ['f'],
    'b': ['a','c','e'],
    'c': ['f'],
    'd': [],
    'e': ['d'],
    'f': ['b','e']
}
in_neighbors = {}
for i,j in out_neighbors.items():
    for k in j:
        if k not in in_neighbors: in_neighbors[k] = []
        in_neighbors[k].append(i)


v = set()
ordering = []
def visit(u):
    if u in v: return
    v.add(u)
    for k in out_neighbors[u]:
        visit(k)
    ordering.append(u)

components = {}
def assign(u,v):
    if u in components: return
    components[u] = v
    for k in in_neighbors[u]:
        assign(k,v)

for i in 'abcdef':
    visit(i)

for i in ordering[::-1]:
    assign(i,i)

component_nodes = {}
for i,j in components.items():
    if j not in component_nodes: component_nodes[j] = []
    component_nodes[j].append(i)

print(component_nodes)
