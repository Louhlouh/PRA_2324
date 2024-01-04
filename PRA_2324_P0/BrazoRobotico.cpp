#include "BrazoRobotico.h"

//constructor
BrazoRobotico::BrazoRobotico(double x, double y, double z, bool sujetar){
	this->x = x;
	this->y = y;
	this->z = z;
	this->sujetar = sujetar; 
}
		
//consultor (1 por atributo)
double BrazoRobotico::getX(){
	return x;
}
		
double BrazoRobotico::getY(){
	return y;
}
		
double BrazoRobotico::getZ(){
	return z;
}
		
bool  BrazoRobotico::getSujetar(){
	return sujetar;
}
		
//métodos
		
void  BrazoRobotico::coger(){
	sujetar = true;
}

void BrazoRobotico::soltar(){
	sujetar = false;
}

void BrazoRobotico::mover(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}
