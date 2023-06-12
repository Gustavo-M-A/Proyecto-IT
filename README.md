# Proyecto-IoT: Control y monitoreo de temperatura para una incubadora de aves.
Repositorio con contenido del proyecto IoT, G11
## Resumen
Se construyó un prototipo que monitorea y regula la temperatura en un ambiente cerrado(contenedor) que simula una incubadora de huevos de gallina mediante un sensor de temperatura los LED(Diodo emisor de Luz)'s simulan el sistema de emisión de calor que es regulada automáticamente a un rango de temperatura de oscilante a los 37 grados, disminuyendo o aumentando la intensidad en los Leds. Los datos registrados de las temperaturas existentes en la incubadora son enviados   vía wi-fi a un dashboard en NodRed, dónde los resultados del monitoreo son presentados de manera gráfica y registrados en una base de datos para futuras comparaciones.
##  Introducción
La crianza de polluelos de granja tiene una demanda constante a niveles globales, desde siempre ha resultado ser un producto comestible y el rápido crecimiento de los mismos ha llevado a los criadores de tal especie a buscar alternativas para su mejor producción en volumen masiva.
Teniendo el enfoque anterior, nos surge la motivación de construir   un prototipo que aboné a las múltiples opciones existentes para mejorar la gestación de polluelos de granja
##  Objetivos
Objetivo General. Construir un prototipo de incubación para la gestación de huevos de aves.
Objetivos específicos principales
Armar una maqueta que simule el contenedor de incubación de huevos.
2. Armar el circuito para el correcto funcionamiento del sistema de incubación.
3. Programar el sistema de incubación en código Arduino utilizando las tarjetas Arduino Mega 2560Y las tarjetas FDTI y ESP32-CAM. Así como la acción de los diferentes dispositivos de salida(Leds, Servomotor, Motor de corriente directa, entre otros)  y entrada(sensor de temperatura DTH11).
4. Programar las interfaces gráficas de entrada, comunicación y presentación de datos.
5. Crear y almacenar los datos en un BD(Base de datos)

## Requerimientos para llevar a cabo el proyecto
Software:

     • Conexión a internet.
    • Ubuntu 20.04.
    • IDE Arduino.
    • Protocolo MQTT.
    • Grafana.
    • Node-RED
        • Protoboard.
    • Cable USB a Mini USB B.
    • Cables Jumper.
    • Modulo ESP32CAM.
    • Leds.
    • Programador FTDI convertidor TTL-USB.
    • Arduino Mega 2060
    • Servo Motor.
    • Sensor de temperatura y humedad DHT11.
    • Resistencias.
    • Mini ventilador a 3-6 V

## Procedimiento y maqueta

Se programado una serie de LEDs al rededor de un contenedor plástico que funje como incubadora  y que simulan los aumentos de temperatura dentro de una incubadora.
Los LEDs son autoregulados automáticamente a una temperatura normal de 37 ° C y que aumentan o disminuyen su intensidad para mantener la temperatura en la incubadora oscilante a los 37 °C.
![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/30d743c4-07e9-41d1-9173-950ca78a6224)

El circuito muestra las conexiones en el protoboard de los LEDs y sobrepuestos con el contenedor a su alrededor periódicamente utilizando una placa Arduino.
Los datos de temperatura que se registran con el sensor (DHT11) por segundo son enviados mediante wifi con el integrado ESP32-CAM, usando el tema /MQTT/MOR/flow4 que se muestran posteriormente

Circuito necesario para la conexión de led’s, resistencias Arduino)

Se muestran los leds dispuestos en serie, y estos actuan de acuerdo a la temperatura del sensor DHT1 y controlados mediante una placa arduino mega 2060.

![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/090a863d-1873-461a-b469-3f251e3e4f00)

