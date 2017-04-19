//
//  SkyKeysDef.h
//  motor
//
//  Created by Stoycho Ivanov Atanasov on 21/3/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef SkyKeysDef_h
#define SkyKeysDef_h

/* The unknown key */
#define SKY_KEY_UNKNOWN            -1

/* Printable keys */
#define SKY_KEY_SPACE              32
#define SKY_KEY_APOSTROPHE         39  /* ' */
#define SKY_KEY_COMMA              44  /* , */
#define SKY_KEY_MINUS              45  /* - */
#define SKY_KEY_PERIOD             46  /* . */
#define SKY_KEY_SLASH              47  /* / */
#define SKY_KEY_0                  48
#define SKY_KEY_1                  49
#define SKY_KEY_2                  50
#define SKY_KEY_3                  51
#define SKY_KEY_4                  52
#define SKY_KEY_5                  53
#define SKY_KEY_6                  54
#define SKY_KEY_7                  55
#define SKY_KEY_8                  56
#define SKY_KEY_9                  57
#define SKY_KEY_SEMICOLON          59  /* ; */
#define SKY_KEY_EQUAL              61  /* = */
#define SKY_KEY_A                  65
#define SKY_KEY_B                  66
#define SKY_KEY_C                  67
#define SKY_KEY_D                  68
#define SKY_KEY_E                  69
#define SKY_KEY_F                  70
#define SKY_KEY_G                  71
#define SKY_KEY_H                  72
#define SKY_KEY_I                  73
#define SKY_KEY_J                  74
#define SKY_KEY_K                  75
#define SKY_KEY_L                  76
#define SKY_KEY_M                  77
#define SKY_KEY_N                  78
#define SKY_KEY_O                  79
#define SKY_KEY_P                  80
#define SKY_KEY_Q                  81
#define SKY_KEY_R                  82
#define SKY_KEY_S                  83
#define SKY_KEY_T                  84
#define SKY_KEY_U                  85
#define SKY_KEY_V                  86
#define SKY_KEY_W                  87
#define SKY_KEY_X                  88
#define SKY_KEY_Y                  89
#define SKY_KEY_Z                  90
#define SKY_KEY_LEFT_BRACKET       91  /* [ */
#define SKY_KEY_BACKSLASH          92  /* \ */
#define SKY_KEY_RIGHT_BRACKET      93  /* ] */
#define SKY_KEY_GRAVE_ACCENT       96  /* ` */
#define SKY_KEY_WORLD_1            161 /* non-US #1 */
#define SKY_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define SKY_KEY_ESCAPE             256
#define SKY_KEY_ENTER              257
#define SKY_KEY_TAB                258
#define SKY_KEY_BACKSPACE          259
#define SKY_KEY_INSERT             260
#define SKY_KEY_DELETE             261
#define SKY_KEY_RIGHT              262
#define SKY_KEY_LEFT               263
#define SKY_KEY_DOWN               264
#define SKY_KEY_UP                 265
#define SKY_KEY_PAGE_UP            266
#define SKY_KEY_PAGE_DOWN          267
#define SKY_KEY_HOME               268
#define SKY_KEY_END                269
#define SKY_KEY_CAPS_LOCK          280
#define SKY_KEY_SCROLL_LOCK        281
#define SKY_KEY_NUM_LOCK           282
#define SKY_KEY_PRINT_SCREEN       283
#define SKY_KEY_PAUSE              284
#define SKY_KEY_F1                 290
#define SKY_KEY_F2                 291
#define SKY_KEY_F3                 292
#define SKY_KEY_F4                 293
#define SKY_KEY_F5                 294
#define SKY_KEY_F6                 295
#define SKY_KEY_F7                 296
#define SKY_KEY_F8                 297
#define SKY_KEY_F9                 298
#define SKY_KEY_F10                299
#define SKY_KEY_F11                300
#define SKY_KEY_F12                301
#define SKY_KEY_F13                302
#define SKY_KEY_F14                303
#define SKY_KEY_F15                304
#define SKY_KEY_F16                305
#define SKY_KEY_F17                306
#define SKY_KEY_F18                307
#define SKY_KEY_F19                308
#define SKY_KEY_F20                309
#define SKY_KEY_F21                310
#define SKY_KEY_F22                311
#define SKY_KEY_F23                312
#define SKY_KEY_F24                313
#define SKY_KEY_F25                314
#define SKY_KEY_KP_0               320
#define SKY_KEY_KP_1               321
#define SKY_KEY_KP_2               322
#define SKY_KEY_KP_3               323
#define SKY_KEY_KP_4               324
#define SKY_KEY_KP_5               325
#define SKY_KEY_KP_6               326
#define SKY_KEY_KP_7               327
#define SKY_KEY_KP_8               328
#define SKY_KEY_KP_9               329
#define SKY_KEY_KP_DECIMAL         330
#define SKY_KEY_KP_DIVIDE          331
#define SKY_KEY_KP_MULTIPLY        332
#define SKY_KEY_KP_SUBTRACT        333
#define SKY_KEY_KP_ADD             334
#define SKY_KEY_KP_ENTER           335
#define SKY_KEY_KP_EQUAL           336
#define SKY_KEY_LEFT_SHIFT         340
#define SKY_KEY_LEFT_CONTROL       341
#define SKY_KEY_LEFT_ALT           342
#define SKY_KEY_LEFT_SUPER         343
#define SKY_KEY_RIGHT_SHIFT        344
#define SKY_KEY_RIGHT_CONTROL      345
#define SKY_KEY_RIGHT_ALT          346
#define SKY_KEY_RIGHT_SUPER        347
#define SKY_KEY_MENU               348

