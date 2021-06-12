def group(x,l):
    g1=[]
    g=[]
    i=0
    while i<len(x):
        if(len(g1) < l):
            g1.append(x[i])
            i=i+1
        else:
            g.append(g1)
            g1=[]
    g.append(g1)
    return g
print (group([1,3,2,2,9,7,2,4],3))
    