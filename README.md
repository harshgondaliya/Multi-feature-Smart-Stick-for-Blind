# Multi-feature Smart Stick for Blind
This is an Arduino-based smart stick that assists blind people by providing four crucial features - Obstacle Detection, Water Sensing, Stick Searching & Smart Decision Making.  

**Credit:** The idea to incorporate these features in blind stick was inherited from the [Ultrasonic Blind Walking Stick Project](https://nevonprojects.com/ultrasonic-blind-walking-stick-project/) by Neon Projects. However, the arduino code and the working model shown in this repository is an indepedent work of the repository owner.

## Tools & Materials Used
* Arduino UNO R3
* HC-SR04 Ultrasonic Sensor Module
* Soil Moisture Hygrometer Detection Module
* Infrared IR Wireless Remote Control Kit (IR Receiver + IR Remote)
* 3.3-5V Passive Buzzers - 2 pcs
* Active Buzzer Module - 1 pc (to play ringtone)
* Generic Breadboard
* 9V Hi-Watt Battery
* Jumper Breadboard Wires (M-F / M-M / F-F)
* PVC Pipe (used for creating the armature)
* Red Electric Tape (to give a blind-stick look)

## Diagram
Diagram of the fully working model of stick with all its components is availalble at this [link](https://github.com/harshgondaliya/Multi-feature-Smart-Stick-for-Blind/blob/master/Diagram/Multi-feature%20Smart%20Stick%20for%20Blind%20diagram.PNG).
## Working 
The stick rings a different type of buzzer to execute each of the below mentioned features.

**Obstacle Detection** : When an object is detected within 3 meter range of the stick, a buzzer rings. For this project, only a single HC-SR04 Ultrasonic Sensor Module was used. Thus, it can detect obstacle within 15 degree sector of the sensor. [_Video Link_](https://drive.google.com/open?id=1UZcNT_zw5SvOxyt5aXLhGN5MzU3aWY2t)

**Water Sensing** :	When the base of the stick touches any water or liquid element, a buzzer rings. This was done using the Soil Moisture Hygrometer Detection Module for Arduino. [_Video Link_](https://drive.google.com/open?id=1mR_TAaNOmUZ_ZYcDpYIUa1qlD4ikmtVn)

**Stick Searching** : When the blind needs to search for his stick, he could press an IR Remote button. This will ring a ringtone at the active buzzer on the stick. The sound of this ringtone will enable the blind to search for his stick. [_Video Link_](https://drive.google.com/open?id=1jZtp-uNvQp1QdGIxsyIFQJdPlg6NGqCj)

**Smart Decision Making** : If all three features need to be triggered at the same time then the priority is given as : 

Stick Searching > Water Sensing > Obstacle Sensing [_Video Link_](https://drive.google.com/open?id=1a4C9jij5G8dznrQMwNZcQ9HBPovyn7AU)

This is because, before alarming the blind about a 3m distant object, it is more important to give him notice of the impending water. Moreover, if the blind wants to use Stick Searching feature then the rest two features will come in no use.

