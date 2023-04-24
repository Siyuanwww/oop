#include <vector>
#include <string>
using namespace std;

class Farm {
private:
    int n;
    std::vector<Cow> cows;
    std::vector<int> supp;
    std::vector<int> meal;
    static double sum;

public:
    Farm(int n) : n(n) {
        supp.resize(n, 0);
        meal.resize(n, 0);
    }
    void addCow(const Cow &cow) {
        cows.push_back(cow);
    }
    void supply(const string &name, int a) {
        for (int i = 0; i < n; i++) {
            if (cows[i].name == name) {
                supp[i] += a;
                break;
            }
        }
    }
    void startMeal() {
        for (int i = 0; i < n; i++) {
            meal[i] = std::min(supp[i], cows[i].u);
            supp[i] -= meal[i];
        }
    }
    void produceMilk() {
        for (int i = 0; i < n; i++) {
            if (meal[i] >= cows[i].l) {
                sum += cows[i].m;
            } else if (meal[i] > 0) {
                sum += cows[i].m / 2.0;
            }
        }
    }
    double getMilkProduction() {
        return sum;
    }
};

double Farm::sum = 0;