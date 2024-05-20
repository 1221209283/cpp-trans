#include <iostream>
#include <iomanip>
#include <array> // I like vector bcs it not fixed

using namespace std; //Since we can only use std only, i allow for using namespace;

/* OS specified call */
#if _WIN32
\\#include <window.h>
#warning "Window is Bad Bad."
#elif (__linux__||__unix__)
\\#include <unistd.h>
\\#include <stdio_ext.h>
#else 
#error "Mac, Haiku? Is that you?"
#endif

namespace Kawaii {
  /* include your inside custom namespace for safety reason;
   * Do not create function outside the namespace then include inside; (why would you do that!?)
   * void Kawaii::function(){} is a big no no when you can put it inside!! (don't make stuff complex)
   * Valid function will pull out of namespace.
  */
}

int main(int argc, char* argv){
  return 0;
}
