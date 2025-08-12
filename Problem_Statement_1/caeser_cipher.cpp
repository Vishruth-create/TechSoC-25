#include <iostream>
#include <string>
using namespace std;

void resolving_shift(int &shift, int operation)
{
    while (shift>26) // Incase someone inputs something like 100 it will bring it down to 22
    {
        shift = shift - 26;
    }
    switch (operation) //Decoding is encoding with negative shift
    {
    case 1:
        break;
    case 2:
        shift = (-1)*shift;
        break;
    
    default:
        cout << "Choosing one out of of options shouldn't be that hard, right?";
        throw "Can't choose options";
        break;
    }

}

void print_menu1()
{
    cout << endl << "Welcome to Caeser Cipher Encoder/Decoder!! Press-" << endl << endl;
    cout << "1. To encode\n";
    cout << "2. To Decode\n"; 
    cout << ">"; 
}

void take_input(string &message, int &shift, int &operation)
{

    cin >> operation; //1 or 2
    cin.ignore(1000, '\n'); //Removing \n which is still in input buffer other my getline won't work
    cout << "Enter your message >> ";
    getline(cin, message);
    cout << "Enter shift value=";
    cin >> shift;
    resolving_shift(shift, operation); //Doing some things with shift value

}

string encode(string message, int shift)
{
    int size = message.length();
    for (int i =0; i<size ; i++)
    {
        char c = message[i];
        if (c>=65 && c<=90)
        {
            if((c+shift)>90)
            {
                c = c+shift-26; //Wrapping around
            }
            else if((c+shift)<65)
            {
                c = c+26+shift;
            }
            else
            {
                c = c+shift;
            }
        }

        if (c>=97 && c<=122)
        {
            if((c+shift)>122)
            {
                c = c-26+shift;
            }
            else if((c+shift)<97)
            {
                c = c+26+shift;
            }
            else
            {
                c = c+shift;
            }
        }

        message[i]=c;
    }

    return message;
}

int main()
{
    while (true)
    {
        string message;
        int shift, operation;

        print_menu1(); //Printing menu....Obviously
        take_input(message, shift, operation); //Taking Input
        cout <<endl <<"code: " << encode(message, shift) << endl; //Printing encoded/decoded message
    }

    return 0;
}