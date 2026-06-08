/PROG  TRAJ15
/ATTR
OWNER		= MNEDITOR;
COMMENT		= "T_eCC21_SR1_OP90";
PROG_SIZE	= 12800;
CREATE		= DATE 22-10-09  TIME 15:53:18;
MODIFIED	= DATE 23-03-05  TIME 08:11:32;
FILE_NAME	= TRAJ5;
VERSION		= 0;
LINE_COUNT	= 209;
MEMORY_SIZE	= 13144;
PROTECT		= READ_WRITE;
TCD:  STACK_SIZE	= 0,
      TASK_PRIORITY	= 50,
      TIME_SLICE	= 0,
      BUSY_LAMP_OFF	= 0,
      ABORT_REQUEST	= 0,
      PAUSE_REQUEST	= 0;
DEFAULT_GROUP	= 1,1,*,*,*;
CONTROL_CODE	= 00000001 00000000;
/APPL
  SPOT : TRUE ; 
  SPOT Welding Equipment Number : 1 ;
/MN
   1:  !******************************** ;
   2:  !* Trajectoire de soudure       * ;
   3:  !* T_eCC21_SR1_PFS1             * ;
   4:  !* ROBOT UR7114                 * ;
   5:  !******************************** ;
   6:   ;
   7:  PAYLOAD[2] ;
   8:   ;
   9:  UFRAME_NUM=3 ;
  10:  UTOOL_NUM=1 ;
  11:   ;
  12:  CALL CTRLPOSITION(50) ;
  13:J PR[50:POS1 eP21] 100% FINE    ;
  14:   ;
  15:  !CTRL PIECE ;
  16:  CALL GRIP_CHK(1,1,1,500) ;
  17:   ;
  18:  !CTRL METIER ;
  19:  CALL SW_CHECK(1,R[1:Kod API]) ;
  20:   ;
  21:  !SORTIE INTER 5  AVEC RB ;
  22:  CALL IT_OUT(5) ;
  23:   ;
  24:J P[1] 100% CNT70    ;
  25:J P[2] 100% CNT70    ;
  26:J P[3] 100% CNT70    ;
  27:   ;
  28:  CALL SW_WELD(1,20700) ;
  29:L P[4:SRE20700] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  30:   ;
  31:  CALL SW_WELD(1,20702) ;
  32:L P[5:SRE20702] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  33:   ;
  34:J P[6] 100% CNT70    ;
  35:   ;
  36:  CALL SW_WELD(1,24626) ;
  37:L P[7:SRE24706] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  38:   ;
  39:J P[8] 100% CNT70    ;
  40:   ;
  41:  CALL SW_WELD(1,24618) ;
  42:L P[9:SRE24618] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  43:   ;
  44:J P[10] 100% CNT50    ;
  45:J P[11] 100% CNT50    ;
  46:   ;
  47:  CALL SW_WELD(1,20732) ;
  48:L P[12:SRE20732] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  49:   ;
  50:J P[13] 100% CNT50    ;
  51:J P[14] 100% CNT70    ;
  52:   ;
  53:  CALL SW_WELD(1,24670) ;
  54:L P[15:SRE24670] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  55:   ;
  56:J P[16] 100% CNT70    ;
  57:J P[17] 100% CNT70    ;
  58:J P[18] 100% CNT70    ;
  59:J P[19] 100% CNT70    ;
  60:J P[20] 100% CNT70    ;
  61:   ;
  62:  CALL SW_WELD(1,24988) ;
  63:L P[21:SRE24988] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=3]    ;
  64:   ;
  65:  CALL SW_WELD(1,24986) ;
  66:L P[22:SRE24986] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  67:   ;
  68:  CALL SW_WELD(1,24822) ;
  69:L P[23:SRE24822] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  70:   ;
  71:  CALL SW_WELD(1,24832) ;
  72:L P[24:SRE24832] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=2]    ;
  73:   ;
  74:  CALL SW_WELD(1,24828) ;
  75:L P[25:SRE24828] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  76:   ;
  77:  CALL SW_WELD(1,24834) ;
  78:L P[26:SRE24834] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  79:   ;
  80:  CALL SW_WELD(1,24826) ;
  81:L P[27:SRE24826] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=2]    ;
  82:   ;
  83:  CALL SW_WELD(1,24824) ;
  84:L P[28:SRE24824] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  85:   ;
  86:  CALL SW_WELD(1,24836) ;
  87:L P[29:SRE24836] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=2]    ;
  88:   ;
  89:  CALL SW_WELD(1,24830) ;
  90:L P[30:SRE24830] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
  91:   ;
  92:J P[31] 100% CNT50    ;
  93:J P[32] 100% CNT50    ;
  94:   ;
  95:  CALL SW_WELD(1,24874) ;
  96:L P[33:SRE24874] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
  97:   ;
  98:  CALL SW_WELD(1,24862) ;
  99:L P[34:SRE24862] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 100:   ;
 101:J P[35] 100% CNT70    ;
 102:J P[36] 100% CNT70    ;
 103:J P[37] 100% CNT70    ;
 104:J P[38] 100% CNT70    ;
 105:J P[39] 100% CNT70    ;
 106:J P[40] 100% CNT70    ;
 107:   ;
 108:  CALL SW_WELD(1,24627) ;
 109:L P[41:SRE24707] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 110:   ;
 111:  CALL SW_WELD(1,24629) ;
 112:L P[42:SRE24733] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 113:   ;
 114:J P[43] 100% CNT70    ;
 115:   ;
 116:  CALL SW_WELD(1,24619) ;
 117:L P[44:SRE24619] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
 118:   ;
 119:J P[45] 100% CNT70    ;
 120:J P[46] 100% CNT70    ;
 121:   ;
 122:  CALL SW_WELD(1,24671) ;
 123:L P[47:SRE24671] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 124:   ;
 125:J P[48] 100% CNT70    ;
 126:J P[49] 100% CNT70    ;
 127:J P[50] 100% CNT70    ;
 128:J P[51] 100% CNT70    ;
 129:J P[52] 100% CNT70    ;
 130:   ;
 131:J P[87] 100% CNT70    ;
 132:J P[86] 100% CNT50    ;
 133:J P[60] 100% CNT30    ;
 134:J P[55] 100% CNT30    ;
 135:J P[88] 100% CNT30    ;
 136:   ;
 137:  CALL SW_WELD(1,24989) ;
 138:L P[53:SRE24989] 2000mm/sec FINE RTCP
    :  SPOT[SD=1,P=1,S=1,ED=1]    ;
 139:   ;
 140:  CALL SW_WELD(1,24987) ;
 141:L P[54:SRE24987] 2000mm/sec FINE RTCP
    :  SPOT[SD=1,P=1,S=1,ED=1]    ;
 142:   ;
 143:  CALL SW_WELD(1,24823) ;
 144:L P[56:SRE24823] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=2]    ;
 145:   ;
 146:  CALL SW_WELD(1,24833) ;
 147:L P[57:SRE24833] 2000mm/sec FINE RTCP
    :  SPOT[SD=1,P=1,S=1,ED=1]    ;
 148:   ;
 149:  CALL SW_WELD(1,24829) ;
 150:L P[58:SRE24829] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=2]    ;
 151:   ;
 152:  CALL SW_WELD(1,24835) ;
 153:L P[59:SRE24835] 2000mm/sec FINE RTCP
    :  SPOT[SD=1,P=1,S=1,ED=1]    ;
 154:   ;
 155:  CALL SW_WELD(1,24827) ;
 156:L P[61:SRE24827] 2000mm/sec FINE RTCP
    :  SPOT[SD=1,P=1,S=1,ED=2]    ;
 157:   ;
 158:  CALL SW_WELD(1,24825) ;
 159:L P[62:SRE24825] 2000mm/sec FINE RTCP
    :  SPOT[SD=1,P=1,S=1,ED=1]    ;
 160:   ;
 161:  CALL SW_WELD(1,24837) ;
 162:L P[63:SRE24837] 2000mm/sec FINE RTCP
    :  SPOT[SD=1,P=1,S=1,ED=1]    ;
 163:   ;
 164:  CALL SW_WELD(1,24831) ;
 165:L P[64:SRE24831] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=2]    ;
 166:   ;
 167:J P[65] 100% CNT50    ;
 168:J P[66] 100% CNT50    ;
 169:J P[67] 100% CNT30    ;
 170:   ;
 171:  CALL SW_WELD(1,24875) ;
 172:L P[68:SRE24875] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=2]    ;
 173:   ;
 174:  CALL SW_WELD(1,24863) ;
 175:L P[69:SRE24863] 2000mm/sec FINE RTCP
    :  SPOT[SD=2,P=1,S=1,ED=4]    ;
 176:   ;
 177:J P[70] 100% CNT50    ;
 178:J P[71] 100% CNT50    ;
 179:J P[72] 100% CNT50    ;
 180:J P[73] 100% CNT70    ;
 181:J P[74] 100% CNT70    ;
 182:   ;
 183:  CALL SW_WELD(1,24601) ;
 184:L P[75:SRE24601] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
 185:   ;
 186:J P[76] 100% CNT70    ;
 187:J P[77] 100% CNT70    ;
 188:   ;
 189:  CALL SW_WELD(1,24937) ;
 190:L P[78:SRE24937] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 191:   ;
 192:  CALL SW_WELD(1,24931) ;
 193:L P[79:SRE24931] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 194:   ;
 195:  CALL SW_WELD(1,24935) ;
 196:L P[80:SRE24935] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 197:   ;
 198:  CALL SW_WELD(1,24933) ;
 199:L P[81:SRE24933] 2000mm/sec FINE RTCP
    :  SPOT[SD=4,P=1,S=1,ED=4]    ;
 200:   ;
 201:J P[82] 100% CNT20    ;
 202:J P[83] 100% CNT20    ;
 203:   ;
 204:  CALL SW_WELD(1,24600) ;
 205:L P[84:SRE24600] 2000mm/sec FINE RTCP
    :  SPOT[SD=3,P=1,S=1,ED=3]    ;
 206:   ;
 207:J P[85] 100% CNT70    ;
 208:   ;
 209:J PR[64:Pos_Fin_Traj5] 100% FINE    ;
