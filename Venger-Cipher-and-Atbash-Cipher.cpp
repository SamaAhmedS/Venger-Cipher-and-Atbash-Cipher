/*
FCAI – Programming 1 – 2022 - Assignment 2
Author: Sama Ahmed saeed
ID:20210163
Program Name:Vignere Cipher
Program Description: using way VingereCipher Add each letter in the encrypted message with its corresponding letterthen make
it %26 then add Ascii of A,then change the message to char (the result) if choice is cipher.
Using way Atbash Cipher sum ascii of the two letters =155.
Purpose: Encrypt the message if the user wants to, or decrypt it.
*/

#include <cstring>
#include <iostream>
#include<string>
using namespace std;
void toUpper(string& message);
void cipherAndDecipher_atbashCipher();
string repeatingKeyword(string message);
void vingereCipher();
void DecipherMessage();

int main() {
	string choosenProcess;
	cout << "Ahlan ya user ya habibi.\nWhat do you like to do today?\n";
	cout << "Enter V for using way VingereCipher or A for using way Atbash Cipher then";
	cout << "1-To cipher a message Enter--> 1\n2 - To Decipher a message Enter--> 2\n3- End Enter-->0\n";
	do {
		getline(cin, choosenProcess);
		if (choosenProcess[0] == 'V') {
			if (choosenProcess[1] == '1') {
				vingereCipher();
			}

			else if (choosenProcess[1] == '2') {
				DecipherMessage();
			}
		}
		else if (choosenProcess[0] == 'A') {
			if (choosenProcess[1] == '1'|| choosenProcess[1] == '2') {
				cipherAndDecipher_atbashCipher();
			}
		}
		cout << "\nEnter c if you want to complete if you to stop Enter s\n";
		getline(cin, choosenProcess);
		if (choosenProcess == "s")break;
		cout << "1-To cipher a message Enter--> 1\n2 - To Decipher a message Enter--> 2\n3- End Enter-->0\n";
	} while (choosenProcess == "c");
}
void toUpper(string& message) {
	//Convert the text to uppercase
	int size = message.size();
	for (int i = 0; i < size; i++) {
		if (isspace(message[i]) == 0 && isdigit(message[i]) == 0) {
			message[i] = toupper(message[i]);
		}
	}
}
string repeatingKeyword(string message) {
	//Repeate KeyWord to equal the length of the message to be encrypted 
	//As we wont to plus each letter in the encrypted message with its corresponding letter 
	string keyword, repeated_keyword = "";
	cout << "please enter akeyword less than or equal 8 char" << endl;
	getline(cin, keyword);
	while (keyword.size() > 8) {
		//if length of the key word biger than 8 then this key word dosenot valid
		cout << "please enter akeyword less than or equal 8 char" << endl;
		getline(cin, keyword);
	}
	toUpper(keyword);//Covert the word to uppercase
	int remain = (message.size()) % (keyword.size());
	int itration = ((message.size()) / (keyword.size()));
	for (int j = 0; j < itration; j++) {
		repeated_keyword += keyword;
	}
	repeated_keyword += keyword.substr(0, remain);
	return repeated_keyword;
}
void vingereCipher() {
	string message;
	cout << "please enter the message you wont to cipher it: " << endl;
	getline(cin, message);//take the message to cipher it 
	toUpper(message);
	string repeatedkeyword = repeatingKeyword(message);
	int size = (message.size());
	for (int x = 0; x < size; x++) {
		if (isspace(message[x]) || isdigit(message[x]))continue;
		//if char== space or number Donot encrypt it 
		else
			message[x] = (char)((((int)repeatedkeyword[x] + (int)message[x]) % 26) + (int)'A');
		// Add each letter in the encrypted message with its corresponding letter then make it %26 
		// then add Ascii of A,then change the message to char (the result)
	}
	cout << "The encrypted message by vingere_cipher is " << endl;
	cout << message;
}
void DecipherMessage() {
	// add each letter in the encrypted message with its corresponding letter then make it %26 
	// then add Ascii of A = result
	// if char(result)== the corresponding letter in the Encrypted Message 
	//then it was the letter in the message befor incrypting
	string encryptedMessage, message = "";
	cout << "Please enter the Encrypted Message: " << endl;
	getline(cin, encryptedMessage);
	toUpper(encryptedMessage);
	string repeatedkeyword = repeatingKeyword(encryptedMessage);
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int size = (encryptedMessage.size());
	for (int x = 0; x < size; x++) {
		if (isspace(encryptedMessage[x])) {
			message += encryptedMessage[x];
		}
		else if (isdigit(encryptedMessage[x])) {
			message += encryptedMessage[x];
		}
		else {
			int size_alpha = alphabet.size();
			for (int j = 0; j < size_alpha; j++) {
				char encryptedchar = (char)((((int)repeatedkeyword[x] + (int)alphabet[j]) % 26) + (int)'A');
				if (encryptedMessage[x] == encryptedchar) {
					message += alphabet[j];
				}
			}
		}
	}
	cout << "Decipher a message by vingere_cipher is " << endl;
	cout << message;
}

void cipherAndDecipher_atbashCipher() {
	string message;
	cout << "please enter the message you wont to cipher it: " << endl;
	getline(cin, message);
	toUpper(message);
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < message.size(); i++) {
		for (int x = 0; x < alphabet.size(); x++) {
			if (isspace(message[i]) || isdigit(message[i]))continue;
			else if ((int)message[i] + (int)alphabet[x] == 155) {
				message[i] = alphabet[x];
				break;
			}
		}
	}
	cout << "the encrypted message or deciphered message is \n";
	cout << message;
}
