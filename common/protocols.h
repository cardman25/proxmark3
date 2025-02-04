#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include <stdint.h>


//The following data is taken from http://www.proxmark.org/forum/viewtopic.php?pid=13501#p13501
/*
ISO14443A (usually NFC tags)
	26 (7bits) = REQA
	30 = Read (usage: 30+1byte block number+2bytes ISO14443A-CRC - answer: 16bytes)
	A2 = Write (usage: A2+1byte block number+4bytes data+2bytes ISO14443A-CRC - answer: 0A [ACK] or 00 [NAK])
	52 (7bits) = WUPA (usage: 52(7bits) - answer: 2bytes ATQA)
	93 20 = Anticollision (usage: 9320 - answer: 4bytes UID+1byte UID-bytes-xor)
	93 70 = Select (usage: 9370+5bytes 9320 answer - answer: 1byte SAK)
	95 20 = Anticollision of cascade level2
	95 70 = Select of cascade level2
	50 00 = Halt (usage: 5000+2bytes ISO14443A-CRC - no answer from card)
Mifare
	60 = Authenticate with KeyA
	61 = Authenticate with KeyB
	40 (7bits) = Used to put Chinese Changeable UID cards in special mode (must be followed by 43 (8bits) - answer: 0A)
	C0 = Decrement
	C1 = Increment
	C2 = Restore
	B0 = Transfer
Ultralight C
	A0 = Compatibility Write (to accomodate MIFARE commands)
	1A = Step1 Authenticate
	AF = Step2 Authenticate


ISO14443B
	05 = REQB
	1D = ATTRIB
	50 = HALT
SRIX4K (tag does not respond to 05)
	06 00 = INITIATE
	0E xx = SELECT ID (xx = Chip-ID)
	0B = Get UID
	08 yy = Read Block (yy = block number)
	09 yy dd dd dd dd = Write Block (yy = block number; dd dd dd dd = data to be written)
	0C = Reset to Inventory
	0F = Completion
	0A 11 22 33 44 55 66 = Authenticate (11 22 33 44 55 66 = data to authenticate)


ISO15693
	MANDATORY COMMANDS (all ISO15693 tags must support those)
		01 = Inventory (usage: 260100+2bytes ISO15693-CRC - answer: 12bytes)
		02 = Stay Quiet
	OPTIONAL COMMANDS (not all tags support them)
		20 = Read Block (usage: 0220+1byte block number+2bytes ISO15693-CRC - answer: 4bytes)
		21 = Write Block (usage: 0221+1byte block number+4bytes data+2bytes ISO15693-CRC - answer: 4bytes)
		22 = Lock Block
		23 = Read Multiple Blocks (usage: 0223+1byte 1st block to read+1byte last block to read+2bytes ISO15693-CRC)
		25 = Select
		26 = Reset to Ready
		27 = Write AFI
		28 = Lock AFI
		29 = Write DSFID
		2A = Lock DSFID
		2B = Get_System_Info (usage: 022B+2bytes ISO15693-CRC - answer: 14 or more bytes)
		2C = Read Multiple Block Security Status (usage: 022C+1byte 1st block security to read+1byte last block security to read+2bytes ISO15693-CRC)

EM Microelectronic CUSTOM COMMANDS
	A5 = Active EAS (followed by 1byte IC Manufacturer code+1byte EAS type)
	A7 = Write EAS ID (followed by 1byte IC Manufacturer code+2bytes EAS value)
	B8 = Get Protection Status for a specific block (followed by 1byte IC Manufacturer code+1byte block number+1byte of how many blocks after the previous is needed the info)
	E4 = Login (followed by 1byte IC Manufacturer code+4bytes password)
NXP/Philips CUSTOM COMMANDS
	A0 = Inventory Read
	A1 = Fast Inventory Read
	A2 = Set EAS
	A3 = Reset EAS
	A4 = Lock EAS
	A5 = EAS Alarm
	A6 = Password Protect EAS
	A7 = Write EAS ID
	A8 = Read EPC
	B0 = Inventory Page Read
	B1 = Fast Inventory Page Read
	B2 = Get Random Number
	B3 = Set Password
	B4 = Write Password
	B5 = Lock Password
	B6 = Bit Password Protection
	B7 = Lock Page Protection Condition
	B8 = Get Multiple Block Protection Status
	B9 = Destroy SLI
	BA = Enable Privacy
	BB = 64bit Password Protection
	40 = Long Range CMD (Standard ISO/TR7003:1990)
		*/

