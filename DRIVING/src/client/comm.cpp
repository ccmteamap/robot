#include"comm.h"
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>

#define CE 9
#define CSN 10

RF24 rf(CE, CSN);

//GETEST
void startComm(){
  uint8_t addresses[][6] = { "RNode", "CNode" };
  
  rf.begin();
  rf.openReadingPipe(1, addresses[1]);
  rf.openWritingPipe(addresses[0]);
  rf.startListening();
}

//GETEST
bool send(const void *msg, uint8_t size){
  rf.stopListening();
  bool success = rf.write(msg, size);
  rf.startListening();

  return success;
}

//GETEST
bool read(void *buffer, uint8_t size) {
	if (rf.available()) {
	  rf.read(buffer, size);
	  return true;
	}

	return false;
}

