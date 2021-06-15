import sys


def read_file(X):
    file = open(sys.argv[1], "r")
    str = file.read()
    is_less = True
    str1 = str.split()
    for i in str1:
        if len(i) > X:
            is_less = False
            break

    if is_less:
        return True

    res = ""
    for i in str.split():
        if len(i) <= X:
            res = res + i + " "

    resfinal = ""
    for j in res:
        if j == 'c':
            resfinal = resfinal + 'd'
        else:
            resfinal = resfinal + j

    return resfinal


X = int(sys.argv[2])
print(read_file(X))
