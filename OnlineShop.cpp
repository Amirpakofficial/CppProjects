#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;
    string description;

public:
    Product(string name, double price, int quantity, string description) 
        : name(name), price(price), quantity(quantity), description(description) {}

    string getName() { return name; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    string getDescription() { return description; }

    void setQuantity(int q) { quantity = q; }
    
    void displayProduct() {
        cout << "Name: " << name << "\nPrice: $" << price 
             << "\nQuantity: " << quantity << "\nDescription: " << description << endl;
    }
};

class User {
private:
    string username;
    string password;
    vector<Product> cart;

public:
    User(string username, string password)
        : username(username), password(password) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }  // Added for account info display
    bool login(string entered_password) { return entered_password == password; }
    
    void addToCart(Product p) {
        cart.push_back(p);
        cout << p.getName() << " added to cart.\n";
    }
    
    void viewCart() {
        cout << "Your Cart:\n";
        for (auto& p : cart) {
            p.displayProduct();
        }
    }

    void displayAccountInfo() {
        cout << "Account Info:\n";
        cout << "Username: " << username << "\nPassword: " << password << endl;
    }
};

class Shop {
private:
    vector<Product> products;
    vector<User> users;

public:
    void addProduct(Product p) { products.push_back(p); }
    void registerUser(User u) { users.push_back(u); }
    
    bool isUserExists(const string& username) {
        for (const auto& user : users) {
            if (user.getUsername() == username) {
                return true;
            }
        }
        return false;
    }

    User* getUserByUsername(const string& username) {
        for (auto& user : users) {
            if (user.getUsername() == username) {
                return &user;
            }
        }
        return nullptr;
    }

    void viewProducts() {
        cout << "Available Products:\n";
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i << ". ";
            products[i].displayProduct();
            cout << endl;
        }
    }
    
    vector<Product>& getProducts() { return products; }
};

// Menu function to display options and get user input
void displayMenu() {
    cout << "\n----- Menu -----\n";
    cout << "1. View Account Info\n";
    cout << "2. Check Cart\n";
    cout << "3. Add Product to Cart\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Shop shop;
    shop.addProduct(Product("Laptop", 1000.00, 5, "High performance laptop"));
    shop.addProduct(Product("Phone", 500.00, 10, "Latest smartphone"));
    shop.addProduct(Product("Tablet", 300.00, 7, "Portable tablet with pen support"));

    User* currentUser = nullptr;  // Pointer to current user
    string username, password;
    cout << "Welcome to the Online Shop!\n";

    // User login or registration
    while (!currentUser) {
        cout << "Enter your username: ";
        cin >> username;

        if (shop.isUserExists(username)) {
            cout << "Enter your password: ";
            cin >> password;

            currentUser = shop.getUserByUsername(username);
            if (currentUser && currentUser->login(password)) {
                cout << "Login successful!" << endl;
            } else {
                cout << "Invalid password. Please try again.\n";
                currentUser = nullptr;
            }
        } else {
            cout << "Username not found. Would you like to create an account? (yes/no): ";
            string response;
            cin >> response;

            if (response == "yes") {
                cout << "Enter a new username: ";
                cin >> username;
                cout << "Enter a new password: ";
                cin >> password;
                shop.registerUser(User(username, password));
                currentUser = shop.getUserByUsername(username);  // Now log in with the new user
                cout << "Account created successfully! You are now logged in.\n";
            } else {
                cout << "Exiting the program. Please come back later to register.\n";
                return 0; // Exit if the user chooses not to create an account
            }
        }
    }

    // Menu-driven interface after login
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:  // View Account Info
                currentUser->displayAccountInfo();
                break;

            case 2:  // Check Cart
                currentUser->viewCart();
                break;

            case 3:  // Add Product to Cart
                shop.viewProducts();
                cout << "Select a product to add to cart (by index): ";
                int index;
                cin >> index;

                if (index >= 0 && index < shop.getProducts().size()) {
                    currentUser->addToCart(shop.getProducts()[index]);
                } else {
                    cout << "Invalid product index." << endl;
                }
                break;

            case 4:  // Exit
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}


