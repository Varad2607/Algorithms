from typing import List
from collections import deque


class Solution:
    def bfs_of_graph(self,adj:List[List[int]])->List[int]:
        visited_node={}

        for i in range (len(adj)):
            visited_node[i]=False

        
        q=deque()
        ans=[]

        q.append(0)
        visited_node[0]=True

        while q:
            current_node=q.popleft()
            ans.append(current_node)

            for neighbour in adj[current_node]:
                if not visited_node[neighbour]:
                    visited_node[neighbour]=True
                    q.append(neighbour)


        return ans

        