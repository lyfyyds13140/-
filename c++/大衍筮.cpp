#include <graphics.h>	
#include <stdlib.h>
#include <wchar.h> 
#include <ctime>
#include <conio.h>
#include<math.h>
#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>
#include <sstream>
#include <locale>
#include <codecvt>
#include <Shlobj.h>
#include <tchar.h>
#include <Windows.h>

#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>
#include <__msvc_chrono.hpp>
#include <random>
#include <list>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")
void GetDesktopWallpaperPath(TCHAR* wallpaperPath, DWORD wallpaperPathSize);
void GetDesktopWallpaperPath(TCHAR* wallpaperPath, DWORD wallpaperPathSize) {
    HKEY hKey;
    LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Control Panel\\Desktop"), 0, KEY_READ, &hKey);
    if (result == ERROR_SUCCESS) {
        TCHAR value[MAX_PATH];
        DWORD valueSize = sizeof(value);
        result = RegQueryValueEx(hKey, _T("Wallpaper"), NULL, NULL, (LPBYTE)value, &valueSize);
        if (result == ERROR_SUCCESS) {
            _tcscpy_s(wallpaperPath, wallpaperPathSize, value);
        }
        RegCloseKey(hKey);
    }
}

#define size 80
#define Xyao 100
#define Yyao 600
#define ARRAY_SIZE 64
const char* gua[ARRAY_SIZE] = {
    "坤为地", "地雷复", "地水师", "地泽临", "地山谦", "地火明夷", "地风升", "地天泰",
    "雷地豫", "震为雷", "雷水解", "雷泽归妹", "雷山小过", "雷火丰", "雷风恒", "雷天大壮",
    "水地比", "水雷屯", "坎为水", "水泽节", "水山蹇", "水火既济", "水风井", "水天需",
     "泽地萃", "泽雷随", "泽水困", "兑为泽", "泽山咸", "泽火革", "泽风大过", "泽天夬",
    "山地剥", "山雷颐", "山水蒙", "山泽损", "艮为山", "山火贲", "山风蛊", "山天大畜",
    "火地晋", "火雷噬嗑", "火水未济", "火泽睽", "火山旅", "离为火", "火风鼎", "火天大有",
    "风地观", "风雷益", "风水涣", "风泽中孚", "风山渐", "风火家人", "巽为风", "风天小畜",
    "天地否", "天雷无妄", "天水讼", "天泽履", "天山遁", "天火同人", "天风姤", "乾为天"
};
struct Button {
    int left, top, right, bottom;
};
void ShowTextByLine(const std::wstring& text, int x, int y, int lineHeight) {
    int screenWidth = getmaxx(); // 获取窗口宽度
    std::wstringstream ss(text); // 确保正确使用了 std::wstringstream
    std::wstring word;
    int spaceWidth = textwidth(_T(" ")); // 计算空格的宽度
    while (ss >> word) { // 逐个单词读取
        // 单词的宽度
        int wordWidth = textwidth(word.c_str());
        if (x + wordWidth > screenWidth) { // 检查是否需要换行
            x = 0; // 回到左侧
            y += lineHeight; // 下移一行
        }
        // 显示单词
        outtextxy(x, y, word.c_str());

        // 更新 x 坐标，为下一个单词做准备
        x += wordWidth + spaceWidth;
    }
}



