class GardenManager:
    total_gardens = 0

    def __init__(self, garden_name: str):
        self.garden_name = garden_name
        self.plants = []
        GardenManager.total_gardens += 1
    
    class GardenStats:
        @staticmethod
        def calculate_report(plants):
            total_growth = sum(p.growth_count for p in plants)
            return total_growth
    
    def add_plant(self, plant):
        self.plants.append(plant)
        if self.garden_name.lower() != "bob":
            print(f"Added {plant.name} to {self.garden_name}'s garden")
    
    def grow_plants(self):
        print(f"\n{self.garden_name} is helping all plants grow...")
        for plant in self.plants:
            plant.grow()

    def get_report(self):
        print(f"\n=== {self.garden_name}'s Garden Report ===")
        print("Plants in garden:")
        n_plant, n_flowering_plant, n_prize_flower = 0, 0, 0
        for plant in self.plants:
            if isinstance(plant, PrizeFlower):
                if self._is_valid(plant.height):
                    print(f"- {plant.name}: {plant.height}cm, {plant.flowers_color}, Prize points: {plant.prize_points}")
                    n_prize_flower += 1
            elif isinstance(plant, FloweringPlant):
                if self._is_valid(plant.height):
                    print(f"- {plant.name}: {plant.height}cm, {plant.flowers_color}")
                    n_flowering_plant += 1
            elif isinstance(plant, Plant):
                if self._is_valid(plant.height):
                    print(f"- {plant.name}: {plant.height}cm")
                    n_plant += 1
        n_total_plants = n_prize_flower + n_flowering_plant + n_plant
        print(f"\nPlants added: {n_total_plants}, Total growth: {GardenManager.GardenStats.calculate_report(self.plants)}")
        print(f"Plant types: {n_plant} regular, {n_flowering_plant} flowering, {n_prize_flower} prize flowers")
    
    @classmethod
    def create_garden_network(cls, gardens):
        scores = {g.garden_name: sum(p.height for p in g.plants) for g in gardens}
        print("Garden scores - " + ", ".join([f"{k}: {v}" for k, v in scores.items()]))

    @staticmethod
    def _is_valid(value: int):
        return value > 0

class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height
        self.growth_count = 0

    def grow(self, value=1):
        self.height += value
        self.growth_count += value
        print(f"{self.name} grew {self.growth_count}cm")

    @property
    def height(self):
        return self.__height

    @height.setter
    def height(self, value: int):
        if GardenManager._is_valid(value):
            self.__height = value
            return True

class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, flowers_color: str):
        super().__init__(name, height)
        self.flowers_color = flowers_color + " flowers (blooming)"

class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, flowers_color: str, prize_points: int):
        super().__init__(name, height, flowers_color)
        self.prize_points = prize_points

def format_label(name: str):
    return name.upper()


if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")
    
    # Setup Alice's Garden
    alice_garden = GardenManager("Alice")
    alice_garden.add_plant(Plant("Oak Tree", 100))
    alice_garden.add_plant(FloweringPlant("Rose", 25, "red"))
    alice_garden.add_plant(PrizeFlower("Sunflower", 50, "yellow", 10))

    # Growth cycle
    alice_garden.grow_plants()
    # Analytics
    alice_garden.get_report()
    
    # Setup Bob's Garden
    bob_garden = GardenManager("Bob")
    bob_garden.add_plant(Plant("Bush", 92))

    # # Growth cycle
    # bob_garden.grow_plants()
    # # Analytics
    # bob_garden.get_report()
    
    GardenManager.create_garden_network([alice_garden, bob_garden])
    plants_height_validation_alice = all(alice_garden._is_valid(plant.height) for plant in alice_garden.plants)
    plants_height_validation_bob = all(bob_garden._is_valid(plant.height) for plant in bob_garden.plants)
    plants_height_validation = [plants_height_validation_bob, plants_height_validation_alice]
    print(f"\nHeight validation test: {all(plants_height_validation)}")
    print(f"Total gardens managed: {GardenManager.total_gardens}")