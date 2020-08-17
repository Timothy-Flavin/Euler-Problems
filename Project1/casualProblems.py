import math
import time
import sympy

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

def eulerProblem12():
    triangleNumber = 1
    numberToBeAdded = 2
    numFactors=0
    while numFactors <=500:
        triangleNumber+=numberToBeAdded
        numberToBeAdded+=1
        numFactors=0
        bigFactor=triangleNumber
        smallFactor=1
        if(triangleNumber%2==0):
            while bigFactor>=smallFactor:
                #print("num tried "+str(i) +"triangle: "+str(triangleNumber))
                if (triangleNumber%smallFactor) == 0:
                    bigFactor=triangleNumber/smallFactor
                    numFactors+=2
                    #print(i)
                smallFactor+=1
        #because we need to count itself
    print("triangle number "+str(triangleNumber)+", numFactors: "+str(numFactors))

#this is trivial in python. Should revisit in C++ so I have to write the addition algo
def eulerProblem13():
    inString = open("problem13.txt", "r").read().split("\n")
    answer=0
    for i in range(len(inString)):
        answer+=int(inString[i])
    print(answer)

def eulerProblem14():
    numLengthDictionary = {}
    longestOne=0
    startingDigit=0
    for i in range(2,1000000):
        j=i
        found = False
        numTerms=0
        while j!=1 and not found:
            #print("current num: "+str(j))
            if j in numLengthDictionary:
                #print(numLengthDictionary[j])
                numTerms+=numLengthDictionary[j]
                found=True
            elif j%2==0:
                j=int(j/2)
                numTerms+=1
            else:
                j=3*j+1
                numTerms+=1
        if(j==1):
            numTerms+=1
        numLengthDictionary[i]=numTerms
        if(numTerms>longestOne):
            longestOne=numTerms
            startingDigit=i
    print(longestOne)
    print(startingDigit)

def eulerProblem15():
    # this is a discrete math problem like spelling a word with 40 letters but two sets of 20 repeats
    # so it is as easy as 40!/(20!*20!) or more general (n+m)!/(n!*m!) for any n by m lattice
    num=1
    # filling the factorials as lists to avoid excessively large numbers during computation although this
    # one is easy enough to type the above equation into google
    for i in range(40):
        num*=40-i
        num/=int((40-i)/2+0.51)
    print(math.ceil(num))

def eulerProblem16():
    num=1
    for i in range(1000):
        num*=2
    num=str(num)
    print(num)
    answer=0
    for i in num:
        print(i)
        answer+=int(i)
    
    print("answer: "+str(answer))

def eulerProblem18():
    inString = open("problem18.txt", "r").read().split("\n")
    for i in range(len(inString)):
        inString[i]=inString[i].split(' ')
    #print(inString)
    maxList = list()
    for i in range(len(inString[-1])):
        maxList.append(int(inString[-1][i]))
    #print(maxList)
    for row in range(len(inString)-2,-1,-1):
        for col in range(len(inString[row])):
            print("row "+str(row)+", col "+ str(col))
            maxList[col]=int(inString[row][col]) + max(maxList[col],maxList[col+1])
        maxList.pop()
        #print(maxList)
    print(maxList[0])

def eulerProblem67():
    inString = open("problem67.txt", "r").read().split("\n")
    for i in range(len(inString)):
        inString[i]=inString[i].split(' ')
    #print(inString)
    maxList = list()
    for i in range(len(inString[-1])):
        maxList.append(int(inString[-1][i]))
    #print(maxList)
    for row in range(len(inString)-2,-1,-1):
        for col in range(len(inString[row])):
            #print("row "+str(row)+", col "+ str(col))
            maxList[col]=int(inString[row][col]) + max(maxList[col],maxList[col+1])
        maxList.pop()
        #print(maxList)
    print(maxList[0])

#745
def eulerProblem19():
    months=[31,28,31,30,31,30,31,31,30,31,30,31]
    year=1901
    month=0
    dayOfMonth=0
    dayOfWeek=2
    endYear=2001

    totalDays=0
    sundays=0
    while year<endYear:
        while month<len(months):
            while dayOfMonth<months[month]:
                if dayOfMonth==0 and dayOfWeek==0:
                    sundays+=1
                    #print("sunday on first day")
                #print("year: "+str(year)+", month: "+str(month+1)+", day: "+str(dayOfMonth+1)+", wkday: "+str(dayOfWeek+1))
                totalDays+=1
                dayOfWeek=(dayOfWeek+1)%7
                dayOfMonth+=1
            dayOfMonth=0
            month+=1
        month=0
        year+=1
        if(year%4==0):
            months[1]=29
        else:
            months[1]=28
    print('sundays '+str(sundays))
    print('total days '+str(totalDays))

def eulerProblem20():
    bigNumber = str(math.factorial(100))
    answer = 0
    for i in bigNumber:
        answer+=int(i)
    print(answer)

