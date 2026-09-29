#include <iostream>
#include <string>
using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int decimalValue)
{
    if (decimalValue == 0)
        return "0";

    string binary = "";
    int value = decimalValue;

    while (value > 0)
    {
        int remainder = value % 2;
        binary = to_string(remainder) + binary;
        value = value / 2;
    }

    return binary;
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binaryValue)
{
    int decimal = 0;
    int power = 0;

    for (int i = binaryValue.length() - 1; i >= 0; i--)
    {
        if (binaryValue[i] == '1')
        {
            int placeValue = 1;
            for (int p = 0; p < power; p++)
                placeValue *= 2;

            decimal += placeValue;
        }
        power++;
    }

    return decimal;
}

// Function 3: Decimal to Hexadecimal (NEW)
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

int main()
{
    int decimalNum;
    cout << "Enter a decimal number: ";
    cin >> decimalNum;
    cout << "Binary representation: " << decimalToBinary(decimalNum) << endl;
    cout << "Hexadecimal representation: " << decimalToHexadecimal(decimalNum) << endl;

    string binaryNum;
    cout << "Enter a binary number: ";
    cin >> binaryNum;
    cout << "Decimal representation: " << binaryToDecimal(binaryNum) << endl;

    return 0;
}
