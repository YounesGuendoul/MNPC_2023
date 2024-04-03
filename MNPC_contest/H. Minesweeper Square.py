dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
 
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    w = []
    for _ in range(n):
        w.append(input().strip())
    
    v = []
    for i in range(n):
        for j in range(m):
            if w[i][j] == '?':
                sp = False
                for k in range(8):
                    x = dx[k]
                    y = dy[k]
                    if 0 <= i+x < n and 0 <= j+y < m and w[i+x][j+y] != '?':
                        sp = True
                if sp:
                    v.append((i, j))
 
    b = [[-7] * m for _ in range(n)]
    b0 = [[-7] * m for _ in range(n)]
 
    for i in range(n):
        for j in range(m):
            if w[i][j] != '?':
                b[i][j] = int(w[i][j])
 
    b0 = [row[:] for row in b]
    l = len(v)
    vis = [False] * l
    g = 1 << l
    max0 = 0
    
    for i in range(g):
        b = [row[:] for row in b0]
        sp = True
        k = 0
 
        for j in range(l):
            if i & (1 << j) != 0:
                k += 1
                a, c = v[j]
                for k in range(8):
                    x = dx[k]
                    y = dy[k]
                    if 0 <= a+x < n and 0 <= c+y < m:
                        if b[a+x][c+y] != -7:
                            if b[a+x][c+y] == 0:
                                sp = False
                            else:
                                b[a+x][c+y] -= 1
 
        for a in range(n):
            for c in range(m):
                if b[a][c] != -7 and b[a][c] != 0:
                    sp = False
 
        if sp:
            for j in range(l):
                if i & (1 << j) != 0:
                    vis[j] = True
 
    max0 = 0
    for i in range(l):
        if not vis[i]:
            max0 += 1
    print(max0)