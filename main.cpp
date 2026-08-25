#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimal)
{
    if (decimal == 0)
        return "0";
    
if (decimal < 0)
    return "Invalid: Please enter a positive number";
    
    string binary = "";

    while (decimal > 0)
    {
        int remainder = decimal % 2;
        binary = char('0' + remainder) + binary;
        decimal = decimal / 2;
    }

    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binary)
{
    int decimal = 0;

    for (int i = 0; i < binary.length(); i++)
    {
        decimal = decimal * 2 + (binary[i] - '0');
    }

    return decimal;
}

// Function 3: Decimal to Hexadecimal
string decimalToHexadecimal(int decimal)
{
    if (decimal == 0)
        return "0";

    string hexadecimal = "";
    char hexDigits[] = "0123456789ABCDEF";

    while (decimal > 0)
    {
        int remainder = decimal % 16;
        hexadecimal = hexDigits[remainder] + hexadecimal;
        decimal = decimal / 16;
    }

    return hexadecimal;
}

// Function 4: Hexadecimal to Decimal
int hexadecimalToDecimal(string hexadecimal)
{
    int decimal = 0;

    for (int i = 0; i < hexadecimal.length(); i++)
    {
        char digit = hexadecimal[i];
        int value;

        if (digit >= '0' && digit <= '9')
        {
            value = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            value = digit - 'A' + 10;
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            value = digit - 'a' + 10;
        }
        else
        {
            return -1;
        }

        decimal = decimal * 16 + value;
    }

    return decimal;
}

// Main program
int main()
{
    int choice;
    srand(time(0));

    do
    {
        cout << "\n=============================\n";
        cout << "       CONVERSION MENU\n";
        cout << "=============================\n";
        cout << "1. Convert Decimal to Binary\n";
        cout << "2. Convert Binary to Decimal\n";
        cout << "3. Convert Decimal to Hexadecimal\n";
        cout << "4. Convert Hexadecimal to Decimal\n";
        cout << "5. Demo (Generate random integer and convert to binary)\n";
        cout << "6. Exit\n";
        cout << "=============================\n";

        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int decimal;

                cout << "Enter a decimal number: ";
                cin >> decimal;

                cout << "Binary representation: "
                     << decimalToBinary(decimal) << endl;

                break;
            }

            case 2:
            {
                string binary;

                cout << "Enter a binary number: ";
                cin >> binary;

                cout << "Decimal representation: "
                     << binaryToDecimal(binary) << endl;

                break;
            }

            case 3:
            {
                int decimal;

                cout << "Enter a decimal number: ";
                cin >> decimal;

                cout << "Hexadecimal representation: "
                     << decimalToHexadecimal(decimal) << endl;

                break;
            }

            case 4:
            {
                string hexadecimal;

                cout << "Enter a hexadecimal number: ";
                cin >> hexadecimal;

                int result = hexadecimalToDecimal(hexadecimal);

                if (result == -1)
                {
                    cout << "Invalid hexadecimal number!" << endl;
                }
                else
                {
                    cout << "Decimal representation: "
                         << result << endl;
                }

                break;
            }

            case 5:
            {
                int randomNumber = rand() % 100;

                cout << "Generated random integer: "
                     << randomNumber << endl;

                cout << "Binary representation: "
                     << decimalToBinary(randomNumber) << endl;

                break;
            }

            case 6:
            {
                cout << "Exiting the program." << endl;
                break;
            }

            default:
            {
                cout << "Invalid choice. Please select 1-6." << endl;
            }
        }

    } while (choice != 6);

    return 0;
}
