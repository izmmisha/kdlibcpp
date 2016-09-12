#pragma once

#include "procfixture.h"

#include "kdlib/typedvar.h"
#include "kdlib/exceptions.h"

#include "test/testvars.h"

using namespace kdlib;

class TypedVarTest : public ProcessFixture 
{
public:

    TypedVarTest() : ProcessFixture( L"typedvartest" ) {}
};


TEST_F( TypedVarTest, Ctor )
{
    EXPECT_NO_THROW( loadTypedVar(L"ucharVar") );
    EXPECT_NO_THROW( loadTypedVar(L"UInt1B", m_targetModule->getSymbolVa(L"ucharVar") ) );
    EXPECT_NO_THROW( loadTypedVar( loadType(L"UInt1B"),  m_targetModule->getSymbolVa(L"ucharVar") ) );

    EXPECT_THROW( loadTypedVar( TypeInfoPtr(),  m_targetModule->getSymbolVa(L"ucharVar") ), DbgException );
}

TEST_F( TypedVarTest, BaseTypeVars )
{
    EXPECT_EQ( ucharVar, *loadTypedVar(L"ucharVar") );
    EXPECT_EQ( ushortVar, *loadTypedVar(L"ushortVar") );
    EXPECT_EQ( ulongVar, *loadTypedVar(L"ulongVar") );
    EXPECT_EQ( ulonglongVar, *loadTypedVar(L"ulonglongVar") );
    EXPECT_EQ( charVar, *loadTypedVar(L"charVar") );
    EXPECT_EQ( wcharVar, *loadTypedVar(L"wcharVar") );
    EXPECT_EQ( shortVar, *loadTypedVar(L"shortVar") );
    EXPECT_EQ( longVar, *loadTypedVar(L"longVar") );
    EXPECT_EQ( ucharVar, *loadTypedVar(L"ucharVar") );
    EXPECT_EQ( longlongVar, *loadTypedVar(L"longlongVar") );
    EXPECT_EQ( floatVar, *loadTypedVar(L"floatVar") );
    EXPECT_EQ( doubleVar, *loadTypedVar(L"doubleVar") );
    EXPECT_EQ( boolVar, *loadTypedVar(L"boolVar") );
}

TEST_F( TypedVarTest, TypedVarPtr )
{
    TypedVarPtr     ptr;
    MEMOFFSET_64    ptrAddr = m_targetModule->getSymbolVa( L"g_structTestPtr" );

    EXPECT_NO_THROW( ptr = loadTypedVar(L"g_structTestPtr") );
    EXPECT_EQ( ptrPtr( ptrAddr ), *ptr );
    EXPECT_EQ( ptrAddr, ptr->getAddress() );

}

TEST_F( TypedVarTest, TypedVarArray )
{
    TypedVarPtr  var;
    MEMOFFSET_64  varAddr = m_targetModule->getSymbolVa( L"g_testArray" );

    EXPECT_NO_THROW( var = loadTypedVar(L"g_testArray") );
    EXPECT_EQ( varAddr, *var);
    EXPECT_EQ( varAddr, var->getAddress() );
}

TEST_F( TypedVarTest, BitFields )
{
    TypedVarPtr  typedVar;

    EXPECT_NO_THROW( typedVar = loadTypedVar(L"g_structWithBits") );
    EXPECT_EQ( g_structWithBits.m_bit0_4, *typedVar->getElement(L"m_bit0_4") );
    EXPECT_EQ( g_structWithBits.m_bit5, *typedVar->getElement(L"m_bit5") );
    EXPECT_EQ( g_structWithBits.m_bit6_8, *typedVar->getElement(L"m_bit6_8") );
    EXPECT_EQ( g_structWithBits.m_bit0_60, *typedVar->getElement(L"m_bit0_60") );

    EXPECT_NO_THROW( typedVar = loadTypedVar(L"g_structWithSignBits") );
    EXPECT_EQ( g_structWithSignBits.m_bit5, *typedVar->getElement(L"m_bit5") );
    EXPECT_EQ( g_structWithSignBits.m_bit6_8, *typedVar->getElement(L"m_bit6_8") );
    EXPECT_EQ( g_structWithSignBits.m_bit0_60, *typedVar->getElement(L"m_bit0_60") );
}

TEST_F( TypedVarTest, GetAddress )
{
    EXPECT_EQ( loadTypedVar(L"ucharVar")->getAddress(), m_targetModule->getSymbolVa(L"ucharVar") );
    EXPECT_EQ( loadTypedVar(L"g_structTest")->getAddress(), m_targetModule->getSymbolVa(L"g_structTest") );
    EXPECT_EQ( loadTypedVar(L"g_structTestPtr")->getAddress(), m_targetModule->getSymbolVa(L"g_structTestPtr") );
}

