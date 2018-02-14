#ifndef MYSTACK_H
#define MYSTACK_H

struct TDATO{
    int cod;
    std::string name;
    std::string surname;
};

class NODE{
public:
  TDATO mynode;
  NODE *next;
private:
};	

class mystack {
public:
    //Estandar
    mystack();
    mystack(const mystack& orig);
    virtual ~mystack();
    //Práctica
    void show();
    void push(TDATO &d);
    NODE& pop();
    void clear();
    int count();
    //Aux
    void debug(bool is_active);
    void dmsg(std::string message);
private:
    void removeat(int at);
    NODE& get(int i);
    void insert(TDATO &d, int at);
    int length = 0;
    bool debug_flag = true;
    NODE* head_reference;
    NODE* find(int i);   
};

#endif /* MYSTACK_H */

