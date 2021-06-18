#include <iostream>

#include <yggdrasil.h>

int main() {

	bsp::I2CA::init();
	ON_SCOPE_EXIT { bsp::I2CA::deinit(); };

	bsp::ygg::prph::ColorSensor::init();
	bsp::ygg::prph::HumiditySensor::init();
	bsp::ygg::prph::SixAxisSensor::init();

	bsp::ygg::prph::ColorSensor::enable();
	bsp::ygg::prph::ColorSensor::startConversion();
	ON_SCOPE_EXIT { bsp::ygg::prph::ColorSensor::disable(); };

	{
		printf("[ Color Sensor ]\n");
		auto rgba8 = bsp::ygg::prph::ColorSensor::getColor8();
		printf("RGBA8: [ 0x%02x, 0x%02x, 0x%02x, 0x%02x ]\n", rgba8.r, rgba8.g, rgba8.b, rgba8.a);
		auto rgba16 = bsp::ygg::prph::ColorSensor::getColor16();
		printf("RGBA8: [ 0x%04x, 0x%04x, 0x%04x, 0x%04x ]\n", rgba16.r, rgba16.g, rgba16.b, rgba16.a);
		printf("\n");
	}
	
	{
		printf("[ Humidity Sensor ]\n");
		auto temperature = bsp::ygg::prph::HumiditySensor::getTemperature();
		printf("Temperature: %f°C\n", temperature);
		auto humidity = bsp::ygg::prph::HumiditySensor::getHumidity();
		printf("Humidity: %f%%\n", humidity);
		printf("\n");
	}

	{
		printf("[ Six-Axis Sensor ]\n");
		auto temperature = bsp::ygg::prph::SixAxisSensor::getTemperature();
		printf("Temperature: %f°C\n", temperature);
		auto [roll, pitch] = bsp::ygg::prph::SixAxisSensor::getBoardOrientation();
		printf("Orientation: [ %f°, %f° ]\n", roll, pitch);
		printf("\n");
	}

	{
		printf("[ Real Time Clock ]\n");
		auto time = bsp::ygg::prph::RealTimeClock::getTime();
		char buffer[20];
		struct tm * timeinfo;
		timeinfo = gmtime(&time);
		strftime(buffer, sizeof(buffer), "%b %d %H:%M:%S", timeinfo);
		printf("Time and Date: %s\n", buffer);
		printf("\n");
	}

}
