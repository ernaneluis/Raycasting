#include <cmath>
#include <iostream>
#include <stdlib.h>

#include <QApplication>
#include <QLabel>
#include <qlist.h>
#include <float.h>


#include "cubo.h"
#include "camera.h"
#include "raio.h"
#include "triangulo.h"
#include "raycasting.h"
#include "luz.h"
#include "material.h"

#include "Angel.h"

using namespace std;

int width = 600;
float widthMundo = 2;
int height = 600;
float heightMundo = 2;

float passoWidth = widthMundo/width;
float passoHeight = heightMundo/height;
float xInicial = (-widthMundo+passoWidth)/2;
float yInicial = (heightMundo-passoHeight)/2;
float x,y;

int countPlano = 0;
int contador=0;


 QList<Cubo> objetos;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QImage image(width,height, QImage::Format_RGB32);
    QLabel resultado;

           vec4 eye(90,70,270, 1);
           vec4 at(105,80,104, 0); // fazendo a camera olhar para o meio da tela
           vec4 up(0,1,0, 0); //direcao para cima
           Camera camera(eye,at,up);
           camera.near = -1;
           mat4 matriz_camera =  LookAt(eye,at,up);

           vec4 matriz_iluminacao[600][600]; //criamos essa matriz para normalizar as componentes de luz para que nao ultrapasse valores maiores que 1

           vec4 posicao_luz(105,30,350, 1);
           posicao_luz = matriz_camera * posicao_luz;
           Luz luz1(vec4(0.75, 0.75, 0.75, 1) , vec4(0.75, 0.75, 0.75, 1) , vec4(0.75, 0.75, 0.75, 1) , posicao_luz );
           luz1.a = 0;
           luz1.b = 0.01;
           luz1.c = 0;


          Cubo torre1;
          torre1.carregarMatriz(Scale(30,160,64));
          torre1.carregarMatriz(Translate(70,0,0));
          torre1.carregarMatriz(matriz_camera);
          torre1.aplicarMatriz();

          Cubo torre2;
          torre2.carregarMatriz(Scale(30,160,64));
          torre2.carregarMatriz(Translate(110,0,0));
          torre2.carregarMatriz(matriz_camera);
          torre2.aplicarMatriz();

          Cubo base1;
          base1.carregarMatriz(Scale(210,2,80));
          base1.carregarMatriz(Translate(0,4,74));
          base1.carregarMatriz(matriz_camera);
          base1.aplicarMatriz();

          Cubo base2;
          base2.carregarMatriz(Scale(210,2,80));
          base2.carregarMatriz(Translate(0,18,74));
          base2.carregarMatriz(matriz_camera);
          base2.aplicarMatriz();

          Cubo preenchimento;
          preenchimento.carregarMatriz(Scale(190,12,70));
          preenchimento.carregarMatriz(Translate(10,6,74 ));
          preenchimento.carregarMatriz(matriz_camera);
          preenchimento.aplicarMatriz();

          objetos.append(torre1);
          objetos.append(torre2);
          objetos.append(base1);
          objetos.append(base2);
          objetos.append(preenchimento);



        for(int i=0;  i<height ; i++){
            for(int j=0; j <width ; j++){

                  matriz_iluminacao[j][i] = vec4(0.74, 0.97, 1);

                  x = xInicial+(j*passoWidth);
                  y = yInicial-(i*passoHeight);

                 float tMin = MAXFLOAT;

                 Raio R = camera.tracarRaio(x,y);

             for(int w=0;w <objetos.size();w++){

                 Cubo cubo = objetos[w];

               for(int k=0;k<cubo.triangulos.size();k++){

                    Triangulo T = cubo.triangulos[k];

                    R.t = Raycasting::calcularT(R,T);
                    if(Raycasting::interceptaPlano(R,T)){
                         if( Raycasting::interceptaTriangulo(R, T) ) {
                                contador++;
                                countPlano++;
                             if(  R.t  < tMin ){
                                    tMin = R.t;

                                    //for lista de luzes
                                    vec4 P = R.origem + R.t*R.direcao;

                                    vec4 V =  normalize(R.origem - P); //viewer
                                    vec4 L =  normalize(P - luz1.posicao);
                                    vec4 Reflec = normalize( (2*dot(L,T.normal) * T.normal) - L); //reflexao

                                    float expressao = pow( (P.x - luz1.posicao.x) ,2) + pow( (P.y - luz1.posicao.y) ,2) + pow( (P.z - luz1.posicao.z) ,2);
                                    float distancia = sqrt(expressao); // distancia do ponto para a luz

                                    float atenuacao = 1/( luz1.a + luz1.b*distancia + luz1.c*pow(distancia,2) );

                                    float DotLN = dot(L,T.normal);
                                    if(DotLN < 0) DotLN = 0; //nao pode ser negativa

                                    float DotReflecV = pow( dot(Reflec, V), luz1.shininess );

                                    vec4 difusa = DotLN * arroba(cubo.difusa, luz1.difusa);
                                    vec4 especular = DotReflecV *  arroba(cubo.especular, luz1.especular);
                                    vec4 ambiente =  arroba(cubo.ambiente, luz1.ambiente);

                                    matriz_iluminacao[j][i] = ( (difusa+especular) * atenuacao )  + ambiente;

                                   image.setPixel(j,i,qRgb(255* T.cor.x, 255*  T.cor.y, 255* T.cor.z ));
                             }
                         }

                    }//end if plano

                 }//for triangulos

               }//for objetos

            }
        }


        float maiorRed = -MAXFLOAT, maiorGreen=-MAXFLOAT, maiorBlue=-MAXFLOAT;

        for(int i=0;  i<height ; i++){
            for(int j=0; j <width ; j++){
                if(matriz_iluminacao[j][i].x > maiorRed)
                    maiorRed = matriz_iluminacao[j][i].x;

                if(matriz_iluminacao[j][i].y > maiorGreen)
                   maiorGreen = matriz_iluminacao[j][i].y;

                if(matriz_iluminacao[j][i].z > maiorBlue)
                   maiorBlue = matriz_iluminacao[j][i].z;
            }
        }

        for(int i=0;  i<height ; i++){
            for(int j=0; j <width ; j++){
                    matriz_iluminacao[j][i].x = matriz_iluminacao[j][i].x / maiorRed;
                    matriz_iluminacao[j][i].y = matriz_iluminacao[j][i].y / maiorGreen;
                    matriz_iluminacao[j][i].z = matriz_iluminacao[j][i].z / maiorBlue;
            }
        }


        for(int i=0;  i<height ; i++){
            for(int j=0; j <width ; j++){
                image.setPixel(j,i,qRgb(255* matriz_iluminacao[j][i].x, 255*  matriz_iluminacao[j][i].y, 255* matriz_iluminacao[j][i].z ));
            }
        }


       resultado.setPixmap(QPixmap::fromImage(image,Qt::AutoColor));
       resultado.show();
       return a.exec();

}






