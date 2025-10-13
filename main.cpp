#include <Wire.h>
#include <MPU6050.h>

// MPU6050 object
MPU6050 mpu;

// Pin config
#define SDA_PIN 12
#define SCL_PIN 13
#define INT_PIN 8

void setup() {
    Serial.begin(115200);
    
    // Initialize I2C
    Wire.begin(SDA_PIN, SCL_PIN);

    // Initialize MPU6050
    Serial.println("Initializing MPU6050...");
    if (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
        Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
        while (1);
    }

    // Configure interrupt (optional)
    pinMode(INT_PIN, INPUT);

    Serial.println("MPU6050 ready!");
}

void loop() {
    // Read raw accelerometer & gyroscope data
    Vector rawAccel = mpu.readRawAccel();
    Vector rawGyro = mpu.readRawGyro();
    
    // Print accelerometer values
    Serial.print("Accel X: "); Serial.print(rawAccel.XAxis);
    Serial.print(" | Y: "); Serial.print(rawAccel.YAxis);
    Serial.print(" | Z: "); Serial.println(rawAccel.ZAxis);

    // Print gyroscope values
    Serial.print("Gyro X: "); Serial.print(rawGyro.XAxis);
    Serial.print(" | Y: "); Serial.print(rawGyro.YAxis);
    Serial.print(" | Z: "); Serial.println(rawGyro.ZAxis);

    delay(500); // Adjust delay as needed
}