#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

typedef long double float128_t;
typedef double float64_t;
typedef float float32_t;

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned uint;
typedef unsigned long ulong;
typedef unsigned long long ularge;

typedef long long large;

#define int(bit) int##bit##_t
#define uint(bit) uint##bit##_t
#define float(bit) float##bit##_t

#define for_n(n, i) for (uint i = 0; i < n; ++i)
#define for_fn(f, n, i) for (int i = f; i < n; ++i)

#define rfor_n(n, i) for (int i = n - 1; i > -1; --i)
#define rfor_fn(f, n, i) for (int i = n - 1; i >= f; --i)
#define for_m(tp, n, i) for (tp i = 0; i < (n); ++i)

#define and &&
#define or ||
#define not !
#define is_odd(a) ((a) % 2)
#define is_even(a) (!is_odd(a))

#define nalloc(tp, n) (tp *)calloc(sizeof(tp), n)
#define ralloc(tp, mem, n) (tp *)realloc(mem, sizeof(tp) * n)
// Use lambda after disabling the error squiggles
// #define lambda(tp, ...) ({ tp lambda __VA_ARGS__; lambda; })

#define next(tp, ele, func, _default) ({ func (ele); (_default); })
#define sum(tp, ele, func) ({ tp e = 0; func e += ele; e; })
#define product(tp, ele, func) ({ tp e = 1; func e *= ele; e; })

#define any(ele, ...) next(bool, ele, __VA_ARGS__ if (ele), false)
#define all(ele, ...) next(bool, ele, __VA_ARGS__ if (!(ele)), true)

#define builder(tp, ele, func) ({ tp *list = nalloc(tp, sum(uint, 1, func)); \
    uint tp##_i = 0; func list[tp##_i] = ele, ++tp##_i; list; })

#define arrlen(arr) (sizeof(arr) / sizeof((arr)[0]))
#define array(tp, ...) __typeof__(tp[__VA_ARGS__])

#define ptr(val) ({ __typeof__(val) *_p = malloc(sizeof(val)); *_p = val; _p; })
#define pinit(var, val) free(var), var = ptr(val)

uint pptrlen(const void **pptr) { return next(
    uint, i, for (uint i = 0; pptr[i]; ++i), 0); }
#define pptrlen(pptr) (pptrlen((const void **)pptr))

void **make_pptr(const uchar ele_size, const uint num_of_ele)
{
  void **pptr = malloc(8 * num_of_ele + 8);
  for_n(num_of_ele, i) pptr[i] = malloc(ele_size);
  pptr[num_of_ele] = NULL;
  return pptr;
}
#define make_pptr(tp, n) make_pptr(sizeof(tp), n)

#define randint(_min, _max) ((_min) + rand() % ((_max) - (_min)))
#define randf(_min, _max) ((_min) + ((_max) - (_min)) * ((float)rand() / RAND_MAX))

/// @brief Concatenates 2 strings of const char *.
/// @param str is the right string.
/// @param _ppend is the left string or the new appended string.
/// @return The concatenate result of both strings.
char *concat(const char *str, const char *_ppend)
{
  uint _strlen = strlen(str), _ppendlen = strlen(_ppend);
  char *newstr = nalloc(char, _strlen + _ppendlen);
  strcpy(newstr, str), strcat(newstr, _ppend);
  return newstr;
}
char *join(char *str, ...)
{
  va_list args;
  va_start(args, str);
  char *joiner = str, *next_str = va_arg(args, char *);
  char *joined = nalloc(char, strlen(next_str));
  strcpy(joined, next_str), next_str = va_arg(args, char *);
  while (next_str)
  {
    char *old = joined;
    joined = concat(joined, joiner), free(old), old = joined;
    joined = concat(joined, next_str), free(old);
    next_str = va_arg(args, char *);
  }
  va_end(args);
  return joined;
}
#define join(str, ...) join(str, __VA_ARGS__, NULL)
