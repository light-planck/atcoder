import sys, math, bisect
from collections import defaultdict, deque
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def calc_sum(x, cnt):
    return x * cnt * (cnt + 1) // 2

    
def main():
    n, a, b = map(int, input().split())
    
    sum = n * (n+1) // 2
    ans = None

    if math.gcd(a, b) == 1:
        cnt_a = n // a
        sum_a = calc_sum(a, cnt_a)
        
        cnt_b = n // b
        sum_b = calc_sum(b, cnt_b)

        ab = a * b
        cnt_ab = n // ab
        sum_ab = calc_sum(ab, cnt_ab)
        
        ans = sum - sum_a - sum_b + sum_ab
    else:
        x = min(a, b)
        cnt_x = n // x
        sum_x = calc_sum(x, cnt_x)
        
        ans = sum - sum_x
    
    print(ans)


if __name__ == '__main__':
    main()