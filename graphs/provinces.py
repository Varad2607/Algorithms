from collections import defaultdict
# For graph based question try to  make adjacency list always its easy to read 


class Solution:
    def __init__(self):
        pass

    def findCirclenum(self,isConnected:list[list[int]])->int:
        def dfs(node):
            for neigbour in graph[node]:
                if neigbour not in seen:
                    seen.add(neigbour)
                    dfs(neigbour)





        n=len(isConnected)
        graph=defaultdict(list)
        for i in range (n):
            for j in range(i+1,n):
                if isConnected[i][j]:
                    graph[i].append(i)
                    graph[j].append(j)
        
        seen=set()

        


