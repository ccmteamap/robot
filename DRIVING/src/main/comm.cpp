#include"comm.h"
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>
#include"pin.h"

RF24 rf(CE_PIN, CSN_PIN);

//GETEST
void startComm(){
  uint8_t addresses[][6] = { "RNode", "CNode" };
  
  rf.begin();
  rf.openReadingPipe(1, addresses[0]);
  rf.openWritingPipe(addresses[1]);
  rf.startListening();
}

//GETEST
void send(const void *msg, uint8_t size){
  rf.stopListening();
  rf.write(msg, size);
  rf.startListening();
}

//GETEST
bool read(void *buffer, uint8_t size) {
	if (rf.available()) {
	  rf.read(buffer, size);
	  return true;
	}

	return false;
}

