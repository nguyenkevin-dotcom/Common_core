from ex0.ft_garden_intro import Plant


def print_stats(day, plant):
    print(f"=== Day {day} ===")
    print(f"{plant.name}: {plant.height}cm, {plant.current_age} days old")


def get_info(plant):
    height = plant.height

    day = 1
    days = 7

    print_stats(day, plant)
    for day in range(days):
        if day + 1 == days:
            print_stats(day + 1, plant)
            height_diff = plant.height - height
            print(f"Growth this week: {height_diff:+}cm")
            return
        plant.grow()
        plant.age()
        day += 1


if __name__ == "__main__":

    plant = Plant("Rose", 25, 30)
    get_info(plant)
