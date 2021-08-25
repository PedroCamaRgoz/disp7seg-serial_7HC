#ifndef DISPLAY7SEGMENTOS_H
#define DISPLAY7SEGMENTOS_H


//struct 
//{
//    void ( * init_serial ) (void);
//    void ( * init_disp7 )  (void);
//    void ( * serial ) (unsigned char num);
//    void ( * dis7seg) (unsigned char num);
// 
//} disp7 = {serial_init, disp7seg_init, disp7seg_serial, disp7seg};
//
void disp7seg_init( void );
void disp7seg ( unsigned char num );
void disp7seg_serial( unsigned char num );



#endif
