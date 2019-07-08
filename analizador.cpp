#include "analizador.h"
#include "funciones.h"
#include <QDebug>
using namespace std;

analizador::analizador()
{
    //FUNCIONES BINARIAS
    dob_b (*f_suma)(dob_bp, dob_bp);
    f_suma =&suma;
    dob_b (*f_resta)(dob_bp, dob_bp);
    f_resta =&resta;
    dob_b (*f_multi)(dob_bp, dob_bp);
    f_multi =&multiplicacion;
    dob_b (*f_divi)(dob_bp, dob_bp);
    f_divi =&division;
    dob_b (*f_expo)(dob_bp, dob_bp);
    f_expo =&exponencial;
    dob_b (*f_modu)(dob_bp,dob_bp);
    f_modu =&modulo;
    dob_b (*f_raiz)(dob_bp,dob_bp);
    f_raiz =&raiz;

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
    f_sen=&seno;
    dob_u(*f_cos)(dob_up);
    f_cos =&coseno;
    dob_u(*f_tg)(dob_up);
    f_tg =&tangente;
    dob_u(*f_ctg)(dob_up);
    f_ctg =&cotangente;
    dob_u(*f_sec)(dob_up);
    f_sec =&secante;
    dob_u(*f_csc)(dob_up);
    f_csc =&cosecante;

    dob_u(*f_asen)(dob_up);
    f_asen = &arco_seno;
    dob_u(*f_acos)(dob_up);
    f_acos = &arco_coseno;
    dob_u(*f_atg)(dob_up);
    f_atg = &arco_tangente;
    dob_u(*f_actg)(dob_up);
    f_actg = &arco_cotangente;
    dob_u(*f_asec)(dob_up);
    f_asec = &arco_secante;
    dob_u(*f_acsc)(dob_up);
    f_acsc = &arco_cosecante;

    dob_u(*f_senh)(dob_up);
    f_senh = &seno_hiperbolico;
    dob_u(*f_cosh)(dob_up);
    f_cosh = &coseno_hiperbolico;
    dob_u(*f_tgh)(dob_up);
    f_tgh = &tangente_hiperbolico;
    dob_u(*f_ctgh)(dob_up);
    f_ctgh = &cotangente_hiperbolico;
    dob_u(*f_sech)(dob_up);
    f_sech = &secante_hiperbolico;
    dob_u(*f_csch)(dob_up);
    f_csch = &cosecante_hiperbolico;

    dob_u(*f_asenh)(dob_up);
    f_asenh = &arco_seno_hiperbolico;
    dob_u(*f_acosh)(dob_up);
    f_acosh = &arco_coseno_hiperbolico;
    dob_u(*f_atgh)(dob_up);
    f_atgh = &arco_tangente_hiperbolico;
    dob_u(*f_actgh)(dob_up);
    f_actgh = &arco_cotangente_hiperbolico;
    dob_u(*f_asech)(dob_up);
    f_asech = &arco_secante_hiperbolico;
    dob_u(*f_acsch)(dob_up);
    f_acsch = &arco_cosecante_hiperbolico;

    dob_u(*f_abs)(dob_up);
    f_abs=&absoluto;

    dob_u(*f_log)(dob_up);
    f_log=&logaritmo;
    dob_u(*f_ln)(dob_up);
    f_ln=&logaritmoN;
    dob_u(*f_log2)(dob_up);
    f_log2=&logaritmo2;

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

    //PRIORIDADES

    prioridad["sqrt"]=1;
    prioridad["^"]=1;
    prioridad["*"]=3;
    prioridad["/"]=3;
    prioridad["%"]=3;
    prioridad["+"]=4;
    prioridad["-"]=4;

    prioridad["log"]=2;
    prioridad["ln"]=2;
    prioridad["log2"]=2;

    prioridad["abs"]=1;
    prioridad["sen"]=2;
    prioridad["cos"]=2;
    prioridad["tg"]=2;
    prioridad["ctg"]=2;
    prioridad["sec"]=2;
    prioridad["csc"]=2;

    prioridad["asen"]=2;
    prioridad["acos"]=2;
    prioridad["asec"]=2;
    prioridad["acsc"]=2;
    prioridad["atg"]=2;
    prioridad["actg"]=2;

    prioridad["senh"]=2;
    prioridad["cosh"]=2;
    prioridad["sech"]=2;
    prioridad["csch"]=2;
    prioridad["tgh"]=2;
    prioridad["ctghh"]=2;

    prioridad["asenh"]=2;
    prioridad["acosh"]=2;
    prioridad["atgh"]=2;
    prioridad["actgh"]=2;
    prioridad["asech"]=2;
    prioridad["acsch"]=2;

}

