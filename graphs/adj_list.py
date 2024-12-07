class Graph:
    def __init__(self):
        self.adj={}

    def add_Edges(self,u,v,direction):
        if u in self.adj:
            self.adj[u].append(v)
        else:
            self.adj[u]=[v]

        if direction == 0:
            if v in self.adj:
                self.adj[v].append(u)
            else:
                self.adj[v]=[u]


    def print_adjlist(self):
        for key, value in self.adj.items():
            print(f"Node {key}:")
            for neighbor in value:
                print(f"  Neighbor: {neighbor}")




def main():
    num_nodes=int(input("Enter the number of node: "))
    num_edges=int(input("Enter the number of edges: "))

    graph=Graph()

    for i in range (num_edges):
        u=int(input("add u: "))
        v=int(input("add v: "))

        graph.add_Edges(u,v,0)

    graph.print_adjlist()


if __name__=="__main__":
    main()