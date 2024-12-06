class Graph:

    def __init__(self,num_nodes):
        self.adj=[[]for _ in range(num_nodes)]

    def addEdge(self,u,v,direction):
        # Add edge u->v
        self.adj[u].append[v]

        if direction==0:
            self.adj[v].append(u)

    def print_adjlist(self):
        for i in range (len(self.adj)):
            print(f"{i}->",end=" ")
            for neighbour in self.adj[i]:
                print(neighbour, end=" , ")

        print()

    def main():
        num_nodes=int(input("Enter the node"))
        num_edges=int(input("Enter the edge to the node"))
        direction=int(input("Enter the diretcion"))

        graph=Graph(num_nodes)

        for _ in range(num_edges):
            


