#include <iostream>
using namespace std;

string ReadName()
{
    string Name ;

    cout << "Enter Your Name?\n" ;
    getline(cin , Name) ;
    return Name ;
}


string Encryption(string Name , short EncryptionKey)
{
    for (int i=0 ; i< Name.length() ; i++)
    {
        Name[i] = char (Name[i] + EncryptionKey) ;
    }

    return Name ;
}


string Decryption(string Name , short EncryptionKey)
{
    for (int i=0 ; i< Name.length() ; i++)
    {
        Name[i] = char (Name[i] - EncryptionKey) ;
    }

    return Name ;
}


int main() 
{
    const short EncryptionKey = 2 ;

    string Name = ReadName() ;
    string EncryptionName = Encryption(Name , EncryptionKey) ;
    string DecryptionName = Decryption(EncryptionName , EncryptionKey) ;

    cout << "\nName Before Encryption : " << Name << endl ;
    cout << "Name After Encryption : " << EncryptionName << endl ;
    cout << "Name After Decryption : " << DecryptionName << endl ;

    return 0;
}