int main()
{
    int yao[6] = { 9,9,9,6,6,6 }, ben = 0, bian = 0, ChouCe = 50,
        dianji = 0, dingwei = 0, moshi = 0, jing, yu1, yu2, jian, tai, ci, Yao, tui = 1;

    double screenWidth = GetSystemMetrics(SM_CXSCREEN);
    double screenHeight = GetSystemMetrics(SM_CYSCREEN);
   

    // 初始化全屏图形窗口
    initgraph(screenWidth, screenHeight, EW_SHOWCONSOLE);
    setbkcolor(BLACK); // 设置背景颜色
    cleardevice();     // 应用背景颜色并清除屏幕
    setfillcolor(WHITE); // 设置绘图颜色为白色
    settextcolor(WHITE); // 设置字体颜色
    // 定义 IMAGE 对象用于存储图片
    TCHAR szWallpaperPath[MAX_PATH];
    GetDesktopWallpaperPath(szWallpaperPath, MAX_PATH);

    // 初始化 GDI+
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // 加载壁纸图像
    Bitmap wallpaper(szWallpaperPath);

    // 计算图像缩放后的大小

    // 调整壁纸图像大小
    Bitmap resizedWallpaper(screenWidth, screenHeight);
    Graphics graphics(&resizedWallpaper);
    graphics.DrawImage(&wallpaper, 0, 0, screenWidth, screenHeight);

    // 将壁纸图像显示到绘图窗口中
    HDC hdc = GetImageHDC();
    Graphics g(hdc);
    g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
    IMAGE img太极, img大衍筮, imgTaiji, img曾老, img卦, img64卦, img经典, img五子棋, img贪吃蛇, img1,
        img浏览器, img应用商店, img贪吃, img2048, img井字棋, img见缝插针,img五子棋背景,img风景,img文件管理器,img毛选,img成就,img成就2
        ,img白银,img黄金,img铂金,img钻石,img星耀,img王者,img荣耀,img传奇,img超越极限,img最强王者,img成功,img谦,img泰,img坚韧不拔;

    // 显示 PNG 格式的图片
    // loadimage 函数加载图片到 img 对象 
    // // 使用 putimage 函数将图片绘制到窗口上
    // 第一和第二个参数指定图片在窗口中显示的位置
    settextstyle(100, 0, _T("宋体"));
    mciSendString(L"open \"音乐\\output.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString(L"play mp3", NULL, 0, NULL);
    loadimage(&img太极, _T("图片\\太极.png"));
    loadimage(&img经典, _T("图片\\经典.jpg"));
    loadimage(&img2048, _T("图片\\2048.jpg"));
    loadimage(&img应用商店, _T("图片\\应用商店.jpg"));
    loadimage(&img贪吃, _T("图片\\贪吃.jpg"));
    loadimage(&img浏览器, _T("图片\\浏览器.png"));
    loadimage(&img五子棋, _T("图片\\五子棋.jpg"));
    loadimage(&img井字棋, _T("图片\\井字棋.jpg"));
    loadimage(&img毛选, _T("图片\\毛选.jpg"));
    loadimage(&img文件管理器, _T("图片\\文件管理器.png"));
    loadimage(&img见缝插针, _T("图片\\见缝插针.jpg"));
    loadimage(&img成就, _T("图片\\成就.png"));
    loadimage(&img成就2, _T("图片\\成就2.png"));
    loadimage(&img成功, _T("图片\\成功.png"));
    loadimage(&img坚韧不拔, _T("图片\\坚韧不拔.png"));
    loadimage(&img超越极限, _T("图片\\超越极限.png"));
    loadimage(&img最强王者, _T("图片\\最强王者.png"));
    loadimage(&img泰, _T("图片\\泰.png"));
    loadimage(&img谦, _T("图片\\谦.png"));
    loadimage(&img白银, _T("图片\\白银.png"));
    loadimage(&img黄金, _T("图片\\黄金.png"));
    loadimage(&img铂金, _T("图片\\铂金.png"));
    loadimage(&img钻石, _T("图片\\钻石.png"));
    loadimage(&img星耀, _T("图片\\星耀.png"));
    loadimage(&img王者, _T("图片\\王者.png"));
    loadimage(&img荣耀, _T("图片\\荣耀.png"));
    loadimage(&img传奇, _T("图片\\传奇.png"));
    putimage(40, 10, &img太极);
    putimage(40, 200, &img浏览器);
    putimage(40, 400, &img应用商店);
    putimage(40, 600, &img贪吃);
    putimage(40, 800, &img见缝插针);
    putimage(240, 10, &img2048);
    putimage(440, 10, &img五子棋);
    putimage(640, 10, &img井字棋);
    putimage(840, 10, &img文件管理器);
    putimage(240, 200, &img毛选);
    putimage(440, 400, &img成就);







    while (1) {
        if (MouseHit()) {
            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
            if (m.uMsg == WM_LBUTTONDOWN) { // 判断是否为左键点击事件
                if (m.x >= 40 && m.x <= 190 && m.y >= 400 && m.y <= 550)
                {
                    HINSTANCE result = ShellExecute(NULL, L"open", L"ms-windows-store:", NULL, NULL, SW_SHOWNORMAL);
                }
                if (m.x >= 40 && m.x <= 190 && m.y >= 200 && m.y <= 350) {
                    system("start microsoft-edge:");
                }
                if (m.x >= 840 && m.x <= 990 && m.y >= 10 && m.y <= 160) {
                    system("explorer");
                }
                if (m.x >= 240 && m.x <= 390 && m.y >= 200 && m.y <= 350) {
                    const char* pdfFilePath = "毛选.pdf";

                    // 构建打开PDF文件的命令字符串
                    char command[256];
                    sprintf_s(command, sizeof(command), "start \"\" \"%s\"", pdfFilePath);


                    // 使用system函数调用命令打开PDF文件
                    system(command);
                }
                if (m.x >= 440 && m.x <= 590 && m.y >= 400 && m.y <= 550) {
                    putimage(0, 0, &img成就2); settextcolor(WHITE);
                    for (int i = 1; i <= 10; i++)
                    {
                        std::string dir_path = ".\\成就\\";

                        std::string file_path = dir_path + std::to_string(i) + ".txt";
                        std::ifstream inFile(file_path);


                        // 读取文件内容
                        std::string fileContent;
                        inFile >> fileContent;  // 假设文件内容很短，一次性读入
                        inFile.close();  // 关闭文件

                        // 检查文件内容
                        if (fileContent == "1") {
                            if (i == 1) { putimage(140, 40, &img谦); }
                            if (i == 2) { putimage(140, 540, &img泰); }
                          if(i==3)  { putimage(640, 40, &img坚韧不拔);
                        }
                         if(i==4)   { putimage(640, 540, &img最强王者); }
                         if (i == 5) { putimage(1140, 40, &img成功); }
                         if (i == 6) { putimage(1140, 540, &img超越极限); }

                        }
                    }
                  
                    settextstyle(30, 0, _T("宋体"));
                    outtextxy(1600, 0, L"关闭");
                    while (1)
                    {
                        if (MouseHit()) {
                            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                            if (m.uMsg == WM_LBUTTONDOWN) {
                                if (m.x >= 1600 && m.x <= 1660 && m.y >= 00 && m.y <= 30) {
                                    cleardevice();
                                    setfillcolor(WHITE); // 设置绘图颜色为白色
                                    settextcolor(WHITE); // 设置字体颜色
                                    HDC hdc = GetImageHDC();
                                    Graphics g(hdc);
                                    g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
                                    putimage(40, 10, &img太极);
                                    putimage(40, 200, &img浏览器);
                                    putimage(40, 400, &img应用商店);
                                    putimage(40, 600, &img贪吃);
                                    putimage(40, 800, &img见缝插针);
                                    putimage(240, 10, &img2048);
                                    putimage(440, 10, &img五子棋);
                                    putimage(640, 10, &img井字棋);
                                    putimage(840, 10, &img文件管理器);
                                    putimage(240, 200, &img毛选);
                                    putimage(440, 400, &img成就);
                                    break;
                                }
                            }

                        }

                    }

                }
            



                if (m.x >= 40 && m.x <= 190 && m.y >= 800 && m.y <= 950) {
                    bool Key = false;
                    double s[36], c[36], jiaodu = 0, JiaoDu[36] = { 0 }, suiji, SuiJi[36];
                    int n , t = 9, v=0, ci = 10,chengjiu=0;
                    const double PI = acos(-1.0);
                    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

                    // 使用当前时间种子初始化随机数生成器
                    std::default_random_engine generator(seed);
                    std::uniform_int_distribution<int> distribution(0, 180);
                    IMAGE img地球;
                   
                    setbkcolor(BLACK);
                    cleardevice();
                    setlinecolor(WHITE);
                    setfillcolor(WHITE);
                    settextstyle(100, 0, _T("宋体"));
                    outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"开始游戏");

                    double kaiguan = 1, kai = 0;;

                    loadimage(&img地球, _T("图片\\地球.jpg"));
                    putimage(620, 320, &img地球);

                    while (1)
                    {
                        if (MouseHit()) {
                            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                            if (m.uMsg == WM_LBUTTONDOWN) {
                                if (m.x >= 1300 && m.x <= 1450 && m.y >= 00 && m.y <= 100) {
                                    cleardevice();
                                    setfillcolor(WHITE); // 设置绘图颜色为白色
                                    settextcolor(WHITE); // 设置字体颜色
                                    HDC hdc = GetImageHDC();
                                    Graphics g(hdc);
                                    g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
                                    putimage(40, 10, &img太极);
                                    putimage(40, 200, &img浏览器);
                                    putimage(40, 400, &img应用商店);
                                    putimage(40, 600, &img贪吃);
                                    putimage(40, 800, &img见缝插针);
                                    putimage(240, 10, &img2048);
                                    putimage(440, 10, &img五子棋);
                                    putimage(640, 10, &img井字棋);
                                    putimage(840, 10, &img文件管理器);
                                    putimage(240, 200, &img毛选); 
                                    putimage(440, 400, &img成就);
                                    break; }

                                if (m.x >= 1300 && m.x <= 1600 && m.y >= 100 && m.y <= 200)
                                {
                                    n = t; ci = 10; kaiguan = 1; jiaodu = 0; for (int m = 0; m < 36; m++) {
                                        c[m] = 0; s[m] = 0;
                                        JiaoDu[m] = 0;
                                    } for (int i = 0; i < t; i++)
                                    {

                                        if (i == 0) {
                                            suiji = distribution(generator);
                                            SuiJi[i] = suiji;
                                            s[i] = sin(jiaodu * PI / 180 + suiji * PI / 90);
                                            c[i] = cos(jiaodu * PI / 180 + suiji * PI / 90);
                                            line(700 + 250 * c[i], 400 + 250 * s[i], 700, 400);
                                            solidcircle(700 + 250 * c[i], 400 + 250 * s[i], 250 * sin(PI / 36));
                                        }
                                        else {
                                            while (true) {
                                                kai = 0;
                                                suiji = distribution(generator);
                                                for (int j = 0; j < i; j++) {
                                                    double newY = 400 + 250 * sin(jiaodu * PI / 180 + suiji * PI / 90); // 储存新点的Y坐标
                                                    double newX = 700 + 250 * cos(jiaodu * PI / 180 + suiji * PI / 90); // 储存新点的X坐标

                                                    double oldY = 400 + 250 * s[j]; // 旧点的Y坐标
                                                    double oldX = 700 + 250 * c[j]; // 旧点的X坐标

                                                    double jianju = (newY - oldY) * (newY - oldY) + (newX - oldX) * (newX - oldX); // 计算两点间距离的平方

                                                    double zhijing = 500 * sin(PI / 36) * 500 * sin(PI / 36); // 定义直径的平方
                                                    if (jianju > zhijing)
                                                    {
                                                        kai++;
                                                    }

                                                }if (kai == i) {
                                                    SuiJi[i] = suiji;
                                                    s[i] = sin(jiaodu * PI / 180 + suiji * PI / 90);
                                                    c[i] = cos(jiaodu * PI / 180 + suiji * PI / 90);
                                                    line(700 + 250 * c[i], 400 + 250 * s[i], 700, 400);
                                                    solidcircle(700 + 250 * c[i], 400 + 250 * s[i], 250 * sin(PI / 36)); break;
                                                }
                                            }
                                        }
                                    }

                                    while (!_kbhit()) { // 按任意键退出循环

                                        cleardevice();
                                        for (int i = 0; i < t; i++)
                                        {
                                            c[i] = cos(SuiJi[i] * PI / 90 + jiaodu * PI / 180);
                                            s[i] = sin(SuiJi[i] * PI / 90 + jiaodu * PI / 180);
                                            line(700 + 250 * c[i], 400 + 250 * s[i], 700, 400);
                                            solidcircle(700 + 250 * c[i], 400 + 250 * s[i], 250 * sin(PI / 36));
                                        } if (GetAsyncKeyState(' ') & 0x8000)
                                        {
                                            Key = true;
                                        }
                                        else if (Key) {
                                            Key = false;
                                            for (int i = 0; i < n; i++)
                                            {
                                                if (c[i] > cos(PI / 18)) {
                                                    kaiguan = 0; break;
                                                }
                                            }
                                            n++; ci--;
                                        }
                                        for (int i = t; i < n; i++) {
                                            c[i] = cos(JiaoDu[i] * PI / 180);
                                            s[i] = sin(JiaoDu[i] * PI / 180);
                                            line(700 + 250 * c[i], 400 + 250 * s[i], 700, 400);
                                            solidcircle(700 + 250 * c[i], 400 + 250 * s[i], 250 * sin(PI / 36));
                                            JiaoDu[i] = JiaoDu[i] + 2;

                                        }
                                        for (int i = 0; i < ci; i++)
                                        {
                                            solidcircle(1050 + i * 50, 400, 250 * sin(PI / 36));
                                        }outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"重新游戏");
                                        std::wstring str = std::to_wstring(t - 8+v);
                                        outtextxy(1300, 200, L"第 关");
                                        outtextxy(1400, 200, str.c_str());
                                        if (t == 10) { putimage(10,10, &img白银); }
                                        if (t == 11) { putimage(10, 10, &img黄金); }
                                       if(t==12) {putimage(10, 10, &img铂金);}
                                       if(t==13) {putimage(10, 10, &img钻石);}
                                       if(t==14) {putimage(10, 10, &img星耀);}
                                       if(t==15) {putimage(10, 10, &img王者);}
                                       if(v==1) {putimage(10, 10, &img荣耀);}
                                       if(v>=2) {putimage(10, 10, &img传奇);}
                                        putimage(620, 320, &img地球);
                                        jiaodu += 2;
                                        Sleep(210 - t * 10-v*15);
                                        if (kaiguan == 0) { MessageBox(GetHWnd(), _T("游戏结束"), _T("Game Over"), MB_OK); chengjiu++;
                                        if (chengjiu == 8) { MessageBox(GetHWnd(), _T("获得成就坚韧不拔"), _T("恭喜你"), MB_OK);
                                        std::string dir_path = ".\\成就\\";
                                        std::string file_path = dir_path + std::to_string(3) + ".txt";
                                        // 用于存储文件内容
                                        std::stringstream buffer;
                                        {
                                            // 创建输入文件流对象
                                            std::ifstream inFile(file_path);
                                            // 将文件内容读取到字符串流（buffer）中
                                            buffer << inFile.rdbuf();
                                            // 关闭输入文件流
                                            inFile.close();
                                        }
                                        // 修改buffer中的内容
                                        std::string content = buffer.str();
                                        std::string oldString = "0";
                                        std::string newString = "1";
                                        // 在content中查找并替换所有旧字符串
                                        size_t pos = content.find(oldString);
                                        while (pos != std::string::npos) {
                                            content.replace(pos, oldString.length(), newString);
                                            pos = content.find(oldString, pos + newString.length());
                                        }
                                        {
                                            // 创建输出文件流对象
                                            std::ofstream outFile(file_path);
                                            // 将修改后的内容写入文件
                                            outFile << content;
                                            // 关闭输出文件流
                                            outFile.close();

                                        }
                                        
                                        }
                                        break; }
                                        if (ci == 0) {
                                            if (t == 15) { v++; }
                                            if (t < 15) { t++; }                                          
                                            chengjiu = 0;
                                            outtextxy(1300, 100, L"下一关  ");
                                            MessageBox(GetHWnd(), _T("恭喜你升段了"), _T("游戏胜利"), MB_OK);
                                            if (v == 2) {
                                                MessageBox(GetHWnd(), _T("获得成就传奇王者"), _T("恭喜你"), MB_OK);
                                                std::string dir_path = ".\\成就\\";
                                                std::string file_path = dir_path + std::to_string(4) + ".txt";
                                                // 用于存储文件内容
                                                std::stringstream buffer;
                                                {
                                                    // 创建输入文件流对象
                                                    std::ifstream inFile(file_path);
                                                    // 将文件内容读取到字符串流（buffer）中
                                                    buffer << inFile.rdbuf();
                                                    // 关闭输入文件流
                                                    inFile.close();
                                                }
                                                // 修改buffer中的内容
                                                std::string content = buffer.str();
                                                std::string oldString = "0";
                                                std::string newString = "1";
                                                // 在content中查找并替换所有旧字符串
                                                size_t pos = content.find(oldString);
                                                while (pos != std::string::npos) {
                                                    content.replace(pos, oldString.length(), newString);
                                                    pos = content.find(oldString, pos + newString.length());
                                                }
                                                {
                                                    // 创建输出文件流对象
                                                    std::ofstream outFile(file_path);
                                                    // 将修改后的内容写入文件
                                                    outFile << content;
                                                    // 关闭输出文件流
                                                    outFile.close();

                                                }
                                            }
                                            break;
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }

                }
                if (m.x >=640  && m.x <= 790 && m.y >= 10 && m.y <= 160) {
                    settextcolor(BLACK); settextstyle(100, 0, _T("宋体"));
                    int kai=1;
                    int board[3][3] = { 0 }; // 0代表空格，1代表玩家1（O），2代表玩家2（X）
                    int currentPlayer = 1; // 当前玩家，游戏开始默认为玩家1


                    setbkcolor(WHITE); // 设置背景颜色


                    cleardevice(); // 应用背景颜色并清除之前的绘制
                    loadimage(&img风景, _T("图片\\风景.png")); putimage(0, 0, &img风景);
                    outtextxy(900, 0, L"退出"); outtextxy(900, 100, L"开始游戏");
                    // DrawBoard 函数内容
                    setlinecolor(BLACK);
                    for (int i = 0; i <= 3; i++) {
                        line(i * 100+600, 300, i * 100+600, 600);
                        line(600, i * 100+300, 900, i * 100+300);
                    }while (1) {
                       
                        MOUSEMSG m;
                        m = GetMouseMsg();
                        if (m.uMsg == WM_LBUTTONDOWN) {
                            if (m.x >= 900 && m.x <= 1200 && m.y >= 100 && m.y <= 200)
                            {
                                kai = 0;
                                for (int row = 0; row < 3; row++) {
                                    for (int col = 0; col < 3; col++) {
                                        board[row][col] = 0;
                                    }
                                }
                                cleardevice(); putimage(0, 0, &img风景);
                                outtextxy(900, 0, L"退出"); outtextxy(900, 100, L"重新游戏");

                                // DrawBoard 函数内容
                                setlinecolor(BLACK);
                                for (int i = 0; i <= 3; i++) {
                                    line(i * 100 + 600, 300, i * 100 + 600, 600);
                                    line(600, i * 100 + 300, 900, i * 100 + 300);
                                }
                            }
                            if (m.x >= 900 && m.x <= 1050 && m.y >= 000 && m.y <= 100)
                            {
                                setbkcolor(BLACK);
                                cleardevice();
                                setfillcolor(WHITE); // 设置绘图颜色为白色
                                settextcolor(WHITE); // 设置字体颜色
                                HDC hdc = GetImageHDC();
                                Graphics g(hdc);
                                g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
                                putimage(40, 10, &img太极);
                                putimage(40, 200, &img浏览器);
                                putimage(40, 400, &img应用商店);
                                putimage(40, 600, &img贪吃);
                                putimage(40, 800, &img见缝插针);
                                putimage(240, 10, &img2048);
                                putimage(440, 10, &img五子棋);
                                putimage(640, 10, &img井字棋);
                                putimage(840, 10, &img文件管理器);
                                putimage(240, 200, &img毛选);
                                putimage(440, 400, &img成就);

                                break;
                            }


                            if (kai == 0) {
                                if (m.x >= 600 && m.x <= 900 && m.y >= 300 && m.y <= 600) {

                                    int row = (m.y - 300) / 100;
                                    int col = (m.x - 600) / 100;
                                    if (board[row][col] == 0) { // 如果点击的格子为空
                                        board[row][col] = currentPlayer;  // 在数组中记录玩家的标志
                                        if (currentPlayer == 1) {
                                            setlinecolor(BLACK);
                                            circle(col * 100 + 100 / 2 + 600, row * 100 + 100 / 2 + 300, 100 / 3);

                                        }
                                        else if (currentPlayer == 2) {
                                            setlinecolor(RED);
                                            line(col * 100 + 600, row * 100 + 300, (col + 1) * 100 + 600, (row + 1) * 100 + 300);
                                            line((col + 1) * 100 + 600, row * 100 + 300, col * 100 + 600, (row + 1) * 100 + 300);
                                        }
                                    }

                                }

                                bool winner = false;
                                for (int i = 0; i < 3; ++i) {
                                    if (board[i][0] == currentPlayer &&
                                        board[i][1] == currentPlayer &&
                                        board[i][2] == currentPlayer) winner = true;
                                }

                                // 检查每一列
                                for (int i = 0; i < 3; ++i) {
                                    if (board[0][i] == currentPlayer &&
                                        board[1][i] == currentPlayer &&
                                        board[2][i] == currentPlayer) winner = true;
                                }

                                // 检查对角线
                                if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
                                    (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
                                    winner = true;
                                }




                                bool full = true;
                                for (int row = 0; row < 3; row++) {
                                    for (int col = 0; col < 3; col++) {
                                        if (board[row][col] == 0) {
                                            full = false; // 如果找到一个格子还没被填充，返回假
                                        }
                                    }
                                }
                                if (winner) {
                                    kai = 1;
                                    MessageBox(GetHWnd(), (currentPlayer == 1 ? TEXT("玩家1胜利!") : TEXT("玩家2胜利!")), TEXT("游戏结束"), MB_OK);

                                }
                                // 检查是否获胜


                                // 检查平局
                                if (full) {
                                    kai = 1;
                                    MessageBox(GetHWnd(), TEXT("平局！"), TEXT("游戏结束"), MB_OK);

                                }


                                currentPlayer = currentPlayer % 2 + 1;

                            }
                        }
                    }

                        
                    
                
                }

                if (m.x >= 40 && m.x <= 190 && m.y >= 600 && m.y <= 750) {
                    settextstyle(100, 0, _T("宋体")); setbkcolor(BLACK);
                    cleardevice(); 
                    loadimage(&img贪吃蛇, _T("图片\\贪吃蛇.jpg")); putimage(00, 00, &img贪吃蛇);
                    
                    setlinecolor(RED);
                    line(800, 0, 800, 800); line(0, 800, 800, 800);
                    outtextxy(900, 0, L"退出"); outtextxy(900, 100, L"开始游戏");
                    while (1) {
                       
                        if (MouseHit()) {
                            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                            if (m.uMsg == WM_LBUTTONDOWN) { // 判断是否为左键点击事件
                                if (m.x >= 900 && m.x <= 1200 && m.y >= 100 && m.y <= 200) {
                                    const int window_width = 800;
                                    const int window_height = 800;
                                    const int block_size = 20;
                                    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
                                    std::default_random_engine generator(seed);
                                    std::uniform_int_distribution<int> distribution(0, 39);

                                    // 定义方向枚举
                                    enum Direction { UP, DOWN, LEFT, RIGHT };

                                    // 蛇的节点结构
                                    struct SnakeNode { int x, y; };

                                    // 蛇和食物的全局变量
                                    std::list<SnakeNode> snake;
                                    SnakeNode food;
                                    Direction dir = RIGHT; // 初始方向向右

                                    // Lambda函数定义来代替原始的函数定义
                                    auto init_game = [&]() {

                                        snake.push_back({ window_width / 2, window_height / 2 });
                                        snake.push_back({ window_width / 2 - block_size, window_height / 2 });
                                        food = { distribution(generator) * block_size, distribution(generator) * block_size };
                                        };

                                    auto draw = [&]() {
                                        cleardevice(); 
                                        loadimage(&img贪吃蛇, _T("图片\\贪吃蛇.jpg")); putimage(00, 00, &img贪吃蛇);
                                        setfillcolor(RED);
                                        solidrectangle(food.x, food.y, food.x + block_size - 1, food.y + block_size - 1);
                                        setfillcolor(GREEN);
                                        for (const auto& node : snake) {
                                            solidrectangle(node.x, node.y, node.x + block_size - 1, node.y + block_size - 1);
                                        } setlinecolor(RED);
                                        line(800, 0, 800, 800); line(0, 800, 800, 800);
                                        outtextxy(900, 0, L"退出"); outtextxy(900, 100, L"重新开始");
                                        FlushBatchDraw();
                                        };

                                    auto update = [&]() -> bool {
                                        if (GetAsyncKeyState('W') & 0x8000) { // 判断 W 键是否被按下
                                            if (dir != DOWN) dir = UP;
                                        }
                                        else if (GetAsyncKeyState('S') & 0x8000) { // 判断 S 键是否被按下
                                            if (dir != UP) dir = DOWN;
                                        }
                                        else if (GetAsyncKeyState('A') & 0x8000) { // 判断 A 键是否被按下
                                            if (dir != RIGHT) dir = LEFT;
                                        }
                                        else if (GetAsyncKeyState('D') & 0x8000) { // 判断 D 键是否被按下
                                            if (dir != LEFT) dir = RIGHT;
                                        }

                                        // 移动蛇头
                                        SnakeNode& head = snake.front();
                                        int newX = head.x, newY = head.y;
                                        switch (dir) {
                                        case UP:    newY -= block_size; break;
                                        case DOWN:  newY += block_size; break;
                                        case LEFT:  newX -= block_size; break;
                                        case RIGHT: newX += block_size; break;
                                        }


                                        // 检查是否吃到食物
                                        if (newX == food.x && newY == food.y) {
                                            // 添加新节点到蛇头，不移动蛇尾
                                            snake.push_front({ newX, newY });
                                            food = { distribution(generator) * 20  ,distribution(generator) * 20 };
                                            // 重设食物位置

                                        }
                                        else {
                                            // 移动蛇尾到新蛇头的位置
                                            snake.pop_back();
                                            snake.push_front({ newX, newY });
                                        }

                                        // 检查游戏结束条件，例如蛇头触碰边界
                                        if (newX < 0 || newY < 0 || newX >= window_width || newY >= window_height) {
                                            return false; // 游戏结束
                                        }

                                        // 检查蛇头是否碰到自己
                                        for (auto itr = ++snake.begin(); itr != snake.end(); ++itr) {
                                            if (itr->x == newX && itr->y == newY) {
                                                return false; // 游戏结束
                                            }
                                        }

                                        return true; // 游戏继续

                                        };

                                    // 使用Lambda函数
                                    init_game();

                                    while (update()) {
                                        draw();
                                        Sleep(100);
                                    }                               
                                    MessageBox(GetHWnd(), _T("游戏结束"), _T("Game Over"), MB_OK);
                                   
                                } if (m.x >= 900 && m.x <= 1050 && m.y >= 00 && m.y <= 100) { break; }
                            }
                        } 
                                
                            
                       
                    } setbkcolor(BLACK);
                    cleardevice();
                    setfillcolor(WHITE); // 设置绘图颜色为白色
                    settextcolor(WHITE); // 设置字体颜色
                    HDC hdc = GetImageHDC();
                    Graphics g(hdc);
                    g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
                    putimage(40, 10, &img太极);
                    putimage(40, 200, &img浏览器);
                    putimage(40, 400, &img应用商店);
                    putimage(40, 600, &img贪吃);
                    putimage(40, 800, &img见缝插针);
                    putimage(240, 10, &img2048);
                    putimage(440, 10, &img五子棋);
                    putimage(640, 10, &img井字棋);
                    putimage(840, 10, &img文件管理器);
                    putimage(240, 200, &img毛选);
                    putimage(440, 400, &img成就);

                }

                
                if (m.x >= 440 && m.x <= 590 && m.y >= 10 && m.y <= 160) {
                    setbkcolor(WHITE); settextstyle(100, 0, _T("宋体"));
                    cleardevice(); loadimage(&img五子棋背景, _T("图片\\五子棋背景.png")); putimage(00, 00, &img五子棋背景);
                    settextcolor(BLACK);
                    setfillcolor(RGB(205, 133, 63)); fillrectangle(0, 0, 1000, 1000); // 定义棋盘大小
                    outtextxy(1100, 0, L"退出"); outtextxy(1100, 100, L"开始下棋"); 
                    setlinecolor(BLACK);
                    for (int i = 0; i <= 25; ++i) {
                        line(i * 40, 0, i * 40, 1000);
                        line(0, i * 40, 1000, i * 40);
                    }
                    while (1) {
                        int guan = 0, kai = 1;

                        if (MouseHit()) {
                            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                            if (m.uMsg == WM_LBUTTONDOWN) { // 判断是否为左键点击事件
                                if (m.x >= 1100 && m.x <= 1400 && m.y >= 100 && m.y <= 200) {settextstyle(100, 0, _T("宋体"));
                                     cleardevice(); loadimage(&img五子棋背景, _T("图片\\五子棋背景.png")); putimage(00, 00, &img五子棋背景);
                                    setfillcolor(RGB(205, 133, 63)); fillrectangle(0, 0, 1000, 1000); // 定义棋盘大小
                                    outtextxy(1100, 0, L"退出"); outtextxy(1100, 100, L"重新下棋");
                                    setlinecolor(BLACK);
                                    for (int i = 0; i <= 25; ++i) {
                                        line(i * 40, 0, i * 40, 1000);
                                        line(0, i * 40, 1000, i * 40);
                                    }
                                    const int N = 25;
                                    const int CELL_SIZE = 40; // 棋盘每格的大小
                                    const int BOARD_SIZE = CELL_SIZE * N; // 棋盘尺寸
                                    const int STROKE_WIDTH = 2; // 线条宽度

                                    int board[N][N] = { 0 }; // 0 表示未下棋，1 表示黑棋，2 表示白棋
                                    int currentPlayer = 1;  // 当前玩家，1 为黑棋，2 为白棋

                                    auto drawBoard = [&]() {
                                        setlinecolor(BLACK);
                                        setlinestyle(PS_SOLID, STROKE_WIDTH);
                                        for (int i = 0; i <= N; ++i) {
                                            line(i * CELL_SIZE, 0, i * CELL_SIZE, BOARD_SIZE);
                                            line(0, i * CELL_SIZE, BOARD_SIZE, i * CELL_SIZE);
                                        }
                                        };

                                    auto drawPiece = [&](int x, int y, int color) {
                                        if (color == 1) setfillcolor(BLACK);
                                        else setfillcolor(WHITE);
                                        solidcircle(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2, CELL_SIZE / 2 - 5);
                                        };

                                    auto checkWin = [&](int x, int y) -> bool {
                                        // 横向检查
                                        for (int i = x - 4; i <= x; ++i) {
                                            if (i >= 0 && i + 4 < N &&
                                                board[y][i] == currentPlayer &&
                                                board[y][i + 1] == currentPlayer &&
                                                board[y][i + 2] == currentPlayer &&
                                                board[y][i + 3] == currentPlayer &&
                                                board[y][i + 4] == currentPlayer) {
                                                return true;
                                            }
                                        }

                                        // 纵向检查
                                        for (int i = y - 4; i <= y; ++i) {
                                            if (i >= 0 && i + 4 < N &&
                                                board[i][x] == currentPlayer &&
                                                board[i + 1][x] == currentPlayer &&
                                                board[i + 2][x] == currentPlayer &&
                                                board[i + 3][x] == currentPlayer &&
                                                board[i + 4][x] == currentPlayer) {
                                                return true;
                                            }
                                        }

                                        // 对角线检查（左上到右下）
                                        for (int i = -4; i <= 0; ++i) {
                                            if (x + i >= 0 && y + i >= 0 && x + i + 4 < N && y + i + 4 < N &&
                                                board[y + i][x + i] == currentPlayer &&
                                                board[y + i + 1][x + i + 1] == currentPlayer &&
                                                board[y + i + 2][x + i + 2] == currentPlayer &&
                                                board[y + i + 3][x + i + 3] == currentPlayer &&
                                                board[y + i + 4][x + i + 4] == currentPlayer) {
                                                return true;
                                            }
                                        }

                                        // 对角线检查（右上到左下）
                                        for (int i = -4; i <= 0; ++i) {
                                            if (x + i >= 0 && y - i - 4 >= 0 && x + i + 4 < N && y - i < N &&
                                                board[y - i][x + i] == currentPlayer &&
                                                board[y - i - 1][x + i + 1] == currentPlayer &&
                                                board[y - i - 2][x + i + 2] == currentPlayer &&
                                                board[y - i - 3][x + i + 3] == currentPlayer &&
                                                board[y - i - 4][x + i + 4] == currentPlayer) {
                                                return true;
                                            }
                                        }

                                        return false; // 如果上述检查都没有返回 true，则继续游戏
                                        };



                                    drawBoard(); // 绘制棋盘
                                  

                                    while (true) {
                                        if (MouseHit()) {
                                            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                                            if (m.uMsg == WM_LBUTTONDOWN) {
                                                if (m.x >= 0 && m.x <= 1000 && m.y >= 00 && m.y <= 1000) {
                                                    int x = m.x / CELL_SIZE; // 计算落子的列
                                                    int y = m.y / CELL_SIZE; // 计算落子的行
                                                    if (board[y][x] == 0) { // 判断该位置是否已有棋子
                                                        board[y][x] = currentPlayer; // 在棋盘数组中记录棋子
                                                        drawPiece(x, y, currentPlayer); // 绘制棋子
                                                        if (checkWin(x, y)) { // 检查是否赢了
                                                            if (currentPlayer == 1) { MessageBox(GetHWnd(), _T("黑棋获胜"), _T("Game Over"), MB_OK); }
                                                            if (currentPlayer == 2) { MessageBox(GetHWnd(), _T("白棋获胜"), _T("Game Over"), MB_OK); }
                                                            break; // 结束游戏循环
                                                        }
                                                        currentPlayer = 3 - currentPlayer; // 切换玩家
                                                    }
                                                }if (m.x >= 1100 && m.x <= 1250 && m.y >= 00 && m.y <= 100) { guan = 1; break; }
                                                if (m.x >= 1100 && m.x <= 1400 && m.y >= 100 && m.y <= 200) {
                                                    for (int i = 0; i < 25; i++) {
                                                        for (int j = 0; j < 25; j++)
                                                            board[i][j] = 0;
                                                    }  cleardevice(); loadimage(&img五子棋背景, _T("图片\\五子棋背景.png")); putimage(00, 00, &img五子棋背景);
                                                    setfillcolor(RGB(205, 133, 63)); fillrectangle(0, 0, 1000, 1000); // 定义棋盘大小
                                                    outtextxy(1100, 0, L"退出"); outtextxy(1100, 100, L"重新下棋");
                                                    setlinecolor(BLACK);
                                                    for (int i = 0; i <= 25; ++i) {
                                                        line(i * 40, 0, i * 40, 1000);
                                                        line(0, i * 40, 1000, i * 40);
                                                    }
                                                }
                                                }
                                            }
                                        }
                                    }
                                if (m.x >= 1100 && m.x <= 1250 && m.y >= 00 && m.y <= 100) { break; }
                                if (guan == 1) { break; }
                            }
                        }
                    }setbkcolor(BLACK);
                    cleardevice();
                    setfillcolor(WHITE); // 设置绘图颜色为白色
                    settextcolor(WHITE); // 设置字体颜色
                    HDC hdc = GetImageHDC();
                    Graphics g(hdc);
                    g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
                    putimage(40, 10, &img太极);
                    putimage(40, 200, &img浏览器);
                    putimage(40, 400, &img应用商店);
                    putimage(40, 600, &img贪吃);
                    putimage(40, 800, &img见缝插针);
                    putimage(240, 10, &img2048);
                    putimage(440, 10, &img五子棋);
                    putimage(640, 10, &img井字棋);
                    putimage(840, 10, &img文件管理器);
                    putimage(240, 200, &img毛选);
                    putimage(440, 400, &img成就);

                        
                    
                }


                if (m.x >= 240 && m.x <= 390 && m.y >= 10 && m.y <= 160) {
                    bool wKey = false, sKey = false, dKey = false, aKey = false;
                    int YuWu[16] = { 0 }, Shu[16] = { 0 }, suiji, gu[16], dong = 0,chengjiu=0;
                    
                    setbkcolor(RGB(205, 133, 63)); // 设置背景颜色
                    cleardevice();     // 应用背景颜色并清除屏幕
                    setfillcolor(WHITE); // 设置绘图颜色为白色
                    settextcolor(BLACK); // 设置字体颜色

                    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

                    // 使用当前时间种子初始化随机数生成器
                    std::default_random_engine generator(seed);
                    std::uniform_int_distribution<int> distribution(0, 15);

                    for (int i = 0; i <= 4; i++)
                    {

                        setlinecolor(BLACK);
                        line(400, 50 + 200 * i, 1200, 50 + 200 * i);
                        line(400 + 200 * i, 50, 400 + 200 * i, 850);
                    }
                    for (int i = 1; i <= 2; i++)
                    {
                        while (true) {
                            suiji = distribution(generator) % 16;
                            if (YuWu[suiji] == 0) {
                                Shu[suiji] = (2 + suiji % 2 * 2); YuWu[suiji] = 1; break;
                            }
                        }
                    }
                    for (int i = 0; i < 16; i++)
                    {
                        if (Shu[i] != 0) YuWu[i] = 1;

                        TCHAR shu[17];
                        char str[17];
                        if (Shu[i] != 0) {
                            sprintf_s(str, "%d", Shu[i]);
                            MultiByteToWideChar(CP_ACP, 0, str, -1, shu, 32);
                            settextstyle(100, 0, _T("宋体"));
                            outtextxy(470 + i % 4 * 200, 100 + i / 4 * 200, shu);
                        }
                    }outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"重新开始");


                    while (1)
                    {
                        if (MouseHit()) {
                            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                            if (m.uMsg == WM_LBUTTONDOWN) {
                                
                                    if (m.x >= 1300 && m.x <= 1600 && m.y >= 100 && m.y <= 200)
                                    {
                                        for (int i = 0; i < 16; i++) {
                                            YuWu[i] = 0; Shu[i] = 0; gu[i] = 0;
                                        } cleardevice();   for (int i = 0; i <= 4; i++)
                                        {

                                            setlinecolor(BLACK);
                                            line(400, 50 + 200 * i, 1200, 50 + 200 * i);
                                            line(400 + 200 * i, 50, 400 + 200 * i, 850);
                                        }
                                        for (int i = 1; i <= 2; i++)
                                        {
                                            while (true) {
                                                suiji = distribution(generator) % 16;
                                                if (YuWu[suiji] == 0) {
                                                    Shu[suiji] = (2 + suiji % 2 * 2); YuWu[suiji] = 1; break;
                                                }
                                            }
                                        }
                                        for (int i = 0; i < 16; i++)
                                        {
                                            if (Shu[i] != 0) YuWu[i] = 1;

                                            TCHAR shu[17];
                                            char str[17];
                                            if (Shu[i] != 0) {
                                                sprintf_s(str, "%d", Shu[i]);
                                                MultiByteToWideChar(CP_ACP, 0, str, -1, shu, 32);
                                                settextstyle(100, 0, _T("宋体"));
                                                outtextxy(470 + i % 4 * 200, 100 + i / 4 * 200, shu);
                                            }
                                        }outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"重新开始");

                                }
                                if (m.x >= 1300 && m.x <= 1450 && m.y >= 00 && m.y <= 100) {
                                    setbkcolor(BLACK); // 设置背景颜色
                                    cleardevice();     // 应用背景颜色并清除屏幕
                                    setfillcolor(WHITE); // 设置绘图颜色为白色
                                    settextcolor(WHITE); // 设置字体颜色
                                    HDC hdc = GetImageHDC();
                                    Graphics g(hdc);
                                    g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
                                    putimage(40, 10, &img太极);
                                    putimage(40, 200, &img浏览器);
                                    putimage(40, 400, &img应用商店);
                                    putimage(40, 600, &img贪吃);
                                    putimage(40, 800, &img见缝插针);
                                    putimage(240, 10, &img2048);
                                    putimage(440, 10, &img五子棋);
                                    putimage(640, 10, &img井字棋);
                                    putimage(840, 10, &img文件管理器);
                                    putimage(240, 200, &img毛选);
                                    putimage(440, 400, &img成就);

                                    break;
                                }
                            }
                        }
                    
                       


                        if (GetAsyncKeyState('S') & 0x8000)
                        {
                            sKey = true;
                        }
                        else if (sKey) {
                            sKey = false;
                            dong = 0;

                            cleardevice(); for (int i = 0; i < 4; i++) {
                                gu[i + 12] = 0; gu[8 + i] = 0;
                                for (int j = 2; j >= 0; j--) {

                                    if (YuWu[12 + i] == 0 && YuWu[4 * j + i] == 1) {
                                        Shu[12 + i] = Shu[4 * j + i]; YuWu[12 + i] = 1;
                                        Shu[4 * j + i] = 0; YuWu[4 * j + i] = 0; dong++;
                                    }  if (YuWu[12 + i] == 1 && YuWu[4 * j + i] == 1 && Shu[12 + i] == Shu[4 * j + i]) {
                                        if (j == 1 && YuWu[8 + i] == 1) { break; }
                                        if (j == 0 && YuWu[4 + i] == 1 || (j == 0 && YuWu[8 + i] == 1)) { break; }
                                        if (gu[12 + i] != 1) {
                                            dong++;
                                            Shu[12 + i] = 2 * Shu[12 + i]; Shu[4 * j + i] = 0; YuWu[4 * j + i] = 0; gu[12 + i] = 1;
                                        }
                                    }
                                }for (int j = 1; j >= 0; j--) {
                                    if (YuWu[8 + i] == 0 && YuWu[4 * j + i] == 1) {
                                        Shu[8 + i] = Shu[4 * j + i]; YuWu[8 + i] = 1;
                                        Shu[4 * j + i] = 0; YuWu[4 * j + i] = 0; dong++;
                                    }if (YuWu[8 + i] == 1 && YuWu[4 * j + i] == 1 && Shu[8 + i] == Shu[4 * j + i]) {
                                        if (j == 0 && YuWu[4 + i] != 0) { break; }
                                        if (gu[8 + i] != 1) {
                                            dong++;
                                            Shu[8 + i] = 2 * Shu[4 * j + i]; Shu[4 * j + i] = 0;  YuWu[4 * j + i] = 0; gu[8 + i] = 1;
                                        }
                                    }
                                }




                                if (YuWu[4 + i] == 0 && YuWu[0 + i] == 1) {
                                    Shu[4 + i] = Shu[0 + i]; YuWu[4 + i] = 1;
                                    Shu[0 + i] = 0; YuWu[0 + i] = 0; dong++;
                                }

                                if (YuWu[4 + i] == 1 && YuWu[0 + i] == 1 && Shu[4 + i] == Shu[0 + i]) {
                                    Shu[4 + i] = 2 * Shu[0 + i]; Shu[0 + i] = 0; YuWu[0 + i] = 0; dong++;
                                }
                            }

                            if (dong != 0) {
                                while (true) {
                                    suiji = distribution(generator) % 16;
                                    if (YuWu[suiji] == 0) {
                                        Shu[suiji] = (2 + suiji % 2 * 2); YuWu[suiji] = 1; break;
                                    }
                                }
                            }
                            for (int i = 0; i < 16; i++)
                            {

                                if (Shu[i] != 0) YuWu[i] = 1;


                                TCHAR shu[17];
                                char str[17];
                                if (Shu[i] != 0) {
                                    sprintf_s(str, "%d", Shu[i]);
                                    MultiByteToWideChar(CP_ACP, 0, str, -1, shu, 32);
                                    settextstyle(100, 0, _T("宋体"));
                                    if (Shu[i] > 64 && Shu[i] <= 512) { outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] < 128) { outtextxy(470 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] > 512) { settextstyle(80, 0, _T("宋体")); outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                }
                            }
                            for (int i = 0; i <= 4; i++)
                            {

                                setlinecolor(BLACK);
                                line(400, 50 + 200 * i, 1200, 50 + 200 * i);
                                line(400 + 200 * i, 50, 400 + 200 * i, 850);
                            }outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"重新开始");


                        }
                        else   if (GetAsyncKeyState('A') & 0x8000)
                        {
                            aKey = true;
                        }
                        else if (aKey) {
                            dong = 0; aKey = false;
                            cleardevice(); for (int i = 0; i <= 12; i = i + 4) {
                                gu[i] = 0; gu[i + 1] = 0;
                                for (int j = 1; j <= 3; j++) {
                                    if (YuWu[i] == 0 && YuWu[i + j] == 1) {
                                        Shu[i] = Shu[j + i]; YuWu[i] = 1;
                                        Shu[j + i] = 0; YuWu[j + i] = 0; dong++;
                                    }  if (YuWu[i] == 1 && YuWu[j + i] == 1 && Shu[i] == Shu[j + i]) {
                                        if (j == 2 && YuWu[i + 1] != 0) {
                                            break;
                                        }
                                        if (j == 3 && YuWu[i + 1] != 0 || (j == 3 && YuWu[i + 2] != 0)) { break; }
                                        if (gu[i] != 1) {
                                            Shu[i] = 2 * Shu[i]; Shu[j + i] = 0; YuWu[j + i] = 0; gu[i] = 1; dong++;
                                        }

                                    }
                                }for (int j = 2; j <= 3; j++) {
                                    if (YuWu[i + 1] == 0 && YuWu[j + i] == 1) {
                                        Shu[i + 1] = Shu[j + i]; YuWu[i + 1] = 1;
                                        Shu[j + i] = 0; YuWu[j + i] = 0; dong++;
                                    }if (YuWu[1 + i] == 1 && YuWu[j + i] == 1 && Shu[1 + i] == Shu[j + i]) {
                                        if (j == 3 && YuWu[i + 2] != 0) { break; }
                                        if (gu[i + 1] != 1) {
                                            dong++;
                                            Shu[1 + i] = 2 * Shu[j + i]; Shu[j + i] = 0;  YuWu[j + i] = 0; gu[i + 1] = 1;
                                        }
                                    }
                                }




                                if (YuWu[2 + i] == 0 && YuWu[3 + i] == 1) {
                                    Shu[2 + i] = Shu[3 + i]; YuWu[2 + i] = 1;
                                    Shu[3 + i] = 0; YuWu[3 + i] = 0; dong++;
                                }

                                if (YuWu[2 + i] == 1 && YuWu[3 + i] == 1 && Shu[2 + i] == Shu[3 + i]) {
                                    Shu[2 + i] = 2 * Shu[3 + i]; Shu[3 + i] = 0; YuWu[3 + i] = 0; dong++;
                                }
                            }
                            if (dong != 0) {
                                while (true) {
                                    suiji = distribution(generator) % 16;
                                    if (YuWu[suiji] == 0) {
                                        Shu[suiji] = (2 + suiji % 2 * 2); YuWu[suiji] = 1; break;
                                    }
                                }
                            }
                            for (int i = 0; i < 16; i++)
                            {

                                if (Shu[i] != 0) YuWu[i] = 1;

                                TCHAR shu[17];
                                char str[17];
                                if (Shu[i] != 0) {
                                    sprintf_s(str, "%d", Shu[i]);
                                    MultiByteToWideChar(CP_ACP, 0, str, -1, shu, 32);
                                    settextstyle(100, 0, _T("宋体"));
                                    if (Shu[i] > 64 && Shu[i] <= 512) { outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] < 128) { outtextxy(470 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] > 512) { settextstyle(80, 0, _T("宋体")); outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                }
                            }
                            for (int i = 0; i <= 4; i++)
                            {

                                setlinecolor(BLACK);
                                line(400, 50 + 200 * i, 1200, 50 + 200 * i);
                                line(400 + 200 * i, 50, 400 + 200 * i, 850);
                            }outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"重新开始");
                        }
                        else   if (GetAsyncKeyState('W') & 0x8000)
                        {
                            wKey = true;
                        }
                        else if (wKey) {
                            wKey = false;
                            dong = 0;



                            cleardevice(); for (int i = 0; i < 4; i++) {
                                gu[i] = 0; gu[i + 4] = 0;
                                for (int j = 0; j <= 2; j++) {
                                    if (YuWu[i] == 0 && YuWu[4 * j + i + 4] == 1) {
                                        Shu[i] = Shu[4 * j + i + 4]; YuWu[i] = 1;
                                        Shu[4 * j + 4 + i] = 0; YuWu[4 * j + 4 + i] = 0; dong++;
                                    }  if (YuWu[i] == 1 && YuWu[4 * j + 4 + i] == 1 && Shu[i] == Shu[4 * j + 4 + i]) {
                                        if (j == 1 && YuWu[4 + i] != 0) { break; }
                                        if (j == 2 && YuWu[8 + i] != 0 || (j == 2 && YuWu[4 + i] != 0)) { break; }
                                        if (gu[i] != 1) {
                                            Shu[i] = 2 * Shu[i]; Shu[4 * j + 4 + i] = 0; YuWu[4 * j + 4 + i] = 0; gu[i] = 1; dong++;
                                        }
                                    }
                                }for (int j = 0; j <= 1; j++) {
                                    if (YuWu[4 + i] == 0 && YuWu[4 * j + 8 + i] == 1) {
                                        Shu[4 + i] = Shu[4 * j + 8 + i]; YuWu[4 + i] = 1;
                                        Shu[4 * j + 8 + i] = 0; YuWu[4 * j + 8 + i] = 0; dong++;
                                    }if (YuWu[4 + i] == 1 && YuWu[4 * j + 8 + i] == 1 && Shu[4 + i] == Shu[4 * j + 8 + i]) {
                                        if (j == 1 && YuWu[8 + i] != 0) { break; }
                                        if (gu[i + 4] != 1) {
                                            Shu[4 + i] = 2 * Shu[4 * j + 8 + i];
                                            Shu[4 * j + 8 + i] = 0;  YuWu[4 * j + 8 + i] = 0; gu[4 + i] = 1; dong++;
                                        }
                                    }
                                }




                                if (YuWu[8 + i] == 0 && YuWu[12 + i] == 1) {
                                    Shu[8 + i] = Shu[12 + i]; YuWu[8 + i] = 1;
                                    Shu[12 + i] = 0; YuWu[12 + i] = 0; dong++;
                                }

                                if (YuWu[8 + i] == 1 && YuWu[12 + i] == 1 && Shu[8 + i] == Shu[12 + i]) {
                                    Shu[8 + i] = 2 * Shu[12 + i]; Shu[12 + i] = 0; YuWu[12 + i] = 0; dong++;
                                }
                            }
                            if (dong != 0) {
                                while (true) {
                                    suiji = distribution(generator) % 16;
                                    if (YuWu[suiji] == 0) {
                                        Shu[suiji] = (2 + suiji % 2 * 2); YuWu[suiji] = 1; break;
                                    }
                                }
                            }
                            for (int i = 0; i < 16; i++)
                            {

                                if (Shu[i] != 0) YuWu[i] = 1;


                                TCHAR shu[17];
                                char str[17];
                                if (Shu[i] != 0) {
                                    sprintf_s(str, "%d", Shu[i]);
                                    MultiByteToWideChar(CP_ACP, 0, str, -1, shu, 32);
                                    settextstyle(100, 0, _T("宋体"));
                                    if (Shu[i] > 64 && Shu[i] <= 512) { outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] < 128) { outtextxy(470 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] > 512) { settextstyle(80, 0, _T("宋体")); outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                }
                            }
                            for (int i = 0; i <= 4; i++)
                            {

                                setlinecolor(BLACK);
                                line(400, 50 + 200 * i, 1200, 50 + 200 * i);
                                line(400 + 200 * i, 50, 400 + 200 * i, 850);
                            }outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"重新开始");

                        }


                        else   if (GetAsyncKeyState('D') & 0x8000)
                        {
                            dKey = true;
                        }
                        else if (dKey) {
                            dKey = false;
                            dong = 0;
                            cleardevice(); for (int i = 0; i <= 12; i = i + 4) {
                                gu[i + 3] = 0; gu[i + 2] = 0;
                                for (int j = 1; j <= 3; j++) {
                                    if (YuWu[3 + i] == 0 && YuWu[i + 3 - j] == 1) {
                                        Shu[3 + i] = Shu[i + 3 - j]; YuWu[i + 3] = 1;
                                        Shu[i + 3 - j] = 0; YuWu[i + 3 - j] = 0; dong++;
                                    }  if (YuWu[i + 3] == 1 && YuWu[i + 3 - j] == 1 && Shu[i + 3] == Shu[i + 3 - j]) {
                                        if (j == 2 && YuWu[i + 2] != 0) {
                                            break;
                                        }
                                        if (j == 3 && YuWu[i + 2] != 0 || (j == 3 && YuWu[i + 1] != 0)) { break; }
                                        if (gu[i + 3] != 1) {
                                            Shu[i + 3] = 2 * Shu[i + 3]; Shu[i + 3 - j] = 0;
                                            YuWu[i + 3 - j] = 0; gu[i + 3] = 1; dong++;
                                        }
                                    }
                                }for (int j = 1; j <= 2; j++) {
                                    if (YuWu[i + 2] == 0 && YuWu[i + 2 - j] == 1) {
                                        Shu[i + 2] = Shu[i + 2 - j]; YuWu[i + 2] = 1;
                                        Shu[i + 2 - j] = 0; YuWu[i + 2 - j] = 0; dong++;
                                    }if (YuWu[i + 2] == 1 && YuWu[i + 2 - j] == 1 && Shu[2 + i] == Shu[i + 2 - j]) {
                                        if (j == 2 && YuWu[i + 1] != 0) { break; }
                                        if (gu[i + 2] != 1) {
                                            Shu[2 + i] = 2 * Shu[i + 2 - j]; Shu[i + 2 - j] = 0;
                                            YuWu[i + 2 - j] = 0; gu[i + 2] = 1; dong++;
                                        }
                                    }
                                }


                                if (YuWu[1 + i] == 0 && YuWu[i] == 1) {
                                    Shu[1 + i] = Shu[i]; YuWu[1 + i] = 1;
                                    Shu[i] = 0; YuWu[i] = 0; dong++;
                                }

                                if (YuWu[1 + i] == 1 && YuWu[i] == 1 && Shu[1 + i] == Shu[i]) {
                                    Shu[1 + i] = 2 * Shu[0 + i]; Shu[0 + i] = 0; YuWu[0 + i] = 0; dong++;
                                }
                            }
                            if (dong != 0) {
                                while (true) {
                                    suiji = distribution(generator) % 16;
                                    if (YuWu[suiji] == 0) {
                                        Shu[suiji] = (2 + suiji % 2 * 2); YuWu[suiji] = 1; break;
                                    }
                                }
                            }
                            for (int i = 0; i < 16; i++)
                            {

                                if (Shu[i] != 0) YuWu[i] = 1;

                                TCHAR shu[17];
                                char str[17];
                                if (Shu[i] != 0) {
                                    sprintf_s(str, "%d", Shu[i]);
                                    MultiByteToWideChar(CP_ACP, 0, str, -1, shu, 32);
                                    settextstyle(100, 0, _T("宋体"));
                                    if (Shu[i] > 64 && Shu[i] <= 512) { outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] < 128) { outtextxy(470 + i % 4 * 200, 100 + i / 4 * 200, shu); }
                                    if (Shu[i] > 512) { settextstyle(80, 0, _T("宋体")); outtextxy(420 + i % 4 * 200, 100 + i / 4 * 200, shu); }

                                }
                            }
                            for (int i = 0; i <= 4; i++)
                            {

                                setlinecolor(BLACK);
                                line(400, 50 + 200 * i, 1200, 50 + 200 * i);
                                line(400 + 200 * i, 50, 400 + 200 * i, 850);
                            }
                            outtextxy(1300, 0, L"退出"); outtextxy(1300, 100, L"重新开始");

                        }
                        if (chengjiu == 0) { for (int i = 0; i < 16; i++) { 
                            if (Shu[i] == 2048){
                         MessageBox(GetHWnd(), _T("获得成就2048达人"), _T("恭喜你"), MB_OK); chengjiu = 1; std::string dir_path = ".\\成就\\";
                         std::string file_path = dir_path + std::to_string(5) + ".txt";
                         // 用于存储文件内容
                         std::stringstream buffer;
                         {
                             // 创建输入文件流对象
                             std::ifstream inFile(file_path);
                             // 将文件内容读取到字符串流（buffer）中
                             buffer << inFile.rdbuf();
                             // 关闭输入文件流
                             inFile.close();
                         }
                         // 修改buffer中的内容
                         std::string content = buffer.str();
                         std::string oldString = "0";
                         std::string newString = "1";
                         // 在content中查找并替换所有旧字符串
                         size_t pos = content.find(oldString);
                         while (pos != std::string::npos) {
                             content.replace(pos, oldString.length(), newString);
                             pos = content.find(oldString, pos + newString.length());
                         }
                         {
                             // 创建输出文件流对象
                             std::ofstream outFile(file_path);
                             // 将修改后的内容写入文件
                             outFile << content;
                             // 关闭输出文件流
                             outFile.close();

                         }
                         break;
                        } } }
                        if (chengjiu == 1) {
                            for (int i = 0; i < 16; i++) {
                                if (Shu[i] == 4096) {
                                    MessageBox(GetHWnd(), _T("获得成就超越极限"), _T("恭喜你"), MB_OK); chengjiu = 1; std::string dir_path = ".\\成就\\";
                                    std::string file_path = dir_path + std::to_string(6) + ".txt";
                                    // 用于存储文件内容
                                    std::stringstream buffer;
                                    {
                                        // 创建输入文件流对象
                                        std::ifstream inFile(file_path);
                                        // 将文件内容读取到字符串流（buffer）中
                                        buffer << inFile.rdbuf();
                                        // 关闭输入文件流
                                        inFile.close();
                                    }
                                    // 修改buffer中的内容
                                    std::string content = buffer.str();
                                    std::string oldString = "0";
                                    std::string newString = "1";
                                    // 在content中查找并替换所有旧字符串
                                    size_t pos = content.find(oldString);
                                    while (pos != std::string::npos) {
                                        content.replace(pos, oldString.length(), newString);
                                        pos = content.find(oldString, pos + newString.length());
                                    }
                                    {
                                        // 创建输出文件流对象
                                        std::ofstream outFile(file_path);
                                        // 将修改后的内容写入文件
                                        outFile << content;
                                        // 关闭输出文件流
                                        outFile.close();

                                    }
                                    break;
                                }
                            }
                        }



                        
                    }

                }






                if (m.x >= 40 && m.x <= 190 && m.y >= 10 && m.y <= 160) {
                   
                    if (dianji == 0) {
                        cleardevice();  mciSendString(L"close mp3", NULL, 0, NULL);
                        mciSendString(L"open \"音乐\\yijing.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                        mciSendString(L"play mp3", NULL, 0, NULL);
                        // 获取当前时间
                        DWORD startTime = timeGetTime();
                        // 播放的总时间
                        DWORD totalTime = 30000; // 30秒
                        while (true)
                        {
                            if (MouseHit()) {
                                MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                                if (m.uMsg == WM_LBUTTONDOWN) { // 判断是否为左键点击事件
                                    if (m.x >= 0 && m.x <= 50 && m.y >= 0 && m.y <= 50) {
                                        dianji += 1; break;
                                    }
                                }
                            }
                            // 获取当前时间
                            DWORD currentTime = timeGetTime();

                            // 计算已经播放的时间
                            DWORD elapsedTime = currentTime - startTime;
                            // 打印文字
                            settextstyle(80, 0, _T("宋体"));
                            if (elapsedTime >= 100) {
                                outtextxy(350, 100, L" 这是一部既古老又新奇");
                                settextstyle(20, 0, _T("宋体")); outtextxy(0, 20, L" 跳过");
                            }
                            settextstyle(80, 0, _T("宋体"));
                            if (elapsedTime >= 3000) { outtextxy(350, 200, L" 既陌生又熟悉"); }
                            if (elapsedTime >= 6000) { outtextxy(350, 300, L" 既高深莫测又简单容易的书"); }
                            if (elapsedTime >= 10000) { outtextxy(350, 400, L" 它就是神秘的《易经》"); }
                            if (elapsedTime >= 13000) { outtextxy(350, 500, L" 也作《周易》"); }
                            if (elapsedTime >= 15000) { outtextxy(350, 600, L" 那么《易经》到底是一部怎样的书呢"); }
                            if (elapsedTime >= 19000) { outtextxy(350, 700, L" 易经是解开宇宙人生密码的一部宝典"); }
                            if (elapsedTime >= 24000) {
                                settextstyle(20, 0, _T("宋体")); outtextxy(0, 20, L" 进入");
                            }
                            DWORD nextFrameTime = startTime + elapsedTime + 1000 / 30; // 每秒30帧

                            // 等待直到下一帧开始
                            while (timeGetTime() < nextFrameTime)
                            {
                                Sleep(1); // 等待1毫秒
                            }
                        }


                        mciSendString(L"close mp3", NULL, 0, NULL);
                    } 
                



            
        
    
    cleardevice();    
    settextstyle(40, 0, _T("宋体")); 
    loadimage(&img经典, _T("图片\\经典.jpg"));
    putimage(00, 00, &img经典);
    loadimage(&img大衍筮, _T("图片\\大衍筮.jpg"));
    putimage(800, 500, &img大衍筮); // 将大衍筮.jpg显示在窗口中的(800, 500)位置
    outtextxy(800, 700, L"大衍筮介绍.txt");

    // 显示 PNG 格式的图片
    loadimage(&imgTaiji, _T("图片\\taiji.png"));
    putimage(300, 100, &imgTaiji); // 将taiji.png显示在窗口中的(300, 100)位置
    outtextxy(300, 350, L"大衍筮模拟.exe");
    // 再显示另一个 PNG 格式的图片
    loadimage(&img曾老, _T("图片\\曾老.jpg"));
    putimage(800, 100, &img曾老); // 将曾老.png显示在窗口中的(800, 100)位置
    outtextxy(800, 400, L"大衍筮视频教学.mp4");
    // 显示第四张 JPG 格式的图片
    loadimage(&img卦, _T("图片\\卦.jpg"));
    putimage(300, 500, &img卦); // 将卦.jpg显示在窗口中的(300, 500)位置
    outtextxy(300, 800, L"易经系辞传.txt"); outtextxy(1500, 0, L"退出");
    setfillcolor(YELLOW); solidrectangle(1500, 100, 1600, 150);
    setfillcolor(BLUE);  solidrectangle(1500, 150, 1600, 200);
    settextcolor(YELLOW); outtextxy(1510, 110, L"音乐");
    settextcolor(BLUE); outtextxy(1510, 160, L"关闭");
    mciSendString(L"open \"音乐\\王先宏 - 太极.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString(L"play mp3", NULL, 0, NULL);

    dianji = 0;
    while (!_kbhit()) {

        if (MouseHit()) {
            MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
            if (m.uMsg == WM_LBUTTONDOWN) { // 判断是否为左键点击事件
                if (m.x >= 1500 && m.x <= 1580 && m.y >= 00 && m.y <= 40){
                    mciSendString(L"close mp3", NULL, 0, NULL);
                    setbkcolor(BLACK); // 设置背景颜色
                    cleardevice();     // 应用背景颜色并清除屏幕
                    setfillcolor(WHITE); // 设置绘图颜色为白色
                    settextcolor(WHITE); // 设置字体颜色
                    HDC hdc = GetImageHDC();
                    Graphics g(hdc);
                    g.DrawImage(&resizedWallpaper, 0, 0, screenWidth, screenHeight);
                    putimage(40, 10, &img太极);
                    putimage(40, 200, &img浏览器);
                    putimage(40, 400, &img应用商店);
                    putimage(40, 600, &img贪吃);
                    putimage(40, 800, &img见缝插针);
                    putimage(240, 10, &img2048);
                    putimage(440, 10, &img五子棋);
                    putimage(640, 10, &img井字棋);
                    putimage(840, 10, &img文件管理器);
                    putimage(240, 200, &img毛选);
                    putimage(440, 400, &img成就);

                    break;
                }
                if (moshi == 1) {
                    settextcolor(WHITE);
                    cleardevice(); settextstyle(40, 0, _T("宋体"));
                   
                    loadimage(&img经典, _T("图片\\经典.jpg"));
                    putimage(00, 00, &img经典);
                    loadimage(&img大衍筮, _T("图片\\大衍筮.jpg"));
                    putimage(800, 500, &img大衍筮); // 将大衍筮.jpg显示在窗口中的(800, 500)位置
                    outtextxy(800, 700, L"大衍筮介绍.txt");

                    // 显示 PNG 格式的图片
                    loadimage(&imgTaiji, _T("图片\\taiji.png"));
                    putimage(300, 100, &imgTaiji); // 将taiji.png显示在窗口中的(300, 100)位置
                    outtextxy(300, 350, L"大衍筮模拟.exe");
                    // 再显示另一个 PNG 格式的图片
                    loadimage(&img曾老, _T("图片\\曾老.jpg"));
                    putimage(800, 100, &img曾老); // 将曾老.png显示在窗口中的(800, 100)位置
                    outtextxy(800, 400, L"大衍筮视频教学.mp4");
                    // 显示第四张 JPG 格式的图片
                    loadimage(&img卦, _T("图片\\卦.jpg"));
                    putimage(300, 500, &img卦); // 将卦.jpg显示在窗口中的(300, 500)位置
                    outtextxy(300, 800, L"易经系辞传.txt"); dianji = 0; outtextxy(1500, 0, L"退出");
                    setfillcolor(YELLOW); solidrectangle(1500, 100, 1600, 150);
                    setfillcolor(BLUE);  solidrectangle(1500, 150, 1600, 200);
                    settextcolor(YELLOW); outtextxy(1510, 110, L"音乐");
                    settextcolor(BLUE); outtextxy(1510, 160, L"关闭");
                } if (m.x >= 1500 && m.x <= 1600 && m.y >= 100 && m.y <= 150) {
                    if (dianji == 0) {
                        mciSendString(L"open \"音乐\\王先宏 - 太极.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                        mciSendString(L"play mp3", NULL, 0, NULL);
                    }
                }
                if (m.x >= 1500 && m.x <= 1600 && m.y > 150 && m.y <= 200) {
                    if (dianji == 0) {
                        mciSendString(L"close mp3", NULL, 0, NULL);
                    }
                }

                if (m.x >= 800 && m.x <= 1100 && m.y >= 100 && m.y <= 400) {
                    mciSendString(L"close mp3", NULL, 0, NULL);
                    ShellExecute(NULL, L"open", L"曾仕强「大衍之数」蓍草筹策起卦教学.mp4", NULL, NULL, SW_SHOWNORMAL);
                }
                if (m.x >= 300 && m.x <= 600 && m.y >= 500 && m.y <= 778) {
                    system("notepad.exe 系辞传.txt");
                }
                if (m.x >= 800 && m.x <= 1150 && m.y >= 500 && m.y <= 700) {
                    if (dianji == 0) {
                        settextcolor(WHITE);
                        cleardevice(); while (true)
                        {
                            settextstyle(20, 0, _T("宋体")); outtextxy(1600, 20, L" 退出");

                            if (MouseHit()) {
                                MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                                if (m.uMsg == WM_LBUTTONDOWN) { // 判断是否为左键点击事件
                                    if (m.x >= 1600 && m.x <= 1650 && m.y >= 0 && m.y <= 50) {
                                        moshi = 1; settextcolor(WHITE);
                                        cleardevice(); settextstyle(40, 0, _T("宋体"));
                                       
                                        loadimage(&img经典, _T("图片\\经典.jpg"));
                                        putimage(00, 00, &img经典);
                                        loadimage(&img大衍筮, _T("图片\\大衍筮.jpg"));
                                        putimage(800, 500, &img大衍筮); // 将大衍筮.jpg显示在窗口中的(800, 500)位置
                                        outtextxy(800, 700, L"大衍筮介绍.txt");

                                        // 显示 PNG 格式的图片
                                        loadimage(&imgTaiji, _T("图片\\taiji.png"));
                                        putimage(300, 100, &imgTaiji); // 将taiji.png显示在窗口中的(300, 100)位置
                                        outtextxy(300, 350, L"大衍筮模拟.exe");
                                        // 再显示另一个 PNG 格式的图片
                                        loadimage(&img曾老, _T("图片\\曾老.jpg"));
                                        putimage(800, 100, &img曾老); // 将曾老.png显示在窗口中的(800, 100)位置
                                        outtextxy(800, 400, L"大衍筮视频教学.mp4");
                                        // 显示第四张 JPG 格式的图片
                                        loadimage(&img卦, _T("图片\\卦.jpg"));
                                        putimage(300, 500, &img卦); // 将卦.jpg显示在窗口中的(300, 500)位置
                                        outtextxy(300, 800, L"易经系辞传.txt"); dianji = 0; outtextxy(1500, 0, L"退出");
                                        setfillcolor(YELLOW); solidrectangle(1500, 100, 1600, 150);
                                        setfillcolor(BLUE);  solidrectangle(1500, 150, 1600, 200);
                                        settextcolor(YELLOW); outtextxy(1510, 110, L"音乐");
                                        settextcolor(BLUE); outtextxy(1510, 160, L"关闭");
                                        break;
                                    }
                                }
                            }

                            settextstyle(40, 0, _T("宋体")); // 设置字体大小和样式
                            int lineHeight = textheight(_T("H"));

                            //打开文件，并设置为UTF-8编码
                            std::wifstream infile("大衍筮介绍.txt");
                            infile.imbue(std::locale(infile.getloc(), new std::codecvt_utf8<wchar_t>));


                            std::wstring lin;
                            int y = 0;

                            //按行读取文件并显示
                            while (std::getline(infile, lin)) {
                                ShowTextByLine(lin, 0, y, lineHeight); // 输出当前行
                                y += lineHeight; // 到下一行的位置
                            }
                            infile.close();
                            settextstyle(30, 0, _T("宋体"));
                            int lineHeight2 = textheight(_T("H"));

                            // 打开文件，并设置为UTF-8编码
                            std::wifstream infile2("操作步骤.txt");
                            infile2.imbue(std::locale(infile2.getloc(), new std::codecvt_utf8<wchar_t>));


                            std::wstring lin2;
                            int y2 = 450;

                            // 按行读取文件并显示
                            while (std::getline(infile2, lin2)) {
                                ShowTextByLine(lin2, 0, y2, lineHeight2); // 输出当前行
                                y2 += lineHeight2; // 到下一行的位置
                            }
                            infile.close();
                        }
                    }
                }
                if (m.x >= 300 && m.x <= 600 && m.y >= 100 && m.y <= 350) {
                    dianji = 0;  mciSendString(L"close mp3", NULL, 0, NULL); Yao = 1;
                    while (true) {

                        settextcolor(WHITE);
                        if (dianji == 0) {
                            if (moshi == 2) { moshi = 1; break; }
                            cleardevice();  settextstyle(50, 0, _T("宋体"));
                            outtextxy(500, 300, L" 保持头脑清醒和冷静。");
                            outtextxy(500, 400, L" 放松心态集中注意力。");
                            outtextxy(500, 500, L" 避免干扰清空杂念。");
                            outtextxy(500, 600, L" 不要强求结果理性思考。");

                            dianji = 1;
                        }
                        while (true) {
                            if (MouseHit()) {
                                MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                                if (m.uMsg == WM_LBUTTONDOWN) { // 判断是否为左键点击事件

                                    if (dianji == 1) {
                                        cleardevice();
                                        settextstyle(50, 0, _T("宋体"));
                                        outtextxy(50, 100, L" 默念一小段祷词:");
                                        outtextxy(100, 200, L"“假尔泰筮有常，某(自己名字)今以某事(想要占问之事)，未知可否。");
                                        outtextxy(100, 300, L"爰质所疑于神之灵，吉凶、得失、悔吝、忧虞，惟尔有神，尚明告知。”");
                                        dianji = 2; break;
                                    }

                                    if (dianji == 2) {
                                        cleardevice(); settextstyle(50, 0, _T("宋体"));
                                        outtextxy(200, 200, L"随意取出一根放在一边，象征太极，从开始到结束这根筷子不动。");
                                        for (int i = 1; i <= ChouCe; i++)
                                        {
                                            setlinecolor(BROWN);
                                            line(100 + i * 30, 300, 100 + i * 30, 600);
                                        }
                                        dianji = 3; break;
                                    }

                                    if (dianji == 3) {
                                        if (Yao == 1) {
                                            for (int i = 1; i <= ChouCe; i++) {
                                                int startX = 95 + i * 30; // 当前线段的起始点x坐标
                                                int endX = 105 + i * 30;   // 当前线段的终点x坐标
                                                if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                    cleardevice();
                                                    settextstyle(100, 0, _T("宋体")); setlinecolor(RED);
                                                    line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(40, 0, _T("宋体"));
                                                    outtextxy(100, 200, L"初爻第一次运算，随机将剩下的筷子分为两组，左边一组象征天，右边象征地。");
                                                    outtextxy(100, 120, L"每一爻需要三次运算，六爻共十八次运算，所谓“十八有变而成卦");
                                                    dianji = 4; tai = i;

                                                    for (int j = 1; j <= ChouCe; j++)
                                                    {
                                                        if (j != i) {
                                                            setlinecolor(BROWN);
                                                            line(100 + j * 30, 300, 100 + j * 30, 600);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cleardevice();
                                            settextstyle(100, 0, _T("宋体")); setlinecolor(RED);
                                            line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(40, 0, _T("宋体"));
                                            dianji = 4;
                                            if (Yao > 1) {
                                                for (int n = 0; n < Yao - 1; n++)
                                                {
                                                    if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                    if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                    if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                    if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                }
                                            }
                                            for (int j = 1; j <= ChouCe; j++)
                                            {
                                                if (j != tai) {
                                                    setlinecolor(BROWN);
                                                    line(100 + j * 30, 300, 100 + j * 30, 600);
                                                }
                                            }
                                            if (Yao == 2) { outtextxy(100, 200, L"二爻第一次运算，随机将剩下的筷子分为两组"); }
                                            if (Yao == 3) { outtextxy(100, 200, L"三爻第一次运算，随机将剩下的筷子分为两组"); }
                                            if (Yao == 4) { outtextxy(100, 200, L"四爻第一次运算，随机将剩下的筷子分为两组"); }
                                            if (Yao == 5) { outtextxy(100, 200, L"五爻第一次运算，随机将剩下的筷子分为两组"); }
                                            if (Yao == 6) { outtextxy(100, 200, L"上爻第一次运算，随机将剩下的筷子分为两组"); }
                                        }
                                        break;
                                    }




                                    if (dianji == 4) {

                                        for (int i = 1; i <= ChouCe; i++) {
                                            int startX = 100 + i * 30; // 当前线段的起始点x坐标
                                            int endX = 130 + i * 30;         // 当前线段的终点x坐标
                                            int a = 0, b = 51;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                dingwei = i; cleardevice(); dianji = 5;  settextstyle(100, 0, _T("宋体"));
                                                setlinecolor(RED); line(650, 100, 950, 100);
                                                outtextxy(700, 0, L"太极");  settextstyle(50, 0, _T("宋体"));
                                                outtextxy(100, 120, L"从右边一组筷子中拿出一根，夹在左手小指与无名指中，这根筷子代表人。");
                                                outtextxy(100, 200, L"这样左右两组和这一根象征着天地人三才");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    if (j != tai) {
                                                        a++;
                                                        setlinecolor(BROWN);
                                                        line(110 + a * 20, 300, 110 + a * 20, 600);
                                                    }
                                                }
                                                for (int j = 50; j > dingwei; j--)
                                                {
                                                    if (j != tai) {
                                                        b--;
                                                        setlinecolor(BROWN);
                                                        line(600 + b * 20, 300, 600 + b * 20, 600);
                                                    }
                                                }
                                            }
                                        }break;
                                    }


                                    if (dianji == 5) {

                                        for (int i = 1; i <= ChouCe - 1 - dingwei; i++) {
                                            int startX = 1615 - i * 20; // 当前线段的起始点x坐标
                                            int endX = 1625 - i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 51;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 6; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(50, 0, _T("宋体"));
                                                outtextxy(200, 200, L"右手组以四除之，也就是四根一组划开");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    if (j != tai) {
                                                        a++;
                                                        setlinecolor(BROWN);
                                                        line(110 + a * 20, 300, 110 + a * 20, 600);
                                                    }
                                                }for (int j = 50; j > dingwei; j--) {
                                                    if (j != tai) {
                                                        b--; if (j != 51 - i) {
                                                            setlinecolor(BROWN);
                                                            line(600 + b * 20, 300, 600 + b * 20, 600);
                                                        }
                                                    }
                                                }
                                                setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                            }
                                        }
                                        break;
                                    }if (dianji == 6) {
                                        for (int i = 1; i <= ChouCe - 2 - dingwei; i++) {
                                            int startX = 1610 - i * 20; // 当前线段的起始点x坐标
                                            int endX = 1630 - i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 620;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 7; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(45, 0, _T("宋体"));
                                                outtextxy(100, 200, L"右手组所余之数，为一或二或三或四，将此筹策也放置于左手无名指与中指之间。");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                if (dingwei > tai)dingwei -= 1;
                                                yu1 = (48 - dingwei) % 4; if (yu1 == 0) { yu1 = 4; }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(110 + j * 20, 300, 110 + j * 20, 600);
                                                }for (int j = 49; j > dingwei + 1; j--) {
                                                    if (j - dingwei - 1 <= yu1) {
                                                        setlinecolor(YELLOW);
                                                    }
                                                    if (a % 4 == 0) { b = b - 40; }
                                                    line(b + j * 20, 300, b + j * 20, 600);
                                                    a++; jing = 620 - b;
                                                } setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                            }
                                        }break;
                                    }
                                    if (dianji == 7) {
                                        for (int i = 48 - dingwei - yu1; i <= ChouCe - 2 - dingwei; i++) {
                                            int startX = 1612 - jing - i * 20; // 当前线段的起始点x坐标
                                            int endX = 1628 - jing - i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 620;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 8; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(50, 0, _T("宋体"));
                                                outtextxy(100, 200, L"左手组亦以四除之，也就是四根一组划开");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(110 + j * 20, 300, 110 + j * 20, 600);
                                                }for (int j = 49; j > dingwei + 1; j--) {
                                                    setlinecolor(BROWN); if (j - dingwei - 1 <= yu1) {
                                                        break;
                                                    }
                                                    if (a % 4 == 0) { b = b - 40; }
                                                    line(b + j * 20, 300, b + j * 20, 600);
                                                    a++;
                                                } setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                                for (int gen = 1; gen <= yu1; gen++)
                                                {
                                                    line(130, 740 + gen * 10, 430, 740 + gen * 10);
                                                }
                                                outtextxy(200, 750 + yu1 * 10, L" 中指");
                                            }
                                        }  break;
                                    } if (dianji == 8) {
                                        for (int i = 1; i <= dingwei; i++) {
                                            int startX = 103 + i * 20; // 当前线段的起始点x坐标
                                            int endX = 118 + i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 110;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 9; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(45, 0, _T("宋体"));
                                                outtextxy(100, 200, L"左手组所余之数，为一或二或三或四，将此筹策也放置于左手中指与食指之间。");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                yu2 = dingwei % 4; if (yu2 == 0) { yu2 = 4; }
                                                for (int j = 49; j > dingwei + 1 + yu1; j--)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(620 + j * 20, 300, 620 + j * 20, 600);
                                                }for (int j = 1; j <= dingwei; j++) {
                                                    if (dingwei + 1 - j <= yu2) {
                                                        setlinecolor(YELLOW);
                                                    }
                                                    if (a % 4 == 0) { b = b + 40; }
                                                    line(b + j * 20, 300, b + j * 20, 600);
                                                    a++; jing = b - 110;
                                                } setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                                for (int gen = 1; gen <= yu1; gen++)
                                                {
                                                    line(130, 740 + gen * 10, 430, 740 + gen * 10);
                                                }
                                                outtextxy(200, 750 + yu1 * 10, L" 中指");
                                            }
                                        }break;
                                    }if (dianji == 9) {
                                        for (int i = dingwei - yu2 + 1; i <= dingwei; i++) {
                                            int startX = 103 + jing + i * 20; // 当前线段的起始点x坐标
                                            int endX = 118 + jing + i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 110;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 10; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极");
                                                settextstyle(50, 0, _T("宋体")); ci = 2;
                                                outtextxy(100, 120, L"第一次运算完成，将左手指的筹策放于右上");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                outtextxy(100, 200, L"剩余筹策重新开始运算");
                                                setfillcolor(YELLOW); solidrectangle(1390, 15, 1505, 75);
                                                outtextxy(1400, 20, L"放这");
                                                yu2 = dingwei % 4; if (yu2 == 0) { yu2 = 4; }
                                                for (int j = 49; j > dingwei + 1 + yu1; j--)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(620 + j * 20, 300, 620 + j * 20, 600);
                                                }for (int j = 1; j <= dingwei; j++) {
                                                    if (dingwei + 1 - j <= yu2) {
                                                        break;
                                                    } setlinecolor(BROWN);
                                                    if (a % 4 == 0) { b = b + 40; }
                                                    line(b + j * 20, 300, b + j * 20, 600);
                                                    a++;
                                                } setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                                for (int gen = 1; gen <= yu1; gen++)
                                                {
                                                    line(130, 740 + gen * 10, 430, 740 + gen * 10);
                                                }
                                                outtextxy(200, 750 + yu1 * 10, L" 中指");
                                                for (int gen = 1; gen <= yu2; gen++)
                                                {
                                                    line(130, 800 + yu1 * 10 + gen * 10, 430, 800 + yu1 * 10 + gen * 10);
                                                }
                                                outtextxy(200, 810 + yu1 * 10 + yu2 * 10, L" 食指"); jian = yu1 + yu2 + 1 + 1;
                                            }
                                        }break;
                                    } if (dianji == 10) {
                                        if (m.x >= 1390 && m.x <= 1505 && m.y >= 15 && m.y <= 75) {
                                            cleardevice(); settextstyle(100, 0, _T("宋体"));  setlinecolor(RED);  dianji = 11;
                                            line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(50, 0, _T("宋体"));
                                            if (ci == 2) { outtextxy(500, 120, L"第二次运算"); }
                                            if (ci == 3) { outtextxy(500, 120, L"第三次运算"); }
                                            outtextxy(300, 200, L"将剩余筹策任意分为左右两组");
                                            if (Yao > 1) {
                                                for (int n = 0; n < Yao - 1; n++)
                                                {
                                                    if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                    if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                    if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                    if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                }
                                            }
                                            for (int i = 1; i <= ChouCe - jian; i++)
                                            {
                                                setlinecolor(BROWN);
                                                line(100 + jian * 15 + i * 30, 300, 100 + jian * 15 + i * 30, 600);
                                            }
                                        }
                                        break;
                                    }  if (dianji == 11) {

                                        for (int i = 1; i <= ChouCe - jian; i++) {
                                            int startX = 100 + jian * 15 + i * 30; // 当前线段的起始点x坐标
                                            int endX = 130 + jian * 15 + i * 30;         // 当前线段的终点x坐标
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                dingwei = i; cleardevice(); dianji = 12;  settextstyle(100, 0, _T("宋体"));
                                                setlinecolor(RED); line(650, 100, 950, 100);
                                                outtextxy(700, 0, L"太极");  settextstyle(50, 0, _T("宋体"));
                                                outtextxy(100, 120, L"从右边一组筷子中拿出一根，夹在左手小指与无名指中，这根筷子代表人。");
                                                outtextxy(100, 200, L"这样左右两组和这一根象征着天地人三才");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(110 + jian * 15 + j * 20, 300, 110 + jian * 15 + j * 20, 600);
                                                }
                                                for (int j = ChouCe - jian; j > dingwei; j--)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(600 + jian * 5 + j * 20, 300, 600 + jian * 5 + j * 20, 600);
                                                }

                                            }
                                        }break;
                                    }   if (dianji == 12) {

                                        for (int i = 1; i <= ChouCe - jian - dingwei; i++) {
                                            int startX = 1615 - jian * 15 - i * 20; // 当前线段的起始点x坐标
                                            int endX = 1625 - jian * 15 - i * 20;// 当前线段的终点x坐标
                                            int a = 0;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 13; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(50, 0, _T("宋体"));
                                                outtextxy(200, 200, L"右手组以四除之，也就是四根一组划开");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    a++;
                                                    setlinecolor(BROWN);
                                                    line(110 + jian * 15 + a * 20, 300, 110 + jian * 15 + a * 20, 600);
                                                }for (int j = ChouCe - jian; j > dingwei; j--) {
                                                    if (j != ChouCe - jian - i + 1) {
                                                        setlinecolor(BROWN);
                                                        line(600 + jian * 5 + j * 20, 300, 600 + jian * 5 + j * 20, 600);
                                                    }
                                                }
                                                setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                            }
                                        }
                                        break;
                                    }if (dianji == 13) {
                                        for (int i = 1; i <= ChouCe - jian - dingwei; i++) {
                                            int startX = 1610 - jian * 15 - i * 20; // 当前线段的起始点x坐标
                                            int endX = 1630 - jian * 15 - i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 620;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 14; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(45, 0, _T("宋体"));
                                                outtextxy(100, 200, L"右手组所余之数，为一或二或三或四，将此筹策也放置于左手无名指与中指之间。");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                yu1 = (ChouCe - jian - 1 - dingwei) % 4; if (yu1 == 0) { yu1 = 4; }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(110 + jian * 15 + j * 20, 300, 110 + jian * 15 + j * 20, 600);
                                                }for (int j = ChouCe - jian; j > dingwei + 1; j--) {
                                                    if (j - dingwei - 1 <= yu1) {
                                                        setlinecolor(YELLOW);
                                                    }
                                                    if (a % 4 == 0) { b = b - 40; }
                                                    line(b + jian * 5 + j * 20, 300, b + jian * 5 + j * 20, 600);
                                                    a++; jing = 620 - b;
                                                } setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                            }
                                        }break;
                                    }
                                    if (dianji == 14) {
                                        for (int i = ChouCe - jian - dingwei - yu1; i <= ChouCe - jian - dingwei; i++) {
                                            int startX = 1630 - jing - jian * 15 - i * 20; // 当前线段的起始点x坐标
                                            int endX = 1650 - jing - jian * 15 - i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 620;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 15; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(50, 0, _T("宋体"));
                                                outtextxy(100, 200, L"左手组亦以四除之，也就是四根一组划开");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                for (int j = 1; j <= dingwei; j++)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(110 + jian * 15 + j * 20, 300, 110 + jian * 15 + j * 20, 600);
                                                }for (int j = ChouCe - jian; j > dingwei + 1; j--) {
                                                    setlinecolor(BROWN); if (j - dingwei - 1 <= yu1) {
                                                        break;
                                                    }
                                                    if (a % 4 == 0) { b = b - 40; }
                                                    line(b + jian * 5 + j * 20, 300, b + jian * 5 + j * 20, 600);
                                                    a++;
                                                } setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                                for (int gen = 1; gen <= yu1; gen++)
                                                {
                                                    line(130, 740 + gen * 10, 430, 740 + gen * 10);
                                                }
                                                outtextxy(200, 750 + yu1 * 10, L" 中指");
                                            }
                                        }  break;
                                    }if (dianji == 15) {
                                        for (int i = 1; i <= dingwei; i++) {
                                            int startX = 103 + jian * 15 + i * 20; // 当前线段的起始点x坐标
                                            int endX = 118 + jian * 15 + i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 110;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体")); dianji = 16; setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(45, 0, _T("宋体"));
                                                outtextxy(100, 200, L"左手组所余之数，为一或二或三或四，将此筹策也放置于左手中指与食指之间。");
                                                if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                yu2 = dingwei % 4; if (yu2 == 0) { yu2 = 4; }
                                                for (int j = ChouCe - jian; j > dingwei + 1 + yu1; j--)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(620 + jian * 5 + j * 20, 300, 620 + jian * 5 + j * 20, 600);
                                                }for (int j = 1; j <= dingwei; j++) {
                                                    if (dingwei + 1 - j <= yu2) {
                                                        setlinecolor(YELLOW);
                                                    }
                                                    if (a % 4 == 0) { b = b + 40; }
                                                    line(b + jian * 15 + j * 20, 300, b + jian * 15 + j * 20, 600);
                                                    a++; jing = b - 110;
                                                } setlinecolor(RED);
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                                for (int gen = 1; gen <= yu1; gen++)
                                                {
                                                    line(130, 740 + gen * 10, 430, 740 + gen * 10);
                                                }
                                                outtextxy(200, 750 + yu1 * 10, L" 中指");
                                            }
                                        }break;
                                    }if (dianji == 16) {
                                        for (int i = dingwei - yu2 + 1; i <= dingwei; i++) {
                                            int startX = 103 + jian * 15 + jing + i * 20; // 当前线段的起始点x坐标
                                            int endX = 118 + jing + jian * 15 + i * 20;// 当前线段的终点x坐标
                                            int a = 0, b = 110;
                                            if (m.x >= startX && m.x <= endX && m.y >= 300 && m.y <= 600) {
                                                cleardevice(); settextstyle(100, 0, _T("宋体"));
                                                setlinecolor(RED);
                                                line(650, 100, 950, 100); outtextxy(700, 0, L"太极"); settextstyle(50, 0, _T("宋体"));
                                                if (ci == 2) {
                                                    outtextxy(100, 120, L"第二次运算完成，将左手指的筹策放于右上");
                                                    outtextxy(100, 200, L"剩余筹策重新开始运算");
                                                }
                                                if (ci == 3) {
                                                    outtextxy(100, 120, L"第三次运算完成，将左手指的筹策放于右上");
                                                } if (Yao > 1) {
                                                    for (int n = 0; n < Yao - 1; n++)
                                                    {
                                                        if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                        if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                        if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                        if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                    }
                                                }
                                                setfillcolor(YELLOW); solidrectangle(1390, 15, 1505, 75);
                                                outtextxy(1400, 20, L"放这");
                                                yu2 = dingwei % 4; if (yu2 == 0) { yu2 = 4; }
                                                for (int j = ChouCe - jian; j > dingwei + 1 + yu1; j--)
                                                {
                                                    setlinecolor(BROWN);
                                                    line(620 + j * 20, 300, 620 + j * 20, 600);
                                                }for (int j = 1; j <= dingwei; j++) {
                                                    if (dingwei + 1 - j <= yu2) {
                                                        break;
                                                    } setlinecolor(BROWN);
                                                    if (a % 4 == 0) { b = b + 40; }
                                                    line(b + j * 20, 300, b + j * 20, 600);
                                                    a++;
                                                } setlinecolor(RED); ci += 1; if (ci <= 3) { dianji = 10; }
                                                if (ci == 4) { dianji = 17; }
                                                settextstyle(50, 0, _T("宋体")); outtextxy(200, 620, L" 小指");
                                                line(130, 680, 430, 680); outtextxy(180, 690, L" 无名指");
                                                for (int gen = 1; gen <= yu1; gen++)
                                                {
                                                    line(130, 740 + gen * 10, 430, 740 + gen * 10);
                                                }
                                                outtextxy(200, 750 + yu1 * 10, L" 中指");
                                                for (int gen = 1; gen <= yu2; gen++)
                                                {
                                                    line(130, 800 + yu1 * 10 + gen * 10, 430, 800 + yu1 * 10 + gen * 10);
                                                }
                                                outtextxy(200, 810 + yu1 * 10 + yu2 * 10, L" 食指"); jian += yu1 + yu2 + 1;
                                            }
                                        }break;
                                    }
                                    if (dianji == 17) {
                                        if (m.x >= 1390 && m.x <= 1505 && m.y >= 15 && m.y <= 75) {
                                            int a = 0, b = 110; yao[Yao - 1] = (ChouCe - jian) / 4;
                                            cleardevice(); settextstyle(100, 0, _T("宋体"));
                                            setlinecolor(RED); dianji = 3;
                                            line(650, 100, 950, 100); outtextxy(700, 0, L"太极");
                                            settextstyle(50, 0, _T("宋体"));
                                            if (Yao == 1) { outtextxy(100, 120, L"初爻三次运算完成，记下组数，点击开始二爻的操作"); }
                                            if (Yao == 2) { outtextxy(100, 200, L"二爻三次运算完成，记下组数，点击开始三爻的操作"); }
                                            if (Yao == 3) { outtextxy(100, 200, L"三爻三次运算完成，记下组数，点击开始四爻的操作"); }
                                            if (Yao == 4) { outtextxy(100, 200, L"四爻三次运算完成，记下组数，点击开始五爻的操作"); }
                                            if (Yao == 5) { outtextxy(100, 200, L"五爻三次运算完成，记下组数，点击开始六爻的操作"); }
                                            if (Yao == 6) { outtextxy(100, 200, L"上爻三次运算完成，记下组数，生成卦像"); }
                                            if (Yao > 1) {
                                                for (int n = 0; n < Yao - 1; n++)
                                                {
                                                    if (yao[n] == 6) { outtextxy(500 + n * 60, 700, L"六"); }
                                                    if (yao[n] == 7) { outtextxy(500 + n * 60, 700, L"七"); }
                                                    if (yao[n] == 8) { outtextxy(500 + n * 60, 700, L"八"); }
                                                    if (yao[n] == 9) { outtextxy(500 + n * 60, 700, L"九"); }
                                                }
                                            }
                                            for (int i = 1; i <= ChouCe - jian; i++)
                                            {
                                                setlinecolor(BROWN);
                                                if (a % 4 == 0) { b = b + 40; }
                                                line(b + jian * 15 + i * 20, 300, b + jian * 15 + i * 20, 600); a++;
                                            }Yao++; if (Yao == 7) { dianji = 18; }
                                        }
                                        break;
                                    } if (dianji == 18) {
                                        cleardevice();
                                        // 绘制实心矩形
                                        for (int i = 0; i < 6; i++)
                                        {
                                            if (yao[i] == 6) {
                                                setfillcolor(WHITE);
                                                solidrectangle(Xyao, Yyao - i * size, Xyao + 180, Yyao + 40 - i * size);//size 80 Xyao 100 Yyao 600
                                                solidrectangle(Xyao + 240, Yyao - i * size, Xyao + 420, Yyao + 40 - i * size);
                                                solidrectangle(Xyao + 820, Yyao - i * size, Xyao + 1240, Yyao + 40 - i * size);
                                            }
                                            if (yao[i] == 7) {
                                                setfillcolor(WHITE);
                                                solidrectangle(Xyao, Yyao - i * size, Xyao + 420, Yyao + 40 - i * size);
                                                solidrectangle(Xyao + 820, Yyao - i * size, Xyao + 1240, Yyao + 40 - i * size);
                                            }
                                            if (yao[i] == 8) {
                                                setfillcolor(WHITE);
                                                solidrectangle(Xyao, Yyao - i * size, Xyao + 180, Yyao + 40 - i * size);
                                                solidrectangle(Xyao + 240, Yyao - i * size, Xyao + 420, Yyao + 40 - i * size);
                                                solidrectangle(Xyao + 820, Yyao - i * size, Xyao + 1000, Yyao + 40 - i * size);
                                                solidrectangle(Xyao + 1060, Yyao - i * size, Xyao + 1240, Yyao + 40 - i * size);
                                            }
                                            if (yao[i] == 9) {
                                                setfillcolor(WHITE);
                                                solidrectangle(Xyao, Yyao - i * size, Xyao + 420, Yyao + 40 - i * size);
                                                solidrectangle(Xyao + 820, Yyao - i * size, Xyao + 1000, Yyao + 40 - i * size);
                                                solidrectangle(Xyao + 1060, Yyao - i * size, Xyao + 1240, Yyao + 40 - i * size);
                                            }

                                            Sleep(150);
                                        }
                                        // 绘制箭头主干   
                                        setlinecolor(WHITE);
                                        line(550, 420, 880, 420);

                                        // 绘制箭头头部
                                        line(880, 420, 850, 400);
                                        line(880, 420, 850, 440);

                                        // 渲染箭头头部
                                        POINT arrowhead[3] = { {850, 400}, {880, 420}, {850, 440} };
                                        fillpolygon(arrowhead, 3);


                                        for (int i = 0; i < 6; i++)
                                        {
                                            if (yao[i] % 2 == 1) ben = ben + pow(2, i);
                                            if (yao[i] == 6 || yao[i] == 7) bian = bian + pow(2, i);
                                        }     // 设置字体和颜色
                                        // 注意: EasyX 2021新增了ege里的字体设置函数setfont，如果使用老版本的库，可能需要找到对应的函数或者切换到新版图形库

                                        // 在图形界面上显示本卦和变卦的名称
                                        TCHAR benMing[64];
                                        TCHAR bianMing[64];
                                        // 安全地将多字节的C字符串转换为宽字符串
                                        MultiByteToWideChar(CP_ACP, 0, gua[ben], -1, benMing, 64);
                                        MultiByteToWideChar(CP_ACP, 0, gua[bian], -1, bianMing, 64);
                                        settextstyle(100, 0, _T("宋体"));
                                        outtextxy(150, 50, benMing);  // 画面顶部显示本卦
                                        outtextxy(980, 50, bianMing); // 画面顶部显示变卦
                                        outtextxy(600, 300, L"变卦");
                                        Button btn = { 100, 650, 320, 800 };
                                        setfillcolor(YELLOW);
                                        fillrectangle(btn.left, btn.top, btn.right, btn.bottom);
                                        fillrectangle(btn.left + 820, btn.top, btn.right + 820, btn.bottom);
                                        outtextxy(btn.left + 10, btn.top + 20, L"注释");
                                        outtextxy(btn.left + 830, btn.top + 20, L"注释");
                                        settextstyle(20, 0, _T("宋体"));
                                        outtextxy(1600, 10, L"退出");


                                        if (tui == 1) {
                                            while (true) {
                                                // 监听鼠标事件
                                                if (MouseHit()) {
                                                    MOUSEMSG m = GetMouseMsg(); // 获取一个鼠标消息
                                                    // 判断是否为左键点击事件
                                                    if (m.uMsg == WM_LBUTTONDOWN) {
                                                        // 判断是否点击在按钮区域内
                                                        if (m.x >= btn.left && m.x <= btn.right && m.y >= btn.top && m.y <= btn.bottom) {
                                                            // 执行打开文本操作
                                                                  // 这里是你的数字
                                                            std::string dir_path = ".\\六十四卦\\";
                                                            std::string file_path = dir_path + std::to_string(ben) + ".txt";
                                                            std::ifstream file(file_path);

                                                            if (file.is_open()) {
                                                                MessageBox(GetHWnd(), L"文件成功打开！", L"提示", MB_OK);
                                                                file.close();
                                                            }
                                                            else {
                                                                MessageBox(GetHWnd(), L"无法打开文件！", L"错误", MB_OK | MB_ICONERROR);
                                                            }

                                                            system(("notepad.exe " + file_path).c_str());


                                                        }
                                                        if (m.x >= btn.left + 820 && m.x <= btn.right + 820 && m.y >= btn.top && m.y <= btn.bottom) {
                                                            // 执行打开文本操作
                                                            std::string dir_path = ".\\六十四卦\\";

                                                            std::string file_path = dir_path + std::to_string(bian) + ".txt";
                                                            std::ifstream file(file_path);

                                                            if (file.is_open()) {
                                                                MessageBox(GetHWnd(), L"文件成功打开！", L"提示", MB_OK);
                                                                file.close();
                                                            }
                                                            else {
                                                                MessageBox(GetHWnd(), L"无法打开文件！", L"错误", MB_OK | MB_ICONERROR);
                                                            }

                                                            system(("notepad.exe " + file_path).c_str());
                                                        }  if (m.x >= 1600 && m.x <= 1650 && m.y >= 0 && m.y <= 50) {
                                                            tui = 2; dianji = 19;
                                                            break;
                                                        }

                                                    }
                                                }
                                            }
                                        }
                                    }if (dianji == 19) {
                                        cleardevice(); settextstyle(40, 0, _T("宋体"));
                                       
                                        loadimage(&img经典, _T("图片\\经典.jpg"));
                                        putimage(00, 00, &img经典);
                                        loadimage(&img大衍筮, _T("图片\\大衍筮.jpg"));
                                        putimage(800, 500, &img大衍筮); // 将大衍筮.jpg显示在窗口中的(800, 500)位置
                                        outtextxy(800, 700, L"大衍筮介绍.txt");

                                        // 显示 PNG 格式的图片
                                        loadimage(&imgTaiji, _T("图片\\taiji.png"));
                                        putimage(300, 100, &imgTaiji); // 将taiji.png显示在窗口中的(300, 100)位置
                                        outtextxy(300, 350, L"大衍筮模拟.exe");
                                        // 再显示另一个 PNG 格式的图片
                                        loadimage(&img曾老, _T("图片\\曾老.jpg"));
                                        putimage(800, 100, &img曾老); // 将曾老.png显示在窗口中的(800, 100)位置
                                        outtextxy(800, 400, L"大衍筮视频教学.mp4");
                                        // 显示第四张 JPG 格式的图片
                                        loadimage(&img卦, _T("图片\\卦.jpg"));
                                        putimage(300, 500, &img卦); // 将卦.jpg显示在窗口中的(300, 500)位置
                                        outtextxy(300, 800, L"易经系辞传.txt"); outtextxy(1500, 0, L"退出");
                                        setfillcolor(YELLOW); solidrectangle(1500, 100, 1600, 150);
                                        setfillcolor(BLUE);  solidrectangle(1500, 150, 1600, 200);
                                        settextcolor(YELLOW); outtextxy(1510, 110, L"音乐");
                                        settextcolor(BLUE); outtextxy(1510, 160, L"关闭");
                                        mciSendString(L"open \"音乐\\王先宏 - 太极.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
                                        mciSendString(L"play mp3", NULL, 0, NULL);

                                        dianji = 0; moshi = 2; break;

                                    }
                                }
                            }

                        }
                    }
                }
                }
                }
    }}}}}

    system("pause"); // 暂停，等待任意键继续
    
    closegraph(); // 关闭图形窗口
    return 0;
}




