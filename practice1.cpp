#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// Class representing an item
class Item {
public:
    int itemID;
    string itemName;
    double price;
    int stockQuantity;

    Item(int id, string name, double p, int qty) {
        if (p < 0 || qty < 0)
            throw invalid_argument("Price and quantity cannot be negative.");
        itemID = id;
        itemName = name;
        price = p;
        stockQuantity = qty;
    }

    void reduceStock(int qty) {
        if (qty > stockQuantity)
            throw runtime_error("Not enough stock available.");
        stockQuantity -= qty;
    }
};

// Bill class
class Bill {
private:
    static int billCounter;

public:
    int billID;
    string customerName;
    vector<pair<Item, int>> purchasedItems;

    Bill(string cname) {
        billID = ++billCounter;
        customerName = cname;
    }

    void operator+(pair<Item, int> purchase) {
        Item item = purchase.first;
        int qty = purchase.second;

        if (qty <= 0)
            throw invalid_argument("Quantity must be positive.");

        if (qty > item.stockQuantity)
            throw runtime_error("Attempt to buy more than available stock.");

        purchasedItems.push_back(purchase);
    }

    friend ostream& operator<<(ostream& out, const Bill& b) {
        if (b.purchasedItems.empty())
            throw runtime_error("Bill is empty!");

        out << "\n--- Bill ID: " << b.billID << " ---\n";
        out << "Customer Name: " << b.customerName << "\n";
        out << "Items:\n";

        double total = 0;
        for (const auto& item : b.purchasedItems) {
            out << "- " << item.first.itemName
                << " | Qty: " << item.second
                << " | Price: " << item.first.price
                << " | Subtotal: " << item.first.price * item.second << "\n";
            total += item.first.price * item.second;
        }

        out << "Total Amount: $" << total << "\n";
        out << "----------------------\n";
        return out;
    }

    void saveToFile() {
        ofstream file("bills.txt", ios::app);
        if (file.is_open()) {
            file << *this;
            file.close();
        }
    }

    static void loadBills() {
        ifstream file("bills.txt");
        string line;
        cout << "\n--- Previous Bills ---\n";
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }
};

int Bill::billCounter = 0;

int main() {
    try {
        Bill::loadBills();

        int numItems;
        cout << "Enter number of items to store in the shop: ";
        cin >> numItems;

        vector<Item> storeItems;
        for (int i = 0; i < numItems; i++) {
            cout << "\nEnter details for item #" << (i + 1) << ":\n";

            int id;
            string name;
            double price;
            int stock;

            cout << "Item ID: ";
            cin >> id;
            cin.ignore();  // Ignore leftover newline

            cout << "Item Name: ";
            getline(cin, name);

            cout << "Price: ";
            cin >> price;

            cout << "Stock Quantity: ";
            cin >> stock; 

            storeItems.push_back(Item(id, name, price, stock));
        }

        // Get customer name
        string customerName;
        cout << "\nEnter customer name: ";
        cin.ignore();  // Ignore newline from previous input
        getline(cin, customerName);

        Bill bill(customerName);

        while (true) {
            cout << "\nAvailable items:\n";
            for (const auto& item : storeItems) {
                cout << item.itemID << ". " << item.itemName << " (Price: $" << item.price 
                     << ", Stock: " << item.stockQuantity << ")\n";
            }
            cout << "Enter item ID to purchase (0 to finish): ";
            int chosenID;
            cin >> chosenID;

            if (chosenID == 0)
                break;

            // Find the item by ID
            bool found = false;
            for (auto& item : storeItems) {
                if (item.itemID == chosenID) {
                    found = true;
                    cout << "Enter quantity to buy: ";
                    int qty;
                    cin >> qty;

                    if (qty <= 0) {
                        cout << "Quantity must be positive. Try again.\n";
                        break;
                    }

                    if (qty > item.stockQuantity) {
                        cout << "Not enough stock. Available: " << item.stockQuantity << "\n";
                        break;
                    }

                    // Add item to bill
                    bill + make_pair(item, qty);

                    // Reduce stock from store
                    item.reduceStock(qty);

                    cout << qty << " x " << item.itemName << " added to bill.\n";
                    break;
                }
            }
            if (!found) {
                cout << "Item ID not found. Try again.\n";
            }
        }

        // Show the bill
        cout << bill;

        // Save bill to file
        bill.saveToFile();

    } catch (exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
