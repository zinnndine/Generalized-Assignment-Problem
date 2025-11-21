
def mn(p,n,m):
    k=p[1][1]
    b= 1
    a=1
    for i in range(0,n):
        for j in range(0,m):
            if(p[i][j]<k):
                k = p[i][j]
                a=i
                b=j
    if k==10000:
        return -1,-1,-1
    return k,a,b



def main (tm,p,c,m,n):
    T=[j+1 for j in range(m)]
    Ct=0
    aff=[]

    while(len(T)!=0):
        minimum,a,b = mn(p,n,m)
        if minimum ==-1:
            return [[0,0],[0,0]]
        if(p[a][b]<=tm[a]):
            tm[a]-=p[a][b]
            Ct+=c[a][b]
            aff.append([b+1,a+1])
            T.remove(int(b+1))
            for j in range(0,n):
                p[j][b] = 10000
            
        else:
            p[a][b] = 10000
    return aff

