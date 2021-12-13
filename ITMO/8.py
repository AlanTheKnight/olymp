left = 494
evil_counter = 0
kind_counter = 0
day = 0
while left > 0:
    day += 1
    left -= 1
    evil_counter += 1
    kind_counter += 1

    if evil_counter == 10 and kind_counter == 3:
        if left >= 10:
            left -= 10
        else:
            left = 0
        kind_counter = 0
        print(f'Day {day} - {left}')
        continue

    if evil_counter == 10:
        left += 15
        evil_counter = 0
        print(f'Day {day} - {left}')
        continue

    if kind_counter == 3:
        if left >= 10:
            left -= 10
        else:
            left = 0
        kind_counter = 0
        print(f'Day {day} - {left}')
print(day)
