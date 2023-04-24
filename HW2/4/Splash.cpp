#include "Splash.h"

void Splash::buildMap() {
	char tmp[5];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cin >> tmp;
			if (tmp[0] == '1' || tmp[0] == '2' || tmp[0] == '3') {
				this->map[i][j] = new Object();
				this->map[i][j]->set2water(tmp[0] - '0', i, j, this);
			}
			else if (tmp[0] == '#') {
				this->map[i][j] = new Object();
				this->map[i][j]->set2void(i, j, this);
			}
			else if (tmp[0] == '*') {
				this->map[i][j] = new Object();
				this->map[i][j]->set2barrier(i, j, this);
			}
			else if (tmp[0] == '-') {
				this->map[i][j] = new Object();
				this->map[i][j]->set2toxic(tmp[1] - '0', i, j, this);
			}
		}
	}
}

void Splash::actAt(int x, int y) {
	Object *obj = map[x][y];
	score += obj->act(NONE, PLAYER);
	if(obj != map[x][y]) delete obj;
	return;
}