#ifndef BRAZOROBOTICO_H
#define BRAZOROBOTICO_H

class BrazoRobotico{
	private:
		double x, y, z;
		bool sujetar;
		
	public:
                //constructor
		BrazoRobotico(double x, double y, double z, bool sujetar);
		
		//consultor (1 por atributo)
		double getX();
		double getY();
		double getZ();
		
		bool getSujetar();

                //métodos
		void coger();
		void soltar();
		void mover(double x, double y, double z);
};

#endif
