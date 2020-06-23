/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
  
#ifndef STANDARD_TYPES_H
#define	STANDARD_TYPES_H


typedef  unsigned char uint8;
typedef  signed char sint8;

typedef  unsigned short uint16;
typedef  signed short sint16;

typedef  unsigned long uint32;
typedef  signed long sint32;

typedef  unsigned long long uint64;
typedef  signed long long sint64;

typedef  volatile unsigned char vuint8;
typedef  volatile signed char vsint8;
typedef  volatile unsigned short vuint16;
typedef  volatile signed short vsint16;
typedef  volatile unsigned long vuint32;
typedef  volatile signed long vsint32;
typedef  volatile unsigned long long vuint64;
typedef  volatile signed long long vsint64;

typedef  float float32;
typedef double float64;
typedef long double float96;

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

