//#include "stdafx.h"
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include "arry1.h"
#include "string.h"


#if 0
unsigned int GetFileSize(char *filename);
void read_src(char *path, unsigned char *buf, unsigned int size);
void make_dstfile(char *outpath, unsigned char *buf, unsigned int size);

int main()
{
unsigned char *buf = NULL;

unsigned int size;
char srcbmp[100]={0};
char dstfile[100]={0};
//char srcbmp[100]="test.bin";
//char dstfile[100]="test.h";
printf("Please input src file name\nC file path name\n");
scanf("%s %s",srcbmp,dstfile);
size = GetFileSize(srcbmp);
buf = (unsigned char *)malloc(sizeof(unsigned char)*size);
read_src(srcbmp, buf, size);
make_dstfile(dstfile, buf, size);

	return 0;
}
unsigned int GetFileSize(char *filename)
{
	unsigned int  siz = 0;
	FILE  *fp = fopen(filename, "rb");
	if (fp)
	{
		fseek(fp, 0, SEEK_END);
		siz = ftell(fp);
		fclose(fp);
	}
	return siz;
}

void read_src(char *path, unsigned char *buf, unsigned int size)
{
	FILE *infile;

	if((infile=fopen(path,"rb"))==NULL)
	{
		printf( "\nCan not open the path: %s \n", path);
		exit(-1);
	}

	fread(buf, sizeof(unsigned char), size, infile);//printf("\n�򿪵�ͼΪ %d",img->bfType);

	fclose(infile);
}
void make_dstfile(char *outpath, unsigned char *buf, unsigned int size)
{
	FILE *infile;
	int i,j,k,n;
	char pbuf[10]={0};
	if((infile=fopen(outpath,"wa+"))==NULL)
	{
		printf( "\nCan not open the path: %s \n", outpath);
		exit(-1);
	}
	k=0;

	fwrite("u8 temp_array[] = {\n",strlen("u8 m_firmware_data_200[] = {\n"),1,infile);
	for(i = 0; i < size; i++)
	{
			k++;
			sprintf(pbuf,"0x%02x",buf[i]);
			fwrite(pbuf,strlen(pbuf),1,infile);
			if(k != 8)
			fwrite(", ",strlen(", "),1,infile);
			else
			fwrite(",",strlen(","),1,infile);

			if(k==8)
			{
				k=0;
				fwrite("\n",strlen("\n"),1,infile);

			}

	}

	fseek(infile,0,SEEK_END);
	if(k == 0)
		fwrite("};",strlen("};"),1,infile);
	else
		fwrite("\n};",strlen("\n};"),1,infile);


	fclose(infile);
}
#endif

#define UINT16	unsigned short
#define UINT8	unsigned char

typedef unsigned int 	UINT32;
//unsigned char g_flashdata[10]={0xA5,0x5A,0x5A,0xA5,0x00,0x10,0x04,0x08,0x00,0x00};

//unsigned char g_flashdata[0x3FFC00]={0x00,0x80,0x00,0x00,0x00,0xD0,0x18,0x00,0x00,0x20,0x39,0x00,0x00,0xc0,0x3f,0x00,0x00,0x90,0x3f,0x00,0x01,0x00};

const UINT16 crc16_table[16] =
{
       0x0000,0x1021,0x2042,0x3063,
       0x4084,0x50a5,0x60c6,0x70e7,
       0x8108,0x9129,0xa14a,0xb16b,
       0xc18c,0xd1ad,0xe1ce,0xf1ef,
};

