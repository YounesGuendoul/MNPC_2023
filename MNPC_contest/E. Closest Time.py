def u(g):
    a = int(g[:2])
    b = int(g[3:])
    S = a * 60 + b
    return S

def check(s):
    a = int(s[:2])
    b = int(s[3:])
    if a >= 24 or b >= 60:
        return False
    return True

def f(tst, s2):
    global k0, ans
    if not check(tst):
        return
    d = min(abs(u(tst) - u(s2)), 24 * 60 - abs(u(tst) - u(s2)))
    if k0 > d:
        k0 = d
        ans = tst

t = int(input())
for _ in range(t):
    s1, s2 = input().split()
    sp = False
    l = [10] * 5
    for i in range(len(s1)):
        if s1[i] == '?':
            sp = True
    if not sp:
        print(s1)
        continue
    g = "0123456789"
    tst = s1
    k0 = 1e9
    for i in range(3):
        for j in range(10):
            for k in range(7):
                for d in range(10):
                    if s1[0] == '?':
                        tst = tst[:0] + g[i] + tst[1:]
                    if s1[1] == '?':
                        tst = tst[:1] + g[j] + tst[2:]
                    if s1[3] == '?':
                        tst = tst[:3] + g[k] + tst[4:]
                    if s1[4] == '?':
                        tst = tst[:4] + g[d]
                    f(tst, s2)
    print(ans)
