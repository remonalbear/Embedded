#ifndef DIO_H_
#define DIO_H_
void DIO_set_bit_dir(unsigned char port,unsigned char bit , unsigned char dir);
unsigned char DIO_read_bit(unsigned char port,unsigned char bit);
void DIO_write_bit(unsigned char port,unsigned char bit , unsigned char value);
void DIO_toggle_bit(unsigned char port,unsigned char bit);
void DIO_set_port_dir(unsigned char port , unsigned char dir);
void DIO_write_port(unsigned char port, unsigned char value);
unsigned char DIO_read_port(unsigned char port);
void DIO_connect_pullup(unsigned char port,unsigned char bit,unsigned char connect);
void DIO_write_low_nibble(unsigned char port,unsigned char value);
void DIO_write_high_nibble(unsigned char port,unsigned char value);

#endif