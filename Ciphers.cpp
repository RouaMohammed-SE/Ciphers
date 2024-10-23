/*
Name: Roaa mohammed sayed 
Email : rouamohamedse@gmail.com
Program Description: 7 encrypting/decrypting methods using Affine cipher,Route cipher,Vignere cipher
Simple substitution cipher,Polybius Square Cipher,Morse Code cipher,Rail-fence Cipher
Last Modification Date: 18/3/2024

*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <limits>
using namespace std;
//Affine cipher
void main_function_Affine();
void encryption1(int a, int b, int c, string cs);
void decryption1(int a, int b, int c, string cs);
//Route cipher
void main_function_Route();
void encryption2(vector<vector<char>>v, int row);
void decryption2(vector<vector<char>>v, int row);
//Vignere cipher
void main_function_Vignere();
string generateKey(string str, string key);
string cipherText(string str, string key);
string originalText(string cipher_text, string key);
//Simple Substitution Cipher
void main_function_Substitution();
void encryption3(string str, map<char, char>mp2);
void decryption3(string str, map<char, char>mp1);
//Polybius Square Cipher
void main_function_Polybius();
void encryption4(string str, vector<vector<int>>v);
void decryption4(string str, vector<vector<int>>v);
//Morse code cipher
void main_function_Morse();
void encryption5(string str, map<char, string>mp);
void decryption5(string str, map<string, char>mp1);
//rail-fence cipher
string removeSpacesAndSpecialChars(string text);
string railFence_cipher(string text, int key);
string railFence_decipher(string text, int key);
void main_function_Rail();
int main(void)
{
    cout << "Welcome to ciphers encryption/decryption" << endl;
    while (true)
    {
        char ans;
        while (true)
        {
            cout << "which cipher do you want to use today" << endl;
            cout << "A)Affine cipher" << endl;
            cout << "B)Route cipher" << endl;
            cout << "C)Vignere cipher" << endl;
            cout << "D)Simple substitution" << endl;
            cout << "E)Polybius square cipher" << endl;
            cout << "F) Morse code cipher" << endl;
            cout << "G)Railway cipher" << endl;
            cout << "H)Exit" << endl;
            cin >> ans;
            if (toupper(ans) == 'A' || toupper(ans) == 'B' || toupper(ans) == 'C' || toupper(ans) == 'D' || toupper(ans) == 'E' || toupper(ans) == 'F' || toupper(ans) == 'G' || toupper(ans) == 'H')break;
            cout << "Please insert a correct value" << endl;

        }
        if (toupper(ans) == 'H')break;
        if (toupper(ans) == 'A')main_function_Affine();
        else if (toupper(ans) == 'B')main_function_Route();
        else if (toupper(ans) == 'C')main_function_Vignere();
        else if (toupper(ans) == 'D')main_function_Substitution();
        else if (toupper(ans) == 'E')main_function_Polybius();
        else if (toupper(ans) == 'F')main_function_Morse();
        else if (toupper(ans) == 'G')main_function_Rail();
    }
}
// Function for the main Affine cipher program
void main_function_Affine() {
    // Welcome message
    cout << "Welcome to Affine cipher game" << endl;
    // Main loop for the program
    while (true) {
        char choice, cc;
        string cs;
        // Loop to get a valid choice from the user
        while (true) {
            cout << "Choose the method that you want to apply:" << endl;
            cout << "A) Encryption" << endl;
            cout << "B) Decryption" << endl;
            cout << "C) Return" << endl;
            cin >> choice;
            // Check if the choice is valid
            if (toupper(choice) == 'A' || toupper(choice) == 'B' || toupper(choice) == 'C')
                break;
            cout << "Please choose a correct value" << endl;
        }
        // Exit the loop if the choice is to return
        if (toupper(choice) == 'C') break;
        int a, b, c;
        // Loop to get valid parameters for encryption/decryption
        while (true) {
            cout << "Input the three parameters a, b, c: ";
            cin >> a >> b >> c;

            // Check if the input was successful and if a*c % 26 == 1
            if (cin.fail() || (a * c) % 26 != 1) {
                cout << "Please insert correct values that satisfy the equation (a*c) % 26 == 1" << endl;
                // Clear error flags and discard input buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        // Get the character input from the user
        cout << "Input a string: ";
        cin >> cs;
        // Perform encryption if the choice is 'A'
        if (toupper(choice) == 'A') {
            cout << "Plain text = " << cs << endl;
            encryption1(a, b, c, cs);
        }
        // Perform decryption if the choice is 'B'
        else if (toupper(choice) == 'B') {
            cout << "Cipher text = " << cs << endl;
            decryption1(a, b, c, cs);
        }
    }
}

// Function for Affine encryption
void encryption1(int a, int b, int c, string cs) {
    cout << "Cipher text = ";
    for (auto i : cs)
    {
        int x = toupper(i) % 65;
        char result = (((5 * x) + 8) % 26) + 'A';
        cout << result;
    }
    cout << endl;

}

// Function for Affine decryption
void decryption1(int a, int b, int c, string cs) {
    cout << "Plain text: ";
    for (auto i : cs)
    {
        int y = toupper(i) % 65;
        int result = (21 * (y - 8));
        while (result >= 26) result -= 26;
        while (result < 0) result += 26;
        cout << char(result + 'a');
    }
    cout << endl;

}
// Function for the main Route cipher program
void main_function_Route() {
    // Welcome message
    cout << "Welcome to Route cipher" << endl;
    char choice;
    // Main loop for the program
    while (true) {
        while (true) {
            // Loop to get a valid choice from the user
            cout << "Choose the method that you want to apply:" << endl;
            cout << "A) Encryption" << endl;
            cout << "B) Decryption" << endl;
            cout << "C) Return" << endl;
            cin >> choice;
            // Check if the choice is valid
            if (toupper(choice) == 'A' || toupper(choice) == 'B' || toupper(choice) == 'C')
                break;
            cout << "Please choose a correct value" << endl;
        }
        // Exit the loop if the choice is to return
        if (toupper(choice) == 'C') break;
        cout << "Input your string: ";
        cin.ignore();
        string f, s = "";
        getline(cin, f);
        // Remove spaces from the input string
        for (auto i : f) {
            if (i != ' ') s += i;
        }
        // Calculate the number of rows in the grid
        int row = s.size() / 3;
        vector<vector<char>>v(row, vector<char>(3, 'x'));
        int n = 0;
        // Populate the grid with characters from the input string
        for (int i = 0; i < row; i++) {
            if (n == s.size() - 1)break;
            for (int j = 0; j < 3; j++) {
                v[i][j] = s[n];
                n++;
                if (n == s.size() - 1)break;
            }
        }
        // Perform encryption if the choice is 'A'
        if (toupper(choice) == 'A')
            cout << "Plain text: " << f << endl, encryption2(v, row);
        // Perform decryption if the choice is 'B'
        else
            cout << "Cipher text: " << f << endl, decryption2(v, row);
    }
}

// Function for Route cipher encryption
void encryption2(vector<vector<char>> v, int row) {
    cout << "Cipher text: ";
    // Output the characters from the last column of the grid
    for (int i = 0; i < row; i++) {
        cout << v[i][2];
    }
    // Output the characters from the last row (in reverse order)
    for (int j = 1; j >= 0; j--) {
        cout << v[row - 1][j];
    }
    // Output the characters from the first column (in reverse order)
    for (int i = row - 2; i >= 0; i--) {
        cout << v[i][0];
    }
    // Output the characters from the second column
    for (int i = 0; i < row - 1; i++) {
        cout << v[i][1];
    }
    cout << endl;
}

// Function for Route cipher decryption
void decryption2(vector<vector<char>> v, int row) {
    cout << "Plain text: ";
    // Output the characters from the second column (in reverse order)
    for (int i = row - 2; i >= 0; i--) {
        cout << v[i][1];
    }
    // Output the characters from the first column
    for (int i = 0; i < row; i++) {
        cout << v[i][0];
    }
    // Output the character from the last row
    cout << v[row - 1][1];
    // Output the characters from the last column (in reverse order)
    for (int i = row - 1; i >= 0; i--) {
        cout << v[i][2];
    }
    cout << endl;
}

//Vignere cipher
void main_function_Vignere()
{
    int choice;
    string str, keyword;
    bool flag = 1;
    while (flag) {
        // Display menu
        cout << "What do you like to do today?" << endl;
        cout << "1- Cipher a message" << endl;
        cout << "2- Decipher a message" << endl;
        cout << "3-Return" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
        case 1: {
            // Encryption process
            while (true) {
                cout << "Enter the original text: ";
                getline(cin, str);
                if (str.length() > 80) {
                    cout << "Message is too long. Maximum 80 characters allowed." << endl;
                    continue;
                }

                while (true) {
                    cout << "Enter the keyword: ";
                    getline(cin, keyword);
                    if (keyword.length() > 8) {
                        cout << "Keyword is too long. Maximum 8 characters allowed." << endl;
                        continue;
                    }
                    break;
                }

                // Validate keyword
                bool validKeyword = true;
                for (char c : keyword) {
                    if (!isalpha(c)) {
                        cout << "Keyword should contain only alphabetic characters." << endl;
                        validKeyword = false;
                        break;
                    }
                }
                if (!validKeyword)
                    continue;

                break;
            }
            // Generate key and encrypt text
            string key = generateKey(str, keyword);
            string cipher_text = cipherText(str, key);
            cout << "Ciphertext : " << cipher_text << endl;
            break;
        }

        case 2: {
            // Decryption process
            while (true) {
                cout << "Enter the encrypted text: ";
                getline(cin, str);
                if (str.length() > 80) {
                    cout << "Message is too long. Maximum 80 characters allowed." << endl;
                    continue;
                }

                while (true) {
                    cout << "Enter the keyword: ";
                    getline(cin, keyword);
                    if (keyword.length() > 8) {
                        cout << "Keyword is too long. Maximum 8 characters allowed." << endl;
                        continue;
                    }
                    break;
                }

                // Validate keyword
                bool validKeyword = true;
                for (char c : keyword) {
                    if (!isalpha(c)) {
                        cout << "Keyword should contain only alphabetic characters." << endl;
                        validKeyword = false;
                        break;
                    }
                }
                if (!validKeyword)
                    continue;

                break;
            }
            // Generate key and decrypt text
            string key = generateKey(str, keyword);
            string decrypted_text = originalText(str, key);
            cout << "Decrypted text: " << decrypted_text << endl;
            break;
        }

        case 3:
            flag = 0;
            break;

        default:
            // Invalid choice
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}
string generateKey(string str, string key)
{
    int x = str.size();

    for (int i = 0; ; i++) {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}
string cipherText(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            // Encrypt alphabetic characters
            char x = ((toupper(str[i]) + toupper(key[i])) % 26) + 'A';
            cipher_text.push_back(x);
        }
        else {
            // Keep non-alphabetic characters unchanged
            cipher_text.push_back(str[i]);
        }
    }
    return cipher_text;
}
string originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0; i < cipher_text.size(); i++) {
        if (isalpha(cipher_text[i])) {
            // Decrypt alphabetic characters
            char x = (((toupper(cipher_text[i]) - toupper(key[i % key.size()])) + 26) % 26) + 'A';
            orig_text.push_back(x);
        }
        else {
            // Keep non-alphabetic characters unchanged
            orig_text.push_back(cipher_text[i]);
        }
    }
    return orig_text;
}
// Function for Simple Substitution Cipher
void main_function_Substitution() {
    char ans;
    // Welcome message
    cout << "Welcome to Simple Substitution Cipher." << endl;
    // Main loop for the program
    while (true) {
        while (true) {
            // Loop to get a valid choice from the user
            cout << "What do you like to do today?" << endl;
            cout << "A) Encrypt" << endl;
            cout << "B) Decrypt" << endl;
            cout << "C) Return" << endl;
            cin >> ans;
            // Check if the choice is valid
            if (toupper(ans) == 'A' || toupper(ans) == 'B' || toupper(ans) == 'C')
                break;
            cout << "Please select a valid value" << endl;
        }
        // Exit the loop if the choice is to return
        if (toupper(ans) == 'C') break;
        int count = 0;
        // Maps for encryption and decryption
        map<char, char> mp1;
        map<char, char> mp2;
        string key;
        // Get the key from the user
        cout << "Enter the key: ";
        cin >> key;
        // Construct encryption and decryption maps based on the key
        for (int i = 0; i < 5; i++) {
            mp1[(toupper(key[i]))] = char('A' + i);
            mp2[char('A' + i)] = toupper(key[i]);
        }
        // Fill the remaining characters in the maps
        for (int i = 0; i < 26; i++) {
            if (!mp1.count(char('A' + i))) {
                mp2[char('F' + count)] = char('A' + i);
                mp1[char('A' + i)] = char('F' + count);
                count++;
            }
        }
        // Prompt user for text input
        if (toupper(ans) == 'A')
            cout << "Plain text: ";
        else
            cout << "Cipher text: ";
        cin.ignore();
        string str;
        getline(cin, str);
        // Perform encryption or decryption based on user choice
        if (toupper(ans) == 'A')
            encryption3(str, mp2);
        else
            decryption3(str, mp1);
    }
}

// Function for Simple Substitution encryption
void encryption3(string str, map<char, char> mp2) {
    cout << "Cipher text: ";
    for (auto i : str) {
        char x = toupper(i);
        if (x != ' ')
            cout << mp2[x];
        else
            cout << " ";
    }
    cout << endl;
}

// Function for Simple Substitution decryption
void decryption3(string str, map<char, char> mp1) {
    cout << "Plain text: ";
    for (auto i : str) {
        char x = toupper(i);
        if (x != ' ')
            cout << mp1[x];
        else
            cout << " ";
    }
    cout << endl;
}

// Function for Polybius Square Cipher
void main_function_Polybius() {
    // Welcome message
    cout << "Welcome to Polybius Square Cipher" << endl;
    // Main loop for the program
    while (true) {
        char ans;
        while (true) {
            // Loop to get a valid choice from the user
            cout << "What do you want to do today?" << endl;
            cout << "A) Encryption" << endl;
            cout << "B) Decryption" << endl;
            cout << "C) Return" << endl;
            cin >> ans;
            // Check if the choice is valid
            if (toupper(ans) == 'A' || toupper(ans) == 'B' || toupper(ans) == 'C')
                break;
            cout << "Please choose a correct value" << endl;
        }
        // Exit the loop if the choice is to return
        if (toupper(ans) == 'C') break;
        int count = 0;
        // Initialize a 6x6 grid for the Polybius Square
        vector<vector<int>> v(6, vector<int>(6));
        int n[5];
        cout << "Enter your key: ";
        // Get the key from the user
        for (int i = 0; i < 5; i++) cin >> n[i];
        // Fill the Polybius Square grid using the key
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (char('A' + count) == 'J')
                    count++, v[n[i]][n[j]] = ('A' + count);
                else
                    v[n[i]][n[j]] = ('A' + count);
                count++;
            }
        }
        // Perform encryption or decryption based on user choice
        if (toupper(ans) == 'A') {
            cout << "Plain text: ";
            cin.ignore();
            string str;
            getline(cin, str);
            encryption4(str, v);
        }
        else {
            cout << "Encrypted text: ";
            cin.ignore();
            string str;
            getline(cin, str);
            decryption4(str, v);
        }
    }
}

// Function for Polybius Square encryption
void encryption4(string str, vector<vector<int>> v) {
    char x;
    cout << "Encrypted text: ";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') continue;
        else {
            for (int k = 1; k < 6; k++) {
                for (int j = 1; j < 6; j++) {
                    x = toupper(str[i]);
                    if (v[k][j] == int(x)) cout << k << j;
                }
            }
        }
    }
    cout << endl;
}

// Function for Polybius Square decryption
void decryption4(string str, vector<vector<int>> v) {
    cout << "Plain text: ";
    for (int i = 0; i < str.size(); i += 2) {
        if (str[i] == ' ') i++;
        int row = str[i] - '0';
        int col = str[i + 1] - '0';
        if (str[i] != ' ') cout << char((v[row][col]));
    }
    cout << endl;
}

// Function for Morse code cipher
void main_function_Morse() {
    map<char, string> mp = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}
    };
    map<string, char> mp1;
    for (auto i : mp) {
        mp1[i.second] = i.first;
    }
    while (true) {
        char ans;
        while (true) {
            cout << "What do you want to do today" << endl;
            cout << "A) encryption" << endl;
            cout << "B) decryption" << endl;
            cout << "C) Return" << endl;
            cin >> ans;
            ans = toupper(ans); // Convert to uppercase for case-insensitive comparison
            if (ans == 'A' || ans == 'B' || ans == 'C') break;
            cout << "Invalid choice. Please enter a valid option." << endl;
            // Clear input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (ans == 'C') break;

        cout << "Enter the string" << endl;
        cin.ignore();
        string str;
        getline(cin, str);
        if (ans == 'A') {
            cout << "Morse text: ";
            encryption5(str, mp);
        }
        else {
            cout << "Cipher text: ";
            decryption5(str, mp1);
        }
    }
}

void encryption5(string str, map<char, string> mp) {
    string morseText = "";
    for (char& c : str) {
        if (c == ' ') {
            morseText += "   "; // Three spaces between words
        }
        else if (mp.find(toupper(c)) != mp.end()) {
            morseText += mp[toupper(c)] + " "; // Morse code for the character with a space between letters
        }
    }
    cout << morseText << endl;
}

void decryption5(string str, map<string, char> mp1) {
    string word = "";
    string decryptedText = "";
    for (char& c : str) {
        if (c == ' ') {
            if (!word.empty()) { // Check if word is not empty before decryption
                decryptedText += mp1[word];
                word = "";
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) { // Check if word is not empty before decryption
        decryptedText += mp1[word];
    }
    cout << decryptedText << endl;
}
//Rail-fence cipher
// Function to remove spaces and special characters from a string and convert to lowercase
string removeSpacesAndSpecialChars(string text) {
    string result;
    // Iterate through each character in the input text
    for (char ch : text) {
        // Check if the character is alphanumeric
        if (isalnum(ch)) {
            // Convert alphanumeric characters to lowercase
            result.push_back(tolower(ch));
        }
    }
    // Return the modified string
    return result;
}
// Function to perform Rail-Fence encryption
string railFence_cipher(string text, int key) {
    int size = text.size();
    // Dynamically allocate memory for the 2D array

    char** arr = new char* [key];
    for (int i = 0; i < key; ++i) {
        arr[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            // Initialize each element of the array with a placeholder character
            arr[i][j] = '.';
        }
    }

    // Iterate over the 2D array in a zigzag pattern
    int row = 0;
    bool down = true;

    // Fill the array with the characters from the text
    for (int i = 0; i < size; ++i) {
        arr[row][i] = text[i];

        // Check if we need to change direction
        if (row == 0) {
            down = true;  // Move down if at the top row
        }
        else if (row == key - 1) {
            down = false;  // Move down if at the top row
        }
        // Update the row based on the direction
        if (down) {
            ++row;
        }
        else {
            --row;
        }
    }
    string res;
    // Construct the result string by reading off the characters from the array
    for (int i = 0; i < key; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] != '.') {
                res += arr[i][j];
            }
        }
    }

    // Deallocate the memory for the 2D array
    for (int i = 0; i < key; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return res;
}
// Function to perform Rail-Fence decryption
string railFence_decipher(string text, int key) {
    int size = text.size();

    // Dynamically allocate memory for the 2D array
    char** arr = new char* [key];
    for (int i = 0; i < key; ++i) {
        arr[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            // Initialize each element of the array with a placeholder character
            arr[i][j] = ' ';
        }
    }

    int row = 0;
    bool down = true;

    // highlight only the needed space in each row
    for (int i = 0; i < size; ++i) {
        arr[row][i] = '.';

        // Check if we need to change direction
        if (row == 0) {
            down = true;        // Move down if at the top row
        }
        else if (row == key - 1) {
            down = false;       // Move up if at the bottom row
        }
        // Update the row based on the direction
        if (down) {
            ++row;
        }
        else {
            --row;
        }
    }

    int pointer = 0;
    // Fill the array horizontaly with the characters from the ciphertext
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == '.') {
                arr[i][j] = text[pointer];
                pointer += 1;
            }
        }
    }

    string res;
    // Construct the plaintext by reading off the characters from the array vertically
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < key; j++) {
            if (arr[j][i] != ' ') {
                res.push_back(arr[j][i]);
                break;
            }
        }
    }

    // Deallocate the memory for the 2D array
    for (int i = 0; i < key; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return res;
}
//main function
void main_function_Rail() {
    string text;
    int choice;
    // Display welcome message and options
    while (true)
    {
        cout << "**********Welcome to Rail-Fence cipher tool**********\n";
        cout << "Do you want to cipher or decipher a message\n";
        cout << "1- cipher\n";
        cout << "2- decipher\n";
        cout << "3- Return\n";
        cin >> choice;   // Read user's choice

        // Validate user's choice
        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Invalid choice, please enter 1 to cipher or 2 to decipher\n";
            cin >> choice;   // Prompt user to enter a valid choice
        }
        if (choice == 3)break;
        if (choice == 1) {
            cout << "Please enter a text to cipher:\n";
            cin >> ws;
            getline(cin, text);

            int key;
            // Prompt user to enter a valid key
            do {
                cout << "Please enter a key: ";
                cin >> key;
            } while (key <= 1);

            // Remove spaces and special characters, then perform encryption
            string temp = removeSpacesAndSpecialChars(text);
            string ciphered_message = railFence_cipher(temp, key);
            cout << "The ciphertext: " << ciphered_message << endl;
        }
        else {
            cout << "please enter a ciphered message to decipher:\n";
            cin >> text;

            int key;
            // Prompt user to enter a valid key
            do {
                cout << "Please enter a key: ";
                cin >> key;
            } while (key <= 1);

            // Perform decryption
            string deciphered_message = railFence_decipher(text, key);
            cout << "The deciphertext: " << deciphered_message << endl;
        }
    }
}
