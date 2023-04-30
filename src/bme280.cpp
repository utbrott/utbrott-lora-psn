#include "bme280.h"
#include "debug.h"

Adafruit_BME280 sensor;

namespace bme280
{
    void sensorInit(void)
    {
        debug::printDebug(debug::INFO, "Trying to init BME280 sensor");

        Wire.setSDA(SDA_PIN);
        Wire.setSCL(SCL_PIN);

        if (!sensor.begin(SENSOR_ADDR))
        {
            debug::printDebug(debug::ERR, "BME280 not found, program halted!");
            while (true)
            {
                // Infinite loop, do not continue if no sensor found
            }
        }

        debug::printDebug(debug::INFO, "BME280 sensor connected.");
    }

    void readData(SensorData_t *data)
    {
        // Change the magnitue for easier sending
        data->temperature = (sensor.readTemperature() * 100);
        data->pressure = (sensor.readPressure() / 100.00f);
    }
}