#include "funciones.h"
#define Pi 3.141592654

//FUNCIONES BINARIAS
dob_b suma(dob_bp num1,dob_bp num2){
    return num1+num2;
}
dob_b resta(dob_bp num1,dob_bp num2){
    return num1-num2;
}
dob_b multiplicacion(dob_bp num1,dob_bp num2){
    return num1*num2;
}
dob_b division(dob_bp num1,dob_bp num2){
    return num1/num2;
}
dob_b exponencial(dob_bp num1,dob_bp num2){
    return pow(num1,num2);
}
dob_b raiz (dob_bp num1,dob_bp num2){
    return pow(num2,1.0/num1);
}
dob_b modulo(dob_bp num1, dob_bp num2){
    int n1=(int)num1;
    int n2=(int)num2;
    int n=n1%n2;
    double m=(double)n;
    return m;
}

//FUNCIONES UNARIAS
//Funciones trigonometricas
dob_u seno(dob_up num1){
    return sin((Pi*num1)/180);
}
dob_u coseno (dob_up num1){
    return cos((Pi*num1)/180);
}
dob_u tangente (dob_up num1){
    return tan((Pi*num1)/180);
}
dob_u cotangente (dob_up num1){
    return 1/tangente(num1);
}
dob_u secante (dob_up num1){
    return 1/coseno(num1);
}
dob_u cosecante (dob_up num1){
    return 1/seno(num1);
}

dob_u arco_seno(dob_up x){
    return asin(x)*180/Pi;
}
dob_u arco_coseno(dob_up x){
    return acos(x)*180/Pi;
}
dob_u arco_tangente(dob_up x){
    return atan(x)*180/Pi;
}
dob_u arco_cotangente(dob_up x){
    double rad=atan(1/x);
    return rad*180/Pi;
}
dob_u arco_secante(dob_up x){
    double rad=acos(1/x);
    return rad*180/Pi;
}
dob_u arco_cosecante(dob_up x){
    double rad=asin(1/x);
    return rad*180/Pi;
}

dob_u seno_hiperbolico(dob_up x){
    return sinh(x);
}
dob_u coseno_hiperbolico(dob_up x){
    return cosh(x);
}
dob_u tangente_hiperbolico(dob_up x){
    return tanh(x);
}
dob_u cotangente_hiperbolico(dob_up x){
    return 1/tangente_hiperbolico(x);
}
dob_u secante_hiperbolico(dob_up x){
    return 1/coseno_hiperbolico(x);
}
dob_u cosecante_hiperbolico(dob_up x){
    return 1/seno_hiperbolico(x);
}

dob_u arco_seno_hiperbolico(dob_up x){
    return asinh(x);
}
dob_u arco_coseno_hiperbolico(dob_up x){
    return acosh(x);
}
dob_u arco_tangente_hiperbolico(dob_up x){
    return atanh(x);
}
dob_u arco_cotangente_hiperbolico(dob_up x){
    return atanh(1/x);
}
dob_u arco_secante_hiperbolico(dob_up x){
    return acosh(1/x);
}
dob_u arco_cosecante_hiperbolico(dob_up x){
    return asinh(1/x);
}

//F.valor absoluto
dob_u absoluto (dob_up num1)
{
    if(num1<0)
        return num1*-1;
    return num1;
}

//Funciones logaritmo
dob_u logaritmo(dob_up num1)
{
    return log10(num1);
}
dob_u logaritmoN(dob_up num1)
{
    return log(num1);
}
dob_u logaritmo2(dob_up num1)
{
    return log2(num1);
}
