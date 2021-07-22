from math import factorial as ft

def n_k(n,k):
    
    return ft(n) // ( ft(k) * ft(n-k) )

for i in range(61):
    suma = 0
    for j in range(0, i+1):
        suma += n_k(i,j)
        print('',n_k(i,j), end='')
    print('',suma)
