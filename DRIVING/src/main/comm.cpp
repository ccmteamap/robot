#include"comm.h"
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>
#include<Arduino.h>

#define CE 9
#define CSN 10
#define TX_ADDRESS 0xFFFFFFFFFFAA
#define RX_ADDRESS 0xFFFFFFFFFFBB

RF24 rf(CE, CSN);

typedef enum {
  SENDING,
  RECEIVING
} Mode;

Mode currentMode = RECEIVING;

void startComm(){
  rf.begin();
  rf.openReadingPipe(1, RX_ADDRESS);
  rf.openWritingPipe(TX_ADDRESS);
  rf.startListening();
}
