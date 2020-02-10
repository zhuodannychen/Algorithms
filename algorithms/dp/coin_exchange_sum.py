# Min number of coins to represent a value


def coin_change_with_no_rep(dp):
    # this finds the smallest coin value that's greater than the goal
    # function can be modified to a subset sum problem, and finds min number of coins required
    # MAX is infinite
    ans = MAX
    # if sum of all coins is smaller than goal, it's not possible to form goal value
    if sum(coins) < goal:
        print(sum(coins), n)
        return
    for coin in coins:
        for j in range(MAX, coin - 1, -1):
            if dp[j - coin] != MAX:
                dp[j] = min(dp[j], dp[j - coin] + 1)
                # finds min j that's greater than goal
                if j >= goal:
                    ans = min(ans, j)
    # ans is value formed, dp[ans] is number of coins needed
    print(ans, dp[ans])
    return


def coin_change_with_rep(dp, goal):
    ans = MAX
    for coin in coins:
        """
        for j in range(0, MAX+1):
            if coin <= j:
        """
        for j in range(coin, MAX+1):
            if dp[j - coin] != MAX:
                dp[j] = min(dp[j], dp[j-coin] + 1)
    print(dp[goal])
    return dp[goal]


# running code
MAX = int(1e6)
for i in range(int(input())):
    goal = int(input())
    n = int(input())
    coins = []
    dp = [MAX] * (MAX+1)
    dp[0] = 0
    for j in range(n):
        coins.append(int(input()))
    # coin_change_with_no_rep(dp)
    coin_change_with_rep(dp, goal)
