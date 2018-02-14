#include <iostream>
#include "mystack.h"

using namespace std;

int main(int argc, char** argv) {
    
    TDATO a;
    a.cod = 1;
    a.name = "Ramón";  
    a.surname = "Negrillo Valdivia";
    
    TDATO b;
    b.cod = 2;
    b.name = "Yezer";  
    b.surname = "Gonzalez Mella";
    
    TDATO c;
    c.cod = 3;
    c.name = "Rayco";  
    c.surname = "Serpa Alemani";
    
    TDATO d;
    d.cod = 4;
    d.name = "Ana Maria";  
    d.surname = "Nesoya Marquez";
    
    mystack *v = new mystack();
    v->debug(false);
    
    cout << " ================= " << endl;
    cout << "|     MYSTACK     |" << endl;
    cout << " ================= " << endl << endl;
    
    //Introducimos 3 usuario
    cout << "Introducimos Rámon, Yezer, Rayco. Mostramos resultado push" << endl;
    v->push(a);
    v->push(b);
    v->push(c);
    v->show();
    
    //Extraemos el primero que por ser LIFO será Rayco
    cout << "Extraemos Rayco. Mostramos resultado pop y el último estado de la pila" << endl;
    NODE u = v->pop();
    cout << u.mynode.cod << endl;
    cout << u.mynode.name << endl;
    cout << u.mynode.surname << endl;
    v->show();

    //Sacamos en exceso usurios hasta vaciarla y mostramos
    v->pop();
    v->pop();
    v->pop();
    v->pop();
    v->pop();
    v->show();
    
    //Introducimos 1 usuario
    cout << "Introducimos Ana, mostramos el contenido númerico y resultado de la pila" << endl;
    v->push(d);
    cout << "Count: " << v->count() << endl;
    v->show();
    
    //Vaciamos la pila con clear
    cout << "Vaciamos la pila con clear y verificamos tamaño con count()" << endl;
    v->clear();
    cout << "Count: " << v->count() << endl;
    
    delete v;
    return 0;
}

