#pragma once
#include "Point.h"
#include "ofMain.h"
#include "Attractor.h"
#include <vector>
class Spring
{
public:
	Spring(double pos, double len, int pointsQuantity, double springConstant);
	~Spring();

	vector<Point*> getPoints();
	void update(Attractor *att);
	void draw();
	
private:
	double position;
	double length;
	int pointsNumber;
	double springConstant;
	char type;
	double G;
	vector<Point*> points;
	
};

