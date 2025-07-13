#ifndef __MENU_H
#define __MENU_H

void Menu_Show(void);
void Menu_Init(void);

void Menu_P1_Init(void);
void Menu_P2_Init(void);
void Menu_P3_Init(void);
void Menu_P4_Init(void);

void Menu_P1_Var(void);
void Menu_P2_Var(void);
void Menu_P3_Var(void);
void Menu_P4_Var(void);

void Menu_P1_Key(uint8_t  Key_Num );
void Menu_P2_Key(uint8_t  Key_Num );
void Menu_P3_Key(uint8_t  Key_Num );
void Menu_P4_Key(uint8_t  Key_Num );

#endif
