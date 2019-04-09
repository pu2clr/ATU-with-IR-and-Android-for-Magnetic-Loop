# Sintonizador de Antena Loop Magnética controlado por Arduino e Infravermelho


## Sumário

* [Introdução]()
* [Componentes]()
* [Esquema Elétrico]()
* [Identificando os comandos do dispositivo infravermelho]()
* [Programa Arduino ]()

## Introdução

Antenas Loop Magnéticas são utilizadas em vários sistemas de comunicação por ser um sistema irradiante que ocupa pouco espaço e excelente performance.  No entanto, há alguns inconvenientes em utilizar antenas do tipo Loop Magnética: 

Devido a sua alta seletividade ou fator de mérito ou ainda fator Q, esse tipo de antena exige sintonia em seu sistema a cada vez que a frequência é alterada no receptor ou transmissor.  Em alguns casos, essa característica torna a utilização desse tipo de antena inviável, já que o seu sistema de ajuste localiza-se próximo a antena. 

A presença do corpo humano próximo a antena interfere no sistema de sintonia, dificultando um ajuste preciso.

Em operações com transmissão, a tensão no capacitor localizado na antena, é geralmente muito elevada, na ordem 1KV ou mais, dependendo da potencia do transmissor. 

Para minimizar este problema, este projeto pretende implementar um sistema de sintonia remota para antenas loop magnética, no estilo Alexloop ou de construção caseira. Para tanto, o sistema utilizado um dispositivo de controle remoto infravermelho, muito comum em TV e rádios domésticos. 



## Componentes


### Servo TG9 Servo

Small and lightweight with considerable output power. This Servo can rotate approximately 180 degrees, and works like a standard servo.

|Feature| Description| 
|Modulation:|Analog|
|Torque:|4.8V: 22.2 oz-in (1.60 kg-cm)|
|Speed:|4.8V: 0.12 sec/60°|
|Weight:|0.32 oz (9.0 g)|
|Dimensions:|  in (mm) |
|Length:|0.91 in (23.1 mm)| 
|Width:|0.43 in (10.9 mm)|
|Height:|1.14 in (29.0 mm)|
| ----- | -----|
|Motor Type:|Coreless|
|Gear Type:|Plastic|
|Rotation/Support:|Bushing| 
|Pulse Range| 600mS to 2100mS pulse| 


- [Rotary Encoder - Illuminated (Red/Green)](https://www.sparkfun.com/products/10596)
- [Infrared receiver (taken from a scrap DVD player)](http://www.ebay.com/itm/- VS1838B-Infrared-receiver-38Khz-Infrared-sensor-IR-Infrared-Receiver-/260875354763?pt=LH_DefaultDomain_0&hash=item3cbd62028b)
- [Arduino (Pro Mini atmega328 5V)](http://www.ebay.com/itm/New-ver-Promini-Pro-Mini-atmega328-328p-5V-16MHz-Arduino-Compatible-nano-size-/321090929788?pt=LH_DefaultDomain_0&hash=item4ac282c47c)
- [LEDS (Gree, Blue, Red and Yellow)](http://www.ebay.com/itm/271092424896?ssPageName=STRK:MEWNX:IT&_trksid=p3984.m1439.l2649)
- [VARIABLE CAPACITOR TWO GANG JACKSON BROS](http://www.ebay.com/itm/VARIABLE-CAPACITOR-TWO-GANG-JACKSON-BROS-/300844646071?pt=LH_DefaultDomain_3&hash=item460bbcfeb7)



## Esquema Elétrico


![schematic](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/schematic/schematic_arduino_IR-NEW.png)


## Identificando os comandos do dispositivo infravermelho

Se você não conhece os valores (mensagens) enviados pelo seu dispositivo infravermelho, você deve seguir os passos apresentado a seguir. 

Desenvolver um sketch para identificar os comandos do dispoditivo infravermelho que será utilizado como controlador remoto...




## Programa Arduino 

Antes de fazer o baixar o sketch para o seu Arduino, verifique as especificações de seu dispositivo infravermelho. Se o seu dispositivo infravermelho não for igual ao utilizado neste projeto, você deve utilizar as instruções do item anterior a ajustar o sketch para o seu controle remoto infravermelho. 


## Fotos



![Photo 01](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo01.jpg)


![Photo 02](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo02.jpg)


![Photo 03](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo03.jpg)


![Photo 04](https://github.com/pu2clr/ATU-with-IR-and-Android-for-Magnetic-Loop/blob/master/Photos/photo04.jpg)




## Vídeo

- [Arduino, IR and Encoder controlling Magnetic Loop Antenna Tuner](https://youtu.be/zD-wKD19_8U)



## Referências





