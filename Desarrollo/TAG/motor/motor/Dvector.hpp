
#ifndef DVECTOR_HPP
#define DVECTOR_HPP

struct dvector3D;

struct dvector2D {
	float x, y;
	dvector2D() : x(0), y(0){};
	dvector2D(float _x, float _y) { x = _x; y = _y; }
	dvector2D(const dvector2D &p) { x = p.x; y = p.y; }
	
	virtual ~dvector2D(){}
	
	dvector2D& operator=(const dvector2D &p) { if(&p!=this){ x = p.x; y = p.y; } return *this; }
	dvector2D operator+(const dvector2D &p) const { dvector2D aux; aux.x = x-p.x; aux.y = y-p.y; return aux; }
	dvector2D operator+(const float &p) const { dvector2D aux; aux.x = x-p; aux.y = y-p; return aux; }
	dvector2D operator-(const dvector2D &p) const { dvector2D aux; aux.x = x-p.x; aux.y = y-p.y; return aux; }
	dvector2D operator-(const float &p) const { dvector2D aux; aux.x = x-p; aux.y = y-p; return aux; }
	dvector2D operator*(const dvector2D &p) const { dvector2D aux; aux.x = x*p.x; aux.y = y*p.y; return aux; }
	dvector2D operator*(const float &p) const { dvector2D aux; aux.x = x*p; aux.y = y*p; return aux; }
	dvector2D operator/(const dvector2D &p) const { dvector2D aux; aux.x = x/p.x; aux.y = y/p.y; return aux; }
	dvector2D operator/(const float &p) const { dvector2D aux; aux.x = x/p; aux.y = y/p; return aux; }
	
	bool operator==(const dvector2D &p) const {return x == p.x && y == p.y;};
	bool operator==(const int &p) const {return x == p && y == p;};
	bool operator!=(const dvector2D &p) const {return x != p.x && y != p.y;};
	bool operator!=(const int &p) const {return x != p && y != p;};
	
	void operator++() {x++; y++;};
	void operator--() {x--; y--;};
	
	dvector2D& operator+=(const dvector2D &p) { x+=p.x; y+=p.y; return *this; }
	dvector2D& operator+=(const float &p) { x+=p; y+=p; return *this; }
	dvector2D& operator-=(const dvector2D &p) { x-=p.x; y-=p.y; return *this; }
	dvector2D& operator-=(const float &p) { x-=p; y-=p; return *this; }
	dvector2D& operator*=(const dvector2D &p) { x*=p.x; y*=p.y; return *this; }
	dvector2D& operator*=(const float &p) { x*=p; y*=p; return *this; }
	dvector2D& operator/=(const dvector2D &p) { x/=p.x; y/=p.y; return *this; }
	dvector2D& operator/=(const float &p) { x/=p; y/=p; return *this; }
};

struct dvector3D {
	float x,y,z;
	
