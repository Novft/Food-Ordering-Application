#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
    int contactNumber , membershipPoint;
    string  membershipCardNumber, customerName;
    float topUpValue;
    //ask user name and contact number
    // bool customerNameValidation;
    // if (customerName.length() > 30)
    // {
    //     /* code */
    // }
    // cout << "Your Name : ";
    // getline(cin , customerName);
    // cout << "Your Contact Number : ";
    // cin >> contactNumber;
    // generate 6 digits
    srand(time(NULL));
    int digit1 = (rand() % 10) ;
    int digit2 = (rand() % 10) ;
    int digit3 = (rand() % 10) ;
    int digit4 = (rand() % 10) ;
    int digit5 = (rand() % 10) ;
    int digit6 = (rand() % 10) ;
    // srand(time(NULL)); //testing for digit validation//
    // int digit1 = 0 ;
    // int digit2 = 0 ;
    // int digit3 = 0 ;
    // int digit4 = 0 ;
    // int digit5 = 0 ;
    // int digit6 = 1 ;
    //preventing number to become 000000 (6 digits all 0)
    while (digit1 == 0 && digit2 == 0 && digit3 == 0 && digit4 == 0 && digit5 == 0 && digit6 == 0)
    {
        srand(time(NULL));
        digit1 = (rand() % 10) ;
        digit2 = (rand() % 10) ;
        digit3 = (rand() % 10) ;
        digit4 = (rand() % 10) ;
        digit5 = (rand() % 10) ;
        digit6 = (rand() % 10) ;
    }
    
    //use the numbers generated to combine with character string (ie.: "ABC") Membership Card Number
    int memValue = digit1*100000 + digit2*10000 + digit3*1000 + digit4*100 + digit5*10 + digit6;
    string memValueToString = to_string(memValue);
    while (memValueToString.length() < 6) //place "0" in front if digit less than 6 (if only 4 digits then instead add another "0" etc.)
    {                                     //if 12345 -> 012345 || if 1234 -> 001234 || etc.
        int memValueCount;
        memValueToString.insert(0,"0");
        memValueCount++;
    }
    membershipCardNumber = "ABC";
    membershipCardNumber.append(memValueToString); //attach 2 strings together
    cout << "Your new Membership Account Number is : " << membershipCardNumber << endl;
    
    //initialize membershipPoint and topUpValue value
    membershipPoint = 0;
    topUpValue = 0;
    
    //store value in file

    return 0;
}