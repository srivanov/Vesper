
#ifndef DVECTOR_HPP
#define DVECTOR_HPP


struct dvector3D {
    float x,y,z;
    dvector3D() : x(0), y(0), z(0){};
	dvector3D(float _x, float _y, float _z);
    dvector3D(const dvector3D &p);
    virtual ~dvector3D();
    dvector3D& operator=(const dvector3D &p);
    dvector3D& operator+(const dvector3D &p);
    dvector3D& operator-(const dvector3D &p);
    dvector3D& operator*(const dvector3D &p);
    dvector3D& operator/(const dvector3D &p);
    bool operator==(const dvector3D &p) const {return this->x == p.x && this->y == p.y && this->z == p.z;};
};

struct dvector2D {
	float x, y;
    dvector2D() : x(0), y(0){};
    dvector2D(float _x, float _y);
	dvector2D(const dvector2D &p);
	virtual ~dvector2D();
	dvector2D& operator=(const dvector2D &p);
	dvector2D& operator+(const dvector2D &p);
	dvector2D& operator-(const dvector2D &p);
	dvector2D& operator*(const dvector2D &p);
	dvector2D& operator/(const dvector2D &p);
	bool operator==(const dvector2D &p) const {return this->x == p.x && this->y == p.y;};
};

#endif /* DVECTOR_HPP */

