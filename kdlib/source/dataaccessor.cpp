#include "stdafx.h"

#include "dataaccessorimpl.h"

namespace kdlib {

///////////////////////////////////////////////////////////////////////////////

DataAccessorPtr  getMemoryAccessor( MEMOFFSET_64  offset, size_t length) 
{
    return DataAccessorPtr( new MemoryAccessor(offset, length) );
}

///////////////////////////////////////////////////////////////////////////////

DataAccessorPtr  getEmptyAccessor()
{
    return DataAccessorPtr( new EmptyAccessor() );
}

///////////////////////////////////////////////////////////////////////////////

}