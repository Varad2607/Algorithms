


def find_connected_componets(graph):
    def dfs(node,component):
        visited.add(node)
        component.append(node)
        for neighbour in graph[node]:
            if neighbour not in visited:
                dfs(neighbour,component)



    visited=set()
    components=[]

    for node in graph:
        if node not in visited:
            component=[]
            visited.add(node)
            dfs(node,component)
            components.append(component)

    return components

graph={0:[1,2],
        1: [0],
        2: [0],
        3: [4],
        4: [3]}

print(find_connected_componets(graph))