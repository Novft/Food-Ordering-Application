#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>

using namespace std;

void registerCustomerModule();
void foodServiceModule();
void topupModule();
void paymentModule();
void pointsModule();

//Global Variable
string membershipList[100], name[100], contactNum[100];
double topUp[100], points[100];
int position = 0, chosen_position;
string dataFile = "Membership Details.txt";

//Main Function
int main()
{
    string option;
    bool stop = false;
    bool stop2 = false;

    cout << setw(45) << setfill('-') << "\n";
    cout << "Welcome to Fast Food Ordering Application" << endl;
    cout << setw(45) << setfill('-') << "\n";

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
                cout << "\n" << setw(75) << setfill('-') << "\n";
                cout << "Thank you for using our Fast Food Ordering Application. Have a nice day." << endl;
                cout << setw(75) << setfill('-') << "\n";
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
    while (getline(inFile, name[position])) // Retrieve each data into array form
    {
        inFile >> membershipList[position] >> contactNum[position] >> topUp[position] >> points[position];
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
        if (membershipList[i] == new_membershipNum)
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
    membershipList[position] = new_membershipNum;

    //Displaying register title
    cout << "\n";
    cout << setw(35) << setfill('*') << "\n";
    cout << " Customer Membership Registration " << endl;
    cout << setw(35) << setfill('*') << "\n";

    //Customer Name Validation
    bool contactNumValidation = false, customerNameValidation = false;
    cout << "Customer Name: ";
    getline(cin, name[position]);
    while (customerNameValidation == false)
    {
        if (name[position].empty()) //Check if the name input is empty
        {
            cout << "Invalid Customer Name!!! Enter your name again: ";
            getline(cin, name[position]);
            customerNameValidation = false;
        }

        for (int i = 0; i < name[position].length(); i++)
        {
            if (isspace(name[position].at(0)) || isdigit(name[position].at(i)) || !isalpha(name[position].at(i)) && !isspace(name[position].at(i))) //Check if the name input have space at the beginning, contain any special character or digits
            {
                cout << "Invalid Customer Name!!! Enter your name again: ";
                getline(cin, name[position]);
                customerNameValidation = false;
                break;
            }
            else customerNameValidation = true;
        }
    }

    //Contact Number Validation
    cout << "Contact Number (Excluding -): ";
    getline(cin, contactNum[position]);
    while (contactNumValidation == false)
    {
        if (contactNum[position].empty()) //Check if the contact number input is empty
        {
            cout << "Invalid contact number!!! Enter your contact number again: ";
            getline(cin, contactNum[position]);
            contactNumValidation = false;
        }

        for (int i = 0; i < contactNum[position].length(); i++)
        {
            if (isspace(contactNum[position].at(i)) || !isdigit(contactNum[position].at(i))) //Check if the contact number contain any space, special character or alphabet
            {
                cout << "Invalid contact number!!! Enter your contact number again: ";
                getline(cin, contactNum[position]);
                contactNumValidation = false;
                break;
            }
            else contactNumValidation = true;
        }
    }

    //Set the membership points and top up value to 0
    topUp[position] = 0.00;
    points[position] = 0.00;

    cout << "Your membership card number is: " << membershipList[position] << endl;
    cout << "Your membership point is: " << points[position] << endl << endl;

    outFile.open(dataFile);

    for (int i = 0; i < position + 1; i++) // Write all the data back to the file
    {
        outFile << name[i] << "\n" << membershipList[i] << " " << contactNum[i] << " " << topUp[i] << " " << points[i] << endl;
    }

    outFile.close();

    inFile.open(dataFile);

    position = 0;
    while (getline(inFile, name[position])) // Retrieve each data into array form again because new customer registered
    {
        inFile >> membershipList[position] >> contactNum[position] >> topUp[position] >> points[position];
        inFile.get();
        position++;
    }

    inFile.close();
}

//Food Service and Selection Module Function
void foodServiceModule()
{
    //User Input Data
    int foodChoice, quantity;
    char waysToDine, foodType, orderAgain;
    //Menu Data
    string foods[6] = { "Burger" , "Fried Chicken" , "Nasi Lemak" , "Nuggets" , "Fries" , "Coke" };
    float foodPrice[6] = { 8.00     , 6.00            , 10.00        , 6.00      , 3.00    , 2.00 };
    //Order Data
    int orderCount = 0, orderedQuantity[10];
    char orderedFoodType[10];
    string foodsOrdered[10];
    float foodOrderedPrice[10];
    //Service Charge Data
    float charges;

    //customer choosing to dine in or take away
    cout << "Do you want to dine-in or take-away?" << endl;
    cout << "Type : [D] Dine-In ;" << endl;
    cout << "       [T] Take-Away" << endl;
    cin >> waysToDine;
    //validation of input
    bool dineValidation = false;
    while (dineValidation == false)
    {
        if (waysToDine == 'D' || waysToDine == 'd')//update dine-in charges
        {
            charges = 0.1;
            dineValidation = true;
        }
        else if (waysToDine == 'T' || waysToDine == 't')//update take-away charges
        {
            charges = 2;
            dineValidation = true;
        }
        else//Invalid input! User try again.
        {
            cout << "Invalid input! Please choose again." << endl;
            cout << "Type : [D] Dine-In ;" << endl;
            cout << "       [T] Take-Away" << endl;
            cin >> waysToDine;
        }
    }
    //Ordering Selection Function
    //1st : Get User Input
    //2nd : Store Data in Arrays
    //3rd : Display Order Details
    //4th : Ask to order again or stop ordering
    for (int i = 0; i < 10; i++)//Will keep looping the Ordering Function //Until "Max Order = 10" reached or user stop ordering
    {
        do//1.0 : Display menu and food selection
        {
            int choiceCount = 0;
            //Menu Display
            cout << "What would you like to order?" << endl;
            cout << "Food              || Price" << endl;
            cout << "==================||================" << endl;
            for (int i = 0; i < 6; i++)// loop print all the menu's foods and price with format
            {
                cout << left << setw(18) << setfill(' ') << foods[i]
                    << "|| RM" << fixed << setprecision(2) << right << setw(8) << setfill(' ') << foodPrice[i]
                    << "  [" << i + 1 << "]" << endl;
            }
            //let user choose the order based on numbers given
            cout << "*Press the number inside [ ] to select your order" << endl;
            cin >> foodChoice;
            if (foodChoice > 6 || foodChoice <= 0)//validation for available option
            {
                cout << "Option does not exist. Please try again." << endl;
                choiceCount++;
            }
        } while (foodChoice > 6 || foodChoice <= 0);// will keep looping until user key in the available number of foodChoice 

        //1.1 : Get user to want set or ala-carte
        cout << "Do you want Set or Ala-carte?" << endl;
        cout << "Type : [S] for Set ;" << endl;
        cout << "       [A] for Ala-carte ;" << endl;
        cout << "       [B] for Both " << endl;
        cin >> foodType;
        //validation
        bool foodTypeValidation = false;
        while (foodTypeValidation == false)
        {
            if (foodType == 'S' || foodType == 's' || foodType == 'A' || foodType == 'a' || foodType == 'B' || foodType == 'b')
            {
                if (foodType == 's')//change from small to large capital
                {
                    foodType = 'S';
                }
                else if (foodType == 'a')//change from small to large capital
                {
                    foodType = 'A';
                }
                else if (foodType == 'b')//change from small to large capital
                {
                    foodType = 'B';
                }
                foodTypeValidation = true; //break validation loop
            }
            else //call out again to ask user to input again
            {
                cout << "Invalid input! Please choose again." << endl;
                cout << "Type : [S] for Set ;" << endl;
                cout << "       [A] for Ala-carte ;" << endl;
                cout << "       [B] for Both " << endl;
                cin >> foodType;
            }
        }

        //1.2 : Get user quantity of food selected 
        cout << "How much Quantity : ";
        cin >> quantity;
        //validation
        bool quantityValidation = false;
        while (quantityValidation == false)
        {
            if (quantity > 10) //can only have Max 10 quantity
            {
                cout << "Max quantity has reached!! Please type in a new quantity : ";
                cin >> quantity;
            }
            else if (quantity <= 0) //quantity must be greater than 0
            {
                cout << "Please type in quantity greater than 0 : ";
                cin >> quantity;
            }
            else //break validation loop
            {
                quantityValidation = true;
            }
        }

        //2 : Store the data user inputed into an array based on current order count
        foodsOrdered[orderCount] = foods[foodChoice - 1];
        orderedFoodType[orderCount] = foodType;
        orderedQuantity[orderCount] = quantity;
        //calculation of single order food price *calculation included "multipled by quantity"
        if (foodType == 'S' || foodType == 's')//if set will also add on the price of fries and coke
        {
            foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1] + foodPrice[4] + foodPrice[5]) * quantity;
        }
        else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
        {
            foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1] * 2 + foodPrice[4] + foodPrice[5]) * quantity;
        }
        else//just add on the ala-carte price
        {
            foodOrderedPrice[orderCount] = foodPrice[foodChoice - 1] * quantity;
        }

        //3 : Display the data user inputed
        cout << endl;
        cout << "Your current order:                                            " << endl;
        cout << "Food               Type        Quantity        Price           " << endl;
        cout << "===============================================================" << endl;
        for (int j = 0; j < orderCount + 1; j++)//condition needs to + 1 else first order won't display 
        {   //Array value display with the same initialization value [j] 
            //      else if used [orderCount] value it will only print the same exact recent order 2 times
            cout << left << setw(18) << setfill(' ') << foodsOrdered[j] <<
                left << setw(18) << setfill(' ') << orderedFoodType[j] <<
                left << setw(18) << setfill(' ') << orderedQuantity[j] <<
                left << setw(18) << setfill(' ') << foodOrderedPrice[j] << endl;
        }
        cout << "===============================================================" << endl;

        //4 : Ask user if they want to continue to order
        cout << "Order Again?" << endl;
        cout << "*Press Any Button for Yes; [N] for No" << endl;
        cin >> orderAgain;
        if (orderAgain == 'N' || orderAgain == 'n')//Will stop when user key in "N" or "n"
        {
            break;
        }
        else //A new order count is added and loopback Ordering Function
        {
            orderCount++;
        }
    }
}

//Membership Card top up Module Function
void topupModule()
{
    const double topupCharge = 0.50;
    double total = 0.00;
    double topupAmount;
    string topupChoice;
    string choice;
    string membershipValidation;
    bool isValid = false;
    bool stop = false;
    bool stop2 = false;

    ifstream inFile;
    ofstream outFile;

    inFile.open(dataFile);

    position = 0; //Reset the position to 0
    while (getline(inFile, name[position])) // Retrieve each data into array form
    {
        inFile >> membershipList[position] >> contactNum[position] >> topUp[position] >> points[position];
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
            if (membershipValidation == membershipList[i]) //Check if the membership number entered is valid
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
            topUp[chosen_position] += total;
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

    for (int i = 0; i < position; i++) // Write all the data back to the file
    {
        outFile << name[i] << "\n" << membershipList[i] << " " << contactNum[i] << " " << topUp[i] << " " << points[i] << endl;
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
            cout << showpoint << fixed << setprecision(2) << "Your balance is RM" << topUp[chosen_position] << endl;
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
    //Inser Payment Module here
}

//Membership Points Module Function
void pointsModule()
{
    //Insert Membership Points Module here
}
