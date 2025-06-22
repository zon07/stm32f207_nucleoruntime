#ifndef  V_DEF_H
#define  V_DEF_H

#include "XcpDefines.h"

/***************************************************************************/
/* Version                  (abcd: Main version=ab, Sub Version=cd )       */
/***************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Common_Vdef CQComponent : Implementation */
#define COMMON_VDEF_VERSION            0x0301
#define COMMON_VDEF_RELEASE_VERSION    0x00

/* compatibility for IL versions < 3.52 */
#define V_DEF_VERSION                  COMMON_VDEF_VERSION

/***************************************************************************/
/***************************************************************************/
/****  Hardware independent settings  **************************************/
/***************************************************************************/
/***************************************************************************/
/*--- standard memory qualifier definition --------------------------------*/

/* 8-Bit qualifier */
#if !defined( vuint8 ) /* ASR compatibility */
typedef unsigned char  vuint8;
#endif
#define canuint8 vuint8

#if !defined( vsint8 ) /* ASR compatibility */
typedef signed char    vsint8;
#endif
#define cansint8 vsint8

/* 16-Bit qualifier */
#if !defined( vuint16 ) /* ASR compatibility */
typedef unsigned short vuint16;
#endif
#define canuint16 vuint16

#if !defined( vsint16 ) /* ASR compatibility */
typedef signed short   vsint16;
#endif
#define cansint16 vsint16

/* 32-Bit qualifier */
#if !defined( vuint32 ) /* ASR compatibility */
typedef unsigned long  vuint32;
#endif
#define canuint32 vuint32

#if !defined( vsint32 ) /* ASR compatibility */
typedef signed long    vsint32;
#endif
#define cansint32 vsint32

typedef unsigned char *TxDataPtr; /* ptr to transmission data buffer */
typedef unsigned char *RxDataPtr; /* ptr to receiving data buffer    */

/***************************************************************************/
/***************************************************************************/
/****  Hardware/Compiler dependent settings   ******************************/
/***************************************************************************/
/***************************************************************************/

/*  data type according to the CPU type */
#if defined( C_CPUTYPE_8BIT )
/* 8-Bit qualifier */
# ifndef vuintx
#  define vuintx vuint8
# endif
# ifndef vsintx
#  define vsintx vsint8
# endif
#else
# if defined( C_CPUTYPE_16BIT )
/* 16-Bit qualifier */
#  ifndef vuintx
#   define vuintx vuint16
#  endif
#  ifndef vsintx
#   define vsintx vsint16
#  endif
# else
#  if defined( C_CPUTYPE_32BIT )
/* 32-Bit qualifier */
#   ifndef vuintx
#    define vuintx vuint32
#   endif
#   ifndef vsintx
#    define vsintx vsint32
#   endif
#  endif
# endif
#endif

/* qualifier for bitfield definition */
typedef unsigned int vbittype;
#define canbittype vbittype

#if defined( C_SUPPORT_MIXED_CAN_LIN )
  /* support combination of "old" CAN driver and "new" LIN driver */
#else
/* Structure for bit accessed memory.           */
/* The bit-order is hardware/compiler dependent */
#  if defined( C_CPUTYPE_BITORDER_LSB2MSB )
struct _c_bits8
{
  canbittype  b0:1;  /* LSB-Bits (lower adr!) */
  canbittype  b1:1;
  canbittype  b2:1;
  canbittype  b3:1;
  canbittype  b4:1;
  canbittype  b5:1;
  canbittype  b6:1;
  canbittype  b7:1;  /* MSB-Bits (higher address) unused */
 };

struct _c_bits16 
{
  canbittype  b0:1;  /* lower adr */
  canbittype  b1:1;
  canbittype  b2:1;
  canbittype  b3:1;
  canbittype  b4:1;
  canbittype  b5:1;
  canbittype  b6:1;
  canbittype  b7:1;

  canbittype  b10:1; /* higher adr */
  canbittype  b11:1;
  canbittype  b12:1;
  canbittype  b13:1;
  canbittype  b14:1;
  canbittype  b15:1;
  canbittype  b16:1;
  canbittype  b17:1;
};

