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
void paymentModule(char, int, int[], char[], string[], float[]);
bool pointsModule(double, string, double, char, int, int[], char[], string[], float[]);
void printReceipt(char, int, int[], char[], string[], float[], double, double);

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
    cout << "***********************************" << endl;
    cout << " Customer Membership Registration " << endl;
    cout << "***********************************" << endl;

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
    //User Input Data
    int foodChoice, quantity;
    char waysToDine, foodType, orderAgain;
    //Menu Data
    string foods[6] = { "Burger" , "Fried Chicken" , "Nasi Lemak" , "Nuggets" , "Fries" , "Coke" };
    float foodPrice[6] = { 8.00     , 6.00            , 10.00        , 6.00      , 3.00    , 2.00 };
    //Order Data
    int orderCount = 0, orderedQuantity[10], foodChoiceSave[10];
    char orderedFoodType[10];
    string foodsOrdered[10];
    float foodOrderedPrice[10];
    //Service Charge Data
    float charges;

    //customer choosing to dine in or take away
    cout << "\nDo you want to dine-in or take-away?" << endl;
    cout << "[D] Dine-In" << endl;
    cout << "[T] Take-Away" << endl;
    cout << "--> ";
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
            cout << "\nInvalid input! Please choose again." << endl;
            cout << "[D] Dine-In" << endl;
            cout << "[T] Take-Away" << endl;
            cout << "--> ";
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
            cout << "\nWhat would you like to order?" << endl;
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
            cout << "--> ";
            cin >> foodChoice;
            if (foodChoice > 6 || foodChoice <= 0)//validation for available option
            {
                cout << "\nOption does not exist. Please try again." << endl;
                choiceCount++;
            }
        } while (foodChoice > 6 || foodChoice <= 0);// will keep looping until user key in the available number of foodChoice 

        //1.1 : Get user to want set or ala-carte
        cout << "\nDo you want Set or Ala-carte or Both?" << endl;
        cout << "(Set includes fries and coke)" << endl;
        cout << "[S] for Set" << endl;
        cout << "[A] for Ala-carte" << endl;
        cout << "[B] for Both" << endl;
        cout << "--> ";
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
                cout << "\nInvalid input! Please choose again." << endl;
                cout << "(Set includes fries and coke)" << endl;
                cout << "[S] for Set" << endl;
                cout << "[A] for Ala-carte" << endl;
                cout << "[B] for Both" << endl;
                cout << "--> ";
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
            if (quantity >= 10) //can only have Max 10 quantity
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
        foodChoiceSave[orderCount] = foodChoice - 1; //To save for further edit track
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
        //condition if 2 index of foodsOrdered and orderedFoodType are the same
        // if (orderCount != 0)//to make sure the validation can run when there are more than 1 index
        // {
        //     for (int i = 0; i < orderCount + 1; i++)
        //     {
        //         if (foodsOrdered[i] == foodsOrdered[orderCount] && orderedFoodType[i] == orderedFoodType[orderCount])
        //         {
        //             orderedQuantity[i] += orderedQuantity[orderCount]; //Add on quantity to same type of index
        //             foodOrderedPrice[i] += foodOrderedPrice[orderCount]; //Add on ordered price to same type of index
        //         }
        //     }
        //     // orderCount -= 1; //reduce the order index
        // }


        //3 : Display the data user inputed
        cout << endl;
        cout << "Your current order:                                                               " << endl;
        cout << "Order No.         Food              Type              Quantity          Price     " << endl;
        cout << "==================================================================================" << endl;
        for (int j = 0; j < orderCount + 1; j++)//condition needs to + 1 else first order won't display 
        {   //Array value display with the same initialization value [j] 
            //      else if used [orderCount] value it will only print the same exact recent order 2 times
            cout << j + 1 << left << setw(17) << setfill(' ') << "." <<
                left << setw(18) << setfill(' ') << foodsOrdered[j] <<
                left << setw(18) << setfill(' ') << orderedFoodType[j] <<
                left << setw(18) << setfill(' ') << orderedQuantity[j] <<
                "RM " << foodOrderedPrice[j] << endl;
        }
        cout << "==================================================================================" << endl;

        //4 : Ask user if they want to continue to order
        cout << "Order Again?" << endl;
        cout << "*Press Any Button for Yes; [N] for No; [E] for Edit" << endl;
        cout << "--> ";
        cin >> orderAgain;

        if (orderAgain == 'N' || orderAgain == 'n')//Will stop when user key in "N" or "n"
        {
            break;
        }

        else if (orderAgain == 'E' || orderAgain == 'e')//Staff edit mode
        {
            int editChoice, editType, toEditFoodChoice;
            char editContinue;
            bool editStop = false;

            while (editStop == false)
            {
                cout << "\n***Order editing mode***" << endl;
                cout << endl;

                cout << "Your current order:                                                               " << endl;
                cout << "Order No.         Food              Type              Quantity          Price     " << endl;
                cout << "==================================================================================" << endl;
                for (int j = 0; j < orderCount + 1; j++)//condition needs to + 1 else first order won't display 
                {   //Array value display with the same initialization value [j] 
                    //      else if used [orderCount] value it will only print the same exact recent order 2 times
                    cout << j + 1 << left << setw(17) << setfill(' ') << "." <<
                        left << setw(18) << setfill(' ') << foodsOrdered[j] <<
                        left << setw(18) << setfill(' ') << orderedFoodType[j] <<
                        left << setw(18) << setfill(' ') << orderedQuantity[j] <<
                        "RM " << foodOrderedPrice[j] << endl;
                }
                cout << "==================================================================================" << endl;
                //get which selection to edit
                cout << "Please select which (Order No.) you would like to have a change : ";
                cin >> editChoice;
                while (editChoice > orderCount + 1 || editChoice < 1)
                {
                    cout << "Invalid Selection! Select again." << endl;
                    cout << "Please select which (Order No.) you would like to have a change : ";
                    cin >> editChoice;
                }

                //get what type of action
                cout << "What would you like to edit?" << endl;
                cout << "[1] Type   [2] Quantity [3] Remove order entirely " << endl;
                cout << "[Any Button] Cancel Edit" << endl;
                cout << "--> ";
                cin >> editType;

                //EDIT CHOICE ACTIONS
                switch (editType)
                {
                case 1: //Type edit
                    cout << "\nDo you want Set or Ala-carte or Both?" << endl;
                    cout << "(Set includes fries and coke)" << endl;
                    cout << "[S] for Set ;" << endl;
                    cout << "[A] for Ala-carte ;" << endl;
                    cout << "[B] for Both " << endl;
                    cout << "--> ";
                    cin >> foodType;
                    //validation
                    foodTypeValidation = false;
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
                            cout << "\nInvalid input! Please choose again." << endl;
                            cout << "(Set includes fries and coke)" << endl;
                            cout << "[S] for Set ;" << endl;
                            cout << "[A] for Ala-carte ;" << endl;
                            cout << "[B] for Both " << endl;
                            cout << "--> ";
                            cin >> foodType;
                        }
                    }
                    orderedFoodType[editChoice - 1] = foodType;

                    //calculation of single order food price *calculation included "multipled by quantity" (edit ver.)
                    toEditFoodChoice = foodChoiceSave[editChoice - 1]; //take the saved foodChoice number from the saved array
                    if (foodType == 'S' || foodType == 's')//if set will also add on the price of fries and coke
                    {
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice] + foodPrice[4] + foodPrice[5]) * orderedQuantity[editChoice - 1];
                    }
                    else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
                    {
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice] * 2 + foodPrice[4] + foodPrice[5]) * orderedQuantity[editChoice - 1];
                    }
                    else//just add on the ala-carte price
                    {
                        foodOrderedPrice[editChoice - 1] = foodPrice[toEditFoodChoice] * orderedQuantity[editChoice - 1];
                    }
                    break;
                case 2: //quantity edit
                    cout << "How much Quantity : ";
                    cin >> quantity;
                    //validation
                    quantityValidation = false;
                    while (quantityValidation == false)
                    {
                        if (quantity >= 10) //can only have Max 10 quantity
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
                    orderedQuantity[editChoice - 1] = quantity;

                    //calculation of single order food price *calculation included "multipled by quantity" (edit ver.)
                    toEditFoodChoice = foodChoiceSave[editChoice - 1]; //take the saved foodChoice number from the saved array
                    if (foodType == 'S' || foodType == 's')//if set will also add on the price of fries and coke
                    {
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice] + foodPrice[4] + foodPrice[5]) * orderedQuantity[editChoice - 1];
                    }
                    else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
                    {
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice] * 2 + foodPrice[4] + foodPrice[5]) * orderedQuantity[editChoice - 1];
                    }
                    else//just add on the ala-carte price
                    {
                        foodOrderedPrice[editChoice - 1] = foodPrice[toEditFoodChoice] * orderedQuantity[editChoice - 1];
                    }
                    break;
                case 3: //remove selected order no. data
                    if (orderCount < 1)
                    {
                        cout << "\nCannot remove. Only have 1 order" << endl;
                    }
                    else
                    {
                        orderCount -= 1;
                        //update order count in order
                        for (int i = editChoice - 1; i < orderCount + 1; i++)
                        {
                            foodsOrdered[i] = foodsOrdered[i + 1];
                            orderedFoodType[i] = orderedFoodType[i + 1];
                            orderedQuantity[i] = orderedQuantity[i + 1];
                            foodOrderedPrice[i] = foodOrderedPrice[i + 1];
                        }
                    }
                    break;
                default:
                    break;
                }
                cout << endl;
                //print out current changed order
                cout << "Your current order:                                                               " << endl;
                cout << "Order No.         Food              Type              Quantity          Price     " << endl;
                cout << "==================================================================================" << endl;
                for (int j = 0; j < orderCount + 1; j++)//condition needs to + 1 else first order won't display 
                {   //Array value display with the same initialization value [j] 
                    //      else if used [orderCount] value it will only print the same exact recent order 2 times
                    cout << j + 1 << left << setw(17) << setfill(' ') << "." <<
                        left << setw(18) << setfill(' ') << foodsOrdered[j] <<
                        left << setw(18) << setfill(' ') << orderedFoodType[j] <<
                        left << setw(18) << setfill(' ') << orderedQuantity[j] <<
                        "RM " << foodOrderedPrice[j] << endl;
                }
                cout << "==================================================================================" << endl << endl;

                //ask if there's anything more to edit
                cout << "Need to edit more?" << endl;
                cout << "[Y] Yes [Any Button] No" << endl;
                cout << "--> ";
                cin >> editContinue;
                //edit module action
                if (editContinue == 'Y' || editContinue == 'y')//edit module continue
                {
                    continue;
                }
                else//stop edit module
                {
                    editStop = true;
                }
            }
            //ask to order again or not
            cout << "Order Again?" << endl;
            cout << "*Press Any Button for Yes; [N] for No" << endl;
            cout << "--> ";
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
        else //A new order count is added and loopback Ordering Function
        {
            orderCount++;
        }
    }
    paymentModule(waysToDine, orderCount, orderedQuantity, orderedFoodType, foodsOrdered, foodOrderedPrice);
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
            cout << showpoint << fixed << setprecision(2) << "\nYour current top up balance is : RM" << member.topUp[chosen_position] << endl;
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
            cout << "\n---------------------------" << endl;
            cout << "Your balance is RM" << member.topUp[chosen_position] << endl;
            cout << "---------------------------" << endl;
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
void paymentModule(char waysToDine, int orderCount, int orderedQuantity[], char orderedFoodType[], string foodsOrdered[], float foodOrderedPrice[])
{
    double subtotal = 0;
    double payment = 0; //Payment Testing
    for (int i = 0; i < orderCount + 1; i++)
    {
        subtotal += foodOrderedPrice[i];
    }
    if (waysToDine == 'D')
    {
        payment = subtotal * 1.10;
    }
    else if (waysToDine == 'T')
    {
        payment = subtotal + 2.00;
    }
    cout << "\nYour order:                                                               " << endl;
    cout << "Order No.         Food              Type              Quantity          Price     " << endl;
    cout << "==================================================================================" << endl;
    for (int j = 0; j < orderCount + 1; j++)//condition needs to + 1 else first order won't display 
    {   
        cout << j + 1 << left << setw(17) << setfill(' ') << "." <<
            left << setw(18) << setfill(' ') << foodsOrdered[j] <<
            left << setw(18) << setfill(' ') << orderedFoodType[j] <<
            left << setw(18) << setfill(' ') << orderedQuantity[j] <<
            "RM " << foodOrderedPrice[j] << endl;
    }
    cout << "==================================================================================" << endl << endl;
    cout << showpoint << fixed << setprecision(2) << "Subtotal: RM" << subtotal << endl;
    cout << showpoint << fixed << setprecision(2) << "Total Payment: RM" << payment << endl;
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
    cin.get();
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
                    pointsModule(payment, paymentMethod, subtotal, waysToDine, orderCount, orderedQuantity, orderedFoodType, foodsOrdered, foodOrderedPrice);
                    member.topUp[chosen_position] -= payment;
                    cout << showpoint << fixed << setprecision(2) << "\nPayment received using top up. Your new membership top up is RM" << member.topUp[chosen_position] << ".";
                    cout << "\nYou have earned " << (int)payment << " points. Your new membership points is " << member.points[chosen_position] << " points." << endl;
                    printReceipt(waysToDine, orderCount, orderedQuantity, orderedFoodType, foodsOrdered, foodOrderedPrice, subtotal, payment);
                    break;
                }
            }
            break;
        }
        else if (paymentMethod == "2")
        {
            stop4 = pointsModule(payment, paymentMethod, subtotal, waysToDine, orderCount, orderedQuantity, orderedFoodType, foodsOrdered, foodOrderedPrice);
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
bool pointsModule(double payment, string paymentMethod, double subtotal, char waysToDine, int orderCount, int orderedQuantity[], char orderedFoodType[], string foodsOrdered[], float foodOrderedPrice[])
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
            printReceipt(waysToDine, orderCount, orderedQuantity, orderedFoodType, foodsOrdered, foodOrderedPrice, subtotal, payment);
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

void printReceipt(char waysToDine, int orderCount, int orderedQuantity[], char orderedFoodType[], string foodsOrdered[], float foodOrderedPrice[], double subtotal, double payment)
{
    ofstream outFile;
    string receiptFile = member.membershipList[chosen_position] + " " + member.name[chosen_position] + " Receipt.txt";
    outFile.open(receiptFile);
    outFile << "NELOON FAST FOOD" << endl;
    outFile << setw(16) << setfill('*') << "\n";
    outFile << setw(11) << setfill(' ') << "RECEIPT" << endl;
    outFile << setw(16) << setfill('*') << "\n";
    outFile << "Order No.         Food              Type              Quantity          Price     " << endl;
    outFile << "==================================================================================" << endl;
    for (int j = 0; j < orderCount + 1; j++)//condition needs to + 1 else first order won't display 
    {
        outFile << j + 1 << left << setw(17) << setfill(' ') << "." <<
            left << setw(18) << setfill(' ') << foodsOrdered[j] <<
            left << setw(18) << setfill(' ') << orderedFoodType[j] <<
            left << setw(18) << setfill(' ') << orderedQuantity[j] <<
            "RM " << foodOrderedPrice[j] << endl;
    }
    outFile << "==================================================================================" << endl << endl;
    outFile << showpoint << fixed << setprecision(2) << "Subtotal: RM" << subtotal << endl;
    outFile << showpoint << fixed << setprecision(2) << "Total Payment: RM" << payment << endl;
    outFile << "Membership number: " << member.membershipList[chosen_position] << endl;
    outFile << "Membership name: " << member.name[chosen_position] << endl;
    outFile.close();

    cout << "\nNELOON FAST FOOD" << endl;
    cout << "****************" << endl;
    cout << "     RECEIPT" << endl;
    cout << "****************" << endl;
    cout << "Order No.         Food              Type              Quantity          Price     " << endl;
    cout << "==================================================================================" << endl;
    for (int j = 0; j < orderCount + 1; j++)//condition needs to + 1 else first order won't display 
    {
        cout << j + 1 << left << setw(17) << setfill(' ') << "." <<
            left << setw(18) << setfill(' ') << foodsOrdered[j] <<
            left << setw(18) << setfill(' ') << orderedFoodType[j] <<
            left << setw(18) << setfill(' ') << orderedQuantity[j] <<
            "RM " << foodOrderedPrice[j] << endl;
    }
    cout << "==================================================================================" << endl << endl;
    cout << showpoint << fixed << setprecision(2) << "Subtotal: RM" << subtotal << endl;
    cout << showpoint << fixed << setprecision(2) << "Total Payment: RM" << payment << endl;
    cout << "Membership number: " << member.membershipList[chosen_position] << endl;
    cout << "Membership name: " << member.name[chosen_position] << endl;
}
