#include <vector>

class Altset {
    std::vector<int> gene;
public:
    Altset();

    Altset(const char *data, int len);
	Altset& operator = (const Altset &altset);
    Altset& operator = (Altset &&altset);

    void inverse(int index);
    void append(int value);
    bool get(int index) const;
    bool empty() const;
    int count() const;
};
