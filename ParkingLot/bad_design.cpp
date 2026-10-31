#include <bits/stdc++.h>
using namespace std;

class ParkingLot {
    public:
        vector<string> floors;
        vector<string> spots;
        vector<string> vehicles;
        vector<string> tickets;

        void parkVehicle(string vehicleType , string vehicleNumber) {
            int spotIdx = -1;
            for(int i = 0 ; i < spots.size() ; i++) {
                if(spots[i] == "EMPTY") {
                    spotIdx = i;
                    break;
                }
            }
            if(spotIdx == -1) {
                cout << "Parking Lot full" << endl;
                return;
            }
            if(vehicleType == "Bike") {
                spots[spotIdx] = vehicleNumber;
            } else if(vehicleType == "Car") {
                spots[spotIdx] = vehicleNumber;
            } else if(vehicleType == "Truck") {
                spots[spotIdx] = vehicleNumber;
            }
            string ticket = vehicleNumber + "__ticket";
            tickets.push_back(ticket);
            vehicles.push_back(vehicleNumber);
            cout << "Vehicle Parked";
        }

        void exitVehicle(string vehicleNumber , string paymentType , int hours) {
            int amount = 0;
            if(vehicleNumber.find("Car") != string::npos) {
                amount = hours * 50;
            } else if(vehicleNumber.find("Bike") != string::npos) {
                amount = hours * 20;
            } else {
                amount = hours * 80;
            }
            if(paymentType == "UPI") {
                cout << "UPI payment";
            } else if(paymentType == "Card") {
                cout << "Card payment";
            } else if(paymentType == "Cash") {
                cout << "Cash payment";
            }
            for(int i = 0 ; i < spots.size() ; i++) {
                if(spots[i] == vehicleNumber) {
                    spots[i] = "EMPTY";
                    breaks;
                }
            }
            cout << "Vehicle exited";
        }

        void addFloors() {
            // add floors
        }

        void addSpot() {
            // add spot
        }
};