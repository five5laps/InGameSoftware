#include "include.h"
#include "GlowThread.h"

//������� ��������

BOOL WINAPI glowThread(HMODULE hModule) {
    //�������� � gameModule ��� ������� client.dll 
    uintptr_t gameModule = (uintptr_t)GetModuleHandle("client.dll");
    //��������� ����� ���� ������ END
    while (!GetAsyncKeyState(VK_END)) {
        //�������� ���������� ������ �� ������� dwLocalPlayer � ���������� localPlayer
        uintptr_t localPlayer = *(uintptr_t*)(gameModule + dwLocalPlayer);
        //���� ��� ���������� ������, �� �������� �� �����
        if (localPlayer == NULL) continue;
        //�������� localPlayer �������
        uint32_t localTeam = *(uint32_t*)(localPlayer + m_iTeamNum);
        
    }
    //����� �� ������
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
