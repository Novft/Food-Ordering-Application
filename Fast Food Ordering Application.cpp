#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"
#define CYAN "\x1B[36m"

using namespace std;

void registerCustomerModule();
void foodServiceModule();
void topupModule();
void paymentModule();
bool pointsModule(double, string);

//Global Variable
struct membershipDetails //Membership Details Structure
{
    string membershipList[100], name[100], contactNum[100];
    double topUp[100];
    int points[100];
};
membershipDetails member;
int position = 0, chosen_position;
string dataFile = "Membership Details.txt"; //Name of the file
string info = "//Membership Name\n//Membership Number, Contact Number, Top Up, Points\n"; //Information inside the file
string clearInfo;

//Main Function
int main()
{
    bool stop = false, stop2 = false;
    string option;

    cout << YELLOW "\n############################################################################################################################################################################"
        << "\n# ___       __    _______    ___        ________   ________   _____ ______    _______           _________   ________                                                       #"
        << "\n#|\\  \\     |\\  \\ |\\  ___ \\  |\\  \\      |\\   ____\\ |\\   __  \\ |\\   _ \\  _   \\ |\\  ___ \\         |\\___   ___\\|\\   __  \\                                                      #"
        << "\n#\\ \\  \\    \\ \\  \\\\ \\   __/| \\ \\  \\     \\ \\  \\___| \\ \\  \\|\\  \\\\ \\  \\\\\\__\\ \\  \\\\ \\   __/|        \\|___ \\  \\_|\\ \\  \\|\\  \\                                                     #"
        << "\n# \\ \\  \\  __\\ \\  \\\\ \\  \\_|/__\\ \\  \\     \\ \\  \\     \\ \\  \\\\\\  \\\\ \\  \\\\|__| \\  \\\\ \\  \\_|/__           \\ \\  \\  \\ \\  \\\\\\  \\                                                    #"
        << "\n#  \\ \\  \\|\\__\\_\\  \\\\ \\  \\_|\\ \\\\ \\  \\____ \\ \\  \\____ \\ \\  \\\\\\  \\\\ \\  \\    \\ \\  \\\\ \\  \\_|\\ \\           \\ \\  \\  \\ \\  \\\\\\  \\                                                   #"
        << "\n#   \\ \\____________\\\\ \\_______\\\\ \\_______\\\\ \\_______\\\\ \\_______\\\\ \\__\\    \\ \\__\\\\ \\_______\\           \\ \\__\\  \\ \\_______\\                                                  #"
        << "\n#    \\|____________| \\|_______| \\|_______| \\|_______| \\|_______| \\|__|     \\|__| \\|_______|            \\|__|   \\|_______|                                                  #"
        << "\n# ________    _______    ___        ________   ________   ________           ________  ________   ________   _________        ________  ________   ________   ________     #"
        << "\n#|\\   ___  \\ |\\  ___ \\  |\\  \\      |\\   __  \\ |\\   __  \\ |\\   ___  \\        |\\  _____\\|\\   __  \\ |\\   ____\\ |\\___   ___\\     |\\  _____\\|\\   __  \\ |\\   __  \\ |\\   ___ \\    #"
        << "\n#\\ \\  \\\\ \\  \\\\ \\   __/| \\ \\  \\     \\ \\  \\|\\  \\\\ \\  \\|\\  \\\\ \\  \\\\ \\  \\       \\ \\  \\__/ \\ \\  \\|\\  \\\\ \\  \\___|_\\|___ \\  \\_|     \\ \\  \\__/ \\ \\  \\|\\  \\\\ \\  \\|\\  \\\\ \\  \\_|\\ \\   #"
        << "\n# \\ \\  \\\\ \\  \\\\ \\  \\_|/__\\ \\  \\     \\ \\  \\\\\\  \\\\ \\  \\\\\\  \\\\ \\  \\\\ \\  \\       \\ \\   __\\ \\ \\   __  \\\\ \\_____  \\    \\ \\  \\       \\ \\   __\\ \\ \\  \\\\\\  \\\\ \\  \\\\\\  \\\\ \\  \\ \\\\ \\  #"
        << "\n#  \\ \\  \\\\ \\  \\\\ \\  \\_|\\ \\\\ \\  \\____ \\ \\  \\\\\\  \\\\ \\  \\\\\\  \\\\ \\  \\\\ \\  \\       \\ \\  \\_|  \\ \\  \\ \\  \\\\|____|\\  \\    \\ \\  \\       \\ \\  \\_|  \\ \\  \\\\\\  \\\\ \\  \\\\\\  \\\\ \\  \\_\\\\ \\ #"
        << "\n#   \\ \\__\\\\ \\__\\\\ \\_______\\\\ \\_______\\\\ \\_______\\\\ \\_______\\\\ \\__\\\\ \\__\\       \\ \\__\\    \\ \\__\\ \\__\\ ____\\_\\  \\    \\ \\__\\       \\ \\__\\    \\ \\_______\\\\ \\_______\\\\ \\_______\\#"
        << "\n#    \\|__| \\|__| \\|_______| \\|_______| \\|_______| \\|_______| \\|__| \\|__|        \\|__|     \\|__|\\|__||\\_________\\    \\|__|        \\|__|     \\|_______| \\|_______| \\|_______|#"
        << "\n#                                                                                                   \\|_________|                                                           #"
        << "\n############################################################################################################################################################################" << RESET << endl;

    while (stop2 == false)
    {
        cout << "\nChoose your option (1-4)" << endl;
        cout << "1. Register Customer" << endl;
        cout << "2. Food Selection and Service" << endl;
        cout << "3. Membership Card Top Up" << endl;
        cout << "4. Exit" << endl;
        cout << "--> ";
        getline(cin, option);
        stop = false;

        while (stop == false)
        {
            if (option == "1") //Check if the choice input is 1
            {
                registerCustomerModule();
                stop = true;
                stop2 = false;
            }
            else if (option == "2") //Check if the choice input is 2
            {
                foodServiceModule();
                stop = true;
                stop2 = false;
            }
            else if (option == "3") //Check if the choice input is 3
            {
                topupModule();
                stop = true;
                stop2 = false;
            }
            else if (option == "4") //Check if the choice input is 4
            {
                stop = true;
                stop2 = true;
                cout << CYAN << "\n/====================================================================================\\"
                    << "\n|| _____  _                    _                             __                     ||"
                    << "\n|||_   _|| |__    __ _  _ __  | | __  _   _   ___   _   _   / _|  ___   _ __        ||"
                    << "\n||  | |  | '_ \\  / _` || '_ \\ | |/ / | | | | / _ \\ | | | | | |_  / _ \\ | '__|       ||"
                    << "\n||  | |  | | | || (_| || | | ||   <  | |_| || (_) || |_| | |  _|| (_) || |          ||"
                    << "\n||  |_|  |_| |_| \\__,_||_| |_||_|\\_\\  \\__, | \\___/  \\__,_| |_|   \\___/ |_|          ||"
                    << "\n||             _                      |___/            __              _            ||"
                    << "\n|| _   _  ___ (_) _ __    __ _    ___   _   _  _ __   / _|  __ _  ___ | |_          ||"
                    << "\n||| | | |/ __|| || '_ \\  / _` |  / _ \\ | | | || '__| | |_  / _` |/ __|| __|         ||"
                    << "\n||| |_| |\\__ \\| || | | || (_| | | (_) || |_| || |    |  _|| (_| |\\__ \\| |_          ||"
                    << "\n|| \\__,_||___/|_||_| |_| \\__, |  \\___/  \\__,_||_|    |_|   \\__,_||___/ \\__|         ||"
                    << "\n||                       |___/                                                      ||"
                    << "\n||  __                    _                   _              _                      ||"
                    << "\n|| / _|  ___    ___    __| |   ___   _ __  __| |  ___  _ __ (_) _ __    __ _        ||"
                    << "\n||| |_  / _ \\  / _ \\  / _` |  / _ \\ | '__|/ _` | / _ \\| '__|| || '_ \\  / _` |       ||"
                    << "\n|||  _|| (_) || (_) || (_| | | (_) || |  | (_| ||  __/| |   | || | | || (_| |       ||"
                    << "\n|||_|   \\___/  \\___/  \\__,_|  \\___/ |_|   \\__,_| \\___||_|   |_||_| |_| \\__, |       ||"
                    << "\n||                      _  _              _    _                       |___/        ||"
                    << "\n||  __ _  _ __   _ __  | |(_)  ___  __ _ | |_ (_)  ___   _ __                       ||"
                    << "\n|| / _` || '_ \\ | '_ \\ | || | / __|/ _` || __|| | / _ \\ | '_ \\                      ||"
                    << "\n||| (_| || |_) || |_) || || || (__| (_| || |_ | || (_) || | | |                     ||"
                    << "\n|| \\__,_|| .__/ | .__/ |_||_| \\___|\\__,_| \\__||_| \\___/ |_| |_|                     ||"
                    << "\n|| _   _ |_|    |_|                          _                  _                   ||"
                    << "\n||| | | |  __ _ __   __ ___    __ _   _ __  (_)  ___  ___    __| |  __ _  _   _     ||"
                    << "\n||| |_| | / _` |\\ \\ / // _ \\  / _` | | '_ \\ | | / __|/ _ \\  / _` | / _` || | | |    ||"
                    << "\n|||  _  || (_| | \\ V /|  __/ | (_| | | | | || || (__|  __/ | (_| || (_| || |_| |  _ ||"
                    << "\n|||_| |_| \\__,_|  \\_/  \\___|  \\__,_| |_| |_||_| \\___|\\___|  \\__,_| \\__,_| \\__, | (_)||"
                    << "\n||                                                                        |___/     ||"
                    << "\n\\====================================================================================/" << RESET << endl;
            }
            else if (option != "1" || option != "2" || option != "3" || option != "4" || option.empty()) //Check if the choice input is empty or contain other out of bound digit
            {
                cout << "\nInvalid input !!! Choose your option (1-4)" << endl;
                cout << "1. Register Customer" << endl;
                cout << "2. Food Selection and Service" << endl;
                cout << "3. Membership Card Top Up" << endl;
                cout << "4. Exit" << endl;
                cout << "--> ";
                getline(cin, option);
                stop = false;
            }
        }
    }
}

