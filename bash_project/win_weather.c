#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <iostream>
#include <string>
using namespace std;
int main()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep); //把日期和时间转换为格林威治(GMT)时间的函数
    const char* weather_table[]={"1-5", "1-20", "2-3", "2-18", "3-5", "3-20", "4-4", "4-19", "5-5", "5-20", "6-5", "6-21", "7-6", "7-22", "8-7", "8-22", "9-7", "9-22", "10-8", "10-23", "11-7", "11-22", "12-6", "12-21"};

    char *today = (char*)malloc(20);
    //char *today = new char(20);
    sprintf(today, "%d-%d", 1+p->tm_mon, p->tm_mday);
    printf("today :  %s\n", today);
    int i;
    for(i=0; weather_table[i]; ++i) {
        int state = strcmp(today, weather_table[i]);
        if(!state) {
            cout<<"true: i is"<<i<<endl;
            break;
        }else if(state > 0) {
            //cout<<weather_table[i]<<endl;
            cout<<"true: i is"<<i<<endl;
        }else {
            cout<<weather_table[i]<<endl;
            cout<<"else: i is"<<i<<endl;
            break;
        }
    }
    //printf("Month:  %d\n", 1+p->tm_mon);
    //printf("Day:  %d\n", p->tm_mday);
    //printf("Year:  %d\n", 1900+p->tm_year);
    //printf("Hour:  %d\n", p->tm_hour);
    //printf("Minute:  %d\n", p->tm_min);
    //printf("Second:  %d\n",  p->tm_sec);
    //printf("Weekday:  %d\n", p->tm_wday);
    //printf("Days:  %d\n", p->tm_yday);
    //printf("Isdst:  %d\n", p->tm_isdst);
}

//wallpaper.c
//by onezeros@yahoo.cn||Zhijie Lee
//usage:wallpaper "full directory path" interval
//			interval is in minutes

//#include <windows.h>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
///*	argc=3;
//	argv[1]="E://picture//testbmp";
//	argv[2]="1";
//*/	LPCSTR currentDir;
//	LPCSTR currentImage;
//	int interval;
//		
//	HKEY hKey;
//	WIN32_FIND_DATAA FileData;
//	HANDLE hFind;
//	
//	//initialize parameters
//	if(argc==1){
//		//find parameters in registry
//		if(RegOpenKeyA(HKEY_LOCAL_MACHINE,(LPCSTR)"Software//wallpaper",
//				&hKey)!=ERROR_SUCCESS||
//			RegQueryValueExA(hKey,(LPCSTR)"interval",0,NULL,
//				(LPBYTE)interval,NULL)!=ERROR_SUCCESS||
//			RegQueryValueExA(hKey,(LPCSTR)"directory",0,NULL,
//				(LPBYTE)currentDir,NULL)!=ERROR_SUCCESS||
//			RegQueryValueExA(hKey,(LPCSTR)"image",0,NULL,
//				(LPBYTE)currentImage,NULL)!=ERROR_SUCCESS){
//			//if connot be found ,wrong usage
//			cout<<"wrong usage"<<endl
//				<<"Please use it like this"<<endl
//				<<"wallpaper /"D://Files//Images/" 30"<<endl
//				<<"30 is the interval in minutes or"<<endl
//				<<"wallpaper /"D://Files//Images/""<<endl
//				<<"with 30 minutes as default interval"<<endl;
//			exit(1);
//		}else{
//			hFind=FindFirstFileA(currentImage,&FileData);
//			if(hFind==INVALID_HANDLE_VALUE){
//				cout<<"connot open file";
//				exit(1);
//			}
//		}
//	}else if(argc==3){
//		interval=60000*atoi(argv[2]);
//		currentDir=(LPCSTR)argv[1];
//		SetCurrentDirectoryA(currentDir);
//		hFind = FindFirstFileA((LPCSTR)"*.jpg",&FileData);
//		//hFind = FindFirstFileA((LPCSTR)"228973.jpg",&FileData);
//		if (hFind == INVALID_HANDLE_VALUE) {
//			cout<<"Invalid directory.Last Error reports "<<endl;
//			exit(1);
//		} else {
//			currentImage=FileData.cFileName;
//			//register the directory
//			RegCreateKeyA(HKEY_LOCAL_MACHINE,(LPCSTR)"Software//wallpaper",&hKey);
//			RegSetValueExA(hKey,(LPCSTR)"directory",0,REG_SZ,
//				(CONST BYTE*)currentDir,strlen((const char*)currentDir));
//			RegSetValueExA(hKey,(LPCSTR)"image",0,REG_SZ,
//				(CONST BYTE*)currentImage,strlen((const char*)currentImage));
//			RegSetValueExA(hKey,(LPCSTR)"interval",0,REG_DWORD,
//				(CONST BYTE*)&interval,4);
//		}
//	}else{//wrong parameters
//		cout<<"wrong parameters"<<endl;
//		exit(1);
//	}
//	
//		
//	//circle and wait
//	while(1){
//		//set wallpaper
//		bool b=false;
//        string fullpath((char*)currentDir);
//		fullpath+=string("//");
//        fullpath+=string((char*)currentImage);
//		b=SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0,(PVOID)fullpath.c_str(),SPIF_UPDATEINIFILE+SPIF_SENDWININICHANGE);
//
//		if(b==false){
//			cout<<"failed to call /"SystemParametersInfoA/" ";
//			exit(1);
//		}
//		Sleep(interval);
//		if (!FindNextFileA(hFind, &FileData)){
//			if (GetLastError() == ERROR_NO_MORE_FILES){ 
//				hFind = FindFirstFileA((LPCSTR)"*.jpg",&FileData);
//			}else{ 
//				printf("Couldn't find next file."); 
//				exit(1);
//			} 
//		}
//		currentImage=FileData.cFileName;
//		//register the currentfile 
//		RegSetValueExA(hKey,(LPCSTR)"image",0,REG_SZ,
//			(CONST BYTE*)currentImage,strlen((const char*)currentImage));
//	}
//	
//	//FindClose(hFind);
//	//RegCloseKey(hKey);
//	
//	return 0;
//}
//
//
