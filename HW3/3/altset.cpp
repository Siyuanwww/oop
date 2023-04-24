#include "altset.h"

Altset::Altset() {}
Altset::Altset(const char *data, int len) {
    gene.resize(len, 0);
    for (int i = 0; i < len; i++) {
        gene[i] = data[len - i - 1] - '0';
    }
}
Altset& Altset::operator = (const Altset &altset) {
    gene = altset.gene;
    return *this;
}
Altset& Altset::operator = (Altset &&altset) {
    gene = std::move(altset.gene);
    return *this;
}
void Altset::inverse(int index) {
    gene[index] ^= 1;
}
void Altset::append(int value) {
    gene.emplace_back(value);
}
bool Altset::get(int index) const {
    return gene[index];
}
bool Altset::empty() const {
    return gene.empty();
}
int Altset::count() const {
    int cnt = 0;
    for (auto x : gene) {
        cnt += x == 1;
    }
    return cnt;
}