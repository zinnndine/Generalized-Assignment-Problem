

def mn(c,n,m):
    k=c[1][1]
    b= 1
    a=1
    for i in range(0,m):
        for j in range(0,n):
            if(c[i][j]<k ):
                k = c[i][j]
                a=i
                b=j
    if k==10000:
        return -1,-1,-1
    return k,a,b



def main (tm,p,c,n,m):

    T = [j+1 for j in range(0,n)]
    aff=[]
    Ct=0

    while(len(T)!=0):
        minimum,a,b = mn(c,n,m)
        if minimum ==-1:
            return [[0,0],[0,0]]
        if(p[a][b]<=tm[a]):
            tm[a]-=p[a][b]
            Ct+=c[a][b]
            aff.append([b+1,a+1])
            T.remove(int(b+1))
            for j in range(0,m):
                c[j][b] = 10000 
        else:
            c[a][b] = 10000
        

    return aff

