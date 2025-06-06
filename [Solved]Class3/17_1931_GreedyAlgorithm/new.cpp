#include <stdio.h>
#include <stdlib.h>
#include <algorithm>  // C++ sort ����� ���� �߰�

typedef struct _tagGreedy {
    int StartTime;
    int EndTime;
} Greedy;

// C++ sort�Լ��� ���� �� �Լ� (C++ ����) -> ��Ʈ�� ���� Intro Sort
int compare(const void* a, const void* b) {
    Greedy* m1 = (Greedy*)a;
    Greedy* m2 = (Greedy*)b;

    // ����ð��� ������ ���۽ð� ��������
    if (m1->EndTime == m2->EndTime) {
        return m1->StartTime - m2->StartTime;
    }
    // ����ð� ��������
    return m1->EndTime - m2->EndTime;
}

int main() {
    int InputAmount;
    int RecentFinish = 0;
    int ResultCount = 0;

    scanf("%d", &InputAmount);
    Greedy* Meetings = (Greedy*)calloc(InputAmount, sizeof(Greedy));

    for (int i = 0; i < InputAmount; i++) {
        scanf("%d %d", &Meetings[i].StartTime, &Meetings[i].EndTime);
    }

    // �� - IntroSort for using C language
    qsort(Meetings, InputAmount, sizeof(Greedy), compare);

    /*
    std::sort(Meetings, Meetings + InputAmount, [](const Greedy& a, const Greedy& b)
    { // using C++'s sort()
        if(a.EndTime == b.EndTime) return a.StartTime < b.StartTime;
        return a.EndTime < b.EndTime;
    });
    */

    // �� - Linear Search/Greedy Algorithm
    for (int i = 0; i < InputAmount; i++) {
        if (Meetings[i].StartTime >= RecentFinish) {
            ResultCount++;
            RecentFinish = Meetings[i].EndTime;
        }
    }

    // �� - print and unallocate
    printf("%d", ResultCount);
    free(Meetings);
    return 0;
}
