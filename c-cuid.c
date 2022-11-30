#include <stdio.h>
#include <sys/timeb.h>
#include <stdlib.h>
#include <string.h>
#include "c-cuid.h"
#ifdef _WIN32
#include <winsock2.h>
#endif
int discreteValues = 1679616; // 1679616 = 36^4 which is the value right next to the maximum int that gives 4 characters long base36 string
char* padCounter(char* buff, int len){
	if(len == 4) return buff;
	int zerosToAdd = 4 - len;
	char backup[4];
	strcpy(backup, buff);
	for(int i = 0; i < zerosToAdd; i++) buff[i] = '0';
	for(int i = zerosToAdd; i < 4; i++) buff[i] = backup[i - zerosToAdd];
}
double randnum(){
	unsigned int i;
	#ifdef __unix__
	FILE *fp;
	fp = fopen("/dev/urandom", "r");
	fread(&i, 1, 4, fp);
	fclose(fp);
	#elif defined(_WIN32)
	rand_s(&i);
	#endif
	return (double)i/ 4294967295; // i / ( 2 ** 32 - 1 )
}
int get_pid(){
	#ifdef __unix__
	return getpid();
	#elif defined(_WIN32)
	return GetCurrentProcessId();
	#endif
}
char *reverse(char *str)
{
    char *end = str;
    char *start = str;

    if(!str || !*str) return str;
    while(*(end + 1)) end++;
    while(end > start)
    {
        int ch = *end;
        *end-- = *start;
        *start++ = ch;
    }
    return str;
}
char* tobase36string(char* buff, time_t num) {
	const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *savedbuff = buff;
    if(buff)
    {
        do
        {
			*buff++ = digits[abs(num % 36)];
			num /= 36;
        }while(num);
        *buff = 0;
        reverse(savedbuff);
    }
    return savedbuff;
}
void randomBlock(char* buff){
	int random = randnum() * discreteValues;
	tobase36string(buff, random);
	padCounter(buff, strlen(buff));
}
int safeCounter(){
	static int counter = 0;
	if(counter >= 1679616) counter = 0; 
	counter++;
	return counter - 1;
}
char* cuid(char* buff){
	buff[0] = 'c';
	struct timeb timestampb;
	ftime(&timestampb);
	char counterS[5];
	char pidS[4];
	char timestampS[9];
	char hostS[10];
	char hostname[20];
	char random1[5];
	char random2[5];
	tobase36string(&timestampS, 1000 * timestampb.time + timestampb.millitm);

	for(int i = 0; i < 8; i++) {
		buff[i+1] = timestampS[i];
	}
	int counterValue = safeCounter();
	tobase36string(counterS, counterValue);
	padCounter(counterS, strlen(counterS));

	for(int i = 0; i < 4; i++) {
		buff[i+9] = counterS[i];
	}
	int pid = get_pid();
	tobase36string(pidS, pid);
	buff[13] = pidS[0];
	buff[14] = pidS[1];
	#ifdef _WIN32
	WSADATA wsaData;
	WSAStartup(MAKEWORD( 1, 0 ), &wsaData);
	WSACleanup();
	#endif
	gethostname(hostname, 20);
	int hlen = strlen(hostname);
	int initial = hlen + 36;
	for (int i = 0; i < hlen; i++) initial += (int) hostname[i];
	tobase36string(hostS, initial);
	buff[15] = hostS[0];
	buff[16] = hostS[1] != 0 ? hostS[1] : '0';
	randomBlock(random1);
	randomBlock(random2);
	for (int i = 0; i < 4; i++) buff[17+i] = random1[i];
	for (int i = 0; i < 4; i++) buff[21+i] = random2[i];
	buff[25] = 0;
}
char* slug(char* buff){
	struct timeb timestampb;
	ftime(&timestampb);
	char pidS[4];
	char timestampS[9];
	char counterS[5];
	char randomS[5];
	char hostS[10];
	char hostname[20];
	tobase36string(&timestampS, 1000 * timestampb.time + timestampb.millitm);
	buff[0] = timestampS[6];
	buff[1] = timestampS[7];
	tobase36string(counterS, safeCounter());
	int len = strlen(counterS);
	int i = 2;
	for(; i < len+2; i++) buff[i] = counterS[i-2];
	int pid = get_pid();
	tobase36string(pidS, pid);
	buff[i++] = pidS[0];
	#ifdef _WIN32
	WSADATA wsaData;
	WSAStartup(MAKEWORD( 1, 0 ), &wsaData);
	WSACleanup();
	#endif
	gethostname(hostname, 20);
	int hlen = strlen(hostname);
	int initial = hlen + 36;
	for (int j = 0; j < hlen; j++) initial += (int) hostname[j];
	tobase36string(hostS, initial);
	buff[i++] = hostS[0];
	randomBlock(randomS);
	buff[i++] = randomS[2];
	buff[i++] = randomS[3];
	buff[i] = 0;
}
_Bool isCuid(char* buff){
	if(buff[0] != 'c' || strlen(buff) < 25) return 0;
	return 1;
}
_Bool isSlug(char* buff){
	int len = strlen(buff);
	if(len >= 7 && len <= 10) return 1;
	return 0;
}