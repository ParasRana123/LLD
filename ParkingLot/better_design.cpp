#include <bits/stdc++.h>
using namespace std;

enum class VehicleType {
    MOTORCYCLE,
    CAR,
    TRUCK
};

enum class SpotType {
    MOTORCYCLE,
    CAR,
    TRUCK
};

class Vehicle {
    protected:
        string regNo;
        VehicleType type;
    public:
        Vehicle(string number , VehicleType t) {
            regNo = number;
            type = t;
        }

        string getRegNo() const {
            return regNo;
        }

        VehicleType getVehicleType() const {
            return type;
        }
};

class Motorcycle: public Vehicle {
    public:
        Motorcycle(string number) : Vehicle(number , VehicleType::MOTORCYCLE) {};
};

class Car: public Vehicle {
    public:
        Car(string number) : Vehicle(number , VehicleType::CAR) {};
};

class Truck: public Vehicle {
    public:
        Truck(string number) : Vehicle(number , VehicleType::TRUCK) {};
};

// Now this design will satisfy OCP now because we can add another
// class called ElectricVehicle which again can get inherited from the Vehicle
// class itself

class ParkingSpot {
    private:
        int id;
        SpotType type;
        bool occupied;
        Vehicle* vehicle;
    public:
        ParkingSpot(int id , SpotType t) {
            id = id;
            type = t;
            occupied = false;
            vehicle = nullptr;
        }

        bool isAvailable() const {
            return !occupied;
        }

        SpotType getType() const {
            return type;
        }

        bool parkVehicle(Vehicle *v) {
            if(occupied || v == nullptr) return false;
            vehicle = v;
            occupied = true;
            return true;
        }

        void removeVehicle() {
            vehicle = nullptr;
            occupied = false;
        }
};

// We have made the above class just to calculate the spot occupancy 
// and for nothing else

class ParkingFloor {
    private:
        int floorNumber;
        vector<ParkingSpot*> spots;
    public:
        ParkingFloor(int number) {
            floorNumber = number;
        }
        void addSpot(ParkingSpot* spot) {
            spots.push_back(spot);
        }
        vector<ParkingSpot*> &getSpots() {
            return spots;
        }
};

// The above class's work was to add new floors , maintain spots
// in a floor , add spots and the get spots