#include<stdlib.h>
#include<GL/glut.h>
#include "image.h"
#define TEXTURA_DO_PLANO "Letreiro.sgi"

GLfloat chao_difusa[]    = { 0.2, 0.2, 0.2, 0.2 };
GLfloat chao_especular[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat chao_brilho[]    = { 0.3 };

GLfloat cobertura_difusa[]    = { 0.6, 0.6, 0.6, 0.6 };
GLfloat cobertura_especular[] = { 0.1, 0.1, 0.1, 0.1 };
GLfloat cobertura_brilho[]    = { 50.0 };

GLfloat marrom_difusa[]    = { 0.5, 0.2, 0.0, 0.0 };
GLfloat marrom_especular[] = { 0.2, 0.2, 0.2, 0.2 };
GLfloat marrom_brilho[]    = { 50.0 };

GLfloat det_pil_difusa[]    = { 0.6, 0.3, 0.0, 1.0 };
GLfloat det_pil_especular[] = { 0.5, 0.5, 0.5, 0.5 };
GLfloat det_pil_brilho[]    = { 50.0 };

GLfloat branco_difusa[]    = { 1.0, 1.0, 1.0, 1.0 };
GLfloat branco_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat branco_brilho[]    = { 50.0 };

GLfloat vidro_difusa[]    = { 0.15, 0.15, 0.15, 0.15 };
GLfloat vidro_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat vidro_brilho[]    = { 50.0 };

GLfloat portao_metal_difusa[]    = { 0.05, 0.05, 0.05, 0.05 };
GLfloat portao_metal_especular[] = { 0.4, 0.4, 0.4, 0.4 };
GLfloat portao_metal_brilho[]    = { 50.0 };

GLfloat barreira_difusa[]    = { 1.0, 1.0, 0.0, 1.0 };
GLfloat barreira_especular[] = { 0.3, 0.3, 0.3, 0.3 };
GLfloat barreira_brilho[]    = { 50.0 };

GLfloat posicao_luz[]    = { 1.0, 1.1, -2.0, 1.0};
GLfloat cor_luz[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]    = { 0.5, 0.5, 0.5, 1.0};

static int rot = 0;
static int zoom = 0;
static int lat = 0;

GLuint  textura_plano;

GLfloat planotext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

void carregar_texturas(void){
  IMAGE *img;
  GLenum gluerr;

  /* textura do plano */
  glGenTextures(1, &textura_plano);
  glBindTexture(GL_TEXTURE_2D, textura_plano);
  
  if(!(img=ImageLoad(TEXTURA_DO_PLANO))) {
    exit(-1);
  }

  gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  if(gluerr){
    exit(-1);
  }

  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_BLEND);

}

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  carregar_texturas();
  
  glEnable(GL_DEPTH_TEST);
  
  glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz);
  glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz);
  glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz_amb);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);
  
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

GLUquadricObj *quadric;

glPushMatrix();
glTranslatef(lat, 0.0, zoom);
glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);

glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  glBindTexture(GL_TEXTURE_2D,textura_plano);
  
// Textura: letreiro

  glEnable(GL_TEXTURE_2D);  
  glBegin(GL_QUADS);
  glTexCoord2fv(planotext[0]);  glVertex3f(-5.01,4.2,-16.0);
  glTexCoord2fv(planotext[1]);  glVertex3f(-5.01,4.2,8.0);
  glTexCoord2fv(planotext[2]);  glVertex3f(-5.01,5.2,8.0);
  glTexCoord2fv(planotext[3]);  glVertex3f(-5.01,5.2,-16.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);

//chao
glPushMatrix();
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chao_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chao_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chao_brilho);
glTranslatef(1.0, 0.0, -4.0);
glScalef(12.0, 0.2, 24.0);
glutSolidCube(1.0);
glPopMatrix();

// ################## COBERTURA ABAIXO ##################
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cobertura_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cobertura_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, cobertura_brilho);
//teto
glPushMatrix();
glTranslatef(-0.5, 4.7, -4.0);
glScalef(9.0, 1.0, 24.0);
glutSolidCube(1.0);
glPopMatrix();

//fundo
glPushMatrix();
glTranslatef(-0.5, 2.15, -15.5);
glScalef(9.0, 4.1, 1.0);
glutSolidCube(1.0);
glPopMatrix();
// ################## COBERTURA ACIMA ##################

// ################## LAMPADAS ABAIXO ##################
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);

