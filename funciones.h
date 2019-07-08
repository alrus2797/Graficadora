#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <math.h>
#include <stdlib.h>

#include "typedef.h"
#define Pi 3.141592654

//FUNCIONES BINARIAS
dob_b suma(dob_bp ,dob_bp);
dob_b resta(dob_bp ,dob_bp );
dob_b multiplicacion(dob_bp ,dob_bp );
dob_b division(dob_bp ,dob_bp );
dob_b exponencial(dob_bp ,dob_bp );
dob_b raiz (dob_bp ,dob_bp );
dob_b modulo(dob_bp , dob_bp );

//FUNCIONES UNARIAS
//Funciones trigonometricas
dob_u seno(dob_up );
dob_u coseno (dob_up );
dob_u tangente (dob_up );
dob_u cotangente (dob_up );
dob_u secante (dob_up);
dob_u cosecante (dob_up);

dob_u arco_seno(dob_up);
dob_u arco_coseno(dob_up);
dob_u arco_tangente(dob_up);
dob_u arco_cotangente(dob_up);
dob_u arco_secante(dob_up );
dob_u arco_cosecante(dob_up);

dob_u seno_hiperbolico(dob_up);
dob_u coseno_hiperbolico(dob_up);
dob_u tangente_hiperbolico(dob_up);
dob_u cotangente_hiperbolico(dob_up);
dob_u secante_hiperbolico(dob_up);
dob_u cosecante_hiperbolico(dob_up);

dob_u arco_seno_hiperbolico(dob_up);
dob_u arco_coseno_hiperbolico(dob_up);
dob_u arco_tangente_hiperbolico(dob_up);
dob_u arco_cotangente_hiperbolico(dob_up);
dob_u arco_secante_hiperbolico(dob_up);
dob_u arco_cosecante_hiperbolico(dob_up);

//F.valor absoluto
dob_u absoluto (dob_up);

//Funciones logaritmo
dob_u logaritmo(dob_up);
dob_u logaritmoN(dob_up);
dob_u logaritmo2(dob_up);

#endif // FUNCIONES_H
