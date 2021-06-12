def lensort(list):
    list.sort(key=lambda s: len(s))
    return list

print(lensort(['python', 'perl', 'java', 'c', 'haskell', 'lisp', 'ocaml', 'smalltalk', 'ruby']))