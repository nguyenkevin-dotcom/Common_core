class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age

class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, colour: str):
        super().__init__(name, height, age)
        self.colour = colour + " color"
    
    def bloom(self):
        print(f"{self.name} is blooming beautifully!")
    
class Tree(Plant):
    def __init__(self, name: str, height: int, age: int, trunk_diameter: int):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
    
    def produce_shade(self):
        shade = round(self.height / 6.41025641)
        print(f"{self.name} provides {shade} square meters of shade")

class Vegetable(Plant):
    def __init__(self, name: str, height: int, age: int, harvest_season: str, nutritional_value: str):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season + " harvest"
        self.nutritional_value = nutritional_value


if __name__ == "__main__":

    rose = Flower("Rose", 25, 30, "red")
    oak = Tree("Oak", 500, 1825, 50)
    tomato = Vegetable("Tomato", 80, 90, "summer", "C")
    
    plants = [rose, oak, tomato]
    print("=== Garden Plant Types ===")
    for plant in plants:
        if isinstance(plant, Flower):
            print(f"\n{plant.name} (Flower): {plant.height}cm, {plant.age} days, {plant.colour}")
            plant.bloom()
        elif isinstance(plant, Tree):
            print(f"\n{plant.name} (Tree): {plant.height}cm, {plant.age} days, {plant.trunk_diameter}cm diameter")
            plant.produce_shade()
        elif isinstance(plant, Vegetable):
            print(f"\n{plant.name} (Vegetable): {plant.height}cm, {plant.age} days, {plant.harvest_season}")
            print(f"{plant.name} is rich in vitamin {plant.nutritional_value}")


    