// linha 0
glPushMatrix();
glTranslatef(-4.2, 4.15, 0.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.15, 0.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 1
glPushMatrix();
glTranslatef(-4.2, 4.15, -2.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.15, -2.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 2
glPushMatrix();
glTranslatef(-4.2, 4.15, -4.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.15, -4.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 3
glPushMatrix();
glTranslatef(-4.2, 4.15, -6.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.15, -6.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// linha 4
glPushMatrix();
glTranslatef(-4.2, 4.15, -8.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 4.15, -8.0);
glRotatef(90.0, -1.0, 0.0, 0.0);
glutSolidCone(0.25, 0.1, 13, 13);
glPopMatrix();

// ################## LAMPADAS ACIMA ##################

// ################## PORTARIA ABAIXO ##################

glPushMatrix();
glTranslatef(-0.05, 0.0, 11.593);

// HORIZONTAL SUPERIOR PRETA
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vidro_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, vidro_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, vidro_brilho);

glPushMatrix();
glTranslatef(0.35, 4.0, -25.0);
glScalef(-7.4, 0.4, 3.2);
glutSolidCube(1.0);
glPopMatrix();

//parede lateral direita
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marrom_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, marrom_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, marrom_brilho);

glPushMatrix();
glTranslatef(1.8, 1.95, -25.0);
glScalef(4.5, 3.7, 3.2);
glutSolidCube(1.0);
glPopMatrix();

// Parede superior esquerda
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, portao_metal_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, portao_metal_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, portao_metal_brilho);
glPushMatrix();
glTranslatef(-2.45, 3.37, -25.0);
glScalef(-4.0, 0.86, 3.2);
glutSolidCube(1.0);
glPopMatrix();

// Parede inferior central baixo
glPushMatrix();
glTranslatef(-3.45, 0.8, -24.2);
glScalef(-2.0, 1.4, 1.6);
glutSolidCube(1.0);
glPopMatrix();

// Parede inferior direita baixo

glPushMatrix();
glTranslatef(-1.45, 0.8, -24.2);
glScalef(-2.0, 1.4, 1.6);
glutSolidCube(1.0);
glPopMatrix();

// Parede inferior esquerda baixo
glPushMatrix();
glTranslatef(-3.45, 0.8, -25.8);
glScalef(-2.0, 1.4, 1.6);
glutSolidCube(1.0);
glPopMatrix();

// Detalhe vidro 1
glPushMatrix();
glTranslatef(-4.4, 2.2, -23.45);
glScalef(-0.1, 1.5, 0.1);
glutSolidCube(1.0);
glPopMatrix();

// Detalhe vidro 2
glPushMatrix();
glTranslatef(-2.45, 2.2, -23.45);
glScalef(-0.1, 1.5, 0.1);
glutSolidCube(1.0);
glPopMatrix();

// Detalhe vidro 3
glPushMatrix();
glTranslatef(-0.5, 2.2, -23.45);
glScalef(-0.1, 1.5, 0.1);
glutSolidCube(1.0);
glPopMatrix();

// Detalhe vidro 4
glPushMatrix();
glTranslatef(-4.4, 2.2, -25.0);
glScalef(-0.1, 1.5, 0.1);
glutSolidCube(1.0);
glPopMatrix();

// Detalhe vidro 4
glPushMatrix();
glTranslatef(-4.4, 2.2, -26.55);
glScalef(-0.1, 1.5, 0.1);
glutSolidCube(1.0);
glPopMatrix();

// Vidro
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vidro_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, vidro_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, vidro_brilho);
glPushMatrix();
glTranslatef(-2.45, 2.185, -25.0);
glScalef(-3.9, 1.6, 3.1);
glutSolidCube(1.0);
glPopMatrix();

// Pilastra Superior Esquerda
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marrom_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, marrom_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, marrom_brilho);

glPushMatrix();
glTranslatef(-3.9, 4.5, -25.0);
glScalef(1.1, 1.5, 3.2);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();

// ################## PORTARIA ACIMA ##################

// ################## PORTAO PESSOAS ABAIXO ##################
glPushMatrix();
glTranslatef(-1.7, 0.0, -10.9);
glRotatef(-90.0, 0.0, 1.0, 0.0);

glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(1.5, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(1.5, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(1.5, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.8, 2.7);
glScalef(1.5, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.3, 2.7);
glScalef(1.5, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.8, 2.7);
glScalef(1.5, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas verticais portao*/
glPushMatrix();
glTranslatef(0.8, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.8, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();

// ################## PORTAO PESSOAS ACIMA ##################

// ################## PORTAO FRONTAL 1 ABAIXO ##################
glPushMatrix();
glTranslatef(-1.7, 0.0, -0.7);
glRotatef(-90.0, 0.0, 1.0, 0.0);

/*estacas horizontais portao*/
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.8, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas verticais portao*/
glPushMatrix();
glTranslatef(-3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();
// ################## PORTAO FRONTAL 1 ACIMA ##################

// ################## PORTAO FRONTAL 2 ABAIXO ##################
glPushMatrix();
glTranslatef(-1.7, 0.0, -6.9);
glRotatef(-90.0, 0.0, 1.0, 0.0);

/*estacas horizontais portao*/
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.8, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas verticais portao*/
glPushMatrix();
glTranslatef(-3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();
// ################## PORTAO FRONTAL 2 ACIMA ##################

// ################## PORTAO ENTRE PILASTRAS LATERAIS ABAIXO ##################
glPushMatrix();
glTranslatef(-0.6, 0.0, -0.2);

/*estacas horizontais portao*/
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.8, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.3, 2.7);
glScalef(5.8, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 2.8, 2.7);
glScalef(5.8, 0.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas verticais portao*/
glPushMatrix();
glTranslatef(-3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(3.0, 1.5, 2.7);
glScalef(0.2, 2.8, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();
// ################## PORTAO ENTRE PILASTRAS LATERAIS ACIMA ##################

// ################## PILASTRA 1 ABAIXO ##################
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marrom_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, marrom_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, marrom_brilho);

glPushMatrix();
// altura = altura_chao/2 + altura_obj/2
glTranslatef(-4.2, 2.2, 2.5);
glScalef(1.2, 4.2, 0.2);
glutSolidCube(1.0);
glPopMatrix();

//detalhes pilastra 1
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, det_pil_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, det_pil_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, det_pil_brilho);
//linha 0
//cima
glPushMatrix();
glTranslatef(-4.5, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 0.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 1
//baixo
glPushMatrix();
glTranslatef(-4.5, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 0.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 3
//cima
glPushMatrix();
glTranslatef(-4.5, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 1.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 4
//baixo
glPushMatrix();
glTranslatef(-4.5, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 1.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 5
//cima
glPushMatrix();
glTranslatef(-4.5, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 2.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 6
//baixo
glPushMatrix();
glTranslatef(-4.5, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 2.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 7
//cima
glPushMatrix();
glTranslatef(-4.5, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 2.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 8
//baixo
glPushMatrix();
glTranslatef(-4.5, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 3.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 9
//cima
glPushMatrix();
glTranslatef(-4.5, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-4.2, 3.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-3.9, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 10
//baixo
glPushMatrix();
glTranslatef(-4.5, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(-4.2, 4.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(-3.9, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

// ################## PILASTRA 1 ACIMA ##################

// ################## PILASTRA 2 ABAIXO ##################
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, marrom_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, marrom_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, marrom_brilho);

glPushMatrix();
// altura = altura_chao/2 + altura_obj/2
glTranslatef(3.0, 2.2, 2.5);
glScalef(1.2, 4.2, 0.2);
glutSolidCube(1.0);
glPopMatrix();

//detalhes pilastra 2
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, det_pil_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, det_pil_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, det_pil_brilho);

//linha 0
//cima
glPushMatrix();
glTranslatef(3.3, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 0.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 0.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 1
//baixo
glPushMatrix();
glTranslatef(3.3, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 0.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 0.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 3
//cima
glPushMatrix();
glTranslatef(3.3, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 1.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 1.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 4
//baixo
glPushMatrix();
glTranslatef(3.3, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 1.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 1.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 5
//cima
glPushMatrix();
glTranslatef(3.3, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 2.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 2.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 6
//baixo
glPushMatrix();
glTranslatef(3.3, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 2.4, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 2.4, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 7
//cima
glPushMatrix();
glTranslatef(3.3, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 2.8, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 2.8, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 8
//baixo
glPushMatrix();
glTranslatef(3.3, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 3.2, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 3.2, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 9
//cima
glPushMatrix();
glTranslatef(3.3, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(3.0, 3.6, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(2.7, 3.6, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//linha 10
//baixo
glPushMatrix();
glTranslatef(3.3, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//cima
glPushMatrix();
glTranslatef(3.0, 4.0, 2.5);
glRotatef(215.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

//baixo
glPushMatrix();
glTranslatef(2.7, 4.0, 2.5);
glRotatef(35.0, 0.0, 0.0, 1.0);
glScalef(0.3, 0.3, 0.3);
glutSolidTetrahedron();
glPopMatrix();

/*estaca lado esquerdo frente*/
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, barreira_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, barreira_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, barreira_brilho);

glPushMatrix();
glTranslatef(-2.5, 0.7, 3.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-2.5, 0.7, 7.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();


/*estaca lado direito frente*/
glPushMatrix();
glTranslatef(2.5, 0.7, 3.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(2.5, 0.7, 7.0);
glScalef(0.2, 1.2, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//lateral direita
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);

glPushMatrix();
glTranslatef(2.5, 1.2, 4.9);
glScalef(0.1, 0.1, 3.8);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();



  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
glTranslatef(0.0, -2.0, -12.0);
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
case 'w':
zoom += 2;
glutPostRedisplay();
break;
case 's':
zoom -= 2;
glutPostRedisplay();
break;
case 'a':
lat += 2;
glutPostRedisplay();
break;
case 'd':
lat -= 2;
glutPostRedisplay();
break;
case 'r':
rot = (rot+5) % 360;
glutPostRedisplay();
break;
case 'R':
rot = (rot-5) % 360;
glutPostRedisplay();
break;
  case 27:
	exit(0);
	break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glEnable(GL_DEPTH_TEST);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Portaria Condomínio");
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
