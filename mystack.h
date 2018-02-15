#ifndef MYSTACK_H
#define MYSTACK_H

struct TDATO{
    int cod;
    std::string name;
    std::string surname;
};

class STACKNODE{
public:
  TDATO mynode;
  STACKNODE *next;
private:
};	

class mystack {
public:
    mystack();
    mystack(const mystack& orig);
    virtual ~mystack();
    void show();
    int count();
    void clear();
    STACKNODE& pop();
    void push(TDATO &d);
    void debug(bool is_active);
private:
    int length = 0;
    bool debug_flag = false;
    STACKNODE* head_reference;
    void removeat(int at);
    STACKNODE& get(int i);
    STACKNODE* find(int i);   
    void insert(TDATO &d, int at);
    void dmsg(std::string message);
};

#endif /* MYSTACK_H */