const UINT32 CRC32_table[256] =
{
       0x00000000, 0x0E939C67, 0x1D2738CE, 0x13B4A4A9, 0x3A4E719C, 0x34DDEDFB, 0x27694952, 0x29FAD535,
       0x749CE338, 0x7A0F7F5F, 0x69BBDBF6, 0x67284791, 0x4ED292A4, 0x40410EC3, 0x53F5AA6A, 0x5D66360D,
       0x390EAC35, 0x379D3052, 0x242994FB, 0x2ABA089C, 0x0340DDA9, 0x0DD341CE, 0x1E67E567, 0x10F47900,
       0x4D924F0D, 0x4301D36A, 0x50B577C3, 0x5E26EBA4, 0x77DC3E91, 0x794FA2F6, 0x6AFB065F, 0x64689A38,
       0x721D586A, 0x7C8EC40D, 0x6F3A60A4, 0x61A9FCC3, 0x485329F6, 0x46C0B591, 0x55741138, 0x5BE78D5F,
       0x0681BB52, 0x08122735, 0x1BA6839C, 0x15351FFB, 0x3CCFCACE, 0x325C56A9, 0x21E8F200, 0x2F7B6E67,
       0x4B13F45F, 0x45806838, 0x5634CC91, 0x58A750F6, 0x715D85C3, 0x7FCE19A4, 0x6C7ABD0D, 0x62E9216A,
       0x3F8F1767, 0x311C8B00, 0x22A82FA9, 0x2C3BB3CE, 0x05C166FB, 0x0B52FA9C, 0x18E65E35, 0x1675C252,
       0x340DDA91, 0x3A9E46F6, 0x292AE25F, 0x27B97E38, 0x0E43AB0D, 0x00D0376A, 0x136493C3, 0x1DF70FA4,
       0x409139A9, 0x4E02A5CE, 0x5DB60167, 0x53259D00, 0x7ADF4835, 0x744CD452, 0x67F870FB, 0x696BEC9C,
       0x0D0376A4, 0x0390EAC3, 0x10244E6A, 0x1EB7D20D, 0x374D0738, 0x39DE9B5F, 0x2A6A3FF6, 0x24F9A391,
       0x799F959C, 0x770C09FB, 0x64B8AD52, 0x6A2B3135, 0x43D1E400, 0x4D427867, 0x5EF6DCCE, 0x506540A9,
       0x461082FB, 0x48831E9C, 0x5B37BA35, 0x55A42652, 0x7C5EF367, 0x72CD6F00, 0x6179CBA9, 0x6FEA57CE,
       0x328C61C3, 0x3C1FFDA4, 0x2FAB590D, 0x2138C56A, 0x08C2105F, 0x06518C38, 0x15E52891, 0x1B76B4F6,
       0x7F1E2ECE, 0x718DB2A9, 0x62391600, 0x6CAA8A67, 0x45505F52, 0x4BC3C335, 0x5877679C, 0x56E4FBFB,
       0x0B82CDF6, 0x05115191, 0x16A5F538, 0x1836695F, 0x31CCBC6A, 0x3F5F200D, 0x2CEB84A4, 0x227818C3,
       0x681BB522, 0x66882945, 0x753C8DEC, 0x7BAF118B, 0x5255C4BE, 0x5CC658D9, 0x4F72FC70, 0x41E16017,
       0x1C87561A, 0x1214CA7D, 0x01A06ED4, 0x0F33F2B3, 0x26C92786, 0x285ABBE1, 0x3BEE1F48, 0x357D832F,
       0x51151917, 0x5F868570, 0x4C3221D9, 0x42A1BDBE, 0x6B5B688B, 0x65C8F4EC, 0x767C5045, 0x78EFCC22,
       0x2589FA2F, 0x2B1A6648, 0x38AEC2E1, 0x363D5E86, 0x1FC78BB3, 0x115417D4, 0x02E0B37D, 0x0C732F1A,
       0x1A06ED48, 0x1495712F, 0x0721D586, 0x09B249E1, 0x20489CD4, 0x2EDB00B3, 0x3D6FA41A, 0x33FC387D,
       0x6E9A0E70, 0x60099217, 0x73BD36BE, 0x7D2EAAD9, 0x54D47FEC, 0x5A47E38B, 0x49F34722, 0x4760DB45,
       0x2308417D, 0x2D9BDD1A, 0x3E2F79B3, 0x30BCE5D4, 0x194630E1, 0x17D5AC86, 0x0461082F, 0x0AF29448,
       0x5794A245, 0x59073E22, 0x4AB39A8B, 0x442006EC, 0x6DDAD3D9, 0x63494FBE, 0x70FDEB17, 0x7E6E7770,
       0x5C166FB3, 0x5285F3D4, 0x4131577D, 0x4FA2CB1A, 0x66581E2F, 0x68CB8248, 0x7B7F26E1, 0x75ECBA86,
       0x288A8C8B, 0x261910EC, 0x35ADB445, 0x3B3E2822, 0x12C4FD17, 0x1C576170, 0x0FE3C5D9, 0x017059BE,
       0x6518C386, 0x6B8B5FE1, 0x783FFB48, 0x76AC672F, 0x5F56B21A, 0x51C52E7D, 0x42718AD4, 0x4CE216B3,
       0x118420BE, 0x1F17BCD9, 0x0CA31870, 0x02308417, 0x2BCA5122, 0x2559CD45, 0x36ED69EC, 0x387EF58B,
       0x2E0B37D9, 0x2098ABBE, 0x332C0F17, 0x3DBF9370, 0x14454645, 0x1AD6DA22, 0x09627E8B, 0x07F1E2EC,
       0x5A97D4E1, 0x54044886, 0x47B0EC2F, 0x49237048, 0x60D9A57D, 0x6E4A391A, 0x7DFE9DB3, 0x736D01D4,
       0x17059BEC, 0x1996078B, 0x0A22A322, 0x04B13F45, 0x2D4BEA70, 0x23D87617, 0x306CD2BE, 0x3EFF4ED9,
       0x639978D4, 0x6D0AE4B3, 0x7EBE401A, 0x702DDC7D, 0x59D70948, 0x5744952F, 0x44F03186, 0x4A63ADE1
};

static UINT32 check_CRC32(UINT32 crc,const UINT8* input, UINT32 len )
       {
              UINT32 i;
              unsigned char index;
              unsigned char* pch;
              pch = ( unsigned char* ) input;

              for ( i=0; i<len; i++ )
              {
                     index = ( crc^*pch ) & 0xFF;
                     crc = ( crc>>8 ) ^CRC32_table[index];
                     pch++;
              }

              return (crc ^ 0xFFFFFFFF);
       }


static UINT16 check_CRC16 ( const UINT8* psrc, UINT32 nLen )
       {
              UINT8   da = 0;
              UINT16  crc = 0;

              while ( nLen-- != 0 )
              {
                     da = ( ( UINT8 ) ( crc >> 8 ) ) >> 4;
                     crc <<= 4;
                     crc ^= crc16_table[da^ ( *psrc>>4 )];
                     da = ( ( UINT8 ) ( crc >> 8 ) ) >> 4;
                     crc <<= 4;
                     crc ^= crc16_table[da^ ( *psrc&0x0f )];
                     psrc++;
              }

              return ( crc & 0xFFFF );
       }
int test_ret();
int main(void)
{
  #if 1
  static unsigned int crc=0xFFFFFFFF;
  printf("sizeofdata=%d\r\n",sizeof(int));
  crc=check_CRC32(crc,arry1,0x3FFC00);
  printf("crc_value=%x",crc);
  #endif
  int value=0;
  value=test_ret();
}

int test_ret()
{
    int flag=0;
    while(1)
    {
        if(flag==0)
        {
            return 1;
        }
        else
            return 0;
    }

    flag++;
    flag=0;

    return 3;
}
