#include <iostream>
#include <iomanip> 
#include <limits>  


void printHeader();
void printMenu();
void performOperation(int choice, double &num1, double &num2);

int main()
{
    char choice;
    do
    {
        double num1, num2;
        int operation;

        printHeader();

        // Input first number
        std::cout << "Enter the first number: ";
        std::cin >> num1;

        // Input second number
        std::cout << "Enter the second number: ";
        std::cin >> num2;

        // Loop to display menu and perform operations
        do
        {
            std::cout << std::endl;
            // Print menu and get operation choice
            printMenu();
            std::cout << "Enter your choice (1-5 to continue/6 to exit): ";
            std::cin >> operation;

            // Perform selected operation or change numbers
            if (operation >= 1 && operation <= 4)
            {
                performOperation(operation, num1, num2);
            }
            else if (operation == 5)
            {
                // Change numbers
                std::cout << "\nEnter new numbers:" << std::endl;
                std::cout << "Enter the first number: ";
                std::cin >> num1;
                std::cout << "Enter the second number: ";
                std::cin >> num2;
            }
            else if (operation == 6)
            {
                // Exit the program
                break;
            }
            else
            {
                std::cout << "Invalid choice! Please enter a number between 1 and 6." << std::endl;
            }

        } while (operation != 6);

        std::cout << "\nDo you want to use the calculator again? (y/n): ";
        std::cin >> choice;

    
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice == 'y' || choice == 'Y');

    std::cout << "\nGoodbye! Thank you for using the calculator." << std::endl;

    return 0;
}

void printHeader()
{
    std::cout << "===================================" << std::endl;
    std::cout << "   WELCOME TO SIMPLE CALCULATOR" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
    std::cout << "This program performs basic arithmetic operations." << std::endl;
    std::cout << "Please enter two numbers and choose an operation." << std::endl;
    std::cout << std::endl;
}

void printMenu()
{
    std::cout << "-------------- MENU --------------" << std::endl;
    std::cout << std::setw(2) << "1. Addition" << std::endl;
    std::cout << std::setw(2) << "2. Subtraction" << std::endl;
    std::cout << std::setw(2) << "3. Multiplication" << std::endl;
    std::cout << std::setw(2) << "4. Division" << std::endl;
    std::cout << std::setw(2) << "5. Change numbers" << std::endl;
    std::cout << std::setw(2) << "6. Exit" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}

void performOperation(int choice, double &num1, double &num2)
{
    double result;

    switch (choice)
    {
    case 1:
        result = num1 + num2;
        std::cout << std::fixed << std::setprecision(2) << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
        break;
    case 2:
        result = num1 - num2;
        std::cout << std::fixed << std::setprecision(2) << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
        break;
    case 3:
        result = num1 * num2;
        std::cout << std::fixed << std::setprecision(2) << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
        break;
    case 4:
        if (num2 == 0)
        {
            std::cout << "Error! Division by zero is not allowed." << std::endl;
        }
        else
        {
            result = num1 / num2;
            std::cout << std::fixed << std::setprecision(2) << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
        }
        break;
    default:
        std::cout << "Invalid choice! Please enter a number between 1 and 6." << std::endl;
        return;
    }
}
