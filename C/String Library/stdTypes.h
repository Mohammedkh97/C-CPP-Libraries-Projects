/*
* stdTypes.h
*
* Created: 10/10/2023 4:22:10 AM
*  Author: Mohammed Khalaf
*/


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char  u8;
typedef signed char    s8;

typedef unsigned int  u16;
typedef signed int    s16;

typedef unsigned long u32;
typedef signed long   s32;

typedef float 			f32;
typedef double			f64;
typedef long double		f80;

typedef enum
{
	FALSE 	= 0,
	CLEAR 	= 0,
	TRUE	= 1
}bool_t;


#define  NullPtr ((void*)0)

typedef enum
{
	OK,
	NOK,
	Null_Ptr,
	OUT_OF_RANGE,
	BUSY
}error_t;

#define  MAX_U8 ((u8)255)
#define  MIN_U8 ((u8)0)

#define  MAX_S8 ((u8)127)
#define  MIN_S8 ((u8)-128)
#define ZERO_S8 ((s8)0)



#endif /* STDTYPES_H_ */
