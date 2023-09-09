#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;

//Main operating functions
void dineChoiceFunction(bool dineValidation, char waysToDine, float charges); //line 25
int foodSelectionDisplayAndOrder(string foods[], float foodPrice[], int &foodChoice);
char typeSelection(char &foodType);
int getQuantity(int &quantity);
char getOrderAgain(char orderAgain);
void displayOrder(int orderCount, string foodsOrdered[], char orderedFoodType[], int orderedQuantity[], float foodOrderedPrice[]);

//sub-functions
void menuDisplay(string foods[], float foodPrice[]);
void foodTypeCalculation_S(int quantity, int orderCount, int foodChoice, float &foodOrderedPrice[], float foodPrice[]);
void foodTypeCalculation_B(int quantity, int orderCount, int foodChoice, float &foodOrderedPrice[], float foodPrice[]);
void foodTypeCalculation_A(int quantity, int orderCount, int foodChoice, float &foodOrderedPrice[], float foodPrice[]);

int main ()
{
    //User Input Data
    int foodChoice, quantity, maxOrder = 10;
    char waysToDine, foodType, orderAgain;
    //Menu Data
    string foods [6]    = {"Burger" , "Fried Chicken" , "Nasi Lemak" , "Nuggets" , "Fries" , "Coke" };
    float foodPrice [6] = { 8.00    ,  6.00           , 10.00        , 6.00      , 3.00    , 2.00   };
    //Order Data
    int orderCount = 0, orderedQuantity [maxOrder], foodChoiceSave [maxOrder];
    char orderedFoodType [maxOrder];
    string foodsOrdered [maxOrder];
    float foodOrderedPrice [maxOrder];
    //Service Charge Data
    float charges;

    //customer choosing to dine in or take away
    dineChoiceFunction(waysToDine, charges);

    //Ordering Selection Function
    //1st : Get User Input
    //2nd : Store Data in Arrays
    //3rd : Display Order Details
    //4th : Ask to order again (until maxOrder) or stop ordering *or staff edit
    for (int i = 0; i < maxOrder; i++)
    {
        //1 : Get User Input
        foodSelectionDisplayAndOrder(foods, foodPrice, foodChoice);
        typeSelection(foodType);
        getQuantity(quantity);

        //2 : Store the data user inputed into an array based on current order count
        foodsOrdered[orderCount] = foods[foodChoice - 1];
        orderedFoodType[orderCount] = foodType;
        orderedQuantity[orderCount] = quantity;
        foodChoiceSave[orderCount] = foodChoice - 1; //To save for further edit track
        //calculation of single order food price *calculation included "multipled by quantity"
        if (foodType == 'S' || foodType == 's')//if set will also add on the price of fries and coke
        {
            foodTypeCalculation_S(quantity, orderCount, foodChoice, foodOrderedPrice, foodPrice);
        }
        else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
        {
            foodTypeCalculation_B(quantity, orderCount, foodChoice, foodOrderedPrice, foodPrice);
        }
        else//just add on the ala-carte price
        {
            foodTypeCalculation_A(quantity, orderCount, foodChoice, foodOrderedPrice, foodPrice);
        }    

        //3 : Display the data user inputed
        displayOrder(orderCount, foodsOrdered, orderedFoodType, orderedQuantity, foodOrderedPrice);

        //4 : Ask user if they want to continue to order
        getOrderAgain(orderAgain);

        if (orderAgain == 'N' || orderAgain == 'n')//Will stop when user key in "N" or "n"
        {
            break;
        }

        else if (orderAgain == 'E' || orderAgain == 'e')//Staff editing mode
        {
            int editChoice, editType, toEditFoodChoice;
            char editContinue;
            bool editStop = false;

            while (editStop == false)
            {
                cout << "***Order editing mode***" << endl;
                cout << endl;

                displayOrder(orderCount, foodsOrdered, orderedFoodType, orderedQuantity, foodOrderedPrice);



            }
            
        }
        

        else //A new order count is added and loopback Ordering Function
        {
            orderCount++;
        }
    }
    
    
    return 0;
}

