/*
체스는 총 16개의 피스를 사용하며, 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개로 구성되어 있다.
동혁이가 발견한 흰색 피스의 개수가 주어졌을 때, 몇 개를 더하거나 빼야 올바른 세트가 되는지 구하는 프로그램을 작성하시오.
*/
#include <stdio.h>

int main()
{
    int King,Queen,Rook,Bishop,Knight,Pawn;

    scanf("%d", &King);
    scanf("%d", &Queen);
    scanf("%d", &Rook);
    scanf("%d", &Bishop);
    scanf("%d", &Knight);
    scanf("%d", &Pawn);
    printf("%d %d %d %d %d %d", 1-King, 1-Queen, 2-Rook,
           2-Bishop, 2-Knight, 8-Pawn);

    return 0;
}