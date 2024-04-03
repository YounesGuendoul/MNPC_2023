def multiply_list(lst):
    result = 1
    for element in lst:
        result *= element
    return result
 
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    print(sum(l)*multiply_list(l))