struct _c_bits32 
{
  canbittype  b0:1;  /* lower adr */
  canbittype  b1:1;
  canbittype  b2:1;
  canbittype  b3:1;
  canbittype  b4:1;
  canbittype  b5:1;
  canbittype  b6:1;
  canbittype  b7:1;

  canbittype  b10:1; /* mid low adr */
  canbittype  b11:1;
  canbittype  b12:1;
  canbittype  b13:1;
  canbittype  b14:1;
  canbittype  b15:1;
  canbittype  b16:1;
  canbittype  b17:1;

  canbittype  b20:1; /* mid high adr */
  canbittype  b21:1;
  canbittype  b22:1;
  canbittype  b23:1;
  canbittype  b24:1;
  canbittype  b25:1;
  canbittype  b26:1;
  canbittype  b27:1;

  canbittype  b30:1; /* higher adr */
  canbittype  b31:1;
  canbittype  b32:1;
  canbittype  b33:1;
  canbittype  b34:1;
  canbittype  b35:1;
  canbittype  b36:1;
  canbittype  b37:1;
};

# else /* MSB2LSB */
#  if defined( C_CPUTYPE_BITORDER_MSB2LSB )
struct _c_bits8         
{
  canbittype  b7:1;  /* MSB-Bits (Higher addr!) */
  canbittype  b6:1;
  canbittype  b5:1;
  canbittype  b4:1;
  canbittype  b3:1;
  canbittype  b2:1;
  canbittype  b1:1;
  canbittype  b0:1;  /* LSB-Bits (higher address) unused */
};

struct _c_bits16 
{
  canbittype  b7:1;   /* lower adr */
  canbittype  b6:1;
  canbittype  b5:1;
  canbittype  b4:1;
  canbittype  b3:1;
  canbittype  b2:1;
  canbittype  b1:1;
  canbittype  b0:1;

  canbittype  b17:1;  /* higher adr */
  canbittype  b16:1;
  canbittype  b15:1;
  canbittype  b14:1;
  canbittype  b13:1;
  canbittype  b12:1;
  canbittype  b11:1;
  canbittype  b10:1;
};

struct _c_bits32 
{
  canbittype  b7:1;   /* lower adr */
  canbittype  b6:1;
  canbittype  b5:1;
  canbittype  b4:1;
  canbittype  b3:1;
  canbittype  b2:1;
  canbittype  b1:1;
  canbittype  b0:1;

  canbittype  b17:1;  /* mid low adr */
  canbittype  b16:1;
  canbittype  b15:1;
  canbittype  b14:1;
  canbittype  b13:1;
  canbittype  b12:1;
  canbittype  b11:1;
  canbittype  b10:1;

  canbittype  b27:1;  /* mid high adr */
  canbittype  b26:1;
  canbittype  b25:1;
  canbittype  b24:1;
  canbittype  b23:1;
  canbittype  b22:1;
  canbittype  b21:1;
  canbittype  b20:1;

  canbittype  b37:1;  /* higher adr */
  canbittype  b36:1;
  canbittype  b35:1;
  canbittype  b34:1;
  canbittype  b33:1;
  canbittype  b32:1;
  canbittype  b31:1;
  canbittype  b30:1;
};
#  else
//#  error "Bitorder unknown: C_CPUTYPE_BITORDER_MSB2LSB or C_CPUTYPE_BITORDER_LSB2MSB has to be defined"
#  endif /* C_CPUTYPE_BITORDER_MSB2LSB */
# endif  /* C_CPUTYPE_BITORDER_LSB2MSB */
#endif

/***************************************************************************/
/* Memory qualifier                                                        */
/***************************************************************************/

#ifndef MEMORY_HUGE
# define MEMORY_HUGE               /* no entry                         */
#endif

/* default defines used to store permanent data  */
#ifndef V_MEMROM0
# define V_MEMROM0                  /* addition qualifier data access in ROM  */
#endif

#ifndef V_MEMROM1_NEAR
# define V_MEMROM1_NEAR             /* fast data access in ROM */
#endif

#ifndef V_MEMROM1
# define V_MEMROM1                 /* fast data access in ROM */
#endif

#ifndef V_MEMROM1_FAR
# define V_MEMROM1_FAR             /* slow addressing mode in ROM */
#endif

