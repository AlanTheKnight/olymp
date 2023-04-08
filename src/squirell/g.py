for f1 in range(4, 10):
    for f2 in range(4, 10):
        for f3 in range(3, 10):
            a, b, c = int("311", f1), int("213", f2), int("121", f3)
            if a == b == c:
                print(a, b, c)
