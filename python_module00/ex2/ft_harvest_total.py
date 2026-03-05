def ft_harvest_total():
    harvest = 0
    for i in range(1, 4):
        harvest = harvest + int(input(f"Day {i} harvest: "))
    print(f"Total harvest: {harvest}")
