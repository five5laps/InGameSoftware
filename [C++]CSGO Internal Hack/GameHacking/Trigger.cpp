#include "pch.h"
#include "include.h"

bool triggerbot = false;

//������� ��������
BOOL WINAPI triggerThread(HMODULE hModule) {

    //�������� � gameModule ��� ������� client.dll 
    DWORD gameModule = (DWORD)GetModuleHandle("client.dll");
    //��������� ����� ���� ������ END
    while (true) {
        if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
            triggerbot = !triggerbot;
        }
        if (triggerbot) {
        //�������� ���������� ������ �� ������� dwLocalPlayer � ���������� localPlayer
        DWORD localPlayer = *(DWORD*)(gameModule + dwLocalPlayer);
        //���� ��� ���������� ������, �� �������� �� �����
        if (localPlayer == NULL) continue;
        //�������� ������ localPlayer � ��� �������
        uint32_t localTeam = *(uint32_t*)(localPlayer + m_iTeamNum);
        uint32_t CrosshairID = *(uint32_t*)(localPlayer + m_iCrosshairId);
        if (CrosshairID != 0 && CrosshairID < 32)
        {
            //������� ������ �����
            DWORD EnemyPlayer = *(DWORD*)(gameModule + dwEntityList + (CrosshairID - 1) * 0x10);
            //���� ����� ���, �� ��������
            if (EnemyPlayer == NULL) continue;
            //�������� ��������� ������� � ��
            uint32_t EnemyHealth = *(uint32_t*)(EnemyPlayer + m_iHealth);
            uint32_t EnemyTeam = *(DWORD*)(EnemyPlayer + m_iTeamNum);

            if (EnemyTeam != localTeam && EnemyHealth > 0 && EnemyHealth <= 100) {
                //�������� � ������
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                // �������� ����� ��������
                Sleep(100);
            }
        }
            //����������� ������
            Sleep(1);
        }

    }

    //����� �� ������
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}
