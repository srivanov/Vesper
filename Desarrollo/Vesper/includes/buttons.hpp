// Conversion de nuestros botones a los de irrlicht//enum Keys {//    SKY_MOUSE_BUTTON_1      =   KEY_LBUTTON,//    SKY_MOUSE_BUTTON_2      =   KEY_RBUTTON,//    SKY_MOUSE_BUTTON_MIDDLE	=   KEY_MBUTTON,//    SKY_KEY_TAB             =   KEY_TAB,//    SKY_KEY_BACKSPACE       =   KEY_CLEAR,//    SKY_KEY_KP_ENTER        =   KEY_RETURN,//    SKY_KEY_ESCAPE          =   KEY_ESCAPE,//    SKY_KEY_SPACE           =   KEY_SPACE,//    SKY_KEY_LEFT			=	KEY_LEFT,//    SKY_KEY_UP				=	KEY_UP,//    SKY_KEY_RIGHT			=	KEY_RIGHT,//    SKY_KEY_DOWN			=	KEY_DOWN,//    SKY_KEY_0				=	KEY_KEY_0,//    SKY_KEY_1				=	KEY_KEY_1,//    SKY_KEY_2				=	KEY_KEY_2,//    SKY_KEY_3				=	KEY_KEY_3,//    SKY_KEY_4				=	KEY_KEY_4,//    SKY_KEY_5				=	KEY_KEY_5,//    SKY_KEY_6				=	KEY_KEY_6,//    SKY_KEY_7				=	KEY_KEY_7,//    SKY_KEY_8				=	KEY_KEY_8,//    SKY_KEY_9				=	KEY_KEY_9,//    SKY_KEY_A				=	KEY_KEY_A,//    SKY_KEY_B				=	KEY_KEY_B,//    SKY_KEY_C				=	KEY_KEY_C,//    SKY_KEY_D				=	KEY_KEY_D,//    SKY_KEY_E				=	KEY_KEY_E,//    SKY_KEY_F				=	KEY_KEY_F,//    SKY_KEY_G				=	KEY_KEY_G,//    SKY_KEY_H				=	KEY_KEY_H,//    SKY_KEY_I				=	KEY_KEY_I,//    SKY_KEY_J				=	KEY_KEY_J,//    SKY_KEY_K				=	KEY_KEY_K,//    SKY_KEY_L				=	KEY_KEY_L,//    SKY_KEY_M				=	KEY_KEY_M,//    SKY_KEY_N				=	KEY_KEY_N,//    SKY_KEY_O				=	KEY_KEY_O,//    SKY_KEY_P				=	KEY_KEY_P,//    SKY_KEY_Q				=	KEY_KEY_Q,//    SKY_KEY_R				=	KEY_KEY_R,//    SKY_KEY_S				=	KEY_KEY_S,//    SKY_KEY_T				=	KEY_KEY_T,//    SKY_KEY_U				=	KEY_KEY_U,//    SKY_KEY_V				=	KEY_KEY_V,//    SKY_KEY_W				=	KEY_KEY_W,//    SKY_KEY_X				=	KEY_KEY_X,//    SKY_KEY_Y				=	KEY_KEY_Y,//    SKY_KEY_Z				=	KEY_KEY_Z,//    SKY_KEY_F1				=	KEY_F1,//    SKY_KEY_F2				=	KEY_F2,//    SKY_KEY_F3				=	KEY_F3,//    SKY_KEY_F4				=	KEY_F4,//    SKY_KEY_F5				=	KEY_F5,//    SKY_KEY_F6				=	KEY_F6,//    SKY_KEY_F7				=	KEY_F7,//    SKY_KEY_F8				=	KEY_F8,//    SKY_KEY_F9				=	KEY_F9,//    SKY_KEY_F10				=	KEY_F10,//    SKY_KEY_F11				=	KEY_F11,//    SKY_KEY_F12				=	KEY_F12,//    SKY_KEY_F13				=	KEY_F13,//    SKY_KEY_F14				=	KEY_F14,//    SKY_KEY_F15				=	KEY_F15,//    SKY_KEY_F16				=	KEY_F16,//    SKY_KEY_F17				=	KEY_F17,//    SKY_KEY_F18				=	KEY_F18,//    SKY_KEY_F19				=	KEY_F19,//    SKY_KEY_F20				=	KEY_F20,//    SKY_KEY_F21				=	KEY_F21,//    SKY_KEY_F22				=	KEY_F22,//    SKY_KEY_F23				=	KEY_F23,//    SKY_KEY_F24				=	KEY_F24,//    SKY_KEY_LEFT_SHIFT		=	KEY_LSHIFT,//    SKY_KEY_RIGHT_SHIFT		=	KEY_RSHIFT,//    SKY_KEY_LEFT_CONTROL	=	KEY_LCONTROL,//    SKY_KEY_RIGHT_CONTROL	=	KEY_RCONTROL//};#define SKY_MOUSE_BUTTON_1			KEY_LBUTTON#define SKY_MOUSE_BUTTON_2			KEY_RBUTTON#define SKY_MOUSE_BUTTON_MIDDLE		KEY_MBUTTON#define SKY_KEY_TAB					KEY_TAB#define SKY_KEY_BACKSPACE			KEY_CLEAR#define SKY_KEY_KP_ENTER			KEY_RETURN#define SKY_KEY_ESCAPE				KEY_ESCAPE#define SKY_KEY_SPACE				KEY_SPACE#define SKY_KEY_LEFT				KEY_LEFT#define SKY_KEY_UP					KEY_UP#define SKY_KEY_RIGHT				KEY_RIGHT#define SKY_KEY_DOWN				KEY_DOWN#define SKY_KEY_0					KEY_KEY_0#define SKY_KEY_1					KEY_KEY_1#define SKY_KEY_2					KEY_KEY_2#define SKY_KEY_3					KEY_KEY_3#define SKY_KEY_4					KEY_KEY_4#define SKY_KEY_5					KEY_KEY_5#define SKY_KEY_6					KEY_KEY_6#define SKY_KEY_7					KEY_KEY_7#define SKY_KEY_8					KEY_KEY_8#define SKY_KEY_9					KEY_KEY_9#define SKY_KEY_A					KEY_KEY_A#define SKY_KEY_B					KEY_KEY_B#define SKY_KEY_C					KEY_KEY_C#define SKY_KEY_D					KEY_KEY_D#define SKY_KEY_E					KEY_KEY_E#define SKY_KEY_F					KEY_KEY_F#define SKY_KEY_G					KEY_KEY_G#define SKY_KEY_H					KEY_KEY_H#define SKY_KEY_I					KEY_KEY_I#define SKY_KEY_J					KEY_KEY_J#define SKY_KEY_K					KEY_KEY_K#define SKY_KEY_L					KEY_KEY_L#define SKY_KEY_M					KEY_KEY_M#define SKY_KEY_N					KEY_KEY_N#define SKY_KEY_O					KEY_KEY_O#define SKY_KEY_P					KEY_KEY_P#define SKY_KEY_Q					KEY_KEY_Q#define SKY_KEY_R					KEY_KEY_R#define SKY_KEY_S					KEY_KEY_S#define SKY_KEY_T					KEY_KEY_T#define SKY_KEY_U					KEY_KEY_U#define SKY_KEY_V					KEY_KEY_V#define SKY_KEY_W					KEY_KEY_W#define SKY_KEY_X					KEY_KEY_X#define SKY_KEY_Y					KEY_KEY_Y#define SKY_KEY_Z					KEY_KEY_Z#define SKY_KEY_F1					KEY_F1#define SKY_KEY_F2					KEY_F2#define SKY_KEY_F3					KEY_F3#define SKY_KEY_F4					KEY_F4#define SKY_KEY_F5					KEY_F5#define SKY_KEY_F6					KEY_F6#define SKY_KEY_F7					KEY_F7#define SKY_KEY_F8					KEY_F8#define SKY_KEY_F9					KEY_F9#define SKY_KEY_F10					KEY_F10#define SKY_KEY_F11					KEY_F11#define SKY_KEY_F12					KEY_F12#define SKY_KEY_F13					KEY_F13#define SKY_KEY_F14					KEY_F14#define SKY_KEY_F15					KEY_F15#define SKY_KEY_F16					KEY_F16#define SKY_KEY_F17					KEY_F17#define SKY_KEY_F18					KEY_F18#define SKY_KEY_F19					KEY_F19#define SKY_KEY_F20					KEY_F20#define SKY_KEY_F21					KEY_F21#define SKY_KEY_F22					KEY_F22#define SKY_KEY_F23					KEY_F23#define SKY_KEY_F24					KEY_F24#define SKY_KEY_LEFT_SHIFT			KEY_LSHIFT#define SKY_KEY_RIGHT_SHIFT			KEY_RSHIFT#define SKY_KEY_LEFT_CONTROL		KEY_LCONTROL#define SKY_KEY_RIGHT_CONTROL		KEY_RCONTROL