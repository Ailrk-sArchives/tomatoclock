#include <error.h>
#include <iostream>
#include <sys/file.h>

// make sure this process the only instance that's running.
static void ensure_singleton() {
  // use some unix api.
}

#ifdef MAIN
int main(void) {

  std::cout << "good" << std::endl;
  return 0;
}
#endif
