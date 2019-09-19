#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14152635898

void init(void){
	glClearColor(1.0, 0.5, 1.5, 1.0); //Cor de fundo 
	gluOrtho2D(-250.0f,250.0f,-250.0f,250.0f); //Posição da figura
}	


void display(void){
	glClear(GL_COLOR_BUFFER_BIT); //limpa janela
	glColor3f(0.0, 0.0, 0.0); //cor da linha 

	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX=200.0f, raioY = 100.0f; // Os raios X e Y definem o tamanho da figura

	glBegin(GL_POLYGON);
		for(int i=0; i<circle_points;i++){
			angle = (2*PI*i)/circle_points;
			glVertex2f(cos(angle)*raioX,sin(angle)*raioY);
		}
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 27:  //Tecla Esc encerra o programa
			exit(0);
			break;
	}
}

//Função Principal
int main (int argc, char** argv){
	glutInit(&argc, argv); //Incializa o glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//Epecifica o sistema de cores 
	glutInitWindowSize(400,350);  //Dimeções da janela
	glutInitWindowPosition(200,100); // Posição das Janelas
	glutCreateWindow("Desenhando Elipse");

	init();

	glutDisplayFunc(display);  //Redesenha o GLUT
	glutKeyboardFunc(keyboard);  //Função do teclado
	glutMainLoop();  //Mostra as janelas criadas

return 0 ;

}
