import numpy as np
x = np.array(['2', 'ab', '234', '1234', '12345'])
print("\nOriginal Array:")
print(x)
r = np.char.ljust(x, 5, '0')
print("\nNumeric string of 5 digits with zeros:")
print(r)