#ifndef MEMORY_ROM_NEAR
# ifndef V_MEMROM2_NEAR
#  define V_MEMROM2_NEAR   const   /* fast data access in ROM */
# endif

  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM_NEAR   V_MEMROM2_NEAR
#else
# define V_MEMROM2_NEAR    MEMORY_ROM_NEAR
#endif

#ifndef MEMORY_ROM
# ifndef V_MEMROM2
#  define V_MEMROM2        const    /* fast data access in ROM */
#endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM        V_MEMROM2       
#else
# define V_MEMROM2         MEMORY_ROM
#endif

#ifndef MEMORY_ROM_FAR
# ifndef V_MEMROM2_FAR
#  define V_MEMROM2_FAR    const    /* slow addressing mode in ROM */
# endif

  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_ROM_FAR    V_MEMROM2_FAR
#else
# define V_MEMROM2_FAR     MEMORY_ROM_FAR
#endif

#ifndef V_MEMROM3
# define V_MEMROM3        
#endif

/* default defines */
/* used to store volatile data  */
#ifndef V_MEMRAM0
# define V_MEMRAM0                  /* addition qualifier data access in RAM  */
#endif

#ifndef V_MEMRAM1_NEAR
# define V_MEMRAM1_NEAR             /* fast data access in RAM */
#endif

#ifndef V_MEMRAM1
# define V_MEMRAM1                 /* fast data access in RAM */
#endif

#ifndef V_MEMRAM1_FAR
# define V_MEMRAM1_FAR             /* slow addressing mode in RAM */
#endif

#ifndef MEMORY_NEAR
# ifndef V_MEMRAM2_NEAR
#  define V_MEMRAM2_NEAR           /* fast data access in RAM */
# endif

  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_NEAR   V_MEMRAM2_NEAR
#else
# define V_MEMRAM2_NEAR    MEMORY_NEAR
#endif

#ifndef MEMORY_NORMAL
# ifndef V_MEMRAM2
#  define V_MEMRAM2                /* fast data access in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_NORMAL   V_MEMRAM2       
#else
# define V_MEMRAM2           MEMORY_NORMAL
#endif

#ifndef MEMORY_FAR
# ifndef V_MEMRAM2_FAR
#  define V_MEMRAM2_FAR            /* slow addressing mode in RAM */
# endif
  /* compatibility for modules which use old definition of memory qualifer */
# define MEMORY_FAR    V_MEMRAM2_FAR
#else
# define V_MEMRAM2_FAR     MEMORY_FAR
#endif

#ifndef V_MEMRAM3_NEAR
# define V_MEMRAM3_NEAR            /* fast data access in RAM */
#endif

#ifndef V_MEMRAM3
# define V_MEMRAM3                 /* fast data access in RAM */
#endif

#ifndef V_MEMRAM3_FAR
# define V_MEMRAM3_FAR             /* slow addressing mode in RAM */
#endif

#if !defined(VUINT8_CAST)
# define VUINT8_CAST
#endif 
#if !defined(VSINT8_CAST)
# define VSINT8_CAST
#endif
#if !defined(VUINT16_CAST)
# define VUINT16_CAST
#endif
# if !defined(VSINT16_CAST)
# define VSINT16_CAST
#endif
#if !defined(CANBITTYPE_CAST)
# define CANBITTYPE_CAST
#endif
#if !defined(CANSINTCPUTYPE_CAST)
# define CANSINTCPUTYPE_CAST
#endif
#if !defined(CANUINTCPUTYPE_CAST)
# define CANUINTCPUTYPE_CAST
#endif

/***************************************************************************/
/*  Common_VStdLib                                                         */
/***************************************************************************/
# if defined (VGEN_ENABLE_VSTDLIB) || defined (V_ENABLE_VSTDLIB)
#  include "vstdlib.h"
# endif

/***************************************************************************/
/*  V_NULL Definition                                                      */
/***************************************************************************/

#if !defined(V_NULL)
# define V_NULL ((void*)0)
#endif

#ifndef NULL
# define NULL V_NULL
#endif

