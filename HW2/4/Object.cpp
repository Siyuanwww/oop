#include "Splash.h"
#include "Object.h"

int Object::act_water(Direction fromwhere, Actor fromwho) {
	if (fromwho == PLAYER || fromwho == WATER) {
		size++;
	} else {
		size--;
	}
	if (size == 0) {
		set2void(x, y, splash);
		return 0;
	} else if (size > 3) {
		set2void(x, y, splash);
		int ans = 1;
		if (x > 0) {
			ans += splash->map[x - 1][y]->act(UP, WATER);
		}
		if (x + 1 < splash->size) {
			ans += splash->map[x + 1][y]->act(DOWN, WATER);
		}
		if (y > 0) {
			ans += splash->map[x][y - 1]->act(LEFT, WATER);
		}
		if (y + 1 < splash->size) {
			ans += splash->map[x][y + 1]->act(RIGHT, WATER);
		}
		return ans;
	} else {
		return 0;
	}
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	if (fromwho == PLAYER) {
		std::cout << "Error: Cannot act a Void.\n";
		return 0;
	}
	if (fromwhere == UP && x > 0) {
		return splash->map[x - 1][y]->act(UP, fromwho);
	} else if (fromwhere == DOWN && x + 1 < splash->size) {
		return splash->map[x + 1][y]->act(DOWN, fromwho);
	} else if (fromwhere == LEFT && y > 0) {
		return splash->map[x][y - 1]->act(LEFT, fromwho);
	} else if (fromwhere == RIGHT && y + 1 < splash->size) {
		return splash->map[x][y + 1]->act(RIGHT, fromwho);
	} else {
		return 0;
	}
}

int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	if (fromwho == PLAYER) {
		std::cout << "Error: Cannot act a Barrier.\n";
	}
	return 0;
}

int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	if (fromwho == PLAYER || fromwho == TOXIC) {
		size++;
	} else {
		size--;
	}
	if (size == 0) {
		set2void(x, y, splash);
		return 0;
	} else if (size > 3) {
		set2void(x, y, splash);
		int ans = -1;
		if (x > 0) {
			ans += splash->map[x - 1][y]->act(UP, TOXIC);
		}
		if (x + 1 < splash->size) {
			ans += splash->map[x + 1][y]->act(DOWN, TOXIC);
		}
		if (y > 0) {
			ans += splash->map[x][y - 1]->act(LEFT, TOXIC);
		}
		if (y + 1 < splash->size) {
			ans += splash->map[x][y + 1]->act(RIGHT, TOXIC);
		}
		return ans;
	} else {
		return 0;
	}
}