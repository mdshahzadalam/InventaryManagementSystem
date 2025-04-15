#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
};

class InventorySystem {
private:
    std::vector<Item> inventory;
    int nextId = 1;

public:
    void addItem(const std::string& name, int quantity, double price) {
        inventory.push_back({nextId++, name, quantity, price});
        std::cout << "Item added successfully.\n";
    }

    void removeItem(int id) {
        auto it = std::remove_if(inventory.begin(), inventory.end(),
            [id](const Item& item) { return item.id == id; });

        if (it != inventory.end()) {
            inventory.erase(it, inventory.end());
            std::cout << "Item removed successfully.\n";
        } else {
            std::cout << "Item with ID " << id << " not found.\n";
        }
    }

    void generateReport() const {
        std::cout << std::left << std::setw(5) << "ID"
                  << std::setw(20) << "Name"
                  << std::setw(10) << "Qty"
                  << std::setw(10) << "Price" << "\n";
        std::cout << "---------------------------------------------\n";

        for (const auto& item : inventory) {
            std::cout << std::left << std::setw(5) << item.id
                      << std::setw(20) << item.name
                      << std::setw(10) << item.quantity
                      << std::setw(10) << item.price << "\n";
        }
    }

    void menu() {
        int choice;
        do {
            std::cout << "\n--- Inventory Management System ---\n";
            std::cout << "1. Add Item\n";
            std::cout << "2. Remove Item\n";
            std::cout << "3. Generate Report\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::string name;
                    int qty;
                    double price;
                    std::cout << "Enter item name: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    std::cout << "Enter quantity: ";
                    std::cin >> qty;
                    std::cout << "Enter price: ";
                    std::cin >> price;
                    addItem(name, qty, price);
                    break;
                }
                case 2: {
                    int id;
                    std::cout << "Enter item ID to remove: ";
                    std::cin >> id;
                    removeItem(id);
                    break;
                }
                case 3:
                    generateReport();
                    break;
                case 4:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    InventorySystem system;
    system.menu();
    return 0;
}
