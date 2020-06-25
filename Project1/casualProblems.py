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

def eulerProblem11():
    problemString = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"
    problemString = problemString.split(" ")
    for i in range(len(problemString)):
        problemString[i]=int(problemString[i])
    #print(problemString)
    HEIGHT=20
    WIDTH=20
    productLength=4
    #find largest diagonal
    maxDiag=1
    tempDiag=1
    # i know i use far more multiplications than needed by repeating them
    # but I did not feel like doing fot the diagonals what I did for vert 
    # and hori
    for y in range(HEIGHT-productLength+1):
        for x in range(WIDTH):
            temp1=1
            temp2=1
            if x <= WIDTH-productLength:
                #down to the right
                for i in range(productLength):
                    temp1=temp1*problemString[(y+i)*WIDTH+x+i]
            if x >= productLength-1:
                for i in range(productLength):
                    temp2=temp2*problemString[(y+i)*WIDTH+x-i]
                #down to the left
            #print("temp1: "+str(temp1)+", temp2: "+str(temp2))
            tempDiag=max(temp1,temp2)
            maxDiag=max(tempDiag,maxDiag)
    print("maxDiag: "+str(maxDiag))
    #find largest horizontal
    maxHori=1
    tempHori=1
    for y in range(HEIGHT):
        tempHori=1
        for i in range(productLength):
            tempHori=tempHori*problemString[y*WIDTH+i]
            #print(problemString[y*WIDTH+i])
        #print(tempHori)
        for x in range(productLength, WIDTH):
            #test=1
            #or i in range(productLength):
            #    test=test*problemString[y*WIDTH+x-i]
            #print("test "+str(test))
            if(problemString[y*WIDTH+x-productLength]==0):
                tempHori=1
                for i in range(productLength):
                    tempHori=tempHori*problemString[y*WIDTH+x-i]
                #print(tempHori)
            else:
                tempHori=tempHori*problemString[y*WIDTH+x]
                tempHori=tempHori/problemString[y*WIDTH+x-productLength]
                #print(tempHori)
            if(tempHori>maxHori):
                maxHori=tempHori
                #print(maxHori)
            
    print(maxHori)
    #find largest vertical
    maxVert =1
    tempVert=1
    for x in range(WIDTH):
        tempVert=1
        for i in range(productLength):
            tempVert=tempVert*problemString[x+i*WIDTH]
            #print(problemString[y*WIDTH+i])
        #print(tempHori)
        for y in range(productLength, HEIGHT):
            #test=1
            #or i in range(productLength):
            #    test=test*problemString[y*WIDTH+x-i]
            #print("test "+str(test))
            if(problemString[x+WIDTH*y-WIDTH*productLength]==0):
                tempVert=1
                for i in range(productLength):
                    tempVert=tempVert*problemString[x+WIDTH*y-WIDTH*i]
                #print(tempHori)
            else:
                tempVert=tempVert*problemString[x+WIDTH*y]
                tempVert=tempVert/problemString[x+WIDTH*y-WIDTH*productLength]
                #print(tempHori)
            if(tempVert>maxVert):
                maxVert=tempVert
                #print(maxHori)
            
    print(maxVert)

start = time.perf_counter()
eulerProblem11()
end = time.perf_counter()-start
print("time elapsed "+ str(end) + "seconds")