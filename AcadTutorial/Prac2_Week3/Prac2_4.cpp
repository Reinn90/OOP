#include <cmath>
#include <iostream>

using namespace std;

// const int COST_OVER_LAND = 70;
// const int COST_UNDER_WATER = 95;
const int MAX_FACTORY_DISTANCE = 8000;

void getRiverWidth(float &width) {
    do {
        cout << "Please enter the width of the river (in km): ";
        cin >> width;
        width = width * 1000; // convert to meters
    } while (width < 0);
}

void getFactoryDistance(float &dist) {
    do {
        cout << "Please enter the distance of the factory downstream (in km): ";
        cin >> dist;
        dist = dist * 1000; // convert to meters
    } while (dist < 0);
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

float calcUnderwaterCost(float riverWidth, float factoryDistance,
                         float underwaterLineCost) {
    // Over land line  = 8000 - factoryDistance
    double overLandLine = 8000 - factoryDistance;

    float underWaterLine =
        sqrt(riverWidth * riverWidth + overLandLine * overLandLine);
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
    getRiverWidth(w); // a)
    // getFactoryDistance(d);            // b)
    getPowerLineCost(uwCost, olCost); // c & d

    cout << "River width: " << w << " meters." << endl;
    // cout << "Distance of Factory: " << d << " meters." << endl;
    cout << "Underwater Laying Cost: $" << uwCost << "/meter." << endl;
    cout << "Over land Laying Cost: $" << olCost << "/meter." << endl;

    for (d = 0; d <= 8000; d++) {
        uwLineCost = calcUnderwaterCost(w, d, uwCost);
        // cout << "UWL Cost: $ " << uwLineCost << endl;

        olLineCost = d * olCost;
        // cout << "OLL Cost: $ " << olLineCost << endl;

        totalCost = uwLineCost + olLineCost;
        // cout << "Total Cost: $ " << totalCost << endl << endl;

        // if a smaller total is found, record it and print to console
        if (totalCost < minCost) {
            minCost = totalCost;
            bestLandDist = d;
            // cout << "New minimum total cost is: $" << minCost << endl;
        }
    }

    float bestUWDist;

    int x = MAX_FACTORY_DISTANCE - bestLandDist;

    bestUWDist = sqrt(x * x + w * w);

    cout << "Best Over Land distance is: " << bestLandDist << " meters."
         << endl;
    cout << "Best Underwater distance is: " << bestUWDist << " meters." << endl;
    cout << "Minimum Total Cost: $" << minCost << endl;

    return 0;
}
