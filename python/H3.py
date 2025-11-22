
tm = []
                
p = []
                
c = []

n = 0
m= 0
temps_left = []
copy_c = []
T=[]
Ct=0
affictaion = []
huge=100000
z=[]
r=[]
hz=[]
zero_bare = []
croise =[]
xcroise =[]
croisment_complete = False

def min_lign(c,i):
    k=c[i][0]
    for j in range(0,max(n,m)):
        if(c[i][j]<k):
                k = c[i][j]
    return k

def min_col(c,j):
    k=c[0][j]
    for i in range(0,max(n,m)):
        if(c[i][j]<k):
                k = c[i][j]
    return k

def cpying():
    temp_c = []
    temp_c.clear()
    for i in range(0,n):
        temp_c.append([])  
        for j in T:
                temp_c[i].append(c[i][j-1]) 
    return temp_c

def zero(zero_bare,x):
    zero_bare.clear()
    for i in range(0,max(n,m)):
        zero_bare.append([])
        for j in range(0,max(n,m)):
            if x[i][j]==0:
                zero_bare[i].append(3) 
            else:
                zero_bare[i].append(0) 
    return zero_bare


def suming(zero_bare , ch ,tn , tm ,l,y): 
    k=0
    for i in range(l,tn):
        for j in range(y,tm):
           if zero_bare[i][j] == ch :
                k=k+1
    return k


def min_matrix(c,vector_min_ligne,vector_min_coloumn,ch):
    if ch ==1:
        for i in range(0,max(n,m)):
            vector_min_ligne.append(min_lign(c,i))
    if ch ==2:
        for j in range(0,max(n,m)):
            vector_min_coloumn.append(min_col(c,j))


def baree(mat,f_index,s_index):
    for i in range(0,max(n,m)):
        if i != f_index and mat[i][s_index] ==3 : 
            mat[i][s_index]=2
    for j in range(0,max(n,m)):
        if j != s_index and mat[f_index][j]==3 :    
            mat[f_index][j]=2  


def carre(c,n,m):
    if m<n :
        for i in range(0,n):
            for j in range(m,n):
                c[i].append(0)
    if m>n :
        for i in range(n,m):
            c.append([])
            for j in range(0,m):
                c[i].append(0)
    return c

def calculate(D): 
    global T,Ct , affictaion , temps_left
    for i in range(0,n):
        for j in range(0,m):
            if D[i][j]==1:
                Ct =  Ct + c[i][j]
                affictaion.append([i+1,T[j]])
    for fv in affictaion:
        if fv[1] in T :
            T.remove(fv[1])

def algo_affic(mm,nn):
    global croisment_complete , n , m , temps_left
    z.clear()
    r.clear()
    copy_c = cpying()
    copy_c = carre(copy_c,n,m)
    zero_bare = []
    min_matrix(copy_c,z,r,1)
    for i in range(0,nn):
        for j in range(0,mm):
            copy_c[i][j] = copy_c[i][j]- z[i]
    min_matrix(copy_c,z,r,2)
    for j in range(0,mm):
        for i in range(0,nn):
            copy_c[i][j] =copy_c[i][j] - r[j]  
    zero_bare = zero(zero_bare,copy_c) #   1 for zero encadre , 2 for zero barre , 3 for zero , 0 for else  ;

    while suming(zero_bare, 1, nn, mm, 0, 0) != mm : 
        
        croise.clear()
        xcroise.clear()
        croisment_complete = False
        
        while suming(zero_bare, 3, nn, mm, 0, 0) != 0: 
            count_zero = [0 for i_ in range(nn)]
            
            for h in range(nn):
                for k in range(mm):
                    if copy_c[h][k] == 0 and zero_bare[h][k] == 3:
                        count_zero[h] = count_zero[h] + 1    
                
                if count_zero[h] == 0:
                    count_zero[h] = huge
            inx = count_zero.index(min(count_zero))
            if inx < n and inx < nn:
                feasible_found = False
                
                while not feasible_found:
                    
                    for j in range(mm):
                        if j >= m or inx >= n:
                            feasible_found = True
                            break
                        if copy_c[inx][j] == 0 and zero_bare[inx][j] == 3:
                            if temps_left[inx] >= p[inx][j]:
                                feasible_found = True
                                break
                    if not feasible_found:
                        count_zero[inx] = huge
                        if count_zero[0:n] == [huge]*n:
                            return "no sol realisable"
                        inx = count_zero.index(min(count_zero))

            for j in range(mm):
                if copy_c[inx][j] == 0 and zero_bare[inx][j] == 3:
                    if inx < n and j < m:
                        if temps_left[inx] >= p[inx][j]:
                            temps_left[inx] = temps_left[inx] - p[inx][j]
                            zero_bare[inx][j] = 1
                            dex = j
                            break

                    elif inx >= n or j >= m:
                        zero_bare[inx][j] = 1
                        dex = j
                        break

            baree(zero_bare, inx, dex)
        if mm == sum(b.count(1) for b in zero_bare):
            break
        else:
            temps_left = temps[:]
            for i in range(0,nn):
                if suming(zero_bare,1,i+1,mm,i,0) == 0:
                    croise.append(i)
            while  not croisment_complete:       
                croisment_complete = True     
                for i in croise:
                    for j in range(0,mm):
                            if zero_bare[i][j] == 2 and j not in xcroise:
                                xcroise.append(j)
                                croisment_complete = False 
                for j in xcroise:
                    for i in range(0,nn):
                            if zero_bare[i][j]==1 and i not in croise: 
                                croise.append(i)
                                croisment_complete = False             
            minimum = huge
            for i in croise :
                for j in range(0,mm):
                    if j not in xcroise:
                        if minimum > copy_c[i][j]:
                            minimum = copy_c[i][j]
            for i in croise :
                for j in range(0,mm):
                    if j not in xcroise:
                            copy_c[i][j] = copy_c[i][j] - minimum    
            for i in range(0,nn):
                for j in xcroise: 
                    if i not in croise :
                        copy_c[i][j] = copy_c[i][j] + minimum
            zero_bare = zero(zero_bare,copy_c) 
    
    if n >= m :
        calculate(zero_bare)
        if T ==[]:
            print("RETURN 2: n >= m case all tasks assigned, T is empty")
            return zero_bare
        else :

            return algo_affic(n,n)
    else:
        calculate(zero_bare)
        m = m-n
        g = max(n,m)
        return algo_affic(g,g)





def main(tile,pp,cc,client,machines):
    global p,c,m,n,tm,temps_left,T
    p.clear()
    p=pp
    c.clear()
    c=cc
    m=client
    n=machines
    tm.clear()
    tm= tile
    temps_left.clear()
    temps_left = tile
    T = [j+1 for j in range(0,m)]
    if m == n :
        hz =  algo_affic(m,n)
    else:
        nm = max(n,m)
        hz =  algo_affic(nm,nm)
    print(affictaion)
    return affictaion        
    


