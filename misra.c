// W3042
enum directions {
  EAST=0,
  SOUTH,
  WEST,
  NORTH=3
};

// W3046
int global_var;

// W3119 
#define DIV(x, y) (x / y)

void W3012() {
  /*
   * expected 
   * while(1)
   *   ; // explain why while got an empty body
   */
  while(1);
}

void W3027() {
  // x = 54;
  int x = 066; // 7.1
}

struct A {};
struct B {};

void* malloc(unsigned int);

void W3059() {
  struct A* a = (struct A *) malloc(sizeof(struct A));
  struct B* b;
  b = a;
}

int W3081(int value) {
  if (value==0)
    goto bad_arg;
  return 0;
bad_arg:
  return -1;
}

void W3041(int x) {
  int arr[x];
}

void W3045() {
    int x;
    x += 1;  // x is used before it has been initialized
}

int add(int, int);
void W3069(void) {
  int x = 10;
  int y = 20;
  add((0, 10), 20);
}
