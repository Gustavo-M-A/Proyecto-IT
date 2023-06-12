  #include <DHT.h>
  #include <LiquidCrystal.h>
  LiquidCrystal lcd(28, 30, 32, 34, 36, 38); //Pines de salida de configuracion parael LCD
  DHT dht(12, DHT11);  //Pin 12 de configuracion que recibe la señal del sensor de  temperatura y humedad
  int boton1=2, opcion=3, boton_AutMan=22; //Pines de control para el aumento de intencidad en los LEds automatico o manual.
  int cont=0; //para el incremeto de los Leds y su encendido uno a  uno.
  int Led1=4,Led2=5,Led3=6, Led4=7, Led5=8, Led6=9, Led7=10, Led8=11; //Serie de leds que simulan la temperatura en el interior del contenedor
  int a=0; //variable de intencidad para analogwrite
void setup() {
  // put your setup code here, to run once:

  pinMode(boton1,INPUT); //boton para el incremento gradual de los LEDs
  pinMode(opcion,INPUT); // Selecciona modo de intencidad analogwrite en inremento de intencidad o si los leds prenden uno a uno
  pinMode(boton_AutMan,INPUT); // Modo manual para los casos anteriores o modo automatico para regular la temperatura
  pinMode(Led1,OUTPUT); //Led1 - Led8 configuraciones de salida para los Leds
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
  pinMode(Led4,OUTPUT);
  pinMode(Led5,OUTPUT);
  pinMode(Led6,OUTPUT);
  pinMode(Led7,OUTPUT);
  pinMode(Led8,OUTPUT);
  Serial.begin(9600);
  dht.begin(); // Se  inicia el sensor
  lcd.begin(16,2);  //  Se inicia el LCD
}
void loop()
{
  if(digitalRead(boton_AutMan)==LOW) // Si la entrada esta seleccionada de boton_AutMan esta en tierra LOW,  la intencidad de los LEds sera en modo manual
  Manual();
  else 
  Auto(); // Si  esta en Alto (v+) el sistema estara funcionando en modo automatico
}
void Manual() {
  // put your main code here, to run repeatedly:
if(digitalRead(opcion)==HIGH) // Si esta seleccionada en modo manual
{
if(digitalRead(boton1)==HIGH) // Y si se ha presionado el boton1
cont++; // se incrementa el contador y se prende un Led
delay(190); // Se da un tiempo de  190 mls para captar el push del boton
switch (cont) //dependiendo del numero de  veces que haya registrado el push en su contador, este ira al caso de Leds prendidos que le  corresponda.
  {
    case 0:
      digitalWrite(Led1, LOW); // Caso 0 si el boton no se ha oprimido , no hay ni un led prendido
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
      digitalWrite(Led5, LOW);
      digitalWrite(Led6, LOW);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);
      break;
    case 1:
      digitalWrite(Led1, HIGH); // Caso 1 si el boton se ha oprimido 1 vez, solo hay 1 led prendido
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
      digitalWrite(Led5, LOW);
      digitalWrite(Led6, LOW);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);
      break;
    case 2:
      digitalWrite(Led1, HIGH); // Caso 2 si el boton se ha oprimido 2 veces, existen 2 leds prendidos
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
      digitalWrite(Led5, LOW);
      digitalWrite(Led6, LOW);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);

      break;
    case 3:
      digitalWrite(Led1, HIGH); // Caso 3 si el boton se ha oprimido 3 veces, existen 3 leds prendidos
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, LOW);
      digitalWrite(Led5, LOW);
      digitalWrite(Led6, LOW);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);

      break;
    case 4:
      digitalWrite(Led1, HIGH);  // Caso 4 si el boton se ha oprimido 4 veces, existen 4 leds prendidos
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led5, LOW);
      digitalWrite(Led6, LOW);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);
      break;
    case 5:
      digitalWrite(Led1, HIGH);  // Caso 5 si el boton se ha oprimido 5 veces, existen 5 leds prendidos
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led5, HIGH);
      digitalWrite(Led6, LOW);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);
      break;
    case 6:
      digitalWrite(Led1, HIGH);   // Caso 6 si el boton se ha oprimido 6 veces, existen 6 leds prendidos
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led5, HIGH);
      digitalWrite(Led6, HIGH);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);
      break;
    case 7:
      digitalWrite(Led1, HIGH);   // Caso 7 si el boton se ha oprimido 7 veces, existen 7 leds prendidos
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led5, HIGH);
      digitalWrite(Led6, HIGH);
      digitalWrite(Led7, HIGH);
      digitalWrite(Led8, LOW);
      break;
    case 8:
      digitalWrite(Led1, HIGH);   // Caso 8 si el boton se ha oprimido 8 veces, existen 8 leds prendidos (todos los leds dispuestos en la incubadora)
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led5, HIGH);
      digitalWrite(Led6, HIGH);
      digitalWrite(Led7, HIGH);
      digitalWrite(Led8, HIGH);
      break;

      default:
      digitalWrite(Led1, LOW);   // si el contador exece los 8 leds dispuestos en la maqueta, todos los leds se apagan y se  reinicia el contador
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
      digitalWrite(Led5, LOW);
      digitalWrite(Led6, LOW);
      digitalWrite(Led7, LOW);
      digitalWrite(Led8, LOW);
      cont=0;
      break;
  }
}
  else
  {
  if(digitalRead(boton1)==HIGH){  // Si el boton de manual esta desactivado entonces el boton para la intencidad de los leds (boton1) esta en alto
    a++;   //se incrementa "a" para la intencidad de luz en los leds (Led1 ...8), los leds iran prendiendo poco a poco mientras el boton se encuentre
      analogWrite(Led1, a); // presionado con la intencidad del valor de la variable "a"
      analogWrite(Led2, a);
      analogWrite(Led3, a);
      analogWrite(Led4, a);
      analogWrite(Led5, a);
      analogWrite(Led6, a);
      analogWrite(Led7, a);
      analogWrite(Led8, a);
  delay(20);
  }
    if(a==250) // hasta un tope de intencidad de  250
    a=0; //  posterior a ese tope se renicia a  0 (apagado en los Leds).
  }

}

