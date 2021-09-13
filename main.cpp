//Programme édité le 13/09/2021 par Pascal KESHMIRI
//Valable uniquement pour les valeurs décimales de 1 à 1000
//IDE utilisé : Visual Studio 2019

#include <iostream>
#include <string>
#include <math.h>
#include <bitset>


//méthode qui indique la taille de la liste des valeurs binaires correspondantes à la valeur entière d'entrée
const int setBinaryOrder(int entryNumber){
	int it = 0;
	int binaryPower = pow(2, it);

	while (entryNumber > binaryPower) {binaryPower = pow(2, it++);}
	const int result = it - 1;
	return result;
}

//méthode qui restitue toutes les puissances de deux avec comme paramètre la taille de la liste
int* getBinaryPowerArray(const int size) {
	int* output = new int[size];
	for (int i = 0; i < size; i++) {
		*(output + i) = (int)pow(2, size - i-1);
	}
	return output;
}

//méthode pour convertir la valeur décimale d'entrée en valeur binaire
std::bitset<32> toBinary(int entryNumber) {
	const int binarySize = setBinaryOrder(entryNumber);
	int* binaryPowersArray = getBinaryPowerArray(binarySize);

	int* binaryTempArray = new int[binarySize];

	for (int i = 0; i < binarySize; i++) {
		if (entryNumber > *(binaryPowersArray + i)) {
			entryNumber -= *(binaryPowersArray + i);
			*(binaryTempArray + i) = 1;
		}
		else if (entryNumber < *(binaryPowersArray + i)) {
			*(binaryTempArray + i) = 0;
		}
		else {
			*(binaryTempArray + i) = 1;
		}
	}

	int binaryOutput = 0;

	for (int i = 0; i < binarySize; i++) {
		binaryOutput += pow(10, binarySize - i - 1)* *(binaryTempArray + i);
	}

	std::string binaryStringTemp = std::to_string(binaryOutput);
	std::bitset<32> binary(binaryStringTemp);

	return binary;
}

int main() {

	int userNumber;
	int storedNumber;
	std::cout << "Type a number: ";
	std::cin >> userNumber;
	storedNumber = userNumber;
	std::cout << "stored value : " << storedNumber << std::endl;
	std::cout << "Converted stored value to binary: " << toBinary(storedNumber) << std::endl;
  
}