def eulerProblem21():
    factorTotals = list(range(10000))
    for i in range(10000):
        factorTotals[i]=0
    amicableNumSum=0

    def d(n):
        dn=-n
        bigFactor=n
        smallFactor=1
        while bigFactor>smallFactor:
                #print("num tried "+str(i) +"triangle: "+str(triangleNumber))
                if (n%smallFactor) == 0:
                    bigFactor=int(n/smallFactor)
                    if(bigFactor!=smallFactor):
                        dn+=bigFactor+smallFactor
                    else:
                        dn+=bigFactor
                    #print(bigFactor)
                    #print(smallFactor)
                smallFactor+=1
        return int(dn)

    #print(d(284))
    #input()

    for i in range(2,10000):
        if factorTotals[i]==0:
            factorTotals[i]=d(i)
            if factorTotals[i]<10000 and factorTotals[factorTotals[i]]==0:
                factorTotals[factorTotals[i]]=d(factorTotals[i])
            if factorTotals[i]<10000 and factorTotals[factorTotals[i]] == i and factorTotals[i]!=i:
                amicableNumSum+=factorTotals[factorTotals[i]] + factorTotals[i]
                print('factor 1: ' + str(factorTotals[i]) + ' factor 2: ' +str(factorTotals[factorTotals[i]]) )


    print(amicableNumSum)
    
def eulerProblem22():
    alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    alphaVals = {}
    for i in range(len(alphabet)):
        alphaVals[alphabet[i]]=i+1
    inString = open("problem22.txt", "r").read().split('","')
    inString[0]=inString[0][1:]
    inString[-1]=inString[-1][:-1]
    
    def compareStrings(st1, st2):
        length = min(len(st1), len(st2))
        for i in range(length):
            if alphaVals[st1[i]] < alphaVals[st2[i]]:
                return 1
            elif alphaVals[st2[i]] < alphaVals[st1[i]]:
                return -1

        if len(st1)!=len(st2):
            if len(st1)<len(st2):
                return 1
            else:
                return -1
        else:
            return 0

    def bubbleSort(arr): 
        n = len(arr) 
        for i in range(n-1): 
            for j in range(0, n-i-1): 
                if compareStrings(arr[j],arr[j+1])==-1: 
                    arr[j], arr[j+1] = arr[j+1], arr[j] 
    bubbleSort(inString)
    print(inString)

    answer=0
    for i in range(len(inString)):
        stringTotal=0
        for j in range(len(inString[i])):
            stringTotal+=alphaVals[inString[i][j]]
        #if(i==937):
            #print(inString[i]+"string tot: "+str(stringTotal)+" numToBeAdded: " +str(stringTotal*(i+1)))
        answer+=stringTotal*(i+1)
    print(answer)

def eulerProblem23():
    def d(n):
        dn=-n
        bigFactor=n
        smallFactor=1
        while bigFactor>smallFactor:
                #print("num tried "+str(i) +"triangle: "+str(triangleNumber))
                if (n%smallFactor) == 0:
                    bigFactor=int(n/smallFactor)
                    if(bigFactor!=smallFactor):
                        dn+=bigFactor+smallFactor
                    else:
                        dn+=bigFactor
                    #print(bigFactor)
                    #print(smallFactor)
                smallFactor+=1
        return int(dn)>n

    listOfAbundantNums=list()
    listOfNums=[0]*28124
    #print(listOfNums)
    for i in range(10,28124):
        if d(i):
            listOfAbundantNums.append(i)
    #print(listOfAbundantNums)
    i=0
    j=0
    while i<len(listOfAbundantNums):
        j=i
        while j<len(listOfAbundantNums):
            t=listOfAbundantNums[i]+listOfAbundantNums[j]
            if t<28124:
                listOfNums[t]=1
            else:
                j=len(listOfAbundantNums)
            j+=1
        i+=1
    answer=0
    for n in range(len(listOfNums)):
        if(listOfNums[n]==0):
            #print(n)
            answer+=n
        #if n%100==0:
            #input()
    print("done "+str(answer))

def eulerProblem24():
    digits={"0":0, "1":0, "2":0, "3":0, "4":0, "5":0, "6":0, "7":0, "8":0, "9":0}
    target=1000000-1
    i=0
    while(target!=0):
        print(target)
        digitNum=0
        permuteNum=1
        while permuteNum*(digitNum+1)<=target:
            digitNum+=1
            permuteNum*=digitNum
        while permuteNum<=target:
            target-=permuteNum
            digits[str(digitNum)]+=1
            #print("i: "+str(i)+", digitNum: "+str(digitNum))
            #print(digits)
        i+=1
        #digits[str(digitNum)]+=1
    tempstr="0123456789"
    answer=""
    for i in range(9,-1,-1):
        answer+=tempstr[digits[str(i)]]
        tempstr=tempstr.replace(answer[-1],"")
        #print(answer+"-"+tempstr)
    print("answer: "+answer)

