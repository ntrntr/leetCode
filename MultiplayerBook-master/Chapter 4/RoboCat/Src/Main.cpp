
#include <iostream>

#include "RoboCatPCH.h"

void function_test()
{
	std::cout << "hello world" << std::endl;
	OutputMemoryStream Stream;
	Stream.Write(std::string("abc"));
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

