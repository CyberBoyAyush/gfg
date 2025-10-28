from collections import deque
class Solution:
	def nearest(self, grid):
		q=deque([])
		ans=[[-1]*(len(grid[0])) for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    q.append((i,j,0))
                    ans[i][j]=0
        
        d=[
            [0,1],
            [1,0],
            [-1,0],
            [0,-1]
        ]
        while q:
            i,j,dis=q.popleft()
            for k in d:
                x,y=i+k[0],j+k[1]
                if 0<=x<len(grid) and 0<=y<len(grid[0]) and ans[x][y]==-1:
                    ans[x][y]=dis+1
                    q.append((x,y,dis+1))
        return ans