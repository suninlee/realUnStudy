#include <iostream>
#include <conio.h>

void Status(int Hp, int Att) 
{
    printf_s("----------------------------------------------------\n");
    printf_s("Hp %d\n", Hp);
    printf_s("Att %d\n", Att);
    printf_s("----------------------------------------------------\n");
}

enum ATTACKER_TYPE
{
    PLAYER,
    MONSTER,
};

void Damage(int* _PlayerHp, int _PlayerAtt, int* _MonHP, int _MonAtt, ATTACKER_TYPE _Type) 
{
    int* Hp = nullptr;
    int Att = 0;

    switch (_Type)
    {
    case PLAYER:
        Hp = _PlayerHp;
        Att = _MonAtt;
        *Hp -= Att;
        break;
    case MONSTER:
        Hp = _MonHP;
        Att = _PlayerAtt;
        *Hp -= Att;
        break;
    }


    system("cls");

    printf_s("플레이어 스테이터스\n");
    Status(*_PlayerHp, _PlayerAtt);
    printf_s("몬스터 스테이터스\n");
    Status(*_MonHP, _MonAtt);

    switch (_Type)
    {
    case PLAYER:
        printf_s("플레이어가 ");
        break;
    case MONSTER:
        printf_s("몬스터가 ");
        break;
    }


    printf_s("%d의 데미지를 입었습니다.\n", Att);


}

int PlayerHp = 100;

int main()
{
    int PlayerAtt = 10;
    int MonsterHp = 100;
    int MonsterAtt = 10;

    while (PlayerHp)
    {
        // 콘솔화면을 한번 깨끗하게 삭제해주는 함수
        system("cls");

        printf_s("플레이어 스테이터스\n");
        Status(PlayerHp, PlayerAtt);
        printf_s("몬스터 스테이터스\n");
        Status(MonsterHp, MonsterAtt);

        _getch();
        Damage(&PlayerHp, PlayerAtt, &MonsterHp, MonsterAtt, PLAYER);

        _getch();
        Damage(&PlayerHp, PlayerAtt, &MonsterHp, MonsterAtt, MONSTER);

        if (0 < PlayerHp)
        {
            printf_s("플레이어는 생존했습니다.\n");
        }

        _getch();
    }
}
