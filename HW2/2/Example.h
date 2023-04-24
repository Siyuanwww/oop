#ifndef __EXAMPLE__
#define __EXAMPLE__

class Example {
private:
	static int cnt;
	int id, dat;
public:
	Example(int data);
	void getData();
	~Example();
};

#endif