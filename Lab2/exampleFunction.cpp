#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

// INT30-C. Ensure that unsigned integer operations do not wrap
unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b)
{
  unsigned int usum = 0;
  if (UINT_MAX - ui_a < ui_b)  {
    printf("Error: Los números producen desbordamiento\n");
  }
  else  {
    usum = ui_a + ui_b;
  }

  return usum;
}

// INT30-C. Ensure that unsigned integer operations do not wrap
unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b)
{
  unsigned umul = ui_a;

  if (ui_a == 0 || ui_b == 0)  {
    umul = 0;
  }  else if (ui_b > UINT_MAX / ui_a)  {
    printf("Error: Los números producen desbordamiento\n");
    umul = 0;
  }  else  {
    umul *= ui_b;
  }

  return umul;
}

// INT34-C. Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand
uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b)
{
  uint32_t uresult = 0;
  if (ui_b >= __builtin_popcount(UINT_MAX))  {
    printf("Error:ui_b >= 32\n");
  }  else  {
    uresult = ui_a << ui_b | ui_a >> (32 - ui_b);
  }
  return uresult;
}
