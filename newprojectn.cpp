#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class shopping {
private:
    int productCode;
    float price;
    float discount;  // discount is in percentage
    string productName;

public:
    void menu() {
        // Display the Main menu to the customer, admin, staff, etc.
        while (true) {
            int choice;
            string email;
            string password;

            cout << "-----------------------------------------------------------------------\n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t        Supermarket Main Menu        \n";
            cout << "\t\t\t                                     \n";
            cout << "-----------------------------------------------------------------------\n";

            cout << "|                                                                      |\n";
            cout << "| 1)Administrator                                                      |\n";
            cout << "|                                                                      |\n";
            cout << "| 2)Customer                                                           |\n";
            cout << "|                                                                      |\n";
            cout << "| 3)Exit                                                               |\n";
            cout << "|                                                                      |\n";
            cout << "\n\t\t\tPlease Select: ";
            cin >> choice;
            cout<<"__________________________________________________________________________\n";

            switch (choice) {
                case 1:
                    cout << "\t\t\tPlease Login(Administrators)        " << endl;
                    cout << "\t\t\tEnter Email: ";
                    cin >> email;
                    cout << "\t\t\tEnter Password: ";
                    cin >> password;
                    if ((email == "admin1@navanit.com" && password == "NIT@Agartala123") ||
                        (email == "admin2@navanit.com" && password == "LoremIpsum") ||
                        (email == "admin3@navanit.com" && password == "23UEE130")) {
                        admin();
                    } else {
                        cout << "Invalid Username and Password" << endl;
                    }
                    break;
                case 2:
                    customer();
                    break;
                case 3:
                    exit(0);
                    break;
                default:
                    cout << "Please select the correct number from the given option" << endl;
                    break;
            }
        }
    }

    void admin() {
        // For administrator to access the Back Panel
        int key;
        while (true) {
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t          Administrator Menu         \n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t 1) Add new Product\t\t\t" << endl;
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t 2) Modify the Product\t\t\t" << endl;
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t 3) Delete the Product\t\t\t" << endl;
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t 4) Back to the Main menu\t\t\t" << endl;
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t Please Enter your choice: ";
            cin >> key;

            switch (key) {
                case 1:
                    addProduct();
                    break;
                case 2:
                    modifyProduct();
                    break;
                case 3:
                    removeProduct();
                    break;
                case 4:
                    return; // Go back to main menu
                default:
                    cout << "Please enter a valid choice. Redirecting you back to the Menu." << endl;
                    break;
            }
        }
    }

    void customer() {
        // For customer to access items in the store
        int key;
        while (true) {
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t*************************************\n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t            Customer Menu            \n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t*************************************\n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t                                     \n";
            cout << "\t\t\t1) Buy Product " << endl;
            cout << "\t\t\t2) Exit " << endl;

            cout << "\t\t\tEnter your choice: ";
            cin >> key;
            switch (key) {
                case 1:
                    receipt();
                    break;
                case 2:
                    return; // Go back to main menu
                default:
                    cout << "\nPlease enter a valid choice. Redirecting you to the main menu." << endl;
                    break;
            }
        }
    }

    void addProduct() {
        // For admin to add new product
        fstream data;
        int c;
        int check = 0;
        float p;
        float d;
        string n;

        cout << "\n\t\t\tAdding new Product" << endl;
        cout << "\t\t--------------------------------------" << endl;
        cout << "\n\t\t\tName of the Product: ";
        cin >> productName;
        cout << "\n\t\t\tProduct code of the Product: ";
        cin >> productCode;
        cout << "\n\t\t\tPrice of the Product: ";
        cin >> price;
        cout << "\n\t\t\tDiscount on Product: ";
        cin >> discount;

        data.open("database.txt", ios::in);
        if (!data) {
            data.open("database.txt", ios::app | ios::out);
            data << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
            data.close();
        } else {
            data >> c >> n >> p >> d;

            while (!data.eof()) {
                if (c == productCode) {
                    check++;
                }
                data >> c >> n >> p >> d;
            }
            data.close();
        }

        if (check == 1) {
            cout << "\t\t\tProduct already exists with the entered product code" << endl;
        } else {
            data.open("database.txt", ios::app | ios::out);
            data << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
            data.close();
        }
        cout << "\n\n\t\t\tRecord Inserted inside file" << endl;
    }

    void modifyProduct() {
        // For admin to edit existing product
        fstream data0, data1;
        int pkey;
        int check = 0;
        float d;
        string n;
        float p;
        int c;

        cout << "\n\t\t\tModify the records" << endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\tProduct code: ";
        cin >> pkey;

        data0.open("database.txt", ios::in);

        if (!data0) {
            cout << "\t\t\tFile does not exist" << endl;
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data0 >> productCode >> productName >> price >> discount;
            while (!data0.eof()) {
                if (pkey == productCode) {
                    cout << "\n\t\t\tEnter the new details for the product" << endl;
                    cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "\n\t\t\tNew product code: ";
                    cin >> c;
                    cout << "\n\t\t\tProduct Name: ";
                    cin >> n;
                    cout << "\n\t\t\tPrice (new): ";
                    cin >> p;
                    cout << "\n\t\t\tNew Discount: ";
                    cin >> d;
                    data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                    cout << "\n\t\t\tRecord Edited Successfully!" << endl;
                    check++;
                } else {
                    data1 << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
                }
                data0 >> productCode >> productName >> price >> discount;
            }
            data0.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (check == 0) {
                cout << "\n\t\t\tRecord not found" << endl;
                cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            }
        }
    }

    void removeProduct() {
        // For admin to remove an existing product
        fstream data0, data1;
        int pkey;
        int check = 0;
        cout << "\n\t\t\tRemove Product" << endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\tEnter product code of the product to be removed: ";
        cin >> pkey;
        data0.open("database.txt", ios::in);

        if (!data0) {
            cout << "\n\t\t\tFile does not exist" << endl;
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            data0 >> productCode >> productName >> price >> discount;
            while (!data0.eof()) {
                if (productCode == pkey) {
                    cout << "\n\t\t\tProduct removed successfully" << endl;
                    check++;
                } else {
                    data1 << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
                }
                data0 >> productCode >> productName >> price >> discount;
            }
            data0.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (check == 0) {
                cout << "\n\t\t\tProduct code not found" << endl;
                cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            }
        }
    }