//Imprime el vector
void analizador::imprimir(vector<string> v){

    //cout<<"\nEl vector es: ";
    int lon= v.size();
    for(int i=0;i<lon;i++){
        //cout<<v[i]<<" ";
    }
    //cout<<"\nFin";
}

// Borra los espacios en blanco
string analizador::borrarE(string str)
{
    stringstream ss;
    ss<<str;
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    return str;
}

//NO LO USO
void analizador::llenar(vector<string> vec,string str)
{
    vec.push_back(str);
}

//Elimina los parentesis del string
string analizador::sinPar(string stri)
{
    stri.erase(remove(stri.begin(), stri.end(), '('), stri.end());
    stri.erase(remove(stri.begin(), stri.end(), ')'), stri.end());
    return stri;
}

//Deja al string con solo parentesis
string analizador::solopar(string s){
    int len=s.size();
    string st;
    stringstream ss;
    for (int i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]==')')
            ss<<s[i];
    }
    ss>>st;
    return st;
}

//Funcion usada para comprobar en funcion Parentesis
bool analizador::SonPar(char abre, char cerrar)
{
	if(abre == '(' && cerrar == ')')
        return true;
	else if(abre == '{' && cerrar == '}')
        return true;
	else if(abre == '[' && cerrar == ']')
        return true;
	return false;
}
//Funcion usada para ver si esta bien la sintaxis de los parentesis
bool analizador::Parentesis(string stri)
{
	stack<char> S;
    int lon=stri.size();
	for(int i =0;i<lon;i++)
	{
		if(stri[i] == '(' || stri[i] == '{' || stri[i] == '[')
			S.push(stri[i]);
		else if(stri[i] == ')' || stri[i] == '}' || stri[i] == ']')
		{
			if(S.empty() || !SonPar(S.top(),stri[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

// Funcion para comprobar si un elemento es numero o no
bool analizador::esNum(string stri)
{
    int puntos=0;
    char *cstr = new char[stri.length() + 1];
    strcpy(cstr, stri.c_str());

    char *numeros = "0123456789";
    char *todo = "0123456789.";
    bool fg=false;

    for(int i=0;i<strlen(numeros);i++){
        if(cstr[0]==numeros[i])
            fg=true;
    }

    bool *fu=new bool[strlen(cstr)];

    for (int i=0 ;i<strlen(cstr) ;i++)
    {
        fu[i]=false;
    }

    for(int i=0; i<strlen(todo); i++){
        for(int j=0; j<strlen(cstr);j++)
            if(cstr[j]==todo[i]){
                fu[j]=true;
                if(cstr[j]=='.')
                    puntos++;
            }
    }
    for (int i=0; i<strlen(cstr); i++)
    {
        if(fu[i]==false)
            fg=false;
    }

    if(puntos>1)
        fg=false;

    if(fg==true)
        return true;
    else
        return false;
}
//Funcion para saber si un elemento es variable
bool analizador::esVar(string stri)
{
    int len =stri.size();
    char *cstr = new char[stri.length() + 1];
    strcpy(cstr, stri.c_str());

    if(len>1)
        return false;
    else if(cstr[0]=='x' || cstr[0]=='y')
        return true;
    else
        return false;
}

vector<string> analizador::vecNumeros(vector<string> v)    //Acumula los numeros en un vector
{
    vector<string> Numeros;
    int lon=v.size();
    string elem;
    stringstream ss;

    for(int i=0;i<lon;i++){
        if(esNum(v[i])==true){
            ss<<v[i];
            ss>>elem;
            Numeros.push_back(elem);
        }
        ss.str(string());
        ss.clear();
    }
    return Numeros;
}

vector<string> analizador::vecVariables(vector<string> v)  //Acumula las variables en un vector
{
    vector<string> Variables;
    int lon=v.size();
    string elem;
    stringstream ss;

    for(int i=0;i<lon;i++){
        if(esVar(v[i])==true){
            ss<<v[i];
            ss>>elem;
            Variables.push_back(elem);
        }
        ss.str(string());
        ss.clear();
    }
    return Variables;
}

vector<string> analizador::vecSemFun(vector<string> v) //Acumula las aun no comprobadas funciones en un vector
{
    vector<string> SemFunc;
    int lon=v.size();
    string elem;
    stringstream ss;

    for(int i=0;i<lon;i++){
        if(esVar(v[i])==false && esNum(v[i])==false){
            ss<<v[i];
            ss>>elem;
            SemFunc.push_back(elem);
        }
        ss.str(string());
        ss.clear();
    }
    return SemFunc;
}

// Funcion que retorna la parte de al lado de una funcion
//Ejemplo sen45 , retorna el 45
string analizador::esPam(string stri)
{
    bool flag =false;
    string funciones1[]={"sen","cos","ctg","sec","csc","atg","tgh","abs","log"};
    string funciones2[]={"tg","ln"};
    string funciones3[]={"asen","acos","actg","asec","acsc","senh",
    "cosh","ctgh","sech","csch","atgh","log2"};
    string funciones4[]={"asenh","acosh","actgh","asech","acsch"};

    int len1 = sizeof(funciones4)/sizeof(string);
    for(int i =0;i<len1;i++){
        if (stri.compare(0,5,funciones4[i])==0){
            //cout << "Es funcion de long5"<<endl;
            stri.erase (stri.begin(), stri.begin()+5);
            flag=true;
            return stri;
            break;
        }
    }
    int len2 = sizeof(funciones3)/sizeof(string);
    for(int i =0;i<len2;i++){
        if(flag==true)
            break;
        if(stri.compare(0,4,funciones3[i])==0){
            //cout<<" Es funcion de long4"<<endl;
            stri.erase (stri.begin(), stri.begin()+4);
            flag=true;
            return stri;
            break;
        }
    }
    int len3 = sizeof(funciones1)/sizeof(string);
    for(int i =0;i<len3;i++){
        if(flag==true)
            break;
        if(stri.compare(0,3,funciones1[i]) == 0){
            //cout<<" Es funcion de long3"<<endl;
            stri.erase (stri.begin(), stri.begin()+3);
            flag=true;
            return stri;
            break;
        }
    }
    int len4 = sizeof(funciones2)/sizeof(string);
    for(int i =0;i<len4;i++){
        if(flag==true)
            break;
        if(stri.compare(0,2,funciones2[i])==0){
           // cout<<" Es funcion de long2"<<endl;
            stri.erase (stri.begin(), stri.begin()+2);
            flag=true;
            return stri;
            break;
        }
    }
}



//Funcion para saber si es un string es una funcion, se ayuda de esPam()
bool analizador::esFun(string stri)
{
    string comprobar= esPam(stri);
    if(esNum(comprobar)==true || esVar(comprobar)==true)
        return true;
    else
        return false;

}

//Pone toda la expresion en un vector
vector <string> analizador::Tokens (string stri)
{
    vector<string> Tok;
    stringstream ss,si;
    string Todo="",Op="";

    int lon= stri.size();
    int siz;

    for (int i=0; i<lon;i++)
    {
        if(stri[i]!='+' && stri[i]!='-' && stri[i]!='*' && stri[i]!='/' && stri[i]!='^' && stri[i]!='%' && stri[i]!= '(' && stri[i]!= ')')
        {
            ss<<stri[i];
        }
        else
        {
//            ss.seekg(0, ios::end);
//            siz = ss.tellg();
            siz=ss.str().length();
            if(siz > 0 )
            {
                ss>>Todo;
                Tok.push_back(Todo);
                ss.str(string());
                ss.clear();
                siz=0;
            }

            si<<stri[i];
            si>>Op;
            Tok.push_back(Op);
            si.str(string());
            si.clear();
        }
    }
    //Todo="";
    siz=ss.str().length();
    if(siz>0)
    {
        ss>>Todo;
        Tok.push_back(Todo);
    }
    return Tok;
}

 //Consigue el vector de semifunciones y comprueba si en realidad son sintacticamente correctas
bool analizador::esFuncion(vector <string> v)
{
    //cout<<"\n Comprobando correctas funciones:"<<endl;
    int lon=v.size();
    bool flag= true;
    bool *fu= new bool[lon];

    for(int i=0;i<lon ;i++){
        fu[i]=false;
    }

    for (int i=0;i<lon ;i++){
        //cout<<v[i]<<endl;
        if(esFun(v[i])==true){
            //cout<<"true\n";
            fu[i]=true;}
    }

    for (int i=0;i<lon;i++){
        if(fu[i]==false){
            //cout<<"false\n";
            flag=false;
        }
    }

    if(flag==true){
       // cout<< "SI ES FUNCION "<<endl;
        return true;
    }
    else{
       // cout<<"NO ES FUNCION"<<endl;
        return false;
    }
}


// Funcion que imprime vector  indicando que es cada elemento
//Ejmplo: sen45 +5 +x // Imprimir sen45 : esfuncion , 5: es Numero, x: es variable
/*
void analizador::Es(vector<string> v){

    cout<<"\nEl vector es: ";
    int lon=v.size();
    for(int i=0;i<lon;i++){
        cout<<v[i]<<endl;
        if(esNum(v[i])==true)
            cout<<": Es numero"<<endl;
        else if(esVar(v[i])==true)
            cout<<": Es variable"<<endl;
        else if(esFun(v[i])==true)
            cout<<" :Es funcion "<<endl;
//        else if(esFun(v[i])==true)
//            cout<<": Es funcion"<<endl;
    }
}
*/

// Funcion que comprueba si esta bien la sintaxis
//Ejemplo si ponemos dos operadores juntos, entonces no es funcion.
//Si ponemos solo un elemento, este no debe ser operador
bool analizador::Sintaxis(string stri)
{
    int flag=0;
    int len=stri.size();

    if(len==1)    {
        if(stri[0]!='+' || stri[0]!='-' || stri[0]!='*' || stri[0]!='/' || stri[0]!='%' || stri[0]!='^' )
            flag=1;
    }
    else if(len==0)    {
        flag=0;
    }
    else if(len>1)
    {
        for(int i=0; i<(len-1);i++)
        {
            if((stri[i]=='+' || stri[i]=='-' || stri[i]=='*' || stri[i]=='/' || stri[i]=='%' || stri[i]=='^' ) &&
               (stri[i+1]=='+' || stri[i+1]=='-' || stri[i+1]=='*' || stri[i+1]=='/' || stri[i+1]=='%' || stri[i+1]=='^' ))
            {
                //cout<<"Error en sintaxis"<<endl;
                flag=0;
                break;
            }
            else if(stri[len-1]=='+' || stri[len-1]=='-' || stri[len-1]=='*' || stri[len-1]=='/' || stri[len-1]=='%' || stri[len-1]=='^' )
            {
                //cout<<"Error en sintaxis"<<endl;
                flag=0;
                break;
            }
            else
                flag=1;
        }
    }
    if(flag==1)
        return true;
    else
        return false;
}

// funcion que retorna un vector de tokens ( osea puede ser numero, funcion ,variable, o palabras sin sentido)
//ejemplo= sen45 + asda +43 +x   // guarda en el vector : sen45, asda,43,x
vector<string> analizador::ClasiT(string stri,vector<string> v)
{
    stringstream ss;
    string Nop ="";
    int lon= stri.size();
    for (int i=0; i<lon;i++){
        if(stri[i]!='+' && stri[i]!='-' && stri[i]!='*' && stri[i]!='/' && stri[i]!='%' && stri[i]!='^' )
        {
//            string s(1,str[i]);
            ss<<stri[i];
            //so>>Op;
            //o.push_back(Op);
            //Op="";
            //cout<<"if"<<endl;
        }
        else
        {
        //(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='%'){
            ss>>Nop;
            //string so(1,stri[i]);
            //v.push_back("-");
            v.push_back(Nop);
            //Nop="";
            //cout<<"else"<<endl;
            ss.str( std::string() );
            ss.clear();
        }
    }

    ss>>Nop;
    v.push_back(Nop);
    return v;
    //so>>Op;
        //o.push_back(Op);
}
//funcion que retorna un vector de operadores ( + - / * % )
vector<string> analizador::ClasiO(string stri,vector<string> o)
{
    stringstream so;
    string Op="";
    int lon=stri.size();
    for (int i=0; i<lon;i++){
        if(stri[i]=='+' || stri[i]=='-' || stri[i]=='*' || stri[i]=='/' || stri[i]=='%' || stri[i]=='^' )
        {
            so<<stri[i];
           // cout<<"if"<<endl;
            so>>Op;
            o.push_back(Op);
            so.str( std::string() );
            so.clear();
        }
        else
        {
            //cout<<"else"<<endl;
        }
    }
    return o;
}

/***  POSTORDEN- K   ***/

vector<string> analizador::POST(vector<string> Entrada)
{
    vector <string> Salida;  //S
    vector <string> Auxiliar;  //P

    string x,aux;

   // cout<<"Empezando a analizar"<<endl;

    while(Entrada.size()!=0 )
    {
        string e="";
        e=Entrada[0];

        const char *c;
        if(Entrada[0].size()==1)
            c = e.c_str();

        Entrada.erase(Entrada.begin());

        const char *a;
        a=aux.c_str();

        if(esVar(e)==true || esNum(e)==true || esFun(e)==true){
            Salida.push_back(e);
        }

        else if (c[0]=='('){
            Auxiliar.push_back(e);
            aux=Auxiliar.back();
        }

        else if(c[0]==')'){
            while(a[0]!='('){
                if(Auxiliar.size()>0){
                    x=Auxiliar.back();
                    aux=Auxiliar.back();
                    a=aux.c_str();}
                //if(Auxiliar.size()>0){
                    Auxiliar.erase(Auxiliar.end());
                    Salida.push_back(x);
                //}
                if(Auxiliar.size()>0){
                    aux=Auxiliar.back(); //duda
                    a=aux.c_str();}
                /*
                if(Auxiliar.size()>0){
                    aux=Auxiliar.back();
                    a=aux.c_str();
                }*/
            }/*
            if(Auxiliar.size()>0){
                aux=Auxiliar.back();
                a=aux.c_str();
            }*/
            if(Auxiliar.size()>0){
                Auxiliar.erase(Auxiliar.end());}
            if(Auxiliar.size()>0){
                aux=Auxiliar.back();
                a=aux.c_str();
            }
        }


        else if(c[0]=='+'||c[0]=='-'||c[0]=='*'||c[0]=='/'||c[0]=='%'|| c[0]=='^'){
            while(Auxiliar.size()!=0 && a[0]!='(' &&
                prioridad[Auxiliar.back()]<=prioridad[e]){
                x=Auxiliar.back();
                a=aux.c_str();
                Auxiliar.erase(Auxiliar.end());
                /*if(Auxiliar.size()>0){
                    aux=Auxiliar.back();
                    a=aux.c_str();
                }*/
                Salida.push_back(x);
                if(Auxiliar.size()>0){
                aux=Auxiliar.back();
                a=aux.c_str();}
            }
            Auxiliar.push_back(e);
            if(Auxiliar.size()>0){
                aux=Auxiliar.back();
                a=aux.c_str();
            }
        }
    }

    while(Auxiliar.size()!=0){
        x=Auxiliar.back();
        Auxiliar.erase(Auxiliar.end());
        if(Auxiliar.size()>0)
            aux=Auxiliar.back();
        if(x[0]!='(')
            Salida.push_back(x);
    }

    //cout<< "Terminando de analizar"<<endl;

    return Salida;
}

vector<string> analizador::main(string funcion)
{
    stringstream ss;

    vector<string> vec;
    vector<string> vec1;
    vector<string> vecN;
    vector<string> vecO;

    vector <string> Funciones;

    vector <string> Tok;
    vector <string> PostOrden;

    bool func;
    
    string str= borrarE(funcion);  //Borra los espacios

    string spar = solopar(str);  //Deja solo los parentesis

    //Clasi(str,vecN,vecO);
    bool par= Parentesis(str);   // si es que si esta bien la sintax de parentesis sigue

    if(par==true)
    {
        string stri=sinPar(str);   //Deja sin parentesis
        bool correcto = Sintaxis(stri);           //si la sintaxis esta bien sigue (ejemplo : x+8+ esta mal pero 4+8 esta bien)
        if(correcto==true)
        {
            vec= ClasiT(stri,vecN);                      // crea vector de tokens
            vec1=ClasiO(stri,vecO);                       //crea vector de operadores
            //cout<<"Semifunciones: "; imprimir(vecSemFun(vec));                         //Imprime el vector de semifunciones
            //cout<<"Descripcion de c/u: "; Es(vec);                                        //imprime los tokens con su descripcion
            //cout<<"Operadores :"; imprimir(vec1);                               //solo imprime el vector de operadores
            func = esFuncion(vecSemFun(vec));
            
            if(func==true)
            {
                Tok=Tokens(str);    //Da el vector de la expresion con parentesis
                PostOrden= POST(Tok);   //Da el vector en postorden

                //cout<<"SI ES UNA EXPRESION VALIDA!"<<endl;
            }
            //else
                //cout<<"NO ES UNA EXPRESION VALIDA"<<endl;
        }
        //else return 0;
            //cout<<"No se pudo analizar por error de sintaxis";
    }
    //else return 0;
        //cout<<"Faltan parentesis o su sintaxis mal";

    return PostOrden;
}