#define ICLASS_CMD_ACTALL           0x0A
#define ICLASS_CMD_READ_OR_IDENTIFY 0x0C
#define ICLASS_CMD_SELECT           0x81
#define ICLASS_CMD_PAGESEL          0x84
#define ICLASS_CMD_READCHECK_KD     0x88
#define ICLASS_CMD_READCHECK_KC     0x18
#define ICLASS_CMD_CHECK_KC         0x95
#define ICLASS_CMD_CHECK_KD         0x05
#define ICLASS_CMD_DETECT           0x0F
#define ICLASS_CMD_HALT             0x00
#define ICLASS_CMD_UPDATE           0x87
#define ICLASS_CMD_ACT              0x8E
#define ICLASS_CMD_READ4            0x06


#define ISO14443A_CMD_REQA       0x26
#define ISO14443A_CMD_WUPA       0x52
#define ISO14443A_CMD_ANTICOLL_OR_SELECT     0x93
#define ISO14443A_CMD_ANTICOLL_OR_SELECT_2   0x95
#define ISO14443A_CMD_ANTICOLL_OR_SELECT_3   0x97
#define ISO14443A_CMD_HALT       0x50
#define ISO14443A_CMD_RATS       0xE0

#define MIFARE_CMD_READBLOCK     0x30
#define MIFARE_CMD_WRITEBLOCK    0xA0
#define MIFARE_AUTH_KEYA         0x60
#define MIFARE_AUTH_KEYB         0x61
#define MIFARE_MAGICWUPC1        0x40
#define MIFARE_MAGICWUPC2        0x43
#define MIFARE_MAGICWIPEC        0x41
#define MIFARE_CMD_INC           0xC0
#define MIFARE_CMD_DEC           0xC1
#define MIFARE_CMD_RESTORE       0xC2
#define MIFARE_CMD_TRANSFER      0xB0

#define MIFARE_EV1_PERSONAL_UID  0x40
#define MIFARE_EV1_UIDF0         0x00
#define MIFARE_EV1_UIDF1         0x40
#define MIFARE_EV1_UIDF2         0x20
#define MIFARE_EV1_UIDF3         0x60
#define MIFARE_EV1_SETMODE       0x43

#define MIFARE_ULC_WRITE         0xA2
#define MIFARE_ULC_COMP_WRITE    MIFARE_CMD_WRITEBLOCK
#define MIFARE_ULC_AUTH_1        0x1A
#define MIFARE_ULC_AUTH_2        0xAF

#define MIFARE_ULEV1_AUTH        0x1B
#define MIFARE_ULEV1_VERSION     0x60
#define MIFARE_ULEV1_FASTREAD    0x3A
#define MIFARE_ULEV1_WRITE       0xA2
#define MIFARE_ULEV1_COMP_WRITE  MIFARE_CMD_WRITEBLOCK
#define MIFARE_ULEV1_READ_CNT    0x39
#define MIFARE_ULEV1_INCR_CNT    0xA5
#define MIFARE_ULEV1_READSIG     0x3C
#define MIFARE_ULEV1_CHECKTEAR   0x3E
#define MIFARE_ULEV1_VCSL        0x4B

// mifare 4bit card answers
#define CARD_ACK                 0x0A  // 1010 - ACK
#define CARD_NACK_NA             0x04  // 0100 - NACK, not allowed (command not allowed)
#define CARD_NACK_TR             0x05  // 0101 - NACK, transmission error


/**
06 00 = INITIATE
0E xx = SELECT ID (xx = Chip-ID)
0B = Get UID
08 yy = Read Block (yy = block number)
09 yy dd dd dd dd = Write Block (yy = block number; dd dd dd dd = data to be written)
0C = Reset to Inventory
0F = Completion
0A 11 22 33 44 55 66 = Authenticate (11 22 33 44 55 66 = data to authenticate)
**/

#define ISO14443B_REQB         0x05
#define ISO14443B_ATTRIB       0x1D
#define ISO14443B_HALT         0x50
#define ISO14443B_INITIATE     0x06
#define ISO14443B_SELECT       0x0E
#define ISO14443B_GET_UID      0x0B
#define ISO14443B_READ_BLK     0x08
#define ISO14443B_WRITE_BLK    0x09
#define ISO14443B_RESET        0x0C
#define ISO14443B_COMPLETION   0x0F
#define ISO14443B_AUTHENTICATE 0x0A

