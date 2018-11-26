#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc1(double a, double b, double c, double d, double r);
int main(){
    calc1(3,3,-2,4,5.0990);
    return 0;
}

void calc1(double a, double b, double c, double d, double r){
    //EQ1
    double x1 = -2*a;
    double y1 = -2*b;
    double result1 = ((a*a) + (b*b) - (r*r))*-1;
    printf("x^2 + y^2 %.2fx %.2fy = %.2f\n", x1, y1, result1);
    //EQ2
    double x2 = -2*c;
    double y2 = -2*d;
    double result2 = ((c*c) + (d*d) - (r*r))*-1;
    printf("x^2 + y^2 %.2fx %.2fy = %.2f\n", x2, y2, result2);
    printf("-----------------------\n");
    //TESTE OK!

    //EQ resultante //TESTE OK!
    double x = x1 - x2;
    double y = y1 - y2;
    double result = result1 - result2;
    printf("%.2fx %.2fy = %.2f\n", x, y, result);
    printf("-----------------------\n");
    double xFinal = ((x*(-1))/y);
    double resultFinal = result/y;
    printf("y = %.2fx %.2f\n", xFinal, resultFinal);
    printf("-----------------------\n"); //TESTE OK

    //Produto notavel de Y
    double xValue = (xFinal*xFinal);
    double xTimes = (2*xFinal*resultFinal);
    double valueIndepent = resultFinal*resultFinal;
    printf("%.2f^2 %.2fx %.2f = 0\n", xValue, xTimes, valueIndepent);
    printf("-----------------------\n"); //TESTE OK

    //Formando Equação 2grau que define os pontos X' X''
    //Substituinndo na primeira equação
    double xSquare = 1 + xValue;
    double xTimesFinal = xTimes + x1 + (y1*xFinal);
    double indepent = valueIndepent + (y1 * resultFinal) + (result1*(-1));
    //Gera segundo eq grau OK!
    printf("%.2f^2 %.2fx %.2f = 0\n", xSquare, xTimesFinal, indepent);

    printf("-----------------------\n"); //TESTE OK
    //achando as raizes

    double delta = (xTimesFinal*xTimesFinal) -4*xSquare*indepent;
    double cX1 = ((-xTimesFinal)+sqrt(delta))/(2.0*xSquare);
    double cX2 = ((-xTimesFinal)-sqrt(delta))/(2.0*xSquare);

    //TESTE OK!
    printf("%.f\n", delta);
    printf("X1: %.3f\n", cX1);
    printf("X2: %.3f\n", cX2);




}