//Register Customer Module Function
void registerCustomerModule()
{
    string new_membershipNum = "ABC";
    string digit[6];

    ifstream inFile;
    ofstream outFile;

    srand(time(0));

    inFile.open(dataFile);
    position = 0;
    getline(inFile, clearInfo);
    getline(inFile, clearInfo);
    while (getline(inFile, member.name[position])) // Retrieve each data into array form
    {
        inFile >> member.membershipList[position] >> member.contactNum[position] >> member.topUp[position] >> member.points[position];
        inFile.get();
        position++;
    }

    inFile.close();

    //Generate random membership number
    for (int i = 0; i < 6; i++)
    {
        digit[i] = (rand() % 10 + 0) + 48;
        new_membershipNum += digit[i];
    }

    inFile.open(dataFile);

    //Check if the generated membership number is the same as previous membership number
    for (int i = 0; i < position; i++)
    {
        if (member.membershipList[i] == new_membershipNum)
        {
            new_membershipNum = "ABC";
            for (int i = 0; i < 6; i++) //Generate another random membership number
            {
                digit[i] = (rand() % 10 + 0) + 48;
                new_membershipNum += digit[i];
            }
            i = 0; //Loop it again to check if the randomly generated number is the same as previous membership number
        }
    }

    inFile.close();

    //Assign new membership number into membership number list
    member.membershipList[position] = new_membershipNum;

    //Displaying register title
    cout << "\n";
    cout << setw(35) << setfill('*') << "\n";
    cout << " Customer Membership Registration " << endl;
    cout << setw(35) << setfill('*') << "\n";

    //Customer Name Validation
    bool contactNumValidation = false, customerNameValidation = false;
    cout << "Customer Name: ";
    getline(cin, member.name[position]);
    while (customerNameValidation == false)
    {
        if (member.name[position].empty()) //Check if the name input is empty
        {
            cout << "Invalid Customer Name!!! Enter your name again: ";
            getline(cin, member.name[position]);
            customerNameValidation = false;
        }

        for (int i = 0; i < member.name[position].length(); i++)
        {
            if (isspace(member.name[position].at(0)) || isdigit(member.name[position].at(i)) || !isalpha(member.name[position].at(i)) && !isspace(member.name[position].at(i))) //Check if the name input have space at the beginning, contain any special character or digits
            {
                cout << "Invalid Customer Name!!! Enter your name again: ";
                getline(cin, member.name[position]);
                customerNameValidation = false;
                break;
            }
            else customerNameValidation = true;
        }
    }

    //Contact Number Validation
    cout << "Contact Number (Excluding -): ";
    getline(cin, member.contactNum[position]);
    while (contactNumValidation == false)
    {
        if (member.contactNum[position].empty()) //Check if the contact number input is empty
        {
            cout << "Invalid contact number!!! Enter your contact number again: ";
            getline(cin, member.contactNum[position]);
            contactNumValidation = false;
        }

        for (int i = 0; i < member.contactNum[position].length(); i++)
        {
            if (isspace(member.contactNum[position].at(i)) || !isdigit(member.contactNum[position].at(i))) //Check if the contact number contain any space, special character or alphabet
            {
                cout << "Invalid contact number!!! Enter your contact number again: ";
                getline(cin, member.contactNum[position]);
                contactNumValidation = false;
                break;
            }
            else contactNumValidation = true;
        }
    }

    //Set the membership points and top up value to 0
    member.topUp[position] = 0.00;
    member.points[position] = 0.00;

    cout << "Your membership card number is: " << member.membershipList[position] << endl;
    cout << "Your membership topup is: " << member.topUp[position] << endl;
    cout << "Your membership point is: " << member.points[position] << endl << endl;

    outFile.open(dataFile);
    outFile << info;
    for (int i = 0; i < position + 1; i++) // Write all the data back to the file
    {
        outFile << member.name[i] << "\n" << member.membershipList[i] << " " << member.contactNum[i] << " " << member.topUp[i] << " " << member.points[i] << endl;
    }

    outFile.close();

    inFile.open(dataFile);

    position = 0;
    getline(inFile, clearInfo);
    getline(inFile, clearInfo);
    while (getline(inFile, member.name[position])) // Retrieve each data into array form again because new customer registered
    {
        inFile >> member.membershipList[position] >> member.contactNum[position] >> member.topUp[position] >> member.points[position];
        inFile.get();
        position++;
    }

    inFile.close();
}

