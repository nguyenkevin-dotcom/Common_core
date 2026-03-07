from ex0.ft_garden_intro import Plant


def print_stats(day, plant):
    print(f"=== Day {day} ===")
    print(f"{plant.name}: {plant.height}cm, {plant.current_age} days old")


def get_info(plant):
    height = plant.height

    day = 1
    days = int(input("Days skip: "))

    print_stats(day, plant)
    while day <= days:
        if day == days:
            print_stats(day, plant)
            break
        plant.grow()
        plant.age()
        day += 1
    height_diff = plant.height - height
    print(f"Growth this week: {"+" if height_diff >= 0 else ""}{height_diff}cm")


if __name__ == "__main__":

    plant = Plant("Rose", 25, 30)
    get_info(plant)
