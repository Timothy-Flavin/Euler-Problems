#include <iostream>
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
		for (int i = 0; i < counter && primeList[i] <= sqrt(currentNum); i++) {
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
	for (int i = 2; i < pow(9, power)*(power+1); i++) {
		int digitCounter = 0;
		int temp = i;
		for (int j = 0; j < power+1; j++) {
			digitCounter += pow(temp % 10,power);
			temp /= 10;
		}
		if (digitCounter == i) {
			answer += digitCounter;
		}
	}
	std::cout << "answer: " << answer << std::endl;
}

void eulerProblem17() {
	std::string[] onesPlace = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
	std::string[] teens = ["eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"];
	int[9] oneePlaceLengths;
	int[9] teensLengths;

	for (int i = 0; i < 9; i++) {
		onesPlaceLengths = onesPlace[i].length();
		teensLengths = teens[i].length();
	}

	std::cout << onsePLaceLengths<<std::endl;
	std::cout < teensLengths<<std::endl;
}