from typing import List
from collections import deque

class Solution:
    def bfs_of_graph(self,adj:List[List[int]])->List[int]:
        visited_node={}
        for lst in adj:
            if lst:
                visited_node[lst[0]]=False

        q=deque
        ans=[]

        q.append(adj[0][0])
        visited_node[adj[0][0]]=True

        while q is not q.empty:
            first_node=q.popleft()
            ans.append(first_node)

            for neighbour in adj[first_node-1]:
                if not visited_node[neighbour]:
                    visited_node[neighbour]=True
                    q.append(neighbour)

        

