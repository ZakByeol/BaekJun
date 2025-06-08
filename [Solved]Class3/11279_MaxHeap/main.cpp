#include<stdio.h>
#define MAX 100001

typedef struct _Heap {
	int numOfData;
	int arr[MAX];
} Heap;

void initHeap(Heap* heap);
void Insert(Heap* heap, int data);
int Delete(Heap* heap);

int main() {
	int CaseAmount, CalculateType, i;
	Heap heap;
	initHeap(&heap);
	scanf("%d", &CaseAmount);
	for (i = 0; i < CaseAmount; i++) {
		scanf("%d", &CalculateType);
		if (CalculateType == 0) {
			if (!heap.numOfData)
				printf("0\n");
			else
				printf("%d\n", Delete(&heap));
		}
		else {
			Insert(&heap, CalculateType);
		}
	}

	return 0;
}

void initHeap(Heap* heap) {
	heap->numOfData = 0;
}

void Insert(Heap* _Heap, int _InsertData) {
	int idx = _Heap->numOfData + 1;
	while (idx != 1) {
		if (_InsertData > _Heap->arr[idx / 2]) {
			_Heap->arr[idx] = _Heap->arr[idx / 2];
			idx /= 2;
		}
		else
			break;
	}
	_Heap->arr[idx] = _InsertData;
	_Heap->numOfData++;
}

int Delete(Heap* _Heap) {
	int root = _Heap->arr[1];
	int last = _Heap->arr[_Heap->numOfData];
	_Heap->numOfData--;

	int pIdx = 1, Lchild = pIdx * 2, Rchild = pIdx * 2 + 1;
	int cIdx;
	while (Lchild <= _Heap->numOfData) {
		if (Lchild == _Heap->numOfData) {
			if (last < _Heap->arr[Lchild]) {
				cIdx = Lchild;
				_Heap->arr[pIdx] = _Heap->arr[cIdx];
				pIdx = cIdx;
			}
			break;
		}
		else {
			cIdx = _Heap->arr[Lchild] > _Heap->arr[Rchild] ? Lchild : Rchild;
			if (last > _Heap->arr[cIdx])
				break;
			else
				_Heap->arr[pIdx] = _Heap->arr[cIdx];
		}
		pIdx = cIdx;
		Lchild = pIdx * 2;
		Rchild = pIdx * 2 + 1;
	}
	_Heap->arr[pIdx] = last;
	return root;
}