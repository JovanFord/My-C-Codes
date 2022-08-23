# total = 0
# for num in range(2,101, 2):
#     total += num
# print(total)

for i in range(1,101):
    if i % 5 == 0 and i % 3 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else: 
     print(i)
