class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: None Do not return anything, modify rooms in-place instead.
        """
        r = len(rooms)
        c = len(rooms[0])
        q = []
        d = [0,1,0,-1,0]
        for i in range(r):
            for j in range(c):
                if rooms[i][j] == 0:
                    q.append((i,j))
        
        level = 1

        while q:
            for i in range(len(q)):
                x,y = q.pop(0)
                for z in range(4):
                    nX,nY= x + d[z], y + d[z+1]

                    if nX < 0 or nX >= r or nY < 0 or nY >= c:
                        continue
                    
                    if level >= rooms[nX][nY]:
                        continue
                    
                    rooms[nX][nY] = level
                    q.append((nX,nY))
            level += 1
