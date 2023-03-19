#pragma once
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <windows.h>
#include <string>
#include <vector>
#include <filesystem>

#include <psapi.h>
#include <iostream>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "psapi.lib")








auto outPutConsoleMessage(std::string msg)
{

	std::cout << msg << "\n";
}



char* wchar_to_char(const wchar_t* pwchar)
{
	// get the number of characters in the string.
	int currentCharIndex = 0;
	char currentChar = pwchar[currentCharIndex];

	while (currentChar != '\0')
	{
		currentCharIndex++;
		currentChar = pwchar[currentCharIndex];
	}

	const int charCount = currentCharIndex + 1;

	// allocate a new block of memory size char (1 byte) instead of wide char (2 bytes)
	char* filePathC = (char*)malloc(sizeof(char) * charCount);

	for (int i = 0; i < charCount; i++)
	{
		// convert to char (1 byte)
		char character = pwchar[i];

		*filePathC = character;

		filePathC += sizeof(char);

	}
	filePathC += '\0';

	filePathC -= (sizeof(char) * charCount);

	return filePathC;
}




















HANDLE g_hEvent = 0;
int timers = 1;
BOOL WINAPI HandlerRoutine(
	DWORD dwCtrlType   //  control signal type
)
{
	if (!g_hEvent)
		return FALSE;

	switch (dwCtrlType)
	{
	case CTRL_C_EVENT:


		SetEvent(g_hEvent);
		break;
	case CTRL_BREAK_EVENT:
		outPutConsoleMessage("Ctrl+Break pressed");
		SetEvent(g_hEvent);
		break;
	case CTRL_CLOSE_EVENT:
		outPutConsoleMessage("Close pressed");
		SetEvent(g_hEvent);
		break;
	case CTRL_LOGOFF_EVENT:
		outPutConsoleMessage("User logoff");
		SetEvent(g_hEvent);
		break;
	case CTRL_SHUTDOWN_EVENT:
		outPutConsoleMessage("System shutdown");
		SetEvent(g_hEvent);
		break;
	}

	return TRUE; // as we handle the event
}


void noExit()
{

	g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);

	if (g_hEvent)
	{
		outPutConsoleMessage("Ожидание закрытия окна...\n");
		WaitForSingleObject(g_hEvent, INFINITE);
		CloseHandle(g_hEvent);
	}
	else
	{
		outPutConsoleMessage("Ошибка создания эвента\n");
	}
	outPutConsoleMessage("\nНажмите на любую кнопку,для выхода");
	SetConsoleCtrlHandler(HandlerRoutine, FALSE);
	exit(0);
}


#include <cassert>
typedef unsigned int   uint;
template <class T, int SIZE>
struct SFixedArray
{
	T& operator[](uint uiIndex)
	{
		assert(uiIndex < SIZE);
		return data[uiIndex];
	}

	const T& operator[](uint uiIndex) const
	{
		assert(uiIndex < SIZE);
		return data[uiIndex];
	}

	T data[SIZE];
};

const int mVal = 422;

struct model
{
	const char* name;
};

