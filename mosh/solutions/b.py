def solve():
    cost, delivery_cost, free_delivery = map(int, input().split())
    if cost == free_delivery:
        return cost - 1 + delivery_cost
    if cost > free_delivery:
        sale = cost - free_delivery + 1
        cost_with_sale = cost - sale + delivery_cost
        return max(cost, cost_with_sale)
    return cost + delivery_cost


ans = ""
n = int(input())
for _ in range(n):
    ans += str(solve())
    ans += "\n"


with open("b.out.txt", "w") as f:
    f.write(ans)
