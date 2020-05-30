#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define __create(__type) ((__type *)calloc(1, sizeof(__type)))

#define __unused(__stuff) ((void)(__stuff))

#define __max(a, b) ((a) > (b) ? (a) : (b))

#define __min(a, b) ((a) < (b) ? (a) : (b))