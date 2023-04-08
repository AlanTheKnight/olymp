def sieve_of_eratosthenes(num):
    prime = [True for i in range(num+1)]
    p = 2
    while (p * p <= num):
        if prime[p]:
            for i in range(p * p, num+1, p):
                prime[i] = False
        p += 1

    for p in range(2, num+1):
        if prime[p]:
            yield p


def binary_search(a, x, lo=0, hi=None):
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        midval = a[mid]
        if midval < x:
            lo = mid+1
        elif midval > x:
            hi = mid
        else:
            return mid
    return -1


primes = list(sieve_of_eratosthenes(12345678))

mn = [10 ** 10, None]
for i in primes:
    j = (12345678 - i)
    if j < 0:
        break
    if binary_search(primes, j) != -1 and abs(i - j) < mn[0]:
        mn = [abs(i - j), i]

print(min(mn[1], 12345678 - mn[1]))
