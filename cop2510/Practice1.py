#Matt Velazquez
#8/26/13
#Practice Exercise

print('my name is Matt Velazquez')

item = input("Enter item description: ")
price = float (input("Enter price: "))
qty = int(input("Enter the quantity: "))

#Calculate Total
total = price * qty
print(price, qty  ,sep='^')

print("Item\tPrice\tQty")
print(item, price,qty, sep='\t')


print("The total amount is", format(total,'.2f'))