//Food Service and Selection Module Function
void foodServiceModule()
{
    //Insert here
}

//Membership Card top up Module Function
void topupModule()
{
    const double topupCharge = 0.50;
    double total = 0.00, topupAmount;
    string topupChoice, choice, membershipValidation;
    bool isValid = false, stop = false, stop2 = false;

    ifstream inFile;
    ofstream outFile;

    inFile.open(dataFile);

    position = 0; //Reset the position to 0
    getline(inFile, clearInfo);
    getline(inFile, clearInfo);
    while (getline(inFile, member.name[position])) // Retrieve each data into array form
    {
        inFile >> member.membershipList[position] >> member.contactNum[position] >> member.topUp[position] >> member.points[position];
        inFile.get();
        position++;
    }

    inFile.close();

    cout << "\nEnter your membership number to top up your balance: ";
    getline(cin, membershipValidation);

    //Membership Number Validation
    while (isValid == false)
    {
        for (int i = 0; i < position; i++)
        {
            if (membershipValidation == member.membershipList[i]) //Check if the membership number entered is valid
            {
                chosen_position = i;
                isValid = true;
                stop = false;
                break;
            }
        }
        if (isValid == false)
        {
            if (stop == false)
            {
                if (membershipValidation.empty()) //If the membership number input empty, ask the user to register a membership number
                {
                    cout << "Invalid membership number!!! Do you want to register a new membership number (Y/N): ";
                    getline(cin, choice);
                }
                else //If the membership number not correct, ask the user to register a membership number
                {
                    cout << "Invalid membership number!!! Do you want to register a new membership number (Y/N): ";
                    getline(cin, choice);
                }
            }
            if (choice == "Y" || choice == "y") //Check if the choice input is Y or y
            {
                registerCustomerModule(); //Register a new customer

                cout << "\nEnter your membership number to top up your balance: ";
                getline(cin, membershipValidation);
                stop = false;
            }
            else if (choice == "N" || choice == "n") //Check if the choice input is N or n
            {
                cout << "\nEnter your membership number to top up your balance: ";
                getline(cin, membershipValidation);
                stop = false;
            }
            else if (choice != "Y" || choice != "y" || choice != "N" || choice != "n" || choice.empty()) //Check if the choice input is invalid
            {
                cout << "Invalid input!!! Do you want to register a new membership number (Y/N): ";
                getline(cin, choice);
                stop = true;
            }
        }
    }

    stop = false;
    do
    {
        //Top Up
        if (stop2 == false)
        {
            cout << "\nChoose top-up amount (1-4)" << endl;
            cout << "1. RM5" << endl;
            cout << "2. RM10" << endl;
            cout << "3. RM30" << endl;
            cout << "4. RM50" << endl;
            cout << "--> ";
            getline(cin, topupChoice);
            isValid = false;
        }
        while (isValid == false && stop2 == false)
        {
            if (topupChoice == "1") //Check if the choice input is 1
            {
                topupAmount = 5;
                isValid = true;
                stop2 = false;
            }
            else if (topupChoice == "2") //Check if the choice input is 2
            {
                topupAmount = 10;
                isValid = true;
                stop2 = false;
            }
            else if (topupChoice == "3") //Check if the choice input is 3
            {
                topupAmount = 30;
                isValid = true;
                stop2 = false;
            }
            else if (topupChoice == "4") //Check if the choice input is 4
            {
                topupAmount = 50;
                isValid = true;
                stop2 = false;
            }
            else if (topupChoice != "1" || topupChoice != "2" || topupChoice != "3" || topupChoice != "4" || topupChoice.empty()) //Check if the choice input is empty or contain other out of bound digit
            {
                cout << "\nInvalid input !!! Choose top-up amount (1-4)" << endl;
                cout << "1. RM5" << endl;
                cout << "2. RM10" << endl;
                cout << "3. RM30" << endl;
                cout << "4. RM50" << endl;
                cout << "--> ";
                getline(cin, topupChoice);
                isValid = false;
            }
        }

        //Top Up Confirmation
        if (stop2 == false)
        {
            cout << showpoint << fixed << setprecision(2) << "\nAre you sure you want to top up RM" << topupAmount << " (Y/N)" << endl;
            cout << showpoint << fixed << setprecision(2) << "RM" << topupCharge << " will be charged for service charges" << endl;
            cout << "--> ";
            getline(cin, choice);
        }
        if (choice == "Y" || choice == "y") //Check if the choice input is Y or y
        {
            total = topupAmount - topupCharge;
            member.topUp[chosen_position] += total;
            stop = true;
        }
        else if (choice == "N" || choice == "n") //Check if the choice input is N or n
        {
            stop = false;
            stop2 = false;
        }
        else if (choice != "Y" || choice != "y" || choice != "N" || choice != "n" || choice.empty()) //Check if the choice input is invalid
        {
            cout << showpoint << fixed << setprecision(2) << "\nInvalid Input !!! Are you sure you want to top up RM" << topupAmount << " (Y/N)" << endl;
            cout << showpoint << fixed << setprecision(2) << "RM" << topupCharge << " will be charged for service charges" << endl;
            cout << "--> ";
            getline(cin, choice);
            stop2 = true;
        }
    } while (stop == false);

    //Checking Balance
    outFile.open(dataFile);

    outFile << info;
    for (int i = 0; i < position; i++) // Write all the data back to the file
    {
        outFile << member.name[i] << "\n" << member.membershipList[i] << " " << member.contactNum[i] << " " << member.topUp[i] << " " << member.points[i] << endl;
    }

    outFile.close();

    cout << "Do you want to check your balance? (Y/N)" << endl;
    cout << "--> ";
    getline(cin, choice);
    stop = false;
    while (stop == false)
    {
        if (choice == "Y" || choice == "y") //Check if the choice input is Y or y
        {
            cout << "\n" << setw(25) << setfill('-') << "\n";
            cout << showpoint << fixed << setprecision(2) << "Your balance is RM" << member.topUp[chosen_position] << endl;
            cout << setw(25) << setfill('-') << "\n";
            stop = true;
        }
        else if (choice == "N" || choice == "n") //Check if the choice input is N or n
        {
            stop = true;
        }
        else if (choice != "Y" || choice != "y" || choice != "N" || choice != "n" || choice.empty()) //Check if the choice input is invalid
        {
            cout << "Invalid input!!! Do you want to check your balance? (Y/N)" << endl;
            cout << "--> ";
            getline(cin, choice);
            stop = false;
        }
    }
}

