s1 = "Шцлиц эцадгнюизх 15 гдхчжх ю шыжгйзт 13 ъыацчжх".lower()
s2 = "101 идгг ъдчсидя гыкию ъцбю -40 еждмыгидш уккыаиюшгдзию ацеюицбдшбдьыгюя".lower()
s3 = "Эцъцяиы задждзит шжцпыгюх адбыгнцидщд шцбц ш 124 ежю йщбы -63".lower()

alp = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя 0123456789-"
let = {}
for i in alp:
    let[i] = i


def delt(a, b):
    for i in range(len(a)):
        let[a[i]] = b[i]


def get(s):
    for i in s:
        print(let[i], end='')
    print()


delt("г", "е")


def see():
    for i in [s1, s2, s3]:
        get(i)


see()
"""
Шцлиц эцадгнюизх 15 гдхчжх ю шыжгйзт 13 ъыацчжх
101 идгг ъдчсидя гыкию ъцбю -40 еждмыгидш уккыаиюшгдзию ацеюицбдшбдьыгюя
Эцъцяиы задждзит шжцпыгюх адбыгнцидщд шцбц ш 124 ежю йщбы -63
"""
