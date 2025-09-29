#include "TEXHOUM_US.h"
// инициализация модуля
US::US(byte trig, byte echo) {
  _pin_TRIG=trig; pinMode(_pin_TRIG, OUTPUT);			// инициализация TRIG
  _pin_ECHO=echo; pinMode(_pin_ECHO, INPUT);			// инициализация ECHO
  _pulseinTimeout = 9445;                         // значение по умолчанию - 150 см ((150+12)*58.3)
  digitalWrite(_pin_TRIG, LOW);
}
// определение расстояния
long US::get(){
  long time = 0;
  byte k = 0;
  while ((time <= 0) and (k < 5)) { // пока не получено ненулевое значение и количество проходов меньше пяти
    k += 1;
    time=returnDelay(); // Считываем длительность импульса на выводе ECHO
    if (k >= 5) {       // Если за 5 проходов стабильно получаем 0, значит время равно таймауту pulsein
      time = 0;
    }    
  }					
  return (long)(time / 58.3f + 0.5f); // округление до ближайшего целого и вывод результата в см
}
// определение длительности
long US::returnDelay(){
  digitalWrite(_pin_TRIG, HIGH);					// Устанавливаем высокий уровень на TRIG
  delayMicroseconds(10);					// Ждём 10 мкс
  digitalWrite(_pin_TRIG, LOW);					// Устанавливаем низкий уровень на TRIG
  return pulseIn(_pin_ECHO, HIGH, _pulseinTimeout);			// Фиксируем вермя возвращения сигнала
}

void US::limit(uint16_t pulseinTimeout) { // Изменение максимального времени ожидания возврата сигнала для увеличения дальности действия
  _pulseinTimeout = (unsigned long)((pulseinTimeout + 12) * 58.3f + 0.5f); // 12 - компенсация дополнительной задержки
}

// датчики, согласно схеме
US US1(25, 23);
US US2(27, 29);
US US3(31, 33);
