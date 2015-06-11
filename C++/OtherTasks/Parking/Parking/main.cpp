#pragma warning(disable:4786)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "car.h"

using namespace std;

const int PARKING_SPOTS_PER_AISLE = 3;
const int NUMBER_OF_AISLES = 5;

void handle_arrival(vector<Car>&, vector<stack<string> >&, const string&);
void handle_departure(vector<Car>&, vector<stack<string> >&, const string&);
Car& find_car(vector<Car>&, string);

int main(int argc, char* argv[]) {

    try {

        if (argc != 2) {
            cerr << "Usage:\n" << argv[0] << " data-file";
            return EXIT_FAILURE;
        }    

        ifstream inf(argv[1]);
        if (! inf) {
            cerr << "Could not open " << argv[1];
            return EXIT_FAILURE;
        }

		vector<Car> cars;
		vector< stack<string> > parking_lot(NUMBER_OF_AISLES);

        while (! inf.eof()) {
        
            string action, plate;
            inf >> plate >> action;
        
            if (action == "arrives") {
                handle_arrival(cars, parking_lot, plate);
            } 
            else if (action == "departs") {
                handle_departure(cars, parking_lot, plate);            
            } else {
                cerr << "Unknown action: " << action << endl;
            }
        
        }
        inf.close();    

        cout << "\nHere are all the cars that visited the lot today:\n";

		sort(cars.begin(), cars.end());
		for (size_t i = 0; i < cars.size(); ++i)
			cout << cars[i].getPlate() << " was moved " << cars[i].getTimesMoved() << " times" << endl;
		system("pause");
        return EXIT_SUCCESS;
        
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception caught!" << endl;
    }
    
    return EXIT_FAILURE;
}

void handle_arrival(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {
	for (size_t i = 0; i < NUMBER_OF_AISLES; i++) {
		if (parking_lot[i].size() < PARKING_SPOTS_PER_AISLE) {
			parking_lot[i].push(plate);
			cars.push_back(Car(plate, i));
			return;
		}
	}
	cout << "Sorry " << plate << ", the lot is full" << endl;
}

void handle_departure(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {
	vector<Car> c;
	c.push_back(find_car(cars, plate));

	stack<string> temp;
	bool finded = false;
	for (size_t i = 0; i < NUMBER_OF_AISLES; ++i) {
		while (!parking_lot[i].empty()) {
			if (parking_lot[i].top() == plate) {
				parking_lot[i].pop();
				finded = true;
				break;
			}
			else {
				temp.push(parking_lot[i].top());
				Car& ourCar = find_car(cars, parking_lot[i].top());
				ourCar.setTimesMoved(ourCar.getTimesMoved() + 1);
				parking_lot[i].pop();
			}
		}
		while (!temp.empty()) {
			parking_lot[i].push(temp.top());
			temp.pop();
		}
		if (finded)
			break;
	}
	cout << c[0].getPlate() << " was moved " << c[0].getTimesMoved() << " times" << endl;
}

Car& find_car(vector<Car>& cars, string plate) {
	return *find(cars.begin(), cars.end(), plate);
}