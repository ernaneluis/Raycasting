#include "cubo.h"


/*
vec4 Cubo::vertices[] = {
    vec4(0,0,0, 1),  vec4(0,1,0, 1),  vec4(1,1,0, 1),  vec4(1,0,0, 1),
    vec4(0,0,1, 1),  vec4(0,1,1, 1),  vec4(1,1,1, 1), vec4(1,0,1, 1)
};
*/



Cubo::Cubo()
{



      vertices.append(vec4(0,0,0, 1));
      vertices.append(vec4(0,1,0, 1));
      vertices.append(vec4(1,1,0, 1));
      vertices.append(vec4(1,0,0, 1));
      vertices.append(vec4(0,0,1, 1));
      vertices.append(vec4(0,1,1, 1));
      vertices.append(vec4(1,1,1, 1));
      vertices.append(vec4(1,0,1, 1));


      triangulos.append(Triangulo(&vertices[0],&vertices[1],&vertices[2],  vec4(1,0,0, 0) ) );
      triangulos.append(Triangulo(&vertices[2],&vertices[3],&vertices[0],  vec4(1,0,0, 0) ) );


      triangulos.append(Triangulo(&vertices[0],&vertices[4],&vertices[5], vec4(0,1,0, 0)));
      triangulos.append(Triangulo(&vertices[5],&vertices[1],&vertices[0], vec4(0,1,0, 0)));



      triangulos.append(Triangulo(&vertices[0],&vertices[3],&vertices[7], vec4(0,0,1, 0)));
      triangulos.append(Triangulo(&vertices[7],&vertices[4],&vertices[0], vec4(0,0,1, 0)));


      triangulos.append(Triangulo(&vertices[3],&vertices[2],&vertices[6], vec4(1,0,1, 0)));
      triangulos.append(Triangulo(&vertices[6],&vertices[7],&vertices[3], vec4(1,0,1, 0)));


      triangulos.append(Triangulo(&vertices[2],&vertices[1],&vertices[5], vec4(1,1,0, 0)));
      triangulos.append(Triangulo(&vertices[5],&vertices[6],&vertices[2], vec4(1,1,0, 0)));


      triangulos.append(Triangulo(&vertices[6],&vertices[5],&vertices[4], vec4(0,0,0.3, 0)));
      triangulos.append(Triangulo(&vertices[4],&vertices[7],&vertices[6], vec4(0,0,0.3, 0)));


       ambiente = vec4(0.75, 0.75, 0.75, 1);
       difusa = vec4(0.75, 0.75, 0.75, 1);
       especular = vec4(0.75, 0.75, 0.75, 1);
}

void Cubo::carregarMatriz(mat4 matriz){

    matriz_corrente = matriz * matriz_corrente;
}

void Cubo::aplicarMatriz(){

    for(int i=0;i< vertices.size();i++)
        vertices[i] = matriz_corrente * vertices[i];

    for(int i=0;i< triangulos.size();i++)
        triangulos[i].recalculaNormal();

}
