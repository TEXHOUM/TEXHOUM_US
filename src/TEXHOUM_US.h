//  Библиотека для упарвления моторами постоянного тока с помощью драйвера L298N
//  Автор библиотеки: Коркин Максим Валерьевич, Пятов Антон Витальевич

#ifndef TEXHOUM_US_h
#define TEXHOUM_US_h
#include <Arduino.h>

class	US{
	public:
	        US(byte trig, byte echo);	//	Инициализация (pin TRIG, pin ECHO)
		long get();		//	Определение расстояния
		void limit(uint16_t pulseinTimeout); // Порог дальности действия в см, по умолчанию 150
	private:
		long returnDelay();		//	Время ECHO
		byte _pin_TRIG;		//	Номер вывода подключённого к TRIG
		byte _pin_ECHO;		//	Номер вывода подключённого к ECHO
		uint16_t _pulseinTimeout;
};

extern US US1;
extern US US2;
extern US US3;

#endif
