#include <iostream>
#include <math.h>
template <typename T>
class Vec3 {
	private:
	T x;
	T y;
	T z;
	public:
	T getx(){
		return this->x;
	}
	T gety(){
		return this->y;
	}
	T getz(){
		return this->z;
	}

	void print(){
		std::cout << "x = " << this->x << " y = " << this->y << " z = " << this->z << "\n";
	}

	Vec3(T xIn, T yIn, T zIn): x(xIn), y(yIn), z(zIn){};
	Vec3(): x(0), y(0), z(0){};

	Vec3<T> operator+(Vec3<T> input) {
		Vec3<T> temp(0,0,0);
		temp.x = this->getx() + input.getx();
		temp.y = this->gety() + input.gety();
		temp.z = this->getz() + input.getz();
		return temp;
	}

	void operator+=(Vec3<T> other){
		this->x += other.getx();
		this->y += other.gety();
		this->z += other.getz();
	}
	void operator-=(Vec3<T> other){
		this->x -= other.getx();
		this->y -= other.gety();
		this->z -= other.getz();
	}



	T abs() {
		return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
	}

	void setx(T input){
		this->x = input;
	}
	void sety(T input){
		this->y = input;
	}
	void setz(T input){
		this->z = input;
	}

};

template<typename T>
Vec3<T> operator*(T scalar, Vec3<T> vector ){
	T x = scalar*vector.getx();
	T y = scalar*vector.gety();
	T z = scalar*vector.getz();
	Vec3<T> temp(x, y, z);
	return temp;
}
template<typename T>
Vec3<T> operator*(Vec3<T> vector,T scalar ){
	T x = scalar*vector.getx();
	T y = scalar*vector.gety();
	T z = scalar*vector.getz();
	Vec3<T> temp(x, y, z);
	return temp;
}