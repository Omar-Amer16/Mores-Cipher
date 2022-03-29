/*
    Name   : Omar Amer Ahmed
    ID     : 20210267
    Cipher : Morse Cipher (Number 7)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

// A map to store each character with it's corresponding cipher code.

map<char, string> cipher{

        {'a', ".-"},{'b',"-..."},{'c',"-.-."},{'d',"-.."},{'e',"."},{'f',"..-."},
        {'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"},{'l',".-.."},
        {'m',"--"},{'n',"-."},{'o',"---"},{'p',".--."},{'q',"--.-"},{'r',".-."},
        {'s',"..."},{'t',"-"},{'u',"..-"},{'v',"...-"},{'w',".--"},{'x',"-..-"},
        {'y',"-.--"},{'z',"--.."}

};
void encryption();
void decryption();

int main() {
    // Getting the user to choose either to encrypt or decrypt.

    char choice;
    cout << "Do you want to encrypt or decrypt a message ?, for encryption write e and for decryption write d: " << endl;
    cin >> choice;
    cin.ignore();

    if(choice == 'e' or choice == 'E')
        encryption();
    else if (choice == 'd' or choice == 'D')
        decryption();
    else
        cout << "Please enter e or d.";

    return 0;
}

void encryption(){

    // Taking the message the user wants to cipher

    cout << "Please enter the sentence you want to cipher: " << endl;
    string sentence;
    getline(cin, sentence);

    // Converting the input into lowercase, so we can use the map.

    for (char & i : sentence) {
        i = tolower(i);
    }

    // Interchanging the input with the map's keys.

    for (char i : sentence){
        if ( i == char(32)) {
            cipher[i] = "   ";
        }
        cout << cipher[i] << " ";
        // Don't put break
    }
}
void decryption(){
    string code, token;
    istringstream is("");

    // Taking the message the user wants to decipher

    cout << "Please enter the encrypted message you want to decrypt: " << endl;

    getline(cin, code);
    is.str(code);

    is >> token;

    // Interchanging the input with the map's values

    while(is) {
        for (char i = 97; i < 122; i++) {
            if (cipher[i] == token) {
                cout << i;
                break;
            }
        }
        is >> token;
    }
    cout << endl;
}