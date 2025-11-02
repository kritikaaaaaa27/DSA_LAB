#include <iostream>
#include <algorithm>
using namespace std;

class Connection {
public:
    int from;
    int to;
    int cost;
};

class HouseGroup {
public:
    int parent[100];

    void createHouses(int n) {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findMainHouse(int h) {
        if (parent[h] == h)
            return h;
        return parent[h] = findMainHouse(parent[h]);
    }

    void joinHouses(int h1, int h2) {
        int p1 = findMainHouse(h1);
        int p2 = findMainHouse(h2);
        if (p1 != p2)
            parent[p1] = p2;
    }
};

bool sortByCost(Connection a, Connection b) {
    return a.cost < b.cost;
}

int main() {
    int n, e;
    cout << "Pimpri Chinchwad Water Pipeline Layout System\n";
    cout << "--------------------------------------------------\n";
    cout << "Enter number of houses: ";
    cin >> n;
    cout << "Enter number of possible connections: ";
    cin >> e;

    Connection conns[100];
    cout << "\nEnter connection details (House1 House2 Cost):\n";
    for (int i = 0; i < e; i++) {
        cin >> conns[i].from >> conns[i].to >> conns[i].cost;
    }

    sort(conns, conns + e, sortByCost);

    HouseGroup hg;
    hg.createHouses(n);

    int totalCost = 0;
    Connection selected[100];
    int count = 0;

    for (int i = 0; i < e; i++) {
        int h1 = conns[i].from;
        int h2 = conns[i].to;
        int c = conns[i].cost;

        int main1 = hg.findMainHouse(h1);
        int main2 = hg.findMainHouse(h2);

        if (main1 != main2) {
            hg.joinHouses(h1, h2);
            selected[count] = conns[i];
            totalCost += c;
            count++;
        }
    }

    cout << "\nPipelines selected for minimum cost connection:\n";
    for (int i = 0; i < count; i++) {
        cout << "House " << selected[i].from << " connected to House " 
             << selected[i].to << "  (Cost: " << selected[i].cost << ")\n";
    }

    cout << "\nTotal minimum cost to connect all houses: " << totalCost << endl;
    cout << "--------------------------------------------------\n";
    cout << "All houses are now connected efficiently.\n";

    return 0;
}
