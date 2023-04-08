alf = 'абвгдежзийклмнопрстуфхцчшщъыьэюя'
for a in [[_ for _ in "врпвл терпраиэ вйзгцфпз"]]:
    for i in range(len(a) // 2):
        a[i], a[-1 - i] = a[-1 - i], a[i]
    for i in range(len(a)):
        if a[i] == " ":
            continue
        ind = alf.index(a[i]) - 2
        a[i] = alf[ind]
    for i in range(1, len(a), 2):
        a[i - 1], a[i] = a[i], a[i - 1]
    print(''.join(a))
