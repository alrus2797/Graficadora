#include "mapa.h"
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

#include "QString"
#define Pi 3.141592654
/*
bool is_number(char a)
{
    int b=a;
    if ((b>=48 && b<=57)|| a=='.')
        return true;
    return false;
}

bool Mapa::is_operator(char a)
{
    int i=0;
    if (operador.find(a)<operador.length())
        return true;
    return false;
}
double s_to_do(string a)
{
    double t =0.0;
    stringstream ss;
    ss<<a;
    ss>>t;
    return t;
}

*/
//FUNCIONES BINARIAS

dob_b suma1(dob_bp num1,dob_bp num2){
    return num1+num2;
}
dob_b resta1(dob_bp num1,dob_bp num2){
    return num1-num2;
}
dob_b multiplicacion1(dob_bp num1,dob_bp num2){
    return num1*num2;
}
dob_b division1(dob_bp num1,dob_bp num2){
    return num1/num2;
}
dob_b exponencial1(dob_bp num1,dob_bp num2){
    return pow(num1,num2);
}
dob_b raiz1 (dob_bp num1,dob_bp num2){
    return pow(num2,1.0/num1);
}
dob_b modulo1(dob_bp num1, dob_bp num2){
    int n1=(int)num1;
    int n2=(int)num2;
    int n=n1%n2;
    double m=(double)n;
    return m;
}

//FUNCIONES UNARIAS
//Funciones trigonometricas
dob_u seno1(dob_up num1){
    return sin(num1);
}
dob_u coseno1 (dob_up num1){
    return cos((Pi*num1)/180);
}
dob_u tangente1 (dob_up num1){
    return tan(num1);
}
dob_u cotangente1 (dob_up num1){
    return 1/tangente1(num1);
}
dob_u secante1 (dob_up num1){
    return 1/coseno1(num1);
}
dob_u cosecante1 (dob_up num1){
    return 1/seno1(num1);
}

dob_u arco_seno1(dob_up x){
    return asin(x)*180/Pi;
}
dob_u arco_coseno1(dob_up x){
    return acos(x)*180/Pi;
}
dob_u arco_tangente1(dob_up x){
    return atan(x)*180/Pi;
}
dob_u arco_cotangente1(dob_up x){
    double rad=atan(1/x);
    return rad*180/Pi;
}
dob_u arco_secante1(dob_up x){
    double rad=acos(1/x);
    return rad*180/Pi;
}
dob_u arco_cosecante1(dob_up x){
    double rad=asin(1/x);
    return rad*180/Pi;
}

dob_u seno_hiperbolico1(dob_up x){
    return sinh(x);
}
dob_u coseno_hiperbolico1(dob_up x){
    return cosh(x);
}
dob_u tangente_hiperbolico1(dob_up x){
    return tanh(x);
}
dob_u cotangente_hiperbolico1(dob_up x){
    return 1/tangente_hiperbolico1(x);
}
dob_u secante_hiperbolico1(dob_up x){
    return 1/coseno_hiperbolico1(x);
}
dob_u cosecante_hiperbolico1(dob_up x){
    return 1/seno_hiperbolico1(x);
}

dob_u arco_seno_hiperbolico1(dob_up x){
    return asinh(x);
}
dob_u arco_coseno_hiperbolico1(dob_up x){
    return acosh(x);
}
dob_u arco_tangente_hiperbolico1(dob_up x){
    return atanh(x);
}
dob_u arco_cotangente_hiperbolico1(dob_up x){
    return atanh(1/x);
}
dob_u arco_secante_hiperbolico1(dob_up x){
    return acosh(1/x);
}
dob_u arco_cosecante_hiperbolico1(dob_up x){
    return asinh(1/x);
}

//F.valor absoluto
dob_u absoluto1 (dob_up num1)
{
    if(num1<0)
        return num1*-1;
    return num1;
}

//Funciones logaritmo
dob_u logaritmo1(dob_up num1)
{
    return log10(num1);
}
dob_u logaritmoN1(dob_up num1)
{
    return log(num1);
}
dob_u logaritmo21(dob_up num1)
{
    return log2(num1);
}


//parser