//Main operating functions
//function of choosing to dine in or take away
void dineChoiceFunction(char waysToDine, float charges)
{
    bool dineValidation = false;
    //customer choosing to dine in or take away
    cout << "Do you want to dine-in or take-away?" << endl;
    cout << "Press : { [D] to dine-in  ,  [T] to take-away }"  << endl;
    cin >> waysToDine;
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
        else if (waysToDine >= 0 || waysToDine < 0)//Invalid input! User try again.
        {
            cout << "Invalid input! Please choose again." << endl;
            cout << "Press : { [D] to dine-in  ,  [T] to take-away } : "; 
            cin >> waysToDine;
        }
        else//Invalid input! User try again.
        {
            cout << "Invalid input! Please choose again." << endl;
            cout << "Press : { [D] to dine-in  ,  [T] to take-away } : "; 
            cin >> waysToDine;
        }
    }
}

//1.0 : Display menu and food selection and get User's food choice
int foodSelectionDisplayAndOrder(string foods[], float foodPrice[], int &foodChoice)
{
    do
    {
        int choiceCount = 0;
        //Menu Display
        menuDisplay(foods, foodPrice);
        //let user choose the order based on numbers given
        cout << "*Press the number inside [ ] to select your order" << endl;
        cin >> foodChoice;
        if (foodChoice > 6 || foodChoice <= 0)//validation for available option
        {
            cout << "Option does not exist. Please try again." << endl;
            choiceCount ++;
        }    
    } while (foodChoice > 6 || foodChoice <= 0);// will keep looping until user key in the available number of foodChoice 
    return foodChoice;
}
//1.1 : Get user to want set or ala-carte
char typeSelection(char &foodType)
{
    cout << "Do you want Set or Ala-carte or Both?" << endl;
    cout << "Type : [S] for Set ;" << endl;
    cout << "       [A] for Ala-carte ;" << endl;
    cout << "       [B] for Both " << endl;
    cin >> foodType;
    //validation
    bool foodTypeValidation = false;
    while (foodTypeValidation == false)
    {
        if (foodType == 'S' || foodType == 's' || foodType == 'A' || foodType == 'a' || foodType == 'B'|| foodType == 'b')
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
    return foodType;
}
//1.2 : Get user quantity of food selected 
int getQuantity(int &quantity)
{
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
    return quantity;
}
//4 : Get orderAgain? Input 
char getOrderAgain(char orderAgain)
{
    //4 : Ask user if they want to continue to order
    cout << "Order Again?" << endl;
    cout << "*Press Any Button for Yes; [N] for No" << endl;
    cin >> orderAgain;
    return orderAgain;
}
//3 : Display the data user inputed
void displayOrder(int orderCount, string foodsOrdered[], char orderedFoodType[], int orderedQuantity[], float foodOrderedPrice[])
{
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
}

//Sub-functions
void menuDisplay(string foods[], float foodPrice[])
{
    cout << "What would you like to order?" << endl;
    cout << "Food              || Price" << endl; 
    cout << "==================||================" <<endl;
    for (int i = 0 ; i < 6 ; i++)// loop print all the menu's foods and price with format
    {
        cout << left << setw(18) << setfill(' ') <<  foods[i] 
        << "|| RM" << fixed << setprecision(2) << right << setw(8) << setfill (' ') << foodPrice[i] 
        << "  [" << i + 1 << "]" << endl;
    }
}

//foodOrderedPrice Calculations
//i)Set calc.
void foodTypeCalculation_S(int quantity, int orderCount, int foodChoice, float &foodOrderedPrice[], float foodPrice[])
{
    foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1] + foodPrice[4] + foodPrice[5])*quantity;
}
//ii)Both calc.
void foodTypeCalculation_B(int quantity, int orderCount, int foodChoice, float &foodOrderedPrice[], float foodPrice[])
{
    foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1]*2 + foodPrice[4] + foodPrice[5])*quantity;
}
//iii)Ala-carte calc.
void foodTypeCalculation_A(int quantity, int orderCount, int foodChoice, float &foodOrderedPrice[], float foodPrice[])
{
    foodOrderedPrice[orderCount] = foodPrice[foodChoice - 1]*quantity;
}

//edit Function
