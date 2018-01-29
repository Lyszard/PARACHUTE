#pragma once
#include "Spring.h"
#include "ofMain.h"
#include <vector>

class RopeSystem : public ofBaseApp{

	public:
		RopeSystem();
		~RopeSystem();
		void update();
		void draw();
		vector<Spring*> ropes;
	private:
};
