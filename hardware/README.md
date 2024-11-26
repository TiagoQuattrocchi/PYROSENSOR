# Hardware

Todos los componentes electronicos utilizados en el proyecto:

Raspberry Pi: El microcontrolador principal, encargado de procesar los datos de la termocupla y el potenciometro de 10k, y controlar la velocidad del motor proporcionalmente en base al software implementado en el microcontrolador. 

Termocupla MAX6675: Es un módulo termopar diseñado para medir temperaturas altas. Convierte la señal analógica del termopar tipo K a una señal digital compatible con la Raspberry Pi, usando un protocolo SPI.

Potenciómetro de 10k: Actúa como un divisor de voltaje ajustable. Que la raspberry procesara y luego implementara en el software.

Motor DC 5V generico: Muestra graficamente el funcionamiento de la llave de paso de gas, empieza a funcionar cuando la temperatura seteada por el potenciometro supera los veinte grados. Y aumentara su velocidad proporcionalmente si la diferencia entre la temperatura medida y seteada es mayor a 20°.
