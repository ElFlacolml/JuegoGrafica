#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include<stdlib.h>
#include"juego.h"
extern int puntos;
int cuadradoX,cuadradoY;
int largoDeSerpiente=5;
bool comida = true;
int comidaX,comidaY;
short sDireccion =  DERECHA;
extern bool finJuego;
int posX[60]={20,20,20,20,20},posY[60]={20,19,18,17,16};

void  colorCuadricula(int x, int y)//initgrit
{
	
	cuadradoX=x;
	cuadradoY=y;
	
}

void unidad(int,int);
void dibujarCuadrado()
{
	for(int x=0;x<cuadradoX;x++){
		
		for(int y=0;y<cuadradoY;y++)
		{
			unidad(x,y);
		}
	}
	//unidad(20,20);
}
void  unidad (int x,int y) //unit
{
	//glLineWidth(1.0);
	//glColor3f(1.1,1.0,1.0);
	
	if(x==0 || y==0 ||x==cuadradoX-1 || y==cuadradoY-1 ){
		glLineWidth(3.0);
		glColor3f(0.0f, 0.0f, 1.0f); //color del borde
	}
	else{
		//	glLineWidth(1.0);
		glColor3f(0.0,1.0,1.0); //color del fondo
		
	}
	glBegin(GL_LINE_LOOP);
	glVertex2f(x,y);
	glVertex2f(x+1,y);
	glVertex2f(x+1,y+1);
	glVertex2f(x,y+1);
	glEnd();
} 
void alimento()
{
	if (comida)
		random(comidaX,comidaY);
	comida=false;
	glColor3f(1.0f, 0.0f, 1.0f);//color comida
	glRectd(comidaX,comidaY,comidaX+ 1,comidaY+1);
}

void dibujarCulebra()

{
	for(int i =largoDeSerpiente-1;i>0;i--)
		{
		for(int j=1;j<largoDeSerpiente;j++) 
		{  if(posX[j]==posX[0] && posY[j]==posY[0])  finJuego=true;  
		
		}
		posX[i] =posX[i-1];
		posY[i] =posY[i-1];
		
		}
	if(sDireccion==ARRIBA)
		posY[0]++;
	else if(sDireccion==ABAJO)
		posY[0]--;
	else if(sDireccion == DERECHA)
		posX[0]++;
	else if(sDireccion==IZQUIERDA)
		posX[0]--;
	for(int i=0; i <largoDeSerpiente;i++){
		
		if(i==0)
		{
		glColor3f(0.1,0.0,1.0);	
		}
		else
		   glColor3f(1.0,1.0,1.0);//cuerpo
		   glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);	
	}
	
	if(posX[0]==0 || posX[0]==cuadradoX-1 || posY[0] == 0 || posY[0] ==cuadradoY-1)
	{
		finJuego=true;
	}
	if(posX[0]==comidaX && posY[0]==comidaY)
	{
		puntos++;
		largoDeSerpiente++;
		if(largoDeSerpiente>MAX)
			largoDeSerpiente=MAX;

			comida=true;
	}
}
void random( int &x,int &y)
{
	int _maxX =cuadradoX-2;
	int _maxY =cuadradoY-2;
	int _min = 1;
	srand(time(NULL));
	x =_min + rand() % (_maxX - _min);
	y =_min + rand() % (_maxY - _min);
}
