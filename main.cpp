#include<GL/gl.h>
#include<Gl/glut.h>
#include"juego.h"
#include<stdlib.h> 
#include <string>
#include<iostream>
#define COLUMNAS 40 
#define  FILA 40
#define FPS 10
extern short sDireccion;
bool finJuego = false;
int puntos=0;
void llamadaTiempo(int);
void llamadaMonitor();
void llamadaRemodelado(int,int);
void llamadaTeclado(int,int,int);


void color()
{
	glClearColor(0.0,0.0,0.0,1.0);
	colorCuadricula(COLUMNAS,FILA);
}
main(int argc,char **argv){
	
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//iniciando modo de visualizacion
	glutInitWindowSize(500,500);// posicionamiento de la ventana
	glutCreateWindow("culebrita de tomas");//Nombre de la ventana
	glutDisplayFunc(llamadaMonitor);
	glutReshapeFunc(llamadaRemodelado);
	glutTimerFunc(0,llamadaTiempo,0);
	glutSpecialFunc(llamadaTeclado);
	color();
	glutMainLoop();
	
	return 0;
	
}
	
	void llamadaMonitor()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		dibujarCuadrado();
		dibujarCulebra();
		alimento();
		glutSwapBuffers();
		if(finJuego)
		{
			char _puntos[10];
		   
			char texto[50]= "tus reales puntos :";
			strcat(texto,_puntos);
			MessageBox(NULL,texto,"Perdiste P' chamo",0);
			exit(0);
		}
		
		
	}
	
	void llamadaRemodelado(int ancho,int largo)
	{
		glViewport(0,0,(GLsizei)ancho,(GLsizei)largo);//definiendo las coordenadas
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0,COLUMNAS,0.0,FILA,-1.0,1.0);
		glMatrixMode(GL_MODELVIEW);
	}
	void llamadaTiempo(int){
		
		glutPostRedisplay();
		glutTimerFunc(1000/FPS,llamadaTiempo,0);
	}
		void llamadaTeclado(int tecla ,int,int){
			
			switch(tecla)
			{
			case GLUT_KEY_UP:
				if(sDireccion!=ABAJO)
					sDireccion=ARRIBA;
				break;
			case GLUT_KEY_DOWN:
				if(sDireccion!=ARRIBA)
					sDireccion=ABAJO;
				break;
			case GLUT_KEY_RIGHT:
				if(sDireccion!= IZQUIERDA)
					sDireccion=DERECHA;
				break;
				
			case GLUT_KEY_LEFT:
				if(sDireccion!=DERECHA)
					sDireccion=IZQUIERDA;
				break;
				
			}
			
		}

