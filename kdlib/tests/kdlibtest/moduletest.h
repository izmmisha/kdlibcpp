#pragma once

#include "processtest.h"
#include "kdlib/module.h"
#include "kdlib/memaccess.h"
#include "kdlib/exceptions.h"

using namespace kdlib;

class ModuleTest : public ProcessTest 
{
};

TEST_F( ModuleTest, Ctor )
{
    std::wstring  targetname = m_targetModule->getName();
    MEMOFFSET_64  targetstart = m_targetModule->getBase();

    EXPECT_EQ( targetname, loadModule( targetname )->getName() );
    EXPECT_EQ( targetname, loadModule( targetstart )->getName() );
}

TEST_F( ModuleTest, getSize )
{
    EXPECT_NE( 0, m_targetModule->getSize() );
}

TEST_F( ModuleTest, getBase )
{
    EXPECT_NE( 0, m_targetModule->getBase() );
    EXPECT_EQ( m_targetModule->getBase(), *m_targetModule );
    EXPECT_EQ( m_targetModule->getBase() + 0x100, 0x100 + *m_targetModule );
}

TEST_F( ModuleTest, getEnd )
{
    EXPECT_EQ( m_targetModule->getSize(), m_targetModule->getEnd() -  m_targetModule->getBase() );
    EXPECT_TRUE( isVaValid( m_targetModule->getEnd() - 1 ) );
    EXPECT_FALSE( isVaValid( m_targetModule->getEnd() + 1 ) );
}

TEST_F( ModuleTest, getSymFile )
{
    EXPECT_FALSE( m_targetModule->getSymFile().empty() );
}

TEST_F( ModuleTest, getImageName )
{
    EXPECT_EQ( L"targetapp.exe",  m_targetModule->getImageName() );
}

TEST_F( ModuleTest, findByAddr )
{
    EXPECT_THROW( loadModule( m_targetModule->getBase() - 1 ), DbgException );
    EXPECT_NO_THROW( loadModule( m_targetModule->getBase() ) );
    EXPECT_NO_THROW( loadModule( m_targetModule->getBase() + 1 ) );
    EXPECT_THROW( loadModule( m_targetModule->getEnd() + 1 ), DbgException );
}

TEST_F( ModuleTest, getSymbolVa )
{
    EXPECT_NE( 0, m_targetModule->getSymbolVa(L"helloStr") );
    EXPECT_EQ( m_targetModule->getSymbolVa(L"g_structTest"), ptrPtr(  m_targetModule->getSymbolVa(L"g_structTestPtr") ) );
}

TEST_F( ModuleTest, getTypeByName )
{
    EXPECT_EQ( L"structTest", m_targetModule->getTypeByName(L"structTest")->getName() );
    EXPECT_EQ( L"structTest", m_targetModule->getTypeByName(L"g_structTest")->getName() );
}

