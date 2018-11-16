#include "bus_server.h"
#include <stdio.h>

int remote_add(int x, int y) {
  return x + y;
}

int main(int argc, char const *argv[])
{
  register_function("remote_add", &remote_add, 2);
  printf("%d\n", dynamic_call("remote_add", 10, 12));
  return 0;
}
