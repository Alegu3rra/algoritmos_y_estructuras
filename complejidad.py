#Clase 1, Complejidad
#
#Suma todos los númeos de 1..N

total = 0
n = 10

for i in range(1, n+1): #for de [1,n]
    for j in range(1, n+1):
        total += i
print(total)#O(N^2 o N*M)


#------------------------------------------- 
for i in range(1, n+1):
    total += i
print(total)#O(N)

#-------------------------------------------
#sumar de 1 a N
n = 10
print((n*(n+1))/(2)) #O(1)

#-------------------------------------------
for i in range(n):
    print("loop")

for y in range(m):
    print("loop")

#complejidad -> O(N+M) -> O(N)

querys = [1, 123,42341, 123, 4] #sumar de 1 a N, tamaño de arreglo es k

for q in querys:
    total = 0
    for i in range(1, int(q)+1): #O(N*K)
        total +=1
    print(total)
    


#operaciones por segundo de un procesador (promedio, genealizando) ~10^8 operaciones/seg
#10^9 operaciones -> 10 segundos en terminar
#O(1)-> constante
#f(x) = 1 -> una recta
#f(n) = n -> recta con pendiente