void Auto() { //  Funcion para el sistema automatico en intencidad de los leds
float t=dht.readTemperature(); // Se lee la temperatura del sensor dht11 y se alamacena en el flotante  t.
t=t+9; // Ajuste de la temperatura ambiente al empollamiento necesario para huevos de gallina 37.8 ºC Aproximadamente
Imprimir_Lcd(t); //Se imprime el valor de "t" en el LCD.
String t2=(String)t; // Se pasa el valor a cadena de la tempertura para obtener sus decimales 
Serial.println(t2); // Se imprime en la IDE de arduino la temperatura.
String sub_S = t2.substring(3,4); // Se obtiene el caracter de la segundo  numero de la temperatura
String sub_S2 = t2.substring(1,2); // se obtiene el caracter del primer numero de la temperatura para poner un 0 antes de la temperatura si el caracter es de 2 digitos o 1  digito
sub_S=sub_S2+sub_S; //se concatenan los caracteres de los numeros de temperatura
int t3=sub_S.toInt(); //se conveirte a numero la primer cadena
if(t>38) // si la temperatura es mayor a 38 entonces se ajusta t3 para hacer la operacion para disminuir la intencidad en los leds
t3=100+t3;
if(t>36) // si la temperatura es menor  a 36 entonces se ajusta t3 para hacer la operacion para aumentar la intencidad en los leds
t3=100-t3;
Serial.println(t3); //Se imprime el valor de t3 en el serial
int res=600-t*(t3/6); // se realiza el ajuste de la temperatura
if(res<0)  // Si el resultado resulta en un valor negativo, entonces el resultado solo puede ser 0
res=0;
//analogWrite(13  ,res);
      analogWrite(Led1, res); //Se incrementan toos los leds de acuerdo a la intencidad en los LEds registrada en res
      analogWrite(Led2, res);
      analogWrite(Led3, res);
      analogWrite(Led4, res);
      analogWrite(Led5, res);
      analogWrite(Led6, res);
      analogWrite(Led7, res);
      analogWrite(Led8, res);
Serial.println(res);  //Se imprime el valor de intencidad que se recibio en todos los LEds en el puerto serial
delay(1000); // se espera  1 segundo
}

void Imprimir_Lcd(float temp) {  // Funcion opcional integrado del LCD
 lcd.clear();
lcd.setCursor(1,0); // Se pone el cursor en la primera linea para imprimir la etiqueta:
 lcd.print(" Temperatura:");  // Temperatura:
 lcd.setCursor(0,1);   // Se pone el cursor en la segunda linea  (linea de abajo) para imprimir la temperatura registrada en la variable temp
 lcd.print("    "+(String)temp+" GC.");
  //delay(1000);
 }  

