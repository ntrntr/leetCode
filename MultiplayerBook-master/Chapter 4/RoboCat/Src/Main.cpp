
#include <iostream>

#include "RoboCatPCH.h"

void function_test()
{
	std::cout << "hello world" << std::endl;
	OutputMemoryStream Stream;
	std::unordered_map<int, int> map{
		{1,1},
		{2,1},
		{3,1},
		{4,3},
	};
	Stream.Write(map);
	uint32_t len = Stream.GetLength();
	char* data = static_cast<char*>(std::malloc(len));
	std::memcpy(data, Stream.GetBufferPtr(), len);
	
	InputMemoryStream InputMemoryStream(data, len);
	std::unordered_map<int, int> newMap;
	InputMemoryStream.Read(newMap);
	std::cout << newMap.size() << std::endl;
}

int main(void)
{
	function_test();
	return 0;
}

// #if _WIN32
// int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow )
// {
// 	function_test();
// 	UNREFERENCED_PARAMETER( hPrevInstance );
// 	UNREFERENCED_PARAMETER( lpCmdLine );
// 	
// }
// #else
// const char** __argv;
// int __argc;
// int main(int argc, const char** argv)
// {
// 	__argc = argc;
// 	__argv = argv;
// 	
// }
// #endif

