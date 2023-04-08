def reverse_convert(s):
    new_s = s.copy()
    new_s[0] = s[1]
    new_s[1] = s[2]
    new_s[2] = s[5]
    new_s[3] = s[0]
    new_s[4] = s[8]
    new_s[5] = s[3]
    new_s[6] = s[7]
    new_s[7] = s[6]
    new_s[8] = s[4]
    return new_s


def full_convert(s):
    for _ in range(31):
        s = reverse_convert(s)
    return "".join(s)


print(full_convert(list("УРЕАЯПИЦТ")))
