#include <iostream>
#include <iomanip>
#include <limits>
#include <array> // I like vector bcs it not fixed

using namespace std; //Since we can only use std only, i allow for using namespace;

/* OS specified call */
#if _WIN32
//#include <window.h>
#warning "Window is Bad Bad."
#elif (__linux__||__unix__)
//#include <unistd.h>
//#include <stdio_ext.h>
#warning "Gay Linux is Good Linux!!"
#else 
#warning "Mac, Haiku? Is that you?"
#endif

constexpr auto MAX_STREAM_SIZE = std::numeric_limits<std::streamsize>::max();


namespace Kawaii {
  /* include your inside custom namespace for safety reason;
   * Do not create function outside the namespace then include inside; (why would you do that!?)
   * void Kawaii::function(){} is a big no no when you can put it inside!! (don't make stuff complex)
   * Valid function will pull out of namespace.
  */
  bool choice(string choice = "\0"){
    unsigned short good = 0, bad = 0;
    if(choice == "\0") {
      choice.erase();
      getline(cin,choice);
    }
    for(char& i:choice){
      switch(i){
        case '\n':
        case ' ':
        case '\t':
        case '\r':
        case '\f':
        case '\v':
          break;
        case 'y':
        case 'Y':
          good++;
          break;
        case 'n':
        case 'N':
        default:
          bad++;
      }
    }
    if(good == 0) good++;
    return (good == 1 && bad == 0);
  }

  class Person {
    protected:
      bool legacy_sex;
      string name;
      unsigned short age;

      void change_name();

    public:
      Person()
      :legacy_sex(false)
      ,age(0)
      {}

      ~Person() = default;
  };

  class Customer : public Person {
    public:
      friend class Admin;
  };

  class Admin : public Person {
      char status;
    public:
      Admin() = default;
      Admin(const bool& legacy_sex,const string& name,const unsigned short& age,const char& status) { // init list to modify local class not inherited class
        this->legacy_sex = legacy_sex;
        this->name = name;
        this->age = age;
        this->status = status;
      }
      ~Admin() = default;

      int change_name(){
        do{
          cout << "Insert Name # "; //user input flow will be revised!!
          getline(cin,name);
          cout << "Confirm !? [Y|n] # ";
        }while (!choice());
        return 0;
      }

      int change_age() {
        do{
          cout << "Insert Age # ";
          if(!(cin >> age)){ // revise here very very important!!!
            cin.clear();
          }
          cin.ignore(MAX_STREAM_SIZE,'\n');
          cout << "Confirm changes !? [Y|n] # ";
        }while(!choice());
        return 0;
      }

      void change_name(const string& name){
        this->name = name;
      }
  };
}

int main(int argc, char* argv[]){
  Kawaii::Admin a;
  (void) a.change_name();
  (void) a.change_age();
  return 0;
}