TEST_F( TypedVarTest, GetSize )
{
    EXPECT_EQ( sizeof(ucharVar), loadTypedVar(L"ucharVar")->getSize() );
    EXPECT_EQ( sizeof(g_structTest), loadTypedVar(L"g_structTest")->getSize() );
    EXPECT_EQ( sizeof(pbigValue), loadTypedVar(L"pbigValue")->getSize() );
    EXPECT_EQ( sizeof(ulonglongArray), loadTypedVar(L"ulonglongArray")->getSize() );
}

TEST_F( TypedVarTest, GetName )
{
    EXPECT_EQ( L"ucharVar", loadTypedVar(L"ucharVar")->getName() );
    EXPECT_EQ( L"g_constEnumThree", loadTypedVar(L"g_constEnumThree")->getName() );
    EXPECT_EQ( L"CdeclFunc", loadTypedVar(L"CdeclFunc")->getName() );

    EXPECT_THROW( loadTypedVar(L"g_structTest")->getElement(L"m_field1")->getName(), DbgException );
    EXPECT_THROW( loadTypedVar(loadType(L"UInt4B"), 0x0)->getName(), DbgException );
}

TEST_F( TypedVarTest, GetField )
{
    EXPECT_THROW( loadTypedVar(L"ucharVar")->getElement(L"nofield"), TypeException );
    EXPECT_THROW( loadTypedVar(L"g_structTest")->getElement(L"nofield"), TypeException );
    EXPECT_EQ( g_structTest.m_field1, *loadTypedVar(L"g_structTest")->getElement(L"m_field1") );
    EXPECT_EQ( g_structWithNested.m_unnameStruct.m_field2, *loadTypedVar(L"g_structWithNested")->getElement(L"m_unnameStruct.m_field2") );
}

TEST_F( TypedVarTest, GetElementCount )
{
    EXPECT_THROW( loadTypedVar(L"ucharVar")->getElementCount(), TypeException );
    EXPECT_THROW( loadTypedVar(L"g_structTestPtr")->getElementCount(), TypeException );
    EXPECT_EQ( 5, loadTypedVar(L"g_structTest")->getElementCount() );
    EXPECT_EQ( ARRAYSIZE(g_testArray), loadTypedVar(L"g_testArray")->getElementCount() );
}

TEST_F( TypedVarTest, GetElementByIndex )
{
    EXPECT_THROW( loadTypedVar(L"ucharVar")->getElement(0), TypeException );
    EXPECT_EQ( g_structTest.m_field1, *loadTypedVar(L"g_structTest")->getElement(1) );
    EXPECT_THROW( loadTypedVar(L"g_structTest")->getElement(10), IndexException );
    EXPECT_EQ( g_testArray[0].m_field1, *loadTypedVar(L"g_testArray")->getElement(0)->getElement(1) );
    EXPECT_NO_THROW( loadTypedVar(L"g_testArray")->getElement( ARRAYSIZE(g_testArray) + 10 ) ); 
}

TEST_F( TypedVarTest, GetElementName )
{
    EXPECT_EQ( L"m_field1", loadTypedVar(L"g_structTest")->getElementName(1) );
    EXPECT_THROW( loadTypedVar(L"g_structTest")->getElementName(10), IndexException );

    EXPECT_EQ( L"b", loadTypedVar(L"FastcallFunc")->getElementName(1) );
    EXPECT_THROW( loadTypedVar(L"FastcallFunc")->getElementName(10), IndexException );

    EXPECT_EQ( L"m_field1", loadTypedVar(L"g_structTestPtr")->deref()->getElementName(1) );

    EXPECT_THROW( loadTypedVar(L"charArray")->getElementName(1), TypeException );
    EXPECT_THROW( loadTypedVar(L"charArray")->getElementName(20), TypeException );
    EXPECT_THROW( loadTypedVar(L"ucharVar")->getElementName(0), TypeException );
}

TEST_F( TypedVarTest, ArithmOp )
{
    EXPECT_EQ( ucharVar + 20, *loadTypedVar(L"ucharVar") + 20);
}

TEST_F( TypedVarTest, Enum )
{
    TypedVarPtr  enumVar;
    ASSERT_NO_THROW( enumVar = loadTypedVar(L"g_constEnumThree") );
    EXPECT_EQ( g_constEnumThree, *enumVar );
}

