#include"comm.h"
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>

#define CE 9
#define CSN 10
#define TX_ADDRESS 0xFFFFFFFFFFBB
#define RX_ADDRESS 0xFFFFFFFFFFAA

RF24 rf(CE, CSN);

void startComm(){
  rf.begin();
  rf.openReadingPipe(1, RX_ADDRESS);
  rf.openWritingPipe(TX_ADDRESS);
  rf.startListening();
}

bool send(const void *msg, uint8_t size){
  rf.stopListening();
  bool success = rf.write(msg, size);
  rf.startListening();

  return success;
}

bool read(void *buffer, uint8_t size) {
	if (rf.available()) {
	  rf.read(&buffer, size);
	  return true;
	}

	return false;
}

