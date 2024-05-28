#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class BusPark {
private:
    map<int, T> parkBuses;
    map<int, T> routeBuses;

public:
    void addBusToPark(int busNumber, const T& busData) {
        parkBuses.insert(make_pair(busNumber, busData));
    }

    void removeBusFromPark(int busNumber) {
        if (parkBuses.count(busNumber)) {
            routeBuses.insert(make_pair(busNumber, parkBuses[busNumber]));
            parkBuses.erase(busNumber);
        }
    }

    void removeBusFromRoute(int busNumber) {
        if (routeBuses.count(busNumber)) {
            parkBuses.insert(std::make_pair(busNumber, routeBuses[busNumber]));
            routeBuses.erase(busNumber);
        }
    }

    void printBusesByNumber() {
        cout << "Buses in Park (Sorted by Bus Number):" << endl;
        for (const auto& bus : parkBuses) {
            cout << "Bus Number: " << bus.first
                << ", Driver: " << bus.second.driver
                << ", Route: " << bus.second.route << endl;
        }

        cout << "\nBuses on Route (Sorted by Bus Number):" << endl;
        for (const auto& bus : routeBuses) {
            cout << "Bus Number: " << bus.first
                << ", Driver: " << bus.second.driver
                << ", Route: " << bus.second.route << endl;
        }
    }

    void printBusesByRoute() {
        cout << "Buses in Park (Sorted by Route):" << endl;
        vector<pair<int, T>> sortedParkBuses(parkBuses.begin(), parkBuses.end());
        sort(sortedParkBuses.begin(), sortedParkBuses.end(),
            [](const pair<int, T>& a, const pair<int, T>& b) {
                return a.second.route < b.second.route;
            });

        for (const auto& bus : sortedParkBuses) {
            cout << "Bus Number: " << bus.first
                << ", Driver: " << bus.second.driver
                << ", Route: " << bus.second.route << endl;
        }

        cout << "\nBuses on Route (Sorted by Route):" << endl;
        vector<pair<int, T>> sortedRouteBuses(routeBuses.begin(), routeBuses.end());
        sort(sortedRouteBuses.begin(), sortedRouteBuses.end(),
            [](const pair<int, T>& a, const pair<int, T>& b) {
                return a.second.route < b.second.route;
            });

        for (const auto& bus : sortedRouteBuses) {
            cout << "Bus Number: " << bus.first
                << ", Driver: " << bus.second.driver
                << ", Route: " << bus.second.route << endl;
        }
    }
};

struct BusData {
    string driver;
    int route;
};

int main() {
    BusPark<BusData> busPark;
    int option;

    do {
        cout << "\nBus Park Management System\n";
        cout << "1. Add Bus to Park\n";
        cout << "2. Remove Bus from Park\n";
        cout << "3. Remove Bus from Route\n";
        cout << "4. Print Buses (Sorted by Bus Number)\n";
        cout << "5. Print Buses (Sorted by Route)\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
        case 1: {
            int busNumber, route;
            string driver;
            cout << "Enter Bus Number: ";
            cin >> busNumber;
            cout << "Enter Driver Name: ";
            cin >> driver;
            cout << "Enter Route Number: ";
            cin >> route;
            BusData newBus{ driver, route };
            busPark.addBusToPark(busNumber, newBus);
            break;
        }
        case 2: {
            int busNumber;
            cout << "Enter Bus Number to remove from Park: ";
            cin >> busNumber;
            busPark.removeBusFromPark(busNumber);
            break;
        }
        case 3: {
            int busNumber;
            cout << "Enter Bus Number to remove from Route: ";
            cin >> busNumber;
            busPark.removeBusFromRoute(busNumber);
            break;
        }
        case 4:
            busPark.printBusesByNumber();
            break;
        case 5:
            busPark.printBusesByRoute();
            break;
        case 0:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (option != 0);

    return 0;
}