testfile = open("test.txt")
lines = testfile.readlines()
for line in reversed(lines):
    print(line)
testfile.close()