static const SFixedArray<model, mVal> getModel = { {
{"dooravia"},
{"doorbezasovok"},
{"doorbezasovok"},
{"sub_roadbarrier"},
{"hotelgen_sv"},
{"mrk_bed02_sv"},
{"Int_turma"},
{"Int_magodej"},
{"Int_ceh1"},
{"Int_ceh2"},
{"Int_boln1"},
{"Int_boln2"},
{"mp_sfpd_big"},
{"mp_sfpd_win1"},
{"mp_sfpd_win2"},
{"mp_sfpd_stairs1"},
{"mp_sfpd_lights1"},
{"mp_sfpd_lights1a"},
{"mp_sfpd_lights2a"},
{"mp_sfpd_lights2a"},
{"police2"},
{"mp_sfpd_signa"},
{"mp_sfpd_obj1"},
{"mp_sfpd_obj2"},
{"Inttec1"},
{"Inttec2"},
{"Inttec3"},
{"Inttec4"},
{"Inttec5"},
{"Inttec6"},
{"Inttec7"},
{"cs_assault"},
{"padick1"},
{"padick2"},
{"sany1"},
{"sany2"},
{"Pasha1"},
{"pasha2"},
{"meria1"},
{"meria2"},
{"meria3"},
{"avtishk"},
{"avtishk2"},
{"Autovlad"},
{"padik2x"},
{"magnint1"},
{"magnint2"},
{"magnint3"},
{"magnint4"},
{"magnint5"},
{"magnint6"},
{"magnint7"},
{"magnint8"},
{"Padic9a"},
{"Padic9b"},
{"Padic9c"},
{"Padic9d"},
{"2vuhka"},
{"4asdomint"},
{"derdomint"},
{"garageint"},
{"banks1"},
{"banks2"},
{"banks3"},
{"banks4"},
{"banks5"},
{"banks6"},
{"banks7"},
{"vokint1"},
{"vokint2"},
{"vokint3"},
{"bankmisha1"},
{"bankmisha2"},
{"ko4alka1"},
{"ko4alka2"},
{"kvnew1"},
{"kvnew2"},
{"hrushint1"},
{"hrushint2"},
{"gostkv1"},
{"gostkv2"},
{"gostkv3"},
{"gostkv4"},
{"gostkv5"},
{"gostkv6"},
{"gostkv7"},
{"tuninggar1"},
{"tuninggar2"},
{"polismirn1"},
{"polismirn2"},
{"polismirn3"},
{"piccaint1"},
{"piccaint2"},
{"magazoint1"},
{"magazoint2"},
{"intgost12"},
{"cerint1"},
{"cerint2"},
{"cerint3"},
{"cerint4"},
{"padiknew1"},
{"padiknew2"},
{"samvok1"},
{"samvok2"},
{"samvok3"},
{"samvok4"},
{"samvok5"},
{"samvok6"},
{"samvok7"},
{"samvok8"},
{"samvok9"},
{"samvok10"},
{"samvok11"},
{"vokint4"},
{"lhouse_barrier3"},
{"lhouse_barrier3"},
{"Kazinoint1"},
{"Kazinoint2"},
{"Kazinoint3"},
{"Kazinoint4"},
{"Kazinoint5"},
{"atpnewint"},
{"atpnewint2"},
{"atpnewint3"},
{"vokznewint"},
{"vokznewint2"},
{"vokznewint3"},
{"vokznewint4"},
{"vokznewint5"},
{"vokznewint6"},
{"zavnewint"},
{"zavnewint2"},
{"zavnewint3"},
{"zavnewint4"},
{"zavnewint5"},
{"zavnewint6"},
{"zav2newint"},
{"zav2newint2"},
{"padiknewint2"},
{"padiknewint3"},
{"padiknewint4"},
{"bolnewint"},
{"bolnewint2"},
{"bolnewint3"},
{"bolnewint4"},
{"bolnewint5"},
{"bolnewint3"},
{"bolnewint3"},
{"bolnewint3"},
{"bolnewint3"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint4"},
{"bolnewint5"},
{"bolnewint5"},
{"bolnewint5"},
{"atpboxnewint"},
{"atpbox2newint"},
{"atpbox3newint"},
{"ttynewint"},
{"tty2newint"},
{"policnewint"},
{"maknewint"},
{"merdistirint"},
{"orujint"},
{"rjd1int"},
{"rjd1int2"},
{"rjd1int3"},
{"rjd1int3"},
{"rjd1int3"},
{"rjd1int3"},
{"kosmosint"},
{"kosmosint1"},
{"kosmosint2"},
{"kosmosint1"},
{"kosmosint2"},
{"kosmosint1"},
{"kosmosint2"},
{"kosmosint1"},
{"kosmosint2"},
{"kosmosint1"},
{"kosmosint2"},
{"kosmosint1"},
{"kosmosint2"},
{"kosmosint3"},
{"Intotelsaha"},
{"voenkaint"},
{"voenkaint1"},
{"voenkaint2"},
{"avrosalnew2"},
{"supermonolit"},
{"mirnbol1"},
{"mirnbol2"},
{"mirnbol3"},
{"mirnbol4"},
{"kvartnev1"},
{"gibdd1"},
{"gibdd2"},
{"gibdd3"},
{"gibdd4"},
{"kvoldnevsk"},
{"bankintnev"},
{"aeroint"},
{"aeroint1"},
{"morkint"},
{"kinoteatr1"},
{"kinoteatr2"},
{"kinoteatr2"},
{"kinoteatr2"},
{"kinoteatr2"},
{"kinoteatr2"},
{"kinoteatr2"},
{"kinoteatr2"},
{"kinoteatr2"},
{"kinoteatr2"},
{"otelnevskiy1"},
{"kvotelint1"},
{"kvotelint2"},
{"kinoidar1"},
{"kinoidar2"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kinoidar3"},
{"kvaraidar"},
{"armiint2"},
{"armiint1"},
{"armitumba"},
{"armkluch"},
{"armimetla"},
{"armilider1"},
{"armilider2"},
{"kazarmaint"},
{"kotedj1"},
{"kotedj2"},
{"kotedj3"},
{"podzparking"},
{"new2019demoint1"},
{"new2019demoint2"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"DEAD_TREE_1"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"sub_floodlite"},
{"intmishademo2"},
{"intmishademo21"},
{"intmishademo22"},
{"intmishademo3"},
{"intmishademo31"},
{"intmishademo32"},
{"intmishademo33"},
{"intmishademo34"},
{"intmishademo35"},
{"intnorora4"},
{"intnorora41"},
{"intnorora42"},
{"intnorora43"},
{"intnorora44"},
{"tramzavodin1"},
{"tramzavodin2"},
{"tramzavodin3"},
{"tramzavodin5"},
{"moikanq1"},
{"searock03"},
{"samvok303"},
{"samvok909"},
{"intbass1"},
{"intbass2"},
{"intbass3"},
{"intbass4"},
{"intbass5"},
{"intbass6"},
{"intbass7"},
{"intbass8"},
{"intbass9"},
{"intbass10"},
{"htl_fan_rotate_dy"},
{"htl_fan_rotate_dy"},
{"htl_fan_rotate_dy"},
{"htl_fan_rotate_dy"},
{"ofisintn1"},
{"ofisintn2"},
{"ofisintn3"},
{"ofisintn4"},
{"ofisintn5"},
{"ofisintn6"},
{"ofisintn7"},
{"ofisintn9"},
{"doorhool11"},
{"doorhool12"},
{"garajeint1"},
{"garajeint2"},
{"garajeint3"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"newramp"},
{"klubesint3"},
{"klubesint4"},
{"klubesint5"},
{"klubesint1"},
{"klubesint6"},
{"klubesint2"},
{"klubesint7"},
{"adrintb191"},
{"adrintb192"},
{"adrintb193"},
{"adrintb194"},
{"adrintb195"},
{"adrintb196"},
{"adrintb197"},
{"adrintb198"},
{"adrintb199"},
{"adrintb1910"},
{"adrintb1911"},
{"adrintb1912"},
{"atpmirnintb"},
{"atpmirnintb2"},
{"atpmirnintb3"},
{"intarmar1"},
{"intarmar2"},
{"intarmar3"},
{"intarmar4"},
{"intarmar4"},
{"intarmar4"},
{"intarmar4"},
{"intarmar5"},
{"intarmar7"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"intarmar6"},
{"garajinkas"},
{"garajinkas2"},
} };


void hueta()
{
	for (unsigned int i = 0; i <= (mVal); i++)
	{
		outPutConsoleMessage(getModel[i].name);
	}
}