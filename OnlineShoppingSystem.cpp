
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Product class
class Product {
private:
    int id;
    string name;
    double price;

public:
    Product(int productId, string productName, double productPrice) 
        : id(productId), name(productName), price(productPrice) {}

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

// Cart class
class Cart {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
        cout << product.getName() << " added to cart." << endl;
    }

    void viewCart() const {
        cout << "\nYour Cart:\n";
        if (products.empty()) {
            cout << "Cart is empty." << endl;
            return;
        }
        for (const auto& product : products) {
            product.display();
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.getPrice();
        }
        return total;
    }
};

// Payment simulation
class Payment {
public:
    static void processPayment(double amount) {
        cout << "\nProcessing payment of $" << amount << "..." << endl;
        cout << "Payment successful! Thank you for shopping.\n" << endl;
    }
};

int main() {
    vector<Product> productList = {
        Product(1, "Laptop", 999.99),
        Product(2, "Smartphone", 499.99),
        Product(3, "Headphones", 199.99),
        Product(4, "Smartwatch", 249.99)
    };

    Cart cart;
    int choice;

    while (true) {
        cout << "\nOnline Shopping System\n";
        cout << "1. View Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nAvailable Products:\n";
            for (const auto& product : productList) {
                product.display();
            }
        } else if (choice == 2) {
            int productId;
            cout << "Enter Product ID to add to cart: ";
            cin >> productId;

            bool found = false;
            for (const auto& product : productList) {
                if (product.getId() == productId) {
                    cart.addProduct(product);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Invalid Product ID." << endl;
            }
        } else if (choice == 3) {
            cart.viewCart();
        } else if (choice == 4) {
            cart.viewCart();
            double total = cart.calculateTotal();
            if (total > 0) {
                cout << "Total Amount: $" << total << endl;
                Payment::processPayment(total);
            } else {
                cout << "Your cart is empty. Cannot proceed to checkout." << endl;
            }
        } else if (choice == 5) {
            cout << "Thank you for using the Online Shopping System. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
