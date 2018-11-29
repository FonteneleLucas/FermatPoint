#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc1(double a, double b, double c, double d, double r, double * x1Pointer, double * y1Pointer, double * x2Pointer, double * y2Pointer);
double distancia(double x1,double y1,double x2,double y2);
void funcaoReta(double x1R, double y1R, double x2R, double y2R, double * xRetaReturn, double * yRetaReturn, double * iRetaReturn);
void calculoP();

double x1Return, x2Return, y1Return, y2Return;
    double ax, ay, bx, by, cx, cy, d_AB, d_AC, d_CB;
    double xReta1, yReta1, iReta1, xReta2, yReta2, iReta2, xReta3, yReta3, iReta3;


int main(){


    /*ax = 1; ay = 2; d_AB = 4.4721; //= raio
    bx = 5, by = 4; d_AC = 2.2360;
    cx = 3, cy = 1; d_CB = 3.6055;*/

    printf("A:(x,y): ");
    scanf("%lf %lf", &ax, &ay);
    printf("B:(x,y): ");
    scanf("%lf %lf", &bx, &by);
    printf("C:(x,y): ");
    scanf("%lf %lf", &cx, &cy);



    d_AB = distancia(ax, ay, bx, by);
    d_AC = distancia(ax, ay, cx, cy);
    d_CB =  distancia(cx, cy, bx, by);

    //Pega os valores
    calc1(ax,ay,bx,by,d_AB, &x1Return, &y1Return, &x2Return, &y2Return); //AB
    double intersectAB[4];
    //Seleciona coordenadas uteis
    if(distancia(x1Return, y1Return, cx, cy) > distancia(x2Return, y2Return, cx, cy)){
        intersectAB[0] = x1Return;
        intersectAB[1] = y1Return;
    }else{
        intersectAB[0] = x2Return;
        intersectAB[1] = y2Return;
    }

    calc1(ax,ay,cx,cy,d_AC, &x1Return, &y1Return, &x2Return, &y2Return); //AC
    double intersectAC[4];

    if(distancia(x1Return, y1Return, bx, by) > distancia(x2Return, y2Return, bx, by)){
        intersectAC[0] = x1Return;
        intersectAC[1] = y1Return;
    }else{
        intersectAC[0] = x2Return;
        intersectAC[1] = y2Return;
    }

    calc1(bx,by,cx,cy,d_CB, &x1Return, &y1Return, &x2Return, &y2Return); //CB
    double intersectCB[4];

    if(distancia(x1Return, y1Return, ax, ay) > distancia(x2Return, y2Return, ax, ay)){
        intersectCB[0] = x1Return;
        intersectCB[1] = y1Return;
    }else{
        intersectCB[0] = x2Return;
        intersectCB[1] = y2Return;
    }

    /*printf("Inter. circ. AB: (%.2f,%.2f);\n", intersectAB[0], intersectAB[1]);
    printf("Inter. circ. AC: (%.2f,%.2f);\n", intersectAC[0], intersectAC[1]);
    printf("Inter. circ. CB: (%.2f,%.2f);\n", intersectCB[0], intersectCB[1]);*/

    //AB ---> C
    //AC ---> B
    //CB ---> A

    //Calcula as funçoes da reta
    funcaoReta(intersectAB[0], intersectAB[1],cx, cy, &xReta1, &yReta1, &iReta1);
    funcaoReta(intersectAC[0], intersectAC[1],bx,by, &xReta2, &yReta2, &iReta2);
    //Exibe o ponto de Fermat
    calculoP();

    return 0;
}

void calc1(double a, double b, double c, double d, double r, double * x1Pointer, double * y1Pointer, double * x2Pointer, double * y2Pointer){
    //EQ1
    double x1 = -2*a;
    double y1 = -2*b;
    double result1 = ((a*a) + (b*b) - (r*r))*-1;
   // printf("x^2 + y^2 %.2fx %.2fy = %.2f\n", x1, y1, result1);
    //EQ2
    double x2 = -2*c;
    double y2 = -2*d;
    double result2 = ((c*c) + (d*d) - (r*r))*-1;
    //printf("x^2 + y^2 %.2fx %.2fy = %.2f\n", x2, y2, result2);
    //printf("-----------------------\n");
    //TESTE OK!

    //EQ resultante //TESTE OK!
    double x = x1 - x2;
    double y = y1 - y2;
    double result = result1 - result2;
    //printf("%.2fx %.2fy = %.2f\n", x, y, result);
    //printf("-----------------------\n");
    double xFinal = ((x*(-1))/y);
    double resultFinal = result/y;
    //printf("y = %.2fx %.2f\n", xFinal, resultFinal);
   // printf("-----------------------\n"); //TESTE OK

    //Produto notavel de Y
    double xValue = (xFinal*xFinal);
    double xTimes = (2*xFinal*resultFinal);
    double valueIndepent = resultFinal*resultFinal;
    //printf("%.2f^2 %.2fx %.2f = 0\n", xValue, xTimes, valueIndepent);
    //printf("-----------------------\n"); //TESTE OK

    //Formando Equação 2grau que define os pontos X' X''
    //Substituinndo na primeira equação
    double xSquare = 1 + xValue;
    double xTimesFinal = xTimes + x1 + (y1*xFinal);
    double indepent = valueIndepent + (y1 * resultFinal) + (result1*(-1));
    //Gera segundo eq grau OK!
    //printf("%.2f^2 %.2fx %.2f = 0\n", xSquare, xTimesFinal, indepent);

    //printf("-----------------------\n"); //TESTE OK
    //achando as raizes

    double delta = (xTimesFinal*xTimesFinal) -4*xSquare*indepent;
    double cX1 = ((-xTimesFinal)+sqrt(delta))/(2.0*xSquare);
    double cX2 = ((-xTimesFinal)-sqrt(delta))/(2.0*xSquare);

    //TESTE OK!
    //printf("%.f\n", delta);
    //printf("X1: %.3f\n", cX1);
    //printf("X2: %.3f\n", cX2);

    //Encontrando coordendas de Y - substituindo na equação

    double cY1 = (xFinal * cX1) + resultFinal;
    double cY2 = (xFinal * cX2) + resultFinal;

    //Retornando coordenadas
    //printf("Coordenadas de intersecao\n");
    //printf("C1(%.3f,%.3f)\n", cX1, cY1);
    //printf("C2(%.3f,%.3f)\n\n", cX2, cY2);

    *x1Pointer = cX1;
    *y1Pointer = cY1;
    *x2Pointer = cX2;
    *y2Pointer = cY2;
}

double distancia(double x1,double y1,double x2,double y2){
    double dist = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
    return sqrt(dist);
}

void funcaoReta(double x1R, double y1R, double x2R, double y2R, double * xRetaReturn, double * yRetaReturn, double * iRetaReturn){
    *xRetaReturn = y1R - y2R;
    *yRetaReturn = x2R - x1R;
    *iRetaReturn = ((x1R*y2R)-(y1R*x2R))*-1;
}

void calculoP(){
    double det = (xReta1*yReta2) - (yReta1*xReta2);

    double dx = (iReta1 * yReta2) - (yReta1*iReta2);
    double dy = (xReta1 * iReta2) - (iReta1*xReta2);
    double xP = dx/det;
    double yP = dy/det;

    printf("\n\tP(%.2f,%.2f)\n", xP, yP);
}
