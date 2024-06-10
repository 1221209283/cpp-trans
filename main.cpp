#include <iostream>
#include <iomanip>
#include <limits>
#include <array> // I like vector bcs it not fixed (not used)

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
  bool choice(string choice = "\0"){ // optional parameter, wooo~
    unsigned short good = 0, bad = 0;
    if(choice == "\0") {
      choice.erase();
      getline(cin,choice);
    }
    for(const char& i:choice){// this function only send for false input, does not warn
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
    if(good == 0) good++; // if the user does not enter any thing, program auto default;
    return (good == 1 && bad == 0);
  }

  class Person {
    protected:
      bool legacy_sex = false;
      string name;
      unsigned short age = 0;

      int set_name(){ // unsafe design
        cout << "Insert Name : "; //user input flow will be revised!!
        getline(cin,name);
        return 0;
      }

      int set_age() {
        cout << "Insert Age : ";
        if(!(cin >> age)){ // revise here very very important!!!
          cerr << "Error Input!!" << endl;
          cin.clear();
          cin.ignore(MAX_STREAM_SIZE,'\n');
          return -1;
        } else cin.ignore(MAX_STREAM_SIZE,'\n');
        return 0;
      }

      int set_sex() {
        unsigned short good = 0, bad = 0;
        string input;
        cout << "Insert Sex [F/m] : ";
        getline(cin,input);
        for(const char& i:input){
          switch(i) {
            case '\n':
            case ' ':
            case '\t':
            case '\r':
            case '\f':
            case '\v':
              break;
            case '0':
            case 'F':
            case 'f':
              good++;
              break;
            case '1':
            case 'M':
            case 'm':
              bad++;
              break;
            default:
              cerr << "Error Input!!" << endl;
              return -1;
          }
        }
        if((good + bad) > 1) {
          cerr << "Error Sex!!" << endl;
          return -1;
        }
        if((good + bad) == 0) good++;
        legacy_sex = (good == 0 && bad == 1);
        return 0;
      }

    public:
      Person() = default; // don't touch
      ~Person() = default; // don't touch

      /*accessor*/

      bool Sex() const {
        return legacy_sex;
      }

      string Name() const {
        return name;
      }

      unsigned short Age() const {
        return age;
      }

  };

  class Customer : public Person { // must revised
    public:
      Customer() = default; // No touch
      ~Customer() = default; // No touch

      Customer(const bool x){
        
      }
      friend class Admin;
  };

  class Admin : public Person {
      char status = '\0';
    protected:

      int set_status() {
        cout << "Insert Status : ";
        cin >> status;
        cin.ignore(MAX_STREAM_SIZE,'\n');
        return 0;
      }

    public:

      Admin() = default; //do not write

      Admin(const bool&& x) {
        if(!x) return;
        (void) set_sex();
        (void) set_name();
        (void) set_age();
        (void) set_status();
      }
      Admin(const bool& legacy_sex,const string& name,const unsigned short& age,const char& status) { // init list to modify local class not inherited class
        this->legacy_sex = legacy_sex;
        this->name = name;
        this->age = age;
        this->status = status;
      }

      Admin(const Admin& A) {
        this->legacy_sex = A.legacy_sex;
        this->name = A.name;
        this->age = A.age;
        this->status = A.status;
      }

      ~Admin() {
        cout << "Admin -> " << name << " <- Destroyed !" << endl;
      }

      int change_sex(){
        do{
          set_sex();
          cout<<"Confirm!? [Y/n] ";
        } while(!choice());
        return 0;
      }

      int change_name(){
        do{
          set_name();
          cout<<"Confirm!? [Y/n] ";
        } while(!choice());
        return 0;
      }

      int change_age(){
        do{
          set_age();
          cout<<"Confirm!? [Y/n] ";
        } while(!choice());
        return 0;
      }

      int change_status(){
        do{
          set_status();
          cout<<"Confirm!? [Y/n] ";
        } while(!choice());
        return 0;
      }

      void change_sex(const bool& legacy_sex){
        this->legacy_sex = legacy_sex;
      }
      void change_name(const string& name){
        this->name = name;
      }
      void change_age(const unsigned short& age){
        this->age = age;
      }
      void change_status(const char& status){
        this->status = status;
      }

      /*accessor*/

      char Status() const {
        return status;
      }

      string Check_Status() const {
        switch(status){
          case 'A':
            return "Active";
          case 'I':
            return "Inactive";
        }
        return "None";
      }

      void Details() const {
        cout << "=Admin=" << '\n'
          << "Name   : " << name << '\n'
          << "Sex    : " << ((legacy_sex == false) ? "Female" : "Male") << '\n'
          << "Age    : " << age << '\n'
          << "Status : " << Check_Status() << endl;
      }

      int Edit_Cust(Customer& cust) {
        return 0;
      }
  };

  struct Login_Data { // Not Safe 0n0``!!
    string name;
    string passcode;
    string level;
    Login_Data* previous = nullptr;
    Login_Data* next = nullptr;

    Login_Data(){
      cerr << "Wrong call" <<endl;
    }

    Login_Data(const string name = "",const string passcode = "",const string level = ""){
      this->name = name;
      this->passcode = passcode;
      this->level =level;
    }

    Login_Data(Login_Data* const ptr,const string name = "",const string passcode = "",const string level = ""){
      this->previous = ptr;
      this->name = name;
      this->passcode = passcode;
      this->level = level;
    }

    ~Login_Data(){
      Login_Data* ptr; //Incase of Stupid Action
      cout << "Alert !! Read Warning Below!!" << '\n' 
        << "You has callout of Deletion of this Memory Sector, Deletion is imminent!!" << '\n'
        << "You are unable to prevent the deletion of this this data but to ensure the intergrity of the rest of data." << '\n'
        << "We making sure of the pointer still pointing to rest of the data." << '\n'
        << "If you inssist purging the pointer, we will terminate the whole sector of data for memory leak!!" << endl;
    }
  };

  class Login {
      Login_Data* ptr = nullptr;
    public:

      Login(){
        //code
      }
      void Logout(){
        //erase code
      }
  };

  class Menu { //refer to plan
      //
    public:
      Menu();

      
  };
}

int main(int argc, char* argv[]){ // Halt revise the planing
  Kawaii::Admin* a = new Kawaii::Admin(true);
  a->Details();
  a->change_sex();
  a->Details();
  delete a;
  return 0;
}
