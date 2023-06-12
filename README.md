# Proyecto-IoT: Control y monitoreo de temperatura para una incubadora de aves.
Repositorio con contenido del proyecto IoT, G11
# Resumen
Se construyó un prototipo que monitorea y regula la temperatura en un ambiente cerrado(contenedor) que simula una incubadora de huevos de gallina mediante un sensor de temperatura los LED(Diodo emisor de Luz)'s simulan el sistema de emisión de calor que es regulada automáticamente a un rango de temperatura de oscilante a los 37 grados, disminuyendo o aumentando la intensidad en los Leds. Los datos registrados de las temperaturas existentes en la incubadora son enviados   vía wi-fi a un dashboard en NodRed, dónde los resultados del monitoreo son presentados de manera gráfica y registrados en una base de datos para futuras comparaciones.
# Introducción
La crianza de polluelos de granja tiene una demanda constante a niveles globales, desde siempre ha resultado ser un producto comestible y el rápido crecimiento de los mismos ha llevado a los criadores de tal especie a buscar alternativas para su mejor producción en volumen masiva.
Teniendo el enfoque anterior, nos surge la motivación de construir   un prototipo que aboné a las múltiples opciones existentes para mejorar la gestación de polluelos de granja
# Objetivos
Objetivo General. Construir un prototipo de incubación para la gestación de huevos de aves.
Objetivos específicos principales
Armar una maqueta que simule el contenedor de incubación de huevos.
2. Armar el circuito para el correcto funcionamiento del sistema de incubación.
3. Programar el sistema de incubación en código Arduino utilizando las tarjetas Arduino Mega 2560Y las tarjetas FDTI y ESP32-CAM. Así como la acción de los diferentes dispositivos de salida(Leds, Servomotor, Motor de corriente directa, entre otros)  y entrada(sensor de temperatura DTH11).
4. Programar las interfaces gráficas de entrada, comunicación y presentación de datos.
5. Crear y almacenar los datos en un BD(Base de datos)
