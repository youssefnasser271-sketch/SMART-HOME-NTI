/*
 * ADC_Interface.h
 *
 * Created: 6/15/2023 9:50:45 PM
 *  Author: Rizk
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHANNEL0  0
#define ADC_CHANNEL1  1
#define ADC_CHANNEL2  2
#define ADC_CHANNEL3  3
#define ADC_CHANNEL4  4
#define ADC_CHANNEL5  5
#define ADC_CHANNEL6  6
#define ADC_CHANNEL7  7

void ADC_INIT (void);
void ADC_CHANNEL_SELECT (u8 copy_adc_channel);
void ADC_START_CONVERSION (void);
u16 ADC_Read_value ();




#endif /* ADC_INTERFACE_H_ */