def solve(n):
    ans = [0] * 10
    for d in range(10):
        x = 100 if d == 0 else d
        cnt = 1 if d == 0 else 0
        while x <= n:
            cnt += 1
            x *= 10
            x += d
        ans[d] = cnt
    converted_string = ' '.join(map(str, ans))
    return converted_string
 
t = int(input())
for _ in range(t):
    n = int(input())
    print(solve(n))