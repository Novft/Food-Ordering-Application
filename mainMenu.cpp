#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    //User Input Data
    int foodChoice, quantity;
    char waysToDine, foodType, orderAgain;
    //Menu Data
    string foods [6]    = {"Burger" , "Fried Chicken" , "Nasi Lemak" , "Nuggets" , "Fries" , "Coke"};
    float foodPrice [6] = {8.00     , 6.00            , 10.00        , 6.00      , 3.00    , 2.00  };
    //Order Data
    int orderCount = 0, orderedQuantity [10], foodChoiceSave [10];
    char orderedFoodType [10];
    string foodsOrdered [10];
    float foodOrderedPrice [10];
    //Service Charge Data
    float charges;

    //customer choosing to dine in or take away
    cout << "Do you want to dine-in or take-away?" << endl;
    cout << "Type : [D] Dine-In ;"  << endl;
    cout << "       [T] Take-Away" << endl;
    cin >> waysToDine;
    //validation of input
    bool dineValidation ;
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
            cout << "Type : [D] Dine-In ;"  << endl;
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
            cout << "==================||================" <<endl;
            for (int i = 0 ; i < 6 ; i++)// loop print all the menu's foods and price with format
            {
                cout << left << setw(18) << setfill(' ') <<  foods[i] 
                << "|| RM" << fixed << setprecision(2) << right << setw(8) << setfill (' ') << foodPrice[i] 
                << "  [" << i + 1 << "]" << endl;
            }
            //let user choose the order based on numbers given
            cout << "*Press the number inside [ ] to select your order" << endl;
            cin >> foodChoice;
            if (foodChoice > 6 || foodChoice <= 0)//validation for available option
            {
                cout << "Option does not exist. Please try again." << endl;
                choiceCount ++;
            }    
        } while (foodChoice > 6 || foodChoice <= 0);// will keep looping until user key in the available number of foodChoice 

        //1.1 : Get user to want set or ala-carte
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
            foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1] + foodPrice[4] + foodPrice[5])*quantity;
        }
        else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
        {
            foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1]*2 + foodPrice[4] + foodPrice[5])*quantity;
        }
        else//just add on the ala-carte price
        {
            foodOrderedPrice[orderCount] = foodPrice[foodChoice - 1]*quantity;
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
        cout << "*Press Any Button for Yes; [N] for No" << endl;
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
                cout << "***Order editing mode***" << endl;
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
                cin >> editType;

                //EDIT CHOICE ACTIONS
                switch (editType) 
                {
                case 1: //Type edit
                    cout << "Do you want Set or Ala-carte or Both?" << endl;
                    cout << "Type : [S] for Set ;" << endl;
                    cout << "       [A] for Ala-carte ;" << endl;
                    cout << "       [B] for Both " << endl; 
                    cin >> foodType;
                    //validation
                    foodTypeValidation = false;
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
                    orderedFoodType[editChoice - 1] = foodType;

                    //calculation of single order food price *calculation included "multipled by quantity" (edit ver.)
                    toEditFoodChoice = foodChoiceSave[editChoice - 1]; //take the saved foodChoice number from the saved array
                    if (foodType == 'S' || foodType == 's')//if set will also add on the price of fries and coke
                    {
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice] + foodPrice[4] + foodPrice[5])*orderedQuantity[editChoice - 1];
                    }
                    else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
                    {
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice]*2 + foodPrice[4] + foodPrice[5])*orderedQuantity[editChoice - 1];
                    }
                    else//just add on the ala-carte price
                    {
                        foodOrderedPrice[editChoice - 1] = foodPrice[toEditFoodChoice]*orderedQuantity[editChoice - 1];
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
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice] + foodPrice[4] + foodPrice[5])*orderedQuantity[editChoice - 1];
                    }
                    else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
                    {
                        foodOrderedPrice[editChoice - 1] = (foodPrice[toEditFoodChoice]*2 + foodPrice[4] + foodPrice[5])*orderedQuantity[editChoice - 1];
                    }
                    else//just add on the ala-carte price
                    {
                        foodOrderedPrice[editChoice - 1] = foodPrice[toEditFoodChoice]*orderedQuantity[editChoice - 1];
                    }
                    break;
                case 3: //remove selected order no. data
                    orderCount -= 1;
                    //update order count in order
                    for (int i = editChoice - 1; i < orderCount + 1 ; i++)
                    {
                        foodsOrdered[i] = foodsOrdered[i+1];
                        orderedFoodType[i] = orderedFoodType[i+1];
                        orderedQuantity[i] = orderedQuantity[i+1];
                        foodOrderedPrice[i] = foodOrderedPrice[i+1];
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
    return 0;
}
    
//Things to do:
//  1. Add staff editable ordering function //Important //orderCount to track array of order //FIN
//  2. Complete display formating //FIN
//  3. Track customer's order based on Membership Number //Will do at further weeks
//  4. Files storing
//  5. Sorting function



//@ Juin Hong
//Data Types to note in order for you to carry it to Payment Module from this module :
//  float charges;
//  float foodOrderedPrice [10];
//Also... (From Assignment Question about your Payment Module)
//  "Once the customer confirms the order, the system calculates and displays
//  the *subtotal* of each ordered item and then calculates the *total payment of the food ordered*."
//Since I accidentally done your "Subtotal" part you can make this code as refrence to your module
//  //Data 
//  char foodType /*(can make it as ask user input temporarily for you to test)*/ ;
//  float foodPrice [6] = {8.00     , 6.00            , 10.00        , 6.00      , 3.00    , 2.00  };
//  int orderCount = 0 /*Array value for you to track individual order list*/
//  int quantity = 1 /*(you can self defined how much you want or ask user input)*/;
//  //Operation
//calculation of single order food price *calculation included "multipled by quantity"
// if (foodType == 'S' || foodType == 's')//if set will also add on the price of fries and coke
// {
//     foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1] + foodPrice[4] + foodPrice[5])*quantity;
// }
// else if (foodType == 'B' || foodType == 'b')//if both double the price of food choice and also add on fries and coke
// {
//     foodOrderedPrice[orderCount] = (foodPrice[foodChoice - 1]*2 + foodPrice[4] + foodPrice[5])*quantity;
// }
// else//just add on the ala-carte price
// {
//     foodOrderedPrice[orderCount] = foodPrice[foodChoice - 1]*quantity;
// }
