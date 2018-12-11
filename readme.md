### Example Flow

In one example flow, we have one group of developers develop a server framework. Then uses bus to expose its endpoints and publishes to bus hub.

The second group downloads this library from bus hub and uses in their server.

#### Server Framework Developer Side

1. Download our SDK which includes `busd` and `bus-cli`.
2. `bus-cli init` opens the `busd` process.
3. Program the server:

```c
#include <bus>

void add_controller(string path, func_pointer controller_method) {
  // implementation omitted
}

void starter() {

}

void stopper() {

}

int main(int argv, char **args) {
  // connect to busd via uds
  bus::connect();

  // register starter & stopper
  bus::register_starter(starter);
  bus::register_stopper(stopper);

  // register services
  bus::register(add_controller);

  // enters a main loop
  bus::run();
}
```

4. package `bus-cli publish`

#### Other Developer Side

1. download bus SDK
2. `bus-cli init`
3. `bus-cli get server`
4. program:

```
#include <busd>
#include <server>

void index(request r) {
  // serve RESTful endpoint
}

int main(int argv, char **args) {
  bus::connect();
  
  server::add_controller("/", index);
  server::start()
}
```

5. compile and run
