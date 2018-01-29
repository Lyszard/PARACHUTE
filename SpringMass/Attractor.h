#pragma once
#include "ofMain.h"
#include "Point.h"
class Attractor
{
	public:
		Attractor(ofVec3f pos, double m);
		void draw();
		ofVec3f CalculateAttraction(Point* a);
		void setG();
		ofVec3f getPos();
		void setMass(double m);

	private:
		ofVec3f position;
		double mass;
		double G;







};