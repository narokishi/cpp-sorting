#include <iostream>

class Model
{
    public:
        int id, property;

        void set(int id, int property)
        {
            this->id       = id;
            this->property = property;
        }
};

int main()
{
    int amount, type, biggest = -1;

    std::cin >> amount;

    if (amount < 0) return 0;

    Model *models = new Model[amount];

    for (int i=0; i < amount; i++) {
        int id, property, bigger;
        std::cin >> id >> property;
        bigger  = id > property ? id : property;
        biggest = biggest > bigger ? biggest : bigger;
        models[i].set(id, property);
    }

    int *counts = new int[biggest+1];

    for (int i=0; i <= biggest; i++) counts[i] = 0;
    for (int i=0; i < amount; i++) counts[models[i].id]++;

    int *indexes = new int[biggest+1];
    indexes[0] = 0;

    for (int i=1; i <= biggest; i++) indexes[i] = indexes[i-1] + counts[i-1];

    delete [] counts;
    Model *response = new Model[amount];

    for (int i=0; i < amount; i++) {
        int id = models[i].id;
        int index = indexes[id]++;
        response[index] = models[i];
    }

    delete [] indexes;
    delete [] models;

    std::cin >> type;

    if (type == 0) for (int i=0; i < amount; i++) std::cout << response[i].id << "\n";
    if (type == 1) for (int i=0; i < amount; i++) std::cout << response[i].id << "," << response[i].property << "\n";

    delete [] response;

    return 0;
}
