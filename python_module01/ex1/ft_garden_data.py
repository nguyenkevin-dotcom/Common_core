from ex0.ft_garden_intro import Plant

if __name__ == "__main__":

    plant01 = Plant("Rose", 25, 30)
    plant02 = Plant("Sunflower", 80, 45)
    plant03 = Plant("Cactus", 15, 120)

    plants = [plant01, plant02, plant03]

    print("=== Garden Plant Registry ===")
    for plant in plants:
        print(f"{plant.name}: {plant.height}cm, {plant.age} days old")
