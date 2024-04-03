def winner_of_game(N, K):
    if N % (K + 1) == 0:
        return "Abdelghafour"
    else:
        return "Khalil"
 
N, K = map(int, input().split())
print(winner_of_game(N, K))