//Payment Module Function
void paymentModule()
{
    double payment = 5; //Payment Testing
    bool stop = false, isValid = false, stop2 = false, stop3 = false, stop4 = false;
    string membershipValidation, choice, paymentMethod;
    ifstream inFile;
    ofstream outFile;

    inFile.open(dataFile);

    position = 0; //Reset the position to 0
    getline(inFile, clearInfo);
    getline(inFile, clearInfo);
    while (getline(inFile, member.name[position])) // Retrieve each data into array form
    {
        inFile >> member.membershipList[position] >> member.contactNum[position] >> member.topUp[position] >> member.points[position];
        inFile.get();
        position++;
    }

    inFile.close();

    cout << "\nEnter your membership number to proceed to payment: ";
    getline(cin, membershipValidation);

    //Membership Number Validation
    while (isValid == false)
    {
        for (int i = 0; i < position; i++)
        {
            if (membershipValidation == member.membershipList[i]) //Check if the membership number entered is valid
            {
                chosen_position = i;
                isValid = true;
                stop = false;
                break;
            }
        }
        if (isValid == false)
        {
            if (stop == false)
            {
                if (membershipValidation.empty()) //If the membership number input empty, ask the user to register a membership number
                {
                    cout << "Invalid membership number!!! Do you want to register a new membership number (Y/N): ";
                    getline(cin, choice);
                }
                else //If the membership number not correct, ask the user to register a membership number
                {
                    cout << "Invalid membership number!!! Do you want to register a new membership number (Y/N): ";
                    getline(cin, choice);
                }
            }
            if (choice == "Y" || choice == "y") //Check if the choice input is Y or y
            {
                registerCustomerModule(); //Register a new customer

                cout << "\nEnter your membership number to proceed to payment: ";
                getline(cin, membershipValidation);
                stop = false;
            }
            else if (choice == "N" || choice == "n") //Check if the choice input is N or n
            {
                cout << "\nEnter your membership number to proceed to payment: ";
                getline(cin, membershipValidation);
                stop = false;
            }
            else if (choice != "Y" || choice != "y" || choice != "N" || choice != "n" || choice.empty()) //Check if the choice input is invalid
            {
                cout << "Invalid input!!! Do you want to register a new membership number (Y/N): ";
                getline(cin, choice);
                stop = true;
            }
        }
    }

    while (stop3 == false)
    {
        while (stop4 == false)
        {
            cout << "\nChoose your payment method or cancel the purchase (1-3)";
            cout << "\n1. Top Up";
            cout << "\n2. Membership Points";
            cout << "\n3. Cancel the purchase";
            cout << "\n--> ";
            getline(cin, paymentMethod);
            stop4 = true;
        }
        if (paymentMethod == "1")
        {
            while (stop2 == false)
            {
                if (member.topUp[chosen_position] < payment)
                {
                    cout << "\nInsufficient Top Up Balance !!! Choose your option (1-2)";
                    cout << "\n1. Top Up Balance";
                    cout << "\n2. Cancel the purchase";
                    cout << "\n--> ";
                    getline(cin, choice);
                    stop = false;
                    while (stop == false)
                    {
                        if (choice == "1")
                        {
                            topupModule();
                            break;
                        }
                        else if (choice == "2")
                        {
                            cout << "\nThe order is cancelled" << endl;
                            stop2 = true;
                            break;
                        }
                        else if (choice != "1" || choice != "2" || choice.empty()) //Check if the choice input is invalid
                        {
                            cout << "\nInvalid Input !!! Insufficient Top Up Balance !!! Choose your option (1-2)";
                            cout << "\n1. Top Up Balance";
                            cout << "\n2. Cancel the purchase";
                            cout << "\n--> ";
                            getline(cin, choice);
                        }
                    }
                }
                else if (member.topUp[chosen_position] >= payment)
                {
                    pointsModule(payment, paymentMethod);
                    member.topUp[chosen_position] -= payment;
                    cout << showpoint << fixed << setprecision(2) << "\nPayment received using top up. Your new membership top up is RM" << member.topUp[chosen_position] << ".";
                    cout << "\nYou have earned " << (int)payment << " points. Your new membership points is " << member.points[chosen_position] << " points." << endl;
                    break;
                }
            }
            break;
        }
        else if (paymentMethod == "2")
        {
            stop4 = pointsModule(payment, paymentMethod);
            if (stop4 == true)
            {
                break;
            }
        }
        else if (paymentMethod == "3")
        {
            cout << "\nThe order is cancelled" << endl;
            break;
        }
        else if (paymentMethod != "1" || paymentMethod != "2" || paymentMethod != "3" || paymentMethod.empty())
        {
            cout << "\nInvalid Input !!! Choose your payment method or cancel the purchase (1-3)";
            cout << "\n1. Top Up";
            cout << "\n2. Membership Points";
            cout << "\n3. Cancel the purchase";
            cout << "\n--> ";
            getline(cin, paymentMethod);
            stop4 = true;
        }
    }

    outFile.open(dataFile);

    outFile << info;
    for (int i = 0; i < position; i++) // Write all the data back to the file
    {
        outFile << member.name[i] << "\n" << member.membershipList[i] << " " << member.contactNum[i] << " " << member.topUp[i] << " " << member.points[i] << endl;
    }

    outFile.close();
}

