//
//  Pila.hpp
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 17/2/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef Pila_h
#define Pila_h

#include <stack>
#include <glm/glm.hpp>

class Pila{
public:
	static Pila* Instance(){
		static Pila pinstance;
		return &pinstance;
	}
	virtual ~Pila(){}
	
	void push(glm::mat4 &m){
		pila.push(m);
	}
	
	glm::mat4* pop(){
		glm::mat4* p = &pila.top();
		pila.pop();
		return p;
	}
	
	glm::mat4* top(){
		return &pila.top();
	}
	
	void calculaMVP(){
		MVP = mProjection * mView * actual;
	}
	
	void activateClipping(bool p){
		clipping = p;
	}
	
	bool getClippingState(){
		return clipping;
	}
	
	void calculoFrustum(){
		if(clipping){
			float mat[16]; // Modelview-projection matrix
			glm::vec4 l,r,b,t,n,f; // Frustum-planes
			
			// Code to fill the modelview-projection matrix
			for (int i=0; i<16; i+=4) {
				int h = i/4;
				mat[i] = MVP[h].x;
				mat[i+1] = MVP[h].y;
				mat[i+2] = MVP[h].z;
				mat[i+3] = MVP[h].w;
			}
			
			// Left Plane
			// col4 + col1
			l.x = mat[3]  + mat[0];
			l.y = mat[7]  + mat[4];
			l.z = mat[11] + mat[8];
			l.w = mat[15] + mat[12];
			
			// Right Plane
			// col4 - col1
			r.x = mat[3]  - mat[0];
			r.y = mat[7]  - mat[4];
			r.z = mat[11] - mat[8];
			r.w = mat[15] - mat[12];
			
			// Bottom Plane
			// col4 + col2
			b.x = mat[3]  + mat[1];
			b.y = mat[7]  + mat[5];
			b.z = mat[11] + mat[9];
			b.w = mat[15] + mat[13];
			
			// Top Plane
			// col4 - col2
			t.x = mat[3]  - mat[1];
			t.y = mat[7]  - mat[5];
			t.z = mat[11] - mat[9];
			t.w = mat[15] - mat[13];
			
			// Near Plane
			// col4 + col3
			n.x = mat[3]  + mat[2];
			n.y = mat[7]  + mat[6];
			n.z = mat[11] + mat[10];
			n.w = mat[15] + mat[14];
	  
			// Far Plane
			// col4 - col3
			f.x = mat[3]  - mat[2];
			f.y = mat[7]  - mat[6];
			f.z = mat[11] - mat[10];
			f.w = mat[15] - mat[14];
			
			frustum[0] = l; frustum[1] = r; frustum[2] = b;
			frustum[3] = t;	frustum[4] = n;	frustum[5] = f;
		}
	}
	
	// false if fully outside, true if inside or intersects
	bool AABB_Frustum_Test(glm::vec3 const & mMin, glm::vec3 const & mMax)
	{
		if(!clipping)
			return true;
		// check box outside/inside of frustum
		for( int i=0; i<6; i++ )
		{
			int out = 0;
			out += ((glm::dot( frustum[i], glm::vec4(mMin.x, mMin.y, mMin.z, 1.0f) ) < 0.0 ) ? 1:0);
			out += ((glm::dot( frustum[i], glm::vec4(mMax.x, mMin.y, mMin.z, 1.0f) ) < 0.0 ) ? 1:0);
			out += ((glm::dot( frustum[i], glm::vec4(mMin.x, mMax.y, mMin.z, 1.0f) ) < 0.0 ) ? 1:0);
			out += ((glm::dot( frustum[i], glm::vec4(mMax.x, mMax.y, mMin.z, 1.0f) ) < 0.0 ) ? 1:0);
			out += ((glm::dot( frustum[i], glm::vec4(mMin.x, mMin.y, mMax.z, 1.0f) ) < 0.0 ) ? 1:0);
			out += ((glm::dot( frustum[i], glm::vec4(mMax.x, mMin.y, mMax.z, 1.0f) ) < 0.0 ) ? 1:0);
			out += ((glm::dot( frustum[i], glm::vec4(mMin.x, mMax.y, mMax.z, 1.0f) ) < 0.0 ) ? 1:0);
			out += ((glm::dot( frustum[i], glm::vec4(mMax.x, mMax.y, mMax.z, 1.0f) ) < 0.0 ) ? 1:0);
			if( out==8 ) return false;
		}

		// check frustum outside/inside box
		int out;
		out=0; for( int i=0; i<8; i++ ) out += ((frustum[i].x > mMax.x) ? 1:0); if( out==8 ) return false;
		out=0; for( int i=0; i<8; i++ ) out += ((frustum[i].x < mMin.x) ? 1:0); if( out==8 ) return false;
		out=0; for( int i=0; i<8; i++ ) out += ((frustum[i].y > mMax.y) ? 1:0); if( out==8 ) return false;
		out=0; for( int i=0; i<8; i++ ) out += ((frustum[i].y < mMin.y) ? 1:0); if( out==8 ) return false;
		out=0; for( int i=0; i<8; i++ ) out += ((frustum[i].z > mMax.z) ? 1:0); if( out==8 ) return false;
		out=0; for( int i=0; i<8; i++ ) out += ((frustum[i].z < mMin.z) ? 1:0); if( out==8 ) return false;
		return true;
	}
	
	glm::mat4 actual, mView, mProjection, MVP;
protected:
	Pila(){ clipping = true; }
private:
	std::stack<glm::mat4> pila;
	glm::vec4 frustum[6]; // Frustum-planes
	bool clipping;
};

#endif /* Pila_h */
