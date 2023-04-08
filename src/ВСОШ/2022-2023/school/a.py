a = int(input())
b = int(input())
t = int(input())

f = a * ((t // a) + (0 if t % a == 0 else 1))
s = b * ((t // b) + (0 if t % b == 0 else 1))
print(min(f - t, s - t))