TEST_F( TypedVarTest, GetType )
{
    TypedVarPtr  var;

    ASSERT_NO_THROW( var = loadTypedVar(L"g_constEnumThree") );
    EXPECT_EQ( L"enumType", var->getType()->getName() );

    ASSERT_NO_THROW( var = loadTypedVar(L"strArray") );
    EXPECT_EQ( L"Char*[2]", var->getType()->getName() );
}

TEST_F( TypedVarTest, Deref )
{
    TypedVarPtr  var;
    ASSERT_NO_THROW( var = loadTypedVar(L"pbigValue") );
    EXPECT_EQ( bigValue, *var->deref() );

    ASSERT_NO_THROW( var = loadTypedVar(L"g_listHead") );
    ASSERT_EQ( *var->getElement(L"flink")->deref()->getElement(L"flink"), *var->getElement(L"flink")->getElement(L"flink") );
}

TEST_F( TypedVarTest, ContainingRecord )
{
    TypedVarPtr   entry;
    ASSERT_NO_THROW( entry = loadTypedVar(L"g_listHead")->getElement(L"flink") );

    TypedVarPtr   liststr;
    ASSERT_NO_THROW( liststr = containingRecord( entry->getAddress(), L"listStruct", L"next.flink" ) );

    EXPECT_EQ( 0, *liststr->getElement(L"num") );
}

TEST_F( TypedVarTest, StaticMember )
{
    TypedVarPtr   var;
    ASSERT_NO_THROW( var = loadTypedVar(L"g_classChild") );

    EXPECT_EQ( g_classChild.m_staticField, *var->getElement(L"m_staticField") );
    EXPECT_EQ( g_classChild.m_staticConst, *var->getElement(L"m_staticConst") );
}


TEST_F( TypedVarTest, VirtualMember )
{
    TypedVarPtr   var;

    ASSERT_NO_THROW( var = loadTypedVar(L"g_virtChild") );
    EXPECT_EQ( -100, *var->getElement(L"m_baseField") );
    EXPECT_EQ( -100, *var->getElement(5) );

    ASSERT_NO_THROW( var = loadTypedVar(L"g_classChild") );
    EXPECT_EQ( g_classChild.m_staticField, *var->getElement(6) );
}

TEST_F( TypedVarTest, LoadTypedVarList )
{
    TypedVarList   lst;
    ASSERT_NO_THROW( lst = loadTypedVarList( m_targetModule->getSymbolVa(L"g_listHead"), L"listStruct", L"next.flink" ) );
    ASSERT_EQ( 5UL, lst.size() );
    EXPECT_EQ( 2, *lst[2]->getElement(L"num") );
}

TEST_F( TypedVarTest, LoadTypedVarArray )
{
    TypedVarList   lst;
    ASSERT_NO_THROW( lst = loadTypedVarArray( m_targetModule->getSymbolVa(L"g_testArray"), L"listStruct", 2 ));
    EXPECT_EQ( 2, lst.size() );
}

TEST_F( TypedVarTest, FuncPtr )
{
    TypedVarPtr  funcptr;
    ASSERT_NO_THROW( funcptr = loadTypedVar( L"CdeclFuncPtr" ) );
}


TEST_F( TypedVarTest, Assign )
{
    char a1 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( char(ulonglongVar), a1 );

    unsigned char a2 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( unsigned char(ulonglongVar), a2 );

    short a3 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( short(ulonglongVar), a3 );

    unsigned short a4 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( unsigned short(ulonglongVar), a4 );

    long a5 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( long(ulonglongVar), a5 );

    unsigned long a6 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( unsigned long(ulonglongVar), a6 );

    long long a7 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( long long(ulonglongVar), a7 );

    unsigned long long a8 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( unsigned long long(ulonglongVar), a8 );

    float a9 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( float(ulonglongVar), a9 );

    double a10 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( double(ulonglongVar), a10 );

    bool a11 = *loadTypedVar(L"ulonglongVar");
    ASSERT_EQ( ulonglongVar!=0, a11 );
}

TEST_F( TypedVarTest, FunctionDebugRange )
{
    TypedVarPtr funcptr;

    ASSERT_NO_THROW( funcptr = loadTypedVar( L"startChildProcess" ) );

    ASSERT_GE(std::ptrdiff_t(funcptr->getDebugStart()), std::ptrdiff_t(funcptr->getAddress()));
    ASSERT_LE(std::ptrdiff_t(funcptr->getDebugEnd()), static_cast<std::ptrdiff_t>(std::ptrdiff_t(funcptr->getAddress()) + funcptr->getSize()));
}


