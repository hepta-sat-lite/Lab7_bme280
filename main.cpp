#include "mbed.h"
#include "BME280.h"

//I2Cピン定義
#define SCL_PIN PB_6
#define SDA_PIN PB_7

I2C i2c(SDA_PIN, SCL_PIN);
BME280 sensor(i2c); 

int main() {
    printf("BME280 Sensor Test\r\n");

    while(1) {
        float temp = sensor.getTemperature();
        float humidity = sensor.getHumidity();
        float pressure = sensor.getPressure();

        printf("Temperature: %.2f C\r\n", temp);
        printf("Humidity: %.2f \r\n", humidity);
        printf("Pressure: %.2f hPa\r\n", pressure); //hPa単位で取得できる

        wait(1.0);
    }
}
