#include <iostream>
#include <string>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
using namespace std;

// ----------------------------------------------------------
// Function 1: Decimal to Binary
// Takes an integer and returns its binary equivalent as a string.
// ----------------------------------------------------------
string decimalToBinary(int decimalValue)
{
    if (decimalValue == 0)
        return "0";

    string binary = "";
    int value = decimalValue;

    while (value > 0)
    {
        int remainder = value % 2;
        // Build the string in reverse (least significant bit first)
        binary = to_string(remainder) + binary;
        value = value / 2;
    }

    return binary;
}

// ----------------------------------------------------------
// Function 2: Binary to Decimal
// Takes a string of binary digits and returns the integer equivalent.
// ----------------------------------------------------------
int binaryToDecimal(string binaryValue)
{
    int decimal = 0;
    int power = 0;

    // Read the binary string from right to left
    for (int i = binaryValue.length() - 1; i >= 0; i--)
    {
        if (binaryValue[i] == '1')
        {
            // 2 raised to the power of the bit's position
            int placeValue = 1;
            for (int p = 0; p < power; p++)
                placeValue *= 2;

            decimal += placeValue;
        }
        power++;
    }

    return decimal;
}

// ----------------------------------------------------------
// Function 3: Decimal to Hexadecimal
// Takes an integer and returns its hexadecimal equivalent as a string.
// ----------------------------------------------------------
string decimalToHexadecimal(int decimalValue)
{
    if (decimalValue == 0)
        return "0";

    string hexDigits = "0123456789ABCDEF";
    string hexResult = "";
    int value = decimalValue;

    while (value > 0)
    {
        int remainder = value % 16;
        hexResult = hexDigits[remainder] + hexResult;
        value = value / 16;
    }

    return hexResult;
}

// ----------------------------------------------------------
// Function 4: Hexadecimal to Decimal
// Takes a string of hexadecimal digits and returns the integer equivalent.
// ----------------------------------------------------------
int hexadecimalToDecimal(string hexValue)
{
    string hexDigits = "0123456789ABCDEF";
    int decimal = 0;
    int power = 0;

    for (int i = hexValue.length() - 1; i >= 0; i--)
    {
        char c = toupper(hexValue[i]);
        int digitValue = hexDigits.find(c);

        int placeValue = 1;
        for (int p = 0; p < power; p++)
            placeValue *= 16;

        decimal += digitValue * placeValue;
        power++;
    }

    return decimal;
}

// ----------------------------------------------------------
// Displays the main menu
// ----------------------------------------------------------
void displayMenu()
{
    cout << "Conversion Menu:" << endl;
    cout << "1. Convert Decimal to Binary" << endl;
    cout << "2. Convert Binary to Decimal" << endl;
    cout << "3. Convert Hexadecimal to Decimal" << endl;
    cout << "4. Convert Decimal to Hexadecimal" << endl;
    cout << "5. Demo (Generate and convert random integers to binary)" << endl;
    cout << "6. Exit" << endl;
}

// ----------------------------------------------------------
// Main Program
// ----------------------------------------------------------
int main()
{
    int choice;
    bool running = true;

    // Seed the random number generator once, using the current time
    srand(static_cast<unsigned int>(time(0)));

    while (running)
    {
        displayMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int decimalNum;
                cout << "Enter a decimal number: ";
                cin >> decimalNum;
                cout << "Binary representation: " << decimalToBinary(decimalNum) << endl;
                break;
            }
            case 2:
            {
                string binaryNum;
                cout << "Enter a binary number: ";
                cin >> binaryNum;
                cout << "Decimal representation: " << binaryToDecimal(binaryNum) << endl;
                break;
            }
            case 3:
            {
                string hexNum;
                cout << "Enter a hexadecimal number: ";
                cin >> hexNum;
                cout << "Decimal representation: " << hexadecimalToDecimal(hexNum) << endl;
                break;
            }
            case 4:
            {
                int decimalNum;
                cout << "Enter a decimal number: ";
                cin >> decimalNum;
                cout << "Hexadecimal representation: " << decimalToHexadecimal(decimalNum) << endl;
                break;
            }
            case 5:
            {
                // Demo: generate a random number between 0 and 99, then convert it
                int randomNum = rand() % 100;
                cout << "Generated random integer: " << randomNum << endl;
                cout << "Binary representation: " << decimalToBinary(randomNum) << endl;
                break;
            }
            case 6:
            {
                cout << "Exiting the program." << endl;
                running = false;
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
            }
        }

        cout << endl; // blank line for readability between menu loops
    }

    return 0;
}
