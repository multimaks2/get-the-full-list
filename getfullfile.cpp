#include "Header.h"

const char* getConsolePath()
{
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    strcat_s(buffer, "\\*.*");
    return buffer;
}

void createMeta()
{

}

void parser()
{
    const char* dir_path = getConsolePath();

    WIN32_FIND_DATAA find_data;
    HANDLE hFind = FindFirstFileA(dir_path, &find_data);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        outPutConsoleMessage("Ошибка при поиске файлов в текущей папке.");
        return;
    }


    std::ofstream outfile("список.txt");  // Открыть файл для записи
    do
    {
        if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            outPutConsoleMessage(find_data.cFileName);
            outfile << find_data.cFileName <<"\n";

            //outfile <<"{getDirFile('audio\\" << find_data.cFileName << "',getConsolePath())}," << "\n";
            //int count = 0;
            //do
            //{
            //    if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            //    {
            //        char filename[MAX_PATH];
            //        sprintf_s(filename, MAX_PATH, "{getDirFile(\"audio\\\\%s\",getConsolePath())},", find_data.cFileName);
            //        outPutConsoleMessage(filename);
            //        outfile << filename << "\n";
            //        count++;
            //    }
            //} while (FindNextFileA(hFind, &find_data) != 0);

            //outPutConsoleMessage("Количество записанных строк: " + std::to_string(count));



        }
    } while (FindNextFileA(hFind, &find_data) != 0);

    FindClose(hFind);
    outfile.close();  // Закрыть файл
    std::cout << "Файл создан\n";
}


#include <Windows.h>

void hook(const wchar_t* iconPath)
{
    // Получение дескриптора главного окна
    HWND hWnd = GetActiveWindow();

    // Загрузка иконки из файла
    HICON hIcon = (HICON)LoadImage(NULL, iconPath, IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);

    // Установка иконки для окна
    SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

    // Освобождение ресурсов
    DestroyIcon(hIcon);

}






int main() 
{
    SetConsoleTitleW(L"gta_sa.exe");
    setlocale(LC_ALL, "Russian");

    const wchar_t* iconPath = L"C:\\Users\\SKYNET\\Desktop\\git\\get-the-full-list\\moon.ico";
    hook(iconPath);

    //createMeta();
    parser();

   
	noExit();
    return 0;
}


