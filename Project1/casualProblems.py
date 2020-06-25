import math
import time


def eulerProblem10():
    primes = list()
    for i in range(2,2000000):
        prime = True
        #print("checking prime ness for "+str(i))
        for j in primes:
            #print("i "+str(i)+" j "+str(j))
            if(j>math.sqrt(i)):
                break
            elif (i%j) == 0:
                prime=False
                break
        if prime:
            primes.append(i)   
    tot = 0 
    for i in primes:
        tot=tot+i
    #print("got primeness for "+str(i))
    #print(primes)
    print(tot)

start = time.perf_counter()
eulerProblem10()
end = time.perf_counter()-start
print("time elapsed "+ str(end) + "seconds")