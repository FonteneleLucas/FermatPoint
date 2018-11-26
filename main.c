#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include <iostream>
//using namespace std;

void calc1(double a, double b, double c, double d, double r, double * x1Pointer, double * y1Pointer, double * x2Pointer, double * y2Pointer);
int main(){
    double x1Return, x2Return, y1Return, y2Return;
    double ax, ay, bx, by, cx, cy, d_AB, d_AC, d_CB ;

    /*ax = 2; ay = 6; d_AB = 4.4721; //= raio
    bx = 4, by = 2; d_AC = 6.3245;
    cx = 8, cy = 4; d_CB = 4.4721;*/

    ax = 1; ay = 2; d_AB = 4.4721; //= raio
    bx = 5, by = 4; d_AC = 2.2360;
    cx = 3, cy = 1; d_CB = 3.6055;

    calc1(ax,ay,bx,by,d_AB, &x1Return, &y1Return, &x2Return, &y2Return); //AB
    double intersectAB[4];
    intersectAB[0] = x1Return;
    intersectAB[1] = y1Return;
    intersectAB[2] = x2Return;
    intersectAB[3] = y2Return;

    calc1(ax,ay,cx,cy,d_AC, &x1Return, &y1Return, &x2Return, &y2Return); //AC
    double intersectAC[4];
    intersectAC[0] = x1Return;
    intersectAC[1] = y1Return;
    intersectAC[2] = x2Return;
    intersectAC[3] = y2Return;

    calc1(bx,by,cx,cy,d_CB, &x1Return, &y1Return, &x2Return, &y2Return); //CB
    double intersectCB[4];
    intersectCB[0] = x1Return;
    intersectCB[1] = y1Return;
    intersectCB[2] = x2Return;
    intersectCB[3] = y2Return;

    printf("Inter. circ. AB: (%.2f,%.2f);(%.2f,%.2f)\n", intersectAB[0], intersectAB[1], intersectAB[2], intersectAB[3]);
    printf("Inter. circ. AC: (%.2f,%.2f);(%.2f,%.2f)\n", intersectAC[0], intersectAC[1], intersectAC[2], intersectAC[3]);
    printf("Inter. circ. CB: (%.2f,%.2f);(%.2f,%.2f)\n", intersectCB[0], intersectCB[1], intersectCB[2], intersectCB[3]);



    //calc1(2,6,4,2,4.4721); // AB
    //calc1(2,6,8,4,6.3245); // AC
    //calc1(4,2,8,4,4.4721); // CB

    //AB ---> C
    //AC ---> B
    //CB ---> A
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

   /* static double intersect[4];
    //static double intersect[4] = {0,0,0,0};
    intersect[0] = cX1;
    intersect[1] = cY1;
    intersect[2] = cX2;
    intersect[3] = cY2;
    return intersect;*/
    *x1Pointer = cX1;
    *y1Pointer = cY1;
    *x2Pointer = cX2;
    *y2Pointer = cY2;

}

