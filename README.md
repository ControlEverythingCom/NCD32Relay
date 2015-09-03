# About

This Library is intended for use with the NCD 32 Channel Particle compatible relay controller.

The intention of this library is to make use of the NCD 32 channel relay controller with Particle development web IDE as simple as possible for users.
###Developer information
NCD has been designing and manufacturing computer control products since 1995.  We have specialized in hardware design and manufacturing of Relay controllers for 20 years.  We pride ourselves as being the industry leader of computer control relay products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit www.controlanything.com 

###Requirements
- NCD 32 Channel Particle Compatible Relay board
- Particle Core/Photon module
- Knowledge base for developing and programming with Particle modules.

### Version
1.0.0

### How to use this library

The libary must be imported into your application.  This can be done through the Particle WEB IDE by selecting Libraries, then select the NCD32Relay.  Click Include in App button.  Select the App you want to include the library in.  Finally click Add to this app.  For more information see [Particle's documentation] [ParticleIncludeLibrary] 

### Example use

Once the Library is included in your applicaiton you should see an include statement at the top like this:
```cpp
//This #include statement was automatically added by the Particle IDE.
#include "NCD32Relay/NCD32Relay.h"
```
Now you need to instanciate an object of the library for use in your application like this:
```cpp
NCD32Relay relayController;
```

Here is an example use case for the class
```cpp
// This #include statement was automatically added by the Particle IDE.
#include "NCD32Relay/NCD32Relay.h"
NCD32Relay relayController;

void setup() {
relayController.setAddress(0, 0, 0);
}

void loop() {
relayController.turnOnAllRelays();
delay(500);
relayController.turnOffAllRelays();
delay(500);
relayController.turnOnAllRelays(1);
delay(500);
relayController.turnOnAllRelays(2);
delay(500);
relayController.turnOffAllRelays(1);
delay(500);
relayController.turnOffAllRelays(2);
}
```

###Public accessible methods
```cpp
void setAddress(int a0, int a1);
```
>Must be called first before using the object.  This method should also be called any time communication with
>the controller is lost or broken to recover communication  This method accepts two int arguments.  This
>tells the Library what address to direct commands to.  a0 and a1 ints are representations of the two
>jumpers on the 32 channel relay controller which are labeled on the board A0 and A1.  If the jumper is
>installed then that int in this call should be set to 1.  If it is not installed then the int should be set to 
So if I have A0 and A1 installed I would call ```relayController.setAddress(1, 1).```


```cpp
void turnOnRelay(int Relay);
```
>This method accepts one int argument.  Valid int arguments 1-32.  A call to this method will turn on the
>relay indicated by the passed int argument.


```cpp
void turnOffRelay(int Relay);
```
>This method accepts one int argument.  Valid int arguments 1-32.  A call to this method will turn off the relay
>indicated by the passed int argument.


```cpp
void turnOnAllRelays();
```
>This method does not accept any arguments.  A call to this method will turn on all 32 relays on the
>controller.


```cpp
void turnOffAllRelays();
```
>This method does not accept any arguments.  A call to this method will turn off all 32 relays on the
>controller.


```cpp
void turnOnAllRelays(int bank);
```
>This method accepts one int argument.  Valid ints are 1-4 for relay banks 1-4 respectively.  If 1 is
>passed relays 1-8 will be turned on.  If 2 is passed relays 9-16 will be turned on. If 3 is passed relays 17-24 will be turned on.  If 4 is passed relays 25-32 will be turned on.


```cpp
void turnOffAllRelays(int bank);
```
>This method accepts one int argument.  Valid ints are 1-4 for relay banks 1-4 respectively.  If 1 is
>passed relays 1-8 will be turned off.  If 2 is passed relays 9-16 will be turned off. If 3 is passed relays 17-24 will be turned off.  If 4 is passed relays 25-32 will be turned off.


```cpp
void toggleRelay(int relay);
```
>This method accepts one int argument.  Valid int arguments are 1-32.  A call to this method will toggle the
>status of the relay indicated by the passed int argument.  If the relay was previously off before the method
>call the relay will turn on and vice versa.


```cpp
void setBankStatus(int status, int bank);
```
>This method accepts two int arguments.  Valid status int arguments 0-255.  Valid bank arguments 1-4.  A call
>to this method will set the status of all relays in the specified bank(1-4) to the status byte passed in
the second argument(status).  Each relay in the bank(total of 8) are represented as bits in the status
>argument.


```cpp
void setAllRelayStatus(int bank1, int bank2, int bank3, int bank4);
```
>This method accepts four int arguments.  Valid bank1 int arguments 0-255.  Valid bank2 int arguments 0-255.  Valid bank3 arguments 0-255.  Valid bank4 arguments 0-255  A
>call to this method will set the status of all relays in banks 1(total of 8) to the status sent in the bank1 argument, all relays in bank 2(total of 8) to the
>status int passed in the bank2 argument, all relays in bank 3(total of 8) to the
>status int passed in the bank3 argument, and all relays in bank 4(total of 8) to the
>status int passed in the bank4 argument.  Each relay in the bank are represented in bits in the
>bank1-4 argument.


```cpp
int readRelayStatus(int relay);
```
>This method accepts one int argument and returns one int.  Valid relay int arguments 1-32.  A call to this
>method will read the status of the given relay passed by the relay argument and return the current on/off
>status of the given relay.  1 will be returned if the relay is on and 0 will be returned if the relay is off. 
>256 will be returned if an error has occured(generally due to lack of communication with the controller).


```cpp
int readBankStatus(int bank);
```
>This method accepts one int argument and returns one int.  Valid bank int arguments 1-4.  A call to this
>method will read and return the status of all relays in the given bank(passed to method as bank int argument). 
>Each relay in the bank is represented in a bit in the returned int.  Valid returns are 0-255.  256 will be
>returned if an error has occured(generally due to lack of communciation with controller).


###Public accessible variables
```cpp
bool initialized;
```
>This boolean indicates the current status of the interface connection to the controller.  This variable should
>be checked often throughout your application.  If communication to the board is lost for any reason this
>boolean variable will return false.  If all is well it will return true.


License
----

GNU
[ParticleIncludeLibrary]:https://docs.particle.io/guide/getting-started/build/photon/