def eulerProblem25():
    f1=1
    f2=1
    i=2
    while len(str(f2))<1000:
        f1,f2=f2,f1+f2
        i+=1
    print("index: "+str(i)+", f1: "+str(f1)+", f2: "+str(f2))

def eulerProblem27():
    answer=0
    aFinal=0
    bFinal=0

    for a in range(-999,999):
        for b in range(-999,999):
            prime = True
            n=0
            while prime:
                prime=sympy.isprime(n*n+a*n+b)
                n+=1
            if n>answer:
                answer=n
                aFinal=a
                bFinal=b
        if a%20==0:
            print(str((a+1000)/20.)+str("% done"))
    print("aFinal: "+str(aFinal)+", bFinal: "+str(bFinal)+", answer: "+str(aFinal*bFinal)+", num primes: "+str(answer))    

def eulerProblem28():
    curNum=1
    total=1
    for n_by_n in range(1,1001,2):
        for i in range(4):
            curNum+=n_by_n+1
            total+=curNum
    print(total)

def eulerProblem29():
    answerList = list()
    for a in range(2,101):
        for b in range(2, 101):
            if(int(pow(a,b)) not in answerList):
                answerList.append(int(pow(a,b)))
        print(str(a/100)+"% done")
    print(len(answerList))

def eulerProblem32():
    # at a=135 the smalles b can be is 246 and the product is too many digits
    # so if a is the smaller number a has to be less than 136
    pandigitalNums=list()
    for a in range(1, 136):
        b=a+1
        while True:
            temp=str(a)+str(b) + str(a*b)
            if(len(temp)>9):
                break
            if(len(temp)==9):
                pandigital=True
                for i in range(1,10):
                    if not str(i) in temp:
                        pandigital=False
                if pandigital:
                    if(a*b not in pandigitalNums):
                        #print("a: "+str(a)+", b: "+str(b)+", a*b: "+str(a*b))
                        pandigitalNums.append(a*b)
            b+=1
    print(sum(pandigitalNums))

def eulerProblem33():
    fnum=1
    fden=1
    for numerator in range(11,100):
        for denominator in range(numerator, 100):
            if numerator%10!=0 and numerator%10 == int(denominator/10) and int(numerator/10)!=numerator%10:
                if int(numerator/10)*denominator==numerator*(denominator%10):
                    #print("num: " +str(numerator)+", den: "+str(denominator))
                    fnum*=numerator
                    fden*=denominator
    i=2
    #print("fnum: " +str(fnum)+", fden: "+str(fden))
    while i<=fnum and i<=fden:
        while fnum%i==0 and fden%i==0:
            fnum=int(fnum/i)
            fden=int(fden/i)
        i+=1
    #print("fnum: " +str(fnum)+", fden: "+str(fden))
    print("answer: "+str(fden))

def eulerProblem34():
    start = 3
    tot=0
    while(start<2540160):
        temp=0
        cur=start
        while cur>0:
            temp+=math.factorial(cur%10)
            cur=int(cur/10)
        if(temp==start):
            tot+=temp
            print(tot)
        start+=1
    print("done")
    
def eulerProblem35():
    numCirclePrimes=0
    for i in range(1000000):
        if sympy.isprime(i):
            circlePrime=True
            circle = str(i)
            #print(circle)
            for j in range(len(circle)-1):
                circle=circle[-1]+circle[0:-1]
                if not (sympy.isprime(int(circle))):
                    circlePrime=False
            if circlePrime:
                #print(i)
                numCirclePrimes+=1
                #input()
    print(numCirclePrimes)

def eulerProblem36():
    tot=0
    for i in range(1,1000000):
        decimal=str(i)
        

        doublePalindrone = True        
        for j in range(int((len(decimal)+1)/2)):
            if(decimal[j]!=decimal[-(j+1)]):
                doublePalindrone=False
        if(doublePalindrone):
            binary=""
            temp=i
            while temp>0:
                binary=str(temp%2)+binary
                temp=int(temp/2)
            for j in range(int((len(binary)+1)/2)):
                if(binary[j]!=binary[-(j+1)]):
                    doublePalindrone=False
            if(doublePalindrone):
                tot+=i
        #print(doublePalindrone)
        #print(decimal)
        #print(binary)
        #input()
    print(tot)

