from ex0.ft_garden_intro import Plant

def ft_plant_factory(plants: list):
    counter = 0
    if plants == []:
        print("There are no plants")
    else:
        print("=== Plant Factory Output ===")
        for plant in plants:
            print(f"Created: {plant.name} ({plant.height}cm, {plant.current_age} days old)")
            counter += 1
        print(f"\nTotal plants created: {counter}")

if __name__ == "__main__":
    
    plant01 = Plant("Rose", 25, 30)
    plant02 = Plant("Oak", 200, 365)
    plant03 = Plant("Cactus", 5, 90)
    plant04 = Plant("Sunflower", 80, 45)
    plant05 = Plant("Fern", 15, 120)

    plants = [plant01, plant02, plant03, plant04, plant05]
    ft_plant_factory(plants)
