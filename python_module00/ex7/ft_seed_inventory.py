def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    type = ["packets", "grams", "area"]
    try:
        if unit not in type:
            raise Exception("This unit does not belong to gardening group")
        text = ''
        if unit == "packets":
            text = f"{seed_type} seeds: {quantity} packet{'s' if quantity > 1 else ''} available"
        elif unit == "grams":
            text = f"{seed_type} seeds: {quantity} gram{'s' if quantity > 1 else ''} total"
        elif unit == "area":
            text = f"{seed_type} seeds: covers {quantity} square meters"
        print(text.capitalize())
    except Exception as e:
        print(e)


