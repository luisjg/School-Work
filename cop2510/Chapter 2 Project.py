#Programming Excersise 4
#Matt Velazquez 9/07/13

#Input & Define Items 1-5
item1 = float(input('Enter price of your first item: '))
item2 = float(input('Enter price of your second item: '))
item3 = float(input('Enter price of your third item: '))
item4 = float(input('Enter price of your fourth item: '))
item5 = float(input('Enter price of your fifth item: '))
tax_rate = float(format(0.06, '.2f'))

#Calculations
subtotal = (item1 + item2 + item3 + item4 + item5)
tax = (subtotal * tax_rate)
total = (subtotal + tax)

#Displays
print('Subtotal: ',format(subtotal,'.2f'))
print('Sales Tax: $',format(tax,'.2f'))
print('Total: $',format(total,'.2f'))
