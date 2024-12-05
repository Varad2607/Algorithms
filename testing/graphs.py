class graph:
    def __init__(self):
        self.adj={}

    def addEdge(self,v,u,direction):
        if u in self.adj:
             self.adj[u].append(v)
        else:
            self.adj[u]=[v]
        if direction==0:
            if v in self.adj:
                self.adj[v].append(u)
            else:
                self.adj[v]=[u]
        

    def print_adjlist(self):
        for key, value in self.adj.items():
            print(key,"-> ")
            for i in range (len(value)):
                print(i,",")

def main():
    data=int(input("Enter the number of nodes"))
    data_2=int(input("ENter the edges"))
    directed_graph=graph()



    for i in range (0,data_2):
        u=int(input("addu"))
        v=int(input("addv"))
        # creating undirected graph
        directed_graph.addEdge(v,u,0)

    directed_graph.print_adjlist()


if __name__ =="__main__":
    main()











    










        



