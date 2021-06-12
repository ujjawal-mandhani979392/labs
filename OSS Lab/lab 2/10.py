filename = "test.txt"
f = open(filename, 'r+')
lines = f.readlines()
for x in lines:
    print(x[-1::-1])
f.close()