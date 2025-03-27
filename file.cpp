#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill {
private:
    string itemName;
    int itemPrice, itemQuantity;
public:
    Bill() : itemName(""), itemPrice(0), itemQuantity(0) { }

    void setItemName(string name) {
        itemName = name;
    }

    void setItemPrice(int price) {
        itemPrice = price;
    }

    void setItemQuantity(int quantity) {
        itemQuantity = quantity;
    }

    string getItemName() {
        return itemName;
    }

    int getItemPrice() {
        return itemPrice;
    }

    int getItemQuantity() {
        return itemQuantity;
    }
};

void addNewItem(Bill bill) {
    bool closeMenu = false;
    while (!closeMenu) {
        int userChoice;
        cout << "\t1. Add Item." << endl;
        cout << "\t2. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> userChoice;

        if (userChoice == 1) {
            system("cls");
            string item;
            int price, quantity;

            cout << "\tEnter Item Name: ";
            cin >> item;
            bill.setItemName(item);

            cout << "\tEnter Price of Item: ";
            cin >> price;
            bill.setItemPrice(price);

            cout << "\tEnter Quantity of Item: ";
            cin >> quantity;
            bill.setItemQuantity(quantity);

            ofstream fileOut("D:/Bill.txt", ios::app);
            if (!fileOut) {
                cout << "\tError: Unable to Open File!" << endl;
            } else {
                fileOut << "\t" << bill.getItemName() << " : " << bill.getItemPrice() << " : " << bill.getItemQuantity() << endl << endl;
            }
            fileOut.close();
            cout << "\tItem Added Successfully!" << endl;
            Sleep(3000);
        } else if (userChoice == 2) {
            system("cls");
            closeMenu = true;
            cout << "\tReturning to Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

void generateBill() {
    system("cls");
    int totalAmount = 0;
    bool closeBilling = false;

    while (!closeBilling) {
        system("cls");
        int choice;
        cout << "\t1. Add Item to Bill." << endl;
        cout << "\t2. Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string selectedItem;
            int requiredQuantity;
            cout << "\tEnter Item Name: ";
            cin >> selectedItem;
            cout << "\tEnter Quantity: ";
            cin >> requiredQuantity;

            ifstream fileIn("D:/Bill.txt");
            ofstream tempFile("D:/BillTemp.txt");

            string fileLine;
            bool itemFound = false;

            while (getline(fileIn, fileLine)) {
                stringstream lineStream;
                lineStream << fileLine;
                string name;
                int price, availableQuantity;
                char delimiter;
                lineStream >> name >> delimiter >> price >> delimiter >> availableQuantity;

                if (selectedItem == name) {
                    itemFound = true;
                    if (requiredQuantity <= availableQuantity) {
                        int itemTotal = price * requiredQuantity;
                        cout << "\tItem | Price | Quantity | Total" << endl;
                        cout << "\t" << name << "\t " << price << "\t " << requiredQuantity << "\t " << itemTotal << endl;
                        int newQuantity = availableQuantity - requiredQuantity;
                        availableQuantity = newQuantity;
                        totalAmount += itemTotal;

                        tempFile << "\t" << name << " : " << price << " : " << availableQuantity << endl;
                    } else {
                        cout << "\tSorry, " << selectedItem << " is Out of Stock!" << endl;
                    }
                } else {
                    tempFile << fileLine << endl;
                }
            }
            if (!itemFound) {
                cout << "\tItem Not Available!" << endl;
            }
            tempFile.close();
            fileIn.close();
            remove("D:/Bill.txt");
            rename("D:/BillTemp.txt", "D:/Bill.txt");
        } else if (choice == 2) {
            closeBilling = true;
            cout << "\tCalculating Total Bill..." << endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout << endl << endl;
    cout << "\tTotal Bill Amount: " << totalAmount << endl << endl;
    cout << "\tThank You for Shopping!" << endl;
    Sleep(5000);
}

int main() {
    Bill bill;

    bool exitSystem = false;
    while (!exitSystem) {
        system("cls");
        int mainChoice;

        cout << "\tWelcome to Supermarket Billing System" << endl;
        cout << "\t************************************" << endl;
        cout << "\t\t1. Add Item." << endl;
        cout << "\t\t2. Generate Bill." << endl;
        cout << "\t\t3. Exit." << endl;
        cout << "\t\tEnter Choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            system("cls");
            addNewItem(bill);
            Sleep(3000);
        } else if (mainChoice == 2) {
            generateBill();
        } else if (mainChoice == 3) {
            system("cls");
            exitSystem = true;
            cout << "\tGoodbye! Have a Nice Day!" << endl;
            Sleep(3000);
        }
    }
}
