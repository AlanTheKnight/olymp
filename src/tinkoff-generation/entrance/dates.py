s = input() 
sf = list(enumerate(map(int, s.split('/'))))


days_in_months = {
    1: 31,
    2: 29,
    3: 31,
    4: 30,
    5: 31,
    6: 30,
    7: 31,
    8: 31,
    9: 30,
    10: 31,
    11: 30,
    12: 31,
}


def is_special(year):
    return (year % 4 == 0) and (year % 100 != 0) or (year % 400 == 0)


def transform_year(comb):
    i, year = comb
    if year == 0: return i, 2100
    return i, 2000 + year


def to_ddmmyy(day, month, year):
    day, month = map(lambda x: str(x).zfill(2), [day, month])
    return f"{day}/{month}/{str(year % 100).zfill(2)}"



years = list(map(transform_year, [i for i in sf if 0 <= i[1] <= 99]))


ans = set()
cnt = 0
for yi, year in years:
    other = [i for i in sf if i[0] != yi]
    months = [i for i in other if 1 <= i[1] <= 12]
    for mi, month in months:
        day = [d for di, d in other if di != mi and 1 <= d <= 31]
        if not day: continue
        day = day[0]
        if month == 2:
            if is_special(year):
                if 1 <= day <= 29:
                    ans.add(to_ddmmyy(day, month, year))
            else:
                if 1 <= day <= 28:
                    ans.add(to_ddmmyy(day, month, year))
        else:
            if 1 <= day <= days_in_months[month]:
                ans.add(to_ddmmyy(day, month, year))

if not len(ans):
    print("No such date")
else:
    print(*ans, sep="\n")
