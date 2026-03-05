def ft_water_reminder():
    days = int(input("Days since last watering: "))
    if days > 2:
        print("Water the plants!")
    elif days < 0:
        raise Exception("Days cannot go negative, right?")
    else:
        print("Plants are fine")
