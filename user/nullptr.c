#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char const *argv[]) {
    int* null_ptr = 0;
    printf(1, "The value of the null ptr is %d\n", *null_ptr);
    return 0;
}