TEST_F(TypedVarTest, getVTBL)
{
    TypedVarPtr  vtbl;
    ASSERT_NO_THROW(vtbl = loadTypedVar(L"g_virtChild")->getElement(2)->deref());
    EXPECT_NE(std::wstring::npos, findSymbol(*vtbl->getElement(0)).find(L"virtMethod3"));

    ASSERT_NO_THROW(vtbl = loadTypedVar(L"g_virtChild")->getElement(4)->deref());
    EXPECT_NE(std::wstring::npos, findSymbol(*vtbl->getElement(0)).find(L"virtMethod1"));
    EXPECT_NE(std::wstring::npos, findSymbol(*vtbl->getElement(1)).find(L"virtMethod2"));
}

TEST_F(TypedVarTest, FunctionCall)
{
    TypedVarPtr funcptr;

    ASSERT_NO_THROW( funcptr = loadTypedVar( L"CdeclFuncReturn" ) );
    EXPECT_EQ( 5 + 5, funcptr->call(2, 5, reinterpret_cast<void*>(loadTypedVar(L"helloStr")->getAddress()) ) );
    EXPECT_EQ( 100500 + 5, funcptr->call(2, 100500, reinterpret_cast<void*>(loadTypedVar(L"helloStr")->getAddress()) ) );

    ASSERT_NO_THROW( funcptr = loadTypedVar( L"CdeclFuncLong" ) );
    EXPECT_EQ( 0x100000000ULL + 5, funcptr->call(1, 0x100000000ULL) );
    EXPECT_EQ( 10 + 5, funcptr->call(1, (unsigned long long)10));

    //ASSERT_NO_THROW( funcptr = loadTypedVar( L"CdeclFuncFloat" ) );
    //EXPECT_FLOAT_EQ( 1.5f * 3.2f, funcptr->call(2, (float)1.5f, (float)3.2f).asFloat() );
    //EXPECT_FLOAT_EQ( 10 * -3.2f, funcptr->call(2, (float)10, (float)-3.2f).asFloat() );

    //ASSERT_NO_THROW( funcptr = loadTypedVar( L"CdeclFuncDouble" ) );
    //EXPECT_DOUBLE_EQ( (1.2 + 3.4) / 2, funcptr->call(2, (double)1.2, (double)3.4).asDouble() );
    //EXPECT_DOUBLE_EQ( (-1.2 + 7.4) / 2, funcptr->call(2, (double)-1.2, (double)7.4).asDouble() );

    ASSERT_NO_THROW( funcptr = loadTypedVar( L"StdcallFuncRet" ) );
    EXPECT_EQ( 100/2, funcptr->call(2, 2, 100 ) );
    EXPECT_EQ( 300/3, funcptr->call(2, 3, 300 ) );

    ASSERT_NO_THROW( funcptr = loadTypedVar( L"StdcallFuncLong" ) );
    EXPECT_EQ( 0x100000001 & 1, funcptr->call(2, 0x100000001, 1ULL ) );
    EXPECT_EQ( 2 & 0xF, funcptr->call(2, 2ULL, 0xFULL ) );
  

    //ASSERT_NO_THROW( funcptr = loadTypedVar( L"StdcallFuncFloat" ) );
    //EXPECT_FLOAT_EQ( 3.0f/1.5f, funcptr->call(2, 3.0f, 1.5f ) );
    //EXPECT_FLOAT_EQ( 25.0f/-0.1f, funcptr->call(2, 25.0f, -0.1f ).asFloat() );

    //ASSERT_NO_THROW(funcptr = loadTypedVar( L"StdcallFuncDouble" ) );
    //EXPECT_DOUBLE_EQ( 2.9 + 3.1, funcptr->call(2, 2.9, 3.1).asDouble() );
    //EXPECT_DOUBLE_EQ( -2.9 + 13.1, funcptr->call(2, -2.9, 13.1).asDouble() );
}

TEST_F(TypedVarTest, CustomDefineFunctionCall)
{
    TypeInfoPtr  FuncType;
    ASSERT_NO_THROW( FuncType = defineFunction( loadType(L"Void*"), kdlib::CallConv_NearStd) );
    ASSERT_NO_THROW( FuncType->appendField(L"var1", kdlib::loadType(L"WChar*") ) );
    ASSERT_NO_THROW( FuncType->appendField(L"var2", kdlib::loadType(L"UInt4B") ) );

    TypedVarPtr  funcPtr;
    ASSERT_NO_THROW( funcPtr = loadTypedVar(FuncType, 0x10000) );
}
