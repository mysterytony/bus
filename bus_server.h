#include <stdarg.h>
#include <stdio.h>

typedef int (*rpc_func)();

typedef struct rpc_func_tuple {
  const char* func_name;
  rpc_func func_pointer;
  int arg_num;
} rpc_func_tuple;

rpc_func_tuple tuple;

void register_function(const char* func_name, rpc_func func_pointer,
                       int arg_num) {
  tuple.func_name = func_name;
  tuple.func_pointer = func_pointer;
  tuple.arg_num = arg_num;
}

int dynamic_call(const char* func_name, int* ret_val, int arg_num, ...) {
  va_list valist;
  va_start(valist, arg_num);


  // https://en.cppreference.com/w/cpp/utility/apply
  int x = va_arg(valist, int);
  int y = va_arg(valist, int);

  *ret_val = tuple.func_pointer(x, y);
  va_end(valist);
  return 0;
}