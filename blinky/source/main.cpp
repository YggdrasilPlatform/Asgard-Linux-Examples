#include <iostream>

#include <yggdrasil.h>

#include <signal.h>

int main() {
	// Define signal handler to capture CTRL + C
	static bool running = true;
	signal(SIGINT, [](int signal) {
		running = false;
	});

	// Initialize GPIO pins
	bsp::LDA.init();
	bsp::LDB.init();
	bsp::LDC.init();
	bsp::LDD.init();

	// Cleanup
	ON_SCOPE_EXIT {
		bsp::LDA.deinit();
		bsp::LDB.deinit();
		bsp::LDC.deinit();
		bsp::LDD.deinit();
	};

	// Turn all LED GPIOs into outputs
	bsp::LDA.makeOutput();
	bsp::LDB.makeOutput();
	bsp::LDC.makeOutput();
	bsp::LDD.makeOutput();

	// Blink LEDs
	while (running) {
		bsp::LDA = true;
		bsp::core::delay(250);
		bsp::LDB = true;
		bsp::core::delay(250);
		bsp::LDC = true;
		bsp::core::delay(250);
		bsp::LDD = true;
		bsp::core::delay(1000);
		bsp::LDA = false;
		bsp::core::delay(250);
		bsp::LDB = false;
		bsp::core::delay(250);
		bsp::LDC = false;
		bsp::core::delay(250);
		bsp::LDD = false;
		bsp::core::delay(1000);
	}
}
