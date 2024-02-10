#include "System.h"

int main()
{
	//std::cout << "Hello World";

	System Solar;

	while (Solar.isRunning())
	{
		Solar.Update();


		Solar.Render();
	}

	return 0;
}