// ISO15693 COMMANDS
#define ISO15693_INVENTORY                   0x01
#define ISO15693_STAYQUIET                   0x02
#define ISO15693_READBLOCK                   0x20
#define ISO15693_WRITEBLOCK                  0x21
#define ISO15693_LOCKBLOCK                   0x22
#define ISO15693_READ_MULTI_BLOCK            0x23
#define ISO15693_SELECT                      0x25
#define ISO15693_RESET_TO_READY              0x26
#define ISO15693_WRITE_AFI                   0x27
#define ISO15693_LOCK_AFI                    0x28
#define ISO15693_WRITE_DSFID                 0x29
#define ISO15693_LOCK_DSFID                  0x2A
#define ISO15693_GET_SYSTEM_INFO             0x2B
#define ISO15693_READ_MULTI_SECSTATUS        0x2C

// ISO15693 REQUEST FLAGS
#define ISO15693_REQ_SUBCARRIER_TWO          (1<<0)
#define ISO15693_REQ_DATARATE_HIGH           (1<<1)
#define ISO15693_REQ_INVENTORY               (1<<2)
#define ISO15693_REQ_PROTOCOL_EXT            (1<<3) // RFU
#define ISO15693_REQ_OPTION                  (1<<6) // Command specific option selector
// when REQ_INVENTORY is not set
#define ISO15693_REQ_SELECT                  (1<<4) // only selected cards response
#define ISO15693_REQ_ADDRESS                 (1<<5) // this req contains an address
// when REQ_INVENTORY is set
#define ISO15693_REQINV_AFI                  (1<<4) // AFI Field is present
#define ISO15693_REQINV_SLOT1                (1<<5) // 1 Slot     (16 slots if not set)

// ISO15693 RESPONSE FLAGS
#define ISO15693_RES_ERROR                   (1<<0)
#define ISO15693_RES_EXT                     (1<<3) // Protocol Extention	

// ISO15693 RESPONSE ERROR CODES
#define ISO15693_NOERROR                     0x00
#define ISO15693_ERROR_CMD_NOT_SUP           0x01 // Command not supported
#define ISO15693_ERROR_CMD_NOT_REC           0x02 // Command not recognized (eg. parameter error)
#define ISO15693_ERROR_CMD_OPTION            0x03 // Command option not supported
#define ISO15693_ERROR_GENERIC               0x0F // No additional Info about this error
#define ISO15693_ERROR_BLOCK_UNAVAILABLE     0x10
#define ISO15693_ERROR_BLOCK_LOCKED_ALREADY  0x11 // cannot lock again
#define ISO15693_ERROR_BLOCK_LOCKED          0x12 // cannot be changed
#define ISO15693_ERROR_BLOCK_WRITE           0x13 // Writing was unsuccessful
#define ISO15693_ERROR_BLOCL_WRITELOCK       0x14 // Locking was unsuccessful


// Topaz command set:
#define	TOPAZ_REQA						0x26	// Request
#define	TOPAZ_WUPA						0x52	// WakeUp
#define	TOPAZ_RID						0x78	// Read ID
#define	TOPAZ_RALL						0x00	// Read All (all bytes)
#define	TOPAZ_READ						0x01	// Read (a single byte)
#define	TOPAZ_WRITE_E					0x53	// Write-with-erase (a single byte)
#define	TOPAZ_WRITE_NE					0x1a	// Write-no-erase (a single byte)
// additional commands for Dynamic Memory Model
#define TOPAZ_RSEG						0x10	// Read segment
#define TOPAZ_READ8						0x02	// Read (eight bytes)
#define TOPAZ_WRITE_E8					0x54	// Write-with-erase (eight bytes)
#define TOPAZ_WRITE_NE8					0x1B	// Write-no-erase (eight bytes)

