// Библиотеки
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

// Датчик DS18B20
#define DS18B20_1 7
OneWire oneWire1(DS18B20_1);
DallasTemperature ds_sensor1(&oneWire1);

// Датчик DHT11
#define DHTPIN 4
DHT dht1(DHTPIN, DHT11);

// Выход управления помпой через реле
#define PUMP 8

// Вход датчика света
#define LIGHT_SENSOR A1

// Вход переменного резистора
#define RESISTOR A0

// Вход аналогового датчика температуры
#define LM35_SENSOR A2

// Вход датчика влажности почвы
#define SOIL_SENSOR A3

// Выходы на светодиод RGB
#define R_LED 9
#define G_LED 10
#define B_LED 11

// Выход на красный светодиод
#define RED_LED 12

// Выход на синий светодиод
#define BLUE_LED 13

void setup() {
  // Инициализация UART
  Serial.begin(115200);

  // Инициализация датчика DHT11
  dht1.begin();

  // Инициализация датчика DS18B20
  ds_sensor1.begin();

  // Инициализация выхода реле
  pinMode(PUMP, OUTPUT);
  digitalWrite(PUMP, LOW);

}

void loop() {
}

// Считывание датчиков и вывод показаний в монитор порта
void readSensorData() {
  float air_hum = dht1.readHumidity();                // Считывание влажности воздуха
  float air_temp = dht1.readTemperature();            // Считывание температуры воздуха
  Serial.print("Air temperature = ");
  Serial.println(air_temp);
  Serial.print("Air humidity = ");
  Serial.println(air_hum);

  ds_sensor1.requestTemperatures();                   // Считывание температуры воздуха
  float soil_temp = ds_sensor1.getTempCByIndex(0);
  Serial.print("Soil temperature = ");
  Serial.println(soil_temp);

  float light = analogRead(LIGHT_SENSOR) / 1023.0 * 100.0;    // Считывание датчика света
  float soil_hum = analogRead(SOIL_SENSOR) / 1023.0 * 100.0;  // Считывание влажности почвы
  Serial.print("Soil moisture = ");
  Serial.println(soil_hum);
  Serial.print("Light = ");
  Serial.println(light);
}