//original one
    // void list() {
    //     // For the customer to check the list of products
    //     fstream data;
    //     data.open("database.txt", ios::in);
    //     cout << "\n\n\t\t\t______________________________________\n";
    //     cout << "\t\t\t        PRODUCT LIST                  \n";
    //     cout << "\t\t\t--------------------------------------\n";
    //     cout << "ProNo\t\tName\t\tPrice\t\tDiscount";
    //     cout << "\t\t\t______________________________________\n";
    //     data >> productCode >> productName >> price >> discount;
    //     while (!data.eof()) {
    //         cout << productCode << "\t\t" << productName << "\t\t" << price <<"\t\t"<<discount<< endl;
    //         data >> productCode >> productName >> price >> discount;
    //     }
    //     data.close();
    // }




void list() {
    // For the customer to check the list of products
    fstream data;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n\t\t\tNo products available\n";
        return;
    }

    cout << "\n\n____________________________________________________________________\n";
    cout << "\t\t\t        PRODUCT LIST                  \n";
    cout << "------------------------------------------------------------------------\n";
    cout << left << setw(10) << "ProNo" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Discount" << endl;
    cout << "________________________________________________________________________\n";

    data >> productCode >> productName >> price >> discount;
    while (!data.eof()) {
        cout << left << setw(10) << productCode << setw(20) << productName << setw(10) << price << setw(10) << discount << endl;
        data >> productCode >> productName >> price >> discount;
    }
    data.close();
}



    void receipt() {
        // For customer to buy products and get a receipt
        fstream data;
        int arrCode[100];
        int arrQty[100];
        char choice;
        int count = 0;
        float amount = 0;
        float total = 0;
        float dis = 0;

        // cout << "\n\n\t\t\t______________________________________\n";
        // cout << "\t\t\t        Generate Receipt              \n";
        // cout << "\t\t\t--------------------------------------\n";
        data.open("database.txt", ios::in);
        if (!data) {
            cout << "\n\n\t\t\tEmpty Database" << endl;
        } else {
            data.close();

            list();
            cout << "\n________________________________________________________________________\n";
            cout << "\n\t\t\t    Please place the order            \n";
            cout << "\n________________________________________________________________________\n";
            do {
                cout << "\n\t\t\tEnter Product code: ";
                cin >> arrCode[count];
                cout << "\t\t\tEnter the quantity: ";
                cin >> arrQty[count];
                for (int i = 0; i < count; i++) {
                    if (arrCode[count] == arrCode[i]) {
                        cout << "\n\t\t\tDuplicate product code. Please try again.\n";
                        count--;
                        break;
                    }
                }
                count++;
                cout << "\n\t\t\tDo you want to buy another product? (Y/N): ";
                cin >> choice;
            } while (choice == 'Y' || choice == 'y');

            cout << "\n\n__________________________RECEIPT_______________________________\n";
            cout << "\tProduct No\tProduct Name\tQuantity\tPrice\tAmount\tAmount with discount\n";

            for (int i = 0; i < count; i++) {
                data.open("database.txt", ios::in);
                data >> productCode >> productName >> price >> discount;
                while (!data.eof()) {
                    if (productCode == arrCode[i]) {
                        amount = price * arrQty[i];
                        dis = amount - (amount * discount / 100);
                        total += dis;
                        cout << "\t" << productCode << "\t\t" << productName << "\t\t" << arrQty[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis << endl;
                    }
                    data >> productCode >> productName >> price >> discount;
                }
                data.close();
            }
            cout << "\n\t\t\t______________________________________\n";
            cout << "\t\t\t Total Amount: " << total << endl;
        }
    }
};

int main() {
    shopping s;
    s.menu();
    return 0;
}