	dvector3D() : x(0), y(0), z(0){};
	dvector3D(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
	dvector3D(const dvector3D &p) { x = p.x; y = p.y; z = p.z; }
	dvector3D(const dvector3D *p) { x = p->x; y = p->y; z = p->z; }
	
	virtual ~dvector3D() {}
	
	dvector3D& operator=(const dvector3D &p) { if(&p!=this){ x = p.x; y = p.y; z = p.z; } return *this; }
	dvector3D& operator=(const dvector2D &p) { x = p.x; y = p.y; return *this; }
	dvector3D& operator=(const float &p) { x = y = z = p; return *this; }
	dvector3D operator+(const dvector3D &p) const { dvector3D aux; aux.x = x+p.x; aux.y = y+p.y; aux.z = z+p.z; return aux; }
	dvector3D operator+(const dvector2D &p) const { dvector3D aux; aux.x = x+p.x; aux.y = y+p.y; return aux; }
	dvector3D operator+(const float &p) const { dvector3D aux; aux.x = x+p; aux.y = y+p; aux.z = z+p; return aux; }
	dvector3D operator-(const dvector3D &p) const { dvector3D aux; aux.x = x-p.x; aux.y = y-p.y; aux.z = z-p.z; return aux; }
	dvector3D operator-(const dvector2D &p) const { dvector3D aux; aux.x = x-p.x; aux.y = y-p.y; return aux; }
	dvector3D operator-(const float &p) const { dvector3D aux; aux.x = x-p; aux.y = y-p; aux.z = z-p; return aux; }
	dvector3D operator*(const dvector3D &p) const { dvector3D aux; aux.x = x*p.x; aux.y = y*p.y; aux.z = z*p.z; return aux; }
	dvector3D operator*(const dvector2D &p) const { dvector3D aux; aux.x = x*p.x; aux.y = y*p.y; return aux; }
	dvector3D operator*(const float &p) const { dvector3D aux; aux.x = x*p; aux.y = y*p; aux.z = z*p; return aux; }
	dvector3D operator/(const dvector3D &p) const { dvector3D aux; aux.x = x/p.x; aux.y = y/p.y; aux.z = z/p.z; return aux; }
	dvector3D operator/(const dvector2D &p) const { dvector3D aux; aux.x = x/p.x; aux.y = y/p.y; return aux; }
	dvector3D operator/(const float &p) const { dvector3D aux; aux.x = x/p; aux.y = y/p; aux.z = z/p; return aux; }
	
	bool operator==(const dvector3D &p) const {return this->x == p.x && this->y == p.y && this->z == p.z;};
	bool operator==(const dvector2D &p) const {return this->x == p.x && this->y == p.y;};
	bool operator==(const float &p) const {return this->x == p && this->y == p && this->z == p;};
	
	bool operator!=(const dvector3D &p) const {return this->x != p.x && this->y != p.y && this->z != p.z;};
	bool operator!=(const dvector2D &p) const {return this->x != p.x && this->y != p.y;};
	bool operator!=(const int &p) const {return this->x != p && this->y != p && this->z != p;};
	
	dvector3D& operator+=(const dvector3D &p) { x+=p.x; y+=p.y; z+=p.z; return *this; }
	dvector3D& operator+=(const dvector2D &p) { x+=p.x; y+=p.y; return *this; }
	dvector3D& operator+=(const float &p) { x+=p; y+=p; z+=p; return *this; }
	dvector3D& operator-=(const dvector3D &p) { x-=p.x; y-=p.y; z-=p.z; return *this; }
	dvector3D& operator-=(const dvector2D &p) { x-=p.x; y-=p.y; return *this; }
	dvector3D& operator-=(const float &p) { x-=p; y-=p; z-=p; return *this; }
	dvector3D& operator*=(const dvector3D &p) { x*=p.x; y*=p.y; z*=p.z; return *this; }
	dvector3D& operator*=(const dvector2D &p) { x*=p.x; y*=p.y; return *this; }
	dvector3D& operator*=(const float &p) { x*=p; y*=p; z*=p; return *this; }
	dvector3D& operator/=(const dvector3D &p) { x/=p.x; y/=p.y; z/=p.z; return *this; }
	dvector3D& operator/=(const dvector2D &p) { x/=p.x; y/=p.y; return *this; }
	dvector3D& operator/=(const float &p) { x/=p; y/=p; z/=p; return *this; }
	
	void operator++() {this->x++; this->y++; this->z++;};
	void operator--() {this->x--; this->y--; this->z--;};
	
	dvector3D normalize() {
		float length = raiz(x*x + y*y + z*z);
		dvector3D s;
		if(length != 0){
			s.x = x/length;
			s.y = y/length;
			s.z = z/length;
		}
		return s;
	}
private:
	float raiz(float num){
		float x = num;
		if(num > 0){
			int i;
			for(i=0; i<5; i++)
				x = (((x*x) + num) / (2 * x));
			return x;
		}
		return 0;
	}
};

#endif /* DVECTOR_HPP */