/*-----------------------------------------------------------------------------------------------*/
#if !defined(V_ENABLE_CAN_ASR_ABSTRACTION) && !defined(V_ENABLE_VSTDLIB_ASR_ABSTRACTION)
# define V_ENABLE_CBD_ABSTRACTION
# define STATIC                                          static
# define AUTOMATIC
# if !defined(NULL_PTR)
#  define NULL_PTR                                       V_NULL
# endif
# define V_NONE       /* empty storage used instead of extern, static, volatile... */
# if !defined( C_CALLBACK_1 )
#  define C_CALLBACK_1
# endif
# if !defined( C_CALLBACK_2 )
#  define C_CALLBACK_2
# endif
# if !defined( C_API_1 )
#  define C_API_1
# endif
# if !defined( C_API_2 )
#  define C_API_2
# endif
# if !defined( C_API_3 )
#  define C_API_3
# endif
# define V_DEF_VAR(storage, vartype, memclass)                    V_MEMRAM0 storage V_MEMRAM1 vartype V_MEMRAM2
# define V_DEF_VAR_NEAR(storage, vartype)                         V_MEMRAM0 storage V_MEMRAM1_NEAR vartype V_MEMRAM2_NEAR
# define V_DEF_VAR_FAR(storage, vartype)                          V_MEMRAM0 storage V_MEMRAM1_FAR vartype V_MEMRAM2_FAR
# define V_DEF_VAR_TYPE(storage, vartype)                         typedef storage V_MEMRAM1 vartype V_MEMRAM2
# define V_DEF_P2VAR(storage, ptrtype, memclass, ptrclass)        V_MEMRAM0 storage V_MEMRAM1 ptrtype V_MEMRAM2 *
# define V_DEF_P2VAR_PARA(storage, ptrtype, memclass, ptrclass)   storage V_MEMRAM1 ptrtype V_MEMRAM2 *
# define V_DEF_P2VAR_TYPE(storage, ptrtype, ptrclass)             typedef storage V_MEMRAM1 ptrtype V_MEMRAM2 *
/* platform specific order may be needed for MEMORY_CAN (position RAM1 or RAM2) */
# define V_DEF_P2SFR_CAN(storage, ptrtype, memclass)              V_MEMRAM0 storage V_MEMRAM1 ptrtype MEMORY_CAN *
# define V_DEF_P2SFR_CAN_TYPE(storage, ptrtype)                   typedef storage V_MEMRAM1 ptrtype MEMORY_CAN *
/* --- */
# define V_DEF_CONSTP2VAR(storage, ptrtype, memclass, ptrclass)   V_MEMROM0 storage V_MEMRAM1 ptrtype V_MEMRAM2 V_MEMRAM3 * V_MEMROM1 V_MEMROM2
# define V_DEF_CONST(storage, type, memclass)                     V_MEMROM0 storage V_MEMROM1 type V_MEMROM2
# define V_DEF_CONST_NEAR(storage, type)                          V_MEMROM0 storage V_MEMROM1_NEAR type V_MEMROM2_NEAR
# define V_DEF_CONST_FAR(storage, type)                           V_MEMROM0 storage V_MEMROM1_FAR type V_MEMROM2_FAR
# define V_DEF_CONST_TYPE(storage, type, memclass)                typedef storage V_MEMROM1 type V_MEMROM2
# define V_DEF_P2CONST(storage, ptrtype, memclass, ptrclass)      V_MEMRAM0 storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2
# define V_DEF_P2CONST_PARA(storage, ptrtype, memclass, ptrclass) storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2
# define V_DEF_P2CONST_TYPE(storage, ptrtype, ptrclass)           typedef storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 *
# define V_DEF_CONSTP2CONST(storage, ptrtype, memclass, ptrclass) V_MEMROM0 storage V_MEMROM1 ptrtype V_MEMROM2 V_MEMROM3 * V_MEMROM1 V_MEMROM2
# define V_DEF_FUNC(storage, rettype, memclass)                   storage rettype
# define V_DEF_FUNC_API(storage, rettype, memclass)               storage C_API_1 rettype C_API_2
# define V_DEF_FUNC_CBK(storage, rettype, memclass)               storage C_CALLBACK_1 rettype C_CALLBACK_2
# define V_DEF_P2FUNC(storage, rettype, ptrclass, fctname)        storage C_CALLBACK_1 rettype (C_CALLBACK_2 *fctname)
#endif
/*-----------------------------------------------------------------------------------------------*/

#endif /* V_DEF_H */
