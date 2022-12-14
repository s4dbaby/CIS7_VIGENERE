// Jimmy Lam
// CIS-7 Discrete Structures
// Professor Kasey Nguyen
// Case 3: Vigenere Cipher Decryption

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string vigenere_encryption(string pt, string key)
{
	string encrypted_txt = ""; // initialize variables
	string keyTotal = "";
	string op;
	string ptKey;
	int keyCount = 0;

	transform(pt.begin(), pt.end(), pt.begin(), ::toupper); // uppercase plaintext and key
	transform(key.begin(), key.end(), key.begin(), ::toupper);

	for (int i = 0; i < pt.length(); i++) // lengthens key and matches whitespace location 
	{
		if ((key.length() != pt.length()) && (pt[i] != ' '))
		{
			if (key[keyCount] != '\0')
			{
				ptKey = key[keyCount];
				keyCount++;
				keyTotal += ptKey;
			}
			else
			{
				keyCount = 0;
				ptKey = key[keyCount];
				keyCount++;
				keyTotal += ptKey;
			}
		}
		else if ((key.length() != pt.length()) && (pt[i] == ' '))
		{
			keyTotal += ' ';
		}
	}

	for (int i = 0; pt[i] != '\0'; ++i) // loops each char 
	{
		if(pt[i] == ' ')
			encrypted_txt += ' ';
		else
		{ 
			op = (pt[i] + keyTotal[i]) % 26 + 65; // vigenere encryption algorithm

			encrypted_txt += op; // accumulates cipher calculation to encrypted_txt
		}
	}

	return encrypted_txt; // returning decrypted text
}

string vigenere_decryption(string ct, string key)
{
	string decrypted_txt = ""; // initializing variable
	string op;
	string keyTotal = "";
	string ctKey;
	int keyCount = 0;

	transform(ct.begin(), ct.end(), ct.begin(), ::toupper); // uppercase cipher and key
	transform(key.begin(), key.end(), key.begin(), ::toupper);

	for (int i = 0; i < ct.length(); i++) // lengthens key and matches whitespace location 
	{
		if ((key.length() != ct.length()) && (ct[i] != ' '))
		{
			if (key[keyCount] != '\0')
			{
				ctKey = key[keyCount];
				keyCount++;
				keyTotal += ctKey;
			}
			else
			{
				keyCount = 0;
				ctKey = key[keyCount];
				keyCount++;
				keyTotal += ctKey;
			}
		}
		else if ((key.length() != ct.length()) && (ct[i] == ' '))
		{
			keyTotal += ' ';
		}
	}

	for (int i = 0; ct[i] != '\0'; ++i) // loops each char 
	{
		if (ct[i] == ' ')
			decrypted_txt += ' ';
		else
		{
			op = (ct[i] - keyTotal[i] + 26) % 26 + 65; // vigenere encryption algorithm

			decrypted_txt += op; // accumulates cipher calculation to encrypted_txt
		}
	}

	return decrypted_txt; // returning decrypted text
}

int main()
{
	string c; // cin variables
	string plaintext, key, ciphertext;

	do // loops + asks user if they want to repeat program
	{
		cout << "PRESS 1 TO ENCRYPT\n"; // choices
		cout << "PRESS 2 TO DECRYPT\n";
		cout << "PRESS 3 TO END\n\n";
		cout << "INPUT: ";
		cin >> c;
		cin.ignore();

		if (c == "1") // choice if statement
		{
			cout << "\nPLEASE ENTER YOUR PLAINTEXT AND PRESS ENTER TWICE: ";
			getline(cin, plaintext);
			cin.ignore();

			cout << "PLEASE ENTER YOUR KEY AND PRESS ENTER TWICE: ";
			getline(cin, key);
			cin.ignore();
			// displays encrypted text
			cout << "ENCRYPTED TEXT: " << vigenere_encryption(plaintext, key) << endl << endl;
		}
		else if (c == "2")
		{
			cout << "\nPLEASE ENTER YOUR CIPHERTEXT AND PRESS ENTER TWICE: ";
			getline(cin, ciphertext);
			cin.ignore();

			cout << "PLEASE ENTER YOUR KEY AND PRESS ENTER TWICE: ";
			getline(cin, key);
			cin.ignore();
			// displays decrypted text
			cout << "DECRYPTED TEXT: " << vigenere_decryption(ciphertext, key) << endl << endl;
		}
		else if(c == "3")
			cout << "\nGOODBYE!\n\n";
		else 
			cout << "\nWRONG INPUT...PLEASE RESTART AND TRY AGAIN\n";
		break;
	} while (c != "3"); // ends if input is 3

	return 0;
}