Mapa::Mapa()
{
    //FUNCIONES BINARIAS
    dob_b (*f_suma)(dob_bp, dob_bp);
    f_suma =&suma1;
    dob_b (*f_resta)(dob_bp, dob_bp);
    f_resta =&resta1;
    dob_b (*f_multi)(dob_bp, dob_bp);
    f_multi =&multiplicacion1;
    dob_b (*f_divi)(dob_bp, dob_bp);
    f_divi =&division1;
    dob_b (*f_expo)(dob_bp, dob_bp);
    f_expo =&exponencial1;
    dob_b (*f_modu)(dob_bp,dob_bp);
    f_modu =&modulo1;
    dob_b (*f_raiz)(dob_bp,dob_bp);
    f_raiz =&raiz1;

    f_binaria["+"]=f_suma;
    f_binaria["-"]=f_resta;
    f_binaria["*"]=f_multi;
    f_binaria["/"]=f_divi;
    f_binaria["^"]=f_expo;
    f_binaria["%"]=f_modu;
    f_binaria["sqrt"]=f_raiz;

//    f_binaria["+"]=suma;
//    f_binaria["-"]=resta;
//    f_binaria["*"]=multiplicacion;
//    f_binaria["/"]=division;
//    f_binaria["^"]=exponencial;
//    f_binaria["%"]=modulo;
//    f_binaria["sqrt"]=raiz;

    //FUNCIONES UNARIAS
    dob_u(*f_sen)(dob_up);
    f_sen=&seno1;
    dob_u(*f_cos)(dob_up);
    f_cos =&coseno1;
    dob_u(*f_tg)(dob_up);
    f_tg =&tangente1;
    dob_u(*f_ctg)(dob_up);
    f_ctg =&cotangente1;
    dob_u(*f_sec)(dob_up);
    f_sec =&secante1;
    dob_u(*f_csc)(dob_up);
    f_csc =&cosecante1;

    dob_u(*f_asen)(dob_up);
    f_asen = &arco_seno1;
    dob_u(*f_acos)(dob_up);
    f_acos = &arco_coseno1;
    dob_u(*f_atg)(dob_up);
    f_atg = &arco_tangente1;
    dob_u(*f_actg)(dob_up);
    f_actg = &arco_cotangente1;
    dob_u(*f_asec)(dob_up);
    f_asec = &arco_secante1;
    dob_u(*f_acsc)(dob_up);
    f_acsc = &arco_cosecante1;

    dob_u(*f_senh)(dob_up);
    f_senh = &seno_hiperbolico1;
    dob_u(*f_cosh)(dob_up);
    f_cosh = &coseno_hiperbolico1;
    dob_u(*f_tgh)(dob_up);
    f_tgh = &tangente_hiperbolico1;
    dob_u(*f_ctgh)(dob_up);
    f_ctgh = &cotangente_hiperbolico1;
    dob_u(*f_sech)(dob_up);
    f_sech = &secante_hiperbolico1;
    dob_u(*f_csch)(dob_up);
    f_csch = &cosecante_hiperbolico1;

    dob_u(*f_asenh)(dob_up);
    f_asenh = &arco_seno_hiperbolico1;
    dob_u(*f_acosh)(dob_up);
    f_acosh = &arco_coseno_hiperbolico1;
    dob_u(*f_atgh)(dob_up);
    f_atgh = &arco_tangente_hiperbolico1;
    dob_u(*f_actgh)(dob_up);
    f_actgh = &arco_cotangente_hiperbolico1;
    dob_u(*f_asech)(dob_up);
    f_asech = &arco_secante_hiperbolico1;
    dob_u(*f_acsch)(dob_up);
    f_acsch = &arco_cosecante_hiperbolico1;

    dob_u(*f_abs)(dob_up);
    f_abs=&absoluto1;

    dob_u(*f_log)(dob_up);
    f_log=&logaritmo1;
    dob_u(*f_ln)(dob_up);
    f_ln=&logaritmoN1;
    dob_u(*f_log2)(dob_up);
    f_log2=&logaritmo21;

    f_unaria["sen"]=f_sen;
    f_unaria["cos"]=f_cos;
    f_unaria["tg"]=f_tg;
    f_unaria["ctg"]=f_ctg;
    f_unaria["sec"]=f_sec;
    f_unaria["csc"]=f_csc;

    f_unaria["asen"]=f_asen;
    f_unaria["acos"]=f_acos;
    f_unaria["atg"]=f_atg;
    f_unaria["actg"]=f_actg;
    f_unaria["asec"]=f_asec;
    f_unaria["acsc"]=f_acsc;

    f_unaria["senh"]=f_senh;
    f_unaria["cosh"]=f_cosh;
    f_unaria["tgh"]=f_tgh;
    f_unaria["ctgh"]=f_ctgh;
    f_unaria["sech"]=f_sech;
    f_unaria["csch"]=f_csch;

    f_unaria["asenh"]=f_asenh;
    f_unaria["acosh"]=f_acosh;
    f_unaria["atgh"]=f_atgh;
    f_unaria["actgh"]=f_actgh;
    f_unaria["asech"]=f_asech;
    f_unaria["acsch"]=f_acsch;

    f_unaria["abs"]=f_abs;

    f_unaria["log"]=f_log;
    f_unaria["ln"]=f_ln;
    f_unaria["log2"]=f_log2;


//    f_unaria["sen"]=seno;
//    f_unaria["cos"]=coseno;
//    f_unaria["tg"]=tangente;
//    f_unaria["ctg"]=cotangente;
//    f_unaria["sec"]=secante;
//    f_unaria["csc"]=cosecante;
//    f_unaria["abs"]=absoluto;

}

bool Mapa::binouna(string a)
{
    auto p=f_binaria.find(a);
    if (p!=f_binaria.end())
    {
        return true;
    }
    else {
        auto s=this->f_unaria.find(a);
        if(s!=this->f_unaria.end())
            return false;
    }
}


dob_m Mapa::res(double iz, double der, string op)
{
    return this->f_binaria[op](iz,der);
}

dob_m Mapa::Valor(string cmd)
{

}
