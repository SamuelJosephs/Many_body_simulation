#ifndef VECTOR
#include "Vector.cpp"
#define VECTOR
#endif

#ifndef stdVector
#include<vector>
#define stdVector
#endif

#ifndef MATH
#define MATH
#include <math.h>
#endif
template<typename T>
class star {
	public:
	Vec3<T> pos;
	Vec3<T> vel;
	T mass;
	int R;
	int G;
	int B;

	star(T m, Vec3<T> position, Vec3<T> velocity): mass(m), vel(velocity),pos(position),R(0xFF),G(0xFF),B(0xFF){};
	star():mass(0),vel(0),pos(0){};

	void update(std::vector<star<T>> stars,int index){
		Vec3<T> acceleration(0,0,0);
		for (int n = 0; n < stars.size();n++){
			if (n == index){
				continue;
			}

			star<T> *i = &stars[n];

			Vec3<T> r(
				i->pos.getx() - this->pos.getx(),
				i->pos.gety() - this->pos.gety(),
				i->pos.getz() - this->pos.getz()
			);
			Vec3<T> rsquared(
				r.getx()*r.getx(),
				r.gety()*r.gety(),
				r.getz()*r.getz()
			);

			acceleration += ((i->mass) / rsquared.abs()) * r;

			// Vec3<T> rsquared_reciprocal(1/rxsquared,1/rysquared,1/rzsquared);
			// acceleration += rsquared_reciprocal;
		}
		
		this->vel += acceleration;
		this-> pos += this->vel;

	}

	void setmass(T input){
		this->mass = input;
	}

	void setRGB(int red, int green, int blue){
		this->R = red;
		this->G = green;
		this->B = blue;
	}



};

