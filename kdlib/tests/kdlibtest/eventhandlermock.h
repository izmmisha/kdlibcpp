#pragma once

#include "kdlib\eventhandler.h"

#include "gmock\gmock.h"

class EventHandlerMock : public kdlib::EventHandler 
{
public:
    MOCK_METHOD1( onBreakpoint, kdlib::DebugCallbackResult ( kdlib::BREAKPOINT_ID bpId ) );
    MOCK_METHOD1( onException, kdlib::DebugCallbackResult ( kdlib::ExceptionInfo &exceptionInfo ) );
    MOCK_METHOD1( onExecutionStatusChange, void ( kdlib::ExecutionStatus executionStatus ) );
    MOCK_METHOD2( onModuleLoad, kdlib::DebugCallbackResult ( kdlib::MEMOFFSET_64, const std::wstring&) );
    MOCK_METHOD2( onModuleUnload, kdlib::DebugCallbackResult ( kdlib::MEMOFFSET_64, const std::wstring&) );
    MOCK_METHOD1( onCurrentThreadChange, void(kdlib::THREAD_DEBUG_ID) );
    MOCK_METHOD0( onChangeLocalScope, void(void) );
};
