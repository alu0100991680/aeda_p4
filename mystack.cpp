#include <string>
#include <iostream>
#include "mystack.h"

using namespace std;

//==================
//Métodos estandares
//==================

mystack::mystack() {
}

mystack::mystack(const mystack& orig) {
}

mystack::~mystack() {
}

//================
//Métodos práctica
//================

NODE * mystack::find(int at){
    NODE *n = this->head_reference;
    for(int i=0;i<at;i++){
        n = n->next;
    }
    return n;
}

NODE& mystack::get(int i){
    this->dmsg("F:GET->" + std::to_string(i));
    NODE *d = this->find(i);
    return *d;
}

int mystack::count() {
    this->dmsg("F:COUNT");
    return this->length;
}

void mystack::show() {
    this->dmsg("F:SHOW");
    this->dmsg("F:SHOW:Lista de objectos");
    if (length==0){ this->dmsg("F:SHOW:Vacia"); }
    
    cout << "--------" << endl;
    for (int i=0; i<this->length; i++){
        NODE *current_ = this->find(i);
        this->dmsg("F:SHOW:Objecto->" + std::to_string(i));
        cout << "Next->" << current_->next << endl;
        cout << current_->mynode.cod << endl;
        cout << current_->mynode.name << endl;
        cout << current_->mynode.surname << endl << endl;
    }
}

void mystack::clear(){
    this->dmsg("F:CLEAR");
    int fullcontent = this->length;
    for (int i=0;i<fullcontent;i++){
        this->removeat(0);
    }
    this->length = 0;
}

void mystack::push(TDATO &d) {
    this->dmsg("F:ADD");
    this->insert(d, 0);
}

 NODE& mystack::pop() {
    this->dmsg("F:REMOVE");
    NODE *c_aux = nullptr;
    if(0<this->length){
        NODE *aux = this->find(0);
        c_aux = new NODE(); // Hacemos una copia antes de borrarlo
        c_aux->mynode.cod = aux->mynode.cod;
        c_aux->mynode.name = aux->mynode.name;
        c_aux->mynode.surname = aux->mynode.surname;
        this->removeat(0);
        
    }
    return *c_aux;
}

void mystack::insert(TDATO &d, int at){
    this->dmsg("F:INSERT->" + std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        NODE *m = new NODE();
        m->mynode.cod = d.cod;
        m->mynode.name = d.name;
        m->mynode.surname = d.surname; 

        if (at<this->length){
            NODE *n = this->find(at);
            m->next = n; 

        }
        
        if (0<at){
            NODE *p = this->find(at-1);
            p->next = m;
        }
        
        if (at==0){
            this->head_reference = m;
        }
        
        this->length++;
    }
}

void mystack::removeat(int at){
    this->dmsg("F:REMOVEAT->" + std::to_string(at));
    if((0<=at)&&(at<=this->length)){
        NODE *c = this->find(at);
        if(0<at){
            NODE *p = this->find(at-1);
            NODE *n = nullptr;
            if (at+1<this->length){        
                n= this->find(at+1);
            }
            p->next = n;
        }else{
            this->head_reference = c->next;
        }

        delete c;
        this->length--;
    }
}

//===========
//Métodos Aux
//===========

void mystack::debug(bool is_active){
    this->debug_flag = is_active;
}

void mystack::dmsg(std::string message){
    if (this->debug_flag==true){
        cout << message << endl;
    }
}
