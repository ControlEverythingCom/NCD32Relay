/* Includes ------------------------------------------------------------------*/
#include "NCD32Relay/NCD32Relay.h"

NCD32Relay relayController;

SYSTEM_MODE(AUTOMATIC);

int triggerRelay(String command);

/* This function is called once at start up ----------------------------------*/
void setup()
{
	Serial.begin(115200);
	relayController.setAddress(0, 0);
	Particle.function("controlRelay", triggerRelay);
}

/* This function loops forever --------------------------------------------*/
void loop()
{

}

int triggerRelay(String command){
	if(command.equalsIgnoreCase("turnonallrelays")){
		relayController.turnOnAllRelays();
		return 1;
	}
	if(command.equalsIgnoreCase("turnoffallrelays")){
		relayController.turnOffAllRelays();
		return 1;
	}
	if(command.startsWith("turnonallrelaysinbank:")){
		int bank = command.substring(22).toInt();
		relayController.turnOnAllRelays(bank);
		return 1;
	}
	if(command.startsWith("turnoffallrelaysinbank:")){
		int bank = command.substring(23).toInt();
		relayController.turnOffAllRelays(bank);
		return 1;
	}
	if(command.startsWith("setallrelaystatus:")){
		//TODO finish this!!!!!!
		String status = command.substring(18,command.length());
		int splitIndex = status.indexOf(",");
		int bank1 = status.substring(0, splitIndex).toInt();
		String remainder = status.substring(splitIndex+1, status.length());
		splitIndex = remainder.indexOf(",");
		int bank2 = remainder.substring(0, splitIndex).toInt();
		remainder = remainder.substring(splitIndex+1, status.length());
		splitIndex = remainder.indexOf(",");
		int bank3 = remainder.substring(0, splitIndex).toInt();
		int bank4 = remainder.substring(splitIndex+1, remainder.length()).toInt();
		Serial.println("Bank status bytes: "+String(bank1)+", "+String(bank2)+", "+String(bank3)+", "+String(bank4)+", ");
		relayController.setAllRelayStatus(bank1, bank2, bank3, bank4);
		return 1;
	}
	if(command.startsWith("setbankstatus:")){
		Serial.println("Set Bank Status Command");
		String status = command.substring(14,command.length());
		int splitIndex = status.indexOf(",");
		int bank = status.substring(0,splitIndex).toInt();
		int bankStatus = status.substring(splitIndex+1, status.length()).toInt();
		if(bankStatus < 0 || bankStatus > 255){
			return 0;
		}
		Serial.println("Setting bank "+String(bank)+ " status to: "+String(bankStatus));
		relayController.setBankStatus(bankStatus,bank);
		Serial.println("done");
		return 1;
	}
	//Relay Specific Command
	int splitIndex = command.indexOf(",");
	int relayNumber = command.substring(0,splitIndex).toInt();
	Serial.print("relayNumber: ");
	Serial.println(relayNumber);
	String relayCommand = command.substring(splitIndex+1);
	Serial.print("relayCommand:");
	Serial.print(relayCommand);
	Serial.println(".");
	if(relayCommand.equalsIgnoreCase("on")){
		Serial.println("Turning on relay");
		relayController.turnOnRelay(relayNumber);
		Serial.println("returning");
		return 1;
	}
	if(relayCommand.equalsIgnoreCase("off")){
		relayController.turnOffRelay(relayNumber);
		return 1;
	}
	if(relayCommand.equalsIgnoreCase("toggle")){
		relayController.toggleRelay(relayNumber);
		return 1;
	}
	if(relayCommand.equalsIgnoreCase("momentary")){
		relayController.turnOnRelay(relayNumber);
		delay(300);
		relayController.turnOffRelay(relayNumber);
		return 1;
	}
	return 0;
}
