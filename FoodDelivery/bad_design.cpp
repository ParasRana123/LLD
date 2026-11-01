#include <bits/stdc++.h>
using namespace std;

class OrderManager {
    public:
        string status;
        string paymentMethod;
        string deliveryMethod;
        unordered_map<string , int> menuItems;
        double amount;
        OrderManager(unordered_map<string , int> items) {
            menuItems = items;
        }

        void placeOrder() {
            cout << "Order placed successfully!" << endl;
            status = "CREATED";
        }

        void calculateTotal(vector<string> &ordereditems) {
            int total = 0;
            for(int i = 0 ; i < ordereditems.size() ; i++) {
                total += menuItems[ordereditems[i]];
            }
            cout << "Total amount to be paid: " << total << endl;
            amount = total;
        }

        void calculateDiscount() {
            if(amount > 2000) {
                cout << "Discount of 10% applied!" << endl;
                amount = amount - (amount * 0.1);
            } else if(amount > 5000) {
                cout << "Discount of 20% applied!" << endl;
                amount = amount - (amount * 0.2);
            }
        }

        void makePayment(string method) {
            if(method == "COD") {
                cout << "Using cash on delivery" << endl;
            } else if(method == "CARD") {
                cout << "Using credit card" << endl;
            } else if(method == "UPI") {
                cout << "Using UPI" << endl; 
            }
            paymentMethod = method;
        }

        void deliverOrder(string method) {
            if(method == "HOME") {
                cout << "Delivering to home" << endl;
            } else if(method == "PICKUP") {
                cout << "Order ready for pickup" << endl;
            }
            deliveryMethod = method;
        }

        void assignDeliveryBoy(string name) {
            cout << "Delivery boy assigned: " << name << endl;
        }
};