/POS
P[1]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1659.078  mm,	RY =   495.277  mm,	RZ =   -65.777  mm,
	RW =      .001 deg,	RP =      .002 deg,	RR =   125.002 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   349.000  mm
};
P[2]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1813.044  mm,	RY =   194.223  mm,	RZ =   -60.306  mm,
	RW =      .001 deg,	RP =     -.004 deg,	RR =   134.999 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   349.000  mm
};
P[3]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1874.591  mm,	RY =    99.564  mm,	RZ =    65.070  mm,
	RW =     -.001 deg,	RP =     -.006 deg,	RR =   134.999 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   200.000  mm
};
P[4:"SRE20700"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1859.429  mm,	RY =   107.001  mm,	RZ =   224.358  mm,
	RW =     -.000 deg,	RP =      .000 deg,	RR =   133.785 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    45.000  mm
};
P[5:"SRE20702"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1857.252  mm,	RY =   195.210  mm,	RZ =   225.530  mm,
	RW =     -.000 deg,	RP =      .000 deg,	RR =   136.785 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    45.000  mm
};
P[6]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1814.013  mm,	RY =   195.210  mm,	RZ =   215.436  mm,
	RW =     0.000 deg,	RP =     0.000 deg,	RR =   136.785 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    45.000  mm
};
P[7:"SRE24706"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1858.510  mm,	RY =   314.700  mm,	RZ =   225.438  mm,
	RW =     -.000 deg,	RP =      .000 deg,	RR =   133.785 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    45.000  mm
};
P[8]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1840.018  mm,	RY =   352.017  mm,	RZ =   187.316  mm,
	RW =     2.899 deg,	RP =     4.094 deg,	RR =   127.262 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    62.832  mm
};
P[9:"SRE24618"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1852.018  mm,	RY =   440.142  mm,	RZ =   208.349  mm,
	RW =    -2.656 deg,	RP =    27.296 deg,	RR =    83.890 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    39.189  mm
};
P[10]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2145.535  mm,	RY =   308.224  mm,	RZ =    70.247  mm,
	RW =     2.376 deg,	RP =     7.444 deg,	RR =   112.086 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   200.000  mm
};
P[11]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2171.322  mm,	RY =   316.391  mm,	RZ =   118.393  mm,
	RW =      .000 deg,	RP =      .000 deg,	RR =   112.897 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   184.679  mm
};
P[12:"SRE20732"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2255.840  mm,	RY =   311.907  mm,	RZ =   161.437  mm,
	RW =     -.001 deg,	RP =      .000 deg,	RR =   108.000 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    89.956  mm
};
P[13]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2253.589  mm,	RY =   311.907  mm,	RZ =   106.221  mm,
	RW =     -.001 deg,	RP =      .000 deg,	RR =   108.000 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   250.000  mm
};
P[14]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2353.034  mm,	RY =   417.023  mm,	RZ =   110.976  mm,
	RW =   -11.191 deg,	RP =    12.447 deg,	RR =   137.687 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   330.685  mm
};
P[15:"SRE24670"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2331.437  mm,	RY =   414.887  mm,	RZ =   184.067  mm,
	RW =   -11.191 deg,	RP =    12.447 deg,	RR =   137.687 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    39.000  mm
};
P[16]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2365.053  mm,	RY =   410.436  mm,	RZ =    76.649  mm,
	RW =   -11.188 deg,	RP =    12.448 deg,	RR =   137.690 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   330.635  mm
};
P[17]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2260.199  mm,	RY =   632.025  mm,	RZ =    30.050  mm,
	RW =   -14.169 deg,	RP =     8.133 deg,	RR =   109.617 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   349.000  mm
};
P[18]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1945.525  mm,	RY =   542.954  mm,	RZ =   -21.928  mm,
	RW =     2.799 deg,	RP =    11.379 deg,	RR =    86.909 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   299.996  mm
};
P[19]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1712.106  mm,	RY =   691.483  mm,	RZ =   -65.243  mm,
	RW =     2.487 deg,	RP =     8.817 deg,	RR =    89.146 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   232.001  mm
};
P[20]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1572.036  mm,	RY =   745.311  mm,	RZ =  -100.854  mm,
	RW =     2.581 deg,	RP =     7.407 deg,	RR =    90.371 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    89.752  mm
};
P[21:"SRE24988"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1559.990  mm,	RY =   665.879  mm,	RZ =   -15.550  mm,
	RW =     -.233 deg,	RP =     9.998 deg,	RR =    88.650 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    19.997  mm
};
P[22:"SRE24986"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1610.842  mm,	RY =   665.230  mm,	RZ =   -10.712  mm,
	RW =     -.235 deg,	RP =     9.997 deg,	RR =    88.649 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    20.000  mm
};
P[23:"SRE24822"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1680.869  mm,	RY =   693.266  mm,	RZ =   -17.665  mm,
	RW =     -.207 deg,	RP =     8.899 deg,	RR =    88.653 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    37.600  mm
};
P[24:"SRE24832"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1702.457  mm,	RY =   662.721  mm,	RZ =   -10.496  mm,
	RW =     -.235 deg,	RP =     9.997 deg,	RR =    88.649 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    27.600  mm
};
P[25:"SRE24828"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1718.496  mm,	RY =   691.635  mm,	RZ =   -16.188  mm,
	RW =     -.235 deg,	RP =     9.997 deg,	RR =    88.649 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    30.000  mm
};
P[26:"SRE24834"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1752.009  mm,	RY =   666.579  mm,	RZ =   -11.691  mm,
	RW =     -.235 deg,	RP =     9.997 deg,	RR =    88.649 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    30.000  mm
};
P[27:"SRE24826"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1755.494  mm,	RY =   691.259  mm,	RZ =   -15.422  mm,
	RW =     -.235 deg,	RP =     9.997 deg,	RR =    88.649 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    30.000  mm
};
P[28:"SRE24824"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1792.497  mm,	RY =   691.667  mm,	RZ =   -16.181  mm,
	RW =     -.235 deg,	RP =     9.998 deg,	RR =    88.649 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    30.000  mm
};
P[29:"SRE24836"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1810.985  mm,	RY =   662.179  mm,	RZ =   -11.215  mm,
	RW =    -1.017 deg,	RP =    11.160 deg,	RR =    88.628 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    21.133  mm
};
P[30:"SRE24830"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1824.260  mm,	RY =   691.236  mm,	RZ =   -16.797  mm,
	RW =    -1.017 deg,	RP =    11.163 deg,	RR =    88.628 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    30.045  mm
};
P[31]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1938.675  mm,	RY =   702.226  mm,	RZ =   -24.465  mm,
	RW =    -7.737 deg,	RP =     6.967 deg,	RR =    87.787 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    40.888  mm
};
P[32]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2034.093  mm,	RY =   702.618  mm,	RZ =   -16.394  mm,
	RW =   -17.244 deg,	RP =     2.510 deg,	RR =    72.831 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    68.152  mm
};
P[33:"SRE24874"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2067.046  mm,	RY =   694.199  mm,	RZ =    33.660  mm,
	RW =   -16.178 deg,	RP =    -5.911 deg,	RR =    72.967 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    39.995  mm
};
P[34:"SRE24862"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2088.990  mm,	RY =   693.806  mm,	RZ =    39.764  mm,
	RW =   -16.173 deg,	RP =    -5.897 deg,	RR =    72.976 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    39.990  mm
};
P[35]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2101.964  mm,	RY =   678.124  mm,	RZ =   -77.311  mm,
	RW =   -12.711 deg,	RP =    -8.030 deg,	RR =    48.230 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   273.946  mm
};
P[36]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2355.853  mm,	RY =   847.637  mm,	RZ =   -53.674  mm,
	RW =   -12.711 deg,	RP =    -8.027 deg,	RR =    48.230 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   270.000  mm
};
P[37]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1724.794  mm,	RY =  1072.476  mm,	RZ =    -9.382  mm,
	RW =    -1.136 deg,	RP =   -22.789 deg,	RR =   111.233 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   270.000  mm
};
P[38]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1361.623  mm,	RY =  -351.164  mm,	RZ =   -82.983  mm,
	RW =      .002 deg,	RP =   -16.910 deg,	RR =  -169.995 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   236.000  mm
};
P[39]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1611.361  mm,	RY =  -333.963  mm,	RZ =   -93.968  mm,
	RW =      .001 deg,	RP =      .003 deg,	RR =  -169.994 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   260.000  mm
};
P[40]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1791.568  mm,	RY =  -302.153  mm,	RZ =   -50.263  mm,
	RW =     -.000 deg,	RP =      .001 deg,	RR =  -169.994 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   300.000  mm
};
P[41:"SRE24707"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1859.895  mm,	RY =  -319.875  mm,	RZ =   225.824  mm,
	RW =      .006 deg,	RP =      .009 deg,	RR =  -169.994 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    29.995  mm
};
P[42:"SRE24733"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1853.759  mm,	RY =  -440.181  mm,	RZ =   216.177  mm,
	RW =   -23.180 deg,	RP =    14.658 deg,	RR =  -155.371 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    45.000  mm
};
P[43]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2171.553  mm,	RY =  -364.306  mm,	RZ =    66.590  mm,
	RW =    -5.111 deg,	RP =     4.355 deg,	RR =  -127.245 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   288.137  mm
};
P[44:"SRE24619"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2253.167  mm,	RY =  -310.046  mm,	RZ =   159.964  mm,
	RW =      .054 deg,	RP =      .095 deg,	RR =  -118.681 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    39.101  mm
};
P[45]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2171.997  mm,	RY =  -366.433  mm,	RZ =    85.001  mm,
	RW =    -4.807 deg,	RP =     5.003 deg,	RR =  -127.303 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   288.137  mm
};
P[46]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2350.208  mm,	RY =  -401.133  mm,	RZ =    24.870  mm,
	RW =    10.884 deg,	RP =     8.589 deg,	RR =  -136.689 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   342.526  mm
};
P[47:"SRE24671"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2334.391  mm,	RY =  -408.920  mm,	RZ =   190.546  mm,
	RW =    10.886 deg,	RP =     9.188 deg,	RR =  -137.845 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    59.885  mm
};
P[48]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2346.568  mm,	RY =  -400.768  mm,	RZ =    40.374  mm,
	RW =    10.884 deg,	RP =     8.589 deg,	RR =  -136.689 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   342.526  mm
};
P[49]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1934.052  mm,	RY =  -483.365  mm,	RZ =   -33.638  mm,
	RW =     7.422 deg,	RP =     3.309 deg,	RR =  -164.821 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   290.000  mm
};
P[50]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1764.062  mm,	RY =  -620.964  mm,	RZ =   -95.331  mm,
	RW =     7.422 deg,	RP =     3.309 deg,	RR =  -164.821 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   290.000  mm
};
P[51]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2057.047  mm,	RY =  -803.468  mm,	RZ =   -95.332  mm,
	RW =     7.422 deg,	RP =     3.309 deg,	RR =  -141.575 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   290.000  mm
};
P[52]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2120.561  mm,	RY =  -847.224  mm,	RZ =   -32.503  mm,
	RW =     3.318 deg,	RP =     -.130 deg,	RR =  -110.672 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   199.739  mm
};
P[53:"SRE24989"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1562.353  mm,	RY =  -676.680  mm,	RZ =   -14.613  mm,
	RW =     3.041 deg,	RP =     8.285 deg,	RR =   -55.590 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    10.000  mm
};
P[54:"SRE24987"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1614.824  mm,	RY =  -676.683  mm,	RZ =   -15.515  mm,
	RW =     3.041 deg,	RP =     8.285 deg,	RR =   -58.142 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    10.000  mm
};
P[55]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1825.314  mm,	RY =  -699.289  mm,	RZ =   -59.107  mm,
	RW =     6.936 deg,	RP =     8.044 deg,	RR =   -51.684 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    67.464  mm
};
P[56:"SRE24823"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1681.697  mm,	RY =  -704.489  mm,	RZ =   -19.381  mm,
	RW =     5.704 deg,	RP =     8.953 deg,	RR =   -54.342 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[57:"SRE24833"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1700.653  mm,	RY =  -669.570  mm,	RZ =   -13.098  mm,
	RW =     6.936 deg,	RP =     8.045 deg,	RR =   -54.160 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[58:"SRE24829"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1718.291  mm,	RY =  -703.971  mm,	RZ =   -18.771  mm,
	RW =     6.937 deg,	RP =     8.045 deg,	RR =   -55.001 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[59:"SRE24835"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1750.615  mm,	RY =  -678.359  mm,	RZ =   -13.547  mm,
	RW =     6.937 deg,	RP =     8.045 deg,	RR =   -61.337 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[60]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1827.735  mm,	RY =  -748.476  mm,	RZ =   -67.973  mm,
	RW =     6.936 deg,	RP =     8.044 deg,	RR =   -51.683 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    67.464  mm
};
P[61:"SRE24827"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1750.713  mm,	RY =  -703.682  mm,	RZ =   -18.472  mm,
	RW =     6.936 deg,	RP =     8.045 deg,	RR =   -57.228 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[62:"SRE24825"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1792.546  mm,	RY =  -703.684  mm,	RZ =   -18.184  mm,
	RW =     6.937 deg,	RP =     8.045 deg,	RR =   -58.218 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[63:"SRE24837"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1811.085  mm,	RY =  -667.368  mm,	RZ =   -11.075  mm,
	RW =     6.936 deg,	RP =     8.044 deg,	RR =   -66.176 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[64:"SRE24831"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1824.333  mm,	RY =  -702.881  mm,	RZ =   -17.918  mm,
	RW =     6.936 deg,	RP =     8.044 deg,	RR =   -60.444 deg
   GP2:
	UF : 3, UT : 1,	
	J1=     9.987  mm
};
P[65]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1824.302  mm,	RY =  -703.032  mm,	RZ =   -42.316  mm,
	RW =     6.936 deg,	RP =     8.044 deg,	RR =   -60.444 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    79.115  mm
};
P[66]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1911.675  mm,	RY =  -701.305  mm,	RZ =   -40.028  mm,
	RW =     9.770 deg,	RP =     3.772 deg,	RR =   -67.229 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    77.118  mm
};
P[67]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2029.981  mm,	RY =  -704.992  mm,	RZ =    -8.634  mm,
	RW =    12.895 deg,	RP =      .815 deg,	RR =   -73.036 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    54.072  mm
};
P[68:"SRE24875"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2067.290  mm,	RY =  -698.300  mm,	RZ =    31.473  mm,
	RW =    17.244 deg,	RP =    -1.749 deg,	RR =   -79.866 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    13.471  mm
};
P[69:"SRE24863"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2090.790  mm,	RY =  -696.830  mm,	RZ =    38.563  mm,
	RW =    17.324 deg,	RP =    -1.621 deg,	RR =   -79.784 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    13.470  mm
};
P[70]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2090.951  mm,	RY =  -701.135  mm,	RZ =    38.603  mm,
	RW =    17.323 deg,	RP =    -1.622 deg,	RR =   -79.784 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   154.903  mm
};
P[71]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2129.817  mm,	RY =  -673.248  mm,	RZ =  -109.268  mm,
	RW =    17.245 deg,	RP =    -1.750 deg,	RR =   -79.865 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   287.561  mm
};
P[72]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  3117.168  mm,	RY =  -988.426  mm,	RZ =   273.096  mm,
	RW =     7.856 deg,	RP =   -39.302 deg,	RR =   -42.412 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   287.561  mm
};
P[73]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  3113.599  mm,	RY =  -353.913  mm,	RZ =   142.135  mm,
	RW =      .000 deg,	RP =      .000 deg,	RR =   -14.113 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   236.000  mm
};
P[74]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2838.272  mm,	RY =  -425.819  mm,	RZ =   213.685  mm,
	RW =      .001 deg,	RP =     -.001 deg,	RR =    -1.993 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    61.799  mm
};
P[75:"SRE24601"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2789.573  mm,	RY =  -440.610  mm,	RZ =   227.304  mm,
	RW =      .001 deg,	RP =     -.000 deg,	RR =     -.114 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    37.000  mm
};
P[76]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2674.590  mm,	RY =  -337.215  mm,	RZ =   141.369  mm,
	RW =      .000 deg,	RP =      .000 deg,	RR =   -14.113 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   200.000  mm
};
P[77]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2592.461  mm,	RY =  -305.369  mm,	RZ =    52.140  mm,
	RW =      .001 deg,	RP =      .001 deg,	RR =   -14.113 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   200.000  mm
};
P[78:"SRE24937"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2576.469  mm,	RY =  -308.911  mm,	RZ =   229.178  mm,
	RW =      .000 deg,	RP =      .000 deg,	RR =   -14.113 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    46.787  mm
};
P[79:"SRE24931"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2574.335  mm,	RY =  -216.098  mm,	RZ =   230.383  mm,
	RW =      .340 deg,	RP =      .164 deg,	RR =   -14.112 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    39.994  mm
};
P[80:"SRE24935"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2573.500  mm,	RY =  -195.708  mm,	RZ =   229.273  mm,
	RW =      .351 deg,	RP =      .161 deg,	RR =   -14.112 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    46.594  mm
};
P[81:"SRE24933"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2573.615  mm,	RY =  -175.353  mm,	RZ =   229.663  mm,
	RW =      .458 deg,	RP =      .198 deg,	RR =   -14.112 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    39.994  mm
};
P[82]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2569.663  mm,	RY =  -114.268  mm,	RZ =    93.310  mm,
	RW =     -.366 deg,	RP =     1.734 deg,	RR =    -9.774 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   199.932  mm
};
P[83]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2773.450  mm,	RY =   283.987  mm,	RZ =    85.019  mm,
	RW =     -.368 deg,	RP =     1.733 deg,	RR =    -9.775 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   200.000  mm
};
P[84:"SRE24600"]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2789.188  mm,	RY =   439.221  mm,	RZ =   229.537  mm,
	RW =     -.000 deg,	RP =     -.001 deg,	RR =   -20.000 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    50.000  mm
};
P[85]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2926.518  mm,	RY =   219.842  mm,	RZ =    55.520  mm,
	RW =     -.001 deg,	RP =     -.000 deg,	RR =   -18.693 deg
   GP2:
	UF : 3, UT : 1,	
	J1=   200.000  mm
};
P[86]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1787.516  mm,	RY =  -830.864  mm,	RZ =   183.457  mm,
	RW =    -4.552 deg,	RP =    -1.982 deg,	RR =   -52.295 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    67.464  mm
};
P[87]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  2129.425  mm,	RY =  -831.114  mm,	RZ =   158.417  mm,
	RW =    -4.078 deg,	RP =    -3.051 deg,	RR =   -63.981 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    67.464  mm
};
P[88]{
   GP1:
	UF : 3, UT : 1,		CONFIG : 'N U T, 0, 0, 0',
	RX =  1626.666  mm,	RY =  -708.380  mm,	RZ =   -30.387  mm,
	RW =     2.256 deg,	RP =     7.314 deg,	RR =   -55.523 deg
   GP2:
	UF : 3, UT : 1,	
	J1=    23.920  mm
};
/END
