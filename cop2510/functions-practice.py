

def HelloModule():
  print("Hello COP2510 Student!")


def LunchModule():
  print("Pizza for lunch today")

def BreakfastModule():
  print("Cereal for breakfast")

def DisplayValue(number):
  print("Your number is ", number)

def DoubleValue(number):
  double = number *2
  print("Your number is now : ", double)

def CalculateTotal(qty, price, name):
  total = qty * price
  print("The total amount for " , name, " is" , total)
  

def main():
  CalculateTotal(50, 7.77, "Mary")
  CalculateTotal(10, 9.99,"John")

  HelloModule()
  BreakfastModule()
  LunchModule()

  value = 100
  DisplayValue(value)
  DoubleValue(value)

  score = 95
  DisplayValue(score)

main()


