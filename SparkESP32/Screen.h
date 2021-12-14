#ifndef Screen_h
#define Screen_h

#define CON_COL 152
#define TO_COL 214
#define FROM_COL 276

#define CIRC_RAD 12
#define FILL_RAD 10

#define TYPE_OFFSET 46
#define LINES_GAP 30

#define TITLES (TYPE_OFFSET + LINES_GAP + 6)
#define SPK_TEXT (TITLES + LINES_GAP)
#define APP_TEXT (SPK_TEXT + LINES_GAP)
#define BLE_MIDI_TEXT (APP_TEXT + LINES_GAP)
#define USB_MIDI_TEXT (BLE_MIDI_TEXT + LINES_GAP)

#define SPK_ICON (SPK_TEXT + 6)
#define APP_ICON (SPK_ICON + LINES_GAP)
#define BLE_MIDI_ICON (APP_ICON + LINES_GAP)
#define USB_MIDI_ICON (BLE_MIDI_ICON + LINES_GAP)


void setup_screen();
void show_status();

#endif
