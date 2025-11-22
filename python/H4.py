


def maxi(matrix):
    max_value = matrix[0][0]
    for row in matrix:
        for value in row:
            if value > max_value:
                max_value = value
    return max_value
def sad(i,R, time_max,T,p,m,n):
    selection = []
    S=[]
    maximum = 0
    while time_max[i] >0 and maximum >-100 :
        maximum = R[0]
        l=0
        for j in range(m):
            if R[j] >= maximum and T[j] == -1 :
                if R[j] == maximum and p[i][l] > p[i][j] :
                    maximum = R[j]
                    l = j
                elif R[j] == maximum and p[i][l] > p[i][j] :
                    continue
                else :
                    maximum = R[j]
                    l = j
        R[l]=-10000    
        if time_max[i] - p[i][l] >= 0 and l not in S:
            time_max[i] = time_max[i] - p[i][l]
            T[l]=i
            S.append(l)
        else:
            continue
    return S
 

def gap(cout, time_max,p,m,n):

    R=[[] for i in range(n)]
    for i in range(n):
        for j in range(m):
            R[i].append(maxi(cout)-cout[i][j])

    T = [-1] * m
    S=[]
    for i in range(n):
        for j in range(m):
            if T[j] == -1:
                0
            else:
                k = T[j]
                R[i][j] =  -cout[i][j] +cout[k][j]
        x=sad(i,R[i], time_max,T,p,m,n)
        if j > 0:
            for e in x:
                for i in range(len(S)):
                    for j in range(len(S[i])):
                        if e in S[i]:
                            S[i][j]=-1

        S.append(x)


    total_cost = 0
    for j in range(n):
        if T[j] != -1:
            total_cost += cout[T[j]][j]
    
    return S,T, total_cost




def main(tm,p,c,m,n):
    aff,T, cout = gap(c, tm,p,m,n)
    print(aff)
    afec =[ [x+1,i+1] for  i in range(len(aff)) for x in aff[i] if x !=-1 ]
    
    cost_t = []
    for j, machine in enumerate(T):
        if machine != -1:
            cost_t.append(c[machine][j])
    return afec

