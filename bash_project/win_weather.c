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
    int weather_table[]={105, 120, 203, 218, 305, 320, 404, 419, 505, 520, 605, 621, 706,
        722, 807, 822, 907, 922, 1008, 1023, 1107, 1122, 1206, 1221,
        1299};//last one just to simply the judge

    int today = (1+p->tm_mon)*100 + p->tm_mday;
    //printf("today :  %d\n", today);
    int i;
    for(i=0; today>weather_table[i]; ++i)
        /* do nothing */;
    if(i == 0) {
        if(today == weather_table[0])
            i = 1;
        else
            i = 24;
    }
    char *picture_path = (char*)malloc(200);
    sprintf(picture_path, "gsettings set org.gnome.desktop.background picture-uri \"file:///home/yonghao/Pictures/weather/%d.jpg\"", i);
    cout<<picture_path<<endl;
    //    cout<<strlen(picture_path)<<endl;
    system(picture_path);
    //  SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0,(PVOID)picture_path, SPIF_UPDATEINIFILE+SPIF_SENDWININICHANGE);
}

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
