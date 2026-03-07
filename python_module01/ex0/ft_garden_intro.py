class Plant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.current_age = age

    def print_information(self):
        print("=== Welcome to My Garden ===")
        print(f"Plant: {self.name}")
        print(f"Height: {self.height}cm")
        print(f"Age: {self.current_age} days\n")
        print("=== End of Program ===")

    def grow(self):
        self.height = self.height + 1

    def age(self):
        self.current_age = self.current_age + 1


if __name__ == "__main__":
    plant = Plant("Rose", 25, 30)
    plant.grow()
    plant.age()
    plant.print_information()
