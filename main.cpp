#include "mbed.h"
#include "MAX44009.h"

Serial pc(USBTX, USBRX);
I2C i2c(I2C_SDA, I2C_SCL);
MAX44009 light_sensor(&i2c, 0x4A << 1);

int main() {
    pc.printf("Hello World!\n\r");
    light_sensor.setConfig(0x40);

    while (true) {
        float lux = light_sensor.getLUXReading();

        pc.printf("Lux: %f \r\n", lux);

        wait(2);
    }
}