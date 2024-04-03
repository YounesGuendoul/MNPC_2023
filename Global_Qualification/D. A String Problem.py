
s = input()
n = int(input())
for _ in range(n):
    line = input().split()
    if line[0] == "0":
        id = int(line[1]) - 1
        s = s[:id] + line[2][0] + s[id+1:]
    else:
        index = s.find(line[1])
        if index == -1:
            print(-1)
        else:
            print(index + 1)

