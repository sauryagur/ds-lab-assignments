#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//part a
void concatenateStrings() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin.ignore();
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);
    strcat(str1, str2);
    cout << "Concatenated string: " << str1 << endl;
}

//part b
void reverseString() {
    char str[100];
    cout << "Enter string: ";
    cin.ignore();
    cin.getline(str, 100);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}

//part c
void deleteVowels() {
    char str[100], result[100];
    cout << "Enter string: ";
    cin.ignore();
    cin.getline(str, 100);
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';
    cout << "String without vowels: " << result << endl;
}

//part d
void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    char arr[20][100];
    for (int i = 0; i < n; i++) cin.getline(arr[i], 100);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
}

//part e
void uppercaseToLowercase() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    if (isupper(ch)) ch = tolower(ch);
    cout << "Converted character: " << ch << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n——MENU——-\n1.Concatenate Strings\n2.Reverse String\n3.Delete Vowels\n4.Sort Strings\n5.Uppercase to Lowercase\n6.Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) concatenateStrings();
        else if (choice == 2) reverseString();
        else if (choice == 3) deleteVowels();
        else if (choice == 4) sortStrings();
        else if (choice == 5) uppercaseToLowercase();
        else if (choice == 6) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}

