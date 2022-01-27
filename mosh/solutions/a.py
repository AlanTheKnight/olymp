from math import ceil, log10


FILENAME = "a.out"
TRANSITIONS = [4, 5, 2, 3, 3, 1, 5, 4, 1, 2]


def nth_digit(num, index):
    return num // (10 ** (index)) % 10


def num_length(num):
    return ceil(log10(num + 1))


def prefix_sum(arr):
    res = [0]
    cur = 0
    for i in arr:
        cur += i
        res.append(cur)
    return res


def get_first_digit(num):
    return nth_digit(num, num_length(num) - 1)


TRANS_FROM_ZERO = prefix_sum(TRANSITIONS)
TRANS_FROM_ONE = prefix_sum(TRANSITIONS[1:10])
TRANS_SUM = 30
ONE_ON = 2


def solve(n):
    # Длина числа
    l = num_length(n)

    # Заранее просчитываем количество изменений, когда
    # в ведущем разряде появляется единица:
    # 2 * (длина числа - 1)
    ans = ONE_ON * (l - 1)

    # Просчитываем количество изменений в старшем разряде
    if l > 1:
        ans += TRANS_FROM_ONE[get_first_digit(n) - 1]
    
    # Количество изменений в младшем разряде
    ans += TRANS_SUM * (n // 10) + TRANS_FROM_ZERO[nth_digit(n, 0)]

    for i in range(1, l - 1):
        cycles_before = n // (10 ** (i + 1))
        ans += TRANS_SUM * cycles_before
        ans += TRANS_FROM_ZERO[nth_digit(n, i)]
    return ans

answer = ""
t = int(input())
for _ in range(t):
    answer += str(solve(int(input())))
    answer += "\n"

with open(FILENAME, "w") as f:
    f.write(answer)
