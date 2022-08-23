bill = int(input("How much was the bill? $"))
tip = float(input("What percent tip are you going to tip?"))
split = int(input("How many people are you spliting it with?"))
tip = (tip / 100) + 1
total = bill * tip
newTotal = total / split
newTotal = "{:.2f}".format(newTotal)
print("Each person should pay: $", newTotal)