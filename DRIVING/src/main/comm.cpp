#include"comm.h"
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>

#define CE 9
#define CSN 10
#define TX_ADDRESS 0xFFFFFFFFFFAA
#define RX_ADDRESS 0xFFFFFFFFFFBB

RF24 rf(CE, CSN);

bool listening = true;

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

bool read(command* commandBuffer) {
	if (rf.available()) {
		return rf.read(commandBuffer, sizeof(*commandBuffer));
	}

	return false;
}