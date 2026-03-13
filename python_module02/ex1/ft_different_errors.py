def garden_operations(test):
    dict = {"garden_key": "_plant"}
    try:
        if "missing_key" in test:
            return dict[test]

        if isinstance(test, str) and ".txt" in test:
            with open(test, "r"):
                return

        test_int = int(test)

        test_int = test_int/0

    except ValueError as e:
        print("Testing ValueError...")
        print(f"Caught ValueError: {e}\n")
    except ZeroDivisionError as z:
        print("Testing ZeroDivisionError...")
        print(f"Caught ZeroDivisionError: {z}\n")
    except FileNotFoundError as f:
        print("Testing FileNotFoundError...")
        print(f"Caught FileNotFoundError: {f}\n")
    except KeyError as k:
        print("Testing KeyError...")
        print(f"Caught KeyError: {k}\n")
    return None


def test_error_types(tests):
    print("=== Garden Error Types Demo ===\n")
    for test in tests:
        garden_operations(test)


if __name__ == "__main__":
    tests = ["abc", "10", "missing.txt", "missing_key/_plant"]
    test_error_types(tests)
