def print_days(i, days):
    print(f"Day {i}")
    if i != days:
        print_days(i + 1, days)
    else:
        print("Harvest Time!")


def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    i = 1
    print_days(i, days)
