/*
template <typename T>
void int_input(T& a,string&& out = ""){
  static_assert(false, "Use num_input");
  bool error_input = false, no_symbol = false;
  string input;
  do{
    error_input = false;
    no_symbol = false;
    input.erase();
    cout << out;
    getline(cin,input);
    if(input == ""){
      error_input = true;
      continue;
    }
    for(const char& i:input){
      if((int)i < 33){
        continue;
      }else if((int)i < 58){
        if((int)i > 47){
          no_symbol = true;
          continue;
        }else if((i == '+' || i == '-') && !no_symbol){
          no_symbol = true;
          continue;
        }else{
          cerr << "\e[31mError Int!!\e[0m" << endl;    
          error_input = true;
          break;
        }
      }else{
        cerr << "\e[31mError Input!!\e[0m" << endl;
        error_input = true;
        break;
      }
    }
  }while(error_input);
  a = (T)stoi(input);
}

template <typename  T>
void float_input(T& a,string&& out = ""){
  static_assert(false, "Use num_input");
  bool error_input = false, no_symbol = false, dot_format = false, lock_dot = false;
  string input;
  do{
    error_input = false;
    no_symbol = false;
    dot_format = false;
    lock_dot = false;
    input.erase();
    cout << out;
    getline(cin,input);
    if(input == ""){
      error_input = true;
      continue;
    }
    for(const char& i:input){
      if((int)i < 33){
        continue;
      }else if((int)i < 58){
        if((int)i > 47) {
          no_symbol = true;
          dot_format = true;
          continue;
        }else if((i == '+' || i == '-') && !no_symbol){
          no_symbol = true;
          continue;
        }else if(i == '.' && dot_format && !lock_dot){
          lock_dot = true;
          continue;
        }else{
          cerr << "\e[31mError Input!!\e[0m" << endl;    
          error_input = true;
          break;
        }
      }else{
        cerr << "\e[31mError Input!!\e[0m" << endl;
        error_input = true;
        break;
      }
    }
  }while(error_input);
  a = (T)stod(input);
}

template <typename T>
void num_input(T& a,string&& out = "input : "){ // one big bloat function
  static_assert(!is_unsigned_v<T>, "This Function cannot handle unsigned varaible !!");
  bool error_input = false, no_symbol = false, dot_format = false, lock_dot = false, is_null = true;
  string input;
  do {
    error_input = false;
    no_symbol = false;
    dot_format = false;
    lock_dot = false;
    is_null = true;
    input.clear();
    cout << out;
    getline(cin, input);
    for(const char& i:input){ // white space
      if((int)i < 33){
        //if(no_symbol) error_input = true;
        continue;
      }
      if((int)i < 58 && (int)i > 47){ // check is number
        no_symbol = true;
        dot_format = true;
        is_null = false;
        continue;
      }
      switch (i) {
        case '+':
        case '-':
          if(!no_symbol){ // make sure plus minus is on the first
            no_symbol = true;
          }else{
            error_input = true;
          }
          break;
        case '.':
          if(dot_format && !lock_dot){ // make sure only one dot between number
            lock_dot = true;
            dot_format = false;
          }else{
            error_input = true;
          }
          break;
        default:
          error_input = true; // other words
      }
      if(error_input){
        cerr << "\e[1;31mError Input!!\e[0m" << endl;
        //cerr << no_symbol << dot_format << lock_dot << is_null << endl;
        break;
      }
    }
    if(is_null){
      error_input = true; // check the string is empty that only contain whitespace
      continue;
    }
    if(!dot_format){ // prevent empty number after .
      cerr << "\e[1;31mError Input!!\e[0m" << endl;
      error_input = true;
    }
  }while (error_input);
  if(is_integral_v<T>){
    a = (T)stoi(input);
    return;
  }
  if(is_same_v<T, float>){
    a = stof(input);
    return;
  }
  if(is_same_v<T, double>){
    a = stod(input);
    return;
  }
}

template <typename T>
void unsign_input(T& a,string&& out = ""){
  bool error_input = false, is_null = true;
  string input;
  do{
    error_input = false;
    is_null = true;
    input.clear();
    cout << out;
    getline(cin,input);
    for(const char& i:input){
      if((int)i < 33){
      }else if((int)i < 58 && (int)i > 47){
        is_null = false;
        continue;
      }else{
        cerr << "\e[1;31mError Input!!\e[0m" << endl;
        error_input = true;
        break;
      }
    }
    if(is_null) error_input = true;
  }while(error_input);
  a = (T)stoull(input);
}
*/

/*
About the Big num_input above is very Big.
I wiil try to optimised a bit.
the fucntion is developed and inspired by cpu CNZV
it does have a similiar boolen to check user input format flow and format.
i design this to make sure user can a correct input,
not: 
.2
2.
other false inputs
*/
