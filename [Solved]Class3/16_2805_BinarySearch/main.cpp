#include <iostream>
#pragma warning(disable: 4996)



int Output(const int* _vlen, const long long* _vCut)
{
	if (*_vlen >= *_vCut)
	{
		return *_vlen - *_vCut;
	}
	else
	{
		return 0;
	}
}

int main()
{
    int vAmount, vBring;
	int i;
    int* listTree;
    long long vMin = 0;
    long long vMid = 1;
	long long vMax = 0;
	long long vGain, max, ResultLen;

    scanf("%d %d", &vAmount, &vBring);
    listTree = (int*)calloc(vAmount, sizeof(int));

    for (i = 0, max = 0; i < vAmount; i++) // ���� ���� �Է� �� ���� ���� ������ ���� ����
    {
        scanf(" %d", listTree + i);

        if (vMax < listTree[i])
        {
            vMax = listTree[i];
        }
    }

    ResultLen = 0;
    while (vMin <= vMax)
    {
        vMid = (vMin + vMax) / 2; // �߰� ����

		// vGain �ʱ�ȭ �� �߸� ������ ����
        for (i = 0, vGain = 0; i < vAmount; i++)
        {
            vGain += Output(listTree + i, &vMid);
        }

        
        if (vGain < vBring) // ������ �̴޼� -> ���� ���� ����
        {
            vMax = vMid - 1;
        }
        else // ������ �޼� -> ���� ���� �ø�
        {
            //���ܱ��� �ִ���� ����
            if (ResultLen < vMid)
            {
                ResultLen = vMid;
            }
            vMin = vMid + 1;
        }
    }

    printf("%lld\n", ResultLen);

    free(listTree);
    return 0;
}