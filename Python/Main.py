import random
#Coin tossing funtion 
def coinToss():
    coin = ['Heads', 'Tails']
    choice = random.choices(coin, k=10)
    print(choice)

coinToss()