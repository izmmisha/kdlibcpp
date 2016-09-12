#include "stdafx.h"
#include <string.h>

#pragma optimize("g", off)

#include "test/testfunc.h"

double
static
LocalStaticFunc( int a, float b )
{
   return a + b;
}

void 
__cdecl
CdeclFunc( int a, float b)
{
   int c = a*10;
   float d = b/10;

   LocalStaticFunc(c,d);
}

int
__cdecl
CdeclFuncReturn( int a, char* b )
{
    return a + strlen(b);
}

long long
__cdecl
CdeclFuncLong( unsigned long long a )
{
    return a + 5;
}

float
__cdecl
CdeclFuncFloat( float a, float b )
{
    return a*b;
}

double
__cdecl
CdeclFuncDouble( double a, double b )
{
    return (a+b)/2.0;
}

void
__stdcall
StdcallFunc( int a, float b )
{
   LocalStaticFunc(a + 10, b / 2 );
}

short
__stdcall
StdcallFuncRet( char a, long b)
{
    return b/a;
}

long long
__stdcall
StdcallFuncLong( unsigned long long a, unsigned long long b)
{
    return a & b;
}

float
__stdcall
StdcallFuncFloat(float a, float b)
{
    return a/b;
}

double
__stdcall
StdcallFuncDouble(double a, double b)
{
    return a + b;
}



double
__fastcall
FastcallFunc( int a, float b )
{
   return LocalStaticFunc(a,b);
}

void
_UnderscoreFunc( int a, float b )
{
   LocalStaticFunc(a,b);
}

void FuncTestClass::method()
{
    LocalStaticFunc(1,2);
}

void __cdecl FuncTestClass::staticMethod()
{
    LocalStaticFunc(2,3);
}

void ( *CdeclFuncPtr)( int a, float b) = &CdeclFunc;

void (FuncTestClass::*MethodPtr)() = &FuncTestClass::method;
void (__cdecl*CdeclStaticMethodPtr)() = &FuncTestClass::staticMethod;

void (*ArrayOfCdeclFuncPtr[])(int, float) = { &CdeclFunc, &CdeclFunc, &CdeclFunc };
void (FuncTestClass::*ArrayOfMethodPtr[])() = { &FuncTestClass::method, &FuncTestClass::method };



FuncTestClass FuncReturnClass()
{
    return FuncTestClass();
}

extern "C" 
{

void __stdcall PureCStdcallFunc( int a, float b )
{
    LocalStaticFunc(a,b);
}
void __cdecl PureCCdeclFunc( int a, float b )
{
    LocalStaticFunc(a,b);
}
void __fastcall PureCFastcallFunc( int a, float b )
{
    LocalStaticFunc(a,b);
}

}

void VariadicFunc(int, ...)
{
}