// HITAG1 commands
#define HITAG1_SET_CCNEW                0xC2    // left 5 bits only
#define HITAG1_READ_ID                  0x00    // not a real command, consists of 5 bits length, <length> bits partial SN, 8 bits CRC
#define HITAG1_SELECT                   0x00    // left 5 bits only, followed by 32 bits SN and 8 bits CRC
#define HITAG1_WRPPAGE                  0x80    // left 4 bits only, followed by 8 bits page and 8 bits CRC
#define HITAG1_WRPBLK                   0x90    // left 4 bits only, followed by 8 bits block and 8 bits CRC
#define HITAG1_WRCPAGE                  0xA0    // left 4 bits only, followed by 8 bits page or key information and 8 bits CRC
#define HITAG1_WRCBLK                   0xB0    // left 4 bits only, followed by 8 bits block and 8 bits CRC
#define HITAG1_RDPPAGE                  0xC0    // left 4 bits only, followed by 8 bits page and 8 bits CRC
#define HITAG1_RDPBLK                   0xD0    // left 4 bits only, followed by 8 bits block and 8 bits CRC
#define HITAG1_RDCPAGE                  0xE0    // left 4 bits only, followed by 8 bits page and 8 bits CRC
#define HITAG1_RDCBLK                   0xF0    // left 4 bits only, followed by 8 bits block and 8 bits CRC
#define HITAG1_HALT                     0x70    // left 4 bits only, followed by 8 bits (dummy) page and 8 bits CRC

// HITAG2 commands
#define HITAG2_START_AUTH               0xC0    // left 5 bits only
#define HITAG2_READ_PAGE                0xC0    // page number in bits 5 to 3, page number inverted in bit 0 and following 2 bits
#define HITAG2_READ_PAGE_INVERTED       0x44    // page number in bits 5 to 3, page number inverted in bit 0 and following 2 bits
#define HITAG2_WRITE_PAGE               0x82    // page number in bits 5 to 3, page number inverted in bit 0 and following 2 bits
#define HITAG2_HALT                     0x00    // left 5 bits only

#define ISO_14443A    0
#define ICLASS        1
#define ISO_14443B    2
#define TOPAZ         3
#define PROTO_MIFARE  4
#define ISO_7816_4    5
#define ISO_15693     6
#define ISO_14443_4   7


//-- Picopass fuses
#define FUSE_FPERS   0x80
#define FUSE_CODING1 0x40
#define FUSE_CODING0 0x20
#define FUSE_CRYPT1  0x10
#define FUSE_CRYPT0  0x08
#define FUSE_FPROD1  0x04
#define FUSE_FPROD0  0x02
#define FUSE_RA      0x01

// ISO 7816-4 Basic interindustry commands. For command APDU's.
#define ISO7816_ERASE_BINARY             0x0E
#define ISO7816_VERIFY                   0x20
#define ISO7816_MANAGE_CHANNEL           0x70
#define ISO7816_EXTERNAL_AUTHENTICATE    0x82
#define ISO7816_GET_CHALLENGE            0x84
#define ISO7816_INTERNAL_AUTHENTICATE    0x88
#define ISO7816_SELECT_FILE              0xA4
#define ISO7816_GET_PROCESSING_OPTIONS   0xA8
#define ISO7816_READ_BINARY              0xB0
#define ISO7816_READ_RECORDS             0xB2
#define ISO7816_GET_RESPONSE             0xC0
#define ISO7816_ENVELOPE                 0xC2
#define ISO7816_GET_DATA                 0xCA
#define ISO7816_WRITE_BINARY             0xD0
#define ISO7816_WRITE_RECORD             0xD2
#define ISO7816_UPDATE_BINARY            0xD6
#define ISO7816_PUT_DATA                 0xDA
#define ISO7816_UPDATE_DATA              0xDC
#define ISO7816_APPEND_RECORD            0xE2
// ISO7816-4	For response APDU's
#define ISO7816_OK                       0x9000
//	6x xx = ERROR
#define ISO7816_MAX_FRAME_SIZE           261


/* T55x7 configuration register definitions */
#define T55x7_POR_DELAY             0x00000001
#define T55x7_ST_TERMINATOR         0x00000008
#define T55x7_PWD                   0x00000010
#define T55x7_MAXBLOCK_SHIFT        5
#define T55x7_AOR                   0x00000200
#define T55x7_PSKCF_RF_2            0
#define T55x7_PSKCF_RF_4            0x00000400
#define T55x7_PSKCF_RF_8            0x00000800
#define T55x7_MODULATION_DIRECT     0
#define T55x7_MODULATION_PSK1       0x00001000
#define T55x7_MODULATION_PSK2       0x00002000
#define T55x7_MODULATION_PSK3       0x00003000
#define T55x7_MODULATION_FSK1       0x00004000
#define T55x7_MODULATION_FSK2       0x00005000
#define T55x7_MODULATION_FSK1a      0x00006000
#define T55x7_MODULATION_FSK2a      0x00007000
#define T55x7_MODULATION_MANCHESTER 0x00008000
#define T55x7_MODULATION_BIPHASE    0x00010000
#define T55x7_MODULATION_DIPHASE    0x00018000
#define T55x7_X_MODE                0x00020000
#define T55x7_BITRATE_RF_8          0
#define T55x7_BITRATE_RF_16         0x00040000
#define T55x7_BITRATE_RF_32         0x00080000
#define T55x7_BITRATE_RF_40         0x000C0000
#define T55x7_BITRATE_RF_50         0x00100000
#define T55x7_BITRATE_RF_64         0x00140000
#define T55x7_BITRATE_RF_100        0x00180000
#define T55x7_BITRATE_RF_128        0x001C0000

