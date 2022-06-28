
_port_direction:

;GPIO.c,8 :: 		void port_direction(char base,char state)
;GPIO.c,10 :: 		{  if(state==OUTPUT)
	MOVF       FARG_port_direction_state+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_port_direction0
;GPIO.c,11 :: 		reset_port(*(volatile char *)(base|0x80));
	MOVLW      128
	IORWF      FARG_port_direction_base+0, 0
	MOVWF      FSR
	CLRF       INDF+0
L_port_direction0:
;GPIO.c,13 :: 		if(state==INPUT)
	MOVF       FARG_port_direction_state+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_port_direction1
;GPIO.c,14 :: 		set_port(*(volatile char *)(base|0x80));
	MOVLW      128
	IORWF      FARG_port_direction_base+0, 0
	MOVWF      FSR
	MOVLW      255
	MOVWF      INDF+0
L_port_direction1:
;GPIO.c,16 :: 		}
L_end_port_direction:
	RETURN
; end of _port_direction

_pin_direction:

;GPIO.c,19 :: 		void pin_direction(char base , char bin ,char state)
;GPIO.c,22 :: 		if(state==OUTPUT)
	MOVF       FARG_pin_direction_state+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_pin_direction2
;GPIO.c,23 :: 		reset_bin(*(volatile char *)(base|0x80),bin);
	MOVLW      128
	IORWF      FARG_pin_direction_base+0, 0
	MOVWF      R2+0
	MOVF       FARG_pin_direction_bin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__pin_direction10:
	BTFSC      STATUS+0, 2
	GOTO       L__pin_direction11
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__pin_direction10
L__pin_direction11:
	COMF       R0+0, 0
	MOVWF      R1+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	ANDWF      R0+0, 1
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_pin_direction2:
;GPIO.c,25 :: 		if(state==INPUT)
	MOVF       FARG_pin_direction_state+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_pin_direction3
;GPIO.c,26 :: 		set_bin(*(volatile char *)(base|0x80),bin);
	MOVLW      128
	IORWF      FARG_pin_direction_base+0, 0
	MOVWF      R2+0
	MOVF       FARG_pin_direction_bin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__pin_direction12:
	BTFSC      STATUS+0, 2
	GOTO       L__pin_direction13
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__pin_direction12
L__pin_direction13:
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_pin_direction3:
;GPIO.c,28 :: 		}
L_end_pin_direction:
	RETURN
; end of _pin_direction

_read_bin:

;GPIO.c,31 :: 		char read_bin(char base,char bin)
;GPIO.c,34 :: 		result = (*(volatile char *)(base)) & (1<<bin);
	MOVF       FARG_read_bin_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R2+0
	MOVF       FARG_read_bin_bin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__read_bin15:
	BTFSC      STATUS+0, 2
	GOTO       L__read_bin16
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__read_bin15
L__read_bin16:
	MOVF       R0+0, 0
	ANDWF      R2+0, 0
	MOVWF      R1+0
;GPIO.c,36 :: 		if (result==1)
	MOVF       R1+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_read_bin4
;GPIO.c,37 :: 		return 1;
	MOVLW      1
	MOVWF      R0+0
	GOTO       L_end_read_bin
L_read_bin4:
;GPIO.c,39 :: 		return 0;
	CLRF       R0+0
;GPIO.c,42 :: 		}
L_end_read_bin:
	RETURN
; end of _read_bin

_read_port:

;GPIO.c,44 :: 		char read_port (char base)
;GPIO.c,48 :: 		return  (*(volatile char *)(base));
	MOVF       FARG_read_port_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
;GPIO.c,50 :: 		}
L_end_read_port:
	RETURN
; end of _read_port

_port_write:

;GPIO.c,52 :: 		void port_write (char base ,char value)
;GPIO.c,56 :: 		(*(volatile char *)(base))=value;
	MOVF       FARG_port_write_base+0, 0
	MOVWF      FSR
	MOVF       FARG_port_write_value+0, 0
	MOVWF      INDF+0
;GPIO.c,58 :: 		}
L_end_port_write:
	RETURN
; end of _port_write

_bin_write:

;GPIO.c,61 :: 		void bin_write (char base ,char value ,char bin)
;GPIO.c,65 :: 		if(value==0)
	MOVF       FARG_bin_write_value+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_bin_write6
;GPIO.c,66 :: 		reset_bin(*(volatile char *)(base),bin);
	MOVF       FARG_bin_write_bin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__bin_write20:
	BTFSC      STATUS+0, 2
	GOTO       L__bin_write21
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__bin_write20
L__bin_write21:
	COMF       R0+0, 0
	MOVWF      R1+0
	MOVF       FARG_bin_write_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	ANDWF      R0+0, 1
	MOVF       FARG_bin_write_base+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_bin_write6:
;GPIO.c,69 :: 		if(value==1)
	MOVF       FARG_bin_write_value+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_bin_write7
;GPIO.c,70 :: 		set_bin(*(volatile char *)(base),bin);
	MOVF       FARG_bin_write_bin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__bin_write22:
	BTFSC      STATUS+0, 2
	GOTO       L__bin_write23
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__bin_write22
L__bin_write23:
	MOVF       FARG_bin_write_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	MOVF       FARG_bin_write_base+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_bin_write7:
;GPIO.c,72 :: 		}
L_end_bin_write:
	RETURN
; end of _bin_write
