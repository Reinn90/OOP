#include <cmath>
#include <iostream>

using namespace std;

void getDistances(float &width, float &dist) {
    do {
        cout << "Please enter the width of the river (in km): ";
        cin >> width;
        width = width * 1000; // convert to meters

        cout << "And the distance of the factory downstream (in km): ";
        cin >> dist;
        dist = dist * 1000; // convert to meters
    } while (width < 0 || dist < 0);
}

void getPowerLineCost(float &underWaterCost, float &overLandCost) {
    do {
        cout << "Please enter the unit cost of laying the power line "
                "underwater: ";
        cin >> underWaterCost;
        cout << "Please enter the unit cost of laying the power line over "
                "land: ";
        cin >> overLandCost;
    } while (underWaterCost <= 0 || overLandCost <= 0);
}

float calcUnderwaterCost(float riverWidth, int factoryDistance,
                         float underwaterLineCost) {

    float underWaterLine =
        sqrt(riverWidth * riverWidth + factoryDistance * factoryDistance);
    return underWaterLine * underwaterLineCost;
}

int main() {

    float w, d;
    float uwCost, olCost, uwLineCost, olLineCost, totalCost;
    double minCost = 10000000000000;
    int bestLandDist = 0;

    // Objective: Output how long under water
    // and how long over land to achieve MIN cost.

    // get user input for distances and cost
    getDistances(w, d);               // a & b)
    getPowerLineCost(uwCost, olCost); // c & d

    cout << "\n##### User input #####" << endl;
    cout << "River width: " << w << " meters." << endl;
    cout << "Distance of Factory: " << d << " meters." << endl;
    cout << "Underwater Laying Cost: $" << uwCost << "/meter." << endl;
    cout << "Over land Laying Cost: $" << olCost << "/meter." << endl;

    for (int x = 0; x <= (int)d; x++) {
        uwLineCost = calcUnderwaterCost(w, x, uwCost);

        olLineCost = (d - x) * olCost;

        totalCost = uwLineCost + olLineCost;

        // if a smaller total is found, record it and print to console
        if (totalCost < minCost) {
            minCost = totalCost;
            bestLandDist = x;
        }
    }

    float bestUWDist = sqrt(bestLandDist * bestLandDist + w * w);

    cout << "Best Over Land distance is: " << d - bestLandDist << " meters."
         << endl;
    cout << "Best Underwater distance is: " << bestUWDist << " meters." << endl;
    cout << "Minimum Total Cost: $" << minCost << endl;

    return 0;
}
