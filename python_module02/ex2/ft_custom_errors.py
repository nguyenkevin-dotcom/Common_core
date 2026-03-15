class GardenError(Exception):
    """
    A basic error for garden problems
    """
    pass


class PlantError(GardenError):
    """
    For problems with plants (inherits from GardenError)
    """
    pass


class WaterError(GardenError):
    """
    For problems with watering (inherits from GardenError)
    """
    pass


def custom_errors(plant: str, height: int = 21, ml_water: int = 11):
    print("=== Custom Garden Errors Demo ===")

    print("\nTesting PlantError...")
    try:
        if height < 20:
            raise PlantError(f"The {plant} plant is wilting!")
    except PlantError as p:
        print(f"Caught PlantError: {p}")

    print("\nTesting WaterError...")
    try:
        if ml_water < 10:
            raise WaterError("Not enough water in the tank!")
    except WaterError as w:
        print(f"Caught WaterError: {w}")

    errors = [
        PlantError(f"The {plant} plant is wilting!"),
        WaterError("Not enough water in the tank!")
    ]

    print("\nTesting catching all garden errors...")
    for err in errors:
        try:
            raise err
        except GardenError as g:
            print(f"Caught a garden error: {g}")
    print("\nAll custom error types work correctly")


if __name__ == "__main__":
    custom_errors("tomato", 10, 5)