/* T5555 (Q5) configuration register definitions */
#define T5555_ST_TERMINATOR         0x00000001
#define T5555_MAXBLOCK_SHIFT        0x00000001
#define T5555_MODULATION_MANCHESTER 0
#define T5555_MODULATION_PSK1       0x00000010
#define T5555_MODULATION_PSK2       0x00000020
#define T5555_MODULATION_PSK3       0x00000030
#define T5555_MODULATION_FSK1       0x00000040
#define T5555_MODULATION_FSK2       0x00000050
#define T5555_MODULATION_BIPHASE    0x00000060
#define T5555_MODULATION_DIRECT     0x00000070
#define T5555_INVERT_OUTPUT         0x00000080
#define T5555_PSK_RF_2              0
#define T5555_PSK_RF_4              0x00000100
#define T5555_PSK_RF_8              0x00000200
#define T5555_USE_PWD               0x00000400
#define T5555_USE_AOR               0x00000800
#define T5555_SET_BITRATE(x)        (((x-2)/2)<<12)
#define T5555_GET_BITRATE(x)        ((((x >> 12) & 0x3F)*2)+2)
#define T5555_BITRATE_SHIFT         12 //(RF=2n+2)   ie 64=2*0x1F+2   or n = (RF-2)/2
#define T5555_FAST_WRITE            0x00004000
#define T5555_PAGE_SELECT           0x00008000

#define T55XX_WRITE_TIMEOUT 1500

uint32_t GetT55xxClockBit(uint32_t clock);

// em4x05 & em4x69 chip configuration register definitions
#define EM4x05_GET_BITRATE(x)         (((x & 0x3F)*2)+2)
#define EM4x05_SET_BITRATE(x)         ((x-2)/2)
#define EM4x05_MODULATION_NRZ         0x00000000
#define EM4x05_MODULATION_MANCHESTER  0x00000040
#define EM4x05_MODULATION_BIPHASE     0x00000080
#define EM4x05_MODULATION_MILLER      0x000000C0 //not supported by all 4x05/4x69 chips
#define EM4x05_MODULATION_PSK1        0x00000100 //not supported by all 4x05/4x69 chips
#define EM4x05_MODULATION_PSK2        0x00000140 //not supported by all 4x05/4x69 chips
#define EM4x05_MODULATION_PSK3        0x00000180 //not supported by all 4x05/4x69 chips
#define EM4x05_MODULATION_FSK1        0x00000200 //not supported by all 4x05/4x69 chips
#define EM4x05_MODULATION_FSK2        0x00000240 //not supported by all 4x05/4x69 chips
#define EM4x05_PSK_RF_2               0
#define EM4x05_PSK_RF_4               0x00000400
#define EM4x05_PSK_RF_8               0x00000800
#define EM4x05_MAXBLOCK_SHIFT         14
#define EM4x05_FIRST_USER_BLOCK       5
#define EM4x05_SET_NUM_BLOCKS(x)      ((x+5-1)<<14) //# of blocks sent during default read mode
#define EM4x05_GET_NUM_BLOCKS(x)      (((x>>14) & 0xF)-5+1)
#define EM4x05_READ_LOGIN_REQ         1<<18
#define EM4x05_READ_HK_LOGIN_REQ      1<<19
#define EM4x05_WRITE_LOGIN_REQ        1<<20
#define EM4x05_WRITE_HK_LOGIN_REQ     1<<21
#define EM4x05_READ_AFTER_WRITE       1<<22
#define EM4x05_DISABLE_ALLOWED        1<<23
#define EM4x05_READER_TALK_FIRST      1<<24

#endif 
// PROTOCOLS_H
