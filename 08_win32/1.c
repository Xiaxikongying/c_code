// #define WIN32_LEAN _AND_MEAN
// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>
// DWORD WINAPI ThreadFunc(LPVOID);
// #define THREAD_POOL_SIZE 3
// #define MAX_THREAD_INDEX THREAD_POOL_SIZE - 1
// #define NUM_TASKS 66
// int main()
// {
//     HANDLE hThrds[THREAD_POOL_SIZE];
//     int slot = 0;
//     DWORD threadId;
//     int i;
//     DWORD exitcode;
//     for (i = 1; i <= NUM_TASKS; i++)
//     {
//         if (i > THREAD_POOL_SIZE)
//         {
//             WaitForSingleObject(hThrds[slot], INFINITE);
//             GetExitCodeThread(hThrds[slot], &exitcode);
//             printf("slot %d terminated\n", exitcode);
//             CloseHandle(hThrds[slot]);
//         }
//         hThrds[slot] = CreateThread(NULL, 0, ThreadFunc, (LPVOID)slot, 0, &threadId);
//         printf("Launched thread #%d (slot %d)\n", i, slot);

//         if (++slot > MAX_THREAD_INDEX)
//             slot = 0;
//     }
//     for (slot = 0; slot < THREAD_POOL_SIZE; slot++)
//     {
//         WaitForSingleObject(hThrds[slot], INFINITE);
//         CloseHandle(hThrds[slot]);
//     }
//     printf("All slots terminated\n");
//     return EXIT_SUCCESS;
// }

// DWORD WINAPI ThreadFunc(LPVOID n)
// {
//     srand(GetTickCount());
//     Sleep((rand() % 8) * 500 + 500);
//     printf("slot %d idle\n", n);
//     return ((DWORD)n);
// }
