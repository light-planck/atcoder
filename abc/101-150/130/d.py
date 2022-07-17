import sys

def main():
    input = sys.stdin.readline

    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    right = 0
    sum = 0
    cnt = 0
    for left in range(n):
        while right < n and sum < k:
            sum += a[right]
            right += 1
        
        if sum < k:
            break
        
        cnt += n - right + 1
        sum -= a[left]

    print(cnt)

if __name__ == '__main__':
    main()