//Membership Points Module Function
bool pointsModule(double payment, string paymentMethod)
{
    ifstream inFile;
    ofstream outFile;

    inFile.open(dataFile);

    position = 0; //Reset the position to 0
    getline(inFile, clearInfo);
    getline(inFile, clearInfo);
    while (getline(inFile, member.name[position])) // Retrieve each data into array form
    {
        inFile >> member.membershipList[position] >> member.contactNum[position] >> member.topUp[position] >> member.points[position];
        inFile.get();
        position++;
    }

    inFile.close();

    if (paymentMethod == "1")
    {
        member.points[chosen_position] += (int)payment;
    }
    else if (paymentMethod == "2")
    {
        if ((double)member.points[chosen_position] / 100 >= payment)
        {
            member.points[chosen_position] -= payment * 100;
            cout << "\nPayment received using membership points. Your new membership points is " << member.points[chosen_position] << "." << endl;
            return true;
        }
        else if ((double)member.points[chosen_position] / 100 < payment)
        {
            cout << "\nInsufficient membership points !!!" << endl;
            return false;
        }
    }

    outFile.open(dataFile);

    outFile << info;
    for (int i = 0; i < position; i++) // Write all the data back to the file
    {
        outFile << member.name[i] << "\n" << member.membershipList[i] << " " << member.contactNum[i] << " " << member.topUp[i] << " " << member.points[i] << endl;
    }

    outFile.close();
}
