#include<GL/glut.h>
#include<stdlib.h>

void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.); //Cor de fundo 
	gluOrtho2D(-250.0f,250.0f,-250.0f,250.0f); //posilçao da imagem

}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT); //limpa janela
	glColor3f(1.0, 0.0, 1.0); //cor da linha 

	glLineWidth(10.0);
		glBegin(GL_POLYGON);
		glVertex2f(1.0,0.0); 
		glVertex2f(1.0,60.0); //pontos
		glColor3f(1.0, 0.5, 0.0);//pontos
		glVertex2f(80.0,60.0); //pontos
		glVertex2f(80.0,20.0); //pontos
		glVertex2f(80.0,0.0); //pontos
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
	glutCreateWindow("Desenhando Poligono");

	init();

	glutDisplayFunc(display);  //Redesenha o GLUT
	glutKeyboardFunc(keyboard);  //Função do teclado
	glutMainLoop();  //Mostra as janelas criadas

return 0 ;

}
