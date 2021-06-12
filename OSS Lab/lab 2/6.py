filename = "test.txt"
filehandle = open(filename,"w")
filehandle.write("\nNew line")
filehandle.write("\nNew Content")
filehandle.close()
f=open(filename,"r")
while True:
    line = f.readline()
    if not line:
        break
    print(line)
f.close()