def eulerProblem37():
    answer=0
    numPrimes = 11
    i=11
    stringI =str(i)
    while numPrimes > 0:
        prime=True
        #input()
        #print("current num: "+str(i))
        if(sympy.isprime(i)):
            stringI = str(i)
            if stringI[0]=="1" or stringI[-1]=="1":
                #print("one on the end")
                prime=False
            else:
                for j in range(1, len(stringI)):
                    #print("-----------next--------")
                    #print("[:j] "+stringI[:j])
                    #print("[j:] "+stringI[j:])
                    if not sympy.isprime(int(stringI[:j])) or not sympy.isprime(int(stringI[j:])):
                        prime=False
                        #print("--------not-prime---------")
        else:
            #print("not prime")
            prime=False
        if(prime):
            numPrimes-=1
            answer+=i
            #print("double prime: "+str(i))     
        i+=2
    print("sum of double primes: "+str(answer))

def eulerProblem38():
    maxPerim = 1000
    triangles = {}
    for i in range(maxPerim+1):
        triangles[i]=0
    biggestLeg=math.ceil(maxPerim/2)
    for a in range(1,biggestLeg):
        for b in range(a,biggestLeg):
            c = math.sqrt(a*a+b*b)
            if(a+b+c<=maxPerim and math.floor(c)==c):
                c=int(c)
                #print("a: "+str(a)+", b: "+str(b)+", c: "+str(c))
                triangles[a+b+c]+=1
    mostTriangles=0
    answer=0
    for i in triangles:
        if triangles[i]>mostTriangles:
            mostTriangles=triangles[i]
            answer=i
    print(answer)

def eulerProblem40():
    answer=""
    i=1
    while len(answer)<=1000000:
        answer+=str(i)
        i+=1
    print(str(int(answer[0])*int(answer[9])*int(answer[99])*int(answer[999])*int(answer[9999])*int(answer[99999])*int(answer[999999])))

def eulerProblem41():
    def checkForPandigitalPrimes(numDigits):
        panNum = ""
        foundPrime = False
        for i in range(numDigits):
            panNum=str(i+1)+panNum
        #print(panNum)
        curNumStr = list(str(panNum))
        for i in range(len(curNumStr)):
            curNumStr[i] = int(curNumStr[i])
        #print(curNumStr)
        curDigit = len(curNumStr)-2

        while curNumStr[0]>1:
            #input()
            curDigit=0
            for i in range(len(curNumStr)-1):
                if curNumStr[i]>curNumStr[i+1]:
                    curDigit=i

            minDigits=list()
            largestMinIndex=-1
            for i in range(curDigit+1,len(curNumStr)):
                if curNumStr[i] < curNumStr[curDigit]:
                    minDigits.append(curNumStr[i])
            #print(minDigits)
            #print(max(minDigits))
            
            #print(curDigit)
            #print(curNumStr.index(int(max(minDigits))))
            if len(minDigits)>0:
                minDigits.sort(reverse=True)
                biggestSmall = curNumStr.index(minDigits[0])
                #print(curNumStr)
                #print("curNumStr[curDigit]: "+str(curNumStr[curDigit])+", curNumStr[curNumStr.index(int(max(minDigits)))]: "+ str(curNumStr[biggestSmall]))
                curNumStr[curDigit], curNumStr[biggestSmall] = curNumStr[biggestSmall], curNumStr[curDigit]
                #print("curNumStr[curDigit]: "+str(curNumStr[curDigit])+", curNumStr[curNumStr.index(max(minDigits))]: "+ str(curNumStr[biggestSmall]))
                endOfString=curNumStr[curDigit+1:]
                endOfString.sort(reverse=True)
                curNumStr = curNumStr[0:curDigit+1] + endOfString
            tot=0
            for i in range(len(curNumStr)):
                tot*=10
                tot+=curNumStr[i]
            #print(tot)
            #input()
            if sympy.isprime(tot):
                print('tot: '+str(tot))
                return True
    for i in range(9, 0, -1):
        print(i)
        if(checkForPandigitalPrimes(i)):
            break
    print("done")

def eulerProblem42():
    inString = open("problem42.txt", "r").read().split('","')
    inString[0]=inString[0][1:]
    inString[-1]=inString[-1][:-1]
    #print(inString)

    triangleNumbers = list()
    triangleNumbers.append(1)
    numTriangleWords = 0
    for i in inString:
        #print(i)
        wordTot=0
        for j in i:
            wordTot+=ord(j)-64
            #print(ord(j)-64, end="")
        #print("word tot: "+str(wordTot))
        while wordTot>triangleNumbers[-1]:
            triangleNumbers.append(int(int(len(triangleNumbers)*(len(triangleNumbers)+1))*1/2))
            #print("Length of triangle numbers list: "+str(len(triangleNumbers)))
            #print("Last item in the list: "+str(triangleNumbers[-1]))
        if wordTot in triangleNumbers:
            #print(i+" is a triangle number")
            numTriangleWords+=1
        #print()
        #input()
    print(numTriangleWords)

if __name__ == "__main__":
    start = time.perf_counter()
    eulerProblem42()
    end = time.perf_counter()-start
    print("time elapsed "+ str(end) + "seconds")