## Circuito control ESP32-CAM y FTDI
La temperatura es sensada con la placa ESP32-CAM, el cual registra temperaturas con punto flotante de 0 a 50 grados centígrados, el dato de temperatura obtenido es transmitido tambien a la placa Arduino para regular la témpera de los LEDs que se mencionó anteriormente.


 Cuando la temperatura eleva su temperatura a una cantidad inusual de 40 grados el sistema de ventilación se activa para disipar y disminuir los grados dentro del contenedor de incubación, esta disicipacion se logra abriendo la tapa del contenedor y activando un ventilador para refrescar los huevos dentro del nido robótico.
 
 ![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/58541e0c-2526-4fcc-ae98-cd33b31c675c)
 ![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/5dd65337-2c62-494d-8270-12da75f288c5)

El circuito del sistema programado en la tarjeta ESP32-CAM se muestra las conexiones necesarias para el funcionamiento del sensado y envío de los datos inalámbricos al tema MQTT.
Para este circuito se utilizó el sensor de temperatura y humedad DHT11, un Servomotor para mover la tapa del contenedor de 0 a 180 grados, un motor de corriente directa (CD), un peotoboard y jumpers Macho-Macho (M-M) para las conexiones.
Se utilizó el integrado programador FDTI, para subir el código al ESP32-CAM y para su alimentación a 5v del sistema desarrollado.

Una vez emsamblado ambos circuitos estos comparten el valor del sensor del DHT11, que se puentea de un circuito al otro como se muestra en la siguiente imagen: 
![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/55d5aff6-12ec-476e-996f-96380f274d11)

De manera practica  e ilustrativa el circuito fisico es como se muestra en la segnuda imagen de arriba.

Los circuitos para los circuitos mencionados anteriormente se muestran acontinuacio: 
![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/85af2701-bd87-4abb-b9bd-9f93f2689dfa)

Los codigos se encuentran dentro de este repositorio con sus  debidas lineas comentadas, la primer imagen de arriiba muestra el  codigo para el circuito de iluminaciòn en la maqueta de incubadora, el segundo muestra el codigo que lleva el control del motor de corriente directa para refrescar el recipiente de incubacion, el sensor de temperatura y el sevomotor para abrir la tapa del contenedor.

## Flow necesario para la realización del proyecto

Se realizo el siguiente flow el cual recibe los datos que se mandan del esp32-cam mediante el tema: MQTT/MOR/flow4 via  wi-fi.
Estos datos en el flow son vizualizados en el debug que se muestra en la imagen, se recibe un dato por segundo respectivamente.

![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/2f6bad98-226b-4367-b922-085f9bf8fa57)

dentro de este mismo flow se conectan auna base de datos para su posterior visualizacion en grfana.

Se manda el dato de tempertura junto a la Id de uno de los integrantes del equpo para verificar la recepcion de los mismo, en una 
base de datos que se construyo con el nombre: Temperaturas, donde se muestra una cosntante temperatra de 37°C, temperatura adecuada para la incubacion de huevos. tambie se construye un gauch en el dashboar donde se muestra la temperatura que llega al flow en tiempo real.

![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/81f6b094-0363-4b57-aa09-25953f307068)


## Temperatura registrada por NodRed y grafana 

Sensor registrando temperatura de 37.7°C (ver indicador gauch), una temperatura menor a 38 lo cual mantendrá cerrada la tapa de la incubadora y activara los leds para aumentar la temperatura de la incubadora.
![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/fba2e61d-1d0b-4689-9237-df8f53d657ca)
![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/8d143927-cf36-47c9-866a-5c2774651236)}

ensor registrando temperatura de 38.4°C, una temperatura mayor a 38 lo cual activara el servomotor para abrir la tapa de la incubadora y activara el ventilador para disminuir la temperatura de la incubadora
![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/463a078f-88f4-4d5c-b24d-1b8d7b7aa448)
![image](https://github.com/Gustavo-M-A/Proyecto-IoT/assets/133837622/ef4f3f03-6b2f-48be-87d8-190cecb7ea7b)









