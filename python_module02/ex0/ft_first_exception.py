def check_temperature(temp_str: str):
    try:
        if not isinstance(temp_str, str):
            raise TypeError
        temp_int = int(temp_str)

        if temp_int > 40:
            raise ValueError("is too hot for plants (max 40°C)")
        if temp_int < 0:
            raise ValueError("is too cold for plants (min 0°C)")
        print(f"Temperature {temp_int}°C is perfect for plants!")
    except TypeError:
        print("is not a string")
    except ValueError as e:
        if 'invalid literal' in str(e):
            print(f"Error: {temp_str!r} is not a valid number")
        else:
            print(f"Error: {temp_str} {e}")


def test_temperature_input(temperatures):
    try:
        print("=== Garden Temperature Checker ===\n")

        for temperature in temperatures:
            print(f"Testing temperature: {temperature}")
            check_temperature(temperature)
            print()
    finally:
        print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    temperatures = ['25', 'abc', '100', '-50']

    test_temperature_input(temperatures)