#define SKY_KEY_LAST               SKY_KEY_MENU


/*  mods Modifier key flags
 *
 *  See [key input](@ref input_key) for how these are used.

/*  If this bit is set one or more Shift keys were held down.
 */
#define SKY_MOD_SHIFT           0x0001
/*  If this bit is set one or more Control keys were held down.
 */
#define SKY_MOD_CONTROL         0x0002
/*  If this bit is set one or more Alt keys were held down.
 */
#define SKY_MOD_ALT             0x0004
/*  If this bit is set one or more Super keys were held down.
 */
#define SKY_MOD_SUPER           0x0008

/*  buttons Mouse buttons
 *
 *  See [mouse button input](@ref input_mouse_button) for how these are used.
 */
#define SKY_MOUSE_BUTTON_1         0
#define SKY_MOUSE_BUTTON_2         1
#define SKY_MOUSE_BUTTON_3         2
#define SKY_MOUSE_BUTTON_4         3
#define SKY_MOUSE_BUTTON_5         4
#define SKY_MOUSE_BUTTON_6         5
#define SKY_MOUSE_BUTTON_7         6
#define SKY_MOUSE_BUTTON_8         7
#define SKY_MOUSE_BUTTON_LAST      SKY_MOUSE_BUTTON_8
#define SKY_MOUSE_BUTTON_LEFT      SKY_MOUSE_BUTTON_1
#define SKY_MOUSE_BUTTON_RIGHT     SKY_MOUSE_BUTTON_2
#define SKY_MOUSE_BUTTON_MIDDLE    SKY_MOUSE_BUTTON_3
/*! @} */

/*  Joysticks
 *
 *  See [joystick input](@ref joystick) for how these are used.
 */
#define SKY_JOYSTICK_1             0
#define SKY_JOYSTICK_2             1
#define SKY_JOYSTICK_3             2
#define SKY_JOYSTICK_4             3
#define SKY_JOYSTICK_5             4
#define SKY_JOYSTICK_6             5
#define SKY_JOYSTICK_7             6
#define SKY_JOYSTICK_8             7
#define SKY_JOYSTICK_9             8
#define SKY_JOYSTICK_10            9
#define SKY_JOYSTICK_11            10
#define SKY_JOYSTICK_12            11
#define SKY_JOYSTICK_13            12
#define SKY_JOYSTICK_14            13
#define SKY_JOYSTICK_15            14
#define SKY_JOYSTICK_16            15
#define SKY_JOYSTICK_LAST          SKY_JOYSTICK_16


#endif /* SkyKeysDef_h */
