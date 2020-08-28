#include <windows.h>
#include <stdio.h>
#include <winuser.h>
#include <cmath> 
#include <cstdint>

#define PI 3.14159265

int main(int argc, char *argv[]) {
	float steps = 255.0;
	unsigned int margin, axis;
	axis = 100;
	margin = 500;

	printf("Press Ctrl+C to stop it");

	INPUT inp[3];
	memset(inp, 0, sizeof(inp));

	// Нажатие левой кнопки мыши
	// inp[1].type = INPUT_MOUSE;
	// inp[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	
	while(true) {
		for (uint16_t i = 0; i < steps; ++i)
		{
			float angle, x, y;
			angle = i * 2 * PI / steps;
			x = (axis * 2) * (std::sin(angle));
			y = axis * (std::sin(angle * 2));

			unsigned int xPos = ((margin + static_cast<int>(x)) * (65535 / GetSystemMetrics(SM_CXSCREEN)));
			unsigned int yPos = ((margin + static_cast<int>(y)) * (65535 / GetSystemMetrics(SM_CYSCREEN)));

			inp[0].type = INPUT_MOUSE;
			inp[0].mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE ; // движение мышки
		    inp[0].mi.dx = xPos;
		    inp[0].mi.dy = yPos;

		    Sleep(1);

		    SendInput(3, inp, sizeof(INPUT));
		}
	}

	// Отпускание левой кнопки
    // inp[2].type = INPUT_MOUSE;
    // inp[2].mi.dwFlags = MOUSEEVENTF_LEFTUP; 
   
   	// SendInput(3, inp, sizeof(INPUT)); 
   	
	return 0;
}