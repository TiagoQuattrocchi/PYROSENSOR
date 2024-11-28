# Firmware

Main.c: Lee los valores analogicos del potenciometro mediante ADC y los escala al rango deseado, y tambien los valores de temperatura salidos del modulo max6675, hace la diferencia de estos y se utiliza PWM en una salida para mover el motor de manera proporcional teniendo en cuenta esta diferencia de mediciones.

max6675.h: Biblioteca diseñada para interactuar con el sensor de temperatura MAX6675. Proporciona las estructuras y funciones necesarias para configurar y leer datos del sensor.
