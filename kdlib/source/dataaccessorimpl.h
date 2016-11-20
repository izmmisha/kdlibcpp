#pragma once

#include <boost/noncopyable.hpp>

#include "kdlib/dataaccessor.h"
#include "kdlib/memaccess.h"
#include "kdlib/exceptions.h"
#include "kdlib/cpucontext.h"

namespace kdlib {

///////////////////////////////////////////////////////////////////////////////

class EmptyAccessor : public DataAccessor
{
private:

    virtual size_t getLength() const
    {
        throw DbgException("data accessor no data");
    }

    virtual unsigned char readByte(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeByte(unsigned char value, size_t pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeByte(size_t pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual char readSignByte(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignByte(char value, size_t pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual unsigned short readWord(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeWord(unsigned short value, size_t pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual short readSignWord(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignWord(short value, size_t pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual unsigned long readDWord(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeDWord(unsigned long value, size_t pos)
    {
        throw DbgException("data accessor no data");
    }

    virtual long readSignDWord(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignDWord(long value, size_t pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual unsigned long long readQWord(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeQWord(unsigned long long value, size_t pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual long long readSignQWord(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignQWord(long long value, size_t pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual float readFloat(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeFloat(float value, size_t pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual double readDouble(size_t pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeDouble(double value, size_t pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readBytes(std::vector<unsigned char>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeBytes( const std::vector<unsigned char>&  dataRange, size_t pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual void readWords(std::vector<unsigned short>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeWords( const std::vector<unsigned short>&  dataRange, size_t pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual void readDWords(std::vector<unsigned long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeDWords( const std::vector<unsigned long>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readQWords(std::vector<unsigned long long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeQWords( const std::vector<unsigned long long>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignBytes(std::vector<char>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignBytes( const std::vector<char>&  dataRange, size_t  pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignWords(std::vector<short>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignWords( const std::vector<short>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignDWords(std::vector<long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignDWords( const std::vector<long>&  dataRange, size_t  pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignQWords(std::vector<long long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeSignQWords( const std::vector<long long>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readFloats(std::vector<float>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeFloats( const std::vector<float>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readDoubles(std::vector<double>&  dataRange, size_t count, size_t  pos = 0) const
    {
        throw DbgException("data accessor no data");
    }

    virtual void writeDoubles( const std::vector<double>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual MEMOFFSET_64 getAddress() const
    {
        throw DbgException("data accessor no data");
    }

    virtual VarStorage getStorageType() const
    {
        return UnknownVar;
    }

    virtual std::wstring getRegisterName() const
    {
        throw DbgException("data accessor no data");
    }
};

///////////////////////////////////////////////////////////////////////////////

class MemoryAccessor : public EmptyAccessor
{
public:

    MemoryAccessor(MEMOFFSET_64 offset, size_t length) :
        m_begin(addr64(offset)),
        m_length(length)
    {}

private:

    virtual size_t getLength() const
    {
        return m_length;
    }

    virtual unsigned char readByte(size_t pos = 0) const
    {
        if (pos >= m_length)
            throw DbgException("memory accessor range error");

        return ptrByte(m_begin + pos);
    }

    virtual void writeByte(unsigned char value, size_t pos=0) 
    {
        if (pos >= m_length)
            throw DbgException("memory accessor range error");

        setByte(m_begin + pos, value);
    }

    virtual char readSignByte(size_t pos = 0) const
    {
        if (pos >= m_length)
            throw DbgException("memory accessor range error");
        return ptrSignByte(m_begin + pos);
    }

    virtual void writeSignByte(char value, size_t pos=0)
    {
        if (pos >= m_length)
            throw DbgException("memory accessor range error");
        setSignByte(m_begin + pos, value);
    }

    virtual unsigned short readWord(size_t pos = 0) const
    {
        if (pos >= m_length / sizeof(unsigned short) )
            throw DbgException("memory accessor range error");
        return ptrWord(m_begin + pos * sizeof(unsigned short));
    }

    virtual void writeWord(unsigned short value, size_t pos=0)
    {
        if (pos >= m_length / sizeof(unsigned short) )
            throw DbgException("memory accessor range error");
        setWord(m_begin + pos * sizeof(unsigned short), value);
    }

    virtual short readSignWord(size_t pos = 0) const
    {
        if (pos  >= m_length / sizeof(short) )
            throw DbgException("memory accessor range error");
        return ptrSignWord(m_begin + pos * sizeof(short));
    }

    virtual void writeSignWord(short value, size_t pos=0)
    {
        if (pos >= m_length / sizeof(short) )
            throw DbgException("memory accessor range error");
        setSignWord(m_begin + pos * sizeof(short), value);
    }

    virtual unsigned long readDWord(size_t pos = 0) const
    {
        if (pos >= m_length / sizeof(unsigned long) )
            throw DbgException("memory accessor range error");
        return ptrDWord(m_begin + pos * sizeof(unsigned long));
    }

    virtual void writeDWord(unsigned long value, size_t pos)
    {
        if (pos >= m_length / sizeof(unsigned long) )
            throw DbgException("memory accessor range error");
        setDWord(m_begin + pos * sizeof(unsigned long), value);
    }

    virtual long readSignDWord(size_t pos = 0) const
    {
        if (pos >= m_length /sizeof(long) )
            throw DbgException("memory accessor range error");
        return ptrSignDWord(m_begin + pos * sizeof(long));
    }

    virtual void writeSignDWord(long value, size_t pos=0)
    {
        if (pos >= m_length /sizeof(long) )
            throw DbgException("memory accessor range error");
        setSignDWord(m_begin + pos * sizeof(long), value);
    }

    virtual unsigned long long readQWord(size_t pos = 0) const
    {
        if (pos >= m_length / sizeof(unsigned long long) )
            throw DbgException("memory accessor range error");
        return ptrQWord(m_begin + pos * sizeof(unsigned long long));
    }

    virtual void writeQWord(unsigned long long value, size_t pos=0)
    {
        if (pos >= m_length / sizeof(unsigned long long) )
            throw DbgException("memory accessor range error");
        setQWord(m_begin + pos * sizeof(unsigned long long), value);
    }

    virtual long long readSignQWord(size_t pos = 0) const
    {
        if ( pos >= m_length / sizeof(long long) )
            throw DbgException("memory accessor range error");
        return ptrSignQWord(m_begin + pos * sizeof(long long));
    }

    virtual void writeSignQWord(long long value, size_t pos=0) 
    {
        if ( pos >= m_length / sizeof(long long) )
            throw DbgException("memory accessor range error");
        setSignQWord(m_begin + pos * sizeof(long long), value);
    }

    virtual float readFloat(size_t pos = 0) const
    {
        if (pos >= m_length / sizeof(float) )
            throw DbgException("memory accessor range error");
        return ptrSingleFloat(m_begin + pos * sizeof(float));
    }

    virtual void writeFloat(float value, size_t pos=0) 
    {
        if (pos >= m_length / sizeof(float) )
            throw DbgException("memory accessor range error");

        setSingleFloat(m_begin + pos * sizeof(float), value);
    }

    virtual double readDouble(size_t pos = 0) const
    {
        if (pos >= m_length / sizeof(double) )
            throw DbgException("memory accessor range error");
        return ptrDoubleFloat(m_begin + pos * sizeof(double));
    }

    virtual void writeDouble(double value, size_t pos=0)
    {
        if (pos >= m_length / sizeof(double) )
            throw DbgException("memory accessor range error");
        
        setDoubleFloat(m_begin + pos * sizeof(double), value);
    }

    virtual void readBytes(std::vector<unsigned char>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length - pos )
            throw DbgException("memory accessor range error");
 
        dataRange = loadBytes(m_begin + pos, static_cast<unsigned long>(count) );
    }

    virtual void writeBytes( const std::vector<unsigned char>&  dataRange, size_t pos=0) 
    {
        if ( dataRange.size() > m_length - pos )
            throw DbgException("memory accessor range error");
        kdlib::writeBytes(m_begin + pos, dataRange);
    }

    virtual void readWords(std::vector<unsigned short>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(unsigned short) - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadWords(m_begin + pos* sizeof(unsigned short), static_cast<unsigned long>(count) );
    }

    virtual void writeWords( const std::vector<unsigned short>&  dataRange, size_t pos=0) 
    {
        if ( dataRange.size() > m_length / sizeof(unsigned short) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeWords(m_begin + pos* sizeof(unsigned short), dataRange);
    }

    virtual void readDWords(std::vector<unsigned long>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(unsigned long) - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadDWords(m_begin + pos* sizeof(unsigned long), static_cast<unsigned long>(count) );
    }

    virtual void writeDWords( const std::vector<unsigned long>&  dataRange, size_t  pos=0)
    {
        if ( dataRange.size() > m_length / sizeof(unsigned long) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeDWords(m_begin + pos* sizeof(unsigned long), dataRange);
    }

    virtual void readQWords(std::vector<unsigned long long>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(unsigned long long) - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadQWords(m_begin + pos* sizeof(unsigned long long), static_cast<unsigned long>(count) );
    }

    virtual void writeQWords( const std::vector<unsigned long long>&  dataRange, size_t  pos=0)
    {
        if ( dataRange.size() > m_length / sizeof(unsigned long long) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeQWords(m_begin + pos * sizeof(unsigned long long), dataRange);
    }

    virtual void readSignBytes(std::vector<char>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadSignBytes(m_begin + pos* sizeof(char), static_cast<unsigned long>(count) );
    }

    virtual void writeSignBytes( const std::vector<char>&  dataRange, size_t  pos=0)
    {
        if ( dataRange.size() > m_length  - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeSignBytes(m_begin + pos, dataRange);
    }

    virtual void readSignWords(std::vector<short>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(short) - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadSignWords(m_begin + pos* sizeof(short), static_cast<unsigned long>(count) );
    }

    virtual void writeSignWords( const std::vector<short>&  dataRange, size_t  pos=0)
    {
        if ( dataRange.size() > m_length / sizeof(short) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeSignWords(m_begin + pos * sizeof(short), dataRange);
    }

    virtual void readSignDWords(std::vector<long>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(long) - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadSignDWords(m_begin + pos* sizeof(long), static_cast<unsigned long>(count));
    }

    virtual void writeSignDWords( const std::vector<long>&  dataRange, size_t  pos=0)
    {
        if ( dataRange.size() > m_length / sizeof(long) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeSignDWords(m_begin + pos * sizeof(long), dataRange);
    }

    virtual void readSignQWords(std::vector<long long>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(long long) - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadSignQWords(m_begin + pos* sizeof(long long), static_cast<unsigned long>(count) );
    }

    virtual void writeSignQWords( const std::vector<long long>&  dataRange, size_t  pos=0)
    {
        if ( dataRange.size() > m_length / sizeof(long long) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeSignQWords(m_begin + pos * sizeof(long long), dataRange);
    }

    virtual void readFloats(std::vector<float>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(float) - pos )
            throw DbgException("memory accessor range error");

        dataRange = loadFloats(m_begin + pos* sizeof(float), static_cast<unsigned long>(count));
    }

    virtual void writeFloats( const std::vector<float>&  dataRange, size_t  pos=0) 
    {
        if ( dataRange.size() > m_length / sizeof(float) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeFloats(m_begin + pos * sizeof(float), dataRange);
    }

    virtual void readDoubles(std::vector<double>& dataRange, size_t count, size_t pos = 0) const
    {
        if ( count > m_length / sizeof(double) || pos > m_length / sizeof(double) - count )
            throw DbgException("memory accessor range error");

        dataRange = loadDoubles(m_begin + pos* sizeof(double), static_cast<unsigned long>(count));
    }

    virtual void writeDoubles( const std::vector<double>&  dataRange, size_t  pos=0) 
    {
        if ( dataRange.size() > m_length / sizeof(double) - pos )
            throw DbgException("memory accessor range error");

        kdlib::writeDoubles(m_begin + pos * sizeof(double), dataRange);
    }

    virtual MEMOFFSET_64 getAddress() const {
        return m_begin;
    }

    virtual VarStorage getStorageType() const
    {
        return MemoryVar;
    }


private:

    MEMOFFSET_64  m_begin;
    size_t  m_length;
};


///////////////////////////////////////////////////////////////////////////////

class CacheAccessor : public EmptyAccessor
{
public:

    CacheAccessor(const std::vector<char>& buffer) :
        m_buffer(buffer)
    {}

    CacheAccessor(size_t size):
        m_buffer(size)
    {}

private:

    virtual size_t getLength() const
    {
        return m_buffer.size();
    }

    virtual unsigned char readByte(size_t pos = 0) const
    {
        return getValue<unsigned char>(pos);
    }

    virtual void writeByte(unsigned char value, size_t pos=0) 
    {
        setValue<unsigned char>(value,pos);
    }

    virtual char readSignByte(size_t pos = 0) const
    {
        return getValue<char>(pos);
    }

    virtual void writeSignByte(char value, size_t pos=0) 
    {
        setValue<char>(value,pos);
    }

    virtual unsigned short readWord(size_t pos = 0) const
    {
        return getValue<unsigned short>(pos);
    }

    virtual void writeWord(unsigned short value, size_t pos=0) 
    {
        setValue<unsigned short>(value,pos);
    }

    virtual short readSignWord(size_t pos = 0) const
    {
        return getValue<short>(pos);
    }

    virtual void writeSignWord(short value, size_t pos=0)
    {
        setValue<short>(value,pos);
    }

    virtual unsigned long readDWord(size_t pos = 0) const
    {
        return getValue<unsigned long>(pos);
    }

    virtual void writeDWord(unsigned long value, size_t pos)
    {
        setValue<unsigned long>(value,pos);
    }

    virtual long readSignDWord(size_t pos = 0) const
    {
        return getValue<long>(pos);
    }

    virtual void writeSignDWord(long value, size_t pos=0) 
    {
        setValue<long>(value,pos);
    }

    virtual unsigned long long readQWord(size_t pos = 0) const
    {
        return getValue<unsigned long long>(pos);
    }

    virtual void writeQWord(unsigned long long value, size_t pos=0) 
    {
        setValue<unsigned long long>(value,pos);
    }

    virtual long long readSignQWord(size_t pos = 0) const
    {
        return getValue<long long>(pos);
    }

    virtual void writeSignQWord(long long value, size_t pos=0) 
    {
        setValue<long long>(value,pos);
    }

    virtual float readFloat(size_t pos = 0) const
    {
        return getValue<float>(pos);
    }

    virtual void writeFloat(float value, size_t pos=0)
    {
        setValue<float>(value,pos);
    }

    virtual double readDouble(size_t pos = 0) const
    {
        return getValue<double>(pos);
    }

    virtual void writeDouble(double value, size_t pos=0) 
    {
        setValue<double>(value,pos);
    }

    virtual void readBytes(std::vector<unsigned char>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<unsigned char>(dataRange, count, pos);
    }

    virtual void writeBytes( const std::vector<unsigned char>&  dataRange, size_t pos=0)
    {
        writeValues<unsigned char>(dataRange, pos);
    }

    virtual void readWords(std::vector<unsigned short>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<unsigned short>(dataRange, count, pos);
    }

    virtual void writeWords( const std::vector<unsigned short>&  dataRange, size_t pos=0)
    {
        writeValues<unsigned short>(dataRange, pos);
    }

    virtual void readDWords(std::vector<unsigned long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<unsigned long>(dataRange, count, pos);
    }

    virtual void writeDWords( const std::vector<unsigned long>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readQWords(std::vector<unsigned long long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<unsigned long long>(dataRange, count, pos);
    }

    virtual void writeQWords( const std::vector<unsigned long long>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignBytes(std::vector<char>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<char>(dataRange, count, pos);
    }

    virtual void writeSignBytes( const std::vector<char>&  dataRange, size_t  pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignWords(std::vector<short>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<short>(dataRange, count, pos);
    }

    virtual void writeSignWords( const std::vector<short>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignDWords(std::vector<long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<long>(dataRange, count, pos);
    }

    virtual void writeSignDWords( const std::vector<long>&  dataRange, size_t  pos=0)
    {
        throw DbgException("data accessor no data");
    }

    virtual void readSignQWords(std::vector<long long>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<long long>(dataRange, count, pos);
    }

    virtual void writeSignQWords( const std::vector<long long>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readFloats(std::vector<float>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<float>(dataRange, count, pos);
    }

    virtual void writeFloats( const std::vector<float>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual void readDoubles(std::vector<double>&  dataRange, size_t count, size_t  pos = 0) const
    {
        readValues<double>(dataRange, count, pos);
    }

    virtual void writeDoubles( const std::vector<double>&  dataRange, size_t  pos=0) 
    {
        throw DbgException("data accessor no data");
    }

    virtual MEMOFFSET_64 getAddress() const
    {
        throw DbgException("data accessor no data");
    }

    virtual VarStorage getStorageType() const
    {
        return UnknownVar;
    }

    virtual std::wstring getRegisterName() const
    {
        throw DbgException("data accessor no data");
    }

private:

    std::vector<char>  m_buffer;

    template <typename T>
    T getValue(size_t pos) const
    {
        if ( pos >= m_buffer.size() / sizeof(T) )
            throw DbgException("cache accessor range error");

        return *reinterpret_cast<const T*>( &m_buffer[pos*sizeof(T)] );
    }

    template <typename T>
    void setValue(T& value, size_t pos)
    {
        if ( pos >= m_buffer.size() / sizeof(T) )
            throw DbgException("cache accessor range error");

        *reinterpret_cast<T*>( &m_buffer[pos*sizeof(T)] ) = value;
    }

    template <typename T>
    void readValues(std::vector<T>& dataRange, size_t count, size_t pos) const
    {
        if ( count > m_buffer.size() / sizeof(T)  - pos)
            throw DbgException("cache accessor range error");

        dataRange = std::vector<T>(
            reinterpret_cast<const T*>(&m_buffer[pos*sizeof(T)]), 
            reinterpret_cast<const T*>(&m_buffer[pos*sizeof(T)]) + count );
    }

    template <typename T>
    void writeValues( const std::vector<T>&  dataRange, size_t pos) 
    {
        if ( dataRange.size() > m_buffer.size() / sizeof(T) - pos )
            throw DbgException("cache accessor range error");

        memcpy( &m_buffer[pos*sizeof(T)], &dataRange[0], dataRange.size()*sizeof(T) );
    }
};

///////////////////////////////////////////////////////////////////////////////

class VariantAccessor : public EmptyAccessor
{
public:
    VariantAccessor(const NumVariant& var) :
        m_variant(var)
        {}

    virtual MEMOFFSET_64 getAddress() const
    {
        return ~0;
    }

    virtual unsigned char readByte(size_t pos = 0) const
    {
        return m_variant.asUChar();
    }

    virtual void writeByte(unsigned char value, size_t pos=0)
    {
    }

    virtual char readSignByte(size_t pos = 0) const
    {
        return m_variant.asChar();
    }

    virtual unsigned short readWord(size_t pos = 0) const
    {
        return m_variant.asUShort();
    }

    virtual short readSignWord(size_t pos = 0) const
    {
        return m_variant.asShort();
    }

    virtual unsigned long readDWord(size_t pos = 0) const
    {
        return m_variant.asULong();
    }

    virtual long readSignDWord(size_t pos = 0) const
    {
        return m_variant.asLong();
    }

    virtual unsigned long long readQWord(size_t pos = 0) const
    {
        return m_variant.asULongLong();
    }

    virtual long long readSignQWord(size_t pos = 0) const
    {
        return m_variant.asLongLong();
    }

private:
    NumVariant m_variant;
};

///////////////////////////////////////////////////////////////////////////////

class RegisterAccessor : public EmptyAccessor
{
public:

    RegisterAccessor( const std::wstring& registerName) :
        m_regName(registerName)
     {}


    virtual VarStorage getStorageType() const
    {
        return RegisterVar;
    }

    virtual std::wstring getRegisterName() const
    {
        return m_regName;
    }

    virtual size_t getLength() const
    {
        unsigned long  regIndex = kdlib::getRegsiterIndex(m_regName);
        return kdlib::getRegisterSize(regIndex);
    }


    virtual unsigned char readByte(size_t pos = 0) const
    {
        return getValue<unsigned char>(pos);
    }

    virtual void writeByte(unsigned char value, size_t pos=0) 
    {
        setValue<unsigned char>(value, pos);
    }

    virtual char readSignByte(size_t pos = 0) const
    {
        return getValue<char>(pos);
    }

    virtual void writeSignByte(char value, size_t pos=0)
    {
        setValue<char>(value, pos);
    }

    virtual unsigned short readWord(size_t pos = 0) const
    {
        return getValue<unsigned short>(pos);
    }

    virtual void writeWord(unsigned short value, size_t pos=0)
    {
        setValue<unsigned short>(value, pos);
    }

    virtual short readSignWord(size_t pos = 0) const
    {
        return getValue<short>(pos);
    }

    virtual void writeSignWord(short value, size_t pos=0)
    {
        setValue<short>(value, pos);
    }

    virtual unsigned long readDWord(size_t pos = 0) const
    {
        return getValue<unsigned long>(pos);
    }

    virtual void writeDWord(unsigned long value, size_t pos)
    {
        setValue<unsigned long>(value, pos);
    }

    virtual long readSignDWord(size_t pos = 0) const
    {
        return getValue<long>(pos);
    }

    virtual void writeSignDWord(long value, size_t pos=0)
    {
        setValue<long>(value, pos);
    }

    virtual unsigned long long readQWord(size_t pos = 0) const
    {
        return getValue<unsigned long long>(pos);
    }

    virtual void writeQWord(unsigned long long value, size_t pos=0)
    {
        setValue<unsigned long long>(value, pos);
    }

    virtual long long readSignQWord(size_t pos = 0) const
    {
        return getValue<long long>(pos);
    }

    virtual void writeSignQWord(long long value, size_t pos=0) 
    {
        setValue<long long>(value, pos);
    }

    virtual float readFloat(size_t pos = 0) const
    {
        return getValue<float>(pos);
    }

    virtual void writeFloat(float value, size_t pos=0) 
    {
        setValue<float>(value, pos);
    }

    virtual double readDouble(size_t pos = 0) const
    {
        return getValue<double>(pos);
    }

    virtual void writeDouble(double value, size_t pos=0)
    {
        setValue<double>(value, pos);
    }

    virtual void readBytes(std::vector<unsigned char>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<unsigned char>(dataRange, count, pos);
    }

    virtual void writeBytes( const std::vector<unsigned char>&  dataRange, size_t pos=0) 
    {
       writeValues<unsigned char>(dataRange, pos);
    }

    virtual void readWords(std::vector<unsigned short>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<unsigned short>(dataRange, count, pos);
    }

    virtual void writeWords( const std::vector<unsigned short>&  dataRange, size_t pos=0) 
    {
        writeValues<unsigned short>(dataRange, pos);
    }

    virtual void readDWords(std::vector<unsigned long>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<unsigned long>(dataRange, count, pos);
    }

    virtual void writeDWords( const std::vector<unsigned long>&  dataRange, size_t  pos=0)
    {
        writeValues<unsigned long>(dataRange, pos);
    }

    virtual void readQWords(std::vector<unsigned long long>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<unsigned long long>(dataRange, count, pos);
    }

    virtual void writeQWords( const std::vector<unsigned long long>&  dataRange, size_t  pos=0)
    {
        writeValues<unsigned long long>(dataRange, pos);
    }

    virtual void readSignBytes(std::vector<char>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<char>(dataRange, count, pos);
    }

    virtual void writeSignBytes( const std::vector<char>&  dataRange, size_t  pos=0)
    {
        writeValues<char>(dataRange, pos);
    }

    virtual void readSignWords(std::vector<short>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<short>(dataRange, count, pos);
    }

    virtual void writeSignWords( const std::vector<short>&  dataRange, size_t  pos=0)
    {
        writeValues<short>(dataRange, pos);
    }

    virtual void readSignDWords(std::vector<long>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<long>(dataRange, count, pos);
    }

    virtual void writeSignDWords( const std::vector<long>&  dataRange, size_t  pos=0)
    {
        writeValues<long>(dataRange, pos);
    }

    virtual void readSignQWords(std::vector<long long>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<long long>(dataRange, count, pos);
    }

    virtual void writeSignQWords( const std::vector<long long>&  dataRange, size_t  pos=0)
    {
        writeValues<long long>(dataRange, pos);
    }

    virtual void readFloats(std::vector<float>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<float>(dataRange, count, pos);
    }

    virtual void writeFloats( const std::vector<float>&  dataRange, size_t  pos=0) 
    {
        writeValues<float>(dataRange, pos);
    }

    virtual void readDoubles(std::vector<double>& dataRange, size_t count, size_t pos = 0) const
    {
        readValues<double>(dataRange, count, pos);
    }

    virtual void writeDoubles( const std::vector<double>&  dataRange, size_t  pos=0) 
    {
        writeValues<double>(dataRange, pos);
    }

private:

    template <typename T>
    T getValue(size_t pos) const
    {
        unsigned long  regIndex = kdlib::getRegsiterIndex(m_regName);
        size_t  regSize = kdlib::getRegisterSize(regIndex);
        if ( pos >= regSize/sizeof(T) )
            throw DbgException("register accessor range error");

        std::vector<char>  regValue(regSize);
        kdlib::getRegisterValue(regIndex, &regValue[0], regSize);

        return *reinterpret_cast<T*>( &regValue[pos*sizeof(T)] );
    }

    template <typename T>
    void setValue(T& value, size_t pos)
    {
        unsigned long  regIndex = kdlib::getRegsiterIndex(m_regName);
        size_t  regSize = kdlib::getRegisterSize(regIndex);
        if ( pos >= regSize/sizeof(T) )
            throw DbgException("register accessor range error");

        std::vector<char>  regValue(regSize);
        kdlib::getRegisterValue(regIndex, &regValue[0], regSize);

        *reinterpret_cast<T*>( &regValue[pos*sizeof(T)] ) = value;

        kdlib::setRegisterValue(regIndex, &regValue[0], regSize);
    }

    template <typename T>
    void readValues(std::vector<T>& dataRange, size_t count, size_t pos) const
    {
        unsigned long  regIndex = kdlib::getRegsiterIndex(m_regName);
        size_t  regSize = kdlib::getRegisterSize(regIndex);
        if ( count > regSize/sizeof(T)  - pos)
            throw DbgException("register accessor range error");

        std::vector<char>  regValue(regSize);
        kdlib::getRegisterValue(regIndex, &regValue[0], regSize);

        dataRange = std::vector<T>(
            reinterpret_cast<T*>(&regValue[pos*sizeof(T)]), 
            reinterpret_cast<T*>(&regValue[pos*sizeof(T)]) + count );
    }

    template <typename T>
    void writeValues( const std::vector<T>&  dataRange, size_t pos) 
    {
        unsigned long  regIndex = kdlib::getRegsiterIndex(m_regName);
        size_t  regSize = kdlib::getRegisterSize(regIndex);
        if ( dataRange.size() > regSize/sizeof(T) - pos )
            throw DbgException("register accessor range error");

        std::vector<T>  regValue(regSize/sizeof(T));
        kdlib::getRegisterValue(regIndex, &regValue[0], regSize);

        std::copy( dataRange.begin(), dataRange.end(), regValue.begin() + pos );

        kdlib::setRegisterValue(regIndex, &regValue[0], regSize);
    }

    std::wstring  m_regName;
};

///////////////////////////////////////////////////////////////////////////////

}
