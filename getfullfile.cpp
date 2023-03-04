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
            /*outfile << find_data.cFileName <<"\n";*/

            //outfile <<"{getDirFile('audio\\" << find_data.cFileName << "',getConsolePath())}," << "\n";
            int count = 0;
            do
            {
                if (!(find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                {
                    char filename[MAX_PATH];
                    sprintf_s(filename, MAX_PATH, "{getDirFile(\"audio\\\\%s\",getConsolePath())},", find_data.cFileName);
                    outPutConsoleMessage(filename);
                    outfile << filename << "\n";
                    count++;
                }
            } while (FindNextFileA(hFind, &find_data) != 0);

            outPutConsoleMessage("Количество записанных строк: " + std::to_string(count));



        }
    } while (FindNextFileA(hFind, &find_data) != 0);

    FindClose(hFind);
    outfile.close();  // Закрыть файл
    std::cout << "Файл создан\n";
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    createMeta();

    
    outPutConsoleMessage(getConsolePath());

    parser();

	noExit();
    return 0;
}


