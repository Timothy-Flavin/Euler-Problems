#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <chrono>
#include <algorithm>
#include<array>
template<class T>
double timeFunction(T(*func) (void)) {

	auto t1 = std::chrono::high_resolution_clock::now();
	T answer = func();
	auto t2 = std::chrono::high_resolution_clock::now();
	//std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000.0 << " milli seconds" << std::endl;
	std::cout << "Answer to problem: " << answer << std::endl;
	return (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000.0);
}
int eulerProblem3();
int eulerProblem3b();
void eulerProblem7();
void eulerProblem8();
void eulerProblem9();
void eulerProblem30();
void eulerProblem26();
void eulerProblem17();
void eulerProblem69();
void eulerProblem_69();
void testPrimesVsPrimes2();
void eulerProblem31();
void eulerProblem38();
long long int eulerProblem43();
long long int eulerProblem43b();
long long int eulerProblem43c();
int eulerProblem44();
int eulerProblem44Helper();
int eulerProblem44b();


int calcTotient(int n, std::vector<int> primes);
std::vector<int> getPrimes(int n);
std::vector<int> getPrimes2(int n);





int main() {
	int numTests = 1;
	int (*func)(void) = &eulerProblem44Helper;
	int (*func2)(void) = &eulerProblem44b;
	double totalTime1 = 0;
	double totalTime2 = 0;
	for (int i = 0; i < numTests; i++) {
		totalTime1+=timeFunction(func);
		//totalTime2+=timeFunction(func2);
	}

	std::cout << "Avg time 1: " << totalTime1/numTests << std::endl;
	std::cout << "Avg time 2: " << totalTime2/numTests << std::endl;

	std::cin.get();
	return 0;
}




int eulerProblem3() {
	long long int bigBoi = 600851475143;
	long long int i = 3;
	while (i <= bigBoi) {
		while (bigBoi%i == 0) {
			bigBoi /= i;
		}
		i += 2;
	}
	std::cout << i-2 << std::endl;
	return i-2;
}

int eulerProblem3b() {
	long long int bigBoi = 600851475143;
	int i = 3;
	int largest = 0;
	while (i <= bigBoi) {
		while (bigBoi%i == 0) {
			bigBoi /= i;
			largest = i;
		}
		i += 2;
	}
	//std::cout << largest << std::endl;
	return largest;
}

void eulerProblem26(){
	int sequence[100000];
	int sequenceLength = 0;
	bool notInSequence = true;
	int topSequenceLength = 0;
	for (int i = 1; i < 1000; i++) {
		std::cout << "onNumber: " << i << std::endl;
		sequenceLength = 0;
		notInSequence = true;
		int divisor = 1;
		int remainder = 0;
		int topNumber = divisor / i;
		while (notInSequence) {
			topNumber = divisor / i;
			remainder = divisor - i * topNumber;
			if (remainder == 0) break;
			else {
				sequence[sequenceLength] = remainder;
				divisor = remainder * 10;
				for (int j = 0; j < sequenceLength; j++) {
					if (remainder == sequence[j]) {
						notInSequence = false;
						
						if (sequenceLength - j > topSequenceLength) {
							std::cout << "highestNumber: " << i << "at: " << sequenceLength - j << std::endl;
							topSequenceLength = sequenceLength - j;
						}
					}
				}
				sequenceLength++;
			}
		}
	}
	std::cout << topSequenceLength;
}

void eulerProblem7() {
	int counter = 1;
	int currentNum = 3;
	bool notPrime = true;
	const int primeToFind = 100001;
	int primeList[primeToFind];
	primeList[0] = 2;
	while (counter<primeToFind) {
		notPrime = false;
		for (int i = 0; i < counter && primeList[i] <= std::sqrt(currentNum); i++) {
			if (currentNum % primeList[i] == 0) {
				notPrime = true;
				i = currentNum;
			}
		}
		if (!notPrime) {
			primeList[counter] = currentNum;
			counter++;
		}
		currentNum++;
	}
	std::cout << currentNum - 1 << std::endl;
}

void eulerProblem30() {
	int answer = 0;
	int power = 5;
	for (int i = 2; i < std::pow(9, power)*(power+1); i++) {
		int digitCounter = 0;
		int temp = i;
		for (int j = 0; j < power+1; j++) {
			digitCounter += std::pow(temp % 10,power);
			temp /= 10;
		}
		if (digitCounter == i) {
			answer += digitCounter;
		}
	}
	std::cout << "answer: " << answer << std::endl;
}

