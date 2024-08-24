import sys

for line in sys.stdin:

    a = list(map(int, line.split()))
    a = a[:-1]

    ans = a[0]

    for i in range(len(a)):
        prod = 1
        for j in range(i, len(a)):
            prod *= a[j]
            ans = max(ans, prod)

    print(ans)

    