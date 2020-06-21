#include <iostream>
#include <string>
#include <cmath>
void eulerProblem7();
void eulerProblem30();
void eulerProblem26();
void eulerProblem17();
int main() {
	eulerProblem17();
	std::cin.get();
	return 0;
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
	std::cout<<" Tim Flavin did this";
}
