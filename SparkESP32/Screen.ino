#include "Screen.h"

unsigned long now, last_time;

void setup_screen() {
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(3);
  M5.Lcd.drawRoundRect(0, 0, 320, 30, 10, TFT_WHITE);
  M5.Lcd.setCursor(72,5);
  M5.Lcd.print("Spark MIDI");

  M5.Lcd.setTextSize(2);

  M5.Lcd.drawRoundRect(0, TYPE_OFFSET - 7, 150, LINES_GAP, 10, TFT_WHITE);
  M5.Lcd.drawRoundRect(160, TYPE_OFFSET - 7, 160, LINES_GAP, 10, TFT_WHITE);
#ifdef CLASSIC
  M5.Lcd.fillRoundRect(161, TYPE_OFFSET - 6, 158, LINES_GAP-2, 10, TFT_BLUE);
  M5.Lcd.setCursor(40, TYPE_OFFSET);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.print("NimBLE"); 
  M5.Lcd.setCursor(174, TYPE_OFFSET);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLUE);
  M5.Lcd.print("BLE Classic"); 
#else
  M5.Lcd.fillRoundRect(1, TYPE_OFFSET - 6, 148, LINES_GAP-2, 10, TFT_BLUE);
  M5.Lcd.setCursor(40, TYPE_OFFSET);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLUE);
  M5.Lcd.print("NimBLE"); 
  M5.Lcd.setCursor(174, TYPE_OFFSET);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.print("BLE Classic"); 
#endif

  for (int i = 0; i <= 3 ; i++) {
    M5.Lcd.drawCircle(CON_COL, SPK_ICON + LINES_GAP * i, CIRC_RAD, TFT_WHITE);
    M5.Lcd.drawCircle(TO_COL, SPK_ICON + LINES_GAP * i, CIRC_RAD, TFT_WHITE);
    M5.Lcd.drawCircle(FROM_COL, SPK_ICON + LINES_GAP * i, CIRC_RAD, TFT_WHITE);
  }
  
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.setCursor(120,TITLES);
  M5.Lcd.print(" Conn  To  From"); 
  M5.Lcd.setCursor(0, SPK_TEXT);
  M5.Lcd.print("Spark Amp"); 
  M5.Lcd.setCursor(0, APP_TEXT);
  M5.Lcd.print("App"); 
  M5.Lcd.setCursor(0, BLE_MIDI_TEXT);
  M5.Lcd.print("BLE MIDI"); 
  M5.Lcd.setCursor(0, USB_MIDI_TEXT);
  M5.Lcd.print("USB MIDI");

  now = millis();
  last_time = millis();
}



void show_status() {
  int rad;

  if (millis() - now > 50) { // only do this evey 50ms so we don't keep redrawing!
    now = millis();
  
    for (int i = 0; i <= 1; i++) 
      for (int j = 0; j <= 3; j++) 
        if (now - conn_last_changed[i][j] <= 900) {
          rad = FILL_RAD - int(FILL_RAD * (now - conn_last_changed[i][j]) / 800); 
          M5.Lcd.fillCircle(i == TO ? TO_COL : FROM_COL, SPK_ICON + j * LINES_GAP, FILL_RAD, TFT_BLACK);
          if (rad > 0)
            M5.Lcd.fillCircle(i == TO ? TO_COL : FROM_COL, SPK_ICON + j * LINES_GAP, rad, TFT_YELLOW);  
        }

    

    for (int j = 0; j <= 2; j++) 
      if (conn_last_changed[STATUS][j] >= last_time)
        if (conn_status[j])
          M5.Lcd.fillCircle(CON_COL, SPK_ICON + j * LINES_GAP, FILL_RAD, TFT_GREEN);
        else
          M5.Lcd.fillCircle(CON_COL, SPK_ICON + j * LINES_GAP, FILL_RAD, TFT_RED);
  
    last_time = now;
  }
}