void eulerProblem17() {
	std::string onesWords[10] = {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string teensWords[10] = {"ten","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	std::string tensWords[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	std::string hundredWord = "hundred";
	std::string andWord = "and";
	std::string oneThousand = "oneThousand";

	int numberLength = 0;
	int totalLength = 0;
	for(int temp = 1; temp < 1000; temp++){
		int ones = temp%10;
		int tens = (temp/10)%10;
		int hundreds = (temp/100)%10;
		
		
		
		numberLength=int(onesWords[hundreds].length() + (hundreds?(hundredWord.length()+((ones||tens)?andWord.length():0)):0));
		std::cout<<temp<<": "<<"Hundreds place "<<hundreds<<", "<<onesWords[hundreds]<<", length: "<<numberLength<<std::endl; //", "<<((ones||tens)?andWord.length():0)
		
		//std::cout<<onesWords[hundreds] << hundreds?(hundredWord+ones?andWord:""):""<<" ";
		switch(tens){
			case 0:
				numberLength+=onesWords[ones].length();
				std::cout<<onesWords[ones];
			break;
			case 1:
				numberLength+=teensWords[ones].length();
				std::cout<<teensWords[ones];
			break;
			default:
				numberLength+=tensWords[tens-2].length()+onesWords[ones].length();
				std::cout<<tensWords[tens-2] << onesWords[ones] <<std::endl;
			break;
		}

		std::cout<<numberLength<<std::endl;
		totalLength+=numberLength;
		//std::cout <<"ones place lengths "<<i<<": "<< onesPlace[0].length()<<std::endl;
		//std::cout <<"teens place lengths "<<i<<": "<< teens[0].length()<<std::endl;
	}

	std::cout<<totalLength + oneThousand.length()<<std::endl;
}

int gcd(int a, int b)  
{  
    if (a == 0)  
        return b;  
    return gcd(b % a, a);  
}  
  
// A simple method to evaluate Euler Totient Function  
int phi(unsigned int n)  
{  
    unsigned int result = 1;  
    for (int i = 2; i < n; i++)  
        if (gcd(i, n) == 1)  
            result++;  
    return result;  
}
void eulerProblem69(){
	double answer = 0;
	double temp=0;
	int solution = 0;
	auto t1 = std::chrono::high_resolution_clock::now();
	auto t3 = std::chrono::high_resolution_clock::now();
	for(int i = 2; i <1000000; i++){
		temp = double(i)/calcTotient(i,getPrimes2(i));
		if(temp>answer){
			answer=temp;
			solution = i;
		}
		if(i%10000==0){
			std::cout<<"answer: "<<answer<<", solution: "<<solution<<std::endl;
			auto t2 = std::chrono::high_resolution_clock::now();
			std::cout<<"took: "<<std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<<"ms"<<std::endl;
			t1=t2;
			std::cout<<double(i)/10000<<"% done"<<std::endl;
		}
	}
	auto t4 = std::chrono::high_resolution_clock::now();
	std::cout<<"answer: "<<answer<<", solution: "<<solution<<std::endl;
	std::cout<<"took: "<<std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()<<"ms"<<std::endl;
}

int calcTotient(int n, std::vector<int> primes){
	int compositeNums=0; 
	int tot = 0;
	int baseNum = 1;
	/*std::cout<<"n: "<<n<<", primes list: "<<std::endl;
	for(int i = 0; i < primes.size();i++){
		std::cout<<primes[i]<<", ";
	}
	std::cout<<std::endl;*/
	/*for(int i = 0; i < primes.size(); i++){
		tot+=n/primes[i];
		baseNum*=primes[i];
		for(int j = i+1; j < primes.size();j++){
			compositeNums++;
			tot-=(n/(primes[i]*primes[j]));
		}
	}*/
	//For each group size of primes find all combinations from size 1 to primes.size()-1
	int underCounting = -1;
	for(int g = 1; g <= primes.size(); g++){
		underCounting*=-1;
		int numToDevideBy = 1;
		std::string bitmask(g, 1); // K leading 1's
		bitmask.resize(primes.size(), 0); // N-K trailing 0's
	
		// print integers and permute bitmask
		do {
			numToDevideBy = 1;
			for (int i = 0; i < primes.size(); ++i) // [0..N-1] integers
			{
				if (bitmask[i]){
					//std::cout << " " << i<<","<<primes[i]<<" ";
					numToDevideBy*=primes[i];
				}
			}
			//std::cout <<std::endl<<" "<<underCounting*(n/numToDevideBy)<<" "<<numToDevideBy<< std::endl;
			tot+=underCounting*(n/numToDevideBy);
		} while (std::prev_permutation(bitmask.begin(), bitmask.end()));
	}
	//std::cout<<"total: "<<tot;
		//this pattern 
		// ooo--, oo-o-, oo--o, o-oo-, o-o-o, o--oo, -ooo-, -oo-o
		// for i=0; i <= primes.size()-groupSize; i++
	return n-tot;//n-(tot+(compositeNums*n/baseNum-(primes.size()-1)*n/baseNum));
}

std::vector<int> getPrimes(int n){
	std::vector<int> primesList;
	bool primesNotFound = true;
	int curNum = 2; 
	while(curNum<=n){
		bool repeat = false;
		while(n%curNum==0 && n>1){
			if(!repeat){
				primesList.push_back(curNum);
				repeat = true;
			}
			n/=curNum;
		}
		curNum++;
	}
	//primesList.push_back(n);
	//if(curNum==n) primesList.push_back(curNum);
	return primesList; 
}
std::vector<int> getPrimes2(int n){
	std::vector<int> primesList;
	bool primesNotFound = true;
	int curNum = 2; 
	while(curNum<sqrt(n)){
		bool repeat = false;
		while(n%curNum==0 && n>1){
			if(!repeat){
				primesList.push_back(curNum);
				repeat = true;
			}
			n/=curNum;
		}
		curNum++;
	}
	if(n>1){
		if(curNum==sqrt(n))
			n=curNum;
		primesList.push_back(n);

	}
		
	//if(curNum==n) primesList.push_back(curNum);
	return primesList; 
}

void eulerProblem_69(){
	/*for(int i = 2; i < 10000; i++){
		if(calcTotient(i,getPrimes(i)) != phi(i)){
			std::cout<<"New tot vs old tot "<<i<<std::endl;
			std::cout<<calcTotient(i,getPrimes(i))<<std::endl;
			std::cout<<phi(i)<<std::endl;
		}
	}*/
	double answer = 0;
	double temp=0;
	int solution = 0;
	unsigned long int phiTime = 0;
	unsigned long int totTime = 0;
	for(int i = 2; i <1000000; i++){
		auto t1 = std::chrono::high_resolution_clock::now();
		temp = double(i)/phi(i);
		auto t2 = std::chrono::high_resolution_clock::now();
		phiTime+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();

		t1 = std::chrono::high_resolution_clock::now();
		temp = double(i)/calcTotient(i, getPrimes(i));
		t2 = std::chrono::high_resolution_clock::now();
		totTime+=std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
		if(i%1000==0){
			std::cout<<"phiTime: "<<phiTime<<"ns"<<std::endl;
			std::cout<<"totTime: "<<totTime<<"ns"<<std::endl;
			std::cout<<double(i)/10000<<"% done"<<std::endl;
		}
	}
	std::cout<<"answer: "<<answer<<std::endl;
	std::cout<<"done"<<std::endl;
	/*for(int i = 0; i < 91; i+=2){
		std::cout<<i;
		
			std::cout<<", ";
		
	}
	std::cout<<std::endl;
	for(int i = 0; i < 91; i+=3){
		std::cout<<i;
		
			std::cout<<", ";
		
	}
	std::cout<<std::endl;
	for(int i = 0; i < 91; i+=5){
		std::cout<<i;
		
			std::cout<<", ";
		
	}*/
	//primes.push_back(2);
	//primes.push_back(3);
	//primes.push_back(5);
	/*std::cout<<"n: "<<n<<", primes list: "<<std::endl;
	for(int i = 0; i < primes.size();i++){
		std::cout<<primes[i]<<", ";
	}*/
	//std::cout<<"primes "<<calcTotient(n,primes)<<std::endl;
}
  
void testPrimesVsPrimes2(){
	std::vector<int> primes;
	std::vector<int> newPrimes;
	int numTests = 1000000;
	for(int i = 0; i < numTests; i++){
		primes = getPrimes(i);
		newPrimes = getPrimes2(i);
		if(i%(numTests/100)==0){
			std::cout<<i/(numTests/100)<<"% done"<<std::endl;
		}
		if(primes.size()!=newPrimes.size()){
			std::cout<<"number: "<<i<<std::endl;
			for(int j = 0; j < primes.size(); j++){
				std::cout<<" "<<primes[j];
			}
			std::cout<<std::endl;
			for(int j = 0; j < newPrimes.size(); j++){
				std::cout<<" "<<newPrimes[j];
			}
			std::cout<<std::endl;
		}
		else{
			bool samePrimes = true;
			for(int j = 0; j < primes.size(); j++){
				if(primes[j]!=newPrimes[j]) samePrimes=false;
			}
			if(!samePrimes){
				std::cout<<"number: "<<i<<std::endl;
				for(int j = 0; j < primes.size(); j++){
					std::cout<<" "<<primes[j];
				}
				std::cout<<std::endl;
				for(int j = 0; j < newPrimes.size(); j++){
					std::cout<<" "<<newPrimes[j];
				}
				std::cout<<std::endl;
			}
		}
	}
	std::cout<<"done"<<std::endl;
}

void eulerProblem8(){
	std::string numberString="7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	unsigned long biggestNum = 0;
	unsigned long tempNum = 1;
	for(int j = 0; j < 13; j++){
		tempNum*=int(numberString[j])-48;
		//std::cout<<"string val: "<<numberString[i+j]<<"num val: "<<int(numberString[i+j])-48<<std::endl;
	}
	biggestNum = tempNum;
	std::cout<<tempNum<<std::endl;
	int bigOCounter =13;
	for(int i=13; i < numberString.length(); i++){
		if(int(numberString[i])-48==0){
			i+=12;
			tempNum=1;
		}
		else if(int(numberString[i-13])-48==0){
			tempNum=1;
			for(int j = 0; j < 13; j++){
				if(int(numberString[i-12+j])-48 == 0){
					i+=j+1;
					j=0;
					tempNum=1;
					
				}
				if(i>999) break;
				tempNum*=int(numberString[i-12+j])-48;
				bigOCounter++;
			}
			std::cout<<"?"<<tempNum<<std::endl;
			if(tempNum>biggestNum) biggestNum=tempNum;
		}
		else{
			tempNum/=int(numberString[i-13])-48;
			tempNum*=int(numberString[i])-48;
			bigOCounter++;
			std::cout<<tempNum<<std::endl;
			if(tempNum>biggestNum) biggestNum=tempNum;
		}
		
	}
	std::cout<<"biggest num: "<<biggestNum<<", "<<"bigO: "<<bigOCounter<<std::endl;
}

void eulerProblem9(){
	int totRun = 0;
	for(int a = 1; a < 292; a++){
		//a with the smallest possible b where a<b must fit a^2+b^2<=c^2 to have a chance
		//of finding a b and c that work 
		//a^2 + b^2 <= c^2
		//a^2 + (a+1)^2 <= (1000-(2a+1))^2
		//2a^2 + 2a + 1 <= (999-2a)^2
		//2a^2 + 2a + 1 <= 999^2 - 1998a + 4a^2
		//-2a^2 + 2000a <= 999^2 - 1
		//
		//if(pow(((1000-(a+1))/2),2) + a*a < pow((1000-(a+1))/2,2))
		for(int b=a+1; b < (1000-a)/2; b++){
			int c=1000-(a+b);
			if(a*a+b*b>c*c){
				break;
			}
			totRun++;
			if(a*a+b*b==c*c) {
				std::cout<<a<<", "<<b<<", "<<c<<std::endl;
				std::cout<<a*b*c<<" tot operations "<<totRun;
				a=1000;
				break;
			}
		}
	}
	std::cout<<"done";
}

void getCoins(int temp, int* coinAmounts, int numCoins, int curCoin, int* counter){
	//std::cout<<"temp "<<temp<<", curCoin "<<coinAmounts[curCoin]<<std::endl;
	while(temp>=0){
		if(curCoin<numCoins-1)
			getCoins(temp, coinAmounts, numCoins, curCoin+1, counter);
		temp-=coinAmounts[curCoin];
	}
	if(curCoin==numCoins-1){
		(*counter)++;
	}
	if(curCoin==0){
		std::cout<<(*counter)<<std::endl;
	}
}

void eulerProblem31(){
	int total = 200;
	int* coinAmounts = new int [8]{200,100,50,20,10,5,2,1};
	int ct = 0;
	int* counter = &ct;
	getCoins(total, coinAmounts, 8, 0, counter);
}

void eulerProblem38(){
	int answer=0;
	for(int i = 1; i < 9999; i++){
		int numDigits = 0;
		int temp = i;
		int tot = 0;
		int n=1;
		while(numDigits<9 || n<3){
			//std::cout<<"i: "<<i<<", n: "<<n<<", tot: "<<tot<<std::endl;
			//std::cin.get();
			temp = i*(n);
			while(temp>0){
				temp/=10;
				tot*=10;
				numDigits++;
			}
			tot+=i*n;
			n++;
		}
		if(numDigits==9){
			int mask=511;
			int number=0;
			temp=tot;
			int t=0;
			for(int j = 0; j < 9; j++){
				t=temp%10;
				if(t>0) number+= 1<<(t-1);
				temp/=10;
			}
			if(number==mask){
				if(tot>answer){
					answer=tot;
				}
				//std::cout<<"Pandigital! i: "<<i<<", n: "<<n<<", tot: "<<tot<<", answer: "<<answer<<std::endl;
			}
		}
	}
	std::cout<<"answer: "<<answer<<std::endl;
}

/*
d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
*/
long long int eulerProblem43() {
	int pandigital[] = { 0,1,2,3,4,5,6,7,8,9 };
	int divisible[] = { 2,3,5,7,11,13,17 };
	//std::swap(pandigital[1], pandigital[2]);
	int substr = 0;
	long long int sum = 0;
	do {
		//std::cin.get();
		bool goodSubstring = true;
		for (int i = 1; i < 8; ++i) {
			substr = 0;
			substr += pandigital[i]*100;
			substr += pandigital[i+1]*10;
			substr += pandigital[i+2];
			if (substr%divisible[i - 1]!=0) {
				goodSubstring = false;
				break;
			}
		}
		if (goodSubstring) {
			long long int temp = 0;
			unsigned int multiple = 1;
			for (int i = 9; i >= 0; --i) {
				temp += pandigital[i] * multiple;
				multiple *= 10;
			}
			//std::cout << pandigital[0] << ' ' << pandigital[1] << ' ' << pandigital[2] << ' ' << pandigital[3] << ' ' << pandigital[4] << ' ' << pandigital[5] << ' ' << pandigital[6] << ' ' << pandigital[7] << ' ' << pandigital[8] << ' ' << pandigital[9] << '\n';
			//std::cout << temp << std::endl;
			sum += temp;
			//std::cin.get();
		}
	} while (std::next_permutation(pandigital, pandigital + 10));
	return sum;
}

long long int eulerProblem43b() {
	int pandigital[] = { 0,1,2,3,4,5,6,7,8,9 };
	int divisible[] = { 2,3,5,7,11,13,17 };
	//std::swap(pandigital[1], pandigital[2]);
	long long int sum = 0;
	do {
		//std::cin.get();
		bool goodSubstring = true;
		if (pandigital[3]&1) {
			goodSubstring = false;
			continue;
		}
		if ((pandigital[2]+ pandigital[3]+ pandigital[4]) % 3 != 0) {
			goodSubstring = false;
			continue;
		}
		if (pandigital[5] != 5 && pandigital[5] != 0) {
			goodSubstring = false;
			continue;
		}
		for (int i = 4; i < 8; ++i) {
			if ((pandigital[i] * 100 + pandigital[i + 1] * 10 + pandigital[i + 2])%divisible[i - 1]!=0) {
				goodSubstring = false;
				break;
			}
		}
		
		if (goodSubstring) {
			long long int temp = 0;
			long long int multiple = 1;
			for (int i = 9; i >= 0; --i) {
				temp += pandigital[i] * multiple;
				multiple *= 10;
			}
			//std::cout << pandigital[0] << ' ' << pandigital[1] << ' ' << pandigital[2] << ' ' << pandigital[3] << ' ' << pandigital[4] << ' ' << pandigital[5] << ' ' << pandigital[6] << ' ' << pandigital[7] << ' ' << pandigital[8] << ' ' << pandigital[9] << '\n';
			//std::cout << temp << std::endl;
			sum += temp;
			//std::cin.get();
		}
	} while (std::next_permutation(pandigital, pandigital + 10));
	return sum;
}

long long int eulerProblem43c() {
	int pandigital[] = { 0,1,2,3,4,5,6,7,8,9 };
	int divisible[] = { 2,3,5,7,11,13,17 };
	//std::swap(pandigital[1], pandigital[2]);
	long long int sum = 0;
	long long int temp = 0;
	long long int multiple = 1;
	do {
		//std::cin.get();
		//bool goodSubstring = true;
		if (pandigital[3] & 1 || ((pandigital[2] + pandigital[3] + pandigital[4]) % 3 != 0) || (pandigital[5] != 5 && pandigital[5] != 0)) {
			//goodSubstring = false;
			continue;
		}
		for (int i = 4; i < 8; ++i) {
			if ((pandigital[i] * 100 + pandigital[i + 1] * 10 + pandigital[i + 2]) % divisible[i - 1] != 0) {
				//goodSubstring = false;
				goto ENDOFLOOP;
			}
		}

		temp = 0;
		multiple = 1;
		for (int i = 9; i >= 0; --i) {
			temp += pandigital[i] * multiple;
			multiple *= 10;
		}
		//std::cout << pandigital[0] << ' ' << pandigital[1] << ' ' << pandigital[2] << ' ' << pandigital[3] << ' ' << pandigital[4] << ' ' << pandigital[5] << ' ' << pandigital[6] << ' ' << pandigital[7] << ' ' << pandigital[8] << ' ' << pandigital[9] << '\n';
		//std::cout << temp << std::endl;
		sum += temp;
		//std::cin.get();
		ENDOFLOOP:;
	} while (std::next_permutation(pandigital, pandigital + 10));
	return sum;
}

int eulerProblem44() {
	//n(3n-1)/2
	int p1 = 1, p2 = 5, pdif = INT_MAX;
	std::vector<int> pentagonalNums;
	pentagonalNums.push_back(1);
	pentagonalNums.push_back(5);
	pentagonalNums.push_back(12);
	std::cout<<std::binary_search(pentagonalNums.begin(), pentagonalNums.end(), 1)<<"end cout"<<std::endl;
	int p1i = 2, p2i = 2;
	while (true) {
		++p2i;
		for (int i = p2i; i < 10000; i++) {
			++p2i;
			if (p1i >= pentagonalNums.size()) {
				pentagonalNums.push_back(p1i*(3 * p1i - 1) / 2);
			}
			if (p2i >= pentagonalNums.size()) {
				pentagonalNums.push_back(p2i*(3 * p2i - 1) / 2);
			}
			if (std::binary_search(pentagonalNums.begin(), pentagonalNums.end(), std::abs((p1i*(3 * p1i - 1) / 2) - (p2i*(3 * p2i - 1) / 2)))) {
				//std::cout << (p1i*(3 * p1i - 1) / 2) << ", " << (p2i*(3 * p2i - 1) / 2) << std::endl;
				while (pentagonalNums.back() < (p1i*(3 * p1i - 1) / 2) + (p2i*(3 * p2i - 1))) {
					int q = pentagonalNums.size();
					//std::cout << "q:" << q << std::endl;
					pentagonalNums.push_back(q*(3 * q - 1) / 2);
				}

				if (std::binary_search(pentagonalNums.begin(), pentagonalNums.end(), std::abs((p1i*(3 * p1i - 1) / 2) + (p2i*(3 * p2i - 1) / 2)))) {

					if (std::abs((p1i*(3 * p1i - 1) / 2) - (p2i*(3 * p2i - 1) / 2)) < pdif) {
						pdif = std::abs((p1i*(3 * p1i - 1) / 2) - (p2i*(3 * p2i - 1) / 2));
						std::cout << "min p so far: " << pdif << ", p1, p1: " << p1i << "," << p2i << std::endl;
					}
				}
			}
		}
		p2i = p1i;
		++p1i;
		
	}
	return pdif;
}

struct StrNumPair {
	int n1 = 0, n2 = 0, diff = 0;
};
bool myfunction(StrNumPair i, StrNumPair j) { return (i.diff < j.diff); }
int eulerProblem44Helper() {
	std::vector<StrNumPair> tries;
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 10; j++) {
			tries.push_back({ i, j, (j*(3*j-1)/2) - (i*(3 * i - 1) / 2) });
			//std::cout << i << ',' << j << ',' << 0 << std::endl;
			std::sort(tries.begin(), tries.end(), myfunction);
		}
	}
	for (int i = 0; i < tries.size(); i++)
		std::cout << tries.at(i).n1 << ',' << tries.at(i).n2 << ',' << tries.at(i).diff << std::endl;
	return 7;
}

int eulerProblem44b() {
	//n(3n-1)/2;
	return 0;
}