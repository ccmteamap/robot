#include"comm.h"
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>

#define CE 4
#define CSN 3
#define TX_ADDRESS 0xFFFFFFFFFFAA
#define RX_ADDRESS 0xFFFFFFFFFFBB

RF24 rf(CE, CSN);

void startComm(){
  rf.begin();
  rf.openReadingPipe(1, RX_ADDRESS);
  rf.openWritingPipe(TX_ADDRESS);
  rf.startListening();
}

void send(const void *msg, uint8_t size){
  rf.stopListening();
  rf.write(msg, size);
  rf.startListening();
}

bool read(void *buffer) {
	if (rf.available()) {
	  rf.read(&buffer, PAYLOAD_SIZE);
	  return true;
	}

	return false;
}

