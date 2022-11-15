#include <RoboCatPCH.h>

void OutputMemoryStream::Write(const std::unordered_map<int, int>& inMap)
{
	const size_t elementCount = inMap.size();
	Write( elementCount );
	for(auto& KV : inMap)
	{
		Write(KV.first);
		Write(KV.second);
	}
}

void OutputMemoryStream::MallocBuffer(uint32_t inNewLength)
{
	mBuffer = static_cast<char*>(std::malloc(inNewLength));
	mCapacity = inNewLength;
}

void OutputMemoryStream::ReallocBuffer( uint32_t inNewLength )
{
	mBuffer = static_cast< char* >( std::realloc( mBuffer, inNewLength ) );
	//handle realloc failure
	//...
	mCapacity = inNewLength;
}

void OutputMemoryStream::Write( const void* inData,
								size_t inByteCount )
{
	//make sure we have space...
	uint32_t resultHead = mHead + static_cast< uint32_t >( inByteCount );
	if( resultHead > mCapacity )
	{
		ReallocBuffer( std::max( mCapacity * 2, resultHead ) );
	}
	
	//copy into buffer at head
	std::memcpy( mBuffer + mHead, inData, inByteCount );
	
	//increment head for next write
	mHead = resultHead;
}


void InputMemoryStream::Read( void* outData,
							  uint32_t inByteCount )
{
	uint32_t resultHead = mHead + inByteCount;
	if( resultHead > mCapacity )
	{
		//handle error, no data to read!
		//...
	}
	
	std::memcpy( outData, mBuffer + mHead, inByteCount );
	
	mHead = resultHead;
}

void InputMemoryStream::Read(std::unordered_map<int, int>& inMap)
{
	size_t elementCount;
	Read( elementCount );
	int key;
	int value;
	for(int i = 0; i < elementCount; ++i)
	{
		Read( key );
		Read( value );
		inMap[key] = value;
	}
}
