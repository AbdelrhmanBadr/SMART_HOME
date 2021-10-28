/*
 * Blutooth_HC06.h
 *
 * Created: 25-Oct-21 2:14:13 PM
 *  Author: Abdelrhman Badr
 */ 


#ifndef BLUTOOTH_HC06_H_
#define BLUTOOTH_HC06_H_

void BluetoothHc06_Setup(void);
void BluetoothHc06_SendToBluetooth(uint8 Data);
void BluetoothHc06_ReceiveFromBluetooth(uint8 *ReceivedData);
void BluetoothHc06_SendStringToBluetooth(char String[]);
void BluetoothHc06_ReceiveStringFromBluetooth(char *string , uint8 StringSize);

#endif /* BLUTOOTH_HC06_H_ */