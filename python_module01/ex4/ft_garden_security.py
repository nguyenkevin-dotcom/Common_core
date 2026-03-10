class SecurePlant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def _is_valid(self, value, field_name):
        if not isinstance(value, int):
            raise TypeError(f"The {field_name} must be integer")
        if value < 0:
            raise ValueError(f"\nInvalid operation attempted: {field_name} {value}{"cm" if field_name == "height" else " days"} [REJECTED]\nSecurity: {"Negative height rejected" if field_name == "height" else "Negative age rejected"}")
        return True
    
    @property
    def height(self):
        return self.__height
    
    @height.setter
    def height(self, value):
        if self._is_valid(value, "height"):
            self.__height = value
    
    def get_height(self):
        if self.__height > 0:
            print(f"Height updated: {self.__height}cm [OK]")

    def set_height(self, value):
        if self._is_valid(value, "height"):
            self.__height = value
            print(f"\nHeight updated. Updating data...\n")
            return True

    @property
    def age(self):
        return self.__age
    
    @age.setter
    def age(self, value):
        if self._is_valid(value, "age"):
            self.__age = value
    
    def get_age(self):
        if self.__age > 0:
            print(f"Age updated: {self.__age} days [OK]")

    def set_age(self, value):
        if self._is_valid(value, "age"):
            self.__age = value
            print(f"\nAge updated. Updating data...\n")
            return True

    def display_case(self):
        print("=== Garden Security System")
        print(f"Plant created: {self.name}")
        self.get_height()
        self.get_age()

if __name__ == "__main__":
    try:
        rose = SecurePlant("Rose", 25, 30)
        rose.display_case()
        rose.set_age(-5)
        if rose.set_height or rose.set_age:
            rose.display_case()
        print(f"\nCurrent plant: {rose.name} ({rose.height}cm, {rose.age} days)")
    except ValueError as e:
        print(e)
        print(f"\nCurrent plant: {rose.name} ({rose.height}cm, {rose.age} days)")
