n = int(input())
h = list(map(int, input().split()))

INF = 10 ** 9

# dp[i + 1] i番目の足場まで到達するのに支払ったコストの最小値
dp = [INF] * n
dp[0] = 0

for i in range(n):
    if dp[i] == INF:
        continue

    if i + 1 < n:
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]))

    if i + 2 < n:
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]))

print(dp[n - 1])