/*
#include <iostream>
using namespace std;

class SingleTon{
  private:
    int _data;
    static SingleTon* _instance;
    SingleTon(int data) : _data(data) {}
    
  public:
    static SingleTon* getInstance(){
        if(!_instance){
            _instance = new SingleTon;
            return _instance;
        }
    }
    void Display(){ cout <<"Data = " << _data << endl; }
};

SingleTon *SingleTon::_instance = 0;

int main()
{
    SingleTon *ptr = getInstance(5);
    ptr->Display();
    return 0;
}
*/

#include <iostream>

using namespace std;

class Singleton {
   static Singleton *instance;
   int data;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }

   public:
   static Singleton *getInstance() {
      if (!instance){
      instance = new Singleton;
      cout << "Created 1st object "<< endl;
      }
      else
      cout << "Not allowed to create obj\n" << endl;
      return instance;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;


int main(){
   Singleton *s = s->getInstance();
   Singleton *s1 = s1->getInstance();

   return 0;
}
